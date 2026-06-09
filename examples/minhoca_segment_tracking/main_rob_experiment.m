% =========================================================================
% Main Simulation - NMPC com CBF Dinâmico e Generalized P2S-HSD
% =========================================================================
clear; clc; close all;

%% 1. Setup the Robotarium object
Nr = 1;
%posicoes_iniciais = [1.2; -0.5; pi/2]; 
posicoes_iniciais = [-1.2; -0.5; 0]; 
r = Robotarium('NumberOfRobots', Nr, 'ShowFigure', true, 'InitialConditions', posicoes_iniciais);

%% 2. Configurações da Simulação e do NMPC
Ts = 0.033;                 
N = 20;                     
T_sim_total = 120;           
n_steps = round(T_sim_total / Ts);

v_max = 0.1; v_min = 0.0;
w_max = 1.5;  w_min = -1.5;


nW = 2*N + 10; 

W_max = [repmat([v_max; w_max], N, 1);
         3; 2;           % xs
         v_max; w_max;   % us
         3; 2;           % r1
         3; 2;           % r2
         3; 2];          % r3
         
W_min = [repmat([v_min; w_min], N, 1);
        -3; -2;          % xs
         v_min; w_min;   % us
        -3; -2;          % r1
        -3; -2;          % r2
        -3; -2];         % r3
         
%% 3. Inicialização do Solver PANOC
gamma_panoc = 0.01; sigma = 1e-4; max_iter = 1000; tol = 1e-3; lbfgs_size = 1000;
solver = PanocSolver(gamma_panoc, sigma, max_iter, tol, W_min, W_max, lbfgs_size);

if exist('wrapper_cost_mex', 'file') == 3 && exist('wrapper_grad_mex', 'file') == 3
    disp('MEX files detectados! Rodando versão compilada.');
    solver.cost_func = @wrapper_cost_mex;
    solver.grad_func = @wrapper_grad_mex;
else
    disp('Rodando versão nativa .m. Lembre-se de compilar (codegen) com o novo tamanho (30)!');
    solver.cost_func = @wrapper_cost;
    solver.grad_func = @wrapper_grad;
end

%% 4. Condições Iniciais e Parâmetros Geométricos
X_k = posicoes_iniciais;  

% Waypoints (Vermelho -> Verde -> Verde -> Ciano)
% x_ref = [-1.3,  -1.3,  1.20,  1.20;  
%          -0.5,  -0.5,  0.25, -0.25];
x_ref = [1.2,  -1.3,  1.20,  1.20;  
         -0.5,  -0.5,  0.25, -0.25];

% =========================================================================
% DEFINIÇÃO DOS BLOCOS DO CORREDOR (x_min, x_max, y_min, y_max) [Metros]
% =========================================================================
% 1. Bloco Azul
b1_xmin = -1.5; b1_xmax = -0.5; b1_ymin = -0.75; b1_ymax = -0.25;
% 2. Bloco Vermelho
b2_xmin = -0.5; b2_xmax = 0.0;  b2_ymin = -0.75; b2_ymax = 0.50;
% 3. Bloco Verde
b3_xmin = 0.0;  b3_xmax = 1.4;  b3_ymin = 0.1;   b3_ymax = 0.5;
% 4. Bloco Ciano
b4_xmin = 0.9;  b4_xmax = 1.4;  b4_ymin = -0.75; b4_ymax = 0.1;

r_rob      = 0.15;
blocks_params = [b1_xmin; b1_xmax+r_rob; b1_ymin; b1_ymax-r_rob; ...
                 b2_xmin+r_rob; b2_xmax-r_rob; b2_ymin; b2_ymax; ...
                 b3_xmin-r_rob; b3_xmax; b3_ymin+r_rob; b3_ymax; ...
                 b4_xmin+r_rob; b4_xmax; b4_ymin; b4_ymax+r_rob];

% =========================================================================
% PESOS DO NMPC
% =========================================================================            
eta_safe   = 1e3;           
gamma_safe = 0.8;  
eta_term   = 1200.0;
eta_eq     = 500.0;
mu_safe    = 1e4;
kappa_s    = 200;

w_init = zeros(nW,1);
w_init(2*N+1:2*N+2) = [-1.0; -0.5];
w_init(2*N+5:2*N+6) = [-0.5; -0.25]; 
w_init(2*N+7:2*N+8) = [0; 0.1]; 
w_init(2*N+9:2*N+10)= [0.75; 0.35];

hist_X = zeros(3, n_steps + 1);
hist_X(:, 1) = X_k;

% Históricos de Controle
hist_U  = zeros(2, n_steps); % Ação de controle executada (v, w)
hist_us = zeros(2, n_steps); % Ação de controle de equilíbrio (v_s, w_s)

hist_iter = zeros(1, n_steps);
hist_time = zeros(1, n_steps);

%% --- SETUP DO PLOT DIRETO NO ROBOTARIUM ---
ax = gca;
hold(ax, 'on');

