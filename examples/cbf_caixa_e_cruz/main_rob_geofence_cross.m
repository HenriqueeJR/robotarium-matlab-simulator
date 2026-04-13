% =========================================================================
% Script: main_simulation.m (NMPC + Geofence CRUZ + Robotarium + Sem Laço Penalty)
% =========================================================================
clear; clc; close all;

%% 1. Setup the Robotarium object
Nr = 1;
% Posicionado no braço inferior da cruz, virado para cima
posicoes_iniciais = [-0.8; 0; 0]; 
r = Robotarium('NumberOfRobots', Nr, 'ShowFigure', true, 'InitialConditions', posicoes_iniciais);

%% 2. Configurações da Simulação e do NMPC
Ts = 0.033;                 % Tempo de amostragem
N = 10;                     % Horizonte de predição 
T_sim_total = 50;           % Tempo total
n_steps = round(T_sim_total / Ts);

% Limites físicos da plataforma diferencial
v_max = 0.1;  v_min = -0.1;
w_max = 1.5;  w_min = -1.5;
u_max = repmat([v_max; w_max], N, 1);
u_min = repmat([v_min; w_min], N, 1);

%% 3. Inicialização do Solver PANOC
gamma_panoc = 0.01; sigma = 1e-4; max_iter = 100; tol = 1e-3; lbfgs_size = 10;
solver = PanocSolver(gamma_panoc, sigma, max_iter, tol, u_min, u_max, lbfgs_size);

% Wrappers locais apontando para a função da Cruz
if exist('wrapper_cost_mex', 'file') == 3 && exist('wrapper_grad_mex', 'file') == 3
    disp('MEX files detectados! Rodando versão compilada.');
    solver.cost_func = @wrapper_cost_mex;
    solver.grad_func = @wrapper_grad_mex;
else
    disp('Rodando versão nativa .m.');
    solver.cost_func = @wrapper_cost;
    solver.grad_func = @wrapper_grad;
end

%% 4. Condições Iniciais e Parâmetros da Geometria
X_k = posicoes_iniciais;  
x_ref = [0; 0.8];       % Alvo [x, y] (Braço direito da cruz)
x_obs = [0.0; 0.0];       % Centro da Cruz
L_obs = 1.3;              % Comprimento total do braço a partir do centro
W_obs = 0.3;              % Meia-largura dos braços
r_rob = 0.15;             % Raio físico do robô

eta_safe = 1e8;           % Peso Fixo (Sem laço while)

u_init_mpc = zeros(2 * N, 1); 
hist_X = zeros(3, n_steps + 1);
hist_X(:, 1) = X_k;
hist_U = zeros(2, n_steps);
hist_iter = zeros(1, n_steps);
hist_time = zeros(1, n_steps);

%% --- SETUP DO PLOT DIRETO NO ROBOTARIUM ---
ax = gca;
hold(ax, 'on');

% --- Desenho da Geofence em Cruz ---
% Caixa 1 (Horizontal)
h_obs1 = fill(ax, [x_obs(1)-L_obs, x_obs(1)+L_obs, x_obs(1)+L_obs, x_obs(1)-L_obs], ...
                  [x_obs(2)-W_obs, x_obs(2)-W_obs, x_obs(2)+W_obs, x_obs(2)+W_obs], ...
                  'b', 'FaceAlpha', 0.2, 'EdgeColor', 'b');
% Caixa 2 (Vertical)
h_obs2 = fill(ax, [x_obs(1)-W_obs, x_obs(1)+W_obs, x_obs(1)+W_obs, x_obs(1)-W_obs], ...
                  [x_obs(2)-L_obs, x_obs(2)-L_obs, x_obs(2)+L_obs, x_obs(2)+L_obs], ...
                  'b', 'FaceAlpha', 0.2, 'EdgeColor', 'b');

