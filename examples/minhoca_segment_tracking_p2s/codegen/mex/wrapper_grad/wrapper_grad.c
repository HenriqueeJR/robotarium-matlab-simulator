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
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "segment_track"
    "ing_p2s\\wrapper_grad.m" /* pathName */
};

static emlrtECInfo emlrtECI = {
    -1,                           /* nDims */
    207,                          /* lineNo */
    5,                            /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "segment_track"
    "ing_p2s\\build_robot_cbf_experiment.m" /* pName */
};

static emlrtBCInfo emlrtBCI = {
    1,                            /* iFirst */
    50,                           /* iLast */
    207,                          /* lineNo */
    12,                           /* colNo */
    "grad",                       /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "segment_track"
    "ing_p2s\\build_robot_cbf_experiment.m", /* pName */
    0                                        /* checkKind */
};

static emlrtDCInfo emlrtDCI = {
    207,                          /* lineNo */
    12,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "segment_track"
    "ing_p2s\\build_robot_cbf_experiment.m", /* pName */
    1                                        /* checkKind */
};

static emlrtECInfo b_emlrtECI = {
    -1,                           /* nDims */
    204,                          /* lineNo */
    9,                            /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "segment_track"
    "ing_p2s\\build_robot_cbf_experiment.m" /* pName */
};

static emlrtBCInfo b_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    204,                          /* lineNo */
    30,                           /* colNo */
    "grad_U",                     /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "segment_track"
    "ing_p2s\\build_robot_cbf_experiment.m", /* pName */
    0                                        /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    204,                          /* lineNo */
    16,                           /* colNo */
    "grad_U",                     /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "segment_track"
    "ing_p2s\\build_robot_cbf_experiment.m", /* pName */
    0                                        /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    163,                          /* lineNo */
    28,                           /* colNo */
    "X_hist",                     /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "segment_track"
    "ing_p2s\\build_robot_cbf_experiment.m", /* pName */
    0                                        /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    162,                          /* lineNo */
    25,                           /* colNo */
    "X_hist",                     /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "segment_track"
    "ing_p2s\\build_robot_cbf_experiment.m", /* pName */
    0                                        /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = {
    162,                          /* lineNo */
    25,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "segment_track"
    "ing_p2s\\build_robot_cbf_experiment.m", /* pName */
    1                                        /* checkKind */
};

static emlrtRTEInfo emlrtRTEI = {
    161,                          /* lineNo */
    13,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "segment_track"
    "ing_p2s\\build_robot_cbf_experiment.m" /* pName */
};

static emlrtBCInfo f_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    75,                           /* lineNo */
    21,                           /* colNo */
    "X_hist",                     /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "segment_track"
    "ing_p2s\\build_robot_cbf_experiment.m", /* pName */
    0                                        /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = {
    75,                           /* lineNo */
    21,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "segment_track"
    "ing_p2s\\build_robot_cbf_experiment.m", /* pName */
    1                                        /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    67,                           /* lineNo */
    19,                           /* colNo */
    "X_hist",                     /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "segment_track"
    "ing_p2s\\build_robot_cbf_experiment.m", /* pName */
    0                                        /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    36,                           /* lineNo */
    15,                           /* colNo */
    "X_hist",                     /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "segment_track"
    "ing_p2s\\build_robot_cbf_experiment.m", /* pName */
    0                                        /* checkKind */
};

static emlrtRTEInfo b_emlrtRTEI = {
    45,                           /* lineNo */
    13,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "segment_track"
    "ing_p2s\\build_robot_cbf_experiment.m" /* pName */
};

static emlrtDCInfo d_emlrtDCI = {
    35,                           /* lineNo */
    23,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "segment_track"
    "ing_p2s\\build_robot_cbf_experiment.m", /* pName */
    1                                        /* checkKind */
};

