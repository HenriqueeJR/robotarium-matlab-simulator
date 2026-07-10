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
#include "build_robot_cbf_experiment.h"
#include "rt_nonfinite.h"
#include "wrapper_grad_data.h"
#include <emmintrin.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = {
    3,              /* lineNo */
    "wrapper_grad", /* fcnName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\wrapper_grad.m" /* pathName */
};

/* Function Definitions */
void wrapper_grad(const emlrtStack *sp, const real_T u[50],
                  const real_T params[30], real_T grad[50])
{
  emlrtStack st;
  real_T grad_smooth[50];
  int32_T dv_tmp;
  int32_T i;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &emlrtRSI;
  build_robot_cbf_experiment(&st, u, params, grad);
  memset(&grad_smooth[0], 0, 50U * sizeof(real_T));
  /*  Calcula as derivadas parciais  */
  for (i = 0; i < 24; i++) {
    real_T dv;
    /*  Derivada em relação a v */
    dv_tmp = (i + 1) << 1;
    dv = u[dv_tmp] - u[dv_tmp - 2];
    /*  v_{i+1} - v_i */
    grad_smooth[dv_tmp - 2] -= 0.4 * dv;
    grad_smooth[dv_tmp] += 0.4 * dv;
    /*  Derivada em relação a w */
    dv = u[dv_tmp + 1] - u[dv_tmp - 1];
    /*  w_{i+1} - w_i */
    grad_smooth[dv_tmp - 1] -= 0.4 * dv;
    grad_smooth[dv_tmp + 1] += 0.4 * dv;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
  /*  5. Gradiente total */
  for (dv_tmp = 0; dv_tmp <= 48; dv_tmp += 2) {
    __m128d r;
    __m128d r1;
    r = _mm_loadu_pd(&grad[dv_tmp]);
    r1 = _mm_loadu_pd(&grad_smooth[dv_tmp]);
    _mm_storeu_pd(&grad[dv_tmp], _mm_add_pd(r, r1));
  }
}

/* End of code generation (wrapper_grad.c) */