% Linhas Tracejadas (Limites físicos reais por conta do raio do robô)
L_safe = L_obs - r_rob; W_safe = W_obs - r_rob;
h_margin1 = plot(ax, [x_obs(1)-L_safe, x_obs(1)+L_safe, x_obs(1)+L_safe, x_obs(1)-L_safe, x_obs(1)-L_safe], ...
                     [x_obs(2)-W_safe, x_obs(2)-W_safe, x_obs(2)+W_safe, x_obs(2)+W_safe, x_obs(2)-W_safe], 'r--', 'LineWidth', 1.5);
h_margin2 = plot(ax, [x_obs(1)-W_safe, x_obs(1)+W_safe, x_obs(1)+W_safe, x_obs(1)-W_safe, x_obs(1)-W_safe], ...
                     [x_obs(2)-L_safe, x_obs(2)-L_safe, x_obs(2)+L_safe, x_obs(2)+L_safe, x_obs(2)-L_safe], 'r--', 'LineWidth', 1.5);

plot(ax, x_ref(1), x_ref(2), 'g*', 'MarkerSize', 10, 'LineWidth', 2);
h_traj = plot(ax, X_k(1), X_k(2), 'm-', 'LineWidth', 2); 
h_pred = plot(ax, X_k(1), X_k(2), 'k--', 'LineWidth', 1.5); 

theta_rob = linspace(0, 2*pi, 40); 
h_robot_body = fill(ax, X_k(1) + r_rob*cos(theta_rob), X_k(2) + r_rob*sin(theta_rob), ...
                    'y', 'FaceAlpha', 0.4, 'EdgeColor', 'yellow', 'LineWidth', 1.5);
h_robot_body_intern = fill(ax, X_k(1) + (0.055)*cos(theta_rob), X_k(2) + (0.055)*sin(theta_rob), ...
                    'g', 'FaceAlpha', 0.4, 'EdgeColor', 'green', 'LineWidth', 1.5);

% Ajuste de Camadas (Z-Order)
uistack(h_obs1, 'bottom');
uistack(h_obs2, 'bottom');
uistack(h_margin1, 'bottom');
uistack(h_margin2, 'bottom');
uistack(h_traj, 'bottom');

disp('Iniciando simulação NMPC no Robotarium (Cruz Geofence Direta)...');
tic;

%% 5. O Loop NMPC (Horizonte Deslizante)
for k = 1:n_steps
    % 1. Adquire o estado real do Robotarium
    X_k = r.get_poses();
    hist_X(:, k+1) = X_k;
    
    % 2. Resolve o NMPC numa única chamada (Sem laço iterativo de penalidade)
    u_current = u_init_mpc; 
    params = [X_k; x_ref; x_obs; L_obs; W_obs; eta_safe];
    
    t_start = tic;
    [u_opt, res_norm, iter_count] = solver.solve(u_current, params);
    tempo_solve = toc(t_start);
    
    % --- Simulação Rápida Apenas para Desenhar a Linha de Predição (Opcional) ---
    X_pred = zeros(3, N+1);
    X_pred(:, 1) = X_k;
    for i = 1:N
        v_p = u_opt((i-1)*2 + 1);
        w_p = u_opt((i-1)*2 + 2);
        X_pred(1, i+1) = X_pred(1, i) + Ts * v_p * cos(X_pred(3, i));
        X_pred(2, i+1) = X_pred(2, i) + Ts * v_p * sin(X_pred(3, i));
        X_pred(3, i+1) = X_pred(3, i) + Ts * w_p;
    end
    set(h_pred, 'XData', X_pred(1, :), 'YData', X_pred(2, :));
    % ----------------------------------------------------------------------------
    
    % 3. Aplica Controle Real no Robotarium
    v_cmd = u_opt(1);
    w_cmd = u_opt(2);
    
    hist_U(:, k) = [v_cmd; w_cmd];
    hist_iter(k) = iter_count;
    hist_time(k) = tempo_solve;
    
    % Clip de Segurança para o hardware do Robotarium
    lim_v = r.max_linear_velocity * 0.99;
    lim_w = r.max_angular_velocity * 0.99;
    v_cmd_safe = max(min(v_cmd, lim_v), -lim_v);
    w_cmd_safe = max(min(w_cmd, lim_w), -lim_w);
    
    r.set_velocities(1:Nr, [v_cmd_safe; w_cmd_safe]);
    
    % --- Atualização Visual ---
    set(h_traj, 'XData', hist_X(1, 1:k+1), 'YData', hist_X(2, 1:k+1));
    
    % Ajuste do offset visual do corpo do robô no Robotarium
    d_off = 0.035; 
    x_centro = X_k(1) + d_off * cos(X_k(3));
    y_centro = X_k(2) + d_off * sin(X_k(3));
    
    set(h_robot_body, 'XData', x_centro + r_rob*cos(theta_rob), ...
                      'YData', y_centro + r_rob*sin(theta_rob));
    set(h_robot_body_intern, 'XData', x_centro + (0.055)*cos(theta_rob), ...
                             'YData', y_centro + (0.055)*sin(theta_rob));
    drawnow;
        
    % Preparação (Warm Start) para a próxima iteração
    u_init_mpc = [u_opt(3:end); u_opt(end-1:end)]; 
    
    % Critérios de Chegada
    if norm(X_k(1:2) - x_ref(1:2)) < 0.075
        disp(['Alvo alcançado em ', num2str(k * Ts), ' segundos!']);
        n_steps = k;
        title(ax, 'Trajetória Concluída');
        break;
    end
    
    % Avança 1 passo físico na simulação
    r.step();
