function [cost, grad] = build_robot_cbf_experiment(W, params)
    %#codegen
    % Desempacotamento limpo do vetor params (Tamanho: 30)
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
    
    % Parâmetro h para a Generalized P2S-HSD
    h_p2s = 0.05; 
    
    % =====================================================================
    % FORWARD PASS (Dinâmica com CBF - Ponto a Ponto Suavizado)
    % =====================================================================
    for n = 1:N
        v_n = u((n-1)*2 + 1);
        w_n = u((n-1)*2 + 2);
        
        [P_k, ~] = calc_point_p2s_penalty(x_k(1:2), blocks_params, h_p2s);
        h_k = -P_k; 
        
        x_next = zeros(3,1);
        x_next(1) = x_k(1) + Ts * v_n * cos(x_k(3));
        x_next(2) = x_k(2) + Ts * v_n * sin(x_k(3));
        x_next(3) = x_k(3) + Ts * w_n;
        
        [P_next, ~] = calc_point_p2s_penalty(x_next(1:2), blocks_params, h_p2s);
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
    % GEOFENCE DE SEGMENTOS (Contenção Convexa Suavizada)
    % =====================================================================
    % Segmento 1: xs até r1
    [P_seg0, gP_seg0_xs, gP_seg0_r1] = calc_segment_p2s_penalty(xs, r1, blocks_params, h_p2s);
    cost = cost + mu_safe * P_seg0;
    
    % Segmento 2: r1 até r2
    [P_seg1, gP_seg1_r1, gP_seg1_r2] = calc_segment_p2s_penalty(r1, r2, blocks_params, h_p2s);
    cost = cost + mu_safe * P_seg1;
    
    % Segmento 3: r2 até r3
    [P_seg2, gP_seg2_r2, gP_seg2_r3] = calc_segment_p2s_penalty(r2, r3, blocks_params, h_p2s);
    cost = cost + mu_safe * P_seg2;
    
    % Segmento 4: r3 até r4 (x_ref)
    [P_seg3, gP_seg3_r3, ~] = calc_segment_p2s_penalty(r3, r4, blocks_params, h_p2s);
    cost = cost + mu_safe * P_seg3; 
    
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
    
    % Acumulação Incondicional dos Gradientes de Segmento
    grad_xs = grad_xs + mu_safe * gP_seg0_xs;
    
    % Cada ponto r intermediário acumula gradiente das duas retas conectadas a ele
    grad_r1 = grad_r1 + mu_safe * (gP_seg0_r1 + gP_seg1_r1);
    grad_r2 = grad_r2 + mu_safe * (gP_seg1_r2 + gP_seg2_r2);
    grad_r3 = grad_r3 + mu_safe * (gP_seg2_r3 + gP_seg3_r3);
    
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
        
        % Avaliação Suavizada Ponto a Ponto para CBF
        [P_k, gP_k] = calc_point_p2s_penalty(x_n(1:2), blocks_params, h_p2s);
        h_k = -P_k;
        
        [P_next, gP_next] = calc_point_p2s_penalty(x_next(1:2), blocks_params, h_p2s);
        h_next = -P_next;
        
        g_corridor = (1 - gamma_safe) * h_k - h_next;
        
        grad_x_k_cbf = [0; 0; 0];
        grad_x_next_cbf = [0; 0; 0];
        
        if g_corridor > 0
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
% FUNÇÃO BASE: Generalized P2S-HSD (Phi e Phi')
% =========================================================================
function [val, grad] = phi_func(s, h)
    %#codegen
    if s >= 0
        val = (s^3) / (2 * (s + h));
        grad = (s^2 * (2*s + 3*h)) / (2 * (s + h)^2);
    else
        val = 0;
        grad = 0;
    end
end

% =========================================================================
% FUNÇÃO AUXILIAR: P2S-HSD para UM Polítopo Convexo
% =========================================================================
function [P, gP] = get_single_block_p2s(pt, blk, h)
    %#codegen
    x_pos = pt(1); y_pos = pt(2);
    
    s1 = blk(1) - x_pos; 
    s2 = x_pos - blk(2); 
    s3 = blk(3) - y_pos; 
    s4 = y_pos - blk(4); 
    
    [v1, g1] = phi_func(s1, h);
    [v2, g2] = phi_func(s2, h);
    [v3, g3] = phi_func(s3, h);
    [v4, g4] = phi_func(s4, h);
    
    P = 0.25 * (v1 + v2 + v3 + v4);
    
    gP = zeros(2,1);
    gP(1) = 0.25 * (-g1 + g2);
    gP(2) = 0.25 * (-g3 + g4);
end

% =========================================================================
% FUNÇÃO AUXILIAR: Mínimo Suave Base (Smooth Min)
% =========================================================================
function [M, gM] = smooth_min_func(a, b, ga, gb)
    %#codegen
    epsilon = 1e-10; % Fator de suavização Numérica
    diff = a - b;
    delta = sqrt(diff^2 + epsilon);
    M = 0.5 * (a + b - delta);
    % O gradiente repassa perfeitamente a direção correspondente ao menor valor
    gM = 0.5 * (ga + gb - (diff / delta) * (ga - gb));
end

% =========================================================================
% FUNÇÃO AUXILIAR: Penalidade de Segmento (Contenção Convexa Suavizada)
% =========================================================================
function [Cost, grad_pa, grad_pb] = calc_segment_p2s_penalty(pa, pb, blocks, h)
    %#codegen
    [Pa1, gPa1] = get_single_block_p2s(pa, blocks(1:4), h);
    [Pa2, gPa2] = get_single_block_p2s(pa, blocks(5:8), h);
    [Pa3, gPa3] = get_single_block_p2s(pa, blocks(9:12), h);
    [Pa4, gPa4] = get_single_block_p2s(pa, blocks(13:16), h);
    
    [Pb1, gPb1] = get_single_block_p2s(pb, blocks(1:4), h);
    [Pb2, gPb2] = get_single_block_p2s(pb, blocks(5:8), h);
    [Pb3, gPb3] = get_single_block_p2s(pb, blocks(9:12), h);
    [Pb4, gPb4] = get_single_block_p2s(pb, blocks(13:16), h);
    
    C1 = Pa1 + Pb1;
    C2 = Pa2 + Pb2;
    C3 = Pa3 + Pb3;
    C4 = Pa4 + Pb4;
    
    gC1 = [gPa1; gPb1];
    gC2 = [gPa2; gPb2];
    gC3 = [gPa3; gPb3];
    gC4 = [gPa4; gPb4];
    
    [M12, gM12] = smooth_min_func(C1, C2, gC1, gC2);
    [M34, gM34] = smooth_min_func(C3, C4, gC3, gC4);
    
    [Cost, gTotal] = smooth_min_func(M12, M34, gM12, gM34);
    
    grad_pa = gTotal(1:2);
    grad_pb = gTotal(3:4);
end

% =========================================================================
% FUNÇÃO AUXILIAR: Penalidade Ponto a Ponto (Smooth Min para a CBF)
% =========================================================================
function [P_total, grad_P] = calc_point_p2s_penalty(pt, blocks, h)
    %#codegen
    [Pa, gPa] = get_single_block_p2s(pt, blocks(1:4), h);
    [Pv, gPv] = get_single_block_p2s(pt, blocks(5:8), h);
    [Pg, gPg] = get_single_block_p2s(pt, blocks(9:12), h);
    [Pc, gPc] = get_single_block_p2s(pt, blocks(13:16), h);
    
    [P1, g1] = smooth_min_func(Pa, Pv, gPa, gPv);
    [P2, g2] = smooth_min_func(Pg, Pc, gPg, gPc);
    [P_total, grad_P] = smooth_min_func(P1, P2, g1, g2);
end