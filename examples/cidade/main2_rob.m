% =========================================================================
% Script: main_simulation.m (NMPC + Geofence Cruz + Robotarium API)
% =========================================================================
clear; clc; close all;

%% 1. Setup the Robotarium object
Nr = 1;
posicoes_iniciais = zeros(3, Nr);
posicoes_iniciais(1, 1) = -1.4;   % Posição X (ponta do braço esquerdo)
posicoes_iniciais(2, 1) = 0.0;    % Posição Y (centro)
posicoes_iniciais(3, 1) = 0.0;    % Orientação (virado para direita)
r = Robotarium('NumberOfRobots', Nr, 'ShowFigure', true, 'InitialConditions', posicoes_iniciais);

%% 2. Configurações da Simulação e do NMPC
Ts = 0.033;             % Tempo de amostragem
N = 75;                 % Horizonte de predição 
T_sim_total = 50;       % Tempo total
n_steps = round(T_sim_total / Ts);

% Limites físicos da plataforma diferencial
v_max = 0.1;  v_min = -0.1;
w_max = 1.5;  w_min = -1.5;
u_max = repmat([v_max; w_max], N, 1);
u_min = repmat([v_min; w_min], N, 1);

%% 3. Inicialização do Solver PANOC (Com Fallback de Segurança)
gamma = 1e-5; sigma = 1e-4; max_iter = 100; tol = 1e-3; lbfgs_size = 10;
solver = PanocSolver(gamma, sigma, max_iter, tol, u_min, u_max, lbfgs_size);

if exist('wrapper_cost_mex', 'file') == 3 && exist('wrapper_grad_mex', 'file') == 3
    disp('MEX files detectados! Rodando versão compilada em C (Alta Performance).');
    solver.cost_func = @wrapper_cost_mex;
    solver.grad_func = @wrapper_grad_mex;
else
    disp('MEX files não encontrados/incompatíveis. Rodando versão nativa .m (Interpretada).');
    solver.cost_func = @wrapper_cost;
    solver.grad_func = @wrapper_grad;
end

%% 4. Condições Iniciais e Parâmetros do Penalty Method
X_k = posicoes_iniciais;    
x_ref = [1.2; -0.1];         % Alvo (ponta do braço superior)
x_obs = [0.0; 0.0];         % Centro da topologia complexa

% Parâmetros do Algoritmo 2 (Penalty Method)
eta_inicial = 1e4;          
eta_max = 1e4;          
omega = 10.0;               
tolerancia_obs = 1e-7;      
u_init_mpc = zeros(2 * N, 1); 

hist_X = zeros(3, n_steps + 1);
hist_X(:, 1) = X_k;
hist_U = zeros(2, n_steps);
hist_iter = zeros(1, n_steps);
hist_time = zeros(1, n_steps);

%% --- SETUP DO PLOT DIRETO NO ROBOTARIUM ---
ax = gca;
hold(ax, 'on');

L_arm = 1.5;  % Comprimento dos braços a partir do centro
W_arm = 0.3;  % Meia-largura dos braços
R_out = 0.5;  % Raio do círculo externo (Hub conector)
R_in  = 0.2;  % Raio do círculo interno (Buraco a evitar)
r_rob = 0.1; % Raio físico do robô

% --- Desenho dos 4 Braços da Cruz (Zonas Seguras) ---
h_geo(1) = fill(ax, [0 L_arm L_arm 0], [-W_arm -W_arm W_arm W_arm], 'b', 'FaceAlpha', 0.2, 'EdgeColor', 'b');
h_geo(2) = fill(ax, [-W_arm W_arm W_arm -W_arm], [0 0 L_arm L_arm], 'b', 'FaceAlpha', 0.2, 'EdgeColor', 'b');
h_geo(3) = fill(ax, [-L_arm 0 0 -L_arm], [-W_arm -W_arm W_arm W_arm], 'b', 'FaceAlpha', 0.2, 'EdgeColor', 'b');
h_geo(4) = fill(ax, [-W_arm W_arm W_arm -W_arm], [-L_arm -L_arm 0 0], 'b', 'FaceAlpha', 0.2, 'EdgeColor', 'b');