end

disp(['Simulação concluída em ', num2str(toc), ' segundos.']);
disp('--- RESULTADOS DO BENCHMARK (PANOC) ---');
disp(['Tempo Médio de Solve   : ', num2str(mean(hist_time(1:n_steps)) * 1000), ' ms']);
disp(['Tempo Máximo de Solve  : ', num2str(max(hist_time(1:n_steps)) * 1000), ' ms']);
disp(['Máximo de Iterações    : ', num2str(max(hist_iter(1:n_steps)))]);

r.debug();

%% 6. Plotagem das Ações de Controle e Estados (Pós Simulação)
figure('Name', 'Esforço Computacional', 'Color', 'w');
plot(1:n_steps, hist_iter(1:n_steps), 'k-', 'LineWidth', 1.5);
xlabel('Passo de Simulação k'); ylabel('Iterações do PANOC');
title('Convergência com Warm Start');
grid on;

figure('Name', 'Ação de Controle ao Longo do Tempo', 'Color', 'w');
t_sim = (0:n_steps-1) * Ts;
subplot(2, 1, 1); hold on; grid on;
stairs(t_sim, hist_U(1, 1:n_steps), 'b-', 'LineWidth', 1.5);
yline(v_max, 'r--', 'LineWidth', 1.2); yline(v_min, 'r--', 'LineWidth', 1.2);
xlabel('Tempo [s]'); ylabel('v [m/s]'); title('Velocidade Linear (v)');
ylim([v_min - 0.1, v_max + 0.1]);

subplot(2, 1, 2); hold on; grid on;
stairs(t_sim, hist_U(2, 1:n_steps), 'm-', 'LineWidth', 1.5);
yline(w_max, 'r--', 'LineWidth', 1.2); yline(w_min, 'r--', 'LineWidth', 1.2);
xlabel('Tempo [s]'); ylabel('\omega [rad/s]'); title('Velocidade Angular (\omega)');
ylim([w_min - 0.2, w_max + 0.2]);

%% =========================================================================
% FUNÇÕES LOCAIS (WRAPPERS)
% =========================================================================
function cost = wrapper_cost(u, params)
    cost = build_robot_cbf_cross_geofence(u, params);
end

function grad = wrapper_grad(u, params)
    [~, grad] = build_robot_cbf_cross_geofence(u, params);
end