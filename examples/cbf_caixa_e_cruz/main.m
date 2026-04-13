% =========================================================================
% Script: main_simulation.m (NMPC + CBF Obstáculo Retangular Único)
% =========================================================================
clear; clc; close all;

%% 1. Configurações da Simulação e do NMPC
Ts = 0.033;                 % Tempo de amostragem aumentado (suaviza curvas)
N = 10;                   % Horizonte de predição 
T_sim_total = 50;         % Tempo total
n_steps = round(T_sim_total / Ts);

% Limites físicos da plataforma diferencial
v_max = 0.1;  v_min = -0.1;
w_max = 1.5;  w_min = -1.5;
u_max = repmat([v_max; w_max], N, 1);
u_min = repmat([v_min; w_min], N, 1);

%% 2. Inicialização do Solver PANOC
gamma_panoc = 0.01; sigma = 1e-4; max_iter = 100; tol = 1e-3; lbfgs_size = 10;
solver = PanocSolver(gamma_panoc, sigma, max_iter, tol, u_min, u_max, lbfgs_size);

% Wrappers locais apontando para a nova função da caixa
solver.cost_func = @wrapper_cost;
solver.grad_func = @wrapper_grad;

%% 3. Condições Iniciais e Parâmetros da Geometria
X_k = [-1.2; -1.2; pi/4]; % Estado inicial [x, y, theta]
x_ref = [0.8; 0.9];       % Alvo [x, y]
x_obs = [0.0; 0.0];       % Centro do obstáculo retangular
L_obs = 0.3;              % Meio-comprimento (eixo X)
W_obs = 0.3;              % Meia-largura (eixo Y)
r_rob = 0.1;              % Raio físico do robô

% Parâmetros do Penalty Method
eta_inicial = 1e10;         
eta_max = 1e10;             
omega = 5.0;                
tolerancia_obs = 1e-6;      

u_init_mpc = zeros(2 * N, 1); 
hist_X = zeros(3, n_steps + 1);
hist_X(:, 1) = X_k;
hist_U = zeros(2, n_steps);
hist_iter = zeros(1, n_steps);
hist_time = zeros(1, n_steps);

%% --- SETUP DO PLOT EM TEMPO REAL ---
figure('Name', 'NMPC: Desvio de Obstáculo Retangular (CBF)', 'Color', 'w');
hold on; grid on; axis equal;
xlim([-1.6, 1.6]); ylim([-1.6, 1.6]); 

% --- Desenho do Obstáculo Retangular ---
% Caixa Vermelha Sólida (Obstáculo real)
fill([x_obs(1)-L_obs, x_obs(1)+L_obs, x_obs(1)+L_obs, x_obs(1)-L_obs], ...
     [x_obs(2)-W_obs, x_obs(2)-W_obs, x_obs(2)+W_obs, x_obs(2)+W_obs], ...
     'r', 'FaceAlpha', 0.5, 'EdgeColor', 'r');

% Caixa Tracejada (Margem de segurança inflada)
plot([x_obs(1)-(L_obs+r_rob), x_obs(1)+(L_obs+r_rob), x_obs(1)+(L_obs+r_rob), x_obs(1)-(L_obs+r_rob), x_obs(1)-(L_obs+r_rob)], ...
     [x_obs(2)-(W_obs+r_rob), x_obs(2)-(W_obs+r_rob), x_obs(2)+(W_obs+r_rob), x_obs(2)+(W_obs+r_rob), x_obs(2)-(W_obs+r_rob)], ...
     'r--', 'LineWidth', 1.5);

plot(x_ref(1), x_ref(2), 'g*', 'MarkerSize', 10, 'LineWidth', 2);
h_traj = plot(X_k(1), X_k(2), 'b-', 'LineWidth', 2); 
h_pred = plot(X_k(1), X_k(2), 'k--', 'LineWidth', 1.5); 

theta_rob = linspace(0, 2*pi, 40); 
h_robot_body = fill(X_k(1) + r_rob*cos(theta_rob), X_k(2) + r_rob*sin(theta_rob), ...
                    'y', 'FaceAlpha', 0.4, 'EdgeColor', 'yellow', 'LineWidth', 1.5);
h_robot_body_intern = fill(X_k(1) + (0.055)*cos(theta_rob), X_k(2) + (0.055)*sin(theta_rob), ...
                    'g', 'FaceAlpha', 0.4, 'EdgeColor', 'green', 'LineWidth', 1.5);
h_robot = plot(X_k(1), X_k(2), 'ro', 'MarkerSize', 8, 'MarkerFaceColor', 'r'); 

xlabel('Posição X [m]'); ylabel('Posição Y [m]');
disp('Iniciando simulação NMPC com CBF (Caixa)...');
tic;

%% 4. O Loop NMPC (Horizonte Deslizante)
for k = 1:n_steps
    eta_safe = eta_inicial;
    u_current = u_init_mpc; 
    
    while eta_safe <= eta_max
        % Parâmetros passados para a nova função build_robot_cbf_box
        params = [X_k; x_ref; x_obs; L_obs; W_obs; eta_safe];
        
        t_start = tic;
        [u_opt, res_norm, iter_count] = solver.solve(u_current, params);
        tempo_solve = toc(t_start);
        
        X_pred = zeros(3, N+1);
        X_pred(:, 1) = X_k;
        max_violacao = 0;
       
        % Forward para checar violações do solver
        for i = 1:N
            v_p = u_opt((i-1)*2 + 1);
            w_p = u_opt((i-1)*2 + 2);
            X_pred(1, i+1) = X_pred(1, i) + Ts * v_p * cos(X_pred(3, i));
            X_pred(2, i+1) = X_pred(2, i) + Ts * v_p * sin(X_pred(3, i));
            X_pred(3, i+1) = X_pred(3, i) + Ts * w_p;
            
            x_p = X_pred(1, i+1) - x_obs(1); 
            y_p = X_pred(2, i+1) - x_obs(2);
            
            % Calcula a violação usando a regra do produto
            dx_p = max(0, L_obs + r_rob - abs(x_p));
            dy_p = max(0, W_obs + r_rob - abs(y_p));
            violacao_atual = (dx_p^2) * (dy_p^2);
            
            if violacao_atual > max_violacao
                max_violacao = violacao_atual;
            end
        end
        
        set(h_pred, 'XData', X_pred(1, :), 'YData', X_pred(2, :));
        title(sprintf('eta\\_safe = %.1e | Violação Máx = %.6f', eta_safe, max_violacao));
        drawnow;
        
        % Critério de aceitação
        if (res_norm <= solver.tol) && (max_violacao <= tolerancia_obs)
            break; 
        else
            eta_safe = eta_safe * omega; 
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
    set(h_robot_body, 'XData', X_k(1) + r_rob*cos(theta_rob), ...
                      'YData', X_k(2) + r_rob*sin(theta_rob));
    set(h_robot_body_intern, 'XData', X_k(1) + (0.055)*cos(theta_rob), ...
                      'YData', X_k(2) + (0.055)*sin(theta_rob));
    drawnow;
        
    u_init_mpc = [u_opt(3:end); u_opt(end-1:end)]; 
    hist_time(k) = hist_time(k) + tempo_solve;
    
    if norm(X_k(1:2) - x_ref(1:2)) < 0.055
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


