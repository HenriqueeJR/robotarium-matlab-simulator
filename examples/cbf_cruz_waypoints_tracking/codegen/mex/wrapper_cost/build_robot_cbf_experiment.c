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
#include "mwmathutil.h"
#include <emmintrin.h>

/* Function Definitions */
real_T calc_cross_penalty(const real_T pt[2], const real_T x_obs[2],
                          real_T L_safe, real_T W_safe, real_T grad_P[2])
{
  real_T gP2[2];
  real_T P1;
  real_T P2;
  real_T P_cross;
  real_T delta;
  real_T diff_P;
  real_T dx1;
  real_T dx2;
  real_T dy1;
  real_T dy2;
  real_T x_pos;
  real_T y_pos;
  x_pos = pt[0] - x_obs[0];
  y_pos = pt[1] - x_obs[1];
  P2 = muDoubleScalarAbs(x_pos);
  dx1 = muDoubleScalarMax(0.0, P2 - L_safe);
  P_cross = muDoubleScalarAbs(y_pos);
  dy1 = muDoubleScalarMax(0.0, P_cross - W_safe);
  P1 = dx1 * dx1 + dy1 * dy1;
  dx2 = muDoubleScalarMax(0.0, P2 - W_safe);
  dy2 = muDoubleScalarMax(0.0, P_cross - L_safe);
  P2 = dx2 * dx2 + dy2 * dy2;
  /*  --- Mínimo Suave Analítico (Smooth Min) --- */
  /*  Fator de suavização para o L-BFGS não travar */
  diff_P = P1 - P2;
  delta = muDoubleScalarSqrt(diff_P * diff_P + 0.0001);
  P_cross = 0.5 * ((P1 + P2) - delta);
  /*  Truncamento suave: só aplica penalidade se estiver fora da cruz */
  if (P_cross <= 0.0) {
    P_cross = 0.0;
    grad_P[0] = 0.0;
    grad_P[1] = 0.0;
  } else {
    __m128d r;
    __m128d r1;
    grad_P[0] = 0.0;
    gP2[0] = 0.0;
    grad_P[1] = 0.0;
    gP2[1] = 0.0;
    if (dx1 > 0.0) {
      grad_P[0] = 2.0 * dx1 * muDoubleScalarSign(x_pos);
    }
    if (dy1 > 0.0) {
      grad_P[1] = 2.0 * dy1 * muDoubleScalarSign(y_pos);
    }
    if (dx2 > 0.0) {
      gP2[0] = 2.0 * dx2 * muDoubleScalarSign(x_pos);
    }
    if (dy2 > 0.0) {
      gP2[1] = 2.0 * dy2 * muDoubleScalarSign(y_pos);
    }
    /*  Regra da cadeia para o Smooth Min */
    r = _mm_loadu_pd(&grad_P[0]);
    r1 = _mm_loadu_pd(&gP2[0]);
    _mm_storeu_pd(&grad_P[0],
                  _mm_mul_pd(_mm_set1_pd(0.5),
                             _mm_sub_pd(_mm_add_pd(r, r1),
                                        _mm_mul_pd(_mm_set1_pd(diff_P / delta),
                                                   _mm_sub_pd(r, r1)))));
  }
  return P_cross;
}

/* End of code generation (build_robot_cbf_experiment.c) */
