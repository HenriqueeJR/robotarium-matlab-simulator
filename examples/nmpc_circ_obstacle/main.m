clear; clc; close all;

% 1. Setup the Robotarium object
Nr = 1;
posicoes_iniciais = zeros(3, Nr);
posicoes_iniciais(1, 1) = -1.5;   % Posição X (esquerda)
posicoes_iniciais(2, 1) = -0.9;    % Posição Y (centro)
posicoes_iniciais(3, 1) = 0.5259;   

r = Robotarium('NumberOfRobots', Nr, 'ShowFigure', true, 'InitialConditions', posicoes_iniciais);

%% Nonlinear MPC Setup
Ts = 0.033; % Tempo de amostragem
N = 70;

v_max = 0.1; 
v_min = -v_max;
w_max = 1.5; 
w_min = -w_max;
u_max = repmat([v_max; w_max], N, 1);
u_min = repmat([v_min; w_min], N, 1);

gamma = 0.001; sigma = 1e-4; max_iter = 100; tol = 1e-3; lbfgs_size = 10;
solver = PanocSolver(gamma, sigma, max_iter, tol, u_min, u_max, lbfgs_size);
solver.cost_func = @wrapper_cost;
solver.grad_func = @wrapper_grad;

X_k = posicoes_iniciais; % Estado inicial: [x, y, theta]
x_ref = [1.5; 0.85];
x_obs = [0.0; 0.0; 0.2];

u_init = zeros(2 * N, 1);
%% --- SETUP DO PLOT DIRETO NO ROBOTARIUM ---
% Pegamos os eixos da figura que o Robotarium acabou de criar
ax = gca;
hold(ax, 'on');

% 1. Desenha os elementos estáticos (Alvo e Obstáculo)
h_alvo = plot(ax, x_ref(1), x_ref(2), 'g*', 'MarkerSize', 10, 'LineWidth', 2);

theta_circle = linspace(0, 2*pi, 100);
obs_x_plot = x_obs(1) + x_obs(3) * cos(theta_circle);
obs_y_plot = x_obs(2) + x_obs(3) * sin(theta_circle);
h_obs = fill(ax, obs_x_plot, obs_y_plot, [1 0.5 0.5], 'EdgeColor', 'r', 'FaceAlpha', 0.5);

% 2. Inicializa os elementos dinâmicos (Trajetória e Predição)
h_traj = plot(ax, X_k(1), X_k(2), 'b-', 'LineWidth', 2); % Trajetória passada
h_pred = plot(ax, X_k(1), X_k(2), 'k--', 'LineWidth', 1.5); % Predição futura do NMPC

% 3. Ajuste de Camadas (Z-Order)
% Joga o obstáculo e a trajetória passada para o fundo para não cobrir os robôs
uistack(h_obs, 'bottom'); 
uistack(h_traj, 'bottom');

% Nota: O Robotarium já desenha o robô oficial, então removemos o `h_robot`
% para não ficar com dois marcadores sobrepostos.


%% Nonlinear MPC experiment loop
T_sim_total = 50;
n_steps = round(T_sim_total / Ts);
hist_X = zeros(3, n_steps + 1);
hist_U = zeros(2, n_steps);
hist_iter = zeros(1, n_steps);
hist_time = zeros(1, n_steps);

hist_X(:, 1) = X_k;

hist_U = zeros(2, n_steps);

hist_iter = zeros(1, n_steps);


disp('Iniciando simulação NMPC no Robotarium...');

