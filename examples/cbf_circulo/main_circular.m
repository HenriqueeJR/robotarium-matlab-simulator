% =========================================================================
% Script: main_simulation.m (NMPC + CBF Obstáculo Circular + Robotarium)
% =========================================================================
clear; clc; close all;

%% 1. Setup the Robotarium object
Nr = 1;
posicoes_iniciais = [-0.8; -0.8; pi/4]; % Estado inicial [x; y; theta]
r = Robotarium('NumberOfRobots', Nr, 'ShowFigure', true, 'InitialConditions', posicoes_iniciais);

%% 2. Configurações da Simulação e do NMPC
Ts = 0.033;               % Tempo de amostragem
N = 10;                   % Horizonte de predição 
T_sim_total = 50;         % Tempo total
n_steps = round(T_sim_total / Ts);

% Limites físicos do NMPC
v_max = 0.1;  v_min = -0.1;
w_max = 1.5;  w_min = -1.5;
u_max = repmat([v_max; w_max], N, 1);
u_min = repmat([v_min; w_min], N, 1);

%% 3. Inicialização do Solver PANOC (Com Fallback de Segurança)
gamma_panoc = 1; sigma = 1e-4; max_iter = 100; tol = 1e-3; lbfgs_size = 10;
solver = PanocSolver(gamma_panoc, sigma, max_iter, tol, u_min, u_max, lbfgs_size);

if exist('wrapper_cost_mex', 'file') == 3 && exist('wrapper_grad_mex', 'file') == 3
    disp('MEX files detectados! Rodando versão compilada em C (Alta Performance).');
    solver.cost_func = @wrapper_cost_mex;
    solver.grad_func = @wrapper_grad_mex;
else
    disp('MEX files não encontrados/incompatíveis. Rodando versão nativa .m (Interpretada).');
    solver.cost_func = @wrapper_cost;
    solver.grad_func = @wrapper_grad;
end

%% 4. Condições Iniciais e Parâmetros da Geometria
X_k = posicoes_iniciais; 
x_ref = [0.8; 0.9];       % Alvo [x, y]
x_obs = [0.0; 0.0];       % Centro do obstáculo circular
R_obs = 0.3;              % Raio do obstáculo
r_rob = 0.1;              % Raio físico do robô (usado na CBF)

% Parâmetros do Penalty Method
eta_inicial = 1400;         % Peso inicial da Barreira
eta_max = 1400;             % Teto de penalidade
omega = 5.0;                % Fator de multiplicação do peso
tolerancia_obs = 1e-4;      % Tolerância para violação de segurança

u_init_mpc = zeros(2 * N, 1); 
hist_X = zeros(3, n_steps + 1);
hist_X(:, 1) = X_k;
hist_U = zeros(2, n_steps);
hist_iter = zeros(1, n_steps);
hist_time = zeros(1, n_steps);

%% --- SETUP DO PLOT DIRETO NO ROBOTARIUM ---
ax = gca;
hold(ax, 'on');

% --- Desenho do Obstáculo Circular ---
theta_circle = linspace(0, 2*pi, 100);
h_obs_fill = fill(ax, x_obs(1) + R_obs*cos(theta_circle), x_obs(2) + R_obs*sin(theta_circle), ...
    'r', 'FaceAlpha', 0.5, 'EdgeColor', 'r');
h_obs_margin = plot(ax, x_obs(1) + (R_obs + r_rob)*cos(theta_circle), ...
     x_obs(2) + (R_obs + r_rob)*sin(theta_circle), 'r--', 'LineWidth', 1.5);

plot(ax, x_ref(1), x_ref(2), 'g*', 'MarkerSize', 10, 'LineWidth', 2);
h_traj = plot(ax, X_k(1), X_k(2), 'b-', 'LineWidth', 2); 
h_pred = plot(ax, X_k(1), X_k(2), 'k--', 'LineWidth', 1.5); 

theta_rob = linspace(0, 2*pi, 40); 
h_robot_body = fill(ax, X_k(1) + r_rob*cos(theta_rob), X_k(2) + r_rob*sin(theta_rob), ...
                    'y', 'FaceAlpha', 0.4, 'EdgeColor', 'yellow', 'LineWidth', 1.5);
h_robot_body_intern = fill(ax, X_k(1) + (0.075)*cos(theta_rob), X_k(2) + (0.075)*sin(theta_rob), ...
                    'g', 'FaceAlpha', 0.4, 'EdgeColor', 'green', 'LineWidth', 1.5);

% Ajuste de Camadas (Z-Order) para ficar atrás do robô real do Robotarium
uistack(h_obs_fill, 'bottom');
uistack(h_obs_margin, 'bottom');
uistack(h_traj, 'bottom');

disp('Iniciando simulação NMPC no Robotarium...');
tic;

