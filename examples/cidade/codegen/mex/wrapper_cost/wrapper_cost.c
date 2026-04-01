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
#include "diff.h"
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
    "simulator\\examples\\cidade\\wrapper_cost.m" /* pathName */
};

/* Function Definitions */
real_T wrapper_cost(const emlrtStack *sp, const real_T u[150],
                    const real_T params[8])
{
  __m128d r;
  emlrtStack st;
  real_T X_hist[228];
  real_T b_u[75];
  real_T b_y[74];
  real_T c_a[74];
  real_T y[74];
  real_T cost;
  real_T l_u;
  real_T x_k_idx_0;
  real_T x_k_idx_1;
  real_T x_k_idx_2;
  real_T y_pos;
  int32_T k;
  int32_T n;
  st.prev = sp;
  st.tls = sp->tls;
  /*  1. Calcula o custo original (distância, obstáculo, etc) */
  st.site = &emlrtRSI;
  /*  =========================================================================
   */
  /*  Algoritmo 1: Backward AD (Cruz 4 Retângulos + 2 Círculos - Regra do
   * Produto) */
  /*  =========================================================================
   */
  /*  Estado inicial x_0 */
  /*  Centro da topologia (ex: [0; 0]) */
  /*  Peso da penalidade global */
  /*  --- Dimensões da Geometria --- */
  /*  Comprimento dos braços a partir do centro */
  /*  Meia-largura dos braços */
  /*  Raio do círculo externo (Hub conector) */
  /*  Raio do círculo interno (Buraco a evitar) */
  /*  Raio do robô para inflar restrições (Margem de segurança) */
  x_k_idx_0 = params[0];
  x_k_idx_1 = params[1];
  x_k_idx_2 = params[2];
  l_u = 0.0;
  /*  ===================================================================== */
  /*  FORWARD PASS (Avaliação do Custo) */
  /*  ===================================================================== */
  for (n = 0; n < 75; n++) {
    real_T varargin_1[5];
    real_T a;
    real_T b_a;
    real_T d_a;
    real_T e_a;
    real_T f_a;
    real_T g_a;
    real_T h_a;
    real_T i_a;
    real_T j_a;
    real_T k_a;
    real_T v_13;
    real_T v_14;
    real_T v_21;
    real_T v_22;
    real_T v_n;
    real_T w_n;
    real_T x_pos_tmp;
    real_T y_pos_tmp;
    int32_T idx;
    idx = n << 1;
    v_n = u[idx];
    w_n = u[idx + 1];
    /*  x_pos = x_k(1) - x_obs(1);  */
    /*  y_pos = x_k(2) - x_obs(2); */
    x_pos_tmp = muDoubleScalarCos(x_k_idx_2);
    cost = (x_k_idx_0 + 0.035 * x_pos_tmp) - params[5];
    y_pos_tmp = muDoubleScalarSin(x_k_idx_2);
    y_pos = (x_k_idx_1 + 0.035 * y_pos_tmp) - params[6];
    /*  1. Retângulo 1 (Braço Direito) */
    /*  x_pos >= 0 vira x_pos >= r_rob  =>  max(0, r_rob - x_pos) */
    a = muDoubleScalarMax(0.0, 0.1 - cost);
    b_a = muDoubleScalarMax(0.0, cost - 1.4);
    v_13 = muDoubleScalarMax(0.0, -y_pos - 0.19999999999999998);
    v_14 = muDoubleScalarMax(0.0, y_pos - 0.19999999999999998);
    /*  2. Retângulo 2 (Braço Superior) */
    v_21 = muDoubleScalarMax(0.0, -cost - 0.19999999999999998);
    v_22 = muDoubleScalarMax(0.0, cost - 0.19999999999999998);
    d_a = muDoubleScalarMax(0.0, 0.1 - y_pos);
    e_a = muDoubleScalarMax(0.0, y_pos - 1.4);
    /*  3. Retângulo 3 (Braço Esquerdo) */
    /*  x_pos <= 0 vira x_pos <= -r_rob =>  max(0, x_pos + r_rob) */
    f_a = muDoubleScalarMax(0.0, -cost - 1.4);
    g_a = muDoubleScalarMax(0.0, cost + 0.1);
    /*  4. Retângulo 4 (Braço Inferior) */
    h_a = muDoubleScalarMax(0.0, -y_pos - 1.4);
    i_a = muDoubleScalarMax(0.0, y_pos + 0.1);
    /*  5. Círculo Externo (Conexão Segura no Centro) */
    /*  Encolhemos a zona segura subtraindo o raio do robô */
    cost = cost * cost + y_pos * y_pos;
    j_a = muDoubleScalarMax(0.0, cost - 0.16000000000000003);
    /*  6. Círculo Interno (Buraco / Obstáculo) */
    /*  Inflamos o obstáculo somando o raio do robô */
    k_a = muDoubleScalarMax(0.0, 0.090000000000000024 - cost);
    /*  A UNIÃO multiplicativa + SOMATÓRIO do obstáculo */
    y_pos = v_13 * v_13;
    v_13 = v_14 * v_14;
    varargin_1[0] = ((a * a + b_a * b_a) + y_pos) + v_13;
    cost = v_21 * v_21 + v_22 * v_22;
    varargin_1[1] = (cost + d_a * d_a) + e_a * e_a;
    varargin_1[2] = ((f_a * f_a + g_a * g_a) + y_pos) + v_13;
    varargin_1[3] = (cost + h_a * h_a) + i_a * i_a;
    varargin_1[4] = j_a * j_a;
    if (!muDoubleScalarIsNaN(varargin_1[0])) {
      idx = 1;
    } else {
      int32_T b_k;
      boolean_T exitg1;
      idx = 0;
      b_k = 2;
      exitg1 = false;
      while ((!exitg1) && (b_k < 6)) {
        if (!muDoubleScalarIsNaN(varargin_1[b_k - 1])) {
          idx = b_k;
          exitg1 = true;
        } else {
          b_k++;
        }
      }
    }
    if (idx == 0) {
      v_13 = varargin_1[0];
    } else {
      v_13 = varargin_1[idx - 1];
      idx++;
      for (k = idx; k < 6; k++) {
        cost = varargin_1[k - 1];
        if (v_13 > cost) {
          v_13 = cost;
        }
      }
    }
    cost = x_k_idx_0 - params[3];
    y_pos = x_k_idx_1 - params[4];
    l_u = (l_u + (10.0 * (cost * cost + y_pos * y_pos) +
                  0.001 * (v_n * v_n + w_n * w_n))) +
          params[7] * (v_13 + k_a * k_a);
    /*  Dinâmica Cinemática */
    cost = 0.033 * v_n;
    x_k_idx_0 += cost * x_pos_tmp;
    x_k_idx_1 += cost * y_pos_tmp;
    x_k_idx_2 += 0.033 * w_n;
    idx = 3 * (n + 1);
    X_hist[idx] = x_k_idx_0;
    X_hist[idx + 1] = x_k_idx_1;
    X_hist[idx + 2] = x_k_idx_2;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }
  /*  ===================================================================== */
  /*  TERMINAL E INICIALIZAÇÃO DO BACKWARD */
  /*  ===================================================================== */
  /*  x_pos_N = x_N(1) - x_obs(1);  */
  /*  y_pos_N = x_N(2) - x_obs(2); */
  /*  P1_N = max(0, -x_pos_N)^2 + max(0, x_pos_N-L_arm)^2 + max(0,
   * -y_pos_N-W_arm)^2 + max(0, y_pos_N-W_arm)^2; */
  /*  P2_N = max(0, -x_pos_N-W_arm)^2 + max(0, x_pos_N-W_arm)^2 + max(0,
   * -y_pos_N)^2 + max(0, y_pos_N-L_arm)^2; */
  /*  P3_N = max(0, -x_pos_N-L_arm)^2 + max(0, x_pos_N)^2 + max(0,
   * -y_pos_N-W_arm)^2 + max(0, y_pos_N-W_arm)^2; */
  /*  P4_N = max(0, -x_pos_N-W_arm)^2 + max(0, x_pos_N-W_arm)^2 + max(0,
   * -y_pos_N-L_arm)^2 + max(0, y_pos_N)^2; */
  /*  P5_N = max(0, x_pos_N^2 + y_pos_N^2 - R_out^2)^2; */
  /*  P6_N = max(0, R_in^2 - (x_pos_N^2 + y_pos_N^2))^2; */
  /*   */
  /*  geo_penalty_N = eta_geo * ((P1_N * P2_N * P3_N * P4_N * P5_N) + P6_N); */
  /*  geo_penalty_N = 0; */
  cost = X_hist[225] - params[3];
  y_pos = X_hist[226] - params[4];
  /*  cost = cost + l_N + geo_penalty_N; */
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
  for (k = 0; k < 75; k++) {
    b_u[k] = u[k << 1];
  }
  diff(b_u, c_a);
  for (k = 0; k <= 72; k += 2) {
    r = _mm_loadu_pd(&c_a[k]);
    _mm_storeu_pd(&y[k], _mm_mul_pd(r, r));
  }
  for (k = 0; k < 75; k++) {
    b_u[k] = u[(k << 1) + 1];
  }
  diff(b_u, c_a);
  for (k = 0; k <= 72; k += 2) {
    r = _mm_loadu_pd(&c_a[k]);
    _mm_storeu_pd(&b_y[k], _mm_mul_pd(r, r));
  }
  /*  5. Custo total */
  return (l_u + 10.0 * (cost * cost + y_pos * y_pos)) +
         (0.01 * sumColumnB(y) + 0.5 * sumColumnB(b_y));
}

/* End of code generation (wrapper_cost.c) */
