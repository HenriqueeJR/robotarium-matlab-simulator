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
    2,              /* lineNo */
    "wrapper_grad", /* fcnName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws\\robotarium-matlab-"
    "simulator\\examples\\cbf_caixa\\wrapper_grad.m" /* pathName */
};

static emlrtECInfo emlrtECI = {
    -1,                    /* nDims */
    152,                   /* lineNo */
    9,                     /* colNo */
    "build_robot_cbf_box", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws\\robotarium-matlab-"
    "simulator\\examples\\cbf_caixa\\build_robot_cbf_box.m" /* pName */
};

/* Function Definitions */
void wrapper_grad(const emlrtStack *sp, const real_T u[100],
                  const real_T params[10], real_T grad[100])
{
  emlrtStack st;
  real_T X_hist[153];
  real_T dv[9];
  real_T dv1[6];
  real_T grad_P_next[3];
  real_T x_k[3];
  real_T x_next[3];
  real_T dv2[2];
  real_T dv3[2];
  real_T L_obs;
  real_T W_obs;
  real_T d;
  real_T d1;
  real_T sy;
  real_T x_pos_k;
  real_T y_pos_k;
  int32_T n;
  int32_T v_n_tmp;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &emlrtRSI;
  /*  =========================================================================
   */
  /*  Algoritmo: Backward AD - Desvio de Obstáculo Retangular (Caixa) via CBF */
  /*  Regra do Produto: P = max(0, dx)^2 * max(0, dy)^2 */
  /*  =========================================================================
   */
  /*  Aumentado para prever mais longe e suavizar a curva */
  /*  R_ctrl aumentado para evitar curvas bruscas */
  x_k[0] = params[0];
  x_k[1] = params[1];
  x_k[2] = params[2];
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
  memset(&X_hist[0], 0, 153U * sizeof(real_T));
  X_hist[0] = params[0];
  X_hist[1] = params[1];
  X_hist[2] = params[2];
  /*  ===================================================================== */
  /*  FORWARD PASS */
  /*  ===================================================================== */
  for (n = 0; n < 50; n++) {
    v_n_tmp = n << 1;
    /*  1. Violação no estado atual (Regra do Produto da Caixa) */
    /*  Simula 1 passo da cinemática */
    x_pos_k = 0.033 * u[v_n_tmp];
    y_pos_k = x_k[0] + x_pos_k * muDoubleScalarCos(x_k[2]);
    x_pos_k = x_k[1] + x_pos_k * muDoubleScalarSin(x_k[2]);
    sy = x_k[2] + 0.033 * u[v_n_tmp + 1];
    /*  2. Violação no estado futuro */
    /*  3. Restrição de Barreira Discreta */
    /*  4. Penalidade */
    x_k[0] = y_pos_k;
    v_n_tmp = 3 * (n + 1);
    X_hist[v_n_tmp] = y_pos_k;
    x_k[1] = x_pos_k;
    X_hist[v_n_tmp + 1] = x_pos_k;
    x_k[2] = sy;
    X_hist[v_n_tmp + 2] = sy;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }
  /*  ===================================================================== */
  /*  TERMINAL E INICIALIZAÇÃO DO BACKWARD */
  /*  ===================================================================== */
  x_k[0] = 40.0 * (X_hist[150] - params[3]);
  x_k[1] = 40.0 * (X_hist[151] - params[4]);
  x_k[2] = 0.0;
  /*  ===================================================================== */
  /*  BACKWARD PASS (Método Adjunto) */
  /*  ===================================================================== */
  memset(&grad[0], 0, 100U * sizeof(real_T));
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
  dv1[5] = 0.033;
  for (n = 0; n < 50; n++) {
    __m128d r;
    __m128d r1;
    __m128d r2;
    __m128d r3;
    __m128d r4;
    real_T b_g_cbf_tmp;
    real_T c_g_cbf_tmp;
    real_T d2;
    real_T d3;
    real_T d_g_cbf_tmp;
    real_T dx_k;
    real_T dx_next;
    real_T dy_k;
    real_T dy_next;
    real_T g_cbf;
    real_T g_cbf_tmp;
    real_T v_n;
    real_T x_pos_next;
    real_T y_pos_next;
    int32_T b_v_n_tmp;
    int32_T x_pos_next_tmp;
    b_v_n_tmp = (49 - n) << 1;
    v_n = u[b_v_n_tmp];
    v_n_tmp = 3 * (49 - n);
    d2 = X_hist[v_n_tmp];
    x_pos_k = d2 - d;
    d3 = X_hist[v_n_tmp + 1];
    y_pos_k = d3 - d1;
    x_pos_next_tmp = 3 * (50 - n);
    x_pos_next = X_hist[x_pos_next_tmp] - d;
    y_pos_next = X_hist[x_pos_next_tmp + 1] - d1;
    dx_k = muDoubleScalarMax(0.0, (L_obs + 0.1) - muDoubleScalarAbs(x_pos_k));
    dy_k = muDoubleScalarMax(0.0, (W_obs + 0.1) - muDoubleScalarAbs(y_pos_k));
    dx_next =
        muDoubleScalarMax(0.0, (L_obs + 0.1) - muDoubleScalarAbs(x_pos_next));
    dy_next =
        muDoubleScalarMax(0.0, (W_obs + 0.1) - muDoubleScalarAbs(y_pos_next));
    g_cbf_tmp = dy_k * dy_k;
    b_g_cbf_tmp = dx_k * dx_k;
    c_g_cbf_tmp = dy_next * dy_next;
    d_g_cbf_tmp = dx_next * dx_next;
    g_cbf = 0.15000000000000002 * (0.0 - b_g_cbf_tmp * g_cbf_tmp) -
            (0.0 - d_g_cbf_tmp * c_g_cbf_tmp);
    x_next[0] = 0.0;
    grad_P_next[0] = 0.0;
    x_next[1] = 0.0;
    grad_P_next[1] = 0.0;
    x_next[2] = 0.0;
    grad_P_next[2] = 0.0;
    if (g_cbf > 0.0) {
      x_next[0] = 0.0;
      grad_P_next[0] = 0.0;
      x_next[1] = 0.0;
      grad_P_next[1] = 0.0;
      x_next[2] = 0.0;
      grad_P_next[2] = 0.0;
      /*  Gradiente de P_k = (dx^2)*(dy^2) */
      if ((dx_k > 0.0) && (dy_k > 0.0)) {
        x_pos_k = muDoubleScalarSign(x_pos_k);
        if (x_pos_k == 0.0) {
          x_pos_k = 1.0;
        }
        sy = muDoubleScalarSign(y_pos_k);
        if (sy == 0.0) {
          sy = 1.0;
        }
        x_next[0] = 2.0 * dx_k * -x_pos_k * g_cbf_tmp;
        x_next[1] = 2.0 * dy_k * -sy * b_g_cbf_tmp;
      }
      /*  Gradiente de P_next */
      if ((dx_next > 0.0) && (dy_next > 0.0)) {
        x_pos_k = muDoubleScalarSign(x_pos_next);
        if (x_pos_k == 0.0) {
          x_pos_k = 1.0;
        }
        sy = muDoubleScalarSign(y_pos_next);
        if (sy == 0.0) {
          sy = 1.0;
        }
        grad_P_next[0] = 2.0 * dx_next * -x_pos_k * c_g_cbf_tmp;
        grad_P_next[1] = 2.0 * dy_next * -sy * d_g_cbf_tmp;
      }
      /*  h = eta - P => grad_h = -grad_P */
      x_pos_k = 2.0 * params[9] * g_cbf;
      r = _mm_loadu_pd(&x_next[0]);
      r1 = _mm_set1_pd(x_pos_k);
      _mm_storeu_pd(
          &x_next[0],
          _mm_mul_pd(r1, _mm_mul_pd(_mm_set1_pd(0.15000000000000002),
                                    _mm_mul_pd(r, _mm_set1_pd(-1.0)))));
      r = _mm_loadu_pd(&grad_P_next[0]);
      _mm_storeu_pd(&grad_P_next[0], _mm_mul_pd(r1, r));
      x_next[2] = x_pos_k * (0.15000000000000002 * -x_next[2]);
      grad_P_next[2] *= x_pos_k;
    }
    sy = X_hist[v_n_tmp + 2];
    y_pos_k = muDoubleScalarCos(sy);
    sy = muDoubleScalarSin(sy);
    grad_P_next[0] += x_k[0];
    grad_P_next[1] += x_k[1];
    grad_P_next[2] += x_k[2];
    dv[2] = -0.033 * v_n * sy;
    dv[5] = 0.033 * v_n * y_pos_k;
    memset(&x_k[0], 0, 3U * sizeof(real_T));
    r = _mm_loadu_pd(&dv[0]);
    r1 = _mm_loadu_pd(&x_k[0]);
    r2 = _mm_set1_pd(grad_P_next[0]);
    _mm_storeu_pd(&x_k[0], _mm_add_pd(r1, _mm_mul_pd(r, r2)));
    x_k[2] += grad_P_next[0] * dv[2];
    r = _mm_loadu_pd(&dv[3]);
    r1 = _mm_loadu_pd(&x_k[0]);
    r3 = _mm_set1_pd(grad_P_next[1]);
    _mm_storeu_pd(&x_k[0], _mm_add_pd(r1, _mm_mul_pd(r, r3)));
    x_k[2] += grad_P_next[1] * dv[5];
    r = _mm_loadu_pd(&dv[6]);
    r1 = _mm_loadu_pd(&x_k[0]);
    r4 = _mm_set1_pd(grad_P_next[2]);
    _mm_storeu_pd(&x_k[0], _mm_add_pd(r1, _mm_mul_pd(r, r4)));
    x_k[2] += grad_P_next[2];
    x_next[0] += 40.0 * (d2 - params[3]);
    x_next[1] += 40.0 * (d3 - params[4]);
    r = _mm_loadu_pd(&x_k[0]);
    r1 = _mm_loadu_pd(&x_next[0]);
    _mm_storeu_pd(&x_k[0], _mm_add_pd(r, r1));
    x_k[2] += x_next[2];
    v_n_tmp = (50 - n) << 1;
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
    dv1[0] = 0.033 * y_pos_k;
    dv1[2] = 0.033 * sy;
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
    dv3[1] = 0.2 * u[b_v_n_tmp + 1];
    r = _mm_loadu_pd(&dv2[0]);
    r1 = _mm_loadu_pd(&dv3[0]);
    _mm_storeu_pd(&grad[x_pos_next_tmp], _mm_add_pd(r, r1));
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }
}

/* End of code generation (wrapper_grad.c) */
