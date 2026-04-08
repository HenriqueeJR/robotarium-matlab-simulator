% =========================================================================
% Algoritmo: Backward AD - Desvio de Obstáculo Circular (CBF)
% =========================================================================
function [cost, grad] = build_robot_cbf_circular(u, params)
    %#codegen
    N = 10;
    Ts = 0.033;
    Q_pos = 30; R_ctrl = 0.01; 
    
    x_k = params(1:3);      % Estado inicial x_0
    x_ref = params(4:5);    % Alvo [x; y]
    x_obs = params(6:7);    % Centro do obstáculo circular
    R_obs = params(8);      % Raio do obstáculo
    eta_safe = params(9);   % Peso da penalidade (Barreira)
    
    % --- Dimensões e Parâmetros da Barreira ---
    r_rob = 0.5;                  % Raio do robô (margem de segurança)
    R_safe = R_obs + r_rob;       % Distância mínima segura centro a centro
    
    % Taxa de decaimento da CBF. 
    % Nota: Geralmente 0 < gamma <= 1 em tempo discreto. Ajuste conforme necessário.
    gamma_cbf = 0.3; 
    
    X_hist = zeros(3, N + 1);
    X_hist(:, 1) = x_k;
    l_u = 0; 
    
    % =====================================================================
    % FORWARD PASS (Avaliação do Custo)
    % =====================================================================
    for n = 1:N
        v_n = u((n-1)*2 + 1);
        w_n = u((n-1)*2 + 2);
        
        % 1. Barreira no estado atual (h_k)
        dx_k = x_k(1) - x_obs(1);
        dy_k = x_k(2) - x_obs(2);
        h_k = (dx_k^2 + dy_k^2) - R_safe^2;
        
        % Simula 1 passo da cinemática
        x_next = zeros(3,1);
        x_next(1) = x_k(1) + Ts * v_n * cos(x_k(3));
        x_next(2) = x_k(2) + Ts * v_n * sin(x_k(3));
        x_next(3) = x_k(3) + Ts * w_n;
        
        % 2. Barreira no estado futuro (h_{k+1})
        dx_next = x_next(1) - x_obs(1);
        dy_next = x_next(2) - x_obs(2);
        h_next = (dx_next^2 + dy_next^2) - R_safe^2;
        
        % 3. Restrição de Barreira (g_k <= 0)
        % g_k = (1 - gamma)*h_k - h_{k+1}
        g_cbf = (1 - gamma_cbf) * h_k - h_next;
        
        % 4. Penalidade
        P_cbf = max(0, g_cbf)^2;
        geo_penalty = eta_safe * P_cbf;
        
        % Custo de estágio normal
        l_estagio = Q_pos * ((x_k(1) - x_ref(1))^2 + (x_k(2) - x_ref(2))^2) + R_ctrl * (v_n^2 + w_n^2);
        l_u = l_u + l_estagio + geo_penalty;
        
        % Atualiza estado para o próximo passo
        x_k = x_next;
        X_hist(:, n+1) = x_k;
    end
    
    cost = l_u;
    
    % =====================================================================
    % TERMINAL E INICIALIZAÇÃO DO BACKWARD
    % =====================================================================
    x_N = X_hist(:, N+1);
    
    l_N = Q_pos * ((x_N(1) - x_ref(1))^2 + (x_N(2) - x_ref(2))^2);
    cost = cost + l_N;
    
    if nargout == 1, return; end
    
    grad_x_l_N = [2 * Q_pos * (x_N(1) - x_ref(1)); 2 * Q_pos * (x_N(2) - x_ref(2)); 0];
    p_n = grad_x_l_N;
    
    % =====================================================================
    % BACKWARD PASS (Método Adjunto)
    % =====================================================================
    grad = zeros(length(u), 1);
    for n = N:-1:1
        x_n = X_hist(:, n);       % Estado atual (p_k)
        x_next = X_hist(:, n+1);  % Estado futuro (p_{k+1})
        v_n = u((n-1)*2 + 1); w_n = u((n-1)*2 + 2);
        theta_n = x_n(3);
        
        grad_x_l_n = [2 * Q_pos * (x_n(1) - x_ref(1)); 2 * Q_pos * (x_n(2) - x_ref(2)); 0];
        grad_u_l_n = [2 * R_ctrl * v_n; 2 * R_ctrl * w_n];
        
        % 1. Recalcular a Violação da Barreira
        dx_k = x_n(1) - x_obs(1);
        dy_k = x_n(2) - x_obs(2);
        h_k = (dx_k^2 + dy_k^2) - R_safe^2;
        
        dx_next = x_next(1) - x_obs(1);
        dy_next = x_next(2) - x_obs(2);
        h_next = (dx_next^2 + dy_next^2) - R_safe^2;
        
        g_cbf = (1 - gamma_cbf) * h_k - h_next;
        
        grad_x_k_cbf = [0; 0; 0];
        grad_x_next_cbf = [0; 0; 0];
        
        % 2. Gradientes da Barreira (Apenas se violada)
        if g_cbf > 0
            % Derivadas de h em relação aos estados x e y
            grad_h_k = [2 * dx_k; 2 * dy_k; 0];
            grad_h_next = [2 * dx_next; 2 * dy_next; 0];
            
            % Derivadas de g = (1-gamma)*h_k - h_{k+1}
            grad_g_k = (1 - gamma_cbf) * grad_h_k;
            grad_g_next = -1 * grad_h_next;
            
            % Aplica a Regra da Cadeia: dP/dx = 2 * eta * g * dg/dx
            multiplicador = 2 * eta_safe * g_cbf;
            
            grad_x_k_cbf = multiplicador * grad_g_k;
            grad_x_next_cbf = multiplicador * grad_g_next;
        end
        
        % 3. Propagação pelo Adjunto
        p_prev = p_n + grad_x_next_cbf; 
        
        % Gradiente total em relação ao estado atual
        grad_x_total = grad_x_l_n + grad_x_k_cbf;
        
        % Jacobianas Cinemáticas
        J_x_T = [1, 0, 0; 
                 0, 1, 0; 
                 -Ts * v_n * sin(theta_n), Ts * v_n * cos(theta_n), 1];
                 
        J_u_T = [Ts * cos(theta_n), Ts * sin(theta_n), 0; 
                 0, 0, Ts];
        
        % Atualiza as variáveis co-estado para o próximo passo da iteração reversa
        p_n = J_x_T * p_prev + grad_x_total;
        
        % Salva o gradiente do controle no vetor final
        grad((n-1)*2 + 1 : n*2) = J_u_T * p_prev + grad_u_l_n;
    end
end