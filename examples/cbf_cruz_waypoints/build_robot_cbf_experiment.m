% =========================================================================
% Algoritmo: Backward AD - Geofence (Cruz) + Obstáculo (Círculo) via CBF
% =========================================================================
function [cost, grad] = build_robot_cbf_experiment(u, params)
    %#codegen
    N = params(15);             % Horizonte longo para enxergar o corredor
    Ts = params(16);           % Tempo de predição
    Q_pos = 1.8;         
    R_v = 0.5;          % Peso para suavizar a velocidade linear
    R_w = 0.001;          % Peso ALTO para evitar zigue-zague
    
    x_k      = params(1:3);      
    x_ref    = params(4:5);      
    x_obs    = params(6:7);      % Centro (Cruz e Círculo)
    L_obs    = params(8);        
    W_obs    = params(9);        
    R_circ   = params(10);       
    eta_safe = params(11);       % Peso da Barreira CBF
    eta_obs = params(12);
    gamma_safe = params(13);
    gamma_obs = params(14);
    
    r_rob = params(17);                 
    
    % Limites Seguros
    L_safe = L_obs - r_rob;      % Geofence (Encolhe)
    W_safe = W_obs - r_rob;      % Geofence (Encolhe)
    R_safe = R_circ + r_rob;     % Obstáculo (Incha)
    
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
        
        % --- Estado Atual (k) ---
        % Cruz
        dx1_k = max(0, abs(x_pos_k) - L_safe); dy1_k = max(0, abs(y_pos_k) - W_safe);
        P1_k = dx1_k^2 + dy1_k^2;
        dx2_k = max(0, abs(x_pos_k) - W_safe); dy2_k = max(0, abs(y_pos_k) - L_safe);
        P2_k = dx2_k^2 + dy2_k^2;
        P_cross_k = P1_k * P2_k;
        
        % Círculo
        v_circ_k = max(0, R_safe^2 - (x_pos_k^2 + y_pos_k^2));
        P_circ_k = v_circ_k^2;
        
        h_cross_k = -P_cross_k; 
        h_circ_k = -P_circ_k;
        
        % Dinâmica
        x_next = zeros(3,1);
        x_next(1) = x_k(1) + Ts * v_n * cos(x_k(3));
        x_next(2) = x_k(2) + Ts * v_n * sin(x_k(3));
        x_next(3) = x_k(3) + Ts * w_n;
        
        x_pos_next = x_next(1) - x_obs(1);
        y_pos_next = x_next(2) - x_obs(2);
        
        % --- Estado Futuro (next) ---
        % Cruz
        dx1_next = max(0, abs(x_pos_next) - L_safe); dy1_next = max(0, abs(y_pos_next) - W_safe);
        P1_next = dx1_next^2 + dy1_next^2;
        dx2_next = max(0, abs(x_pos_next) - W_safe); dy2_next = max(0, abs(y_pos_next) - L_safe);
        P2_next = dx2_next^2 + dy2_next^2;
        P_cross_next = P1_next * P2_next;
        
        % Círculo
        v_circ_next = max(0, R_safe^2 - (x_pos_next^2 + y_pos_next^2));
        P_circ_next = v_circ_next^2;
        
        h_cross_next = -P_cross_next;
        h_circ_next = -P_circ_next;
        

        % --- Restrições CBF Separadas ---
        g_cross = (1 - gamma_safe) * h_cross_k - h_cross_next;
        g_circ = (1 - gamma_obs) * h_circ_k - h_circ_next;
        
        penalty_cross = eta_safe * max(0, g_cross)^2;
        penalty_circ = eta_obs * max(0, g_circ)^2;
        
        l_estagio = Q_pos * ((x_k(1) - x_ref(1))^2 + (x_k(2) - x_ref(2))^2) + (R_v * v_n^2) + (R_w * w_n^2);
        l_u = l_u + l_estagio + penalty_cross + penalty_circ;
        
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
    
    p_n = [2 * Q_pos * (x_N(1) - x_ref(1)); 2 * Q_pos * (x_N(2) - x_ref(2)); 0];
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
        
        % Recalcula k
        dx1_k = max(0, abs(x_pos_k) - L_safe); dy1_k = max(0, abs(y_pos_k) - W_safe); P1_k = dx1_k^2 + dy1_k^2;
        dx2_k = max(0, abs(x_pos_k) - W_safe); dy2_k = max(0, abs(y_pos_k) - L_safe); P2_k = dx2_k^2 + dy2_k^2;
        v_circ_k = max(0, R_safe^2 - (x_pos_k^2 + y_pos_k^2));
        
        h_cross_k = -(P1_k * P2_k);
        h_circ_k = -(v_circ_k^2);
        
        % Recalcula next
        dx1_next = max(0, abs(x_pos_next) - L_safe); dy1_next = max(0, abs(y_pos_next) - W_safe); P1_next = dx1_next^2 + dy1_next^2;
        dx2_next = max(0, abs(x_pos_next) - W_safe); dy2_next = max(0, abs(y_pos_next) - L_safe); P2_next = dx2_next^2 + dy2_next^2;
        v_circ_next = max(0, R_safe^2 - (x_pos_next^2 + y_pos_next^2));
        
        h_cross_next = -(P1_next * P2_next);
        h_circ_next = -(v_circ_next^2);
        
        g_cross = (1 - gamma_safe) * h_cross_k - h_cross_next;
        g_circ = (1 - gamma_obs) * h_circ_k - h_circ_next;
        
        grad_x_k_cbf = [0; 0; 0];
        grad_x_next_cbf = [0; 0; 0];
        
        % --- Gradientes da Geofence (Cruz) ---
        if g_cross > 0
            gP_cross_k = [0; 0; 0];
            gP_cross_next = [0; 0; 0];
            
            if (P1_k * P2_k > 0) || P1_k > 0 || P2_k > 0
                gP1 = [0;0;0]; gP2 = [0;0;0];
                if dx1_k > 0, gP1(1) = 2*dx1_k*sign(x_pos_k); end
                if dy1_k > 0, gP1(2) = 2*dy1_k*sign(y_pos_k); end
                if dx2_k > 0, gP2(1) = 2*dx2_k*sign(x_pos_k); end
                if dy2_k > 0, gP2(2) = 2*dy2_k*sign(y_pos_k); end
                gP_cross_k = (P2_k * gP1) + (P1_k * gP2);
            end
            
            if (P1_next * P2_next > 0) || P1_next > 0 || P2_next > 0
                gP1_n = [0;0;0]; gP2_n = [0;0;0];
                if dx1_next > 0, gP1_n(1) = 2*dx1_next*sign(x_pos_next); end
                if dy1_next > 0, gP1_n(2) = 2*dy1_next*sign(y_pos_next); end
                if dx2_next > 0, gP2_n(1) = 2*dx2_next*sign(x_pos_next); end
                if dy2_next > 0, gP2_n(2) = 2*dy2_next*sign(y_pos_next); end
                gP_cross_next = (P2_next * gP1_n) + (P1_next * gP2_n);
            end
            
            gh_k = -gP_cross_k;
            gh_next = -gP_cross_next;
            
            gg_k = (1 - gamma_safe) * gh_k;
            gg_next = -1 * gh_next;
            
            grad_x_k_cbf = grad_x_k_cbf + (2 * eta_safe * g_cross * gg_k);
            grad_x_next_cbf = grad_x_next_cbf + (2 * eta_safe * g_cross * gg_next);
        end
        
        % --- Gradientes do Obstáculo (Círculo) ---
        if g_circ > 0
            gP_circ_k = [0; 0; 0];
            gP_circ_next = [0; 0; 0];
            
            if v_circ_k > 0
                gP_circ_k(1) = -4 * v_circ_k * x_pos_k;
                gP_circ_k(2) = -4 * v_circ_k * y_pos_k;
            end
            if v_circ_next > 0
                gP_circ_next(1) = -4 * v_circ_next * x_pos_next;
                gP_circ_next(2) = -4 * v_circ_next * y_pos_next;
            end
            
            gh_k = -gP_circ_k;
            gh_next = -gP_circ_next;
            
            gg_k = (1 - gamma_obs) * gh_k;
            gg_next = -1 * gh_next;
            
            grad_x_k_cbf = grad_x_k_cbf + (2 * eta_obs * g_circ * gg_k);
            grad_x_next_cbf = grad_x_next_cbf + (2 * eta_obs * g_circ * gg_next);
        end
        
        p_prev = p_n + grad_x_next_cbf; 
        grad_x_total = grad_x_l_n + grad_x_k_cbf;
        
        J_x_T = [1, 0, 0; 0, 1, 0; -Ts * v_n * sin(theta_n), Ts * v_n * cos(theta_n), 1];
        J_u_T = [Ts * cos(theta_n), Ts * sin(theta_n), 0; 0, 0, Ts];
        
        p_n = J_x_T * p_prev + grad_x_total;
        grad((n-1)*2 + 1 : n*2) = J_u_T * p_prev + grad_u_l_n;
    end
end