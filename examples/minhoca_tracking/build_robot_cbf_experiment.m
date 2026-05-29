function [cost, grad] = build_robot_cbf_experiment(W, params)
    %#codegen
    % Desempacotamento do vetor params (Tamanho: 30)
    x_k           = params(1:3);      
    x_ref         = params(4:5);      
    eta_safe      = params(6);        
    gamma_safe    = params(7);        
    N             = params(8);             
    Ts            = params(9);           
    blocks_params = params(11:26); % Limites [xmin, xmax, ymin, ymax] dos 4 blocos
    
    eta_term      = params(27);
    eta_eq        = params(28);
    mu_safe       = params(29);
    kappa_s       = params(30); 
    
    Q_pos = 5;         
    R_v = 0.5;          
    R_w = 1;          
    
    u  = W(1:2*N);
    xs = W(2*N+1 : 2*N+2); 
    us = W(2*N+3 : 2*N+4);
    v_s = us(1);
    w_s = us(2);
    
    idx_r1 = 2*N + 5;
    idx_r2 = 2*N + 7;
    idx_r3 = 2*N + 9;
    
    r1 = W(idx_r1 : idx_r1 + 1);
    r2 = W(idx_r2 : idx_r2 + 1);
    r3 = W(idx_r3 : idx_r3 + 1);
    
    X_hist = zeros(3, N + 1);
    X_hist(:, 1) = x_k;
    l_u = 0; 
    
    % Parâmetro h para a Generalized P2S-HSD (suavização)
    h_p2s = 0.00001; 
    
    % =====================================================================
    % FORWARD PASS (Dinâmica com CBF - Mantém a Distância Exata Quadratica)
    % =====================================================================
    for n = 1:N
        v_n = u((n-1)*2 + 1);
        w_n = u((n-1)*2 + 2);
        
        [P_a_k, P_v_k, P_g_k, P_c_k] = get_exact_blocks_P(x_k(1:2), blocks_params);
        P_k = min([P_a_k, P_v_k, P_g_k, P_c_k]);
        h_k = -P_k; 
        
        x_next = zeros(3,1);
        x_next(1) = x_k(1) + Ts * v_n * cos(x_k(3));
        x_next(2) = x_k(2) + Ts * v_n * sin(x_k(3));
        x_next(3) = x_k(3) + Ts * w_n;
        
        [P_a_n, P_v_n, P_g_n, P_c_n] = get_exact_blocks_P(x_next(1:2), blocks_params);
        P_next = min([P_a_n, P_v_n, P_g_n, P_c_n]);
        h_next = -P_next;
        
        g_corridor = (1 - gamma_safe) * h_k - h_next;
        penalty_corridor = eta_safe * max(0, g_corridor)^2;
        
        l_estagio = Q_pos * ((x_k(1) - xs(1))^2 + (x_k(2) - xs(2))^2) + R_v * (v_n - v_s)^2 + R_w * (w_n - w_s)^2;
        l_u = l_u + l_estagio + penalty_corridor;
        
        x_k = x_next;
        X_hist(:, n+1) = x_k;
    end
    
    cost = l_u;
    
    % =====================================================================
    % TERMINAL E BACKWARD PASS
    % =====================================================================
    x_N = X_hist(:, N+1);
    cost = cost + eta_term * sum((x_N(1:2) - xs).^2);
    cost = cost + eta_eq * Ts^2 * (v_s^2 + w_s^2);
    
    r0 = xs; 
    r4 = x_ref;     
    cost = cost + kappa_s * (sum((r1 - r0).^2) + ...
                             sum((r2 - r1).^2) + ...
                             sum((r3 - r2).^2) + ...
                             sum((r4 - r3).^2));
                         
    % =====================================================================
    % GEOFENCE PONTO A PONTO USANDO GENERALIZED P2S-HSD
    % =====================================================================
    [P_xs, gP_xs] = calc_point_p2s_penalty(xs, blocks_params, h_p2s);
    cost = cost + (mu_safe) * P_xs;
    
    [P_r1, gP_r1] = calc_point_p2s_penalty(r1, blocks_params, h_p2s);
    cost = cost + (mu_safe) * P_r1;
    
    [P_r2, gP_r2] = calc_point_p2s_penalty(r2, blocks_params, h_p2s);
    cost = cost + (mu_safe) * P_r2;
    
    [P_r3, gP_r3] = calc_point_p2s_penalty(r3, blocks_params, h_p2s);
    cost = cost + (mu_safe) * P_r3;
    
    [P_r4, ~] = calc_point_p2s_penalty(r4, blocks_params, h_p2s);
    cost = cost + (mu_safe) * P_r4; 
    
    if nargout == 1, return; end
    
    grad = zeros(length(W), 1);
    grad_U  = zeros(2*N, 1);
    grad_xs = zeros(2, 1);
    grad_us = zeros(2, 1);
    
    p_n = zeros(3, 1);
    p_n(1:2) = p_n(1:2) + 2 * eta_term * (x_N(1:2) - xs);
    
    grad_xs = grad_xs - 2 * eta_term * (x_N(1:2) - xs);
    grad_xs = grad_xs - 2 * kappa_s * (r1 - r0);
    grad_r1 = 2 * kappa_s * (2*r1 - r0 - r2); 
    grad_r2 = 2 * kappa_s * (2*r2 - r1 - r3); 
    grad_r3 = 2 * kappa_s * (2*r3 - r2 - r4);
    
    grad_us(1) = grad_us(1) + 2 * eta_eq * Ts^2 * v_s;
    grad_us(2) = grad_us(2) + 2 * eta_eq * Ts^2 * w_s;
    
    % Acumulação dos Gradientes Nodais
    if P_xs > 0, grad_xs = grad_xs + (mu_safe) * gP_xs; end
    if P_r1 > 0, grad_r1 = grad_r1 + (mu_safe) * gP_r1; end
    if P_r2 > 0, grad_r2 = grad_r2 + (mu_safe) * gP_r2; end
    if P_r3 > 0, grad_r3 = grad_r3 + (mu_safe) * gP_r3; end
    
    for n = N:-1:1
        x_n = X_hist(:, n);       
        x_next = X_hist(:, n+1);  
        v_n = u((n-1)*2 + 1); w_n = u((n-1)*2 + 2);
        theta_n = x_n(3);
        
        grad_x_l_n = [2 * Q_pos * (x_n(1) - xs(1)); 2 * Q_pos * (x_n(2) - xs(2)); 0];
        grad_u_l_n = [2 * R_v * (v_n - v_s); 2 * R_w * (w_n - w_s)];
        grad_xs(1) = grad_xs(1) - 2 * Q_pos * (x_n(1) - xs(1));
        grad_xs(2) = grad_xs(2) - 2 * Q_pos * (x_n(2) - xs(2));
        grad_us(1) = grad_us(1) - 2 * R_v * (v_n - v_s);
        grad_us(2) = grad_us(2) - 2 * R_w * (w_n - w_s);
        
        [P_a_k, P_v_k, P_g_k, P_c_k] = get_exact_blocks_P(x_n(1:2), blocks_params);
        P_k = min([P_a_k, P_v_k, P_g_k, P_c_k]);
        h_k = -P_k;
        
        [P_a_n, P_v_n, P_g_n, P_c_n] = get_exact_blocks_P(x_next(1:2), blocks_params);
        P_next = min([P_a_n, P_v_n, P_g_n, P_c_n]);
        h_next = -P_next;
        
        g_corridor = (1 - gamma_safe) * h_k - h_next;
        
        grad_x_k_cbf = [0; 0; 0];
        grad_x_next_cbf = [0; 0; 0];
        
        if g_corridor > 0
            gP_k = get_exact_grad(x_n(1:2), blocks_params, P_a_k, P_v_k, P_g_k, P_c_k);
            gP_next = get_exact_grad(x_next(1:2), blocks_params, P_a_n, P_v_n, P_g_n, P_c_n);
            
            gh_k = -gP_k;
            gh_next = -gP_next;
            
            gg_k = (1 - gamma_safe) * gh_k;
            gg_next = -1 * gh_next;
            
            grad_x_k_cbf(1:2) = grad_x_k_cbf(1:2) + (2 * eta_safe * g_corridor * gg_k);
            grad_x_next_cbf(1:2) = grad_x_next_cbf(1:2) + (2 * eta_safe * g_corridor * gg_next);
        end
        
        p_prev = p_n + grad_x_next_cbf; 
        grad_x_total = grad_x_l_n + grad_x_k_cbf;
        
        J_x_T = [1, 0, 0; 0, 1, 0; -Ts * v_n * sin(theta_n), Ts * v_n * cos(theta_n), 1];
        J_u_T = [Ts * cos(theta_n), Ts * sin(theta_n), 0; 0, 0, Ts];
        
        p_n = J_x_T * p_prev + grad_x_total;
        grad_U((n-1)*2 + 1 : n*2) = J_u_T * p_prev + grad_u_l_n;
    end
    
    grad(1:2*N) = grad_U;
    grad(2*N+1:2*N+2) = grad_xs;
    grad(2*N+3:2*N+4) = grad_us;
    grad(idx_r1 : idx_r1 + 1) = grad_r1;
    grad(idx_r2 : idx_r2 + 1) = grad_r2;
    grad(idx_r3 : idx_r3 + 1) = grad_r3;
