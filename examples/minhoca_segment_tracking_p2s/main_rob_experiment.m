% =========================================================================
% Main Simulation - NMPC com CBF Dinâmico e Generalized P2S-HSD
% =========================================================================
clear; clc; close all;

%% 1. Setup the Robotarium object
Nr = 1;
posicoes_iniciais = [1.2; -0.5; pi/2]; 
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
x_ref = [-1.3,  -1.3,  1.20,  1.20;  
         -0.6,  -0.5,  0.25, -0.25];

% =========================================================================
% DEFINIÇÃO DOS BLOCOS DO CORREDOR
% =========================================================================
b1_xmin = -1.5; b1_xmax = -0.5; b1_ymin = -0.75; b1_ymax = -0.25;
b2_xmin = -0.5; b2_xmax = 0.0;  b2_ymin = -0.75; b2_ymax = 0.50;
b3_xmin = 0.0;  b3_xmax = 1.4;  b3_ymin = 0.1;   b3_ymax = 0.5;
b4_xmin = 0.9;  b4_xmax = 1.4;  b4_ymin = -0.75; b4_ymax = 0.1;
r_rob      = 0.15;

blocks_params = [b1_xmin; b1_xmax+r_rob; b1_ymin; b1_ymax-r_rob; ...
                 b2_xmin+r_rob; b2_xmax-r_rob; b2_ymin; b2_ymax; ...
                 b3_xmin-r_rob; b3_xmax; b3_ymin+r_rob; b3_ymax; ...
                 b4_xmin+r_rob; b4_xmax; b4_ymin; b4_ymax+r_rob];

% =========================================================================
% PESOS DO NMPC
% =========================================================================            
eta_safe   = 1e9;           
gamma_safe = 0.8;  
eta_term   = 800.0;
eta_eq     = 5.0;
mu_safe    = 1e4;
kappa_s    = 200;

w_init = zeros(nW,1);
w_init(2*N+1:2*N+2) = [-1.0; -0.5];
w_init(2*N+5:2*N+6) = [-0.5; -0.25]; 
w_init(2*N+7:2*N+8) = [0; 0.1]; 
w_init(2*N+9:2*N+10)= [0.75; 0.35];

hist_X = zeros(3, n_steps + 1);
hist_X(:, 1) = X_k;

% Históricos Originais
hist_U  = zeros(2, n_steps); 
hist_us = zeros(2, n_steps); 
hist_iter = zeros(1, n_steps);
hist_time = zeros(1, n_steps);

% =========================================================================
% NOVOS HISTÓRICOS PARA PLOTAGEM DE CUSTOS
% =========================================================================
hist_cost_stage    = zeros(1, n_steps);
hist_cost_cbf      = zeros(1, n_steps);
hist_cost_term     = zeros(1, n_steps);
hist_cost_eq       = zeros(1, n_steps);
hist_cost_elastic  = zeros(1, n_steps);
hist_cost_geofence = zeros(1, n_steps);

%% --- SETUP DO PLOT DIRETO NO ROBOTARIUM ---
ax = gca;
hold(ax, 'on');

h_azul = fill(ax, [b1_xmin, b1_xmax, b1_xmax, b1_xmin], [b1_ymin, b1_ymin, b1_ymax, b1_ymax], 'b', 'FaceAlpha', 0.2, 'EdgeColor', 'none');
h_verm = fill(ax, [b2_xmin, b2_xmax, b2_xmax, b2_xmin], [b2_ymin, b2_ymin, b2_ymax, b2_ymax], 'r', 'FaceAlpha', 0.2, 'EdgeColor', 'none');
h_verde = fill(ax, [b3_xmin, b3_xmax, b3_xmax, b3_xmin], [b3_ymin, b3_ymin, b3_ymax, b3_ymax], 'g', 'FaceAlpha', 0.2, 'EdgeColor', 'none');
h_ciano = fill(ax, [b4_xmin, b4_xmax, b4_xmax, b4_xmin], [b4_ymin, b4_ymin, b4_ymax, b4_ymax], 'c', 'FaceAlpha', 0.2, 'EdgeColor', 'none');