tic;
for t = 1:n_steps
    X_k = r.get_poses();
    hist_X(:, t+1) = X_k;
    
    params = [X_k; x_ref; x_obs];
    t_start = tic;
    [u_opt, res_norm, iter_count] = solver.solve(u_init, params);
    tempo_solve = toc(t_start)
    hist_iter(t) = iter_count;
    
    u_atual = u_opt(1:2);
    hist_U(:, t) = u_atual;
    lim_v = r.max_linear_velocity * 0.99;
    lim_w = r.max_angular_velocity * 0.99;
    
    u_atual(1) = max(min(u_atual(1), v_max), v_min);
    u_atual(2) = max(min(u_atual(2), w_max), w_min);
    r.set_velocities(1:Nr, u_atual);
    
    X_pred = zeros(3, N+1);

    X_pred(:, 1) = X_k;

    for i = 1:N

        v_p = u_opt((i-1)*2 + 1);

        w_p = u_opt((i-1)*2 + 2);

        X_pred(1, i+1) = X_pred(1, i) + Ts * v_p * cos(X_pred(3, i));

        X_pred(2, i+1) = X_pred(2, i) + Ts * v_p * sin(X_pred(3, i));

        X_pred(3, i+1) = X_pred(3, i) + Ts * w_p;

    end


    % Atualiza os dados dos gráficos usando os handles

    set(h_traj, 'XData', hist_X(1, 1:t+1), 'YData', hist_X(2, 1:t+1));
    set(h_pred, 'XData', X_pred(1, :), 'YData', X_pred(2, :));

    dist_to_target = norm(X_k(1:2) - x_ref(1:2));
    
    raio_robo = r.robot_diameter / 2; % Pega o tamanho real do hardware
    margem_tolerancia = 0.01; % 1 cm extra para absorver pequenos erros de controle
    
    raio_chegada = raio_robo + margem_tolerancia;
    
    if dist_to_target < raio_chegada
        disp(['Alvo alcançado em ', num2str(t * Ts), ' segundos!']);
        n_steps = t; % Corta a simulação
        break;
    end

    u_init = [u_opt(3:end); u_opt(end-1:end)];
    hist_time(t) = hist_time(t) + tempo_solve;
    r.step();
end
disp(['Simulação concluída em ', num2str(toc), ' segundos.']);
disp('--- RESULTADOS DO BENCHMARK (PANOC) ---');
disp(['Tempo Médio de Solve   : ', num2str(mean(hist_time(1:n_steps)) * 1000), ' ms']);
disp(['Tempo Máximo de Solve  : ', num2str(max(hist_time(1:n_steps)) * 1000), ' ms']);
disp(['Máximo de Iterações    : ', num2str(max(hist_iter(1:n_steps)))]);

r.debug();

% Salva as matrizes de histórico em um arquivo chamado 'dados_nmpc.mat'
disp('Salvando dados do experimento para download...');
save('dados_nmpc.mat', 'hist_X', 'hist_U', 'hist_iter', 'hist_time', 'Ts', 'n_steps');
disp('Dados salvos com sucesso!');

%% Plot de figuras
close all;

% 1. Esforço Computacional
figure('Name', 'Esforço Computacional', 'Color', 'w');
plot(1:n_steps, hist_iter(1:n_steps), 'k-', 'LineWidth', 1.5);
xlabel('Passo de Simulação k'); ylabel('Iterações do PANOC');
title('Convergência com Warm Start');
grid on;

% 2. Tempo Computacional
figure('Name', 'Tempo Computacional', 'Color', 'w');
plot(1:n_steps, hist_time(1:n_steps), 'k-', 'LineWidth', 1.5);
xlabel('Passo de Simulação k'); % Alterado para fazer sentido com o eixo X
ylabel('Tempo [s]'); % Corrigido! Estava 'Iterações do PANOC'
title('Tempos Computacionais');
yline(0.033, 'r--', 'LineWidth', 1.2);
legend('Tempo de Solve', 'Limite do Robotarium (33ms)', 'Location', 'best');
grid on;

% --- NOVO PLOT: Evolução dos Estados (hist_X) ---
figure('Name', 'Estados do Robô ao Longo do Tempo (hist_X)', 'Color', 'w');
% Atenção: hist_X tem (n_steps + 1) elementos, então o vetor de tempo precisa de um passo a mais
t_sim_X = (0:n_steps) * Ts; 

% Subplot 1: Posição X
subplot(3, 1, 1);
hold on; grid on;
plot(t_sim_X, hist_X(1, 1:n_steps+1), 'b-', 'LineWidth', 1.5);
yline(x_ref(1), 'g--', 'LineWidth', 1.5); % Linha do alvo X
xlabel('Tempo [s]'); ylabel('X [m]');
title('Evolução da Posição X');
legend('Trajetória X(t)', 'Alvo X', 'Location', 'best');

% Subplot 2: Posição Y
subplot(3, 1, 2);
hold on; grid on;
plot(t_sim_X, hist_X(2, 1:n_steps+1), 'r-', 'LineWidth', 1.5);
yline(x_ref(2), 'g--', 'LineWidth', 1.5); % Linha do alvo Y
xlabel('Tempo [s]'); ylabel('Y [m]');
title('Evolução da Posição Y');
legend('Trajetória Y(t)', 'Alvo Y', 'Location', 'best');

