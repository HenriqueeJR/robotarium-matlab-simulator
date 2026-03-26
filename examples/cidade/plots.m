clear; clc; close all;

%% 1. Configurações da Simulação e do NMPC
Ts = 0.1;               
N = 15;                 
T_sim_total = 200;      % Suficiente para chegar ao fim com v=1
n_steps = T_sim_total / Ts;

% Limites físicos
v_max = 1;  v_min = -1;
w_max = 1;  w_min = -1;
u_max = repmat([v_max; w_max], N, 1);
u_min = repmat([v_min; w_min], N, 1);

%% 2. Inicialização do Solver PANOC
gamma_init = 0.01; sigma_init = 1e-4; max_iter = 400; tol = 1e-3; lbfgs_size = 10;
solver = PanocSolver(gamma_init, sigma_init, max_iter, tol, u_min, u_max, lbfgs_size);
solver.cost_func = @wrapper_cost;
solver.grad_func = @wrapper_grad;

%% 3. Definição dos 4 Experimentos
X_k_start = [-4.5; 0.0; 0.0]; % Ponto inicial comum
x_obs = [0.0; 0.0];           % Centro da topologia

% As 4 referências desejadas
x_refs = [ 4.0, -0.1;
           4.0,  0.1;
           0.0,  4.0;
           0.0, -4.0 ]';

num_exps = size(x_refs, 2);
trajetorias_finais = cell(1, num_exps);
cores = {'b', 'm', 'k', 'c'}; % Cores para distinguir as rotas

% Parâmetros do Algoritmo 2
eta_inicial = 1e-5;          
eta_max = 1e10;          
omega = 2.0;               
tolerancia_obs = 1e-5;      

% Cria figura para o acompanhamento em tempo real
fig_realtime = figure('Name', 'Simulação em Tempo Real', 'Color', 'w');

%% 4. Loop de Experimentos (Batch)
for exp_idx = 1:num_exps
    x_ref = x_refs(:, exp_idx);
    disp(['=== Iniciando Experimento ', num2str(exp_idx), ' | Alvo: (', num2str(x_ref(1)), ', ', num2str(x_ref(2)), ') ===']);
    
    % ---> A CORREÇÃO VITAL: Reset do estado interno do solver <---
    solver.gamma = gamma_init;
    solver.sigma = sigma_init;
    
    % Reset das condições para o experimento atual
    X_k = X_k_start;
    u_init_mpc = zeros(2 * N, 1); 
    hist_X = zeros(3, n_steps + 1);
    hist_X(:, 1) = X_k;
    
    % Limpa e redesenha o plot para o experimento atual
    figure(fig_realtime); clf; hold on; grid on; axis equal;
    xlim([-6, 6]); ylim([-6, 6]);
    
    % Desenha Geofence
    fill([0 5 5 0], [-1 -1 1 1], 'b', 'FaceAlpha', 0.2, 'EdgeColor', 'b');
    fill([-1 1 1 -1], [0 0 5 5], 'b', 'FaceAlpha', 0.2, 'EdgeColor', 'b');
    fill([-5 0 0 -5], [-1 -1 1 1], 'b', 'FaceAlpha', 0.2, 'EdgeColor', 'b');
    fill([-1 1 1 -1], [-5 -5 0 0], 'b', 'FaceAlpha', 0.2, 'EdgeColor', 'b');
    theta_circle = linspace(0, 2*pi, 100);
    fill(2*cos(theta_circle), 2*sin(theta_circle), 'b', 'FaceAlpha', 0.2, 'EdgeColor', 'b'); 
    fill(1*cos(theta_circle), 1*sin(theta_circle), 'w', 'FaceAlpha', 1.0, 'EdgeColor', 'r', 'LineWidth', 1.5); 
    
    plot(x_ref(1), x_ref(2), 'g*', 'MarkerSize', 10, 'LineWidth', 2);
    h_traj = plot(X_k(1), X_k(2), cores{exp_idx}, 'LineWidth', 2); 
    h_pred = plot(X_k(1), X_k(2), 'k--', 'LineWidth', 1.5); 
    h_robot = plot(X_k(1), X_k(2), 'ro', 'MarkerSize', 8, 'MarkerFaceColor', 'r'); 
    
    xlabel('Posição X [m]'); ylabel('Posição Y [m]');
    
    % O Loop NMPC
    passos_executados = n_steps;
    for k = 1:n_steps
        eta_obs = eta_inicial;
        u_current = u_init_mpc; 
        
        while eta_obs <= eta_max
            params = [X_k; x_ref; x_obs; eta_obs];
            [u_opt, res_norm, iter_count] = solver.solve(u_current, params);
            
            X_pred = zeros(3, N+1);
            X_pred(:, 1) = X_k;
            max_violacao = 0;
            
            L_arm = 5.0; W_arm = 1.0; R_out = 2.0; R_in = 1.0;
            
            for i = 1:N
                v_p = u_opt((i-1)*2 + 1); w_p = u_opt((i-1)*2 + 2);
                X_pred(1, i+1) = X_pred(1, i) + Ts * v_p * cos(X_pred(3, i));
                X_pred(2, i+1) = X_pred(2, i) + Ts * v_p * sin(X_pred(3, i));
                X_pred(3, i+1) = X_pred(3, i) + Ts * w_p;
                
                x_p = X_pred(1, i+1) - x_obs(1); y_p = X_pred(2, i+1) - x_obs(2);
                
                P1 = max(0, -x_p)^2 + max(0, x_p - L_arm)^2 + max(0, -y_p - W_arm)^2 + max(0, y_p - W_arm)^2;
                P2 = max(0, -x_p - W_arm)^2 + max(0, x_p - W_arm)^2 + max(0, -y_p)^2 + max(0, y_p - L_arm)^2;
                P3 = max(0, -x_p - L_arm)^2 + max(0, x_p)^2 + max(0, -y_p - W_arm)^2 + max(0, y_p - W_arm)^2;
                P4 = max(0, -x_p - W_arm)^2 + max(0, x_p - W_arm)^2 + max(0, -y_p - L_arm)^2 + max(0, y_p)^2;
                P5 = max(0, x_p^2 + y_p^2 - R_out^2)^2;
                P6 = max(0, R_in^2 - (x_p^2 + y_p^2))^2;
                
                violacao_atual = (P1 * P2 * P3 * P4 * P5) + P6;
                if violacao_atual > max_violacao, max_violacao = violacao_atual; end
            end
            
            set(h_pred, 'XData', X_pred(1, :), 'YData', X_pred(2, :));
            title(sprintf('Exp %d | Alvo [%.1f, %.1f] | \\mu = %.1e', exp_idx, x_ref(1), x_ref(2), eta_obs));
            drawnow;
            
            if (res_norm <= solver.tol) && (max_violacao <= tolerancia_obs)
                break; 
            else
                eta_obs = eta_obs * omega;
                u_current = u_opt; 
            end
        end
        
        v_cmd = u_opt(1); w_cmd = u_opt(2);
        
        X_k(1) = X_k(1) + Ts * v_cmd * cos(X_k(3));
        X_k(2) = X_k(2) + Ts * v_cmd * sin(X_k(3));
        X_k(3) = X_k(3) + Ts * w_cmd;
        hist_X(:, k+1) = X_k;
        
        set(h_traj, 'XData', hist_X(1, 1:k+1), 'YData', hist_X(2, 1:k+1));
        set(h_robot, 'XData', X_k(1), 'YData', X_k(2));
        drawnow;
            
        u_init_mpc = [u_opt(3:end); u_opt(end-1:end)]; 
        
        if norm(X_k(1:2) - x_ref(1:2)) < 0.1
            passos_executados = k;
            disp([' > Alvo ', num2str(exp_idx), ' alcançado!']);
            break;
        end
    end
    
    % Guarda a trajetória efetivamente percorrida neste experimento
    trajetorias_finais{exp_idx} = hist_X(:, 1:passos_executados+1);