% Plot Dinâmico dos Blocos
h_azul = fill(ax, [b1_xmin, b1_xmax, b1_xmax, b1_xmin], [b1_ymin, b1_ymin, b1_ymax, b1_ymax], 'b', 'FaceAlpha', 0.2, 'EdgeColor', 'none');
h_verm = fill(ax, [b2_xmin, b2_xmax, b2_xmax, b2_xmin], [b2_ymin, b2_ymin, b2_ymax, b2_ymax], 'r', 'FaceAlpha', 0.2, 'EdgeColor', 'none');
h_verde = fill(ax, [b3_xmin, b3_xmax, b3_xmax, b3_xmin], [b3_ymin, b3_ymin, b3_ymax, b3_ymax], 'g', 'FaceAlpha', 0.2, 'EdgeColor', 'none');
h_ciano = fill(ax, [b4_xmin, b4_xmax, b4_xmax, b4_xmin], [b4_ymin, b4_ymin, b4_ymax, b4_ymax], 'c', 'FaceAlpha', 0.2, 'EdgeColor', 'none');

h_ref = plot(ax, x_ref(1,1), x_ref(2,1), 'g*', 'MarkerSize', 20, 'LineWidth', 20);
h_traj = plot(ax, X_k(1), X_k(2), 'black', 'LineWidth', 8); 
h_pred = plot(ax, X_k(1), X_k(2), 'black--', 'LineWidth', 15); 

theta_circle = linspace(0, 2*pi, 100);
h_robot_body = fill(ax, X_k(1) + r_rob*cos(theta_circle), X_k(2) + r_rob*sin(theta_circle), 'y', 'FaceAlpha', 0.75, 'EdgeColor', 'yellow', 'LineWidth', 1.5);
h_robot_body_intern = fill(ax, X_k(1) + (0.07)*cos(theta_circle), X_k(2) + (0.07)*sin(theta_circle), 'g', 'FaceAlpha', 0.75, 'EdgeColor', 'green', 'LineWidth', 1.5);

h_xs    = plot(ax, X_k(1),X_k(2),'mo','MarkerFaceColor','m');
h_r1    = plot(ax, X_k(1),X_k(2),'mo','MarkerFaceColor','blue');
h_r2    = plot(ax, X_k(1),X_k(2),'mo','MarkerFaceColor','blue');
h_r3    = plot(ax, X_k(1),X_k(2),'mo','MarkerFaceColor','blue');

uistack(h_azul, 'bottom'); uistack(h_verm, 'bottom'); 
uistack(h_verde, 'bottom'); uistack(h_ciano, 'bottom');
uistack(h_traj, 'bottom'); uistack(h_pred, 'bottom');

disp('Iniciando simulação NMPC no Robotarium...');
tic;
x_ref_current = x_ref(:,1);

%% 5. O Loop NMPC
for k = 1:n_steps
    X_k = r.get_poses();
    hist_X(:, k+1) = X_k;
     
    % Novo Vetor Params (Tamanho Exato: 30)
    params = [X_k; x_ref_current; eta_safe; gamma_safe; N; Ts; r_rob; blocks_params; eta_term; eta_eq; mu_safe; kappa_s];
    
    t_start = tic;
    [w_opt, res_norm, iter_count] = solver.solve(w_init, params);
    tempo_solve = toc(t_start);
    
    % --- Simulação Visual da Predição ---
    X_pred = zeros(3, N+1);
    X_pred(:, 1) = X_k;
    for i = 1:N
        v_p = w_opt((i-1)*2 + 1);
        w_p = w_opt((i-1)*2 + 2);
        X_pred(1, i+1) = X_pred(1, i) + Ts * v_p * cos(X_pred(3, i));
        X_pred(2, i+1) = X_pred(2, i) + Ts * v_p * sin(X_pred(3, i));
        X_pred(3, i+1) = X_pred(3, i) + Ts * w_p;
    end
    set(h_pred, 'XData', X_pred(1, :), 'YData', X_pred(2, :));
    
    v_cmd = w_opt(1);
    w_cmd = w_opt(2);
    
    % Armazena a ação executada e a ação de equilíbrio (us)
    hist_U(:, k)  = [v_cmd; w_cmd];
    hist_us(:, k) = w_opt(2*N+3 : 2*N+4);
    
    hist_iter(k) = iter_count;
    hist_time(k) = tempo_solve;
    
    % Clip de Segurança Hardware
    lim_v = r.max_linear_velocity * 0.99;
    lim_w = r.max_angular_velocity * 0.99;
    v_cmd_safe = max(min(v_cmd, lim_v), -lim_v);
    w_cmd_safe = max(min(w_cmd, lim_w), -lim_w);
    
    r.set_velocities(1:Nr, [v_cmd_safe; w_cmd_safe]);
    
    set(h_traj, 'XData', hist_X(1, 1:k+1), 'YData', hist_X(2, 1:k+1));
    d_off = 0.035; 
    x_centro = X_k(1) + d_off * cos(X_k(3));
    y_centro = X_k(2) + d_off * sin(X_k(3));
    
    set(h_robot_body, 'XData', x_centro + r_rob*cos(theta_circle), 'YData', y_centro + r_rob*sin(theta_circle));
    set(h_robot_body_intern, 'XData', x_centro + (0.07)*cos(theta_circle), 'YData', y_centro + (0.07)*sin(theta_circle));
    
    xs_opt = w_opt(2*N+1:2*N+2);
    r1_opt = w_opt(2*N+5:2*N+6);
    r2_opt = w_opt(2*N+7:2*N+8);
    r3_opt = w_opt(2*N+9:2*N+10);
    
    set(h_xs,'XData',xs_opt(1),'YData',xs_opt(2));
    set(h_r1, 'XData', r1_opt(1), 'YData', r1_opt(2));
    set(h_r2, 'XData', r2_opt(1), 'YData', r2_opt(2));
    set(h_r3, 'XData', r3_opt(1), 'YData', r3_opt(2));
    drawnow;
    
    %% Warm start
    U_opt  = w_opt(1:2*N);
    xs_opt = w_opt(2*N+1:2*N+2);
    us_opt = w_opt(2*N+3:2*N+4);
    
    % CORREÇÃO 3: Faltavam os nós artificiais no vetor de Warm Start!
    U_warm = [U_opt(3:end); U_opt(end-1:end)];
    w_init = [U_warm; xs_opt; us_opt; r1_opt; r2_opt; r3_opt];
    
    %% Gestão Inteligente de Waypoints
    if norm(X_k(1:2) - x_ref_current(1:2)) < 0.15
        disp(['Alvo alcançado em ', num2str(k * Ts), ' segundos!']);
        break;
        
        idx_atual = find(vecnorm(x_ref - x_ref_current, 2, 1) < 1e-3, 1);
        
        if ~isempty(idx_atual) && idx_atual < size(x_ref, 2)
            x_ref_current = x_ref(:, idx_atual + 1);
            set(h_ref, 'XData', x_ref_current(1), 'YData', x_ref_current(2));
        else
            n_steps = k;
            title(ax, 'Trajetória Concluída com Sucesso');
            break;
        end
    end
    r.step();
