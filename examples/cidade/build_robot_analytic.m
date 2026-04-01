% =========================================================================
% Algoritmo 1: Backward AD (Cruz 4 Retângulos + 2 Círculos - Regra do Produto)
% =========================================================================
function [cost, grad] = build_robot_analytic(u, params)
    %#codegen
    N = 75;
    Ts = 0.033;
    Q_pos = 10; R_ctrl = 0.001; 
    
    x_k = params(1:3);      % Estado inicial x_0
    x_ref = params(4:5);
    x_obs = params(6:7);    % Centro da topologia (ex: [0; 0])
    eta_geo = params(8);    % Peso da penalidade global
    
    % --- Dimensões da Geometria ---
    L_arm = 1.5;  % Comprimento dos braços a partir do centro
    W_arm = 0.3;  % Meia-largura dos braços
    R_out = 0.5;  % Raio do círculo externo (Hub conector)
    R_in  = 0.2;  % Raio do círculo interno (Buraco a evitar)

    % Raio do robô para inflar restrições (Margem de segurança)
    r_rob = 0.1; 
    
    X_hist = zeros(3, N + 1);
    X_hist(:, 1) = x_k;
    l_u = 0; 
    
    % =====================================================================
    % FORWARD PASS (Avaliação do Custo)
    % =====================================================================
    for n = 1:N
        v_n = u((n-1)*2 + 1);
        w_n = u((n-1)*2 + 2);
        
        % x_pos = x_k(1) - x_obs(1); 
        % y_pos = x_k(2) - x_obs(2);
        d_off = 0.035;
        x_pos = (x_k(1) + d_off * cos(x_k(3))) - x_obs(1); 
        y_pos = (x_k(2) + d_off * sin(x_k(3))) - x_obs(2);
        
        
        % 1. Retângulo 1 (Braço Direito)
        % x_pos >= 0 vira x_pos >= r_rob  =>  max(0, r_rob - x_pos)
        v_11 = max(0, r_rob - x_pos);                  v_12 = max(0, x_pos - (L_arm - r_rob));
        v_13 = max(0, -y_pos - (W_arm - r_rob));       v_14 = max(0, y_pos - (W_arm - r_rob));
        P1 = v_11^2 + v_12^2 + v_13^2 + v_14^2;
        
        % 2. Retângulo 2 (Braço Superior)
        v_21 = max(0, -x_pos - (W_arm - r_rob));       v_22 = max(0, x_pos - (W_arm - r_rob));
        v_23 = max(0, r_rob - y_pos);                  v_24 = max(0, y_pos - (L_arm - r_rob));
        P2 = v_21^2 + v_22^2 + v_23^2 + v_24^2;
        
        % 3. Retângulo 3 (Braço Esquerdo)
        % x_pos <= 0 vira x_pos <= -r_rob =>  max(0, x_pos + r_rob)
        v_31 = max(0, -x_pos - (L_arm - r_rob));       v_32 = max(0, x_pos + r_rob);
        v_33 = max(0, -y_pos - (W_arm - r_rob));       v_34 = max(0, y_pos - (W_arm - r_rob));
        P3 = v_31^2 + v_32^2 + v_33^2 + v_34^2;
        
        % 4. Retângulo 4 (Braço Inferior)
        v_41 = max(0, -x_pos - (W_arm - r_rob));       v_42 = max(0, x_pos - (W_arm - r_rob));
        v_43 = max(0, -y_pos - (L_arm - r_rob));       v_44 = max(0, y_pos + r_rob);
        P4 = v_41^2 + v_42^2 + v_43^2 + v_44^2;
        
        % 5. Círculo Externo (Conexão Segura no Centro)
        % Encolhemos a zona segura subtraindo o raio do robô
        v_5 = max(0, x_pos^2 + y_pos^2 - (R_out - r_rob)^2);
        P5 = v_5^2;
        
        % 6. Círculo Interno (Buraco / Obstáculo)
        % Inflamos o obstáculo somando o raio do robô
        v_6 = max(0, (R_in + r_rob)^2 - (x_pos^2 + y_pos^2));
        P6 = v_6^2;
        
        % A UNIÃO multiplicativa + SOMATÓRIO do obstáculo
        P_cruz = min([P1, P2, P3, P4, P5]);
        geo_penalty = eta_geo * (P_cruz + P6);
        
        l_estagio = Q_pos * ((x_k(1) - x_ref(1))^2 + (x_k(2) - x_ref(2))^2) + R_ctrl * (v_n^2 + w_n^2);
        l_u = l_u + l_estagio + geo_penalty;
        
        % Dinâmica Cinemática
        x_k(1) = x_k(1) + Ts * v_n * cos(x_k(3));
        x_k(2) = x_k(2) + Ts * v_n * sin(x_k(3));
        x_k(3) = x_k(3) + Ts * w_n;
        
        X_hist(:, n+1) = x_k;
    end
    
    cost = l_u;
    
    % =====================================================================
    % TERMINAL E INICIALIZAÇÃO DO BACKWARD
    % =====================================================================
    x_N = X_hist(:, N+1);
    % x_pos_N = x_N(1) - x_obs(1); 
    % y_pos_N = x_N(2) - x_obs(2);
    
    x_pos_N = (x_N(1) + d_off * cos(x_N(3))) - x_obs(1); 
    y_pos_N = (x_N(2) + d_off * sin(x_N(3))) - x_obs(2);
    
    % P1_N = max(0, -x_pos_N)^2 + max(0, x_pos_N-L_arm)^2 + max(0, -y_pos_N-W_arm)^2 + max(0, y_pos_N-W_arm)^2;
    % P2_N = max(0, -x_pos_N-W_arm)^2 + max(0, x_pos_N-W_arm)^2 + max(0, -y_pos_N)^2 + max(0, y_pos_N-L_arm)^2;
    % P3_N = max(0, -x_pos_N-L_arm)^2 + max(0, x_pos_N)^2 + max(0, -y_pos_N-W_arm)^2 + max(0, y_pos_N-W_arm)^2;
    % P4_N = max(0, -x_pos_N-W_arm)^2 + max(0, x_pos_N-W_arm)^2 + max(0, -y_pos_N-L_arm)^2 + max(0, y_pos_N)^2;
    % P5_N = max(0, x_pos_N^2 + y_pos_N^2 - R_out^2)^2;
    % P6_N = max(0, R_in^2 - (x_pos_N^2 + y_pos_N^2))^2;
    % 
    % geo_penalty_N = eta_geo * ((P1_N * P2_N * P3_N * P4_N * P5_N) + P6_N);
    % geo_penalty_N = 0;
    l_N = Q_pos * ((x_N(1) - x_ref(1))^2 + (x_N(2) - x_ref(2))^2);
    % cost = cost + l_N + geo_penalty_N;
    cost = cost + l_N;
    
    if nargout == 1, return; end
    
    grad_x_l_N = [2 * Q_pos * (x_N(1) - x_ref(1)); 2 * Q_pos * (x_N(2) - x_ref(2)); 0];
    p_n = grad_x_l_N;
    
    % =====================================================================
    % BACKWARD PASS (Método Adjunto com Regra do Produto de 5 Termos)
    % =====================================================================
    grad = zeros(length(u), 1);
    
    for n = N:-1:1
        x_n = X_hist(:, n);
        v_n = u((n-1)*2 + 1); w_n = u((n-1)*2 + 2);
        theta_n = x_n(3);
        
        % x_pos = x_n(1) - x_obs(1); 
        % y_pos = x_n(2) - x_obs(2);
 
        x_pos = (x_n(1) + d_off * cos(theta_n)) - x_obs(1); 
        y_pos = (x_n(2) + d_off * sin(theta_n)) - x_obs(2);

        grad_x_l_n = [2 * Q_pos * (x_n(1) - x_ref(1)); 2 * Q_pos * (x_n(2) - x_ref(2)); 0];
        grad_u_l_n = [2 * R_ctrl * v_n; 2 * R_ctrl * w_n];
        
        % Recalcula as violações
        v_11 = max(0, r_rob - x_pos);                  v_12 = max(0, x_pos - (L_arm - r_rob));
        v_13 = max(0, -y_pos - (W_arm - r_rob));       v_14 = max(0, y_pos - (W_arm - r_rob));
        P1 = v_11^2 + v_12^2 + v_13^2 + v_14^2;
        
        v_21 = max(0, -x_pos - (W_arm - r_rob));       v_22 = max(0, x_pos - (W_arm - r_rob));
        v_23 = max(0, r_rob - y_pos);                  v_24 = max(0, y_pos - (L_arm - r_rob));
        P2 = v_21^2 + v_22^2 + v_23^2 + v_24^2;

        v_31 = max(0, -x_pos - (L_arm - r_rob));       v_32 = max(0, x_pos + r_rob);
        v_33 = max(0, -y_pos - (W_arm - r_rob));       v_34 = max(0, y_pos - (W_arm - r_rob));
        P3 = v_31^2 + v_32^2 + v_33^2 + v_34^2;

        v_41 = max(0, -x_pos - (W_arm - r_rob));       v_42 = max(0, x_pos - (W_arm - r_rob));
        v_43 = max(0, -y_pos - (L_arm - r_rob));       v_44 = max(0, y_pos + r_rob);
        P4 = v_41^2 + v_42^2 + v_43^2 + v_44^2;

        v_5 = max(0, x_pos^2 + y_pos^2 - (R_out - r_rob)^2);
        P5 = v_5^2;
        
        v_6 = max(0, (R_in + r_rob)^2 - (x_pos^2 + y_pos^2));
        
        grad_geo_n = [0; 0; 0];
        
        distancias = [P1, P2, P3, P4, P5];
        [P_min, idx_min] = min(distancias);
        
        grad_P_cruz = [0; 0; 0];
        
        % Só calcula gradiente se o robô estiver fora de TODOS os blocos da cruz
        if P_min > 0
            % Calcula apenas o gradiente do bloco mais próximo para puxar o robô de volta
            if idx_min == 1
                if v_11 > 0, grad_P_cruz(1) = grad_P_cruz(1) - 2*v_11; end
                if v_12 > 0, grad_P_cruz(1) = grad_P_cruz(1) + 2*v_12; end
                if v_13 > 0, grad_P_cruz(2) = grad_P_cruz(2) - 2*v_13; end
                if v_14 > 0, grad_P_cruz(2) = grad_P_cruz(2) + 2*v_14; end
            elseif idx_min == 2
                if v_21 > 0, grad_P_cruz(1) = grad_P_cruz(1) - 2*v_21; end
                if v_22 > 0, grad_P_cruz(1) = grad_P_cruz(1) + 2*v_22; end
                if v_23 > 0, grad_P_cruz(2) = grad_P_cruz(2) - 2*v_23; end
                if v_24 > 0, grad_P_cruz(2) = grad_P_cruz(2) + 2*v_24; end
            elseif idx_min == 3
                if v_31 > 0, grad_P_cruz(1) = grad_P_cruz(1) - 2*v_31; end
                if v_32 > 0, grad_P_cruz(1) = grad_P_cruz(1) + 2*v_32; end
                if v_33 > 0, grad_P_cruz(2) = grad_P_cruz(2) - 2*v_33; end
                if v_34 > 0, grad_P_cruz(2) = grad_P_cruz(2) + 2*v_34; end
            elseif idx_min == 4
                if v_41 > 0, grad_P_cruz(1) = grad_P_cruz(1) - 2*v_41; end
                if v_42 > 0, grad_P_cruz(1) = grad_P_cruz(1) + 2*v_42; end
                if v_43 > 0, grad_P_cruz(2) = grad_P_cruz(2) - 2*v_43; end
                if v_44 > 0, grad_P_cruz(2) = grad_P_cruz(2) + 2*v_44; end
            elseif idx_min == 5
                grad_P_cruz(1) = 4 * v_5 * x_pos;
                grad_P_cruz(2) = 4 * v_5 * y_pos;
            end
        end
        
        grad_geo_n = grad_geo_n + grad_P_cruz;
        
        % --- B) O Obstáculo Interno (Evasão aditiva) ---
        if v_6 > 0
            % Derivada de (R^2 - x^2 - y^2)^2 em relação a x e y
            grad_P6 = [-4 * v_6 * x_pos; -4 * v_6 * y_pos; 0];
            grad_geo_n = grad_geo_n + grad_P6;
        end
        
        % Escala pelo fator de penalidade global
        gx = grad_geo_n(1);
        gy = grad_geo_n(2);
        grad_geo_n(3) = gx * (-d_off * sin(theta_n)) + gy * (d_off * cos(theta_n));
        grad_geo_n = eta_geo * grad_geo_n;
        %grad_geo_n = 0;
        
        grad_x_total = grad_x_l_n + grad_geo_n;
        
        J_x_T = [1, 0, 0; 0, 1, 0; -Ts * v_n * sin(theta_n), Ts * v_n * cos(theta_n), 1];
        J_u_T = [Ts * cos(theta_n), Ts * sin(theta_n), 0; 0, 0, Ts];
        
        p_prev = p_n; 
        p_n = J_x_T * p_prev + grad_x_total;
        grad((n-1)*2 + 1 : n*2) = J_u_T * p_prev + grad_u_l_n;
    end
end