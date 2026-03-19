% =========================================================================
% Script: main_simulation.m (NMPC + Geofence Cruz com Buraco Central) - Robotarium
% =========================================================================
clear; clc; close all;

%% 1. Configurações da Simulação e do NMPC
Ts = 0.033;               % Tempo de amostragem
N = 80;                   % Horizonte de predição 
T_sim_total = 100;        % Tempo total reduzido (escala do mapa é menor)
n_steps = round(T_sim_total / Ts);

% Setup the Robotarium object
Nr = 1;
posicoes_iniciais = zeros(3, Nr);
posicoes_iniciais(1, 1) = -1.4;     % Posição X (esquerda)
posicoes_iniciais(2, 1) = -0.75;    % Posição Y (centro)
posicoes_iniciais(3, 1) = 0;        % Orientação (virado para direita)
r = Robotarium('NumberOfRobots', Nr, 'ShowFigure', true, 'InitialConditions', posicoes_iniciais);

% Limites físicos da plataforma diferencial
v_max = 0.1;  v_min = -0.1;
w_max = 1.5;  w_min = -1.5;
u_max = repmat([v_max; w_max], N, 1);
u_min = repmat([v_min; w_min], N, 1);

%% 2. Inicialização do Solver PANOC
gamma = 0.1; sigma = 1e-4; max_iter = 400; tol = 1e-3; lbfgs_size = 10;
solver = PanocSolver(gamma, sigma, max_iter, tol, u_min, u_max, lbfgs_size);
% Wrappers locais
solver.cost_func = @wrapper_cost;
solver.grad_func = @wrapper_grad;

%% 3. Condições Iniciais e Parâmetros do Penalty Method
X_k = posicoes_iniciais;    % Estado inicial
x_ref = [1.4; 0.75];        % Alvo (ponta do braço superior)
x_obs = [0.0; 0.0];         % Centro da topologia complexa

% Parâmetros do Algoritmo 2 (Penalty Method)
eta_inicial = 1e-5;         % Já começa punindo severamente quem sair da linha!
eta_max = 1e7;              % Teto seguro para não explodir o gradiente do MATLAB
omega = 10.0;               % Fator de multiplicação
tolerancia_obs = 1e-6;      % Tolerância para considerar o caminho seguro (\eta_*)

u_init_mpc = zeros(2 * N, 1); 
hist_X = zeros(3, n_steps + 1);
hist_X(:, 1) = X_k;
hist_U = zeros(2, n_steps);
hist_iter = zeros(1, n_steps);
hist_time = zeros(1, n_steps);

%% --- SETUP DO PLOT DIRETO NO ROBOTARIUM ---
ax = gca;
hold(ax, 'on');

% --- Dimensões da Geometria ---
L_arm = 1.2;  % Comprimento dos braços a partir do centro
W_arm = 0.2;  % Meia-largura dos braços
R_out = 0.5;  % Raio do círculo externo (Hub conector)
R_in  = 0.25; % Raio do círculo interno (Buraco a evitar)

% --- Desenho dos 4 Braços da Cruz (Zonas Seguras) e Obstáculo ---
h_geo(1) = fill(ax, [0 L_arm L_arm 0], [-W_arm -W_arm W_arm W_arm], 'b', 'FaceAlpha', 0.2, 'EdgeColor', 'b');
h_geo(2) = fill(ax, [-W_arm W_arm W_arm -W_arm], [0 0 L_arm L_arm], 'b', 'FaceAlpha', 0.2, 'EdgeColor', 'b');
h_geo(3) = fill(ax, [-L_arm 0 0 -L_arm], [-W_arm -W_arm W_arm W_arm], 'b', 'FaceAlpha', 0.2, 'EdgeColor', 'b');
h_geo(4) = fill(ax, [-W_arm W_arm W_arm -W_arm], [-L_arm -L_arm 0 0], 'b', 'FaceAlpha', 0.2, 'EdgeColor', 'b');
h_geo(5) = fill(ax, [-1.6 -1.2 -1.2 -1.6], [-1.2 -1.2 1.2 1.2], 'b', 'FaceAlpha', 0.2, 'EdgeColor', 'b');
h_geo(6) = fill(ax, [1.2 1.6 1.6 1.2], [-1.2 -1.2 1.2 1.2], 'b', 'FaceAlpha', 0.2, 'EdgeColor', 'b');

theta_circle = linspace(0, 2*pi, 100);
h_geo(7) = fill(ax, R_out*cos(theta_circle), R_out*sin(theta_circle), 'b', 'FaceAlpha', 0.2, 'EdgeColor', 'b'); 
h_geo(8) = fill(ax, R_in*cos(theta_circle), R_in*sin(theta_circle), 'w', 'FaceAlpha', 1.0, 'EdgeColor', 'r', 'LineWidth', 1.5);

plot(ax, x_ref(1), x_ref(2), 'g*', 'MarkerSize', 10, 'LineWidth', 2);
h_traj = plot(ax, X_k(1), X_k(2), 'b-', 'LineWidth', 2); 
h_pred = plot(ax, X_k(1), X_k(2), 'k--', 'LineWidth', 1.5); 