end

disp(['Simulação concluída em ', num2str(toc), ' segundos.']);
disp('--- RESULTADOS DO BENCHMARK (PANOC) ---');
disp(['Tempo Médio de Solve   : ', num2str(mean(hist_time(1:n_steps)) * 1000), ' ms']);
disp(['Tempo Máximo de Solve  : ', num2str(max(hist_time(1:n_steps)) * 1000), ' ms']);
disp(['Máximo de Iterações    : ', num2str(max(hist_iter(1:n_steps)))]);

save('dados_nmpc.mat', 'hist_X', 'hist_U', 'hist_us', 'hist_iter', 'hist_time', 'Ts', 'n_steps');
disp('Dados salvos com sucesso!');
r.debug();

%% 6. Plotagem das Ações de Controle e Estados (Pós Simulação)
figure('Name', 'Ação de Controle ao Longo do Tempo', 'Color', 'w');
t_sim = (0:n_steps-1) * Ts;

% Subplot da Velocidade Linear (v e v_s)
subplot(2, 1, 1); hold on; grid on;
stairs(t_sim, hist_U(1, 1:n_steps), 'b-', 'LineWidth', 2);
stairs(t_sim, hist_us(1, 1:n_steps), 'c--', 'LineWidth', 1.5); 
yline(v_max, 'r--', 'LineWidth', 1.2); yline(v_min, 'r--', 'LineWidth', 2);
xlabel('Tempo [s]'); ylabel('v [m/s]'); title('Velocidade Linear');
legend('Ação Real (v)', 'Ação de Equilíbrio (v_s)', 'Limites', 'Location', 'best');
ylim([v_min - 0.1, v_max + 0.1]);

% Subplot da Velocidade Angular (w e w_s)
subplot(2, 1, 2); hold on; grid on;
stairs(t_sim, hist_U(2, 1:n_steps), 'm-', 'LineWidth', 2);
stairs(t_sim, hist_us(2, 1:n_steps), 'k--', 'LineWidth', 1.5); 
yline(w_max, 'r--', 'LineWidth', 1.2); yline(w_min, 'r--', 'LineWidth', 2);
xlabel('Tempo [s]'); ylabel('\omega [rad/s]'); title('Velocidade Angular');
legend('Ação Real (\omega)', 'Ação de Equilíbrio (\omega_s)', 'Limites', 'Location', 'best');
ylim([w_min - 0.2, w_max + 0.2]);
fontsize(18, "points")

figure('Name', 'Tempo Computacional', 'Color', 'w');
subplot(2, 1, 1);
plot(1:n_steps, hist_time(1:n_steps), 'k-', 'LineWidth', 1.5);
xlabel('Passo de Simulação k'); ylabel('Tempo [s]');
title('Tempos Computacionais');
yline(0.033, 'r--', 'LineWidth', 2);
legend('Tempo de Solve', 'Limite do Robotarium (33ms)', 'Location', 'best');
ylim([0 0.035]);
grid on;

subplot(2, 1, 2)
plot(1:n_steps, hist_iter(1:n_steps), 'k-', 'LineWidth', 1.5);
xlabel('Passo de Simulação k'); ylabel('Iterações do PANOC');
title('Convergência com Warm Start');
grid on;
fontsize(18, "points")