plot(ax, [blocks_params(1), blocks_params(2), blocks_params(2), blocks_params(1), blocks_params(1)], ...
         [blocks_params(3), blocks_params(3), blocks_params(4), blocks_params(4), blocks_params(3)], 'b--', 'LineWidth', 1.5);
plot(ax, [blocks_params(5), blocks_params(6), blocks_params(6), blocks_params(5), blocks_params(5)], ...
         [blocks_params(7), blocks_params(7), blocks_params(8), blocks_params(8), blocks_params(7)], 'r--', 'LineWidth', 1.5);
plot(ax, [blocks_params(9), blocks_params(10), blocks_params(10), blocks_params(9), blocks_params(9)], ...
         [blocks_params(11), blocks_params(11), blocks_params(12), blocks_params(12), blocks_params(11)], 'g--', 'LineWidth', 1.5);
plot(ax, [blocks_params(13), blocks_params(14), blocks_params(14), blocks_params(13), blocks_params(13)], ...
         [blocks_params(15), blocks_params(15), blocks_params(16), blocks_params(16), blocks_params(15)], 'c--', 'LineWidth', 1.5);

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
    
    hist_U(:, k)  = [v_cmd; w_cmd];
    hist_us(:, k) = w_opt(2*N+3 : 2*N+4);
    hist_iter(k) = iter_count;
    hist_time(k) = tempo_solve;
    
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
    us_opt = w_opt(2*N+3:2*N+4);
    r1_opt = w_opt(2*N+5:2*N+6);
    r2_opt = w_opt(2*N+7:2*N+8);
    r3_opt = w_opt(2*N+9:2*N+10);
    
    % =====================================================================
    % EXTRAÇÃO DE CUSTOS PARA PLOTAGEM
    % =====================================================================
    Q_p_plot = 5; R_v_p_plot = 0.5; R_w_p_plot = 1; h_p_plot = 0.05;
    c_stage = 0; c_cbf = 0;
    
    for i = 1:N
        v_p = w_opt((i-1)*2 + 1); w_p = w_opt((i-1)*2 + 2);
        % Custo de Estágio
        c_stage = c_stage + Q_p_plot * norm(X_pred(1:2, i) - xs_opt)^2 + ...
                  R_v_p_plot * (v_p - us_opt(1))^2 + R_w_p_plot * (w_p - us_opt(2))^2;
        % Penalidade CBF
        [P_k_p, ~] = calc_point_p2s_penalty(X_pred(1:2, i), blocks_params, h_p_plot);
        [P_next_p, ~] = calc_point_p2s_penalty(X_pred(1:2, i+1), blocks_params, h_p_plot);
        g_corr = (1 - gamma_safe) * (-P_k_p) - (-P_next_p);
        c_cbf = c_cbf + eta_safe * max(0, g_corr)^2;
    end
    
    c_term = eta_term * norm(X_pred(1:2, N+1) - xs_opt)^2;
    c_eq   = eta_eq * Ts^2 * (us_opt(1)^2 + us_opt(2)^2);
    c_elast = kappa_s * (norm(r1_opt - xs_opt)^2 + norm(r2_opt - r1_opt)^2 + ...
                         norm(r3_opt - r2_opt)^2 + norm(x_ref_current - r3_opt)^2);
                     
    [Pseg0, ~, ~] = calc_segment_p2s_penalty(xs_opt, r1_opt, blocks_params, h_p_plot);
    [Pseg1, ~, ~] = calc_segment_p2s_penalty(r1_opt, r2_opt, blocks_params, h_p_plot);
    [Pseg2, ~, ~] = calc_segment_p2s_penalty(r2_opt, r3_opt, blocks_params, h_p_plot);
    [Pseg3, ~, ~] = calc_segment_p2s_penalty(r3_opt, x_ref_current, blocks_params, h_p_plot);
    c_geo = mu_safe * (Pseg0 + Pseg1 + Pseg2 + Pseg3);
    
    hist_cost_stage(k)    = c_stage;
    hist_cost_cbf(k)      = c_cbf;
    hist_cost_term(k)     = c_term;
    hist_cost_eq(k)       = c_eq;
    hist_cost_elastic(k)  = c_elast;
    hist_cost_geofence(k) = c_geo;
    % =====================================================================
    
    set(h_xs,'XData',xs_opt(1),'YData',xs_opt(2));
    set(h_r1, 'XData', r1_opt(1), 'YData', r1_opt(2));
    set(h_r2, 'XData', r2_opt(1), 'YData', r2_opt(2));
    set(h_r3, 'XData', r3_opt(1), 'YData', r3_opt(2));
    drawnow;
    
    %% Warm start
    U_opt  = w_opt(1:2*N);
    U_warm = [U_opt(3:end); U_opt(end-1:end)];
    w_init = [U_warm; xs_opt; us_opt; r1_opt; r2_opt; r3_opt];
    
    %% Gestão Inteligente de Waypoints
    if norm(X_k(1:2) - x_ref_current(1:2)) < 0.15
        disp(['Alvo alcançado em ', num2str(k * Ts), ' segundos!']);
        break; % <--- COMENTADO PARA NÃO ABORTAR NOS WAYPOINTS INTERMEDIÁRIOS
        
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

