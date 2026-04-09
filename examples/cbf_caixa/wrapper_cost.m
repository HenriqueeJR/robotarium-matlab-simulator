function cost = wrapper_cost(u, params)
    % 1. Calcula o custo original (distância, obstáculo, etc)
    cost_base = build_robot_cbf_experiment(u, params);
    
    % 2. Pesos de suavização (Tuning)
    % Aumente esses valores se o robô continuar tremendo.
    % Diminua se ele ficar "preguiçoso" demais para desviar.
    R_dv = 0.9; % Penalidade para variação de velocidade linear
    R_dw = 0.9; % Penalidade para variação de velocidade angular (Alta para matar o zigue-zague)
    
    % 3. Separa as variáveis v e w do vetor u
    % u tem o formato [v1; w1; v2; w2; ...]
    v = u(1:2:end-1);
    w = u(2:2:end);
    
    % 4. Calcula a variação quadrática (Delta u) ao longo do horizonte
    % A função diff() do MATLAB faz exatamente v(2)-v(1), v(3)-v(2)...
    cost_smooth = R_dv * sum(diff(v).^2) + R_dw * sum(diff(w).^2);
    
    % 5. Custo total
    cost = cost_base + cost_smooth;

end