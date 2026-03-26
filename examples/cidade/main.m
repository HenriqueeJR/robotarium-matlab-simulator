% =========================================================================
% Script: main_simulation.m (NMPC + Geofence Cruz com Buraco Central)
% =========================================================================
clear; clc; close all;

%% 1. Configurações da Simulação e do NMPC
Ts = 0.1;               % Tempo de amostragem
N = 15;                 % Horizonte de predição 
T_sim_total = 1000;       % Tempo total reduzido (escala do mapa é menor)
n_steps = T_sim_total / Ts;

% Limites físicos da plataforma diferencial (Adaptados para a escala de 5m)
v_max = 1;  v_min = -1;
w_max = 1;  w_min = -1;
u_max = repmat([v_max; w_max], N, 1);
u_min = repmat([v_min; w_min], N, 1);

%% 2. Inicialização do Solver PANOC
gamma = 0.01; sigma = 1e-4; max_iter = 400; tol = 1e-3; lbfgs_size = 10;
solver = PanocSolver(gamma, sigma, max_iter, tol, u_min, u_max, lbfgs_size);

% Wrappers locais
solver.cost_func = @wrapper_cost;
solver.grad_func = @wrapper_grad;

%% 3. Condições Iniciais e Parâmetros do Penalty Method
X_k = [-4.5; 0.0; 0.0];     % Estado inicial (ponta do braço esquerdo, virado para direita)
x_ref = [4; 0.1];         % Alvo (ponta do braço superior)
x_obs = [0.0; 0.0];         % Centro da topologia complexa

% Parâmetros do Algoritmo 2 (Penalty Method)
eta_inicial = 1e-5;          % Começa permissivo
eta_max = 1e10;          % Teto de penalidade
omega = 2.0;               % Fator de multiplicação
tolerancia_obs = 1e-5;      % Tolerância para considerar o caminho seguro (\eta_*)

u_init_mpc = zeros(2 * N, 1); 

hist_X = zeros(3, n_steps + 1);
hist_X(:, 1) = X_k;
hist_U = zeros(2, n_steps);
hist_iter = zeros(1, n_steps);
hist_time = zeros(1, n_steps);

% --- SETUP DO PLOT EM TEMPO REAL ---
figure('Name', 'NMPC: Topologia Complexa (Cruz + Buraco)', 'Color', 'w');
hold on; grid on; axis equal;
xlim([-6, 6]); ylim([-6, 6]); % Eixos ajustados para a geometria

% Desenho dos 4 Braços da Cruz (Zonas Seguras)
fill([0 5 5 0], [-1 -1 1 1], 'b', 'FaceAlpha', 0.2, 'EdgeColor', 'b');
fill([-1 1 1 -1], [0 0 5 5], 'b', 'FaceAlpha', 0.2, 'EdgeColor', 'b');
fill([-5 0 0 -5], [-1 -1 1 1], 'b', 'FaceAlpha', 0.2, 'EdgeColor', 'b');
fill([-1 1 1 -1], [-5 -5 0 0], 'b', 'FaceAlpha', 0.2, 'EdgeColor', 'b');

% Desenho do Hub Central e do Buraco
theta_circle = linspace(0, 2*pi, 100);
fill(2*cos(theta_circle), 2*sin(theta_circle), 'b', 'FaceAlpha', 0.2, 'EdgeColor', 'b'); % Hub
fill(1*cos(theta_circle), 1*sin(theta_circle), 'w', 'FaceAlpha', 1.0, 'EdgeColor', 'r', 'LineWidth', 1.5); % Buraco

plot(x_ref(1), x_ref(2), 'g*', 'MarkerSize', 10, 'LineWidth', 2);
h_traj = plot(X_k(1), X_k(2), 'b-', 'LineWidth', 2); 
h_pred = plot(X_k(1), X_k(2), 'k--', 'LineWidth', 1.5); 
h_robot = plot(X_k(1), X_k(2), 'ro', 'MarkerSize', 8, 'MarkerFaceColor', 'r'); 

xlabel('Posição X [m]'); ylabel('Posição Y [m]');
disp('Iniciando simulação NMPC...');
tic;