%% 6. Plotagem das Ações de Controle e Estados
figure('Name', 'Ação de Controle ao Longo do Tempo', 'Color', 'w');
t_sim = (0:n_steps-1) * Ts;

subplot(2, 1, 1); hold on; grid on;
stairs(t_sim, hist_U(1, 1:n_steps), 'b-', 'LineWidth', 2);
stairs(t_sim, hist_us(1, 1:n_steps), 'c--', 'LineWidth', 1.5); 
yline(v_max, 'r--', 'LineWidth', 1.2); yline(v_min, 'r--', 'LineWidth', 2);
xlabel('Tempo [s]'); ylabel('v [m/s]'); title('Velocidade Linear');
legend('Ação Real (v)', 'Ação de Equilíbrio (v_s)', 'Limites', 'Location', 'best');
ylim([v_min - 0.1, v_max + 0.1]);

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
legend('Tempo de Solve', 'Limite Robotarium', 'Location', 'best');
ylim([0 0.035]);
grid on;

subplot(2, 1, 2)
plot(1:n_steps, hist_iter(1:n_steps), 'k-', 'LineWidth', 1.5);
xlabel('Passo de Simulação k'); ylabel('Iterações do PANOC');
title('Convergência com Warm Start');
grid on;
fontsize(18, "points")

%% 7. Plotagem da Evolução dos Custos (NOVO)
figure('Name', 'Evolução dos Componentes da Função de Custo', 'Color', 'w');
hold on; grid on;

% Nota: O '+ 1e-6' garante que valores exatamente zero não gerem erro no plot logarítmico
semilogy(t_sim, hist_cost_stage(1:n_steps) + 1e-6, 'LineWidth', 2, 'DisplayName', 'Custo de Estágio (Trajetória)');
semilogy(t_sim, hist_cost_term(1:n_steps) + 1e-6, 'LineWidth', 2, 'DisplayName', 'Custo Terminal (Âncora xs)');
semilogy(t_sim, hist_cost_eq(1:n_steps) + 1e-6, 'LineWidth', 2, 'DisplayName', 'Custo de Equilíbrio (Velocidade Estacionária)');
semilogy(t_sim, hist_cost_elastic(1:n_steps) + 1e-6, 'LineWidth', 2, 'DisplayName', 'Custo Elástico (Molas)');
semilogy(t_sim, hist_cost_geofence(1:n_steps) + 1e-6, 'LineWidth', 2, 'DisplayName', 'Penalidade Geofence (Segmentos P2S)');
semilogy(t_sim, hist_cost_cbf(1:n_steps) + 1e-6, 'LineWidth', 2, 'DisplayName', 'Penalidade CBF Dinâmica (P2S)');

xlabel('Tempo [s]');
ylabel('Valor do Custo (Escala Logarítmica)');
title('Dinâmica de Competição dos Pesos do NMPC');
legend('Location', 'bestoutside');
fontsize(14, "points");

