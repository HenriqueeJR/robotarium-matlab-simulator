/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * build_robot_cbf_experiment.c
 *
 * Code generation for function 'build_robot_cbf_experiment'
 *
 */

/* Include files */
#include "build_robot_cbf_experiment.h"
#include "rt_nonfinite.h"
#include "wrapper_grad_data.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <string.h>

/* Variable Definitions */
static emlrtECInfo emlrtECI = {
    -1,                           /* nDims */
    210,                          /* lineNo */
    9,                            /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws\\robotarium-matlab-"
    "simulator\\examples\\cbf_caixa\\build_robot_cbf_experiment.m" /* pName */
};

/* Function Definitions */
real_T build_robot_cbf_experiment(const emlrtStack *sp, const real_T u[20],
                                  const real_T params[14], real_T grad[20])
{
  real_T X_hist[33];
  real_T dv[9];
  real_T dv1[6];
  real_T gP1[3];
  real_T gP1_n[3];
  real_T p_n[3];
  real_T x_k[3];
  real_T x_next[3];
  real_T dv2[2];
  real_T dv3[2];
  real_T L_safe;
  real_T P1_k;
  real_T P1_next;
  real_T P2_k;
  real_T P2_next;
  real_T R_circ;
  real_T W_safe;
  real_T a;
  real_T b_a;
  real_T cost;
  real_T d;
  real_T d1;
  real_T dx1_k;
  real_T dx1_next;
  real_T dx2_k;
  real_T dx2_next;
  real_T dy1_k;
  real_T dy1_next;
  real_T dy2_k;
  real_T dy2_next;
  real_T eta_obs;
  real_T eta_safe;
  real_T g_circ;
  real_T g_cross;
  real_T gamma_obs;
  real_T gamma_safe;
  real_T l_u;
  real_T v_circ_k;
  real_T v_circ_next;
  real_T v_n;
  real_T w_n;
  real_T x_pos_k;
  real_T x_pos_next;
  real_T y_pos_k;
  real_T y_pos_next;
  int32_T n;
  int32_T v_n_tmp;
  /*  =========================================================================
   */
  /*  Algoritmo: Backward AD - Geofence (Cruz) + Obstáculo (Círculo) via CBF */
  /*  =========================================================================
   */
  /*  Horizonte longo para enxergar o corredor */
  /*  Tempo de predição */
  /*  Peso para suavizar a velocidade linear */
  /*  Peso ALTO para evitar zigue-zague */
  x_k[0] = params[0];
  x_k[1] = params[1];
  x_k[2] = params[2];
  /*  Centro (Cruz e Círculo) */
  R_circ = params[9];
  eta_safe = params[10];
  /*  Peso da Barreira CBF */
  eta_obs = params[11];
  gamma_safe = params[12];
  gamma_obs = params[13];
  /*  Decaimento da CBF */
  /*  Limites Seguros */
  L_safe = params[7] - 0.15;
  /*  Geofence (Encolhe) */
  W_safe = params[8] - 0.15;
  /*  Geofence (Encolhe) */
  /*  Obstáculo (Incha) */
  memset(&X_hist[0], 0, 33U * sizeof(real_T));
  X_hist[0] = params[0];
  X_hist[1] = params[1];
  X_hist[2] = params[2];
  l_u = 0.0;
  /*  ===================================================================== */
  /*  FORWARD PASS */
  /*  ===================================================================== */
  v_circ_k = params[5];
  g_circ = params[6];
  dx1_k = params[3];
  dy1_k = params[4];
  P1_k = (R_circ + 0.15) * (R_circ + 0.15);
  for (n = 0; n < 10; n++) {
    v_n_tmp = n << 1;
    v_n = u[v_n_tmp];
    w_n = u[v_n_tmp + 1];
    x_pos_k = x_k[0] - v_circ_k;
    y_pos_k = x_k[1] - g_circ;
    /*  --- Estado Atual (k) --- */
    /*  Cruz */
    dy2_next = muDoubleScalarAbs(x_pos_k);
    P1_next = muDoubleScalarMax(0.0, dy2_next - L_safe);
    P2_next = muDoubleScalarAbs(y_pos_k);
    v_circ_next = muDoubleScalarMax(0.0, P2_next - W_safe);
    P2_k = muDoubleScalarMax(0.0, dy2_next - W_safe);
    dy2_k = muDoubleScalarMax(0.0, P2_next - L_safe);
    /*  Círculo */
    dx2_next =
        muDoubleScalarMax(0.0, P1_k - (x_pos_k * x_pos_k + y_pos_k * y_pos_k));
    /*  Dinâmica */
    dy2_next = 0.1 * v_n;
    dx2_k = x_k[0] + dy2_next * muDoubleScalarCos(x_k[2]);
    dx1_next = x_k[1] + dy2_next * muDoubleScalarSin(x_k[2]);
    dy1_next = x_k[2] + 0.1 * w_n;
    x_pos_next = dx2_k - v_circ_k;
    y_pos_next = dx1_next - g_circ;
    /*  --- Estado Futuro (next) --- */
    /*  Cruz */
    dy2_next = muDoubleScalarAbs(x_pos_next);
    a = muDoubleScalarMax(0.0, dy2_next - L_safe);
    P2_next = muDoubleScalarAbs(y_pos_next);
    g_cross = muDoubleScalarMax(0.0, P2_next - W_safe);
    b_a = muDoubleScalarMax(0.0, dy2_next - W_safe);
    P2_next = muDoubleScalarMax(0.0, P2_next - L_safe);
    /*  Círculo */
    dy2_next = muDoubleScalarMax(
        0.0, P1_k - (x_pos_next * x_pos_next + y_pos_next * y_pos_next));
    /*  --- Restrições CBF Separadas --- */
    a = muDoubleScalarMax(
        0.0,
        (1.0 - gamma_safe) * -((P1_next * P1_next + v_circ_next * v_circ_next) *
                               (P2_k * P2_k + dy2_k * dy2_k)) -
            (-((a * a + g_cross * g_cross) * (b_a * b_a + P2_next * P2_next))));
    dy2_next =
        muDoubleScalarMax(0.0, (1.0 - gamma_obs) * -(dx2_next * dx2_next) -
                                   (-(dy2_next * dy2_next)));
    P2_next = x_k[0] - dx1_k;
    b_a = x_k[1] - dy1_k;
    l_u = ((l_u + ((0.8 * (P2_next * P2_next + b_a * b_a) + 0.1 * (v_n * v_n)) +
                   0.01 * (w_n * w_n))) +
           eta_safe * (a * a)) +
          eta_obs * (dy2_next * dy2_next);
    x_k[0] = dx2_k;
    v_n_tmp = 3 * (n + 1);
    X_hist[v_n_tmp] = dx2_k;
    x_k[1] = dx1_next;
    X_hist[v_n_tmp + 1] = dx1_next;
    x_k[2] = dy1_next;
    X_hist[v_n_tmp + 2] = dy1_next;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
  /*  ===================================================================== */
  /*  TERMINAL E BACKWARD PASS */
  /*  ===================================================================== */
  dy2_next = X_hist[30] - params[3];
  P2_next = X_hist[31] - params[4];
  cost = l_u + 0.8 * (dy2_next * dy2_next + P2_next * P2_next);
  p_n[0] = 1.6 * dy2_next;
  p_n[1] = 1.6 * P2_next;
  p_n[2] = 0.0;
  memset(&grad[0], 0, 20U * sizeof(real_T));
  d = params[5];
  d1 = params[6];
  w_n = (R_circ + 0.15) * (R_circ + 0.15);
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
    __m128d r;
    __m128d r1;
    __m128d r2;
    __m128d r3;
    __m128d r4;
    int32_T b_v_n_tmp;
    int32_T x_pos_next_tmp;
    b_v_n_tmp = (9 - n) << 1;
    v_n = u[b_v_n_tmp];
    v_n_tmp = 3 * (9 - n);
    l_u = X_hist[v_n_tmp];
    x_pos_k = l_u - d;
    R_circ = X_hist[v_n_tmp + 1];
    y_pos_k = R_circ - d1;
    x_pos_next_tmp = 3 * (10 - n);
    x_pos_next = X_hist[x_pos_next_tmp] - d;
    y_pos_next = X_hist[x_pos_next_tmp + 1] - d1;
    /*  Recalcula k */
    dy2_next = muDoubleScalarAbs(x_pos_k);
    dx1_k = muDoubleScalarMax(0.0, dy2_next - L_safe);
    P2_next = muDoubleScalarAbs(y_pos_k);
    dy1_k = muDoubleScalarMax(0.0, P2_next - W_safe);
    P1_k = dx1_k * dx1_k + dy1_k * dy1_k;
    dx2_k = muDoubleScalarMax(0.0, dy2_next - W_safe);
    dy2_k = muDoubleScalarMax(0.0, P2_next - L_safe);
    P2_k = dx2_k * dx2_k + dy2_k * dy2_k;
    v_circ_k =
        muDoubleScalarMax(0.0, w_n - (x_pos_k * x_pos_k + y_pos_k * y_pos_k));
    /*  Recalcula next */
    dy2_next = muDoubleScalarAbs(x_pos_next);
    dx1_next = muDoubleScalarMax(0.0, dy2_next - L_safe);
    P2_next = muDoubleScalarAbs(y_pos_next);
    dy1_next = muDoubleScalarMax(0.0, P2_next - W_safe);
    P1_next = dx1_next * dx1_next + dy1_next * dy1_next;
    dx2_next = muDoubleScalarMax(0.0, dy2_next - W_safe);
    dy2_next = muDoubleScalarMax(0.0, P2_next - L_safe);
    P2_next = dx2_next * dx2_next + dy2_next * dy2_next;
    v_circ_next = muDoubleScalarMax(
        0.0, w_n - (x_pos_next * x_pos_next + y_pos_next * y_pos_next));
    b_a = P1_k * P2_k;
    a = P1_next * P2_next;
    g_cross = (1.0 - gamma_safe) * -b_a - (-a);
    g_circ = (1.0 - gamma_obs) * -(v_circ_k * v_circ_k) -
             (-(v_circ_next * v_circ_next));
    gP1[0] = 0.0;
    gP1_n[0] = 0.0;
    gP1[1] = 0.0;
    gP1_n[1] = 0.0;
    gP1[2] = 0.0;
    gP1_n[2] = 0.0;
    /*  --- Gradientes da Geofence (Cruz) --- */
    if (g_cross > 0.0) {
      gP1[0] = 0.0;
      gP1_n[0] = 0.0;
      gP1[1] = 0.0;
      gP1_n[1] = 0.0;
      gP1[2] = 0.0;
      gP1_n[2] = 0.0;
      if ((b_a > 0.0) || (P1_k > 0.0) || (P2_k > 0.0)) {
        gP1[0] = 0.0;
        x_k[0] = 0.0;
        gP1[1] = 0.0;
        x_k[1] = 0.0;
        gP1[2] = 0.0;
        x_k[2] = 0.0;
        if (dx1_k > 0.0) {
          gP1[0] = 2.0 * dx1_k * muDoubleScalarSign(x_pos_k);
        }
        if (dy1_k > 0.0) {
          gP1[1] = 2.0 * dy1_k * muDoubleScalarSign(y_pos_k);
        }
        if (dx2_k > 0.0) {
          x_k[0] = 2.0 * dx2_k * muDoubleScalarSign(x_pos_k);
        }
        if (dy2_k > 0.0) {
          x_k[1] = 2.0 * dy2_k * muDoubleScalarSign(y_pos_k);
        }
        r = _mm_loadu_pd(&gP1[0]);
        r1 = _mm_loadu_pd(&x_k[0]);
        _mm_storeu_pd(&gP1[0], _mm_add_pd(_mm_mul_pd(_mm_set1_pd(P2_k), r),
                                          _mm_mul_pd(_mm_set1_pd(P1_k), r1)));
        gP1[2] = P2_k * gP1[2] + P1_k * 0.0;
      }
      if ((a > 0.0) || (P1_next > 0.0) || (P2_next > 0.0)) {
        gP1_n[0] = 0.0;
        x_k[0] = 0.0;
        gP1_n[1] = 0.0;
        x_k[1] = 0.0;
        gP1_n[2] = 0.0;
        x_k[2] = 0.0;
        if (dx1_next > 0.0) {
          gP1_n[0] = 2.0 * dx1_next * muDoubleScalarSign(x_pos_next);
        }
        if (dy1_next > 0.0) {
          gP1_n[1] = 2.0 * dy1_next * muDoubleScalarSign(y_pos_next);
        }
        if (dx2_next > 0.0) {
          x_k[0] = 2.0 * dx2_next * muDoubleScalarSign(x_pos_next);
        }
        if (dy2_next > 0.0) {
          x_k[1] = 2.0 * dy2_next * muDoubleScalarSign(y_pos_next);
        }
        r = _mm_loadu_pd(&gP1_n[0]);
        r1 = _mm_loadu_pd(&x_k[0]);
        _mm_storeu_pd(&gP1_n[0],
                      _mm_add_pd(_mm_mul_pd(_mm_set1_pd(P2_next), r),
                                 _mm_mul_pd(_mm_set1_pd(P1_next), r1)));
        gP1_n[2] = P2_next * gP1_n[2] + P1_next * 0.0;
      }
      P2_next = 2.0 * eta_safe * g_cross;
      r = _mm_loadu_pd(&gP1[0]);
      r1 = _mm_set1_pd(P2_next);
      _mm_storeu_pd(
          &gP1[0],
          _mm_mul_pd(r1, _mm_mul_pd(_mm_set1_pd(1.0 - gamma_safe),
                                    _mm_mul_pd(r, _mm_set1_pd(-1.0)))));
      r = _mm_loadu_pd(&gP1_n[0]);
      _mm_storeu_pd(&gP1_n[0], _mm_mul_pd(r1, r));
      gP1[2] = P2_next * ((1.0 - gamma_safe) * -gP1[2]);
      gP1_n[2] *= P2_next;
    }
    /*  --- Gradientes do Obstáculo (Círculo) --- */
    if (g_circ > 0.0) {
      x_k[0] = 0.0;
      x_next[0] = 0.0;
      x_k[1] = 0.0;
      x_next[1] = 0.0;
      x_k[2] = 0.0;
      x_next[2] = 0.0;
      if (v_circ_k > 0.0) {
        dy2_next = -4.0 * v_circ_k;
        x_k[0] = dy2_next * x_pos_k;
        x_k[1] = dy2_next * y_pos_k;
      }
      if (v_circ_next > 0.0) {
        dy2_next = -4.0 * v_circ_next;
        x_next[0] = dy2_next * x_pos_next;
        x_next[1] = dy2_next * y_pos_next;
      }
      dy2_next = 2.0 * eta_obs * g_circ;
      r = _mm_loadu_pd(&x_k[0]);
      r1 = _mm_loadu_pd(&gP1[0]);
      r2 = _mm_set1_pd(dy2_next);
      _mm_storeu_pd(
          &gP1[0],
          _mm_add_pd(
              r1,
              _mm_mul_pd(r2, _mm_mul_pd(_mm_set1_pd(1.0 - gamma_obs),
                                        _mm_mul_pd(r, _mm_set1_pd(-1.0))))));
      r = _mm_loadu_pd(&x_next[0]);
      r1 = _mm_loadu_pd(&gP1_n[0]);
      _mm_storeu_pd(&gP1_n[0], _mm_add_pd(r1, _mm_mul_pd(r2, r)));
      gP1[2] += dy2_next * ((1.0 - gamma_obs) * -0.0);
      gP1_n[2] += dy2_next * 0.0;
    }
    dy2_next = X_hist[v_n_tmp + 2];
    P2_next = muDoubleScalarCos(dy2_next);
    dy2_next = muDoubleScalarSin(dy2_next);
    gP1_n[0] += p_n[0];
    gP1_n[1] += p_n[1];
    gP1_n[2] += p_n[2];
    dv[2] = -0.1 * v_n * dy2_next;
    dv[5] = 0.1 * v_n * P2_next;
    memset(&p_n[0], 0, 3U * sizeof(real_T));
    r = _mm_loadu_pd(&dv[0]);
    r1 = _mm_loadu_pd(&p_n[0]);
    r2 = _mm_set1_pd(gP1_n[0]);
    _mm_storeu_pd(&p_n[0], _mm_add_pd(r1, _mm_mul_pd(r, r2)));
    p_n[2] += gP1_n[0] * dv[2];
    r = _mm_loadu_pd(&dv[3]);
    r1 = _mm_loadu_pd(&p_n[0]);
    r3 = _mm_set1_pd(gP1_n[1]);
    _mm_storeu_pd(&p_n[0], _mm_add_pd(r1, _mm_mul_pd(r, r3)));
    p_n[2] += gP1_n[1] * dv[5];
    r = _mm_loadu_pd(&dv[6]);
    r1 = _mm_loadu_pd(&p_n[0]);
    r4 = _mm_set1_pd(gP1_n[2]);
    _mm_storeu_pd(&p_n[0], _mm_add_pd(r1, _mm_mul_pd(r, r4)));
    p_n[2] += gP1_n[2];
    gP1[0] += 1.6 * (l_u - params[3]);
    gP1[1] += 1.6 * (R_circ - params[4]);
    r = _mm_loadu_pd(&p_n[0]);
    r1 = _mm_loadu_pd(&gP1[0]);
    _mm_storeu_pd(&p_n[0], _mm_add_pd(r, r1));
    p_n[2] += gP1[2];
    v_n_tmp = (10 - n) << 1;
    if (b_v_n_tmp + 1 > v_n_tmp) {
      x_pos_next_tmp = 0;
      v_n_tmp = 0;
    } else {
      x_pos_next_tmp = b_v_n_tmp;
    }
    v_n_tmp -= x_pos_next_tmp;
    if (v_n_tmp != 2) {
      emlrtSubAssignSizeCheck1dR2017a(v_n_tmp, 2, &emlrtECI, (emlrtConstCTX)sp);
    }
    dv1[0] = 0.1 * P2_next;
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
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
  return cost;
}

/* End of code generation (build_robot_cbf_experiment.c) */
