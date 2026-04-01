/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * build_robot_analytic.c
 *
 * Code generation for function 'build_robot_analytic'
 *
 */

/* Include files */
#include "build_robot_analytic.h"
#include "rt_nonfinite.h"
#include "wrapper_grad_data.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <string.h>

/* Variable Definitions */
static emlrtECInfo emlrtECI = {
    -1,                     /* nDims */
    219,                    /* lineNo */
    9,                      /* colNo */
    "build_robot_analytic", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws\\robotarium-matlab-"
    "simulator\\examples\\cidade\\build_robot_analytic.m" /* pName */
};

/* Function Definitions */
real_T build_robot_analytic(const emlrtStack *sp, const real_T u[150],
                            const real_T params[8], real_T grad[150])
{
  real_T X_hist[228];
  real_T dv[9];
  real_T dv1[6];
  real_T distancias[5];
  real_T dv2[3];
  real_T x_k[3];
  real_T dv3[2];
  real_T dv4[2];
  real_T P_cruz;
  real_T a_tmp;
  real_T cost;
  real_T eta_geo;
  real_T grad_P_cruz_idx_0;
  real_T grad_P_cruz_idx_1;
  real_T l_u;
  real_T v_11;
  real_T v_12;
  real_T v_13;
  real_T v_14;
  real_T v_21;
  real_T v_22;
  real_T v_23;
  real_T v_24;
  real_T v_31;
  real_T v_32;
  real_T v_43;
  real_T v_44;
  real_T v_5;
  real_T v_6;
  real_T v_n;
  real_T w_n;
  real_T x_pos;
  real_T y_pos;
  int32_T b_k;
  int32_T idx;
  int32_T k;
  int32_T n;
  boolean_T exitg1;
  /*  =========================================================================
   */
  /*  Algoritmo 1: Backward AD (Cruz 4 Retângulos + 2 Círculos - Regra do
   * Produto) */
  /*  =========================================================================
   */
  x_k[0] = params[0];
  x_k[1] = params[1];
  x_k[2] = params[2];
  /*  Estado inicial x_0 */
  /*  Centro da topologia (ex: [0; 0]) */
  eta_geo = params[7];
  /*  Peso da penalidade global */
  /*  --- Dimensões da Geometria --- */
  /*  Comprimento dos braços a partir do centro */
  /*  Meia-largura dos braços */
  /*  Raio do círculo externo (Hub conector) */
  /*  Raio do círculo interno (Buraco a evitar) */
  /*  Raio do robô para inflar restrições (Margem de segurança) */
  memset(&X_hist[0], 0, 228U * sizeof(real_T));
  X_hist[0] = params[0];
  X_hist[1] = params[1];
  X_hist[2] = params[2];
  l_u = 0.0;
  /*  ===================================================================== */
  /*  FORWARD PASS (Avaliação do Custo) */
  /*  ===================================================================== */
  for (n = 0; n < 75; n++) {
    idx = n << 1;
    v_n = u[idx];
    w_n = u[idx + 1];
    /*  x_pos = x_k(1) - x_obs(1);  */
    /*  y_pos = x_k(2) - x_obs(2); */
    v_5 = muDoubleScalarCos(x_k[2]);
    x_pos = (x_k[0] + 0.035 * v_5) - params[5];
    v_6 = muDoubleScalarSin(x_k[2]);
    y_pos = (x_k[1] + 0.035 * v_6) - params[6];
    /*  1. Retângulo 1 (Braço Direito) */
    /*  x_pos >= 0 vira x_pos >= r_rob  =>  max(0, r_rob - x_pos) */
    v_11 = muDoubleScalarMax(0.0, 0.1 - x_pos);
    grad_P_cruz_idx_0 = muDoubleScalarMax(0.0, x_pos - 1.4);
    v_13 = muDoubleScalarMax(0.0, -y_pos - 0.19999999999999998);
    v_14 = muDoubleScalarMax(0.0, y_pos - 0.19999999999999998);
    /*  2. Retângulo 2 (Braço Superior) */
    v_21 = muDoubleScalarMax(0.0, -x_pos - 0.19999999999999998);
    v_22 = muDoubleScalarMax(0.0, x_pos - 0.19999999999999998);
    v_12 = muDoubleScalarMax(0.0, 0.1 - y_pos);
    v_23 = muDoubleScalarMax(0.0, y_pos - 1.4);
    /*  3. Retângulo 3 (Braço Esquerdo) */
    /*  x_pos <= 0 vira x_pos <= -r_rob =>  max(0, x_pos + r_rob) */
    v_24 = muDoubleScalarMax(0.0, -x_pos - 1.4);
    v_31 = muDoubleScalarMax(0.0, x_pos + 0.1);
    /*  4. Retângulo 4 (Braço Inferior) */
    v_32 = muDoubleScalarMax(0.0, -y_pos - 1.4);
    v_43 = muDoubleScalarMax(0.0, y_pos + 0.1);
    /*  5. Círculo Externo (Conexão Segura no Centro) */
    /*  Encolhemos a zona segura subtraindo o raio do robô */
    a_tmp = x_pos * x_pos + y_pos * y_pos;
    grad_P_cruz_idx_1 = muDoubleScalarMax(0.0, a_tmp - 0.16000000000000003);
    /*  6. Círculo Interno (Buraco / Obstáculo) */
    /*  Inflamos o obstáculo somando o raio do robô */
    v_44 = muDoubleScalarMax(0.0, 0.090000000000000024 - a_tmp);
    /*  A UNIÃO multiplicativa + SOMATÓRIO do obstáculo */
    a_tmp = v_13 * v_13;
    P_cruz = v_14 * v_14;
    distancias[0] =
        ((v_11 * v_11 + grad_P_cruz_idx_0 * grad_P_cruz_idx_0) + a_tmp) +
        P_cruz;
    v_11 = v_21 * v_21 + v_22 * v_22;
    distancias[1] = (v_11 + v_12 * v_12) + v_23 * v_23;
    distancias[2] = ((v_24 * v_24 + v_31 * v_31) + a_tmp) + P_cruz;
    distancias[3] = (v_11 + v_32 * v_32) + v_43 * v_43;
    distancias[4] = grad_P_cruz_idx_1 * grad_P_cruz_idx_1;
    if (!muDoubleScalarIsNaN(distancias[0])) {
      idx = 1;
    } else {
      idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k < 6)) {
        if (!muDoubleScalarIsNaN(distancias[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (idx == 0) {
      P_cruz = distancias[0];
    } else {
      P_cruz = distancias[idx - 1];
      idx++;
      for (b_k = idx; b_k < 6; b_k++) {
        v_11 = distancias[b_k - 1];
        if (P_cruz > v_11) {
          P_cruz = v_11;
        }
      }
    }
    v_11 = x_k[0] - params[3];
    a_tmp = x_k[1] - params[4];
    l_u = (l_u + (10.0 * (v_11 * v_11 + a_tmp * a_tmp) +
                  0.001 * (v_n * v_n + w_n * w_n))) +
          eta_geo * (P_cruz + v_44 * v_44);
    /*  Dinâmica Cinemática */
    a_tmp = 0.033 * v_n;
    P_cruz = x_k[0] + a_tmp * v_5;
    x_k[0] = P_cruz;
    v_11 = x_k[1] + a_tmp * v_6;
    x_k[1] = v_11;
    a_tmp = x_k[2] + 0.033 * w_n;
    x_k[2] = a_tmp;
    idx = 3 * (n + 1);
    X_hist[idx] = P_cruz;
    X_hist[idx + 1] = v_11;
    X_hist[idx + 2] = a_tmp;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
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
  a_tmp = X_hist[225] - params[3];
  v_11 = X_hist[226] - params[4];
  /*  cost = cost + l_N + geo_penalty_N; */
  cost = l_u + 10.0 * (a_tmp * a_tmp + v_11 * v_11);
  x_k[0] = 20.0 * a_tmp;
  x_k[1] = 20.0 * v_11;
  x_k[2] = 0.0;
  /*  ===================================================================== */
  /*  BACKWARD PASS (Método Adjunto com Regra do Produto de 5 Termos) */
  /*  ===================================================================== */
  memset(&grad[0], 0, 150U * sizeof(real_T));
  dv[8] = 1.0;
  dv[0] = 1.0;
  dv[1] = 0.0;
  dv[3] = 0.0;
  dv[4] = 1.0;
  dv[6] = 0.0;
  dv[7] = 0.0;
  dv1[4] = 0.0;
  dv1[1] = 0.0;
  dv1[3] = 0.0;
  dv1[5] = 0.033;
  for (n = 0; n < 75; n++) {
    __m128d r;
    __m128d r1;
    __m128d r2;
    __m128d r3;
    __m128d r4;
    real_T b_x_pos_tmp;
    real_T x_pos_tmp;
    real_T y_pos_tmp;
    int32_T v_n_tmp;
    v_n_tmp = (74 - n) << 1;
    v_n = u[v_n_tmp];
    /*  x_pos = x_n(1) - x_obs(1);  */
    /*  y_pos = x_n(2) - x_obs(2); */
    idx = 3 * (74 - n);
    v_11 = X_hist[idx + 2];
    x_pos_tmp = muDoubleScalarCos(v_11);
    w_n = 0.035 * x_pos_tmp;
    b_x_pos_tmp = X_hist[idx];
    x_pos = (b_x_pos_tmp + w_n) - params[5];
    l_u = muDoubleScalarSin(v_11);
    y_pos_tmp = X_hist[idx + 1];
    y_pos = (y_pos_tmp + 0.035 * l_u) - params[6];
    /*  Recalcula as violações */
    v_11 = muDoubleScalarMax(0.0, 0.1 - x_pos);
    v_12 = muDoubleScalarMax(0.0, x_pos - 1.4);
    v_13 = muDoubleScalarMax(0.0, -y_pos - 0.19999999999999998);
    v_14 = muDoubleScalarMax(0.0, y_pos - 0.19999999999999998);
    v_21 = muDoubleScalarMax(0.0, -x_pos - 0.19999999999999998);
    v_22 = muDoubleScalarMax(0.0, x_pos - 0.19999999999999998);
    v_23 = muDoubleScalarMax(0.0, 0.1 - y_pos);
    v_24 = muDoubleScalarMax(0.0, y_pos - 1.4);
    v_31 = muDoubleScalarMax(0.0, -x_pos - 1.4);
    v_32 = muDoubleScalarMax(0.0, x_pos + 0.1);
    v_43 = muDoubleScalarMax(0.0, -y_pos - 1.4);
    v_44 = muDoubleScalarMax(0.0, y_pos + 0.1);
    P_cruz = x_pos * x_pos + y_pos * y_pos;
    v_5 = muDoubleScalarMax(0.0, P_cruz - 0.16000000000000003);
    v_6 = muDoubleScalarMax(0.0, 0.090000000000000024 - P_cruz);
    P_cruz = v_13 * v_13;
    a_tmp = v_14 * v_14;
    distancias[0] = ((v_11 * v_11 + v_12 * v_12) + P_cruz) + a_tmp;
    grad_P_cruz_idx_1 = v_21 * v_21 + v_22 * v_22;
    distancias[1] = (grad_P_cruz_idx_1 + v_23 * v_23) + v_24 * v_24;
    distancias[2] = ((v_31 * v_31 + v_32 * v_32) + P_cruz) + a_tmp;
    distancias[3] = (grad_P_cruz_idx_1 + v_43 * v_43) + v_44 * v_44;
    distancias[4] = v_5 * v_5;
    if (!muDoubleScalarIsNaN(distancias[0])) {
      k = 1;
    } else {
      k = 0;
      idx = 2;
      exitg1 = false;
      while ((!exitg1) && (idx < 6)) {
        if (!muDoubleScalarIsNaN(distancias[idx - 1])) {
          k = idx;
          exitg1 = true;
        } else {
          idx++;
        }
      }
    }
    if (k == 0) {
      a_tmp = distancias[0];
      k = 1;
    } else {
      a_tmp = distancias[k - 1];
      idx = k + 1;
      for (b_k = idx; b_k < 6; b_k++) {
        P_cruz = distancias[b_k - 1];
        if (a_tmp > P_cruz) {
          a_tmp = P_cruz;
          k = b_k;
        }
      }
    }
    grad_P_cruz_idx_0 = 0.0;
    grad_P_cruz_idx_1 = 0.0;
    /*  Só calcula gradiente se o robô estiver fora de TODOS os blocos da cruz
     */
    if (a_tmp > 0.0) {
      /*  Calcula apenas o gradiente do bloco mais próximo para puxar o robô de
       * volta */
      if (k == 1) {
        if (v_11 > 0.0) {
          grad_P_cruz_idx_0 = -(2.0 * v_11);
        }
        if (v_12 > 0.0) {
          grad_P_cruz_idx_0 += 2.0 * v_12;
        }
        if (v_13 > 0.0) {
          grad_P_cruz_idx_1 = -(2.0 * v_13);
        }
        if (v_14 > 0.0) {
          grad_P_cruz_idx_1 += 2.0 * v_14;
        }
      } else if (k == 2) {
        if (v_21 > 0.0) {
          grad_P_cruz_idx_0 = -(2.0 * v_21);
        }
        if (v_22 > 0.0) {
          grad_P_cruz_idx_0 += 2.0 * v_22;
        }
        if (v_23 > 0.0) {
          grad_P_cruz_idx_1 = -(2.0 * v_23);
        }
        if (v_24 > 0.0) {
          grad_P_cruz_idx_1 += 2.0 * v_24;
        }
      } else if (k == 3) {
        if (v_31 > 0.0) {
          grad_P_cruz_idx_0 = -(2.0 * v_31);
        }
        if (v_32 > 0.0) {
          grad_P_cruz_idx_0 += 2.0 * v_32;
        }
        if (v_13 > 0.0) {
          grad_P_cruz_idx_1 = -(2.0 * v_13);
        }
        if (v_14 > 0.0) {
          grad_P_cruz_idx_1 += 2.0 * v_14;
        }
      } else if (k == 4) {
        if (v_21 > 0.0) {
          grad_P_cruz_idx_0 = -(2.0 * v_21);
        }
        if (v_22 > 0.0) {
          grad_P_cruz_idx_0 += 2.0 * v_22;
        }
        if (v_43 > 0.0) {
          grad_P_cruz_idx_1 = -(2.0 * v_43);
        }
        if (v_44 > 0.0) {
          grad_P_cruz_idx_1 += 2.0 * v_44;
        }
      } else {
        v_11 = 4.0 * v_5;
        grad_P_cruz_idx_0 = v_11 * x_pos;
        grad_P_cruz_idx_1 = v_11 * y_pos;
      }
    }
    /*  --- B) O Obstáculo Interno (Evasão aditiva) --- */
    if (v_6 > 0.0) {
      /*  Derivada de (R^2 - x^2 - y^2)^2 em relação a x e y */
      v_11 = -4.0 * v_6;
      grad_P_cruz_idx_0 += v_11 * x_pos;
      grad_P_cruz_idx_1 += v_11 * y_pos;
    }
    /*  Escala pelo fator de penalidade global */
    P_cruz = grad_P_cruz_idx_0 * (-0.035 * l_u) + grad_P_cruz_idx_1 * w_n;
    /* grad_geo_n = 0; */
    dv[2] = -0.033 * v_n * l_u;
    dv[5] = 0.033 * v_n * x_pos_tmp;
    memset(&dv2[0], 0, 3U * sizeof(real_T));
    grad_P_cruz_idx_0 *= eta_geo;
    r = _mm_loadu_pd(&dv[0]);
    r1 = _mm_loadu_pd(&dv2[0]);
    r2 = _mm_set1_pd(x_k[0]);
    _mm_storeu_pd(&dv2[0], _mm_add_pd(r1, _mm_mul_pd(r, r2)));
    dv2[2] += x_k[0] * dv[2];
    grad_P_cruz_idx_1 *= eta_geo;
    r = _mm_loadu_pd(&dv[3]);
    r1 = _mm_loadu_pd(&dv2[0]);
    r3 = _mm_set1_pd(x_k[1]);
    _mm_storeu_pd(&dv2[0], _mm_add_pd(r1, _mm_mul_pd(r, r3)));
    dv2[2] += x_k[1] * dv[5];
    P_cruz *= eta_geo;
    r = _mm_loadu_pd(&dv[6]);
    r1 = _mm_loadu_pd(&dv2[0]);
    r4 = _mm_set1_pd(x_k[2]);
    _mm_storeu_pd(&dv2[0], _mm_add_pd(r1, _mm_mul_pd(r, r4)));
    dv2[2] += x_k[2];
    x_k[0] = 20.0 * (b_x_pos_tmp - params[3]) + grad_P_cruz_idx_0;
    x_k[1] = 20.0 * (y_pos_tmp - params[4]) + grad_P_cruz_idx_1;
    x_k[2] = P_cruz;
    r = _mm_loadu_pd(&dv2[0]);
    r1 = _mm_loadu_pd(&x_k[0]);
    _mm_storeu_pd(&x_k[0], _mm_add_pd(r, r1));
    x_k[2] += dv2[2];
    idx = (75 - n) << 1;
    if (v_n_tmp + 1 > idx) {
      k = 0;
      idx = 0;
    } else {
      k = v_n_tmp;
    }
    idx -= k;
    if (idx != 2) {
      emlrtSubAssignSizeCheck1dR2017a(idx, 2, &emlrtECI, (emlrtConstCTX)sp);
    }
    dv1[0] = 0.033 * x_pos_tmp;
    dv1[2] = 0.033 * l_u;
    memset(&dv3[0], 0, sizeof(real_T) << 1);
    r = _mm_loadu_pd(&dv1[0]);
    r1 = _mm_loadu_pd(&dv3[0]);
    _mm_storeu_pd(&dv3[0], _mm_add_pd(r1, _mm_mul_pd(r, r2)));
    r = _mm_loadu_pd(&dv1[2]);
    r1 = _mm_loadu_pd(&dv3[0]);
    _mm_storeu_pd(&dv3[0], _mm_add_pd(r1, _mm_mul_pd(r, r3)));
    r = _mm_loadu_pd(&dv1[4]);
    r1 = _mm_loadu_pd(&dv3[0]);
    _mm_storeu_pd(&dv3[0], _mm_add_pd(r1, _mm_mul_pd(r, r4)));
    dv4[0] = 0.002 * v_n;
    dv4[1] = 0.002 * u[v_n_tmp + 1];
    r = _mm_loadu_pd(&dv3[0]);
    r1 = _mm_loadu_pd(&dv4[0]);
    _mm_storeu_pd(&grad[k], _mm_add_pd(r, r1));
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
  return cost;
}

/* End of code generation (build_robot_analytic.c) */
