/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * wrapper_grad.c
 *
 * Code generation for function 'wrapper_grad'
 *
 */

/* Include files */
#include "wrapper_grad.h"
#include "rt_nonfinite.h"
#include "wrapper_grad_data.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = {
    3,              /* lineNo */
    "wrapper_grad", /* fcnName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws\\robotarium-matlab-"
    "simulator\\examples\\cbf_caixa\\wrapper_grad.m" /* pathName */
};

static emlrtECInfo emlrtECI = {
    -1,                               /* nDims */
    176,                              /* lineNo */
    9,                                /* colNo */
    "build_robot_cbf_cross_geofence", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws\\robotarium-matlab-"
    "simulator\\examples\\cbf_caixa\\build_robot_cbf_cross_geofence.m" /* pName
                                                                        */
};

/* Function Definitions */
void wrapper_grad(const emlrtStack *sp, const real_T u[20],
                  const real_T params[10], real_T grad[20])
{
  __m128d r;
  __m128d r1;
  emlrtStack st;
  real_T X_hist[33];
  real_T grad_smooth[20];
  real_T dv[9];
  real_T dv1[6];
  real_T grad_P1_next[3];
  real_T grad_P2_k[3];
  real_T grad_P2_next[3];
  real_T x_k[3];
  real_T x_next[3];
  real_T dv2[2];
  real_T dv3[2];
  real_T L_safe;
  real_T W_safe;
  real_T d;
  real_T d1;
  real_T dx2_next;
  real_T dy2_next;
  real_T g_cbf;
  int32_T n;
  int32_T v_n_tmp;
  st.prev = sp;
  st.tls = sp->tls;
  /*  1. Gradiente do modelo analítico original */
  st.site = &emlrtRSI;
  /*  =========================================================================
   */
  /*  Algoritmo: Backward AD - Geofence Cruz (2 Caixas) via CBF */
  /*  Regra da União: P_cruz = P_box1 * P_box2 */
  /*  =========================================================================
   */
  /*  Tempo de amostragem de 0.1s para prever as curvas */
  /*  Penalidade suave para andar */
  /*  Penalidade ALTA para girar (evita o zigue-zague) */
  x_k[0] = params[0];
  x_k[1] = params[1];
  x_k[2] = params[2];
  /*  Centro da Cruz */
  /*  Comprimento do braço maior */
  /*  Comprimento do braço menor (largura) */
  /*  Encolhe a cruz geométrica para o centro do robô não encostar nas paredes
   */
  L_safe = params[7] - 0.15;
  W_safe = params[8] - 0.15;
  memset(&X_hist[0], 0, 33U * sizeof(real_T));
  X_hist[0] = params[0];
  X_hist[1] = params[1];
  X_hist[2] = params[2];
  /*  ===================================================================== */
  /*  FORWARD PASS */
  /*  ===================================================================== */
  for (n = 0; n < 10; n++) {
    v_n_tmp = n << 1;
    /*  --- CAIXA 1 (Horizontal) --- */
    /*  --- CAIXA 2 (Vertical) --- */
    /*  Regra da União: Seguro se (P1=0) OU (P2=0) */
    /*  Dinâmica */
    dy2_next = 0.1 * u[v_n_tmp];
    g_cbf = x_k[0] + dy2_next * muDoubleScalarCos(x_k[2]);
    dy2_next = x_k[1] + dy2_next * muDoubleScalarSin(x_k[2]);
    dx2_next = x_k[2] + 0.1 * u[v_n_tmp + 1];
    /*  Violação Futura */
    /*  Restrição e Penalidade */
    /*  Custo com pesos separados para R_v e R_w */
    x_k[0] = g_cbf;
    v_n_tmp = 3 * (n + 1);
    X_hist[v_n_tmp] = g_cbf;
    x_k[1] = dy2_next;
    X_hist[v_n_tmp + 1] = dy2_next;
    x_k[2] = dx2_next;
    X_hist[v_n_tmp + 2] = dx2_next;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }
  /*  ===================================================================== */
  /*  TERMINAL E BACKWARD PASS */
  /*  ===================================================================== */
  x_k[0] = 1.6 * (X_hist[30] - params[3]);
  x_k[1] = 1.6 * (X_hist[31] - params[4]);
  x_k[2] = 0.0;
  memset(&grad[0], 0, 20U * sizeof(real_T));
  d = params[5];
  d1 = params[6];
  dv[0] = 1.0;
  dv[1] = 0.0;
  dv[3] = 0.0;
  dv[4] = 1.0;
  dv[6] = 0.0;
  dv[7] = 0.0;
  dv[8] = 1.0;
  dv1[4] = 0.0;
  dv1[1] = 0.0;
  dv1[3] = 0.0;
  dv1[5] = 0.1;
  for (n = 0; n < 10; n++) {
    __m128d r2;
    __m128d r3;
    __m128d r4;
    real_T P1_k;
    real_T P1_next;
    real_T P2_k;
    real_T P2_next;
    real_T d2;
    real_T d3;
    real_T dx1_k;
    real_T dx1_next;
    real_T dx2_k;
    real_T dy1_k;
    real_T dy1_next;
    real_T dy2_k;
    real_T v_n;
    real_T x_pos_k;
    real_T x_pos_next;
    real_T y_pos_k;
    real_T y_pos_next;
    int32_T b_v_n_tmp;
    int32_T x_pos_next_tmp;
    b_v_n_tmp = (9 - n) << 1;
    v_n = u[b_v_n_tmp];
    v_n_tmp = 3 * (9 - n);
    d2 = X_hist[v_n_tmp];
    x_pos_k = d2 - d;
    d3 = X_hist[v_n_tmp + 1];
    y_pos_k = d3 - d1;
    x_pos_next_tmp = 3 * (10 - n);
    x_pos_next = X_hist[x_pos_next_tmp] - d;
    y_pos_next = X_hist[x_pos_next_tmp + 1] - d1;
    /*  Recalcula P_k */
    g_cbf = muDoubleScalarAbs(x_pos_k);
    dx1_k = muDoubleScalarMax(0.0, g_cbf - L_safe);
    dx2_next = muDoubleScalarAbs(y_pos_k);
    dy1_k = muDoubleScalarMax(0.0, dx2_next - W_safe);
    P1_k = dx1_k * dx1_k + dy1_k * dy1_k;
    dx2_k = muDoubleScalarMax(0.0, g_cbf - W_safe);
    dy2_k = muDoubleScalarMax(0.0, dx2_next - L_safe);
    P2_k = dx2_k * dx2_k + dy2_k * dy2_k;
    /*  Recalcula P_next */
    dy2_next = muDoubleScalarAbs(x_pos_next);
    dx1_next = muDoubleScalarMax(0.0, dy2_next - L_safe);
    g_cbf = muDoubleScalarAbs(y_pos_next);
    dy1_next = muDoubleScalarMax(0.0, g_cbf - W_safe);
    P1_next = dx1_next * dx1_next + dy1_next * dy1_next;
    dx2_next = muDoubleScalarMax(0.0, dy2_next - W_safe);
    dy2_next = muDoubleScalarMax(0.0, g_cbf - L_safe);
    P2_next = dx2_next * dx2_next + dy2_next * dy2_next;
    g_cbf =
        0.19999999999999996 * (0.0 - P1_k * P2_k) - (0.0 - P1_next * P2_next);
    x_next[0] = 0.0;
    grad_P1_next[0] = 0.0;
    x_next[1] = 0.0;
    grad_P1_next[1] = 0.0;
    x_next[2] = 0.0;
    grad_P1_next[2] = 0.0;
    if (g_cbf > 0.0) {
      /*  --- Gradientes das Caixas --- */
      x_next[0] = 0.0;
      grad_P2_k[0] = 0.0;
      grad_P1_next[0] = 0.0;
      grad_P2_next[0] = 0.0;
      x_next[1] = 0.0;
      grad_P2_k[1] = 0.0;
      grad_P1_next[1] = 0.0;
      grad_P2_next[1] = 0.0;
      x_next[2] = 0.0;
      grad_P2_k[2] = 0.0;
      grad_P1_next[2] = 0.0;
      grad_P2_next[2] = 0.0;
      /*  Gradiente Caixa 1 */
      if (dx1_k > 0.0) {
        x_next[0] = 2.0 * dx1_k * muDoubleScalarSign(x_pos_k);
      }
      if (dy1_k > 0.0) {
        x_next[1] = 2.0 * dy1_k * muDoubleScalarSign(y_pos_k);
      }
      if (dx1_next > 0.0) {
        grad_P1_next[0] = 2.0 * dx1_next * muDoubleScalarSign(x_pos_next);
      }
      if (dy1_next > 0.0) {
        grad_P1_next[1] = 2.0 * dy1_next * muDoubleScalarSign(y_pos_next);
      }
      /*  Gradiente Caixa 2 */
      if (dx2_k > 0.0) {
        grad_P2_k[0] = 2.0 * dx2_k * muDoubleScalarSign(x_pos_k);
      }
      if (dy2_k > 0.0) {
        grad_P2_k[1] = 2.0 * dy2_k * muDoubleScalarSign(y_pos_k);
      }
      if (dx2_next > 0.0) {
        grad_P2_next[0] = 2.0 * dx2_next * muDoubleScalarSign(x_pos_next);
      }
      if (dy2_next > 0.0) {
        grad_P2_next[1] = 2.0 * dy2_next * muDoubleScalarSign(y_pos_next);
      }
      /*  Aplicação da Regra do Produto: grad(P1*P2) = P2*grad(P1) + P1*grad(P2)
       */
      dy2_next = 2.0 * params[9] * g_cbf;
      r = _mm_loadu_pd(&x_next[0]);
      r1 = _mm_loadu_pd(&grad_P2_k[0]);
      r2 = _mm_set1_pd(dy2_next);
      _mm_storeu_pd(
          &x_next[0],
          _mm_mul_pd(
              r2, _mm_mul_pd(
                      _mm_set1_pd(0.19999999999999996),
                      _mm_mul_pd(_mm_add_pd(_mm_mul_pd(_mm_set1_pd(P2_k), r),
                                            _mm_mul_pd(_mm_set1_pd(P1_k), r1)),
                                 _mm_set1_pd(-1.0)))));
      r = _mm_loadu_pd(&grad_P1_next[0]);
      r1 = _mm_loadu_pd(&grad_P2_next[0]);
      _mm_storeu_pd(
          &grad_P1_next[0],
          _mm_mul_pd(r2, _mm_add_pd(_mm_mul_pd(_mm_set1_pd(P2_next), r),
                                    _mm_mul_pd(_mm_set1_pd(P1_next), r1))));
      x_next[2] =
          dy2_next * (0.19999999999999996 * -(P2_k * x_next[2] + P1_k * 0.0));
      grad_P1_next[2] = dy2_next * (P2_next * grad_P1_next[2] + P1_next * 0.0);
    }
    dy2_next = X_hist[v_n_tmp + 2];
    dx2_next = muDoubleScalarCos(dy2_next);
    dy2_next = muDoubleScalarSin(dy2_next);
    grad_P1_next[0] += x_k[0];
    grad_P1_next[1] += x_k[1];
    grad_P1_next[2] += x_k[2];
    dv[2] = -0.1 * v_n * dy2_next;
    dv[5] = 0.1 * v_n * dx2_next;
    memset(&x_k[0], 0, 3U * sizeof(real_T));
    r = _mm_loadu_pd(&dv[0]);
    r1 = _mm_loadu_pd(&x_k[0]);
    r2 = _mm_set1_pd(grad_P1_next[0]);
    _mm_storeu_pd(&x_k[0], _mm_add_pd(r1, _mm_mul_pd(r, r2)));
    x_k[2] += grad_P1_next[0] * dv[2];
    r = _mm_loadu_pd(&dv[3]);
    r1 = _mm_loadu_pd(&x_k[0]);
    r3 = _mm_set1_pd(grad_P1_next[1]);
    _mm_storeu_pd(&x_k[0], _mm_add_pd(r1, _mm_mul_pd(r, r3)));
    x_k[2] += grad_P1_next[1] * dv[5];
    r = _mm_loadu_pd(&dv[6]);
    r1 = _mm_loadu_pd(&x_k[0]);
    r4 = _mm_set1_pd(grad_P1_next[2]);
    _mm_storeu_pd(&x_k[0], _mm_add_pd(r1, _mm_mul_pd(r, r4)));
    x_k[2] += grad_P1_next[2];
    x_next[0] += 1.6 * (d2 - params[3]);
    x_next[1] += 1.6 * (d3 - params[4]);
    r = _mm_loadu_pd(&x_k[0]);
    r1 = _mm_loadu_pd(&x_next[0]);
    _mm_storeu_pd(&x_k[0], _mm_add_pd(r, r1));
    x_k[2] += x_next[2];
    v_n_tmp = (10 - n) << 1;
    if (b_v_n_tmp + 1 > v_n_tmp) {
      x_pos_next_tmp = 0;
      v_n_tmp = 0;
    } else {
      x_pos_next_tmp = b_v_n_tmp;
    }
    v_n_tmp -= x_pos_next_tmp;
    if (v_n_tmp != 2) {
      emlrtSubAssignSizeCheck1dR2017a(v_n_tmp, 2, &emlrtECI, &st);
    }
    dv1[0] = 0.1 * dx2_next;
    dv1[2] = 0.1 * dy2_next;
    memset(&dv2[0], 0, sizeof(real_T) << 1);
    r = _mm_loadu_pd(&dv1[0]);
    r1 = _mm_loadu_pd(&dv2[0]);
    _mm_storeu_pd(&dv2[0], _mm_add_pd(r1, _mm_mul_pd(r, r2)));
    r = _mm_loadu_pd(&dv1[2]);
    r1 = _mm_loadu_pd(&dv2[0]);
    _mm_storeu_pd(&dv2[0], _mm_add_pd(r1, _mm_mul_pd(r, r3)));
    r = _mm_loadu_pd(&dv1[4]);
    r1 = _mm_loadu_pd(&dv2[0]);
    _mm_storeu_pd(&dv2[0], _mm_add_pd(r1, _mm_mul_pd(r, r4)));
    dv3[0] = 0.2 * v_n;
    dv3[1] = 0.02 * u[b_v_n_tmp + 1];
    r = _mm_loadu_pd(&dv2[0]);
    r1 = _mm_loadu_pd(&dv3[0]);
    _mm_storeu_pd(&grad[x_pos_next_tmp], _mm_add_pd(r, r1));
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }
  /*  2. Pesos (Devem ser EXATAMENTE IGUAIS aos da função de custo!) */
  /*  3. Inicializa o vetor do gradiente de suavização */
  memset(&grad_smooth[0], 0, 20U * sizeof(real_T));
  /*  4. Calcula as derivadas parciais (Regra da Cadeia) */
  for (n = 0; n < 9; n++) {
    /*  Derivada em relação a v */
    v_n_tmp = (n + 1) << 1;
    /*  v_{i+1} - v_i */
    dy2_next = 1.8 * (u[v_n_tmp] - u[v_n_tmp - 2]);
    grad_smooth[v_n_tmp - 2] -= dy2_next;
    grad_smooth[v_n_tmp] += dy2_next;
    /*  Derivada em relação a w */
    /*  w_{i+1} - w_i */
    dy2_next = 1.8 * (u[v_n_tmp + 1] - u[v_n_tmp - 1]);
    grad_smooth[v_n_tmp - 1] -= dy2_next;
    grad_smooth[v_n_tmp + 1] += dy2_next;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
  /*  5. Gradiente total */
  for (n = 0; n <= 18; n += 2) {
    r = _mm_loadu_pd(&grad[n]);
    r1 = _mm_loadu_pd(&grad_smooth[n]);
    _mm_storeu_pd(&grad[n], _mm_add_pd(r, r1));
  }
}

/* End of code generation (wrapper_grad.c) */