% =========================================================================
% FUNÇÃO BASE: Generalized P2S-HSD (Phi e Phi')
% =========================================================================
function [val, grad] = phi_func(s, h)
    %#codegen
    if s >= 0
        val = (s^3) / (2 * (s + h));
        grad = (s^2 * (2*s + 3*h)) / (2 * (s + h)^2);
    else
        val = 0;
        grad = 0;
    end
end

% =========================================================================
% FUNÇÃO AUXILIAR: P2S-HSD para UM Polítopo Convexo
% =========================================================================
function [P, gP] = get_single_block_p2s(pt, blk, h)
    %#codegen
    x_pos = pt(1); y_pos = pt(2);
    
    s1 = blk(1) - x_pos; 
    s2 = x_pos - blk(2); 
    s3 = blk(3) - y_pos; 
    s4 = y_pos - blk(4); 
    
    [v1, g1] = phi_func(s1, h);
    [v2, g2] = phi_func(s2, h);
    [v3, g3] = phi_func(s3, h);
    [v4, g4] = phi_func(s4, h);
    
    P = 0.25 * (v1 + v2 + v3 + v4);
    
    gP = zeros(2,1);
    gP(1) = 0.25 * (-g1 + g2);
    gP(2) = 0.25 * (-g3 + g4);
end

% =========================================================================
% FUNÇÃO AUXILIAR: Mínimo Suave Base (Smooth Min)
% =========================================================================
function [M, gM] = smooth_min_func(a, b, ga, gb)
    %#codegen
    epsilon = 1e-10; % Fator de suavização Numérica
    diff = a - b;
    delta = sqrt(diff^2 + epsilon);
    M = 0.5 * (a + b - delta);
    % O gradiente repassa perfeitamente a direção correspondente ao menor valor
    gM = 0.5 * (ga + gb - (diff / delta) * (ga - gb));
end

% =========================================================================
% FUNÇÃO AUXILIAR: Penalidade de Segmento (Contenção Convexa Suavizada)
% =========================================================================
function [Cost, grad_pa, grad_pb] = calc_segment_p2s_penalty(pa, pb, blocks, h)
    %#codegen
    [Pa1, gPa1] = get_single_block_p2s(pa, blocks(1:4), h);
    [Pa2, gPa2] = get_single_block_p2s(pa, blocks(5:8), h);
    [Pa3, gPa3] = get_single_block_p2s(pa, blocks(9:12), h);
    [Pa4, gPa4] = get_single_block_p2s(pa, blocks(13:16), h);
    
    [Pb1, gPb1] = get_single_block_p2s(pb, blocks(1:4), h);
    [Pb2, gPb2] = get_single_block_p2s(pb, blocks(5:8), h);
    [Pb3, gPb3] = get_single_block_p2s(pb, blocks(9:12), h);
    [Pb4, gPb4] = get_single_block_p2s(pb, blocks(13:16), h);
    
    C1 = Pa1 + Pb1;
    C2 = Pa2 + Pb2;
    C3 = Pa3 + Pb3;
    C4 = Pa4 + Pb4;
    
    gC1 = [gPa1; gPb1];
    gC2 = [gPa2; gPb2];
    gC3 = [gPa3; gPb3];
    gC4 = [gPa4; gPb4];
    
    [M12, gM12] = smooth_min_func(C1, C2, gC1, gC2);
    [M34, gM34] = smooth_min_func(C3, C4, gC3, gC4);
    
    [Cost, gTotal] = smooth_min_func(M12, M34, gM12, gM34);
    
    grad_pa = gTotal(1:2);
    grad_pb = gTotal(3:4);
end

% =========================================================================
% FUNÇÃO AUXILIAR: Penalidade Ponto a Ponto (Smooth Min para a CBF)
% =========================================================================
function [P_total, grad_P] = calc_point_p2s_penalty(pt, blocks, h)
    %#codegen
    [Pa, gPa] = get_single_block_p2s(pt, blocks(1:4), h);
    [Pv, gPv] = get_single_block_p2s(pt, blocks(5:8), h);
    [Pg, gPg] = get_single_block_p2s(pt, blocks(9:12), h);
    [Pc, gPc] = get_single_block_p2s(pt, blocks(13:16), h);
    
    [P1, g1] = smooth_min_func(Pa, Pv, gPa, gPv);
    [P2, g2] = smooth_min_func(Pg, Pc, gPg, gPc);
    [P_total, grad_P] = smooth_min_func(P1, P2, g1, g2);
end