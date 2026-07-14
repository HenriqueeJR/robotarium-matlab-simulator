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
    "trakcing_p2s_noeq\\wrapper_cost.m" /* pathName */
};

static emlrtRSInfo b_emlrtRSI = {
    53,                           /* lineNo */
    "build_robot_cbf_experiment", /* fcnName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "trakcing_p2s_noeq\\build_robot_cbf_experiment.m" /* pathName */
};

static emlrtRSInfo c_emlrtRSI = {
    61,                           /* lineNo */
    "build_robot_cbf_experiment", /* fcnName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "trakcing_p2s_noeq\\build_robot_cbf_experiment.m" /* pathName */
};

static emlrtRSInfo d_emlrtRSI = {
    65,                           /* lineNo */
    "build_robot_cbf_experiment", /* fcnName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "trakcing_p2s_noeq\\build_robot_cbf_experiment.m" /* pathName */
};

static emlrtRSInfo e_emlrtRSI = {
    67,                           /* lineNo */
    "build_robot_cbf_experiment", /* fcnName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "trakcing_p2s_noeq\\build_robot_cbf_experiment.m" /* pathName */
};

static emlrtRSInfo f_emlrtRSI = {
    95,                           /* lineNo */
    "build_robot_cbf_experiment", /* fcnName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "trakcing_p2s_noeq\\build_robot_cbf_experiment.m" /* pathName */
};

static emlrtRSInfo g_emlrtRSI = {
    98,                           /* lineNo */
    "build_robot_cbf_experiment", /* fcnName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "trakcing_p2s_noeq\\build_robot_cbf_experiment.m" /* pathName */
};

static emlrtRSInfo h_emlrtRSI = {
    101,                          /* lineNo */
    "build_robot_cbf_experiment", /* fcnName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "trakcing_p2s_noeq\\build_robot_cbf_experiment.m" /* pathName */
};

static emlrtRSInfo i_emlrtRSI = {
    104,                          /* lineNo */
    "build_robot_cbf_experiment", /* fcnName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "trakcing_p2s_noeq\\build_robot_cbf_experiment.m" /* pathName */
};

static emlrtRSInfo n_emlrtRSI = {
    280,                      /* lineNo */
    "calc_point_p2s_penalty", /* fcnName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "trakcing_p2s_noeq\\build_robot_cbf_experiment.m" /* pathName */
};

static emlrtRSInfo o_emlrtRSI = {
    281,                      /* lineNo */
    "calc_point_p2s_penalty", /* fcnName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "trakcing_p2s_noeq\\build_robot_cbf_experiment.m" /* pathName */
};

static emlrtRSInfo p_emlrtRSI = {
    282,                      /* lineNo */
    "calc_point_p2s_penalty", /* fcnName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "trakcing_p2s_noeq\\build_robot_cbf_experiment.m" /* pathName */
};

static emlrtBCInfo emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    79,                           /* lineNo */
    21,                           /* colNo */
    "X_hist",                     /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "trakcing_p2s_noeq\\build_robot_cbf_experiment.m", /* pName */
    0                                                  /* checkKind */
};

static emlrtDCInfo emlrtDCI = {
    79,                           /* lineNo */
    21,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "trakcing_p2s_noeq\\build_robot_cbf_experiment.m", /* pName */
    1                                                  /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    71,                           /* lineNo */
    19,                           /* colNo */
    "X_hist",                     /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "trakcing_p2s_noeq\\build_robot_cbf_experiment.m", /* pName */
    0                                                  /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    40,                           /* lineNo */
    15,                           /* colNo */
    "X_hist",                     /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "trakcing_p2s_noeq\\build_robot_cbf_experiment.m", /* pName */
    0                                                  /* checkKind */
};

static emlrtRTEInfo emlrtRTEI = {
    49,                           /* lineNo */
    13,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "trakcing_p2s_noeq\\build_robot_cbf_experiment.m" /* pName */
};