end

%% 5. Gráfico Final Consolidado (Comparativo)
figure('Name', 'Comparativo das 4 Rotas', 'Color', 'w');
hold on; grid on; axis equal;
xlim([-6, 6]); ylim([-6, 6]);

% Desenha Geofence (Fundo)
fill([0 5 5 0], [-1 -1 1 1], 'b', 'FaceAlpha', 0.1, 'EdgeColor', 'none');
fill([-1 1 1 -1], [0 0 5 5], 'b', 'FaceAlpha', 0.1, 'EdgeColor', 'none');
fill([-5 0 0 -5], [-1 -1 1 1], 'b', 'FaceAlpha', 0.1, 'EdgeColor', 'none');
fill([-1 1 1 -1], [-5 -5 0 0], 'b', 'FaceAlpha', 0.1, 'EdgeColor', 'none');
fill(2*cos(theta_circle), 2*sin(theta_circle), 'b', 'FaceAlpha', 0.1, 'EdgeColor', 'none'); 
fill(1*cos(theta_circle), 1*sin(theta_circle), 'w', 'FaceAlpha', 1.0, 'EdgeColor', 'r', 'LineWidth', 1.5); 

% Desenha o ponto de partida
plot(X_k_start(1), X_k_start(2), 'ks', 'MarkerSize', 10, 'MarkerFaceColor', 'y', 'DisplayName', 'Ponto Inicial');

h_plots = gobjects(num_exps, 1);
leg_labels = cell(num_exps, 1);

% Plota as rotas gravadas e os alvos
for exp_idx = 1:num_exps
    traj = trajetorias_finais{exp_idx};
    x_ref = x_refs(:, exp_idx);
    
    % Estrela do alvo correspondente
    plot(x_ref(1), x_ref(2), 'p', 'Color', cores{exp_idx}, 'MarkerSize', 12, 'MarkerFaceColor', cores{exp_idx}, 'HandleVisibility', 'off');
    
    % Linha da trajetória
    h_plots(exp_idx) = plot(traj(1, :), traj(2, :), cores{exp_idx}, 'LineWidth', 2);
    leg_labels{exp_idx} = sprintf('Rota para [%.1f, %.1f]', x_ref(1), x_ref(2));
end

title('Rotas NMPC: Decisão de Desvio Múltiplo');
xlabel('Posição X [m]'); ylabel('Posição Y [m]');
legend(h_plots, leg_labels, 'Location', 'best');

%% =========================================================================
% FUNÇÕES LOCAIS (WRAPPERS E ADJOINT METHOD)
% =========================================================================
function cost = wrapper_cost(u, params)
    cost = build_robot_analytic_old(u, params);
end
function grad = wrapper_grad(u, params)
    [~, grad] = build_robot_analytic_old(u, params);
end