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
#include "build_robot_cbf_experiment.h"
#include "rt_nonfinite.h"
#include "sumMatrixIncludeNaN.h"
#include <emmintrin.h>

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = {
    3,              /* lineNo */
    "wrapper_cost", /* fcnName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\cbf_cruz_waypoints_tracking\\wrapper_cost.m" /* pathName
                                                                        */
};

/* Function Definitions */
real_T wrapper_cost(const emlrtStack *sp, const real_T u[51],
                    const real_T params[17])
{
  __m128d r;
  emlrtStack st;
  real_T b_y[24];
  real_T c_y[24];
  real_T y[24];
  real_T cost;
  real_T cost_base;
  real_T tmp2;
  int32_T m;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &emlrtRSI;
  cost_base = build_robot_cbf_experiment(&st, u, params);
  /*  Pesos de suavização  */
  cost = u[0];
  for (m = 0; m < 24; m++) {
    tmp2 = cost;
    cost = u[(m + 1) << 1];
    y[m] = cost - tmp2;
  }
  for (m = 0; m <= 22; m += 2) {
    r = _mm_loadu_pd(&y[m]);
    _mm_storeu_pd(&b_y[m], _mm_mul_pd(r, r));
  }
  cost = u[1];
  for (m = 0; m < 24; m++) {
    tmp2 = cost;
    cost = u[((m + 1) << 1) + 1];
    y[m] = cost - tmp2;
  }
  for (m = 0; m <= 22; m += 2) {
    r = _mm_loadu_pd(&y[m]);
    _mm_storeu_pd(&c_y[m], _mm_mul_pd(r, r));
  }
  /*  Custo total */
  return cost_base + (0.2 * sumColumnB(b_y) + 0.2 * sumColumnB(c_y));
}

/* End of code generation (wrapper_cost.c) */