static emlrtBCInfo d_emlrtBCI = {
    1,                            /* iFirst */
    48,                           /* iLast */
    21,                           /* lineNo */
    14,                           /* colNo */
    "W",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "trakcing_p2s_noeq\\build_robot_cbf_experiment.m", /* pName */
    0                                                  /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = {
    21,                           /* lineNo */
    14,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "trakcing_p2s_noeq\\build_robot_cbf_experiment.m", /* pName */
    1                                                  /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = {
    39,                           /* lineNo */
    23,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "trakcing_p2s_noeq\\build_robot_cbf_experiment.m", /* pName */
    1                                                  /* checkKind */
};

static emlrtDCInfo d_emlrtDCI = {
    39,                           /* lineNo */
    23,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "trakcing_p2s_noeq\\build_robot_cbf_experiment.m", /* pName */
    4                                                  /* checkKind */
};

static emlrtDCInfo e_emlrtDCI = {
    39,                           /* lineNo */
    5,                            /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "trakcing_p2s_noeq\\build_robot_cbf_experiment.m", /* pName */
    1                                                  /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    50,                           /* lineNo */
    17,                           /* colNo */
    "u",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "trakcing_p2s_noeq\\build_robot_cbf_experiment.m", /* pName */
    0                                                  /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    51,                           /* lineNo */
    17,                           /* colNo */
    "u",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "trakcing_p2s_noeq\\build_robot_cbf_experiment.m", /* pName */
    0                                                  /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = {
    1,                            /* iFirst */
    48,                           /* iLast */
    37,                           /* lineNo */
    12,                           /* colNo */
    "W",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "trakcing_p2s_noeq\\build_robot_cbf_experiment.m", /* pName */
    0                                                  /* checkKind */
};

static emlrtDCInfo f_emlrtDCI = {
    37,                           /* lineNo */
    12,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "trakcing_p2s_noeq\\build_robot_cbf_experiment.m", /* pName */
    1                                                  /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = {
    1,                            /* iFirst */
    48,                           /* iLast */
    36,                           /* lineNo */
    12,                           /* colNo */
    "W",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "trakcing_p2s_noeq\\build_robot_cbf_experiment.m", /* pName */
    0                                                  /* checkKind */
};

static emlrtDCInfo g_emlrtDCI = {
    36,                           /* lineNo */
    12,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "trakcing_p2s_noeq\\build_robot_cbf_experiment.m", /* pName */
    1                                                  /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = {
    1,                            /* iFirst */
    48,                           /* iLast */
    35,                           /* lineNo */
    12,                           /* colNo */
    "W",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "trakcing_p2s_noeq\\build_robot_cbf_experiment.m", /* pName */
    0                                                  /* checkKind */
};

static emlrtDCInfo h_emlrtDCI = {
    35,                           /* lineNo */
    12,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "trakcing_p2s_noeq\\build_robot_cbf_experiment.m", /* pName */
    1                                                  /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = {
    1,                            /* iFirst */
    48,                           /* iLast */
    22,                           /* lineNo */
    12,                           /* colNo */
    "W",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "trakcing_p2s_noeq\\build_robot_cbf_experiment.m", /* pName */
    0                                                  /* checkKind */
};

static emlrtDCInfo i_emlrtDCI = {
    22,                           /* lineNo */
    12,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "trakcing_p2s_noeq\\build_robot_cbf_experiment.m", /* pName */
    1                                                  /* checkKind */
};

static emlrtRTEInfo c_emlrtRTEI = {
    39,                           /* lineNo */
    5,                            /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "trakcing_p2s_noeq\\build_robot_cbf_experiment.m" /* pName */
};

/* Function Definitions */
real_T wrapper_cost(const emlrtStack *sp, const real_T u[48],
                    const real_T params[29])
{
  __m128d b_r1;
  __m128d r;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  emxArray_real_T *X_hist;
  real_T b_y[23];
  real_T b_y1[23];
  real_T y[23];
  real_T b_gPa[2];
  real_T b_gPc[2];
  real_T b_gPg[2];
  real_T b_gPv[2];
  real_T g1[2];
  real_T g2[2];
  real_T gPa[2];
  real_T gPc[2];
  real_T gPg[2];
  real_T gPv[2];
  real_T grad_P[2];
  real_T r1[2];
  real_T r2[2];
  real_T r3[2];
  real_T xs[2];
  real_T Ts;
  real_T b_xs_tmp;
  real_T cost;
  real_T d;
  real_T idx_r1;
  real_T idx_r2;
  real_T idx_r3;
  real_T l_u;
  real_T tmp2;
  real_T v2;
  real_T work;
  real_T x_k_idx_0;
  real_T x_k_idx_1;
  real_T x_next_idx_2;
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
  /*  Desempacotamento do vetor params (Tamanho atualizado: 29) */
  x_k_idx_0 = params[0];
  x_k_idx_1 = params[1];
  x_next_idx_2 = params[2];
  Ts = params[8];
  /*  Limites [xmin, xmax, ymin, ymax] dos 4 blocos */
  /*  eta_eq removido! */
  d = 2.0 * params[7];
  if (d < 1.0) {
    i = 0;
  } else {
    if (d != (int32_T)muDoubleScalarFloor(d)) {
      emlrtIntegerCheckR2012b(d, &b_emlrtDCI, &st);
    }
    if (((int32_T)d < 1) || ((int32_T)d > 48)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, 48, &d_emlrtBCI, &st);
    }
    i = (int32_T)d;
  }
  d = 2.0 * params[7] + 1.0;
  if (d != (int32_T)muDoubleScalarFloor(d)) {
    emlrtIntegerCheckR2012b(d, &i_emlrtDCI, &st);
  }
  if (((int32_T)d < 1) || ((int32_T)d > 48)) {
    emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, 48, &j_emlrtBCI, &st);
  }
  xs_tmp = u[(int32_T)d - 1];
  xs[0] = xs_tmp;
  if (d + 1.0 != (int32_T)muDoubleScalarFloor(d + 1.0)) {
    emlrtIntegerCheckR2012b(d + 1.0, &i_emlrtDCI, &st);
  }
  if (((int32_T)(d + 1.0) < 1) || ((int32_T)(d + 1.0) > 48)) {
    emlrtDynamicBoundsCheckR2012b((int32_T)(d + 1.0), 1, 48, &j_emlrtBCI, &st);
  }
  b_xs_tmp = u[(int32_T)(d + 1.0) - 1];
  xs[1] = b_xs_tmp;
  /*  ===================================================================== */
  /*  INJEÇÃO DO MAPEAMENTO ANALÍTICO DE EQUILÍBRIO (gu) */
  /*  ===================================================================== */
  /*  Novos índices de leitura (reduzidos em 2 posições) */
  idx_r1 = 2.0 * params[7] + 3.0;
  idx_r2 = 2.0 * params[7] + 5.0;
  idx_r3 = 2.0 * params[7] + 7.0;
  if (idx_r1 != (int32_T)muDoubleScalarFloor(idx_r1)) {
    emlrtIntegerCheckR2012b(idx_r1, &h_emlrtDCI, &st);
  }
  if (((int32_T)idx_r1 < 1) || ((int32_T)idx_r1 > 48)) {
    emlrtDynamicBoundsCheckR2012b((int32_T)idx_r1, 1, 48, &i_emlrtBCI, &st);
  }
  r1[0] = u[(int32_T)idx_r1 - 1];
  if (idx_r1 + 1.0 != (int32_T)muDoubleScalarFloor(idx_r1 + 1.0)) {
    emlrtIntegerCheckR2012b(idx_r1 + 1.0, &h_emlrtDCI, &st);
  }
  if (((int32_T)(idx_r1 + 1.0) < 1) || ((int32_T)(idx_r1 + 1.0) > 48)) {
    emlrtDynamicBoundsCheckR2012b((int32_T)(idx_r1 + 1.0), 1, 48, &i_emlrtBCI,
                                  &st);
  }
  r1[1] = u[(int32_T)(idx_r1 + 1.0) - 1];
  if (idx_r2 != (int32_T)muDoubleScalarFloor(idx_r2)) {
    emlrtIntegerCheckR2012b(idx_r2, &g_emlrtDCI, &st);
  }
  if (((int32_T)idx_r2 < 1) || ((int32_T)idx_r2 > 48)) {
    emlrtDynamicBoundsCheckR2012b((int32_T)idx_r2, 1, 48, &h_emlrtBCI, &st);
  }
  r2[0] = u[(int32_T)idx_r2 - 1];
  if (idx_r2 + 1.0 != (int32_T)muDoubleScalarFloor(idx_r2 + 1.0)) {
    emlrtIntegerCheckR2012b(idx_r2 + 1.0, &g_emlrtDCI, &st);
  }
  if (((int32_T)(idx_r2 + 1.0) < 1) || ((int32_T)(idx_r2 + 1.0) > 48)) {
    emlrtDynamicBoundsCheckR2012b((int32_T)(idx_r2 + 1.0), 1, 48, &h_emlrtBCI,
                                  &st);
  }
  r2[1] = u[(int32_T)(idx_r2 + 1.0) - 1];
  if (idx_r3 != (int32_T)muDoubleScalarFloor(idx_r3)) {
    emlrtIntegerCheckR2012b(idx_r3, &f_emlrtDCI, &st);
  }
  if (((int32_T)idx_r3 < 1) || ((int32_T)idx_r3 > 48)) {
    emlrtDynamicBoundsCheckR2012b((int32_T)idx_r3, 1, 48, &g_emlrtBCI, &st);
  }
  r3[0] = u[(int32_T)idx_r3 - 1];
  if (idx_r3 + 1.0 != (int32_T)muDoubleScalarFloor(idx_r3 + 1.0)) {
    emlrtIntegerCheckR2012b(idx_r3 + 1.0, &f_emlrtDCI, &st);
  }
  if (((int32_T)(idx_r3 + 1.0) < 1) || ((int32_T)(idx_r3 + 1.0) > 48)) {
    emlrtDynamicBoundsCheckR2012b((int32_T)(idx_r3 + 1.0), 1, 48, &g_emlrtBCI,
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
    real_T P_k;
    real_T b_v1;
    real_T b_v2;
    real_T b_v3;
    real_T b_v4;
    real_T c_v1;
    real_T c_v2;
    real_T c_v3;
    real_T c_v4;
    real_T d1;
    real_T d2;
    real_T d_v2;
    real_T d_v3;
    real_T d_v4;
    real_T v1;
    real_T v3;
    real_T v4;
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
    /*  =========================================================================
     */
    /*  FUNÇÃO AUXILIAR: P2S-HSD para UM Polítopo Convexo */
    /*  =========================================================================
     */
    idx_r3 = phi_func(params[10] - x_k_idx_0, &work);
    v2 = phi_func(x_k_idx_0 - params[11], &tmp2);
    v3 = phi_func(params[12] - x_k_idx_1, &idx_r1);
    v4 = phi_func(x_k_idx_1 - params[13], &idx_r2);
    gPa[0] = 0.25 * (-work + tmp2);
    gPa[1] = 0.25 * (-idx_r1 + idx_r2);
    /*  =========================================================================
     */
    /*  FUNÇÃO AUXILIAR: P2S-HSD para UM Polítopo Convexo */
    /*  =========================================================================
     */
    v1 = phi_func(params[14] - x_k_idx_0, &work);
    b_v2 = phi_func(x_k_idx_0 - params[15], &tmp2);
    b_v3 = phi_func(params[16] - x_k_idx_1, &idx_r1);
    b_v4 = phi_func(x_k_idx_1 - params[17], &idx_r2);
    gPv[0] = 0.25 * (-work + tmp2);
    gPv[1] = 0.25 * (-idx_r1 + idx_r2);
    /*  =========================================================================
     */
    /*  FUNÇÃO AUXILIAR: P2S-HSD para UM Polítopo Convexo */
    /*  =========================================================================
     */
    b_v1 = phi_func(params[18] - x_k_idx_0, &work);
    c_v2 = phi_func(x_k_idx_0 - params[19], &tmp2);
    c_v3 = phi_func(params[20] - x_k_idx_1, &idx_r1);
    c_v4 = phi_func(x_k_idx_1 - params[21], &idx_r2);
    gPg[0] = 0.25 * (-work + tmp2);
    gPg[1] = 0.25 * (-idx_r1 + idx_r2);
    /*  =========================================================================
     */
    /*  FUNÇÃO AUXILIAR: P2S-HSD para UM Polítopo Convexo */
    /*  =========================================================================
     */
    c_v1 = phi_func(params[22] - x_k_idx_0, &work);
    d_v2 = phi_func(x_k_idx_0 - params[23], &tmp2);
    d_v3 = phi_func(params[24] - x_k_idx_1, &idx_r1);
    d_v4 = phi_func(x_k_idx_1 - params[25], &idx_r2);
    gPc[0] = 0.25 * (-work + tmp2);
    gPc[1] = 0.25 * (-idx_r1 + idx_r2);
    c_st.site = &n_emlrtRSI;
    idx_r1 =
        smooth_min_func(&c_st, 0.25 * (((idx_r3 + v2) + v3) + v4),
                        0.25 * (((v1 + b_v2) + b_v3) + b_v4), gPa, gPv, g1);
    c_st.site = &o_emlrtRSI;
    tmp2 =
        smooth_min_func(&c_st, 0.25 * (((b_v1 + c_v2) + c_v3) + c_v4),
                        0.25 * (((c_v1 + d_v2) + d_v3) + d_v4), gPg, gPc, g2);
    c_st.site = &p_emlrtRSI;
    P_k = smooth_min_func(&c_st, idx_r1, tmp2, g1, g2, grad_P);
    d1 = Ts * v_n;
    d2 = x_k_idx_0 + d1 * muDoubleScalarCos(x_next_idx_2);
    d1 = x_k_idx_1 + d1 * muDoubleScalarSin(x_next_idx_2);
    x_next_idx_2 += Ts * w_n;
    b_st.site = &c_emlrtRSI;
    /*  =========================================================================
     */
    /*  FUNÇÃO AUXILIAR: Penalidade Ponto a Ponto (Smooth Min para a CBF) */
    /*  =========================================================================
     */
    /*  =========================================================================
     */
    /*  FUNÇÃO AUXILIAR: P2S-HSD para UM Polítopo Convexo */
    /*  =========================================================================
     */
    idx_r3 = phi_func(params[10] - d2, &work);
    v2 = phi_func(d2 - params[11], &tmp2);
    v3 = phi_func(params[12] - d1, &idx_r1);
    v4 = phi_func(d1 - params[13], &idx_r2);
    b_gPa[0] = 0.25 * (-work + tmp2);
    b_gPa[1] = 0.25 * (-idx_r1 + idx_r2);
    /*  =========================================================================
     */
    /*  FUNÇÃO AUXILIAR: P2S-HSD para UM Polítopo Convexo */
    /*  =========================================================================
     */
    v1 = phi_func(params[14] - d2, &work);
    b_v2 = phi_func(d2 - params[15], &tmp2);
    b_v3 = phi_func(params[16] - d1, &idx_r1);
    b_v4 = phi_func(d1 - params[17], &idx_r2);
    b_gPv[0] = 0.25 * (-work + tmp2);
    b_gPv[1] = 0.25 * (-idx_r1 + idx_r2);
    /*  =========================================================================
     */
    /*  FUNÇÃO AUXILIAR: P2S-HSD para UM Polítopo Convexo */
    /*  =========================================================================
     */
    b_v1 = phi_func(params[18] - d2, &work);
    c_v2 = phi_func(d2 - params[19], &tmp2);
    c_v3 = phi_func(params[20] - d1, &idx_r1);
    c_v4 = phi_func(d1 - params[21], &idx_r2);
    b_gPg[0] = 0.25 * (-work + tmp2);
    b_gPg[1] = 0.25 * (-idx_r1 + idx_r2);
    /*  =========================================================================
     */
    /*  FUNÇÃO AUXILIAR: P2S-HSD para UM Polítopo Convexo */
    /*  =========================================================================
     */
    c_v1 = phi_func(params[22] - d2, &work);
    d_v2 = phi_func(d2 - params[23], &tmp2);
    d_v3 = phi_func(params[24] - d1, &idx_r1);
    d_v4 = phi_func(d1 - params[25], &idx_r2);
    b_gPc[0] = 0.25 * (-work + tmp2);
    b_gPc[1] = 0.25 * (-idx_r1 + idx_r2);
    c_st.site = &n_emlrtRSI;
    idx_r1 =
        smooth_min_func(&c_st, 0.25 * (((idx_r3 + v2) + v3) + v4),
                        0.25 * (((v1 + b_v2) + b_v3) + b_v4), b_gPa, b_gPv, g1);
    c_st.site = &o_emlrtRSI;
    tmp2 = smooth_min_func(&c_st, 0.25 * (((b_v1 + c_v2) + c_v3) + c_v4),
                           0.25 * (((c_v1 + d_v2) + d_v3) + d_v4), b_gPg, b_gPc,
                           g2);
    c_st.site = &p_emlrtRSI;
    work = smooth_min_func(&c_st, idx_r1, tmp2, g1, g2, grad_P);
    tmp2 = muDoubleScalarMax(0.0, (1.0 - params[6]) * -P_k - (-work));
    b_st.site = &d_emlrtRSI;
    b_st.site = &e_emlrtRSI;
    work = x_k_idx_0 - xs_tmp;
    b_st.site = &e_emlrtRSI;
    v2 = x_k_idx_1 - b_xs_tmp;
    b_st.site = &e_emlrtRSI;
    b_st.site = &e_emlrtRSI;
    l_u = (l_u +
           ((5.0 * (work * work + v2 * v2) + v_n * v_n) + 0.01 * (w_n * w_n))) +
          params[5] * (tmp2 * tmp2);
    x_k_idx_0 = d2;
    x_k_idx_1 = d1;
    if (((int32_T)((uint32_T)n + 2U) < 1) ||
        ((int32_T)((uint32_T)n + 2U) > X_hist->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)n + 2U), 1,
                                    X_hist->size[1], &b_emlrtBCI, &st);
    }
    loop_ub = 3 * (n + 1);
    X_hist_data[loop_ub] = d2;
    X_hist_data[loop_ub + 1] = d1;
    X_hist_data[loop_ub + 2] = x_next_idx_2;
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
  /*  Penalidade eta_eq * Ts^2 * (v_s^2 + w_s^2) removida! */
  r = _mm_loadu_pd(&X_hist_data[3 * ((int32_T)(params[7] + 1.0) - 1)]);
  emxFree_real_T(&st, &X_hist);
  b_r1 = _mm_loadu_pd(&xs[0]);
  r = _mm_sub_pd(r, b_r1);
  _mm_storeu_pd(&gPg[0], _mm_mul_pd(r, r));
  r = _mm_loadu_pd(&r1[0]);
  b_r1 = _mm_sub_pd(r, b_r1);
  _mm_storeu_pd(&gPc[0], _mm_mul_pd(b_r1, b_r1));
  b_r1 = _mm_loadu_pd(&r2[0]);
  r = _mm_sub_pd(b_r1, r);
  _mm_storeu_pd(&g1[0], _mm_mul_pd(r, r));
  r = _mm_loadu_pd(&r3[0]);
  b_r1 = _mm_sub_pd(r, b_r1);
  _mm_storeu_pd(&g2[0], _mm_mul_pd(b_r1, b_r1));
  r = _mm_sub_pd(_mm_loadu_pd(&params[3]), r);
  _mm_storeu_pd(&grad_P[0], _mm_mul_pd(r, r));
  /*  ===================================================================== */
  /*  GEOFENCE DE SEGMENTOS (Contenção Convexa Suavizada) */
  /*  ===================================================================== */
  b_st.site = &f_emlrtRSI;
  idx_r1 = calc_segment_p2s_penalty(&b_st, xs, r1, &params[10], gPa, gPv);
  b_st.site = &g_emlrtRSI;
  idx_r2 = calc_segment_p2s_penalty(&b_st, r1, r2, &params[10], gPv, gPa);
  b_st.site = &h_emlrtRSI;
  idx_r3 = calc_segment_p2s_penalty(&b_st, r2, r3, &params[10], gPa, gPv);
  b_st.site = &i_emlrtRSI;
  v2 = calc_segment_p2s_penalty(&b_st, r3, &params[3], &params[10], gPa, gPv);
  /*  Pesos de suavização  */
  work = u[0];
  for (loop_ub = 0; loop_ub < 23; loop_ub++) {
    tmp2 = work;
    work = u[(loop_ub + 1) << 1];
    b_y1[loop_ub] = work - tmp2;
  }
  for (loop_ub = 0; loop_ub <= 20; loop_ub += 2) {
    r = _mm_loadu_pd(&b_y1[loop_ub]);
    _mm_storeu_pd(&y[loop_ub], _mm_mul_pd(r, r));
  }
  y[22] = b_y1[22] * b_y1[22];
  work = u[1];
  for (loop_ub = 0; loop_ub < 23; loop_ub++) {
    tmp2 = work;
    work = u[((loop_ub + 1) << 1) + 1];
    b_y1[loop_ub] = work - tmp2;
  }
  for (loop_ub = 0; loop_ub <= 20; loop_ub += 2) {
    r = _mm_loadu_pd(&b_y1[loop_ub]);
    _mm_storeu_pd(&b_y[loop_ub], _mm_mul_pd(r, r));
  }
  b_y[22] = b_y1[22] * b_y1[22];
  /*  Custo total */
  cost =
      ((((((l_u + params[26] * sumColumnB(gPg)) +
           params[28] * (((sumColumnB(gPc) + sumColumnB(g1)) + sumColumnB(g2)) +
                         sumColumnB(grad_P))) +
          params[27] * idx_r1) +
         params[27] * idx_r2) +
        params[27] * idx_r3) +
       params[27] * v2) +
      (0.2 * b_sumColumnB(y) + 0.2 * b_sumColumnB(b_y));
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
  return cost;
}

/* End of code generation (wrapper_cost.c) */
