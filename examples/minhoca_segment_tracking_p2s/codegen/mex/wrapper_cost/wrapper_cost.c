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
#include "wrapper_cost_data.h"
#include "wrapper_cost_emxutil.h"
#include "wrapper_cost_types.h"
#include "mwmathutil.h"
#include <emmintrin.h>

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = {
    3,              /* lineNo */
    "wrapper_cost", /* fcnName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\wrapper_cost.m" /* pathName */
};

static emlrtRSInfo b_emlrtRSI = {
    50,                           /* lineNo */
    "build_robot_cbf_experiment", /* fcnName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m" /* pathName */
};

static emlrtRSInfo c_emlrtRSI = {
    58,                           /* lineNo */
    "build_robot_cbf_experiment", /* fcnName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m" /* pathName */
};

static emlrtRSInfo d_emlrtRSI = {
    62,                           /* lineNo */
    "build_robot_cbf_experiment", /* fcnName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m" /* pathName */
};

static emlrtRSInfo e_emlrtRSI = {
    64,                           /* lineNo */
    "build_robot_cbf_experiment", /* fcnName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m" /* pathName */
};

static emlrtRSInfo f_emlrtRSI = {
    78,                           /* lineNo */
    "build_robot_cbf_experiment", /* fcnName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m" /* pathName */
};

static emlrtRSInfo g_emlrtRSI = {
    92,                           /* lineNo */
    "build_robot_cbf_experiment", /* fcnName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m" /* pathName */
};

static emlrtRSInfo h_emlrtRSI = {
    96,                           /* lineNo */
    "build_robot_cbf_experiment", /* fcnName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m" /* pathName */
};

static emlrtRSInfo i_emlrtRSI = {
    100,                          /* lineNo */
    "build_robot_cbf_experiment", /* fcnName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m" /* pathName */
};

static emlrtRSInfo j_emlrtRSI = {
    104,                          /* lineNo */
    "build_robot_cbf_experiment", /* fcnName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m" /* pathName */
};

static emlrtRSInfo o_emlrtRSI = {
    285,                      /* lineNo */
    "calc_point_p2s_penalty", /* fcnName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m" /* pathName */
};

static emlrtRSInfo p_emlrtRSI = {
    286,                      /* lineNo */
    "calc_point_p2s_penalty", /* fcnName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m" /* pathName */
};

static emlrtRSInfo q_emlrtRSI = {
    287,                      /* lineNo */
    "calc_point_p2s_penalty", /* fcnName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m" /* pathName */
};

static emlrtBCInfo emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    76,                           /* lineNo */
    21,                           /* colNo */
    "X_hist",                     /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m", /* pName */
    0                                             /* checkKind */
};

static emlrtDCInfo emlrtDCI = {
    76,                           /* lineNo */
    21,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m", /* pName */
    1                                             /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    68,                           /* lineNo */
    19,                           /* colNo */
    "X_hist",                     /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m", /* pName */
    0                                             /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    37,                           /* lineNo */
    15,                           /* colNo */
    "X_hist",                     /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m", /* pName */
    0                                             /* checkKind */
};

static emlrtRTEInfo emlrtRTEI = {
    46,                           /* lineNo */
    13,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m" /* pName */
};