end

% =========================================================================
% FUNÇÃO BASE: Generalized P2S-HSD (Função Phi e sua Derivada)
% =========================================================================
function [val, grad] = phi_func(s, h)
    %#codegen
    if s >= 0
        % Função Phi(s)
        val = (s^3) / (2 * (s + h));
        % Derivada Analítica Phi'(s)
        grad = (s^2 * (2*s + 3*h)) / (2 * (s + h)^2);
    else
        val = 0;
        grad = 0;
    end
end

% =========================================================================
% FUNÇÃO AUXILIAR: P2S-HSD para UM Polítopo Convexo (Bloco 2D)
% =========================================================================
function [P, gP] = get_single_block_p2s(pt, blk, h)
    %#codegen
    x_pos = pt(1); y_pos = pt(2);
    
    % Distâncias para as 4 faces do bloco (a_i^T p - b_i <= 0)
    s1 = blk(1) - x_pos; % Face esquerda
    s2 = x_pos - blk(2); % Face direita
    s3 = blk(3) - y_pos; % Face inferior
    s4 = y_pos - blk(4); % Face superior
    
    [v1, g1] = phi_func(s1, h);
    [v2, g2] = phi_func(s2, h);
    [v3, g3] = phi_func(s3, h);
    [v4, g4] = phi_func(s4, h);
    
    % Weak Generalized P2S-HSD: (1/N) * Sum(Phi)
    % Como temos 4 faces (N=4), multiplicamos por 1/4 = 0.25
    P = 0.25 * (v1 + v2 + v3 + v4);
    
    gP = zeros(2,1);
    % Derivadas da cadeia considerando a normal de cada face
    gP(1) = 0.25 * (-g1 + g2);
    gP(2) = 0.25 * (-g3 + g4);