% Joga a geometria e a trajetória passada para o fundo para não cobrir os robôs
for idx = 1:length(h_geo)
    uistack(h_geo(idx), 'bottom');
end
uistack(h_traj, 'bottom');

disp('Iniciando simulação NMPC no Robotarium...');
tic;

%% 4. O Loop NMPC (Horizonte Deslizante)
for k = 1:n_steps
    X_k = r.get_poses();
    hist_X(:, k+1) = X_k;
    
    eta_obs = eta_inicial;
    u_current = u_init_mpc; 
    
    while eta_obs <= eta_max
        params = [X_k; x_ref; x_obs; eta_obs];
        
        t_start = tic;
        [u_opt, res_norm, iter_count] = solver.solve(u_current, params);
        tempo_solve = toc(t_start);
        
        X_pred = zeros(3, N+1);
        X_pred(:, 1) = X_k;
        max_violacao = 0;
       
        for i = 1:N
            v_p = u_opt((i-1)*2 + 1);
            w_p = u_opt((i-1)*2 + 2);
            X_pred(1, i+1) = X_pred(1, i) + Ts * v_p * cos(X_pred(3, i));
            X_pred(2, i+1) = X_pred(2, i) + Ts * v_p * sin(X_pred(3, i));
            X_pred(3, i+1) = X_pred(3, i) + Ts * w_p;
            
            x_p = X_pred(1, i+1) - x_obs(1); 
            y_p = X_pred(2, i+1) - x_obs(2);
            
            % Calcula as violações
            P1 = max(0, -x_p)^2 + max(0, x_p - L_arm)^2 + max(0, -y_p - W_arm)^2 + max(0, y_p - W_arm)^2;
            P2 = max(0, -x_p - W_arm)^2 + max(0, x_p - W_arm)^2 + max(0, -y_p)^2 + max(0, y_p - L_arm)^2;
            P3 = max(0, -x_p - L_arm)^2 + max(0, x_p)^2 + max(0, -y_p - W_arm)^2 + max(0, y_p - W_arm)^2;
            P4 = max(0, -x_p - W_arm)^2 + max(0, x_p - W_arm)^2 + max(0, -y_p - L_arm)^2 + max(0, y_p)^2;
            P5 = max(0, x_p^2 + y_p^2 - R_out^2)^2;
            P6 = max(0, R_in^2 - (x_p^2 + y_p^2))^2;
            P7 = max(0, (-L_arm - 2*W_arm) - x_p)^2 + max(0, x_p - (-L_arm))^2 + max(0, -L_arm - y_p)^2 + max(0, y_p - L_arm)^2;
            P8 = max(0, L_arm - x_p)^2 + max(0, x_p - (L_arm + 2*W_arm))^2 + max(0, -L_arm - y_p)^2 + max(0, y_p - L_arm)^2;
            
            violacao_atual = min([P1, P2, P3, P4, P5, P7, P8]) + P6;
            
            if violacao_atual > max_violacao
                max_violacao = violacao_atual;
            end
        end
        
        set(h_pred, 'XData', X_pred(1, :), 'YData', X_pred(2, :));
        
        if (max_violacao <= tolerancia_obs)
            break; 
        else
            eta_obs = eta_obs * omega;
            u_current = u_opt; 
        end
    end
    
    v_cmd = u_opt(1);
    w_cmd = u_opt(2);
    hist_U(:, k) = [v_cmd; w_cmd];
    hist_iter(k) = iter_count;
    
    lim_v = r.max_linear_velocity * 0.99;
    lim_w = r.max_angular_velocity * 0.99;
    v_cmd_safe = max(min(v_cmd, lim_v), -lim_v);
    w_cmd_safe = max(min(w_cmd, lim_w), -lim_w);
    
    r.set_velocities(1:Nr, [v_cmd_safe; w_cmd_safe]);
    
    set(h_traj, 'XData', hist_X(1, 1:k+1), 'YData', hist_X(2, 1:k+1));
    
    dist_to_target = norm(X_k(1:2) - x_ref(1:2));
    raio_robo = r.robot_diameter / 2;
    if dist_to_target < (raio_robo + 0.01)
        disp(['Alvo alcançado em ', num2str(k * Ts), ' segundos!']);
        n_steps = k;
        break;
    end
    
    u_init_mpc = [u_opt(3:end); u_opt(end-1:end)]; 
    hist_time(k) = tempo_solve;
    r.step();
end

disp(['Simulação concluída em ', num2str(toc), ' segundos.']);
disp('--- RESULTADOS DO BENCHMARK (PANOC) ---');
disp(['Tempo Médio de Solve   : ', num2str(mean(hist_time(1:n_steps)) * 1000), ' ms']);
disp(['Tempo Máximo de Solve  : ', num2str(max(hist_time(1:n_steps)) * 1000), ' ms']);
disp(['Máximo de Iterações    : ', num2str(max(hist_iter(1:n_steps)))]);

r.debug();

