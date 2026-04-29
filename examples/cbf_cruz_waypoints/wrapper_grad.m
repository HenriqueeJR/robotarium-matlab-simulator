function grad = wrapper_grad(u, params)

    [~, grad_base] = build_robot_cbf_experiment(u, params);
    
    R_dv = 0.2;
    R_dw = 0.2;
    
    grad_smooth = zeros(size(u));
    N_horizonte = length(u) / 2;
    
    % Calcula as derivadas parciais 
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