end

% =========================================================================
% FUNÇÃO AUXILIAR: Penalidade Ponto a Ponto (Regra do Produto com P2S)
% =========================================================================
function [P_total, grad_P] = calc_point_p2s_penalty(pt, blocks, h)
    %#codegen
    [Pa, gPa] = get_single_block_p2s(pt, blocks(1:4), h);
    [Pv, gPv] = get_single_block_p2s(pt, blocks(5:8), h);
    [Pg, gPg] = get_single_block_p2s(pt, blocks(9:12), h);
    [Pc, gPc] = get_single_block_p2s(pt, blocks(13:16), h);
    
    % Multiplicatório P(p) da união
    P_total = Pa * Pv * Pg * Pc;
    grad_P = zeros(2,1);
    
    if P_total > 0
        % Gradiente da Regra do Produto (Analítico e Suave)
        grad_P = gPa * (Pv * Pg * Pc) + ...
                 gPv * (Pa * Pg * Pc) + ...
                 gPg * (Pa * Pv * Pc) + ...
                 gPc * (Pa * Pv * Pg);
    end
end

% =========================================================================
% FUNÇÕES DO CBF (Avaliação Exata Mantida para Freios Corretos da Dinâmica)
% =========================================================================
function [P_a, P_v, P_g, P_c] = get_exact_blocks_P(pt, blocks)
    %#codegen
    x_pos = pt(1); y_pos = pt(2);
    
    v_a1 = max(0, blocks(1) - x_pos); v_a2 = max(0, x_pos - blocks(2));
    v_a3 = max(0, blocks(3) - y_pos); v_a4 = max(0, y_pos - blocks(4));
    P_a = v_a1^2 + v_a2^2 + v_a3^2 + v_a4^2;
    
    v_v1 = max(0, blocks(5) - x_pos); v_v2 = max(0, x_pos - blocks(6));
    v_v3 = max(0, blocks(7) - y_pos); v_v4 = max(0, y_pos - blocks(8));
    P_v = v_v1^2 + v_v2^2 + v_v3^2 + v_v4^2;
    
    v_g1 = max(0, blocks(9) - x_pos); v_g2 = max(0, x_pos - blocks(10));
    v_g3 = max(0, blocks(11)- y_pos); v_g4 = max(0, y_pos - blocks(12));
    P_g = v_g1^2 + v_g2^2 + v_g3^2 + v_g4^2;
    
    v_c1 = max(0, blocks(13)- x_pos); v_c2 = max(0, x_pos - blocks(14));
    v_c3 = max(0, blocks(15)- y_pos); v_c4 = max(0, y_pos - blocks(16));
    P_c = v_c1^2 + v_c2^2 + v_c3^2 + v_c4^2;