%% 5. O Loop NMPC (Horizonte Deslizante)
for k = 1:n_steps
    % 1. Adquire o estado real do Robotarium
    X_k = r.get_poses();
    hist_X(:, k+1) = X_k;
    
    eta_safe = eta_inicial;
    u_current = u_init_mpc; 
    
    % 2. Loop de Segurança (Penalty Method)
    while eta_safe <= eta_max
        params = [X_k; x_ref; x_obs; R_obs; eta_safe];
        
        t_start = tic;
        [u_opt, res_norm, iter_count] = solver.solve(u_current, params);
        tempo_solve = toc(t_start);
        
        X_pred = zeros(3, N+1);
        X_pred(:, 1) = X_k;
        max_violacao = 0;
       
        % Forward interno do MATLAB para checar predição
        for i = 1:N
            v_p = u_opt((i-1)*2 + 1);
            w_p = u_opt((i-1)*2 + 2);
            X_pred(1, i+1) = X_pred(1, i) + Ts * v_p * cos(X_pred(3, i));
            X_pred(2, i+1) = X_pred(2, i) + Ts * v_p * sin(X_pred(3, i));
            X_pred(3, i+1) = X_pred(3, i) + Ts * w_p;
            
            dist_sq = (X_pred(1, i+1) - x_obs(1))^2 + (X_pred(2, i+1) - x_obs(2))^2;
            h_val = dist_sq - (R_obs + r_rob)^2;
            
            violacao_atual = max(0, -h_val); 
            if violacao_atual > max_violacao
                max_violacao = violacao_atual;
            end
        end
        
        set(h_pred, 'XData', X_pred(1, :), 'YData', X_pred(2, :));
        title(ax, sprintf('eta\\_safe = %.1e | Violação Máx = %.4f', eta_safe, max_violacao));
        drawnow;
        
        if (res_norm <= solver.tol) && (max_violacao <= tolerancia_obs)
            break; 
        else
            eta_safe = eta_safe * omega; 
            u_current = u_opt; 
        end
    end
    
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
    
    % Ajuste do offset visual do corpo do robô (centro de rotação vs centro geométrico)
    d_off = 0.035; % 3.5 cm para a frente
    x_centro = X_k(1) + d_off * cos(X_k(3));
    y_centro = X_k(2) + d_off * sin(X_k(3));
    
    set(h_robot_body, 'XData', x_centro + r_rob*cos(theta_rob), ...
                      'YData', y_centro + r_rob*sin(theta_rob));
    set(h_robot_body_intern, 'XData', x_centro + (0.075)*cos(theta_rob), ...
                             'YData', y_centro + (0.075)*sin(theta_rob));
    
    u_init_mpc = [u_opt(3:end); u_opt(end-1:end)]; 
    
    % Critérios de Chegada
    if norm(X_k(1:2) - x_ref(1:2)) < 0.075
        disp(['Alvo alcançado em ', num2str(k * Ts), ' segundos!']);
        n_steps = k;
        title(ax, 'Trajetória Concluída');
        break;
    end
    
    % Avança 1 passo físico na simulação (ou hardware real)
    r.step();
end

disp(['Simulação concluída em ', num2str(toc), ' segundos.']);
disp('--- RESULTADOS DO BENCHMARK (PANOC) ---');
disp(['Tempo Médio de Solve   : ', num2str(mean(hist_time(1:n_steps)) * 1000), ' ms']);
disp(['Tempo Máximo de Solve  : ', num2str(max(hist_time(1:n_steps)) * 1000), ' ms']);
disp(['Máximo de Iterações    : ', num2str(max(hist_iter(1:n_steps)))]);

r.debug();

% Salva os dados
disp('Salvando dados do experimento para download...');
save('dados_nmpc_cbf_circular.mat', 'hist_X', 'hist_U', 'hist_iter', 'hist_time', 'Ts', 'n_steps');
disp('Dados salvos com sucesso!');

%% 6. Plotagem das Ações de Controle e Estados (Pós Simulação)
% Para evitar fechar a figura oficial do Robotarium, criamos figuras novas.
figure('Name', 'Esforço Computacional', 'Color', 'w');
plot(1:n_steps, hist_iter(1:n_steps), 'k-', 'LineWidth', 1.5);
xlabel('Passo de Simulação k'); ylabel('Iterações do PANOC');
title('Convergência com Warm Start');
grid on;

figure('Name', 'Tempo Computacional', 'Color', 'w');
plot(1:n_steps, hist_time(1:n_steps), 'k-', 'LineWidth', 1.5);
xlabel('Passo de Simulação k'); ylabel('Tempo [s]');
title('Tempos Computacionais');
yline(0.033, 'r--', 'LineWidth', 1.2);
legend('Tempo de Solve', 'Limite do Robotarium (33ms)', 'Location', 'best');
grid on;

figure('Name', 'Estados do Robô ao Longo do Tempo (hist_X)', 'Color', 'w');
t_sim_X = (0:n_steps) * Ts; 
subplot(3, 1, 1); hold on; grid on;
plot(t_sim_X, hist_X(1, 1:n_steps+1), 'b-', 'LineWidth', 1.5);
yline(x_ref(1), 'g--', 'LineWidth', 1.5); 
xlabel('Tempo [s]'); ylabel('X [m]'); title('Evolução da Posição X');
legend('Trajetória X(t)', 'Alvo X', 'Location', 'best');

subplot(3, 1, 2); hold on; grid on;
plot(t_sim_X, hist_X(2, 1:n_steps+1), 'r-', 'LineWidth', 1.5);
yline(x_ref(2), 'g--', 'LineWidth', 1.5); 
xlabel('Tempo [s]'); ylabel('Y [m]'); title('Evolução da Posição Y');
legend('Trajetória Y(t)', 'Alvo Y', 'Location', 'best');

subplot(3, 1, 3); hold on; grid on;
plot(t_sim_X, hist_X(3, 1:n_steps+1), 'm-', 'LineWidth', 1.5);
xlabel('Tempo [s]'); ylabel('\theta [rad]'); title('Evolução da Orientação (\theta)');

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
    cost = build_robot_cbf_circular(u, params);
end

function grad = wrapper_grad(u, params)
    [~, grad] = build_robot_cbf_circular(u, params);
end