%% 4. O Loop NMPC (Horizonte Deslizante)
for k = 1:n_steps
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
        
        % Parâmetros da Geometria para a Avaliação
        L_arm = 5.0; W_arm = 1.0; R_out = 2.0; R_in = 1.0;
        
        for i = 1:N
            v_p = u_opt((i-1)*2 + 1);
            w_p = u_opt((i-1)*2 + 2);
            X_pred(1, i+1) = X_pred(1, i) + Ts * v_p * cos(X_pred(3, i));
            X_pred(2, i+1) = X_pred(2, i) + Ts * v_p * sin(X_pred(3, i));
            X_pred(3, i+1) = X_pred(3, i) + Ts * w_p;
            
            x_p = X_pred(1, i+1) - x_obs(1); 
            y_p = X_pred(2, i+1) - x_obs(2);
            
            % Calcula as violações dos 6 elementos
            P1 = max(0, -x_p)^2 + max(0, x_p - L_arm)^2 + max(0, -y_p - W_arm)^2 + max(0, y_p - W_arm)^2;
            P2 = max(0, -x_p - W_arm)^2 + max(0, x_p - W_arm)^2 + max(0, -y_p)^2 + max(0, y_p - L_arm)^2;
            P3 = max(0, -x_p - L_arm)^2 + max(0, x_p)^2 + max(0, -y_p - W_arm)^2 + max(0, y_p - W_arm)^2;
            P4 = max(0, -x_p - W_arm)^2 + max(0, x_p - W_arm)^2 + max(0, -y_p - L_arm)^2 + max(0, y_p)^2;
            P5 = max(0, x_p^2 + y_p^2 - R_out^2)^2;
            P6 = max(0, R_in^2 - (x_p^2 + y_p^2))^2;
            
            % Violação total: Regra do Produto (Contenção) + Soma (Buraco)
            violacao_atual = (P1 * P2 * P3 * P4 * P5) + P6;
            
            if violacao_atual > max_violacao
                max_violacao = violacao_atual;
            end
        end
        
        set(h_pred, 'XData', X_pred(1, :), 'YData', X_pred(2, :));
        title(sprintf('mu = %.1e | Violação = %.4f', eta_obs, max_violacao));
        drawnow;
        
        if (res_norm <= solver.tol) && (max_violacao <= tolerancia_obs)
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
    
    X_k(1) = X_k(1) + Ts * v_cmd * cos(X_k(3));
    X_k(2) = X_k(2) + Ts * v_cmd * sin(X_k(3));
    X_k(3) = X_k(3) + Ts * w_cmd;
    hist_X(:, k+1) = X_k;
    
    set(h_traj, 'XData', hist_X(1, 1:k+1), 'YData', hist_X(2, 1:k+1));
    set(h_robot, 'XData', X_k(1), 'YData', X_k(2));
    drawnow;
        
    u_init_mpc = [u_opt(3:end); u_opt(end-1:end)]; 
    hist_time(k) = hist_time(k) + tempo_solve;
    
    % Critério de paragem apertado para escala pequena
    if norm(X_k(1:2) - x_ref(1:2)) < 0.1
        disp(['Alvo alcançado em ', num2str(k * Ts), ' segundos!']);
        n_steps = k;
        title('Trajetória Concluída');
        break;
    end
end
disp(['Simulação concluída em ', num2str(toc), ' segundos.']);
disp('--- RESULTADOS DO BENCHMARK (PANOC) ---');
disp(['Tempo Médio de Solve   : ', num2str(mean(hist_time(1:n_steps)) * 1000), ' ms']);
disp(['Tempo Máximo de Solve  : ', num2str(max(hist_time(1:n_steps)) * 1000), ' ms']);
disp(['Máximo de Iterações    : ', num2str(max(hist_iter(1:n_steps)))]);

%% 5. Plotagem das Ações de Controle
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
% FUNÇÕES LOCAIS (WRAPPERS E ADJOINT METHOD)
% =========================================================================
function cost = wrapper_cost(u, params)
    cost = build_robot_analytic_old(u, params);
end
function grad = wrapper_grad(u, params)
    [~, grad] = build_robot_analytic_old(u, params);
end