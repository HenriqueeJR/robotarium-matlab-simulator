/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * wrapper_cost.c
 *
 * Code generation for function 'wrapper_cost'
 *
 */

/* Include files */
#include "wrapper_cost.h"
#include "rt_nonfinite.h"
#include "wrapper_cost_data.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = {
    2,              /* lineNo */
    "wrapper_cost", /* fcnName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws\\robotarium-matlab-"
    "simulator\\examples\\cbf_circulo\\wrapper_cost.m" /* pathName */
};

/* Function Definitions */
real_T wrapper_cost(const emlrtStack *sp, const real_T u[20],
                    const real_T params[9])
{
  emlrtStack st;
  real_T X_hist[33];
  real_T a_tmp;
  real_T c_a;
  real_T cost;
  real_T d;
  real_T d1;
  real_T d2;
  real_T d3;
  real_T d4;
  real_T l_u;
  real_T x_k_idx_0;
  real_T x_k_idx_1;
  real_T x_next_idx_2;
  int32_T n;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &emlrtRSI;
  /*  =========================================================================
   */
  /*  Algoritmo: Backward AD - Desvio de Obstáculo Circular (CBF) */
  /*  =========================================================================
   */
  /*  Estado inicial x_0 */
  /*  Alvo [x; y] */
  /*  Centro do obstáculo circular */
  /*  Raio do obstáculo */
  /*  Peso da penalidade (Barreira) */
  /*  --- Dimensões e Parâmetros da Barreira --- */
  /*  Raio do robô (margem de segurança) */
  cost = params[7] + 0.5;
  /*  Distância mínima segura centro a centro */
  /*  Taxa de decaimento da CBF.  */
  /*  Nota: Geralmente 0 < gamma <= 1 em tempo discreto. Ajuste conforme
   * necessário. */
  x_k_idx_0 = params[0];
  x_k_idx_1 = params[1];
  x_next_idx_2 = params[2];
  l_u = 0.0;
  /*  ===================================================================== */
  /*  FORWARD PASS (Avaliação do Custo) */
  /*  ===================================================================== */
  d = params[5];
  d1 = params[6];
  d2 = params[3];
  d3 = params[4];
  d4 = params[8];
  a_tmp = cost * cost;
  for (n = 0; n < 10; n++) {
    real_T a;
    real_T b_a;
    real_T d5;
    real_T d6;
    real_T v_n;
    real_T w_n;
    int32_T v_n_tmp;
    v_n_tmp = n << 1;
    v_n = u[v_n_tmp];
    w_n = u[v_n_tmp + 1];
    /*  1. Barreira no estado atual (h_k) */
    a = x_k_idx_0 - d;
    b_a = x_k_idx_1 - d1;
    /*  Simula 1 passo da cinemática */
    cost = 0.033 * v_n;
    d5 = x_k_idx_0 + cost * muDoubleScalarCos(x_next_idx_2);
    d6 = x_k_idx_1 + cost * muDoubleScalarSin(x_next_idx_2);
    x_next_idx_2 += 0.033 * w_n;
    /*  2. Barreira no estado futuro (h_{k+1}) */
    cost = d5 - d;
    c_a = d6 - d1;
    /*  3. Restrição de Barreira (g_k <= 0) */
    /*  g_k = (1 - gamma)*h_k - h_{k+1} */
    /*  4. Penalidade */
    a = muDoubleScalarMax(0.0, 0.7 * ((a * a + b_a * b_a) - a_tmp) -
                                   ((cost * cost + c_a * c_a) - a_tmp));
    /*  Custo de estágio normal */
    c_a = x_k_idx_0 - d2;
    cost = x_k_idx_1 - d3;
    l_u = (l_u + (30.0 * (c_a * c_a + cost * cost) +
                  0.01 * (v_n * v_n + w_n * w_n))) +
          d4 * (a * a);
    /*  Atualiza estado para o próximo passo */
    x_k_idx_0 = d5;
    v_n_tmp = 3 * (n + 1);
    X_hist[v_n_tmp] = d5;
    x_k_idx_1 = d6;
    X_hist[v_n_tmp + 1] = d6;
    X_hist[v_n_tmp + 2] = x_next_idx_2;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }
  /*  ===================================================================== */
  /*  TERMINAL E INICIALIZAÇÃO DO BACKWARD */
  /*  ===================================================================== */
  cost = X_hist[30] - params[3];
  c_a = X_hist[31] - params[4];
  return l_u + 30.0 * (cost * cost + c_a * c_a);
}

/* End of code generation (wrapper_cost.c) */
