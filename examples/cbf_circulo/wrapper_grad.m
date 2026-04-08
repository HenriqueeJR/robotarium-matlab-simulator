function grad = wrapper_grad(u, params)
    [~, grad] = build_robot_cbf_circular(u, params);
end