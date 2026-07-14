function cost = wrapper_cost(u, params)

    cost_base = build_robot_cbf_experiment(u, params);
    
    % Pesos de suavização 
    R_dv = 0.2; 
    R_dw = 0.2; 
    
    v = u(1:2:end-1);
    w = u(2:2:end);
    
    cost_smooth = R_dv * sum(diff(v).^2) + R_dw * sum(diff(w).^2);
    
    % Custo total
    cost = cost_base + cost_smooth;

end