static emlrtBCInfo d_emlrtBCI = {
    1,                            /* iFirst */
    50,                           /* iLast */
    22,                           /* lineNo */
    14,                           /* colNo */
    "W",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m", /* pName */
    0                                             /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = {
    22,                           /* lineNo */
    14,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m", /* pName */
    1                                             /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = {
    36,                           /* lineNo */
    23,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m", /* pName */
    1                                             /* checkKind */
};

static emlrtDCInfo d_emlrtDCI = {
    36,                           /* lineNo */
    23,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m", /* pName */
    4                                             /* checkKind */
};

static emlrtDCInfo e_emlrtDCI = {
    36,                           /* lineNo */
    5,                            /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m", /* pName */
    1                                             /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    47,                           /* lineNo */
    17,                           /* colNo */
    "u",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m", /* pName */
    0                                             /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    48,                           /* lineNo */
    17,                           /* colNo */
    "u",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m", /* pName */
    0                                             /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = {
    1,                            /* iFirst */
    50,                           /* iLast */
    34,                           /* lineNo */
    12,                           /* colNo */
    "W",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m", /* pName */
    0                                             /* checkKind */
};

static emlrtDCInfo f_emlrtDCI = {
    34,                           /* lineNo */
    12,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m", /* pName */
    1                                             /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = {
    1,                            /* iFirst */
    50,                           /* iLast */
    33,                           /* lineNo */
    12,                           /* colNo */
    "W",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m", /* pName */
    0                                             /* checkKind */
};

static emlrtDCInfo g_emlrtDCI = {
    33,                           /* lineNo */
    12,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m", /* pName */
    1                                             /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = {
    1,                            /* iFirst */
    50,                           /* iLast */
    32,                           /* lineNo */
    12,                           /* colNo */
    "W",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m", /* pName */
    0                                             /* checkKind */
};

static emlrtDCInfo h_emlrtDCI = {
    32,                           /* lineNo */
    12,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m", /* pName */
    1                                             /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = {
    1,                            /* iFirst */
    50,                           /* iLast */
    24,                           /* lineNo */
    12,                           /* colNo */
    "W",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m", /* pName */
    0                                             /* checkKind */
};

static emlrtDCInfo i_emlrtDCI = {
    24,                           /* lineNo */
    12,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m", /* pName */
    1                                             /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = {
    1,                            /* iFirst */
    50,                           /* iLast */
    23,                           /* lineNo */
    12,                           /* colNo */
    "W",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m", /* pName */
    0                                             /* checkKind */
};

static emlrtDCInfo j_emlrtDCI = {
    23,                           /* lineNo */
    12,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m", /* pName */
    1                                             /* checkKind */
};

static emlrtRTEInfo c_emlrtRTEI = {
    36,                           /* lineNo */
    5,                            /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m" /* pName */
};

/* Function Definitions */
real_T wrapper_cost(const emlrtStack *sp, const real_T u[50],
                    const real_T params[30])
{
  __m128d b_r1;
  __m128d r;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  emxArray_real_T *X_hist;
  real_T b_y1[24];
  real_T c_y[24];
  real_T d_y[24];
  real_T x_k[3];
  real_T x_next[3];
  real_T b_y[2];
  real_T g1[2];
  real_T gPa[2];
  real_T gPc[2];
  real_T gPg[2];
  real_T gPv[2];
  real_T r1[2];
  real_T r2[2];
  real_T r3[2];
  real_T xs[2];
  real_T y[2];
  real_T P_k;
  real_T Ts;
  real_T b_xs_tmp;
  real_T cost;
  real_T d;
  real_T idx_r1;
  real_T idx_r2;
  real_T idx_r3;
  real_T l_u;
  real_T tmp2;
  real_T v_s_tmp;
  real_T w_s_tmp;
  real_T work;
  real_T xs_tmp;
  real_T *X_hist_data;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  int32_T n;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  st.site = &emlrtRSI;
  /*  Desempacotamento limpo do vetor params (Tamanho: 30) */
  x_k[0] = params[0];
  x_k[1] = params[1];
  x_k[2] = params[2];
  Ts = params[8];
  /*  Limites [xmin, xmax, ymin, ymax] dos 4 blocos */
  d = 2.0 * params[7];
  if (d < 1.0) {
    i = 0;
  } else {
    if (d != (int32_T)muDoubleScalarFloor(d)) {
      emlrtIntegerCheckR2012b(d, &b_emlrtDCI, &st);
    }
    if (((int32_T)d < 1) || ((int32_T)d > 50)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, 50, &d_emlrtBCI, &st);
    }
    i = (int32_T)d;
  }
  d = 2.0 * params[7] + 1.0;
  if (d != (int32_T)muDoubleScalarFloor(d)) {
    emlrtIntegerCheckR2012b(d, &j_emlrtDCI, &st);
  }
  if (((int32_T)d < 1) || ((int32_T)d > 50)) {
    emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, 50, &k_emlrtBCI, &st);
  }
  xs_tmp = u[(int32_T)d - 1];
  xs[0] = xs_tmp;
  if (d + 1.0 != (int32_T)muDoubleScalarFloor(d + 1.0)) {
    emlrtIntegerCheckR2012b(d + 1.0, &j_emlrtDCI, &st);
  }
  if (((int32_T)(d + 1.0) < 1) || ((int32_T)(d + 1.0) > 50)) {
    emlrtDynamicBoundsCheckR2012b((int32_T)(d + 1.0), 1, 50, &k_emlrtBCI, &st);
  }
  b_xs_tmp = u[(int32_T)(d + 1.0) - 1];
  xs[1] = b_xs_tmp;
  d = 2.0 * params[7] + 3.0;
  if (d != (int32_T)muDoubleScalarFloor(d)) {
    emlrtIntegerCheckR2012b(d, &i_emlrtDCI, &st);
  }
  if (((int32_T)d < 1) || ((int32_T)d > 50)) {
    emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, 50, &j_emlrtBCI, &st);
  }
  if (d + 1.0 != (int32_T)muDoubleScalarFloor(d + 1.0)) {
    emlrtIntegerCheckR2012b(d + 1.0, &i_emlrtDCI, &st);
  }
  if (((int32_T)(d + 1.0) < 1) || ((int32_T)(d + 1.0) > 50)) {
    emlrtDynamicBoundsCheckR2012b((int32_T)(d + 1.0), 1, 50, &j_emlrtBCI, &st);
  }
  v_s_tmp = u[(int32_T)d - 1];
  w_s_tmp = u[(int32_T)(d + 1.0) - 1];
  idx_r1 = 2.0 * params[7] + 5.0;
  idx_r2 = 2.0 * params[7] + 7.0;
  idx_r3 = 2.0 * params[7] + 9.0;
  if (idx_r1 != (int32_T)muDoubleScalarFloor(idx_r1)) {
    emlrtIntegerCheckR2012b(idx_r1, &h_emlrtDCI, &st);
  }
  if (((int32_T)idx_r1 < 1) || ((int32_T)idx_r1 > 50)) {
    emlrtDynamicBoundsCheckR2012b((int32_T)idx_r1, 1, 50, &i_emlrtBCI, &st);
  }
  r1[0] = u[(int32_T)idx_r1 - 1];
  if (idx_r1 + 1.0 != (int32_T)muDoubleScalarFloor(idx_r1 + 1.0)) {
    emlrtIntegerCheckR2012b(idx_r1 + 1.0, &h_emlrtDCI, &st);
  }
  if (((int32_T)(idx_r1 + 1.0) < 1) || ((int32_T)(idx_r1 + 1.0) > 50)) {
    emlrtDynamicBoundsCheckR2012b((int32_T)(idx_r1 + 1.0), 1, 50, &i_emlrtBCI,
                                  &st);
  }
  r1[1] = u[(int32_T)(idx_r1 + 1.0) - 1];
  if (idx_r2 != (int32_T)muDoubleScalarFloor(idx_r2)) {
    emlrtIntegerCheckR2012b(idx_r2, &g_emlrtDCI, &st);
  }
  if (((int32_T)idx_r2 < 1) || ((int32_T)idx_r2 > 50)) {
    emlrtDynamicBoundsCheckR2012b((int32_T)idx_r2, 1, 50, &h_emlrtBCI, &st);
  }
  r2[0] = u[(int32_T)idx_r2 - 1];
  if (idx_r2 + 1.0 != (int32_T)muDoubleScalarFloor(idx_r2 + 1.0)) {
    emlrtIntegerCheckR2012b(idx_r2 + 1.0, &g_emlrtDCI, &st);
  }
  if (((int32_T)(idx_r2 + 1.0) < 1) || ((int32_T)(idx_r2 + 1.0) > 50)) {
    emlrtDynamicBoundsCheckR2012b((int32_T)(idx_r2 + 1.0), 1, 50, &h_emlrtBCI,
                                  &st);
  }
  r2[1] = u[(int32_T)(idx_r2 + 1.0) - 1];
  if (idx_r3 != (int32_T)muDoubleScalarFloor(idx_r3)) {
    emlrtIntegerCheckR2012b(idx_r3, &f_emlrtDCI, &st);
  }
  if (((int32_T)idx_r3 < 1) || ((int32_T)idx_r3 > 50)) {
    emlrtDynamicBoundsCheckR2012b((int32_T)idx_r3, 1, 50, &g_emlrtBCI, &st);
  }
  r3[0] = u[(int32_T)idx_r3 - 1];
  if (idx_r3 + 1.0 != (int32_T)muDoubleScalarFloor(idx_r3 + 1.0)) {
    emlrtIntegerCheckR2012b(idx_r3 + 1.0, &f_emlrtDCI, &st);
  }
  if (((int32_T)(idx_r3 + 1.0) < 1) || ((int32_T)(idx_r3 + 1.0) > 50)) {
    emlrtDynamicBoundsCheckR2012b((int32_T)(idx_r3 + 1.0), 1, 50, &g_emlrtBCI,
                                  &st);
  }
  r3[1] = u[(int32_T)(idx_r3 + 1.0) - 1];
  emxInit_real_T(&st, &X_hist, &c_emlrtRTEI);
  i1 = X_hist->size[0] * X_hist->size[1];
  X_hist->size[0] = 3;
  emxEnsureCapacity_real_T(&st, X_hist, i1, &c_emlrtRTEI);
  if (!(params[7] + 1.0 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(params[7] + 1.0, &d_emlrtDCI, &st);
  }
  d = (int32_T)muDoubleScalarFloor(params[7] + 1.0);
  if (params[7] + 1.0 != d) {
    emlrtIntegerCheckR2012b(params[7] + 1.0, &c_emlrtDCI, &st);
  }
  i1 = X_hist->size[0] * X_hist->size[1];
  X_hist->size[1] = (int32_T)(params[7] + 1.0);
  emxEnsureCapacity_real_T(&st, X_hist, i1, &c_emlrtRTEI);
  X_hist_data = X_hist->data;
  if (params[7] + 1.0 != d) {
    emlrtIntegerCheckR2012b(params[7] + 1.0, &e_emlrtDCI, &st);
  }
  loop_ub = 3 * (int32_T)(params[7] + 1.0);
  for (i1 = 0; i1 < loop_ub; i1++) {
    X_hist_data[i1] = 0.0;
  }
  if ((int32_T)(params[7] + 1.0) < 1) {
    emlrtDynamicBoundsCheckR2012b(1, 1, (int32_T)(params[7] + 1.0), &c_emlrtBCI,
                                  &st);
  }
  X_hist_data[0] = params[0];
  X_hist_data[1] = params[1];
  X_hist_data[2] = params[2];
  l_u = 0.0;
  /*  Parâmetro h para a Generalized P2S-HSD */
  /*  ===================================================================== */
  /*  FORWARD PASS (Dinâmica com CBF - Ponto a Ponto Suavizado) */
  /*  ===================================================================== */
  i1 = (int32_T)params[7];
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, params[7], mxDOUBLE_CLASS,
                                (int32_T)params[7], &emlrtRTEI, &st);
  for (n = 0; n < i1; n++) {
    real_T b_params[4];
    real_T v_n;
    real_T w_n;
    loop_ub = (int32_T)(((uint32_T)n << 1) + 1U);
    if ((loop_ub < 1) || (loop_ub > i)) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i, &e_emlrtBCI, &st);
    }
    v_n = u[loop_ub - 1];
    loop_ub = (int32_T)((((real_T)n + 1.0) - 1.0) * 2.0 + 2.0);
    if ((loop_ub < 1) || (loop_ub > i)) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i, &f_emlrtBCI, &st);
    }
    w_n = u[loop_ub - 1];
    b_st.site = &b_emlrtRSI;
    /*  =========================================================================
     */
    /*  FUNÇÃO AUXILIAR: Penalidade Ponto a Ponto (Smooth Min para a CBF) */
    /*  =========================================================================
     */
    b_params[0] = params[10];
    b_params[1] = params[11];
    b_params[2] = params[12];
    b_params[3] = params[13];
    idx_r1 = get_single_block_p2s(&x_k[0], b_params, gPa);
    b_params[0] = params[14];
    b_params[1] = params[15];
    b_params[2] = params[16];
    b_params[3] = params[17];
    idx_r2 = get_single_block_p2s(&x_k[0], b_params, gPv);
    b_params[0] = params[18];
    b_params[1] = params[19];
    b_params[2] = params[20];
    b_params[3] = params[21];
    idx_r3 = get_single_block_p2s(&x_k[0], b_params, gPg);
    b_params[0] = params[22];
    b_params[1] = params[23];
    b_params[2] = params[24];
    b_params[3] = params[25];
    work = get_single_block_p2s(&x_k[0], b_params, gPc);
    c_st.site = &o_emlrtRSI;
    tmp2 = smooth_min_func(&c_st, idx_r1, idx_r2, gPa, gPv, g1);
    c_st.site = &p_emlrtRSI;
    idx_r2 = smooth_min_func(&c_st, idx_r3, work, gPg, gPc, gPv);
    c_st.site = &q_emlrtRSI;
    P_k = smooth_min_func(&c_st, tmp2, idx_r2, g1, gPv, gPa);
    idx_r1 = Ts * v_n;
    x_next[0] = x_k[0] + idx_r1 * muDoubleScalarCos(x_k[2]);
    x_next[1] = x_k[1] + idx_r1 * muDoubleScalarSin(x_k[2]);
    x_next[2] = x_k[2] + Ts * w_n;
    b_st.site = &c_emlrtRSI;
    /*  =========================================================================
     */
    /*  FUNÇÃO AUXILIAR: Penalidade Ponto a Ponto (Smooth Min para a CBF) */
    /*  =========================================================================
     */
    b_params[0] = params[10];
    b_params[1] = params[11];
    b_params[2] = params[12];
    b_params[3] = params[13];
    idx_r1 = get_single_block_p2s(&x_next[0], b_params, gPa);
    b_params[0] = params[14];
    b_params[1] = params[15];
    b_params[2] = params[16];
    b_params[3] = params[17];
    idx_r2 = get_single_block_p2s(&x_next[0], b_params, gPv);
    b_params[0] = params[18];
    b_params[1] = params[19];
    b_params[2] = params[20];
    b_params[3] = params[21];
    idx_r3 = get_single_block_p2s(&x_next[0], b_params, gPg);
    b_params[0] = params[22];
    b_params[1] = params[23];
    b_params[2] = params[24];
    b_params[3] = params[25];
    work = get_single_block_p2s(&x_next[0], b_params, gPc);
    c_st.site = &o_emlrtRSI;
    tmp2 = smooth_min_func(&c_st, idx_r1, idx_r2, gPa, gPv, g1);
    c_st.site = &p_emlrtRSI;
    idx_r2 = smooth_min_func(&c_st, idx_r3, work, gPg, gPc, gPv);
    c_st.site = &q_emlrtRSI;
    idx_r1 = smooth_min_func(&c_st, tmp2, idx_r2, g1, gPv, gPa);
    idx_r3 = muDoubleScalarMax(0.0, (1.0 - params[6]) * -P_k - (-idx_r1));
    b_st.site = &d_emlrtRSI;
    b_st.site = &e_emlrtRSI;
    P_k = x_k[0] - xs_tmp;
    b_st.site = &e_emlrtRSI;
    work = x_k[1] - b_xs_tmp;
    b_st.site = &e_emlrtRSI;
    idx_r2 = v_n - v_s_tmp;
    b_st.site = &e_emlrtRSI;
    idx_r1 = w_n - w_s_tmp;
    l_u = (l_u + (((P_k * P_k + work * work) + 0.5 * (idx_r2 * idx_r2)) +
                  0.5 * (idx_r1 * idx_r1))) +
          params[5] * (idx_r3 * idx_r3);
    x_k[0] = x_next[0];
    x_k[1] = x_next[1];
    x_k[2] = x_next[2];
    if (((int32_T)((uint32_T)n + 2U) < 1) ||
        ((int32_T)((uint32_T)n + 2U) > X_hist->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)n + 2U), 1,
                                    X_hist->size[1], &b_emlrtBCI, &st);
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
  if (params[7] + 1.0 != d) {
    emlrtIntegerCheckR2012b(params[7] + 1.0, &emlrtDCI, &st);
  }
  if (((int32_T)(params[7] + 1.0) < 1) ||
      ((int32_T)(params[7] + 1.0) > X_hist->size[1])) {
    emlrtDynamicBoundsCheckR2012b((int32_T)(params[7] + 1.0), 1,
                                  X_hist->size[1], &emlrtBCI, &st);
  }
  r = _mm_loadu_pd(&X_hist_data[3 * ((int32_T)(params[7] + 1.0) - 1)]);
  emxFree_real_T(&st, &X_hist);
  b_r1 = _mm_loadu_pd(&xs[0]);
  r = _mm_sub_pd(r, b_r1);
  _mm_storeu_pd(&gPg[0], _mm_mul_pd(r, r));
  b_st.site = &f_emlrtRSI;
  b_st.site = &f_emlrtRSI;
  b_st.site = &f_emlrtRSI;
  r = _mm_loadu_pd(&r1[0]);
  b_r1 = _mm_loadu_pd(&xs[0]);
  b_r1 = _mm_sub_pd(r, b_r1);
  _mm_storeu_pd(&gPc[0], _mm_mul_pd(b_r1, b_r1));
  b_r1 = _mm_loadu_pd(&r2[0]);
  r = _mm_sub_pd(b_r1, r);
  _mm_storeu_pd(&g1[0], _mm_mul_pd(r, r));
  r = _mm_loadu_pd(&r3[0]);
  b_r1 = _mm_sub_pd(r, b_r1);
  _mm_storeu_pd(&y[0], _mm_mul_pd(b_r1, b_r1));
  r = _mm_sub_pd(_mm_loadu_pd(&params[3]), r);
  _mm_storeu_pd(&b_y[0], _mm_mul_pd(r, r));
  /*  ===================================================================== */
  /*  GEOFENCE DE SEGMENTOS (Contenção Convexa Suavizada) */
  /*  ===================================================================== */
  /*  Segmento 1: xs até r1 */
  b_st.site = &g_emlrtRSI;
  idx_r1 = calc_segment_p2s_penalty(&b_st, xs, r1, &params[10], gPa, gPv);
  /*  Segmento 2: r1 até r2 */
  b_st.site = &h_emlrtRSI;
  idx_r2 = calc_segment_p2s_penalty(&b_st, r1, r2, &params[10], gPa, gPv);
  /*  Segmento 3: r2 até r3 */
  b_st.site = &i_emlrtRSI;
  idx_r3 = calc_segment_p2s_penalty(&b_st, r2, r3, &params[10], gPa, gPv);
  /*  Segmento 4: r3 até r4 (x_ref) */
  b_st.site = &j_emlrtRSI;
  P_k = calc_segment_p2s_penalty(&b_st, r3, &params[3], &params[10], gPa, gPv);
  /*  Pesos de suavização  */
  work = u[0];
  for (loop_ub = 0; loop_ub < 24; loop_ub++) {
    tmp2 = work;
    work = u[(loop_ub + 1) << 1];
    b_y1[loop_ub] = work - tmp2;
  }
  for (loop_ub = 0; loop_ub <= 22; loop_ub += 2) {
    r = _mm_loadu_pd(&b_y1[loop_ub]);
    _mm_storeu_pd(&c_y[loop_ub], _mm_mul_pd(r, r));
  }
  work = u[1];
  for (loop_ub = 0; loop_ub < 24; loop_ub++) {
    tmp2 = work;
    work = u[((loop_ub + 1) << 1) + 1];
    b_y1[loop_ub] = work - tmp2;
  }
  for (loop_ub = 0; loop_ub <= 22; loop_ub += 2) {
    r = _mm_loadu_pd(&b_y1[loop_ub]);
    _mm_storeu_pd(&d_y[loop_ub], _mm_mul_pd(r, r));
  }
  /*  Custo total */
  cost =
      (((((((l_u + params[26] * sumColumnB(gPg)) +
            params[27] * (params[8] * params[8]) *
                (v_s_tmp * v_s_tmp + w_s_tmp * w_s_tmp)) +
           params[29] * (((sumColumnB(gPc) + sumColumnB(g1)) + sumColumnB(y)) +
                         sumColumnB(b_y))) +
          params[28] * idx_r1) +
         params[28] * idx_r2) +
        params[28] * idx_r3) +
       params[28] * P_k) +
      (0.2 * b_sumColumnB(c_y) + 0.2 * b_sumColumnB(d_y));
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
  return cost;
}

/* End of code generation (wrapper_cost.c) */