end

function gP_min = get_exact_grad(pt, blocks, P_a, P_v, P_g, P_c)
    %#codegen
    x_pos = pt(1); y_pos = pt(2);
    P_min = min([P_a, P_v, P_g, P_c]);
    gP_min = zeros(2,1);
    
    if P_min == P_a
        if blocks(1) - x_pos > 0, gP_min(1) = gP_min(1) - 2*(blocks(1) - x_pos); end
        if x_pos - blocks(2) > 0, gP_min(1) = gP_min(1) + 2*(x_pos - blocks(2)); end
        if blocks(3) - y_pos > 0, gP_min(2) = gP_min(2) - 2*(blocks(3) - y_pos); end
        if y_pos - blocks(4) > 0, gP_min(2) = gP_min(2) + 2*(y_pos - blocks(4)); end
    elseif P_min == P_v
        if blocks(5) - x_pos > 0, gP_min(1) = gP_min(1) - 2*(blocks(5) - x_pos); end
        if x_pos - blocks(6) > 0, gP_min(1) = gP_min(1) + 2*(x_pos - blocks(6)); end
        if blocks(7) - y_pos > 0, gP_min(2) = gP_min(2) - 2*(blocks(7) - y_pos); end
        if y_pos - blocks(8) > 0, gP_min(2) = gP_min(2) + 2*(y_pos - blocks(8)); end
    elseif P_min == P_g
        if blocks(9) - x_pos > 0, gP_min(1) = gP_min(1) - 2*(blocks(9) - x_pos); end
        if x_pos - blocks(10)> 0, gP_min(1) = gP_min(1) + 2*(x_pos - blocks(10)); end
        if blocks(11)- y_pos > 0, gP_min(2) = gP_min(2) - 2*(blocks(11)- y_pos); end
        if y_pos - blocks(12)> 0, gP_min(2) = gP_min(2) + 2*(y_pos - blocks(12)); end
    else
        if blocks(13)- x_pos > 0, gP_min(1) = gP_min(1) - 2*(blocks(13)- x_pos); end
        if x_pos - blocks(14)> 0, gP_min(1) = gP_min(1) + 2*(x_pos - blocks(14)); end
        if blocks(15)- y_pos > 0, gP_min(2) = gP_min(2) - 2*(blocks(15)- y_pos); end
        if y_pos - blocks(16)> 0, gP_min(2) = gP_min(2) + 2*(y_pos - blocks(16)); end
    end
end