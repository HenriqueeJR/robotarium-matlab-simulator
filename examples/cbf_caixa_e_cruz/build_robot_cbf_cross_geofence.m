% =========================================================================
% Algoritmo: Backward AD - Geofence Cruz (2 Caixas) via CBF
% Regra da União: P_cruz = P_box1 * P_box2
% =========================================================================
function [cost, grad] = build_robot_cbf_cross_geofence(u, params)
    %#codegen
    N = 10;
    Ts = 0.1;           % Tempo de amostragem de 0.1s para prever as curvas
    Q_pos = 0.8;         
    R_v = 0.1;          % Penalidade suave para andar
    R_w = 0.01;          % Penalidade ALTA para girar (evita o zigue-zague)
    
    x_k      = params(1:3);      
    x_ref    = params(4:5);      
    x_obs    = params(6:7);      % Centro da Cruz
    L_obs    = params(8);        % Comprimento do braço maior
    W_obs    = params(9);        % Comprimento do braço menor (largura)
    eta_safe = params(10);       
    
    r_rob = 0.15;     
    gamma_cbf = 0.8; 
    eta_cbf = 0.00;  
    
    % Encolhe a cruz geométrica para o centro do robô não encostar nas paredes
    L_safe = L_obs - r_rob;
    W_safe = W_obs - r_rob;
    
    X_hist = zeros(3, N + 1);
    X_hist(:, 1) = x_k;
    l_u = 0; 
    
    % =====================================================================
    % FORWARD PASS
    % =====================================================================
    for n = 1:N
        v_n = u((n-1)*2 + 1);
        w_n = u((n-1)*2 + 2);
        
        x_pos_k = x_k(1) - x_obs(1); 
        y_pos_k = x_k(2) - x_obs(2);
        
        % --- CAIXA 1 (Horizontal) ---
        dx1_k = max(0, abs(x_pos_k) - L_safe);
        dy1_k = max(0, abs(y_pos_k) - W_safe);
        P1_k = dx1_k^2 + dy1_k^2;
        
        % --- CAIXA 2 (Vertical) ---
        dx2_k = max(0, abs(x_pos_k) - W_safe);
        dy2_k = max(0, abs(y_pos_k) - L_safe);
        P2_k = dx2_k^2 + dy2_k^2;
        
        % Regra da União: Seguro se (P1=0) OU (P2=0)
        P_k = P1_k * P2_k;
        h_k = eta_cbf - P_k;
        
        % Dinâmica
        x_next = zeros(3,1);
        x_next(1) = x_k(1) + Ts * v_n * cos(x_k(3));
        x_next(2) = x_k(2) + Ts * v_n * sin(x_k(3));
        x_next(3) = x_k(3) + Ts * w_n;
        
        x_pos_next = x_next(1) - x_obs(1);
        y_pos_next = x_next(2) - x_obs(2);
        
        % Violação Futura
        dx1_next = max(0, abs(x_pos_next) - L_safe);
        dy1_next = max(0, abs(y_pos_next) - W_safe);
        P1_next = dx1_next^2 + dy1_next^2;
        
        dx2_next = max(0, abs(x_pos_next) - W_safe);
        dy2_next = max(0, abs(y_pos_next) - L_safe);
        P2_next = dx2_next^2 + dy2_next^2;
        
        P_next = P1_next * P2_next;
        h_next = eta_cbf - P_next;
        
        % Restrição e Penalidade
        g_cbf = (1 - gamma_cbf) * h_k - h_next;
        P_cbf_penalty = max(0, g_cbf)^2;
        geo_penalty = eta_safe * P_cbf_penalty;
        
        % Custo com pesos separados para R_v e R_w
        l_estagio = Q_pos * ((x_k(1) - x_ref(1))^2 + (x_k(2) - x_ref(2))^2) + (R_v * v_n^2) + (R_w * w_n^2);
        l_u = l_u + l_estagio + geo_penalty;
        
        x_k = x_next;
        X_hist(:, n+1) = x_k;
    end
    
    cost = l_u;
    
    % =====================================================================
    % TERMINAL E BACKWARD PASS
    % =====================================================================
    x_N = X_hist(:, N+1);
    l_N = Q_pos * ((x_N(1) - x_ref(1))^2 + (x_N(2) - x_ref(2))^2);
    cost = cost + l_N;
    
    if nargout == 1, return; end
    
    grad_x_l_N = [2 * Q_pos * (x_N(1) - x_ref(1)); 2 * Q_pos * (x_N(2) - x_ref(2)); 0];
    p_n = grad_x_l_N;
    
    grad = zeros(length(u), 1);
    for n = N:-1:1
        x_n = X_hist(:, n);       
        x_next = X_hist(:, n+1);  
        v_n = u((n-1)*2 + 1); w_n = u((n-1)*2 + 2);
        theta_n = x_n(3);
        
        grad_x_l_n = [2 * Q_pos * (x_n(1) - x_ref(1)); 2 * Q_pos * (x_n(2) - x_ref(2)); 0];
        grad_u_l_n = [2 * R_v * v_n; 2 * R_w * w_n];
        
        x_pos_k = x_n(1) - x_obs(1); y_pos_k = x_n(2) - x_obs(2);
        x_pos_next = x_next(1) - x_obs(1); y_pos_next = x_next(2) - x_obs(2);
        
        % Recalcula P_k
        dx1_k = max(0, abs(x_pos_k) - L_safe); dy1_k = max(0, abs(y_pos_k) - W_safe);
        P1_k = dx1_k^2 + dy1_k^2;
        dx2_k = max(0, abs(x_pos_k) - W_safe); dy2_k = max(0, abs(y_pos_k) - L_safe);
        P2_k = dx2_k^2 + dy2_k^2;
        P_k = P1_k * P2_k; h_k = eta_cbf - P_k;
        
        % Recalcula P_next
        dx1_next = max(0, abs(x_pos_next) - L_safe); dy1_next = max(0, abs(y_pos_next) - W_safe);
        P1_next = dx1_next^2 + dy1_next^2;
        dx2_next = max(0, abs(x_pos_next) - W_safe); dy2_next = max(0, abs(y_pos_next) - L_safe);
        P2_next = dx2_next^2 + dy2_next^2;
        P_next = P1_next * P2_next; h_next = eta_cbf - P_next;
        
        g_cbf = (1 - gamma_cbf) * h_k - h_next;
        
        grad_x_k_cbf = [0; 0; 0];
        grad_x_next_cbf = [0; 0; 0];
        
        if g_cbf > 0
            % --- Gradientes das Caixas ---
            grad_P1_k = [0; 0; 0]; grad_P2_k = [0; 0; 0];
            grad_P1_next = [0; 0; 0]; grad_P2_next = [0; 0; 0];
            
            % Gradiente Caixa 1
            if dx1_k > 0, grad_P1_k(1) = 2 * dx1_k * sign(x_pos_k); end
            if dy1_k > 0, grad_P1_k(2) = 2 * dy1_k * sign(y_pos_k); end
            if dx1_next > 0, grad_P1_next(1) = 2 * dx1_next * sign(x_pos_next); end
            if dy1_next > 0, grad_P1_next(2) = 2 * dy1_next * sign(y_pos_next); end
            
            % Gradiente Caixa 2
            if dx2_k > 0, grad_P2_k(1) = 2 * dx2_k * sign(x_pos_k); end
            if dy2_k > 0, grad_P2_k(2) = 2 * dy2_k * sign(y_pos_k); end
            if dx2_next > 0, grad_P2_next(1) = 2 * dx2_next * sign(x_pos_next); end
            if dy2_next > 0, grad_P2_next(2) = 2 * dy2_next * sign(y_pos_next); end
            
            % Aplicação da Regra do Produto: grad(P1*P2) = P2*grad(P1) + P1*grad(P2)
            grad_P_k = (P2_k * grad_P1_k) + (P1_k * grad_P2_k);
            grad_P_next = (P2_next * grad_P1_next) + (P1_next * grad_P2_next);
            
            grad_h_k = -grad_P_k;
            grad_h_next = -grad_P_next;
            
            grad_g_k = (1 - gamma_cbf) * grad_h_k;
            grad_g_next = -1 * grad_h_next;
            
            multiplicador = 2 * eta_safe * g_cbf;
            
            grad_x_k_cbf = multiplicador * grad_g_k;
            grad_x_next_cbf = multiplicador * grad_g_next;
        end
        
        p_prev = p_n + grad_x_next_cbf; 
        grad_x_total = grad_x_l_n + grad_x_k_cbf;
        
        J_x_T = [1, 0, 0; 0, 1, 0; -Ts * v_n * sin(theta_n), Ts * v_n * cos(theta_n), 1];
        J_u_T = [Ts * cos(theta_n), Ts * sin(theta_n), 0; 0, 0, Ts];
        
        p_n = J_x_T * p_prev + grad_x_total;
        grad((n-1)*2 + 1 : n*2) = J_u_T * p_prev + grad_u_l_n;
    end
end