% =========================================================================
% Algoritmo 1: Backward AD (Custo e Gradiente integrados)
% =========================================================================
function [cost, grad] = build_robot_analytic(u, params)
    N = length(u) / 2;
    Ts = 0.033;
    Q_pos = 1; R_ctrl = 0.01; mu_obs = 10000.0;
    
    x_k = params(1:3);      % Estado inicial x_0
    x_ref = params(4:5);
    x_obs = params(6:8);
    
    % Memória para o Backward Pass
    X_hist = zeros(3, N + 1);
    X_hist(:, 1) = x_k;
    q_hist = zeros(1, N); % Guarda os valores de q_n
    
    % Linha 1: Inicializa o custo
    l_u = 0; 
    
    % =====================================================================
    % FORWARD PASS (Linhas 2 a 6)
    % =====================================================================
    for n = 1:N
        v_n = u((n-1)*2 + 1);
        w_n = u((n-1)*2 + 2);
        
        % Avaliação da restrição C_n (Invasão do obstáculo)
        dist_sq = (x_k(1) - x_obs(1))^2 + (x_k(2) - x_obs(2))^2;
        C_n = x_obs(3)^2 - dist_sq; 
        
        % Linha 3: Mapeamento Proximal (Projeta para <= 0)
        s_n = min(0, C_n);
        
        % Linha 4: Cálculo de q_n (Gradiente do Envelope de Moreau)
        q_n = mu_obs * (C_n - s_n);
        q_hist(n) = q_n; % Salva para o backward pass
        
        % Linha 5: Acumula o custo (h(s_n) é zero pois s_n está no conjunto)
        l_estagio = Q_pos * ((x_k(1) - x_ref(1))^2 + (x_k(2) - x_ref(2))^2) + R_ctrl * (v_n^2 + w_n^2);
        l_u = l_u + l_estagio + 0 + (1 / (2 * mu_obs)) * q_n^2;
        
        % Linha 6: Dinâmica f_n
        x_k(1) = x_k(1) + Ts * v_n * cos(x_k(3));
        x_k(2) = x_k(2) + Ts * v_n * sin(x_k(3));
        x_k(3) = x_k(3) + Ts * w_n;
        
        X_hist(:, n+1) = x_k;
    end
    
    cost = l_u;
    
    
    % =====================================================================
    % TERMINAL E INICIALIZAÇÃO DO BACKWARD (Linhas 7 a 10)
    % =====================================================================
    x_N = X_hist(:, N+1);
    
    % Linhas 7 a 9 (Custo Terminal)
    dist_sq_N = (x_N(1) - x_obs(1))^2 + (x_N(2) - x_obs(2))^2;
    C_N = x_obs(3)^2 - dist_sq_N;
    s_N = min(0, C_N);
    q_N = mu_obs * (C_N - s_N);
    
    l_N = Q_pos * ((x_N(1) - x_ref(1))^2 + (x_N(2) - x_ref(2))^2);
    cost = cost + l_N + (1 / (2 * mu_obs)) * q_N^2;

    % Se a função foi chamada apenas para avaliar o custo (ex: no FBE), encerra aqui
    if nargout == 1
        return;
    end
    
    % Linha 10: Inicializa p_N
    grad_x_l_N = [2 * Q_pos * (x_N(1) - x_ref(1)); 2 * Q_pos * (x_N(2) - x_ref(2)); 0];
    grad_x_C_N = [-2 * (x_N(1) - x_obs(1)); -2 * (x_N(2) - x_obs(2)); 0];
    
    p_n = grad_x_l_N + grad_x_C_N * q_N;
    
    % =====================================================================
    % BACKWARD PASS (Linhas 11 a 13)
    % =====================================================================
    grad = zeros(length(u), 1);
    
    for n = N:-1:1
        x_n = X_hist(:, n);
        v_n = u((n-1)*2 + 1);
        w_n = u((n-1)*2 + 2);
        theta_n = x_n(3);
        q_n = q_hist(n);
        
        % Gradientes base do estágio (l_n e C_n)
        grad_x_l_n = [2 * Q_pos * (x_n(1) - x_ref(1)); 2 * Q_pos * (x_n(2) - x_ref(2)); 0];
        grad_u_l_n = [2 * R_ctrl * v_n; 2 * R_ctrl * w_n];
        
        grad_x_C_n = [-2 * (x_n(1) - x_obs(1)); -2 * (x_n(2) - x_obs(2)); 0];
        grad_u_C_n = [0; 0]; % O obstáculo só depende do estado, não do controle u
        
        % Jacobianas transpostas da dinâmica (df/dx e df/du)
        J_x_T = [1, 0, 0;
                 0, 1, 0;
                -Ts * v_n * sin(theta_n), Ts * v_n * cos(theta_n), 1];
               
        J_u_T = [Ts * cos(theta_n), Ts * sin(theta_n), 0;
                 0, 0, Ts];
        
        % Linha 12: Atualiza o coestado p_n
        % (Nota: p_n no lado direito da equação é o p_{n+1} do loop anterior)
        p_prev = p_n; 
        p_n = J_x_T * p_prev + grad_x_l_n + grad_x_C_n * q_n;
        
        % Linha 13: Calcula o gradiente em relação ao controle u_n
        grad((n-1)*2 + 1 : n*2) = J_u_T * p_prev + grad_u_l_n + grad_u_C_n * q_n;
    end
end