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
    "C:\\Users\\henri\\Desktop\\robotarium_ws\\robotarium-matlab-"
    "simulator\\examples\\cbf_caixa\\wrapper_cost.m" /* pathName */
};

/* Function Definitions */
real_T wrapper_cost(const emlrtStack *sp, const real_T u[20],
                    const real_T params[14])
{
  __m128d r;
  emlrtStack st;
  real_T X_hist[33];
  real_T b_y[9];
  real_T e_a[9];
  real_T y[9];
  real_T L_safe;
  real_T W_safe;
  real_T a_tmp;
  real_T cost;
  real_T d;
  real_T d1;
  real_T d2;
  real_T d3;
  real_T d4;
  real_T d5;
  real_T d6;
  real_T d7;
  real_T l_u;
  real_T tmp2;
  real_T x_k_idx_0;
  real_T x_k_idx_1;
  real_T x_next_idx_2;
  real_T x_pos_k;
  real_T y_pos_k;
  int32_T n;
  st.prev = sp;
  st.tls = sp->tls;
  /*  1. Calcula o custo original (distância, obstáculo, etc) */
  st.site = &emlrtRSI;
  /*  =========================================================================
   */
  /*  Algoritmo: Backward AD - Geofence (Cruz) + Obstáculo (Círculo) via CBF */
  /*  =========================================================================
   */
  /*  Horizonte longo para enxergar o corredor */
  /*  Tempo de predição */
  /*  Peso para suavizar a velocidade linear */
  /*  Peso ALTO para evitar zigue-zague */
  /*  Centro (Cruz e Círculo) */
  cost = params[9];
  /*  Peso da Barreira CBF */
  /*  Decaimento da CBF */
  /*  Limites Seguros */
  L_safe = params[7] - 0.15;
  /*  Geofence (Encolhe) */
  W_safe = params[8] - 0.15;
  /*  Geofence (Encolhe) */
  /*  Obstáculo (Incha) */
  x_k_idx_0 = params[0];
  x_k_idx_1 = params[1];
  x_next_idx_2 = params[2];
  l_u = 0.0;
  /*  ===================================================================== */
  /*  FORWARD PASS */
  /*  ===================================================================== */
  d = params[5];
  d1 = params[6];
  d2 = params[12];
  d3 = params[13];
  d4 = params[3];
  d5 = params[4];
  d6 = params[10];
  d7 = params[11];
  a_tmp = (cost + 0.15) * (cost + 0.15);
  for (n = 0; n < 10; n++) {
    real_T a;
    real_T b_a;
    real_T c_a;
    real_T d8;
    real_T d9;
    real_T d_a;
    real_T f_a;
    real_T g_a;
    real_T h_a;
    real_T i_a;
    real_T v_n;
    real_T w_n;
    int32_T v_n_tmp;
    v_n_tmp = n << 1;
    v_n = u[v_n_tmp];
    w_n = u[v_n_tmp + 1];
    x_pos_k = x_k_idx_0 - d;
    y_pos_k = x_k_idx_1 - d1;
    /*  --- Estado Atual (k) --- */
    /*  Cruz */
    cost = muDoubleScalarAbs(x_pos_k);
    a = muDoubleScalarMax(0.0, cost - L_safe);
    tmp2 = muDoubleScalarAbs(y_pos_k);
    b_a = muDoubleScalarMax(0.0, tmp2 - W_safe);
    c_a = muDoubleScalarMax(0.0, cost - W_safe);
    d_a = muDoubleScalarMax(0.0, tmp2 - L_safe);
    /*  Círculo */
    f_a =
        muDoubleScalarMax(0.0, a_tmp - (x_pos_k * x_pos_k + y_pos_k * y_pos_k));
    /*  Dinâmica */
    cost = 0.1 * v_n;
    d8 = x_k_idx_0 + cost * muDoubleScalarCos(x_next_idx_2);
    d9 = x_k_idx_1 + cost * muDoubleScalarSin(x_next_idx_2);
    x_next_idx_2 += 0.1 * w_n;
    x_pos_k = d8 - d;
    y_pos_k = d9 - d1;
    /*  --- Estado Futuro (next) --- */
    /*  Cruz */
    cost = muDoubleScalarAbs(x_pos_k);
    g_a = muDoubleScalarMax(0.0, cost - L_safe);
    tmp2 = muDoubleScalarAbs(y_pos_k);
    h_a = muDoubleScalarMax(0.0, tmp2 - W_safe);
    i_a = muDoubleScalarMax(0.0, cost - W_safe);
    tmp2 = muDoubleScalarMax(0.0, tmp2 - L_safe);
    /*  Círculo */
    cost =
        muDoubleScalarMax(0.0, a_tmp - (x_pos_k * x_pos_k + y_pos_k * y_pos_k));
    /*  --- Restrições CBF Separadas --- */
    x_pos_k = muDoubleScalarMax(
        0.0, (1.0 - d2) * -((a * a + b_a * b_a) * (c_a * c_a + d_a * d_a)) -
                 (-((g_a * g_a + h_a * h_a) * (i_a * i_a + tmp2 * tmp2))));
    y_pos_k =
        muDoubleScalarMax(0.0, (1.0 - d3) * -(f_a * f_a) - (-(cost * cost)));
    tmp2 = x_k_idx_0 - d4;
    cost = x_k_idx_1 - d5;
    l_u = ((l_u + ((0.8 * (tmp2 * tmp2 + cost * cost) + 0.1 * (v_n * v_n)) +
                   0.01 * (w_n * w_n))) +
           d6 * (x_pos_k * x_pos_k)) +
          d7 * (y_pos_k * y_pos_k);
    x_k_idx_0 = d8;
    v_n_tmp = 3 * (n + 1);
    X_hist[v_n_tmp] = d8;
    x_k_idx_1 = d9;
    X_hist[v_n_tmp + 1] = d9;
    X_hist[v_n_tmp + 2] = x_next_idx_2;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }
  /*  ===================================================================== */
  /*  TERMINAL E BACKWARD PASS */
  /*  ===================================================================== */
  y_pos_k = X_hist[30] - params[3];
  x_pos_k = X_hist[31] - params[4];
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
    e_a[n] = cost - tmp2;
  }
  r = _mm_loadu_pd(&e_a[0]);
  _mm_storeu_pd(&y[0], _mm_mul_pd(r, r));
  r = _mm_loadu_pd(&e_a[2]);
  _mm_storeu_pd(&y[2], _mm_mul_pd(r, r));
  r = _mm_loadu_pd(&e_a[4]);
  _mm_storeu_pd(&y[4], _mm_mul_pd(r, r));
  r = _mm_loadu_pd(&e_a[6]);
  _mm_storeu_pd(&y[6], _mm_mul_pd(r, r));
  y[8] = e_a[8] * e_a[8];
  cost = u[1];
  for (n = 0; n < 9; n++) {
    tmp2 = cost;
    cost = u[((n + 1) << 1) + 1];
    e_a[n] = cost - tmp2;
  }
  r = _mm_loadu_pd(&e_a[0]);
  _mm_storeu_pd(&b_y[0], _mm_mul_pd(r, r));
  r = _mm_loadu_pd(&e_a[2]);
  _mm_storeu_pd(&b_y[2], _mm_mul_pd(r, r));
  r = _mm_loadu_pd(&e_a[4]);
  _mm_storeu_pd(&b_y[4], _mm_mul_pd(r, r));
  r = _mm_loadu_pd(&e_a[6]);
  _mm_storeu_pd(&b_y[6], _mm_mul_pd(r, r));
  b_y[8] = e_a[8] * e_a[8];
  /*  5. Custo total */
  return (l_u + 0.8 * (y_pos_k * y_pos_k + x_pos_k * x_pos_k)) +
         (0.9 * sumColumnB(y) + 0.9 * sumColumnB(b_y));
}

/* End of code generation (wrapper_cost.c) */