% --- Desenho do Hub Central e do Buraco ---
theta_circle = linspace(0, 2*pi, 100);
h_geo(5) = fill(ax, R_out*cos(theta_circle), R_out*sin(theta_circle), 'b', 'FaceAlpha', 0.2, 'EdgeColor', 'b');
h_geo(6) = fill(ax, R_in*cos(theta_circle), R_in*sin(theta_circle), 'w', 'FaceAlpha', 1.0, 'EdgeColor', 'r', 'LineWidth', 1.5);

plot(ax, x_ref(1), x_ref(2), 'g*', 'MarkerSize', 10, 'LineWidth', 2);
h_traj = plot(ax, X_k(1), X_k(2), 'b-', 'LineWidth', 2); 
h_pred = plot(ax, X_k(1), X_k(2), 'k--', 'LineWidth', 1.5); 

theta_rob = linspace(0, 2*pi, 40); 
h_robot_body = fill(ax, X_k(1) + r_rob*cos(theta_rob), X_k(2) + r_rob*sin(theta_rob), ...
                    'y', 'FaceAlpha', 0.4, 'EdgeColor', 'yellow', 'LineWidth', 1.5);
h_robot_body_intern = fill(ax, X_k(1) + (0.075)*cos(theta_rob), X_k(2) + (0.075)*sin(theta_rob), ...
                    'g', 'FaceAlpha', 0.4, 'EdgeColor', 'green', 'LineWidth', 1.5);

% Ajuste de Camadas (Z-Order)
for idx = 1:length(h_geo)
    uistack(h_geo(idx), 'bottom');
end
uistack(h_traj, 'bottom');

disp('Iniciando simulação NMPC no Robotarium...');
tic;

%% 5. O Loop NMPC (Horizonte Deslizante)
for k = 1:n_steps
    X_k = r.get_poses();
    hist_X(:, k+1) = X_k;
    
    
    eta_obs = eta_inicial;
    u_current = u_init_mpc; 

    params = [X_k; x_ref; x_obs; eta_obs];
    t_start = tic;
    [u_opt, res_norm, iter_count] = solver.solve(u_current, params);
    tempo_solve = toc(t_start);
    
    v_cmd = u_opt(1);
    w_cmd = u_opt(2);
    
    hist_U(:, k) = [v_cmd; w_cmd];
    hist_iter(k) = iter_count;
    
    % Clip de Segurança para o Robotarium
    lim_v = r.max_linear_velocity * 0.99;
    lim_w = r.max_angular_velocity * 0.99;
    v_cmd_safe = max(min(v_cmd, lim_v), -lim_v);
    w_cmd_safe = max(min(w_cmd, lim_w), -lim_w);
    
    r.set_velocities(1:Nr, [v_cmd_safe; w_cmd_safe]);
    
    set(h_traj, 'XData', hist_X(1, 1:k+1), 'YData', hist_X(2, 1:k+1));
    % --- DESLOCAMENTO DO CENTRO VISUAL ---
    d_off = 0.035; % 3.5 cm para a frente
    x_centro = X_k(1) + d_off * cos(X_k(3));
    y_centro = X_k(2) + d_off * sin(X_k(3));
    
    set(h_robot_body, 'XData', x_centro + r_rob*cos(theta_rob), ...
                      'YData', y_centro + r_rob*sin(theta_rob));
    set(h_robot_body_intern, 'XData', x_centro + (0.075)*cos(theta_rob), ...
                             'YData', y_centro + (0.075)*sin(theta_rob));
    
    u_init_mpc = [u_opt(3:end); u_opt(end-1:end)]; 
    hist_time(k) = tempo_solve;
    
    % Critérios de Parada
    if norm(X_k(1:2) - x_ref(1:2)) < 0.075
        disp(['Alvo alcançado em ', num2str(k * Ts), ' segundos!']);
        n_steps = k;
        title(ax, 'Trajetória Concluída');
        break;
    end
    
    % if max_violacao >= 0.015
    %     disp('O robô real bateu (Violou os limites)!');
    %     n_steps = k;
    %     break;
    % end
    
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
save('dados_nmpc.mat', 'hist_X', 'hist_U', 'hist_iter', 'hist_time', 'Ts', 'n_steps');
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

