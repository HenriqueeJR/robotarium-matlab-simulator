% =========================================================================
% Algoritmo 1: Backward AD CORRIGIDO (Cruz + Barras + Círculos)
% =========================================================================
function [cost, grad] = build_robot_analytic(u, params)
    N = length(u) / 2;
    Ts = 0.033;
    
    Q_pos = 150;  
    R_ctrl = [0.01 0; 0 0.1];
    
    x_k = params(1:3);      
    x_ref = params(4:5);
    x_obs = params(6:7);    
    eta_geo = params(8);    
    
    L_arm = 1.2;  W_arm = 0.2;  R_out = 0.5;  R_in  = 0.25; 
    
    X_hist = zeros(3, N + 1);
    X_hist(:, 1) = x_k;
    l_u = 0;
    
    % =====================================================================
    % FORWARD PASS (Avaliação do Custo)
    % =====================================================================
    for n = 1:N
        v_n = u((n-1)*2 + 1);
        w_n = u((n-1)*2 + 2);
        
        x_pos = x_k(1) - x_obs(1); 
        y_pos = x_k(2) - x_obs(2);
        
        v_11 = max(0, -x_pos);         v_12 = max(0, x_pos - L_arm);
        v_13 = max(0, -y_pos - W_arm); v_14 = max(0, y_pos - W_arm);
        P1 = v_11^2 + v_12^2 + v_13^2 + v_14^2;
        
        v_21 = max(0, -x_pos - W_arm); v_22 = max(0, x_pos - W_arm);
        v_23 = max(0, -y_pos);         v_24 = max(0, y_pos - L_arm);
        P2 = v_21^2 + v_22^2 + v_23^2 + v_24^2;
        
        v_31 = max(0, -x_pos - L_arm); v_32 = max(0, x_pos);
        v_33 = max(0, -y_pos - W_arm); v_34 = max(0, y_pos - W_arm);
        P3 = v_31^2 + v_32^2 + v_33^2 + v_34^2;
        
        v_41 = max(0, -x_pos - W_arm); v_42 = max(0, x_pos - W_arm);
        v_43 = max(0, -y_pos - L_arm); v_44 = max(0, y_pos);
        P4 = v_41^2 + v_42^2 + v_43^2 + v_44^2;
        
        v_5 = max(0, x_pos^2 + y_pos^2 - R_out^2);
        P5 = v_5^2;
        
        v_6 = max(0, R_in^2 - (x_pos^2 + y_pos^2));
        P6 = v_6^2; % O Buraco Central
        
        v_71 = max(0, (-L_arm - 2*W_arm) - x_pos); v_72 = max(0, x_pos - (-L_arm));
        v_73 = max(0, -L_arm - y_pos);             v_74 = max(0, y_pos - L_arm);
        P7 = v_71^2 + v_72^2 + v_73^2 + v_74^2;
        
        v_81 = max(0, L_arm - x_pos);              v_82 = max(0, x_pos - (L_arm + 2*W_arm));
        v_83 = max(0, -L_arm - y_pos);             v_84 = max(0, y_pos - L_arm);
        P8 = v_81^2 + v_82^2 + v_83^2 + v_84^2;
        
        % UNIÃO usando Active Set (mínimo) + SOMATÓRIO do Obstáculo
        geo_penalty = eta_geo * (min([P1, P2, P3, P4, P5, P7, P8]) + P6);
        
        % CORREÇÃO MATRIZ -> ESCALAR
        l_estagio = Q_pos * ((x_k(1) - x_ref(1))^2 + (x_k(2) - x_ref(2))^2) + R_ctrl(1,1)*v_n^2 + R_ctrl(2,2)*w_n^2;
        
        l_u = l_u + l_estagio + geo_penalty;
        
        x_k(1) = x_k(1) + Ts * v_n * cos(x_k(3));
        x_k(2) = x_k(2) + Ts * v_n * sin(x_k(3));
        x_k(3) = x_k(3) + Ts * w_n;
        
        X_hist(:, n+1) = x_k;
    end
    
    cost = l_u;
    
    if nargout == 1, return; end
    
    x_N = X_hist(:, N+1);
    grad_x_l_N = [2 * Q_pos * (x_N(1) - x_ref(1)); 2 * Q_pos * (x_N(2) - x_ref(2)); 0];
    p_n = grad_x_l_N;
    
    % =====================================================================
    % BACKWARD PASS (Método Adjunto)
    % =====================================================================
    grad = zeros(length(u), 1);
    
    for n = N:-1:1
        x_n = X_hist(:, n);
        v_n = u((n-1)*2 + 1); w_n = u((n-1)*2 + 2);
        theta_n = x_n(3);
        
        x_pos = x_n(1) - x_obs(1); 
        y_pos = x_n(2) - x_obs(2);
        
        grad_x_l_n = [2 * Q_pos * (x_n(1) - x_ref(1)); 2 * Q_pos * (x_n(2) - x_ref(2)); 0];
        
        % CORREÇÃO MATRIZ -> ESCALAR
        grad_u_l_n = [2 * R_ctrl(1,1) * v_n; 2 * R_ctrl(2,2) * w_n];
        
        % Recalcula as violações
        v_11 = max(0, -x_pos);         v_12 = max(0, x_pos - L_arm);
        v_13 = max(0, -y_pos - W_arm); v_14 = max(0, y_pos - W_arm);
        P1 = v_11^2 + v_12^2 + v_13^2 + v_14^2;
        
        v_21 = max(0, -x_pos - W_arm); v_22 = max(0, x_pos - W_arm);
        v_23 = max(0, -y_pos);         v_24 = max(0, y_pos - L_arm);
        P2 = v_21^2 + v_22^2 + v_23^2 + v_24^2;
        
        v_31 = max(0, -x_pos - L_arm); v_32 = max(0, x_pos);
        v_33 = max(0, -y_pos - W_arm); v_34 = max(0, y_pos - W_arm);
        P3 = v_31^2 + v_32^2 + v_33^2 + v_34^2;
        
        v_41 = max(0, -x_pos - W_arm); v_42 = max(0, x_pos - W_arm);
        v_43 = max(0, -y_pos - L_arm); v_44 = max(0, y_pos);
        P4 = v_41^2 + v_42^2 + v_43^2 + v_44^2;
        
        v_5 = max(0, x_pos^2 + y_pos^2 - R_out^2);
        P5 = v_5^2;
        
        v_6 = max(0, R_in^2 - (x_pos^2 + y_pos^2));
        
        v_71 = max(0, (-L_arm - 2*W_arm) - x_pos); v_72 = max(0, x_pos - (-L_arm));
        v_73 = max(0, -L_arm - y_pos);             v_74 = max(0, y_pos - L_arm);
        P7 = v_71^2 + v_72^2 + v_73^2 + v_74^2;
        
        v_81 = max(0, L_arm - x_pos);              v_82 = max(0, x_pos - (L_arm + 2*W_arm));
        v_83 = max(0, -L_arm - y_pos);             v_84 = max(0, y_pos - L_arm);
        P8 = v_81^2 + v_82^2 + v_83^2 + v_84^2;
        
        grad_geo_n = [0; 0; 0];
        
        % --- A) A MAGIA: Active Set (Gradiente apenas do bloco mais próximo) ---
        [P_min_val, idx_min] = min([P1, P2, P3, P4, P5, P7, P8]);
        
        if P_min_val > 0
            if idx_min == 1
                if v_11 > 0, grad_geo_n(1) = grad_geo_n(1) - 2*v_11; end
                if v_12 > 0, grad_geo_n(1) = grad_geo_n(1) + 2*v_12; end
                if v_13 > 0, grad_geo_n(2) = grad_geo_n(2) - 2*v_13; end
                if v_14 > 0, grad_geo_n(2) = grad_geo_n(2) + 2*v_14; end
            elseif idx_min == 2
                if v_21 > 0, grad_geo_n(1) = grad_geo_n(1) - 2*v_21; end
                if v_22 > 0, grad_geo_n(1) = grad_geo_n(1) + 2*v_22; end
                if v_23 > 0, grad_geo_n(2) = grad_geo_n(2) - 2*v_23; end
                if v_24 > 0, grad_geo_n(2) = grad_geo_n(2) + 2*v_24; end
            elseif idx_min == 3
                if v_31 > 0, grad_geo_n(1) = grad_geo_n(1) - 2*v_31; end
                if v_32 > 0, grad_geo_n(1) = grad_geo_n(1) + 2*v_32; end
                if v_33 > 0, grad_geo_n(2) = grad_geo_n(2) - 2*v_33; end
                if v_34 > 0, grad_geo_n(2) = grad_geo_n(2) + 2*v_34; end
            elseif idx_min == 4
                if v_41 > 0, grad_geo_n(1) = grad_geo_n(1) - 2*v_41; end
                if v_42 > 0, grad_geo_n(1) = grad_geo_n(1) + 2*v_42; end
                if v_43 > 0, grad_geo_n(2) = grad_geo_n(2) - 2*v_43; end
                if v_44 > 0, grad_geo_n(2) = grad_geo_n(2) + 2*v_44; end
            elseif idx_min == 5
                grad_geo_n(1) = 4 * v_5 * x_pos;
                grad_geo_n(2) = 4 * v_5 * y_pos;
            elseif idx_min == 6 % P7
                if v_71 > 0, grad_geo_n(1) = grad_geo_n(1) - 2*v_71; end
                if v_72 > 0, grad_geo_n(1) = grad_geo_n(1) + 2*v_72; end
                if v_73 > 0, grad_geo_n(2) = grad_geo_n(2) - 2*v_73; end
                if v_74 > 0, grad_geo_n(2) = grad_geo_n(2) + 2*v_74; end
            elseif idx_min == 7 % P8
                if v_81 > 0, grad_geo_n(1) = grad_geo_n(1) - 2*v_81; end
                if v_82 > 0, grad_geo_n(1) = grad_geo_n(1) + 2*v_82; end
                if v_83 > 0, grad_geo_n(2) = grad_geo_n(2) - 2*v_83; end
                if v_84 > 0, grad_geo_n(2) = grad_geo_n(2) + 2*v_84; end
            end
        end
        
        % --- B) O Obstáculo Interno ---
        if v_6 > 0
            grad_P6 = [-4 * v_6 * x_pos; -4 * v_6 * y_pos; 0];
            grad_geo_n = grad_geo_n + grad_P6;
        end
        
        grad_x_total = grad_x_l_n + (eta_geo * grad_geo_n);
        
        J_x_T = [1, 0, 0; 0, 1, 0; -Ts * v_n * sin(theta_n), Ts * v_n * cos(theta_n), 1];
        J_u_T = [Ts * cos(theta_n), Ts * sin(theta_n), 0; 0, 0, Ts];
        
        p_prev = p_n; 
        p_n = J_x_T * p_prev + grad_x_total;
        grad((n-1)*2 + 1 : n*2) = J_u_T * p_prev + grad_u_l_n;
    end
end