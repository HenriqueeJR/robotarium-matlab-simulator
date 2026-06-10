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
#include "sumMatrixIncludeNaN.h"
#include "wrapper_cost_data.h"
#include "mwmathutil.h"
#include <emmintrin.h>

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = {
    3,              /* lineNo */
    "wrapper_cost", /* fcnName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\cbf_caixa_e_cruz\\wrapper_cost.m" /* pathName */
};

/* Function Definitions */
real_T wrapper_cost(const emlrtStack *sp, const real_T u[20],
                    const real_T params[10])
{
  __m128d r;
  emlrtStack st;
  real_T X_hist[33];
  real_T b_y[9];
  real_T c_a[9];
  real_T y[9];
  real_T L_obs;
  real_T W_obs;
  real_T a;
  real_T b_a;
  real_T cost;
  real_T d;
  real_T d1;
  real_T d2;
  real_T d3;
  real_T d4;
  real_T l_u;
  real_T tmp2;
  real_T x_k_idx_0;
  real_T x_k_idx_1;
  real_T x_next_idx_2;
  int32_T n;
  st.prev = sp;
  st.tls = sp->tls;
  /*  1. Calcula o custo original (distância, obstáculo, etc) */
  st.site = &emlrtRSI;
  /*  =========================================================================
   */
  /*  Algoritmo: Backward AD - Desvio de Obstáculo Retangular (Caixa) via CBF */
  /*  Regra do Produto: P = max(0, dx)^2 * max(0, dy)^2 */
  /*  =========================================================================
   */
  /*  Aumentado para prever mais longe e suavizar a curva */
  /*  R_ctrl aumentado para evitar curvas bruscas */
  /*  Estado inicial x_0 */
  /*  Alvo [x; y] */
  /*  Centro do obstáculo [x; y] */
  L_obs = params[7];
  /*  Meio-comprimento (eixo X) */
  W_obs = params[8];
  /*  Meia-largura (eixo Y) */
  /*  Peso da barreira CBF */
  /*  Raio do robô para inflar o obstáculo */
  /*  Taxa de decaimento menor para antecipar a curva */
  /*  Margem da função P */
  x_k_idx_0 = params[0];
  x_k_idx_1 = params[1];
  x_next_idx_2 = params[2];
  l_u = 0.0;
  /*  ===================================================================== */
  /*  FORWARD PASS */
  /*  ===================================================================== */
  d = params[5];
  d1 = params[6];
  d2 = params[3];
  d3 = params[4];
  d4 = params[9];
  for (n = 0; n < 10; n++) {
    real_T d5;
    real_T d6;
    real_T v_n;
    real_T w_n;
    int32_T v_n_tmp;
    v_n_tmp = n << 1;
    v_n = u[v_n_tmp];
    w_n = u[v_n_tmp + 1];
    /*  1. Violação no estado atual (Regra do Produto da Caixa) */
    b_a = muDoubleScalarMax(0.0,
                            (L_obs + 0.15) - muDoubleScalarAbs(x_k_idx_0 - d));
    a = muDoubleScalarMax(0.0,
                          (W_obs + 0.15) - muDoubleScalarAbs(x_k_idx_1 - d1));
    /*  Simula 1 passo da cinemática */
    cost = 0.033 * v_n;
    d5 = x_k_idx_0 + cost * muDoubleScalarCos(x_next_idx_2);
    d6 = x_k_idx_1 + cost * muDoubleScalarSin(x_next_idx_2);
    x_next_idx_2 += 0.033 * w_n;
    /*  2. Violação no estado futuro */
    cost = muDoubleScalarMax(0.0, (L_obs + 0.15) - muDoubleScalarAbs(d5 - d));
    tmp2 = muDoubleScalarMax(0.0, (W_obs + 0.15) - muDoubleScalarAbs(d6 - d1));
    /*  3. Restrição de Barreira Discreta */
    /*  4. Penalidade */
    a = muDoubleScalarMax(0.0,
                          0.099999999999999978 * (0.0 - b_a * b_a * (a * a)) -
                              (0.0 - cost * cost * (tmp2 * tmp2)));
    tmp2 = x_k_idx_0 - d2;
    cost = x_k_idx_1 - d3;
    l_u = (l_u + (60.0 * (tmp2 * tmp2 + cost * cost) +
                  0.01 * (v_n * v_n + w_n * w_n))) +
          d4 * (a * a);
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
  a = X_hist[30] - params[3];
  b_a = X_hist[31] - params[4];
  /*  2. Pesos de suavização (Tuning) */
  /*  Aumente esses valores se o robô continuar tremendo. */
  /*  Diminua se ele ficar "preguiçoso" demais para desviar. */
  /*  Penalidade para variação de velocidade linear */
  /*  Penalidade para variação de velocidade angular (Alta para matar o
   * zigue-zague) */
  /*  3. Separa as variáveis v e w do vetor u */
  /*  u tem o formato [v1; w1; v2; w2; ...] */
  /*  4. Calcula a variação quadrática (Delta u) ao longo do horizonte */
  /*  A função diff() do MATLAB faz exatamente v(2)-v(1), v(3)-v(2)... */
  cost = u[0];
  for (n = 0; n < 9; n++) {
    tmp2 = cost;
    cost = u[(n + 1) << 1];
    c_a[n] = cost - tmp2;
  }
  r = _mm_loadu_pd(&c_a[0]);
  _mm_storeu_pd(&y[0], _mm_mul_pd(r, r));
  r = _mm_loadu_pd(&c_a[2]);
  _mm_storeu_pd(&y[2], _mm_mul_pd(r, r));
  r = _mm_loadu_pd(&c_a[4]);
  _mm_storeu_pd(&y[4], _mm_mul_pd(r, r));
  r = _mm_loadu_pd(&c_a[6]);
  _mm_storeu_pd(&y[6], _mm_mul_pd(r, r));
  y[8] = c_a[8] * c_a[8];
  cost = u[1];
  for (n = 0; n < 9; n++) {
    tmp2 = cost;
    cost = u[((n + 1) << 1) + 1];
    c_a[n] = cost - tmp2;
  }
  r = _mm_loadu_pd(&c_a[0]);
  _mm_storeu_pd(&b_y[0], _mm_mul_pd(r, r));
  r = _mm_loadu_pd(&c_a[2]);
  _mm_storeu_pd(&b_y[2], _mm_mul_pd(r, r));
  r = _mm_loadu_pd(&c_a[4]);
  _mm_storeu_pd(&b_y[4], _mm_mul_pd(r, r));
  r = _mm_loadu_pd(&c_a[6]);
  _mm_storeu_pd(&b_y[6], _mm_mul_pd(r, r));
  b_y[8] = c_a[8] * c_a[8];
  /*  5. Custo total */
  return (l_u + 60.0 * (a * a + b_a * b_a)) +
         (0.2 * sumColumnB(y) + 0.2 * sumColumnB(b_y));
}

/* End of code generation (wrapper_cost.c) */
