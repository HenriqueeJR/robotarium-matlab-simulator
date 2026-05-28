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
#include "wrapper_grad_emxutil.h"
#include "wrapper_grad_types.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = {
    3,              /* lineNo */
    "wrapper_grad", /* fcnName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_tracking\\wrapper_grad.m" /* pathName */
};

static emlrtDCInfo emlrtDCI = {
    22,                           /* lineNo */
    14,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_tracking\\build_robot_cbf_experimen"
    "t.m", /* pName */
    1      /* checkKind */
};

static emlrtBCInfo emlrtBCI = {
    1,                            /* iFirst */
    51,                           /* iLast */
    22,                           /* lineNo */
    14,                           /* colNo */
    "W",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_tracking\\build_robot_cbf_experimen"
    "t.m", /* pName */
    0      /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = {
    36,                           /* lineNo */
    23,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_tracking\\build_robot_cbf_experimen"
    "t.m", /* pName */
    4      /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = {
    36,                           /* lineNo */
    23,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_tracking\\build_robot_cbf_experimen"
    "t.m", /* pName */
    1      /* checkKind */
};

static emlrtRTEInfo emlrtRTEI = {
    43,                           /* lineNo */
    13,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_tracking\\build_robot_cbf_experimen"
    "t.m" /* pName */
};

static emlrtBCInfo b_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    37,                           /* lineNo */
    15,                           /* colNo */
    "X_hist",                     /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_tracking\\build_robot_cbf_experimen"
    "t.m", /* pName */
    0      /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    71,                           /* lineNo */
    19,                           /* colNo */
    "X_hist",                     /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_tracking\\build_robot_cbf_experimen"
    "t.m", /* pName */
    0      /* checkKind */
};

static emlrtDCInfo d_emlrtDCI = {
    79,                           /* lineNo */
    21,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_tracking\\build_robot_cbf_experimen"
    "t.m", /* pName */
    1      /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    79,                           /* lineNo */
    21,                           /* colNo */
    "X_hist",                     /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_tracking\\build_robot_cbf_experimen"
    "t.m", /* pName */
    0      /* checkKind */
};

static emlrtRTEInfo b_emlrtRTEI = {
    128,                          /* lineNo */
    13,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_tracking\\build_robot_cbf_experimen"
    "t.m" /* pName */
};

static emlrtDCInfo e_emlrtDCI = {
    129,                          /* lineNo */
    25,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_tracking\\build_robot_cbf_experimen"
    "t.m", /* pName */
    1      /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    129,                          /* lineNo */
    25,                           /* colNo */
    "X_hist",                     /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_tracking\\build_robot_cbf_experimen"
    "t.m", /* pName */
    0      /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    130,                          /* lineNo */
    28,                           /* colNo */
    "X_hist",                     /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_tracking\\build_robot_cbf_experimen"
    "t.m", /* pName */
    0      /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    177,                          /* lineNo */
    16,                           /* colNo */
    "grad_U",                     /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_tracking\\build_robot_cbf_experimen"
    "t.m", /* pName */
    0      /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    177,                          /* lineNo */
    30,                           /* colNo */
    "grad_U",                     /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_tracking\\build_robot_cbf_experimen"
    "t.m", /* pName */
    0      /* checkKind */
};

static emlrtECInfo emlrtECI = {
    -1,                           /* nDims */
    177,                          /* lineNo */
    9,                            /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_tracking\\build_robot_cbf_experimen"
    "t.m" /* pName */
};

static emlrtDCInfo f_emlrtDCI = {
    180,                          /* lineNo */
    12,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_tracking\\build_robot_cbf_experimen"
    "t.m", /* pName */
    1      /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = {
    1,                            /* iFirst */
    51,                           /* iLast */
    180,                          /* lineNo */
    12,                           /* colNo */
    "grad",                       /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_tracking\\build_robot_cbf_experimen"
    "t.m", /* pName */
    0      /* checkKind */
};

static emlrtECInfo b_emlrtECI = {
    -1,                           /* nDims */
    180,                          /* lineNo */
    5,                            /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_tracking\\build_robot_cbf_experimen"
    "t.m" /* pName */
};

static emlrtBCInfo j_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    44,                           /* lineNo */
    17,                           /* colNo */
    "u",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_tracking\\build_robot_cbf_experimen"
    "t.m", /* pName */
    0      /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    45,                           /* lineNo */
    17,                           /* colNo */
    "u",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_tracking\\build_robot_cbf_experimen"
    "t.m", /* pName */
    0      /* checkKind */
};

static emlrtDCInfo g_emlrtDCI = {
    106,                          /* lineNo */
    5,                            /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_tracking\\build_robot_cbf_experimen"
    "t.m", /* pName */
    1      /* checkKind */
};

static emlrtDCInfo h_emlrtDCI = {
    106,                          /* lineNo */
    5,                            /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_tracking\\build_robot_cbf_experimen"
    "t.m", /* pName */
    4      /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    131,                          /* lineNo */
    17,                           /* colNo */
    "u",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_tracking\\build_robot_cbf_experimen"
    "t.m", /* pName */
    0      /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    131,                          /* lineNo */
    39,                           /* colNo */
    "u",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_tracking\\build_robot_cbf_experimen"
    "t.m", /* pName */
    0      /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = {
    1,                            /* iFirst */
    51,                           /* iLast */
    34,                           /* lineNo */
    12,                           /* colNo */
    "W",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_tracking\\build_robot_cbf_experimen"
    "t.m", /* pName */
    0      /* checkKind */
};

static emlrtDCInfo i_emlrtDCI = {
    34,                           /* lineNo */
    12,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_tracking\\build_robot_cbf_experimen"
    "t.m", /* pName */
    1      /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = {
    1,                            /* iFirst */
    51,                           /* iLast */
    33,                           /* lineNo */
    12,                           /* colNo */
    "W",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_tracking\\build_robot_cbf_experimen"
    "t.m", /* pName */
    0      /* checkKind */
};

static emlrtDCInfo j_emlrtDCI = {
    33,                           /* lineNo */
    12,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_tracking\\build_robot_cbf_experimen"
    "t.m", /* pName */
    1      /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = {
    1,                            /* iFirst */
    51,                           /* iLast */
    32,                           /* lineNo */
    12,                           /* colNo */
    "W",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_tracking\\build_robot_cbf_experimen"
    "t.m", /* pName */
    0      /* checkKind */
};

static emlrtDCInfo k_emlrtDCI = {
    32,                           /* lineNo */
    12,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_tracking\\build_robot_cbf_experimen"
    "t.m", /* pName */
    1      /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = {
    1,                            /* iFirst */
    51,                           /* iLast */
    24,                           /* lineNo */
    12,                           /* colNo */
    "W",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_tracking\\build_robot_cbf_experimen"
    "t.m", /* pName */
    0      /* checkKind */
};

static emlrtDCInfo l_emlrtDCI = {
    24,                           /* lineNo */
    12,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_tracking\\build_robot_cbf_experimen"
    "t.m", /* pName */
    1      /* checkKind */
};

static emlrtBCInfo r_emlrtBCI = {
    1,                            /* iFirst */
    51,                           /* iLast */
    23,                           /* lineNo */
    12,                           /* colNo */
    "W",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_tracking\\build_robot_cbf_experimen"
    "t.m", /* pName */
    0      /* checkKind */
};

static emlrtDCInfo m_emlrtDCI = {
    23,                           /* lineNo */
    12,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_tracking\\build_robot_cbf_experimen"
    "t.m", /* pName */
    1      /* checkKind */
};

static emlrtRTEInfo c_emlrtRTEI = {
    36,                           /* lineNo */
    5,                            /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_tracking\\build_robot_cbf_experimen"
    "t.m" /* pName */
};

static emlrtRTEInfo d_emlrtRTEI = {
    106,                          /* lineNo */
    5,                            /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_tracking\\build_robot_cbf_experimen"
    "t.m" /* pName */
};

/* Function Definitions */
void wrapper_grad(const emlrtStack *sp, const real_T u[51],
                  const real_T params[30], real_T grad[51])
{
  __m128d b_r1;
  __m128d b_r2;
  __m128d r;
  __m128d r4;
  __m128d r5;
  __m128d r6;
  emlrtStack st;
  emxArray_real_T *X_hist;
  emxArray_real_T *grad_U;
  real_T grad_smooth[51];
  real_T dv[9];
  real_T b_Ts[6];
  real_T grad_xs[3];
  real_T p_n[3];
  real_T x_k[3];
  real_T x_next[3];
  real_T xs[3];
  real_T gP_r1[2];
  real_T gP_r2[2];
  real_T gP_r3[2];
  real_T gP_xs[2];
  real_T grad_r1[2];
  real_T r1[2];
  real_T r2[2];
  real_T r3[2];
  real_T P_c_k;
  real_T P_c_n;
  real_T P_g_k;
  real_T P_g_n;
  real_T P_r2;
  real_T P_r3;
  real_T P_v_k;
  real_T Ts;
  real_T b_xs_tmp;
  real_T d;
  real_T d1;
  real_T eta_safe;
  real_T gamma_safe;
  real_T grad_us_idx_0;
  real_T grad_us_idx_1;
  real_T v_s;
  real_T w_s;
  real_T xs_tmp;
  real_T *X_hist_data;
  real_T *grad_U_data;
  int32_T b_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T loop_ub;
  int32_T n;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  st.site = &emlrtRSI;
  /*  Desempacotamento limpo do vetor params (Tamanho: 30) */
  x_k[0] = params[0];
  x_k[1] = params[1];
  x_k[2] = params[2];
  eta_safe = params[5];
  gamma_safe = params[6];
  Ts = params[8];
  /*  params(10) era o r_rob. Não subtraímos mais aqui para não inverter os
   * blocos.      */
  /*  Limites [xmin, xmax, ymin, ymax] dos 4 blocos */
  d = 2.0 * params[7];
  if (d < 1.0) {
    i = 0;
  } else {
    if (d != (int32_T)muDoubleScalarFloor(d)) {
      emlrtIntegerCheckR2012b(d, &emlrtDCI, &st);
    }
    if (((int32_T)d < 1) || ((int32_T)d > 51)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, 51, &emlrtBCI, &st);
    }
    i = (int32_T)d;
  }
  if (d + 1.0 != (int32_T)muDoubleScalarFloor(d + 1.0)) {
    emlrtIntegerCheckR2012b(d + 1.0, &m_emlrtDCI, &st);
  }
  if (((int8_T)(d + 1.0) < 1) || ((int8_T)(d + 1.0) > 51)) {
    emlrtDynamicBoundsCheckR2012b((int8_T)(d + 1.0), 1, 51, &r_emlrtBCI, &st);
  }
  if ((d + 1.0) + 1.0 != (int32_T)muDoubleScalarFloor((d + 1.0) + 1.0)) {
    emlrtIntegerCheckR2012b((d + 1.0) + 1.0, &m_emlrtDCI, &st);
  }
  if (((int8_T)((d + 1.0) + 1.0) < 1) || ((int8_T)((d + 1.0) + 1.0) > 51)) {
    emlrtDynamicBoundsCheckR2012b((int8_T)((d + 1.0) + 1.0), 1, 51, &r_emlrtBCI,
                                  &st);
  }
  if ((d + 1.0) + 2.0 != (int32_T)muDoubleScalarFloor((d + 1.0) + 2.0)) {
    emlrtIntegerCheckR2012b((d + 1.0) + 2.0, &m_emlrtDCI, &st);
  }
  if (((int8_T)((d + 1.0) + 2.0) < 1) || ((int8_T)((d + 1.0) + 2.0) > 51)) {
    emlrtDynamicBoundsCheckR2012b((int8_T)((d + 1.0) + 2.0), 1, 51, &r_emlrtBCI,
                                  &st);
  }
  xs_tmp = u[(int8_T)(d + 1.0) - 1];
  xs[0] = xs_tmp;
  b_xs_tmp = u[(int8_T)((d + 1.0) + 1.0) - 1];
  xs[1] = b_xs_tmp;
  xs[2] = u[(int8_T)((d + 1.0) + 2.0) - 1];
  if (d + 4.0 != (int32_T)muDoubleScalarFloor(d + 4.0)) {
    emlrtIntegerCheckR2012b(d + 4.0, &l_emlrtDCI, &st);
  }
  if (((int8_T)(d + 4.0) < 1) || ((int8_T)(d + 4.0) > 51)) {
    emlrtDynamicBoundsCheckR2012b((int8_T)(d + 4.0), 1, 51, &q_emlrtBCI, &st);
  }
  if ((d + 4.0) + 1.0 != (int32_T)muDoubleScalarFloor((d + 4.0) + 1.0)) {
    emlrtIntegerCheckR2012b((d + 4.0) + 1.0, &l_emlrtDCI, &st);
  }
  if (((int8_T)((d + 4.0) + 1.0) < 1) || ((int8_T)((d + 4.0) + 1.0) > 51)) {
    emlrtDynamicBoundsCheckR2012b((int8_T)((d + 4.0) + 1.0), 1, 51, &q_emlrtBCI,
                                  &st);
  }
  v_s = u[(int8_T)(d + 4.0) - 1];
  w_s = u[(int8_T)((d + 4.0) + 1.0) - 1];
  if (d + 6.0 != (int32_T)muDoubleScalarFloor(d + 6.0)) {
    emlrtIntegerCheckR2012b(d + 6.0, &k_emlrtDCI, &st);
  }
  if (((int8_T)(d + 6.0) < 1) || ((int8_T)(d + 6.0) > 51)) {
    emlrtDynamicBoundsCheckR2012b((int8_T)(d + 6.0), 1, 51, &p_emlrtBCI, &st);
  }
  if ((d + 6.0) + 1.0 != (int32_T)muDoubleScalarFloor((d + 6.0) + 1.0)) {
    emlrtIntegerCheckR2012b((d + 6.0) + 1.0, &k_emlrtDCI, &st);
  }
  if (((int8_T)((d + 6.0) + 1.0) < 1) || ((int8_T)((d + 6.0) + 1.0) > 51)) {
    emlrtDynamicBoundsCheckR2012b((int8_T)((d + 6.0) + 1.0), 1, 51, &p_emlrtBCI,
                                  &st);
  }
  r1[0] = u[(int8_T)(d + 6.0) - 1];
  r1[1] = u[(int8_T)((d + 6.0) + 1.0) - 1];
  if (d + 8.0 != (int32_T)muDoubleScalarFloor(d + 8.0)) {
    emlrtIntegerCheckR2012b(d + 8.0, &j_emlrtDCI, &st);
  }
  if (((int8_T)(d + 8.0) < 1) || ((int8_T)(d + 8.0) > 51)) {
    emlrtDynamicBoundsCheckR2012b((int8_T)(d + 8.0), 1, 51, &o_emlrtBCI, &st);
  }
  if ((d + 8.0) + 1.0 != (int32_T)muDoubleScalarFloor((d + 8.0) + 1.0)) {
    emlrtIntegerCheckR2012b((d + 8.0) + 1.0, &j_emlrtDCI, &st);
  }
  if (((int8_T)((d + 8.0) + 1.0) < 1) || ((int8_T)((d + 8.0) + 1.0) > 51)) {
    emlrtDynamicBoundsCheckR2012b((int8_T)((d + 8.0) + 1.0), 1, 51, &o_emlrtBCI,
                                  &st);
  }
  r2[0] = u[(int8_T)(d + 8.0) - 1];
  r2[1] = u[(int8_T)((d + 8.0) + 1.0) - 1];
  if (d + 10.0 != (int32_T)muDoubleScalarFloor(d + 10.0)) {
    emlrtIntegerCheckR2012b(d + 10.0, &i_emlrtDCI, &st);
  }
  if (((int8_T)(d + 10.0) < 1) || ((int8_T)(d + 10.0) > 51)) {
    emlrtDynamicBoundsCheckR2012b((int8_T)(d + 10.0), 1, 51, &n_emlrtBCI, &st);
  }
  if ((d + 10.0) + 1.0 != (int32_T)muDoubleScalarFloor((d + 10.0) + 1.0)) {
    emlrtIntegerCheckR2012b((d + 10.0) + 1.0, &i_emlrtDCI, &st);
  }
  if (((int8_T)((d + 10.0) + 1.0) < 1) || ((int8_T)((d + 10.0) + 1.0) > 51)) {
    emlrtDynamicBoundsCheckR2012b((int8_T)((d + 10.0) + 1.0), 1, 51,
                                  &n_emlrtBCI, &st);
  }
  r3[0] = u[(int8_T)(d + 10.0) - 1];
  r3[1] = u[(int8_T)((d + 10.0) + 1.0) - 1];
  if (!(params[7] + 1.0 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(params[7] + 1.0, &b_emlrtDCI, &st);
  }
  i1 = (int32_T)muDoubleScalarFloor(params[7] + 1.0);
  if (params[7] + 1.0 != i1) {
    emlrtIntegerCheckR2012b(params[7] + 1.0, &c_emlrtDCI, &st);
  }
  emxInit_real_T(&st, &X_hist, 2, &c_emlrtRTEI);
  loop_ub = X_hist->size[0] * X_hist->size[1];
  X_hist->size[0] = 3;
  X_hist->size[1] = (int32_T)(params[7] + 1.0);
  emxEnsureCapacity_real_T(&st, X_hist, loop_ub, &c_emlrtRTEI);
  X_hist_data = X_hist->data;
  loop_ub = 3 * (int32_T)(params[7] + 1.0);
  for (n = 0; n < loop_ub; n++) {
    X_hist_data[n] = 0.0;
  }
  if ((int32_T)(params[7] + 1.0) < 1) {
    emlrtDynamicBoundsCheckR2012b(1, 1, (int32_T)(params[7] + 1.0), &b_emlrtBCI,
                                  &st);
  }
  X_hist_data[0] = params[0];
  X_hist_data[1] = params[1];
  X_hist_data[2] = params[2];
  /*  ===================================================================== */
  /*  FORWARD PASS */
  /*  ===================================================================== */
  i2 = (int32_T)params[7];
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, params[7], mxDOUBLE_CLASS,
                                (int32_T)params[7], &emlrtRTEI, &st);
  for (n = 0; n < i2; n++) {
    loop_ub = (int32_T)(((uint32_T)n << 1) + 1U);
    if ((loop_ub < 1) || (loop_ub > i)) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i, &j_emlrtBCI, &st);
    }
    b_loop_ub = (n << 1) + 2;
    if ((b_loop_ub < 1) || (b_loop_ub > i)) {
      emlrtDynamicBoundsCheckR2012b(b_loop_ub, 1, i, &k_emlrtBCI, &st);
    }
    /*  --- Estado Atual (k) --- Usa o Mínimo Exato para CBF */
    get_blocks_P(&x_k[0], &params[10], &P_v_k, &P_g_k, &P_c_k);
    /*  Dinâmica */
    P_v_k = Ts * u[loop_ub - 1];
    x_next[0] = x_k[0] + P_v_k * muDoubleScalarCos(x_k[2]);
    x_next[1] = x_k[1] + P_v_k * muDoubleScalarSin(x_k[2]);
    x_next[2] = x_k[2] + Ts * u[b_loop_ub - 1];
    /*  --- Estado Futuro (next) --- */
    get_blocks_P(&x_next[0], &params[10], &P_v_k, &P_g_k, &P_c_k);
    /*  --- Restrição CBF --- */
    x_k[0] = x_next[0];
    x_k[1] = x_next[1];
    x_k[2] = x_next[2];
    if (((int32_T)((uint32_T)n + 2U) < 1) ||
        ((int32_T)((uint32_T)n + 2U) > X_hist->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)n + 2U), 1,
                                    X_hist->size[1], &c_emlrtBCI, &st);
    }
    loop_ub = 3 * (n + 1);
    X_hist_data[loop_ub] = x_next[0];
    X_hist_data[loop_ub + 1] = x_next[1];
    X_hist_data[loop_ub + 2] = x_next[2];
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }
  /*  ===================================================================== */
  /*  TERMINAL E BACKWARD PASS */
  /*  ===================================================================== */
  if (params[7] + 1.0 != i1) {
    emlrtIntegerCheckR2012b(params[7] + 1.0, &d_emlrtDCI, &st);
  }
  i1 = X_hist->size[1];
  if (((int32_T)(params[7] + 1.0) < 1) ||
      ((int32_T)(params[7] + 1.0) > X_hist->size[1])) {
    emlrtDynamicBoundsCheckR2012b((int32_T)(params[7] + 1.0), 1,
                                  X_hist->size[1], &d_emlrtBCI, &st);
  }
  /*  Custos da Geofence para nós terminais (AQUI USA O SMOOTH MIN) */
  P_g_k = calc_corridor_penalty(&xs[0], &params[10], gP_xs);
  P_c_k = calc_corridor_penalty(r1, &params[10], gP_r1);
  P_r2 = calc_corridor_penalty(r2, &params[10], gP_r2);
  P_r3 = calc_corridor_penalty(r3, &params[10], gP_r3);
  memset(&grad[0], 0, 51U * sizeof(real_T));
  emxInit_real_T(&st, &grad_U, 1, &d_emlrtRTEI);
  if (!(d >= 0.0)) {
    emlrtNonNegativeCheckR2012b(d, &h_emlrtDCI, &st);
  }
  d1 = (int32_T)muDoubleScalarFloor(d);
  if (d != d1) {
    emlrtIntegerCheckR2012b(d, &g_emlrtDCI, &st);
  }
  loop_ub = grad_U->size[0];
  b_loop_ub = (int32_T)d;
  grad_U->size[0] = (int32_T)d;
  emxEnsureCapacity_real_T(&st, grad_U, loop_ub, &d_emlrtRTEI);
  grad_U_data = grad_U->data;
  if (d != d1) {
    emlrtIntegerCheckR2012b(d, &g_emlrtDCI, &st);
  }
  for (n = 0; n < b_loop_ub; n++) {
    grad_U_data[n] = 0.0;
  }
  __m128d b_r3;
  grad_xs[0] = 0.0;
  p_n[0] = 0.0;
  grad_xs[1] = 0.0;
  p_n[1] = 0.0;
  grad_xs[2] = 0.0;
  p_n[2] = 0.0;
  r = _mm_loadu_pd(&X_hist_data[3 * ((int32_T)(params[7] + 1.0) - 1)]);
  b_r1 = _mm_loadu_pd(&xs[0]);
  r = _mm_mul_pd(_mm_set1_pd(2.0 * params[26]), _mm_sub_pd(r, b_r1));
  _mm_storeu_pd(&p_n[0], r);
  b_r2 = _mm_loadu_pd(&r1[0]);
  b_r3 = _mm_set1_pd(2.0 * params[29]);
  r4 = _mm_set1_pd(-1.0);
  _mm_storeu_pd(
      &grad_xs[0],
      _mm_sub_pd(_mm_mul_pd(r, r4), _mm_mul_pd(b_r3, _mm_sub_pd(b_r2, b_r1))));
  r5 = _mm_loadu_pd(&r2[0]);
  r6 = _mm_set1_pd(2.0);
  _mm_storeu_pd(
      &grad_r1[0],
      _mm_mul_pd(b_r3, _mm_sub_pd(_mm_sub_pd(_mm_mul_pd(r6, b_r2), b_r1), r5)));
  r = _mm_loadu_pd(&r3[0]);
  _mm_storeu_pd(
      &r1[0],
      _mm_mul_pd(b_r3, _mm_sub_pd(_mm_sub_pd(_mm_mul_pd(r6, r5), b_r2), r)));
  _mm_storeu_pd(&r3[0],
                _mm_mul_pd(b_r3, _mm_sub_pd(_mm_sub_pd(_mm_mul_pd(r6, r), r5),
                                            _mm_loadu_pd(&params[3]))));
  P_v_k = 2.0 * params[27] * (params[8] * params[8]);
  grad_us_idx_0 = P_v_k * v_s;
  grad_us_idx_1 = P_v_k * w_s;
  /*  Gradientes da Geofence para os nós (usa os gradientes do Smooth Min) */
  if (P_g_k > 0.0) {
    r = _mm_loadu_pd(&gP_xs[0]);
    r5 = _mm_loadu_pd(&grad_xs[0]);
    _mm_storeu_pd(&grad_xs[0],
                  _mm_add_pd(r5, _mm_mul_pd(_mm_set1_pd(params[28] / 2.0), r)));
  }
  if (P_c_k > 0.0) {
    r = _mm_loadu_pd(&gP_r1[0]);
    r5 = _mm_loadu_pd(&grad_r1[0]);
    _mm_storeu_pd(&grad_r1[0],
                  _mm_add_pd(r5, _mm_mul_pd(_mm_set1_pd(params[28] / 2.0), r)));
  }
  if (P_r2 > 0.0) {
    r = _mm_loadu_pd(&gP_r2[0]);
    r5 = _mm_loadu_pd(&r1[0]);
    _mm_storeu_pd(&r1[0],
                  _mm_add_pd(r5, _mm_mul_pd(_mm_set1_pd(params[28] / 2.0), r)));
  }
  if (P_r3 > 0.0) {
    r = _mm_loadu_pd(&gP_r3[0]);
    r5 = _mm_loadu_pd(&r3[0]);
    _mm_storeu_pd(&r3[0],
                  _mm_add_pd(r5, _mm_mul_pd(_mm_set1_pd(params[28] / 2.0), r)));
  }
  i2 = (int32_T) - ((-1.0 - params[7]) + 1.0);
  emlrtForLoopVectorCheckR2021a(params[7], -1.0, 1.0, mxDOUBLE_CLASS,
                                (int32_T) - ((-1.0 - params[7]) + 1.0),
                                &b_emlrtRTEI, &st);
  if ((int32_T) - ((-1.0 - params[7]) + 1.0) - 1 >= 0) {
    b_Ts[4] = 0.0;
    b_Ts[1] = 0.0;
    b_Ts[3] = 0.0;
    b_Ts[5] = params[8];
  }
  if (i2 - 1 >= 0) {
    dv[0] = 1.0;
    dv[1] = 0.0;
    dv[3] = 0.0;
    dv[4] = 1.0;
    dv[6] = 0.0;
    dv[7] = 0.0;
    dv[8] = 1.0;
  }
  for (n = 0; n < i2; n++) {
    real_T P_a_n;
    real_T b_grad_xs_tmp;
    real_T b_n;
    real_T g_corridor;
    real_T grad_us_idx_0_tmp;
    real_T grad_us_idx_1_tmp;
    real_T grad_xs_tmp;
    real_T v_n;
    uint32_T b_u;
    uint32_T u1;
    b_n = params[7] - (real_T)n;
    if (b_n != (int32_T)muDoubleScalarFloor(b_n)) {
      emlrtIntegerCheckR2012b(b_n, &e_emlrtDCI, &st);
    }
    if (((int32_T)b_n < 1) || ((int32_T)b_n > i1)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)b_n, 1, i1, &e_emlrtBCI, &st);
    }
    if (((int32_T)(b_n + 1.0) < 1) || ((int32_T)(b_n + 1.0) > i1)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_n + 1.0), 1, i1, &f_emlrtBCI,
                                    &st);
    }
    b_u = (uint32_T)((int32_T)b_n - 1) << 1;
    if (((int32_T)(b_u + 1U) < 1) || ((int32_T)(b_u + 1U) > i)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_u + 1U), 1, i, &l_emlrtBCI,
                                    &st);
    }
    v_n = u[(int32_T)b_u];
    if (((int32_T)(b_u + 2U) < 1) || ((int32_T)(b_u + 2U) > i)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_u + 2U), 1, i, &m_emlrtBCI,
                                    &st);
    }
    loop_ub = 3 * ((int32_T)b_n - 1);
    grad_xs_tmp = 10.0 * (X_hist_data[loop_ub] - xs_tmp);
    grad_xs[0] -= grad_xs_tmp;
    b_grad_xs_tmp = 10.0 * (X_hist_data[loop_ub + 1] - b_xs_tmp);
    grad_xs[1] -= b_grad_xs_tmp;
    grad_us_idx_0_tmp = v_n - v_s;
    grad_us_idx_0 -= grad_us_idx_0_tmp;
    grad_us_idx_1_tmp = 3.0 * (u[(int32_T)b_u + 1] - w_s);
    grad_us_idx_1 -= grad_us_idx_1_tmp;
    /*  Recalcula penalidades com MÍNIMO EXATO para CBF */
    P_r2 = get_blocks_P(&X_hist_data[loop_ub], &params[10], &P_v_k, &P_g_k,
                        &P_c_k);
    b_loop_ub = 3 * (int32_T)b_n;
    P_a_n = get_blocks_P(&X_hist_data[b_loop_ub], &params[10], &P_r3, &P_g_n,
                         &P_c_n);
    g_corridor = (1.0 - gamma_safe) *
                     -muDoubleScalarMin(muDoubleScalarMin(P_r2, P_v_k),
                                        muDoubleScalarMin(P_g_k, P_c_k)) -
                 (-muDoubleScalarMin(muDoubleScalarMin(P_a_n, P_r3),
                                     muDoubleScalarMin(P_g_n, P_c_n)));
    x_k[0] = 0.0;
    x_next[0] = 0.0;
    x_k[1] = 0.0;
    x_next[1] = 0.0;
    x_k[2] = 0.0;
    x_next[2] = 0.0;
    if (g_corridor > 0.0) {
      /*  Busca o gradiente exato apenas para o bloco mais próximo */
      get_exact_grad(&X_hist_data[loop_ub], &params[10], P_r2, P_v_k, P_g_k,
                     P_c_k, r2);
      r = _mm_loadu_pd(&r2[0]);
      r5 = _mm_set1_pd(2.0 * eta_safe * g_corridor);
      _mm_storeu_pd(&x_k[0],
                    _mm_mul_pd(r5, _mm_mul_pd(_mm_set1_pd(1.0 - gamma_safe),
                                              _mm_mul_pd(r, r4))));
      get_exact_grad(&X_hist_data[b_loop_ub], &params[10], P_a_n, P_r3, P_g_n,
                     P_c_n, r2);
      r = _mm_loadu_pd(&r2[0]);
      _mm_storeu_pd(&x_next[0], _mm_mul_pd(r5, r));
    }
    P_v_k = X_hist_data[loop_ub + 2];
    P_g_k = muDoubleScalarCos(P_v_k);
    P_v_k = muDoubleScalarSin(P_v_k);
    x_next[0] += p_n[0];
    x_next[1] += p_n[1];
    x_next[2] += p_n[2];
    dv[2] = -Ts * v_n * P_v_k;
    dv[5] = Ts * v_n * P_g_k;
    memset(&p_n[0], 0, 3U * sizeof(real_T));
    r = _mm_loadu_pd(&dv[0]);
    r5 = _mm_loadu_pd(&p_n[0]);
    r6 = _mm_set1_pd(x_next[0]);
    _mm_storeu_pd(&p_n[0], _mm_add_pd(r5, _mm_mul_pd(r, r6)));
    p_n[2] += x_next[0] * dv[2];
    r = _mm_loadu_pd(&dv[3]);
    r5 = _mm_loadu_pd(&p_n[0]);
    b_r1 = _mm_set1_pd(x_next[1]);
    _mm_storeu_pd(&p_n[0], _mm_add_pd(r5, _mm_mul_pd(r, b_r1)));
    p_n[2] += x_next[1] * dv[5];
    r = _mm_loadu_pd(&dv[6]);
    r5 = _mm_loadu_pd(&p_n[0]);
    b_r2 = _mm_set1_pd(x_next[2]);
    _mm_storeu_pd(&p_n[0], _mm_add_pd(r5, _mm_mul_pd(r, b_r2)));
    p_n[2] += x_next[2];
    xs[0] = grad_xs_tmp + x_k[0];
    xs[1] = b_grad_xs_tmp + x_k[1];
    xs[2] = x_k[2];
    r = _mm_loadu_pd(&p_n[0]);
    r5 = _mm_loadu_pd(&xs[0]);
    _mm_storeu_pd(&p_n[0], _mm_add_pd(r, r5));
    p_n[2] += x_k[2];
    u1 = (uint32_T)b_n << 1;
    if (b_u + 1U > u1) {
      b_loop_ub = 0;
      loop_ub = 0;
    } else {
      if (((int32_T)(b_u + 1U) < 1) ||
          ((int32_T)(b_u + 1U) > grad_U->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(b_u + 1U), 1, grad_U->size[0],
                                      &g_emlrtBCI, &st);
      }
      b_loop_ub = (int32_T)b_u;
      if (((int32_T)u1 < 1) || ((int32_T)u1 > grad_U->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)u1, 1, grad_U->size[0],
                                      &h_emlrtBCI, &st);
      }
      loop_ub = (int32_T)u1;
    }
    loop_ub -= b_loop_ub;
    if (loop_ub != 2) {
      emlrtSubAssignSizeCheck1dR2017a(loop_ub, 2, &emlrtECI, &st);
    }
    b_Ts[0] = Ts * P_g_k;
    b_Ts[2] = Ts * P_v_k;
    memset(&r2[0], 0, sizeof(real_T) << 1);
    r = _mm_loadu_pd(&b_Ts[0]);
    r5 = _mm_loadu_pd(&r2[0]);
    _mm_storeu_pd(&r2[0], _mm_add_pd(r5, _mm_mul_pd(r, r6)));
    r = _mm_loadu_pd(&b_Ts[2]);
    r5 = _mm_loadu_pd(&r2[0]);
    _mm_storeu_pd(&r2[0], _mm_add_pd(r5, _mm_mul_pd(r, b_r1)));
    r = _mm_loadu_pd(&b_Ts[4]);
    r5 = _mm_loadu_pd(&r2[0]);
    _mm_storeu_pd(&r2[0], _mm_add_pd(r5, _mm_mul_pd(r, b_r2)));
    gP_xs[0] = grad_us_idx_0_tmp;
    gP_xs[1] = grad_us_idx_1_tmp;
    r = _mm_loadu_pd(&r2[0]);
    r5 = _mm_loadu_pd(&gP_xs[0]);
    _mm_storeu_pd(&grad_U_data[b_loop_ub], _mm_add_pd(r, r5));
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }
  emxFree_real_T(&st, &X_hist);
  if (d < 1.0) {
    loop_ub = 0;
  } else {
    if (d != d1) {
      emlrtIntegerCheckR2012b(d, &f_emlrtDCI, &st);
    }
    if (((int32_T)d < 1) || ((int32_T)d > 51)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, 51, &i_emlrtBCI, &st);
    }
    loop_ub = (int32_T)d;
  }
  if (loop_ub != grad_U->size[0]) {
    emlrtSubAssignSizeCheck1dR2017a(loop_ub, grad_U->size[0], &b_emlrtECI, &st);
  }
  for (n = 0; n < loop_ub; n++) {
    grad[n] = grad_U_data[n];
  }
  emxFree_real_T(&st, &grad_U);
  grad[(int8_T)(d + 1.0) - 1] = grad_xs[0];
  grad[(int8_T)((d + 1.0) + 1.0) - 1] = grad_xs[1];
  grad[(int8_T)((d + 1.0) + 2.0) - 1] = grad_xs[2];
  grad[(int8_T)(d + 4.0) - 1] = grad_us_idx_0;
  grad[(int8_T)((d + 4.0) + 1.0) - 1] = grad_us_idx_1;
  grad[(int8_T)(d + 6.0) - 1] = grad_r1[0];
  grad[(int8_T)((d + 6.0) + 1.0) - 1] = grad_r1[1];
  grad[(int8_T)(d + 8.0) - 1] = r1[0];
  grad[(int8_T)((d + 8.0) + 1.0) - 1] = r1[1];
  grad[(int8_T)(d + 10.0) - 1] = r3[0];
  grad[(int8_T)((d + 10.0) + 1.0) - 1] = r3[1];
  memset(&grad_smooth[0], 0, 51U * sizeof(real_T));
  /*  Calcula as derivadas parciais  */
  for (n = 0; n < 24; n++) {
    /*  Derivada em relação a v */
    loop_ub = (n + 1) << 1;
    /*  v_{i+1} - v_i */
    P_v_k = 0.4 * (u[loop_ub] - u[loop_ub - 2]);
    grad_smooth[loop_ub - 2] -= P_v_k;
    grad_smooth[loop_ub] += P_v_k;
    /*  Derivada em relação a w */
    /*  w_{i+1} - w_i */
    P_v_k = 0.4 * (u[loop_ub + 1] - u[loop_ub - 1]);
    grad_smooth[loop_ub - 1] -= P_v_k;
    grad_smooth[loop_ub + 1] += P_v_k;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
  /*  5. Gradiente total */
  for (n = 0; n <= 48; n += 2) {
    r = _mm_loadu_pd(&grad[n]);
    r5 = _mm_loadu_pd(&grad_smooth[n]);
    _mm_storeu_pd(&grad[n], _mm_add_pd(r, r5));
  }
  grad[50] += grad_smooth[50];
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

/* End of code generation (wrapper_grad.c) */