% Salva os dados para download na simulação da Georgia Tech
disp('Salvando dados do experimento para download...');
save('dados_nmpc.mat', 'hist_X', 'hist_U', 'hist_iter', 'hist_time', 'Ts', 'n_steps');
disp('Dados salvos com sucesso!');

%% 5. Plotagem das Ações de Controle

% figure('Name', 'Esforço Computacional', 'Color', 'w');
% plot(1:n_steps, hist_iter(1:n_steps), 'k-', 'LineWidth', 1.5);
% xlabel('Passo de Simulação k'); ylabel('Iterações do PANOC');
% title('Convergência com Warm Start');
% grid on;
% 
% figure('Name', 'Tempo Computacional', 'Color', 'w');
% plot(1:n_steps, hist_time(1:n_steps), 'k-', 'LineWidth', 1.5);
% xlabel('Passo de Simulação k'); 
% ylabel('Tempo [s]'); 
% title('Tempos Computacionais');
% yline(0.033, 'r--', 'LineWidth', 1.2);
% legend('Tempo de Solve', 'Limite do Robotarium (33ms)', 'Location', 'best');
% grid on;
% 
% figure('Name', 'Estados do Robô ao Longo do Tempo (hist_X)', 'Color', 'w');
% t_sim_X = (0:n_steps) * Ts; 
% subplot(3, 1, 1);
% hold on; grid on;
% plot(t_sim_X, hist_X(1, 1:n_steps+1), 'b-', 'LineWidth', 1.5);
% yline(x_ref(1), 'g--', 'LineWidth', 1.5); 
% xlabel('Tempo [s]'); ylabel('X [m]');
% title('Evolução da Posição X');
% legend('Trajetória X(t)', 'Alvo X', 'Location', 'best');
% 
% subplot(3, 1, 2);
% hold on; grid on;
% plot(t_sim_X, hist_X(2, 1:n_steps+1), 'r-', 'LineWidth', 1.5);
% yline(x_ref(2), 'g--', 'LineWidth', 1.5); 
% xlabel('Tempo [s]'); ylabel('Y [m]');
% title('Evolução da Posição Y');
% legend('Trajetória Y(t)', 'Alvo Y', 'Location', 'best');
% 
% subplot(3, 1, 3);
% hold on; grid on;
% plot(t_sim_X, hist_X(3, 1:n_steps+1), 'm-', 'LineWidth', 1.5);
% xlabel('Tempo [s]'); ylabel('\theta [rad]');
% title('Evolução da Orientação (\theta)');
% 
% figure('Name', 'Ação de Controle ao Longo do Tempo', 'Color', 'w');
% t_sim = (0:n_steps-1) * Ts;
% subplot(2, 1, 1);
% hold on; grid on;
% stairs(t_sim, hist_U(1, 1:n_steps), 'b-', 'LineWidth', 1.5);
% yline(v_max, 'r--', 'LineWidth', 1.2); 
% yline(v_min, 'r--', 'LineWidth', 1.2); 
% xlabel('Tempo [s]');
% ylabel('v [m/s]');
% title('Velocidade Linear (v)');
% ylim([v_min - 0.1, v_max + 0.1]);
% legend('Ação do NMPC', 'Limites Físicos', 'Location', 'best');
% 
% subplot(2, 1, 2);
% hold on; grid on;
% stairs(t_sim, hist_U(2, 1:n_steps), 'm-', 'LineWidth', 1.5);
% yline(w_max, 'r--', 'LineWidth', 1.2); 
% yline(w_min, 'r--', 'LineWidth', 1.2); 
% xlabel('Tempo [s]');
% ylabel('\omega [rad/s]');
% title('Velocidade Angular (\omega)');
% ylim([w_min - 0.2, w_max + 0.2]);
% legend('Ação do NMPC', 'Limites Físicos', 'Location', 'best');

%% =========================================================================
% FUNÇÕES LOCAIS (WRAPPERS E ADJOINT METHOD)
% =========================================================================
function cost = wrapper_cost(u, params)
    cost_base = build_robot_analytic(u, params);
    
    R_dv = 10; 
    R_dw = 11; 
    
    v = u(1:2:end-1);
    w = u(2:2:end);
    
    cost_smooth = R_dv * sum(diff(v).^2) + R_dw * sum(diff(w).^2);
    cost = cost_base + cost_smooth;
end

function grad = wrapper_grad(u, params)
    [~, grad_base] = build_robot_analytic(u, params);
    
    R_dv = 10;
    R_dw = 11;
    
    grad_smooth = zeros(size(u));
    N_horizonte = length(u) / 2;
    
    for i = 1:N_horizonte-1
        dv = u(2*i+1) - u(2*i-1); 
        grad_smooth(2*i-1) = grad_smooth(2*i-1) - 2 * R_dv * dv;
        grad_smooth(2*i+1) = grad_smooth(2*i+1) + 2 * R_dv * dv;
        
        dw = u(2*i+2) - u(2*i);   
        grad_smooth(2*i)   = grad_smooth(2*i)   - 2 * R_dw * dw;
        grad_smooth(2*i+2) = grad_smooth(2*i+2) + 2 * R_dw * dw;
    end
    
    grad = grad_base + grad_smooth;
end