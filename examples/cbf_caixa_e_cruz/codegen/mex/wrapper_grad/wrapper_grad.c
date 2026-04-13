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
    "C:\\Users\\henri\\Desktop\\robotarium_ws\\robotarium-matlab-"
    "simulator\\examples\\cbf_caixa\\wrapper_grad.m" /* pathName */
};

/* Function Definitions */
void wrapper_grad(const emlrtStack *sp, const real_T u[40],
                  const real_T params[17], real_T grad[40])
{
  emlrtStack st;
  real_T grad_smooth[40];
  int32_T i;
  st.prev = sp;
  st.tls = sp->tls;
  /*  1. Gradiente do modelo analítico original */
  st.site = &emlrtRSI;
  build_robot_cbf_experiment(&st, u, params, grad);
  /*  2. Pesos (Devem ser EXATAMENTE IGUAIS aos da função de custo!) */
  /*  3. Inicializa o vetor do gradiente de suavização */
  memset(&grad_smooth[0], 0, 40U * sizeof(real_T));
  /*  4. Calcula as derivadas parciais (Regra da Cadeia) */
  for (i = 0; i < 19; i++) {
    real_T grad_smooth_tmp;
    int32_T dv_tmp;
    /*  Derivada em relação a v */
    dv_tmp = (i + 1) << 1;
    /*  v_{i+1} - v_i */
    grad_smooth_tmp = 0.4 * (u[dv_tmp] - u[dv_tmp - 2]);
    grad_smooth[dv_tmp - 2] -= grad_smooth_tmp;
    grad_smooth[dv_tmp] += grad_smooth_tmp;
    /*  Derivada em relação a w */
    /*  w_{i+1} - w_i */
    grad_smooth_tmp = 0.4 * (u[dv_tmp + 1] - u[dv_tmp - 1]);
    grad_smooth[dv_tmp - 1] -= grad_smooth_tmp;
    grad_smooth[dv_tmp + 1] += grad_smooth_tmp;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
  /*  5. Gradiente total */
  for (i = 0; i <= 38; i += 2) {
    __m128d r;
    __m128d r1;
    r = _mm_loadu_pd(&grad[i]);
    r1 = _mm_loadu_pd(&grad_smooth[i]);
    _mm_storeu_pd(&grad[i], _mm_add_pd(r, r1));
  }
}

/* End of code generation (wrapper_grad.c) */