static emlrtDCInfo e_emlrtDCI = {
    35,                           /* lineNo */
    23,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "segment_track"
    "ing_p2s\\build_robot_cbf_experiment.m", /* pName */
    4                                        /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = {
    1,                            /* iFirst */
    50,                           /* iLast */
    21,                           /* lineNo */
    14,                           /* colNo */
    "W",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "segment_track"
    "ing_p2s\\build_robot_cbf_experiment.m", /* pName */
    0                                        /* checkKind */
};

static emlrtDCInfo f_emlrtDCI = {
    21,                           /* lineNo */
    14,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "segment_track"
    "ing_p2s\\build_robot_cbf_experiment.m", /* pName */
    1                                        /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    46,                           /* lineNo */
    17,                           /* colNo */
    "u",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "segment_track"
    "ing_p2s\\build_robot_cbf_experiment.m", /* pName */
    0                                        /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    47,                           /* lineNo */
    17,                           /* colNo */
    "u",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "segment_track"
    "ing_p2s\\build_robot_cbf_experiment.m", /* pName */
    0                                        /* checkKind */
};

static emlrtDCInfo g_emlrtDCI = {
    120,                          /* lineNo */
    5,                            /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "segment_track"
    "ing_p2s\\build_robot_cbf_experiment.m", /* pName */
    1                                        /* checkKind */
};

static emlrtDCInfo h_emlrtDCI = {
    120,                          /* lineNo */
    5,                            /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "segment_track"
    "ing_p2s\\build_robot_cbf_experiment.m", /* pName */
    4                                        /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    164,                          /* lineNo */
    17,                           /* colNo */
    "u",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "segment_track"
    "ing_p2s\\build_robot_cbf_experiment.m", /* pName */
    0                                        /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    164,                          /* lineNo */
    39,                           /* colNo */
    "u",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "segment_track"
    "ing_p2s\\build_robot_cbf_experiment.m", /* pName */
    0                                        /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = {
    1,                            /* iFirst */
    50,                           /* iLast */
    33,                           /* lineNo */
    12,                           /* colNo */
    "W",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "segment_track"
    "ing_p2s\\build_robot_cbf_experiment.m", /* pName */
    0                                        /* checkKind */
};

static emlrtDCInfo i_emlrtDCI = {
    33,                           /* lineNo */
    12,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "segment_track"
    "ing_p2s\\build_robot_cbf_experiment.m", /* pName */
    1                                        /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = {
    1,                            /* iFirst */
    50,                           /* iLast */
    32,                           /* lineNo */
    12,                           /* colNo */
    "W",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "segment_track"
    "ing_p2s\\build_robot_cbf_experiment.m", /* pName */
    0                                        /* checkKind */
};

static emlrtDCInfo j_emlrtDCI = {
    32,                           /* lineNo */
    12,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "segment_track"
    "ing_p2s\\build_robot_cbf_experiment.m", /* pName */
    1                                        /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = {
    1,                            /* iFirst */
    50,                           /* iLast */
    31,                           /* lineNo */
    12,                           /* colNo */
    "W",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "segment_track"
    "ing_p2s\\build_robot_cbf_experiment.m", /* pName */
    0                                        /* checkKind */
};

static emlrtDCInfo k_emlrtDCI = {
    31,                           /* lineNo */
    12,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "segment_track"
    "ing_p2s\\build_robot_cbf_experiment.m", /* pName */
    1                                        /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = {
    1,                            /* iFirst */
    50,                           /* iLast */
    23,                           /* lineNo */
    12,                           /* colNo */
    "W",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "segment_track"
    "ing_p2s\\build_robot_cbf_experiment.m", /* pName */
    0                                        /* checkKind */
};

static emlrtDCInfo l_emlrtDCI = {
    23,                           /* lineNo */
    12,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "segment_track"
    "ing_p2s\\build_robot_cbf_experiment.m", /* pName */
    1                                        /* checkKind */
};

static emlrtBCInfo r_emlrtBCI = {
    1,                            /* iFirst */
    50,                           /* iLast */
    22,                           /* lineNo */
    12,                           /* colNo */
    "W",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "segment_track"
    "ing_p2s\\build_robot_cbf_experiment.m", /* pName */
    0                                        /* checkKind */
};

static emlrtDCInfo m_emlrtDCI = {
    22,                           /* lineNo */
    12,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "segment_track"
    "ing_p2s\\build_robot_cbf_experiment.m", /* pName */
    1                                        /* checkKind */
};

static emlrtRTEInfo c_emlrtRTEI = {
    35,                           /* lineNo */
    5,                            /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "segment_track"
    "ing_p2s\\build_robot_cbf_experiment.m" /* pName */
};

static emlrtRTEInfo d_emlrtRTEI = {
    120,                          /* lineNo */
    5,                            /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "segment_track"
    "ing_p2s\\build_robot_cbf_experiment.m" /* pName */
};

/* Function Definitions */
void wrapper_grad(const emlrtStack *sp, const real_T u[50],
                  const real_T params[30], real_T grad[50])
{
  __m128d b_r1;
  __m128d b_r2;
  __m128d r;
  __m128d r4;
  __m128d r7;
  __m128d r8;
  emlrtStack st;
  emxArray_real_T *X_hist;
  emxArray_real_T *grad_U;
  real_T grad_smooth[50];
  real_T dv[9];
  real_T b_Ts[6];
  real_T grad_x_next_cbf[3];
  real_T x_k[3];
  real_T x_next[3];
  real_T a__1[2];
  real_T gP_seg0_r1[2];
  real_T gP_seg0_xs[2];
  real_T gP_seg1_r1[2];
  real_T gP_seg1_r2[2];
  real_T gP_seg2_r2[2];
  real_T gP_seg2_r3[2];
  real_T gP_seg3_r3[2];
  real_T grad_xs[2];
  real_T r1[2];
  real_T r2[2];
  real_T r3[2];
  real_T xs[2];
  real_T Ts;
  real_T b_xs_tmp;
  real_T cost_dir_tmp;
  real_T cost_dir_tmp_tmp;
  real_T d;
  real_T d1;
  real_T eta_safe;
  real_T g_corridor;
  real_T gamma_safe;
  real_T grad_us_idx_0;
  real_T grad_us_idx_1;
  real_T r1_tmp;
  real_T v_s;
  real_T w_s;
  real_T xs_tmp;
  real_T *X_hist_data;
  real_T *grad_U_data;
  int32_T b_loop_ub;
  int32_T cost_dir_tmp_tmp_tmp;
  int32_T i;
  int32_T i1;
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
  /*  Limites [xmin, xmax, ymin, ymax] dos 4 blocos */
  d = 2.0 * params[7];
  if (d < 1.0) {
    i = 0;
  } else {
    if (d != (int32_T)muDoubleScalarFloor(d)) {
      emlrtIntegerCheckR2012b(d, &f_emlrtDCI, &st);
    }
    if (((int32_T)d < 1) || ((int32_T)d > 50)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, 50, &i_emlrtBCI, &st);
    }
    i = (int32_T)d;
  }
  if (d + 1.0 != (int32_T)muDoubleScalarFloor(d + 1.0)) {
    emlrtIntegerCheckR2012b(d + 1.0, &m_emlrtDCI, &st);
  }
  if (((int8_T)(d + 1.0) < 1) || ((int8_T)(d + 1.0) > 50)) {
    emlrtDynamicBoundsCheckR2012b((int8_T)(d + 1.0), 1, 50, &r_emlrtBCI, &st);
  }
  if ((d + 1.0) + 1.0 != (int32_T)muDoubleScalarFloor((d + 1.0) + 1.0)) {
    emlrtIntegerCheckR2012b((d + 1.0) + 1.0, &m_emlrtDCI, &st);
  }
  if (((int8_T)((d + 1.0) + 1.0) < 1) || ((int8_T)((d + 1.0) + 1.0) > 50)) {
    emlrtDynamicBoundsCheckR2012b((int8_T)((d + 1.0) + 1.0), 1, 50, &r_emlrtBCI,
                                  &st);
  }
  xs_tmp = u[(int8_T)(d + 1.0) - 1];
  xs[0] = xs_tmp;
  b_xs_tmp = u[(int8_T)((d + 1.0) + 1.0) - 1];
  xs[1] = b_xs_tmp;
  if (d + 3.0 != (int32_T)muDoubleScalarFloor(d + 3.0)) {
    emlrtIntegerCheckR2012b(d + 3.0, &l_emlrtDCI, &st);
  }
  if (((int8_T)(d + 3.0) < 1) || ((int8_T)(d + 3.0) > 50)) {
    emlrtDynamicBoundsCheckR2012b((int8_T)(d + 3.0), 1, 50, &q_emlrtBCI, &st);
  }
  if ((d + 3.0) + 1.0 != (int32_T)muDoubleScalarFloor((d + 3.0) + 1.0)) {
    emlrtIntegerCheckR2012b((d + 3.0) + 1.0, &l_emlrtDCI, &st);
  }
  if (((int8_T)((d + 3.0) + 1.0) < 1) || ((int8_T)((d + 3.0) + 1.0) > 50)) {
    emlrtDynamicBoundsCheckR2012b((int8_T)((d + 3.0) + 1.0), 1, 50, &q_emlrtBCI,
                                  &st);
  }
  v_s = u[(int8_T)(d + 3.0) - 1];
  w_s = u[(int8_T)((d + 3.0) + 1.0) - 1];
  if (d + 5.0 != (int32_T)muDoubleScalarFloor(d + 5.0)) {
    emlrtIntegerCheckR2012b(d + 5.0, &k_emlrtDCI, &st);
  }
  if (((int8_T)(d + 5.0) < 1) || ((int8_T)(d + 5.0) > 50)) {
    emlrtDynamicBoundsCheckR2012b((int8_T)(d + 5.0), 1, 50, &p_emlrtBCI, &st);
  }
  if ((d + 5.0) + 1.0 != (int32_T)muDoubleScalarFloor((d + 5.0) + 1.0)) {
    emlrtIntegerCheckR2012b((d + 5.0) + 1.0, &k_emlrtDCI, &st);
  }
  if (((int8_T)((d + 5.0) + 1.0) < 1) || ((int8_T)((d + 5.0) + 1.0) > 50)) {
    emlrtDynamicBoundsCheckR2012b((int8_T)((d + 5.0) + 1.0), 1, 50, &p_emlrtBCI,
                                  &st);
  }
  grad_us_idx_1 = u[(int8_T)(d + 5.0) - 1];
  r1[0] = grad_us_idx_1;
  r1_tmp = u[(int8_T)((d + 5.0) + 1.0) - 1];
  r1[1] = r1_tmp;
  if (d + 7.0 != (int32_T)muDoubleScalarFloor(d + 7.0)) {
    emlrtIntegerCheckR2012b(d + 7.0, &j_emlrtDCI, &st);
  }
  if (((int8_T)(d + 7.0) < 1) || ((int8_T)(d + 7.0) > 50)) {
    emlrtDynamicBoundsCheckR2012b((int8_T)(d + 7.0), 1, 50, &o_emlrtBCI, &st);
  }
  if ((d + 7.0) + 1.0 != (int32_T)muDoubleScalarFloor((d + 7.0) + 1.0)) {
    emlrtIntegerCheckR2012b((d + 7.0) + 1.0, &j_emlrtDCI, &st);
  }
  if (((int8_T)((d + 7.0) + 1.0) < 1) || ((int8_T)((d + 7.0) + 1.0) > 50)) {
    emlrtDynamicBoundsCheckR2012b((int8_T)((d + 7.0) + 1.0), 1, 50, &o_emlrtBCI,
                                  &st);
  }
  r2[0] = u[(int8_T)(d + 7.0) - 1];
  r2[1] = u[(int8_T)((d + 7.0) + 1.0) - 1];
  if (d + 9.0 != (int32_T)muDoubleScalarFloor(d + 9.0)) {
    emlrtIntegerCheckR2012b(d + 9.0, &i_emlrtDCI, &st);
  }
  if (((int8_T)(d + 9.0) < 1) || ((int8_T)(d + 9.0) > 50)) {
    emlrtDynamicBoundsCheckR2012b((int8_T)(d + 9.0), 1, 50, &n_emlrtBCI, &st);
  }
  if ((d + 9.0) + 1.0 != (int32_T)muDoubleScalarFloor((d + 9.0) + 1.0)) {
    emlrtIntegerCheckR2012b((d + 9.0) + 1.0, &i_emlrtDCI, &st);
  }
  if (((int8_T)((d + 9.0) + 1.0) < 1) || ((int8_T)((d + 9.0) + 1.0) > 50)) {
    emlrtDynamicBoundsCheckR2012b((int8_T)((d + 9.0) + 1.0), 1, 50, &n_emlrtBCI,
                                  &st);
  }
  r3[0] = u[(int8_T)(d + 9.0) - 1];
  r3[1] = u[(int8_T)((d + 9.0) + 1.0) - 1];
  if (!(params[7] + 1.0 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(params[7] + 1.0, &e_emlrtDCI, &st);
  }
  cost_dir_tmp_tmp = (int32_T)muDoubleScalarFloor(params[7] + 1.0);
  if (params[7] + 1.0 != cost_dir_tmp_tmp) {
    emlrtIntegerCheckR2012b(params[7] + 1.0, &d_emlrtDCI, &st);
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
    emlrtDynamicBoundsCheckR2012b(1, 1, (int32_T)(params[7] + 1.0), &h_emlrtBCI,
                                  &st);
  }
  X_hist_data[0] = params[0];
  X_hist_data[1] = params[1];
  X_hist_data[2] = params[2];
  /*  Parâmetro h para a Generalized P2S-HSD */
  /*  ===================================================================== */
  /*  FORWARD PASS (Dinâmica com CBF - Ponto a Ponto Suavizado) */
  /*  ===================================================================== */
  b_loop_ub = (int32_T)params[7];
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, params[7], mxDOUBLE_CLASS,
                                (int32_T)params[7], &b_emlrtRTEI, &st);
  for (n = 0; n < b_loop_ub; n++) {
    loop_ub = (int32_T)(((uint32_T)n << 1) + 1U);
    if ((loop_ub < 1) || (loop_ub > i)) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i, &j_emlrtBCI, &st);
    }
    cost_dir_tmp_tmp_tmp = (n << 1) + 2;
    if ((cost_dir_tmp_tmp_tmp < 1) || (cost_dir_tmp_tmp_tmp > i)) {
      emlrtDynamicBoundsCheckR2012b(cost_dir_tmp_tmp_tmp, 1, i, &k_emlrtBCI,
                                    &st);
    }
    calc_point_p2s_penalty(&x_k[0], &params[10], a__1);
    g_corridor = Ts * u[loop_ub - 1];
    x_next[0] = x_k[0] + g_corridor * muDoubleScalarCos(x_k[2]);
    x_next[1] = x_k[1] + g_corridor * muDoubleScalarSin(x_k[2]);
    x_next[2] = x_k[2] + Ts * u[cost_dir_tmp_tmp_tmp - 1];
    calc_point_p2s_penalty(&x_next[0], &params[10], a__1);
    x_k[0] = x_next[0];
    x_k[1] = x_next[1];
    x_k[2] = x_next[2];
    if (((int32_T)((uint32_T)n + 2U) < 1) ||
        ((int32_T)((uint32_T)n + 2U) > X_hist->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)n + 2U), 1,
                                    X_hist->size[1], &g_emlrtBCI, &st);
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
  i1 = X_hist->size[1];
  if (params[7] + 1.0 != cost_dir_tmp_tmp) {
    emlrtIntegerCheckR2012b(params[7] + 1.0, &c_emlrtDCI, &st);
  }
  if (((int32_T)(params[7] + 1.0) < 1) ||
      ((int32_T)(params[7] + 1.0) > X_hist->size[1])) {
    emlrtDynamicBoundsCheckR2012b((int32_T)(params[7] + 1.0), 1,
                                  X_hist->size[1], &f_emlrtBCI, &st);
  }
  /*  ===================================================================== */
  /*  CUSTO DE ALINHAMENTO DIRECIONAL (Look-ahead xs -> r1) */
  /*  ===================================================================== */
  /*  Peso do alinhamento direcional */
  /*  Recompensa o robô por apontar a frente na direção do trecho xs -> r1 */
  cost_dir_tmp_tmp_tmp = 3 * ((int32_T)(params[7] + 1.0) - 1);
  cost_dir_tmp_tmp = X_hist_data[cost_dir_tmp_tmp_tmp + 2];
  cost_dir_tmp = muDoubleScalarSin(cost_dir_tmp_tmp);
  g_corridor = muDoubleScalarCos(cost_dir_tmp_tmp);
  /*  ===================================================================== */
  /*  GEOFENCE DE SEGMENTOS (Contenção Convexa Suavizada) */
  /*  ===================================================================== */
  /*  Segmento 1: xs até r1 */
  calc_segment_p2s_penalty(xs, r1, &params[10], gP_seg0_xs, gP_seg0_r1);
  /*  Segmento 2: r1 até r2 */
  calc_segment_p2s_penalty(r1, r2, &params[10], gP_seg1_r1, gP_seg1_r2);
  /*  Segmento 3: r2 até r3 */
  calc_segment_p2s_penalty(r2, r3, &params[10], gP_seg2_r2, gP_seg2_r3);
  /*  Segmento 4: r3 até r4 (x_ref) */
  calc_segment_p2s_penalty(r3, &params[3], &params[10], gP_seg3_r3, a__1);
  memset(&grad[0], 0, 50U * sizeof(real_T));
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
  __m128d r5;
  __m128d r6;
  /*  (Inicialização existente de p_n) */
  x_k[0] = 0.0;
  x_k[1] = 0.0;
  /*  --- NOVO: Gradiente da orientação terminal (theta_N) --- */
  x_k[2] = 0.0 - 0.0 * (-cost_dir_tmp * (grad_us_idx_1 - xs_tmp) +
                        g_corridor * (r1_tmp - b_xs_tmp));
  /*  (Inicialização existente de grad_xs e grad_r1) */
  /*  ---> LINHA QUE ESTAVA FALTANDO (Derivada da mola para xs) <--- */
  r = _mm_loadu_pd(&X_hist_data[cost_dir_tmp_tmp_tmp]);
  b_r1 = _mm_loadu_pd(&xs[0]);
  r = _mm_mul_pd(_mm_set1_pd(2.0 * params[26]), _mm_sub_pd(r, b_r1));
  _mm_storeu_pd(&x_k[0], r);
  b_r2 = _mm_loadu_pd(&r1[0]);
  b_r3 = _mm_set1_pd(2.0 * params[29]);
  r4 = _mm_set1_pd(-1.0);
  _mm_storeu_pd(
      &grad_xs[0],
      _mm_sub_pd(_mm_mul_pd(r, r4), _mm_mul_pd(b_r3, _mm_sub_pd(b_r2, b_r1))));
  r = _mm_loadu_pd(&r2[0]);
  r5 = _mm_set1_pd(2.0);
  _mm_storeu_pd(
      &xs[0],
      _mm_mul_pd(b_r3, _mm_sub_pd(_mm_sub_pd(_mm_mul_pd(r5, b_r2), b_r1), r)));
  /*  --- NOVO: Gradientes distribuídos para xs e r1 --- */
  g_corridor *= 0.0;
  grad_xs[0] += g_corridor;
  cost_dir_tmp_tmp = 0.0 * cost_dir_tmp;
  grad_xs[1] += cost_dir_tmp_tmp;
  xs[0] -= g_corridor;
  xs[1] -= cost_dir_tmp_tmp;
  /*  O restante continua igual... */
  cost_dir_tmp_tmp = 2.0 * params[27] * (params[8] * params[8]);
  grad_us_idx_0 = cost_dir_tmp_tmp * v_s;
  grad_us_idx_1 = cost_dir_tmp_tmp * w_s;
  /*  Acumulação Incondicional dos Gradientes de Segmento */
  /*  Cada ponto r intermediário acumula gradiente das duas retas conectadas a
   * ele */
  r = _mm_loadu_pd(&gP_seg0_xs[0]);
  b_r2 = _mm_loadu_pd(&grad_xs[0]);
  r6 = _mm_set1_pd(params[28]);
  _mm_storeu_pd(&grad_xs[0], _mm_add_pd(b_r2, _mm_mul_pd(r6, r)));
  r = _mm_loadu_pd(&gP_seg0_r1[0]);
  b_r2 = _mm_loadu_pd(&gP_seg1_r1[0]);
  b_r1 = _mm_loadu_pd(&xs[0]);
  _mm_storeu_pd(&xs[0], _mm_add_pd(b_r1, _mm_mul_pd(r6, _mm_add_pd(r, b_r2))));
  r7 = _mm_loadu_pd(&r2[0]);
  r = _mm_loadu_pd(&r1[0]);
  r8 = _mm_loadu_pd(&r3[0]);
  b_r2 = _mm_loadu_pd(&gP_seg1_r2[0]);
  b_r1 = _mm_loadu_pd(&gP_seg2_r2[0]);
  _mm_storeu_pd(
      &r1[0],
      _mm_add_pd(
          _mm_mul_pd(b_r3, _mm_sub_pd(_mm_sub_pd(_mm_mul_pd(r5, r7), r), r8)),
          _mm_mul_pd(r6, _mm_add_pd(b_r2, b_r1))));
  r = _mm_loadu_pd(&gP_seg2_r3[0]);
  b_r2 = _mm_loadu_pd(&gP_seg3_r3[0]);
  _mm_storeu_pd(
      &r3[0],
      _mm_add_pd(_mm_mul_pd(b_r3, _mm_sub_pd(_mm_sub_pd(_mm_mul_pd(r5, r8), r7),
                                             _mm_loadu_pd(&params[3]))),
                 _mm_mul_pd(r6, _mm_add_pd(r, b_r2))));
  b_loop_ub = (int32_T) - ((-1.0 - params[7]) + 1.0);
  emlrtForLoopVectorCheckR2021a(params[7], -1.0, 1.0, mxDOUBLE_CLASS,
                                (int32_T) - ((-1.0 - params[7]) + 1.0),
                                &emlrtRTEI, &st);
  if ((int32_T) - ((-1.0 - params[7]) + 1.0) - 1 >= 0) {
    b_Ts[4] = 0.0;
    b_Ts[1] = 0.0;
    b_Ts[3] = 0.0;
    b_Ts[5] = params[8];
  }
  if (b_loop_ub - 1 >= 0) {
    dv[0] = 1.0;
    dv[1] = 0.0;
    dv[3] = 0.0;
    dv[4] = 1.0;
    dv[6] = 0.0;
    dv[7] = 0.0;
    dv[8] = 1.0;
  }
  for (n = 0; n < b_loop_ub; n++) {
    real_T b_grad_xs_tmp;
    real_T grad_us_idx_0_tmp;
    real_T grad_us_idx_1_tmp;
    real_T grad_xs_tmp;
    real_T v_n;
    uint32_T b_u;
    uint32_T u1;
    r1_tmp = params[7] - (real_T)n;
    if (r1_tmp != (int32_T)muDoubleScalarFloor(r1_tmp)) {
      emlrtIntegerCheckR2012b(r1_tmp, &b_emlrtDCI, &st);
    }
    if (((int32_T)r1_tmp < 1) || ((int32_T)r1_tmp > i1)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)r1_tmp, 1, i1, &e_emlrtBCI, &st);
    }
    if (((int32_T)(r1_tmp + 1.0) < 1) || ((int32_T)(r1_tmp + 1.0) > i1)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(r1_tmp + 1.0), 1, i1, &d_emlrtBCI,
                                    &st);
    }
    b_u = (uint32_T)((int32_T)r1_tmp - 1) << 1;
    if (((int32_T)(b_u + 1U) < 1) || ((int32_T)(b_u + 1U) > i)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_u + 1U), 1, i, &l_emlrtBCI,
                                    &st);
    }
    v_n = u[(int32_T)b_u];
    if (((int32_T)(b_u + 2U) < 1) || ((int32_T)(b_u + 2U) > i)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_u + 2U), 1, i, &m_emlrtBCI,
                                    &st);
    }
    loop_ub = 3 * ((int32_T)r1_tmp - 1);
    grad_xs_tmp = X_hist_data[loop_ub] - xs_tmp;
    grad_xs[0] -= grad_xs_tmp;
    b_grad_xs_tmp = X_hist_data[loop_ub + 1] - b_xs_tmp;
    grad_xs[1] -= b_grad_xs_tmp;
    grad_us_idx_0_tmp = 0.1 * (v_n - v_s);
    grad_us_idx_0 -= grad_us_idx_0_tmp;
    grad_us_idx_1_tmp = 0.02 * (u[(int32_T)b_u + 1] - w_s);
    grad_us_idx_1 -= grad_us_idx_1_tmp;
    /*  Avaliação Suavizada Ponto a Ponto para CBF */
    cost_dir_tmp_tmp =
        calc_point_p2s_penalty(&X_hist_data[loop_ub], &params[10], a__1);
    cost_dir_tmp = calc_point_p2s_penalty(&X_hist_data[3 * (int32_T)r1_tmp],
                                          &params[10], gP_seg0_xs);
    g_corridor = (1.0 - gamma_safe) * -cost_dir_tmp_tmp - (-cost_dir_tmp);
    x_next[0] = 0.0;
    grad_x_next_cbf[0] = 0.0;
    x_next[1] = 0.0;
    grad_x_next_cbf[1] = 0.0;
    x_next[2] = 0.0;
    grad_x_next_cbf[2] = 0.0;
    if (g_corridor > 0.0) {
      r = _mm_loadu_pd(&a__1[0]);
      b_r2 = _mm_set1_pd(2.0 * eta_safe * g_corridor);
      _mm_storeu_pd(&x_next[0],
                    _mm_mul_pd(b_r2, _mm_mul_pd(_mm_set1_pd(1.0 - gamma_safe),
                                                _mm_mul_pd(r, r4))));
      r = _mm_loadu_pd(&gP_seg0_xs[0]);
      _mm_storeu_pd(&grad_x_next_cbf[0], _mm_mul_pd(b_r2, r));
    }
    cost_dir_tmp_tmp = X_hist_data[loop_ub + 2];
    cost_dir_tmp = muDoubleScalarCos(cost_dir_tmp_tmp);
    cost_dir_tmp_tmp = muDoubleScalarSin(cost_dir_tmp_tmp);
    grad_x_next_cbf[0] += x_k[0];
    grad_x_next_cbf[1] += x_k[1];
    grad_x_next_cbf[2] += x_k[2];
    dv[2] = -Ts * v_n * cost_dir_tmp_tmp;
    dv[5] = Ts * v_n * cost_dir_tmp;
    memset(&x_k[0], 0, 3U * sizeof(real_T));
    r = _mm_loadu_pd(&dv[0]);
    b_r2 = _mm_loadu_pd(&x_k[0]);
    b_r1 = _mm_set1_pd(grad_x_next_cbf[0]);
    _mm_storeu_pd(&x_k[0], _mm_add_pd(b_r2, _mm_mul_pd(r, b_r1)));
    x_k[2] += grad_x_next_cbf[0] * dv[2];
    r = _mm_loadu_pd(&dv[3]);
    b_r2 = _mm_loadu_pd(&x_k[0]);
    r7 = _mm_set1_pd(grad_x_next_cbf[1]);
    _mm_storeu_pd(&x_k[0], _mm_add_pd(b_r2, _mm_mul_pd(r, r7)));
    x_k[2] += grad_x_next_cbf[1] * dv[5];
    r = _mm_loadu_pd(&dv[6]);
    b_r2 = _mm_loadu_pd(&x_k[0]);
    r8 = _mm_set1_pd(grad_x_next_cbf[2]);
    _mm_storeu_pd(&x_k[0], _mm_add_pd(b_r2, _mm_mul_pd(r, r8)));
    x_k[2] += grad_x_next_cbf[2];
    x_next[0] += grad_xs_tmp;
    x_next[1] += b_grad_xs_tmp;
    r = _mm_loadu_pd(&x_k[0]);
    b_r2 = _mm_loadu_pd(&x_next[0]);
    _mm_storeu_pd(&x_k[0], _mm_add_pd(r, b_r2));
    x_k[2] += x_next[2];
    u1 = (uint32_T)r1_tmp << 1;
    if (b_u + 1U > u1) {
      cost_dir_tmp_tmp_tmp = 0;
      loop_ub = 0;
    } else {
      if (((int32_T)(b_u + 1U) < 1) ||
          ((int32_T)(b_u + 1U) > grad_U->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(b_u + 1U), 1, grad_U->size[0],
                                      &c_emlrtBCI, &st);
      }
      cost_dir_tmp_tmp_tmp = (int32_T)b_u;
      if (((int32_T)u1 < 1) || ((int32_T)u1 > grad_U->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)u1, 1, grad_U->size[0],
                                      &b_emlrtBCI, &st);
      }
      loop_ub = (int32_T)u1;
    }
    loop_ub -= cost_dir_tmp_tmp_tmp;
    if (loop_ub != 2) {
      emlrtSubAssignSizeCheck1dR2017a(loop_ub, 2, &b_emlrtECI, &st);
    }
    b_Ts[0] = Ts * cost_dir_tmp;
    b_Ts[2] = Ts * cost_dir_tmp_tmp;
    memset(&r2[0], 0, sizeof(real_T) << 1);
    r = _mm_loadu_pd(&b_Ts[0]);
    b_r2 = _mm_loadu_pd(&r2[0]);
    _mm_storeu_pd(&r2[0], _mm_add_pd(b_r2, _mm_mul_pd(r, b_r1)));
    r = _mm_loadu_pd(&b_Ts[2]);
    b_r2 = _mm_loadu_pd(&r2[0]);
    _mm_storeu_pd(&r2[0], _mm_add_pd(b_r2, _mm_mul_pd(r, r7)));
    r = _mm_loadu_pd(&b_Ts[4]);
    b_r2 = _mm_loadu_pd(&r2[0]);
    _mm_storeu_pd(&r2[0], _mm_add_pd(b_r2, _mm_mul_pd(r, r8)));
    a__1[0] = grad_us_idx_0_tmp;
    a__1[1] = grad_us_idx_1_tmp;
    r = _mm_loadu_pd(&r2[0]);
    b_r2 = _mm_loadu_pd(&a__1[0]);
    _mm_storeu_pd(&grad_U_data[cost_dir_tmp_tmp_tmp], _mm_add_pd(r, b_r2));
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }
  emxFree_real_T(&st, &X_hist);
  if (d < 1.0) {
    loop_ub = 0;
  } else {
    if (d != d1) {
      emlrtIntegerCheckR2012b(d, &emlrtDCI, &st);
    }
    if (((int32_T)d < 1) || ((int32_T)d > 50)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, 50, &emlrtBCI, &st);
    }
    loop_ub = (int32_T)d;
  }
  if (loop_ub != grad_U->size[0]) {
    emlrtSubAssignSizeCheck1dR2017a(loop_ub, grad_U->size[0], &emlrtECI, &st);
  }
  for (n = 0; n < loop_ub; n++) {
    grad[n] = grad_U_data[n];
  }
  emxFree_real_T(&st, &grad_U);
  grad[(int8_T)(d + 1.0) - 1] = grad_xs[0];
  grad[(int8_T)((d + 1.0) + 1.0) - 1] = grad_xs[1];
  grad[(int8_T)(d + 3.0) - 1] = grad_us_idx_0;
  grad[(int8_T)((d + 3.0) + 1.0) - 1] = grad_us_idx_1;
  grad[(int8_T)(d + 5.0) - 1] = xs[0];
  grad[(int8_T)((d + 5.0) + 1.0) - 1] = xs[1];
  grad[(int8_T)(d + 7.0) - 1] = r1[0];
  grad[(int8_T)((d + 7.0) + 1.0) - 1] = r1[1];
  grad[(int8_T)(d + 9.0) - 1] = r3[0];
  grad[(int8_T)((d + 9.0) + 1.0) - 1] = r3[1];
  memset(&grad_smooth[0], 0, 50U * sizeof(real_T));
  /*  Calcula as derivadas parciais  */
  for (n = 0; n < 24; n++) {
    /*  Derivada em relação a v */
    loop_ub = (n + 1) << 1;
    /*  v_{i+1} - v_i */
    cost_dir_tmp_tmp = 0.4 * (u[loop_ub] - u[loop_ub - 2]);
    grad_smooth[loop_ub - 2] -= cost_dir_tmp_tmp;
    grad_smooth[loop_ub] += cost_dir_tmp_tmp;
    /*  Derivada em relação a w */
    /*  w_{i+1} - w_i */
    cost_dir_tmp_tmp = 0.4 * (u[loop_ub + 1] - u[loop_ub - 1]);
    grad_smooth[loop_ub - 1] -= cost_dir_tmp_tmp;
    grad_smooth[loop_ub + 1] += cost_dir_tmp_tmp;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
  /*  5. Gradiente total */
  for (n = 0; n <= 48; n += 2) {
    r = _mm_loadu_pd(&grad[n]);
    b_r2 = _mm_loadu_pd(&grad_smooth[n]);
    _mm_storeu_pd(&grad[n], _mm_add_pd(r, b_r2));
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

/* End of code generation (wrapper_grad.c) */