% Subplot 3: Orientação \theta
subplot(3, 1, 3);
hold on; grid on;
plot(t_sim_X, hist_X(3, 1:n_steps+1), 'm-', 'LineWidth', 1.5);
xlabel('Tempo [s]'); ylabel('\theta [rad]');
title('Evolução da Orientação (\theta)');

% 3. Ação de Controle (hist_U) Original
figure('Name', 'Ação de Controle ao Longo do Tempo', 'Color', 'w');
% Vetor de tempo discreto para U (apenas n_steps)
t_sim = (0:n_steps-1) * Ts;

% Subplot 1: Velocidade Linear (v)
subplot(2, 1, 1);
hold on; grid on;
stairs(t_sim, hist_U(1, 1:n_steps), 'b-', 'LineWidth', 1.5);
yline(v_max, 'r--', 'LineWidth', 1.2); % Linha do limite superior
yline(v_min, 'r--', 'LineWidth', 1.2); % Linha do limite inferior
xlabel('Tempo [s]');
ylabel('v [m/s]');
title('Velocidade Linear (v)');
ylim([v_min - 0.1, v_max + 0.1]);
legend('Ação do NMPC', 'Limites Físicos', 'Location', 'best');

% Subplot 2: Velocidade Angular (\omega)
subplot(2, 1, 2);
hold on; grid on;
stairs(t_sim, hist_U(2, 1:n_steps), 'm-', 'LineWidth', 1.5);
yline(w_max, 'r--', 'LineWidth', 1.2); % Linha do limite superior
yline(w_min, 'r--', 'LineWidth', 1.2); % Linha do limite inferior
xlabel('Tempo [s]');
ylabel('\omega [rad/s]');
title('Velocidade Angular (\omega)');
ylim([w_min - 0.2, w_max + 0.2]);
legend('Ação do NMPC', 'Limites Físicos', 'Location', 'best');




%% Wrapper Functions
function cost = wrapper_cost(u, params)
    % 1. Calcula o custo original (distância, obstáculo, etc)
    cost_base = build_robot_analytic(u, params);
    
    % 2. Pesos de suavização (Tuning)
    % Aumente esses valores se o robô continuar tremendo.
    % Diminua se ele ficar "preguiçoso" demais para desviar.
    R_dv = 0.1; % Penalidade para variação de velocidade linear
    R_dw = 0.8; % Penalidade para variação de velocidade angular (Alta para matar o zigue-zague)
    
    % 3. Separa as variáveis v e w do vetor u
    % u tem o formato [v1; w1; v2; w2; ...]
    v = u(1:2:end-1);
    w = u(2:2:end);
    
    % 4. Calcula a variação quadrática (Delta u) ao longo do horizonte
    % A função diff() do MATLAB faz exatamente v(2)-v(1), v(3)-v(2)...
    cost_smooth = R_dv * sum(diff(v).^2) + R_dw * sum(diff(w).^2);
    
    % 5. Custo total
    cost = cost_base + cost_smooth;
end

function grad = wrapper_grad(u, params)
    % 1. Gradiente do modelo analítico original
    [~, grad_base] = build_robot_analytic(u, params);
    
    % 2. Pesos (Devem ser EXATAMENTE IGUAIS aos da função de custo!)
    R_dv = 0.1;
    R_dw = 0.8;
    
    % 3. Inicializa o vetor do gradiente de suavização
    grad_smooth = zeros(size(u));
    N_horizonte = length(u) / 2;
    
    % 4. Calcula as derivadas parciais (Regra da Cadeia)
    for i = 1:N_horizonte-1
        % Derivada em relação a v
        dv = u(2*i+1) - u(2*i-1); % v_{i+1} - v_i
        grad_smooth(2*i-1) = grad_smooth(2*i-1) - 2 * R_dv * dv;
        grad_smooth(2*i+1) = grad_smooth(2*i+1) + 2 * R_dv * dv;
        
        % Derivada em relação a w
        dw = u(2*i+2) - u(2*i);   % w_{i+1} - w_i
        grad_smooth(2*i)   = grad_smooth(2*i)   - 2 * R_dw * dw;
        grad_smooth(2*i+2) = grad_smooth(2*i+2) + 2 * R_dw * dw;
    end
    
    % 5. Gradiente total
    grad = grad_base + grad_smooth;
end