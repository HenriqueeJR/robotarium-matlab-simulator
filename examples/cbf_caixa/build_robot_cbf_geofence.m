% =========================================================================
% Algoritmo: Backward AD - Geofence Retangular (Caixa) via CBF
% Regra da Soma: P = max(0, |x| - L_safe)^2 + max(0, |y| - W_safe)^2
% =========================================================================
function [cost, grad] = build_robot_cbf_geofence(u, params)
    %#codegen
    N = 10;
    Ts = 0.033; 
    Q_pos = 10; R_ctrl = 0.1; 
    
    x_k      = params(1:3);      
    x_ref    = params(4:5);      
    x_obs    = params(6:7);      % Centro da Geofence
    L_obs    = params(8);        % Meio-comprimento (eixo X)
    W_obs    = params(9);        % Meia-largura (eixo Y)
    eta_safe = params(10);       
    
    r_rob = 0.15;     
    gamma_cbf = 0.3; 
    eta_cbf = 0.00;  
    
    % Para ficar DENTRO da caixa, a borda efetiva encolhe o raio do robô
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
        
        % 1. Violação (Soma quadrática de sair dos limites X ou Y)
        dx_k = max(0, abs(x_pos_k) - L_safe);
        dy_k = max(0, abs(y_pos_k) - W_safe);
        P_k = dx_k^2 + dy_k^2;
        h_k = eta_cbf - P_k;
        
        % Dinâmica
        x_next = zeros(3,1);
        x_next(1) = x_k(1) + Ts * v_n * cos(x_k(3));
        x_next(2) = x_k(2) + Ts * v_n * sin(x_k(3));
        x_next(3) = x_k(3) + Ts * w_n;
        
        x_pos_next = x_next(1) - x_obs(1);
        y_pos_next = x_next(2) - x_obs(2);
        
        % 2. Violação no estado futuro
        dx_next = max(0, abs(x_pos_next) - L_safe);
        dy_next = max(0, abs(y_pos_next) - W_safe);
        P_next = dx_next^2 + dy_next^2;
        h_next = eta_cbf - P_next;
        
        % 3. Restrição e Penalidade
        g_cbf = (1 - gamma_cbf) * h_k - h_next;
        P_cbf_penalty = max(0, g_cbf)^2;
        geo_penalty = eta_safe * P_cbf_penalty;
        
        l_estagio = Q_pos * ((x_k(1) - x_ref(1))^2 + (x_k(2) - x_ref(2))^2) + R_ctrl * (v_n^2 + w_n^2);
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
        grad_u_l_n = [2 * R_ctrl * v_n; 2 * R_ctrl * w_n];
        
        x_pos_k = x_n(1) - x_obs(1); y_pos_k = x_n(2) - x_obs(2);
        x_pos_next = x_next(1) - x_obs(1); y_pos_next = x_next(2) - x_obs(2);
        
        dx_k = max(0, abs(x_pos_k) - L_safe); dy_k = max(0, abs(y_pos_k) - W_safe);
        P_k = dx_k^2 + dy_k^2; h_k = eta_cbf - P_k;
        
        dx_next = max(0, abs(x_pos_next) - L_safe); dy_next = max(0, abs(y_pos_next) - W_safe);
        P_next = dx_next^2 + dy_next^2; h_next = eta_cbf - P_next;
        
        g_cbf = (1 - gamma_cbf) * h_k - h_next;
        
        grad_x_k_cbf = [0; 0; 0];
        grad_x_next_cbf = [0; 0; 0];
        
        if g_cbf > 0
            grad_P_k = [0; 0; 0];
            grad_P_next = [0; 0; 0];
            
            % Gradiente de P_k = dx^2 + dy^2 (Regra da Soma)
            if dx_k > 0
                sx = sign(x_pos_k); if sx == 0, sx = 1; end
                grad_P_k(1) = 2 * dx_k * sx; 
            end
            if dy_k > 0
                sy = sign(y_pos_k); if sy == 0, sy = 1; end
                grad_P_k(2) = 2 * dy_k * sy; 
            end
            
            % Gradiente de P_next
            if dx_next > 0
                sx = sign(x_pos_next); if sx == 0, sx = 1; end
                grad_P_next(1) = 2 * dx_next * sx; 
            end
            if dy_next > 0
                sy = sign(y_pos_next); if sy == 0, sy = 1; end
                grad_P_next(2) = 2 * dy_next * sy; 
            end
            
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