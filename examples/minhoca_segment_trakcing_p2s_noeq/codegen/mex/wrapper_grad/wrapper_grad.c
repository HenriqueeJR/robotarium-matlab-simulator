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
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "trakcing_p2s_noeq\\wrapper_grad.m" /* pathName */
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

static emlrtRSInfo j_emlrtRSI = {
    145,                          /* lineNo */
    "build_robot_cbf_experiment", /* fcnName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "trakcing_p2s_noeq\\build_robot_cbf_experiment.m" /* pathName */
};

static emlrtRSInfo k_emlrtRSI = {
    148,                          /* lineNo */
    "build_robot_cbf_experiment", /* fcnName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "trakcing_p2s_noeq\\build_robot_cbf_experiment.m" /* pathName */
};

static emlrtRSInfo p_emlrtRSI = {
    280,                      /* lineNo */
    "calc_point_p2s_penalty", /* fcnName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "trakcing_p2s_noeq\\build_robot_cbf_experiment.m" /* pathName */
};

static emlrtRSInfo q_emlrtRSI = {
    281,                      /* lineNo */
    "calc_point_p2s_penalty", /* fcnName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "trakcing_p2s_noeq\\build_robot_cbf_experiment.m" /* pathName */
};

static emlrtRSInfo r_emlrtRSI = {
    282,                      /* lineNo */
    "calc_point_p2s_penalty", /* fcnName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "trakcing_p2s_noeq\\build_robot_cbf_experiment.m" /* pathName */
};

static emlrtECInfo emlrtECI = {
    -1,                           /* nDims */
    177,                          /* lineNo */
    5,                            /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "trakcing_p2s_noeq\\build_robot_cbf_experiment.m" /* pName */
};

static emlrtBCInfo emlrtBCI = {
    1,                            /* iFirst */
    48,                           /* iLast */
    177,                          /* lineNo */
    12,                           /* colNo */
    "grad",                       /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "trakcing_p2s_noeq\\build_robot_cbf_experiment.m", /* pName */
    0                                                  /* checkKind */
};

static emlrtDCInfo emlrtDCI = {
    177,                          /* lineNo */
    12,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "trakcing_p2s_noeq\\build_robot_cbf_experiment.m", /* pName */
    1                                                  /* checkKind */
};

static emlrtECInfo b_emlrtECI = {
    -1,                           /* nDims */
    174,                          /* lineNo */
    9,                            /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "trakcing_p2s_noeq\\build_robot_cbf_experiment.m" /* pName */
};

static emlrtBCInfo b_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    174,                          /* lineNo */
    30,                           /* colNo */
    "grad_U",                     /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "trakcing_p2s_noeq\\build_robot_cbf_experiment.m", /* pName */
    0                                                  /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    174,                          /* lineNo */
    16,                           /* colNo */
    "grad_U",                     /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "trakcing_p2s_noeq\\build_robot_cbf_experiment.m", /* pName */
    0                                                  /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    134,                          /* lineNo */
    28,                           /* colNo */
    "X_hist",                     /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "trakcing_p2s_noeq\\build_robot_cbf_experiment.m", /* pName */
    0                                                  /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    133,                          /* lineNo */
    25,                           /* colNo */
    "X_hist",                     /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "trakcing_p2s_noeq\\build_robot_cbf_experiment.m", /* pName */
    0                                                  /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = {
    133,                          /* lineNo */
    25,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "trakcing_p2s_noeq\\build_robot_cbf_experiment.m", /* pName */
    1                                                  /* checkKind */
};

static emlrtRTEInfo emlrtRTEI = {
    132,                          /* lineNo */
    13,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "trakcing_p2s_noeq\\build_robot_cbf_experiment.m" /* pName */
};

static emlrtBCInfo f_emlrtBCI = {
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

static emlrtDCInfo c_emlrtDCI = {
    79,                           /* lineNo */
    21,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "trakcing_p2s_noeq\\build_robot_cbf_experiment.m", /* pName */
    1                                                  /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = {
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

static emlrtBCInfo h_emlrtBCI = {
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

static emlrtRTEInfo b_emlrtRTEI = {
    49,                           /* lineNo */
    13,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "trakcing_p2s_noeq\\build_robot_cbf_experiment.m" /* pName */
};

static emlrtBCInfo i_emlrtBCI = {
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

static emlrtDCInfo d_emlrtDCI = {
    21,                           /* lineNo */
    14,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "trakcing_p2s_noeq\\build_robot_cbf_experiment.m", /* pName */
    1                                                  /* checkKind */
};

static emlrtDCInfo e_emlrtDCI = {
    39,                           /* lineNo */
    23,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "trakcing_p2s_noeq\\build_robot_cbf_experiment.m", /* pName */
    1                                                  /* checkKind */
};

static emlrtDCInfo f_emlrtDCI = {
    39,                           /* lineNo */
    23,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "trakcing_p2s_noeq\\build_robot_cbf_experiment.m", /* pName */
    4                                                  /* checkKind */
};

static emlrtDCInfo g_emlrtDCI = {
    39,                           /* lineNo */
    5,                            /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "trakcing_p2s_noeq\\build_robot_cbf_experiment.m", /* pName */
    1                                                  /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = {
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

static emlrtBCInfo k_emlrtBCI = {
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

static emlrtDCInfo h_emlrtDCI = {
    110,                          /* lineNo */
    5,                            /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "trakcing_p2s_noeq\\build_robot_cbf_experiment.m", /* pName */
    1                                                  /* checkKind */
};

static emlrtDCInfo i_emlrtDCI = {
    110,                          /* lineNo */
    5,                            /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "trakcing_p2s_noeq\\build_robot_cbf_experiment.m", /* pName */
    4                                                  /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    135,                          /* lineNo */
    17,                           /* colNo */
    "u",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "trakcing_p2s_noeq\\build_robot_cbf_experiment.m", /* pName */
    0                                                  /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    135,                          /* lineNo */
    39,                           /* colNo */
    "u",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "trakcing_p2s_noeq\\build_robot_cbf_experiment.m", /* pName */
    0                                                  /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = {
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

static emlrtDCInfo j_emlrtDCI = {
    37,                           /* lineNo */
    12,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "trakcing_p2s_noeq\\build_robot_cbf_experiment.m", /* pName */
    1                                                  /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = {
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

static emlrtDCInfo k_emlrtDCI = {
    36,                           /* lineNo */
    12,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "trakcing_p2s_noeq\\build_robot_cbf_experiment.m", /* pName */
    1                                                  /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = {
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

static emlrtDCInfo l_emlrtDCI = {
    35,                           /* lineNo */
    12,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "trakcing_p2s_noeq\\build_robot_cbf_experiment.m", /* pName */
    1                                                  /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = {
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

static emlrtDCInfo m_emlrtDCI = {
    22,                           /* lineNo */
    12,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "trakcing_p2s_noeq\\build_robot_cbf_experiment.m", /* pName */
    1                                                  /* checkKind */
};

static emlrtRTEInfo d_emlrtRTEI = {
    39,                           /* lineNo */
    5,                            /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "trakcing_p2s_noeq\\build_robot_cbf_experiment.m" /* pName */
};

static emlrtRTEInfo e_emlrtRTEI = {
    110,                          /* lineNo */
    5,                            /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "trakcing_p2s_noeq\\build_robot_cbf_experiment.m" /* pName */
};

/* Function Definitions */
void wrapper_grad(const emlrtStack *sp, const real_T u[48],
                  const real_T params[29], real_T grad[48])
{
  __m128d b_r1;
  __m128d r;
  __m128d r6;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  emxArray_real_T *X_hist;
  emxArray_real_T *grad_U;
  real_T grad_smooth[48];
  real_T dv[9];
  real_T b_Ts[6];
  real_T b_params[4];
  real_T dv1[3];
  real_T grad_x_next_cbf[3];
  real_T x_k[3];
  real_T x_next[3];
  real_T g1[2];
  real_T gP_seg2_r3[2];
  real_T gP_seg3_r3[2];
  real_T gPa[2];
  real_T gPc[2];
  real_T gPg[2];
  real_T gPv[2];
  real_T grad_P[2];
  real_T grad_xs[2];
  real_T r1[2];
  real_T r2[2];
  real_T r3[2];
  real_T xs[2];
  real_T P2;
  real_T Pc;
  real_T Pg;
  real_T Pv;
  real_T Ts;
  real_T b_xs_tmp;
  real_T d;
  real_T d1;
  real_T d2;
  real_T eta_safe;
  real_T g_corridor;
  real_T gamma_safe;
  real_T idx_r1;
  real_T idx_r2;
  real_T idx_r3;
  real_T xs_tmp;
  real_T *X_hist_data;
  real_T *grad_U_data;
  int32_T b_i;
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
  x_k[0] = params[0];
  x_k[1] = params[1];
  x_k[2] = params[2];
  eta_safe = params[5];
  gamma_safe = params[6];
  Ts = params[8];
  /*  Limites [xmin, xmax, ymin, ymax] dos 4 blocos */
  /*  eta_eq removido! */
  d = 2.0 * params[7];
  if (d < 1.0) {
    i = 0;
  } else {
    if (d != (int32_T)muDoubleScalarFloor(d)) {
      emlrtIntegerCheckR2012b(d, &d_emlrtDCI, &st);
    }
    if (((int32_T)d < 1) || ((int32_T)d > 48)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, 48, &i_emlrtBCI, &st);
    }
    i = (int32_T)d;
  }
  d1 = 2.0 * params[7] + 1.0;
  if (d1 != (int32_T)muDoubleScalarFloor(d1)) {
    emlrtIntegerCheckR2012b(d1, &m_emlrtDCI, &st);
  }
  if (((int8_T)d1 < 1) || ((int8_T)d1 > 48)) {
    emlrtDynamicBoundsCheckR2012b((int8_T)d1, 1, 48, &q_emlrtBCI, &st);
  }
  if (d1 + 1.0 != (int32_T)muDoubleScalarFloor(d1 + 1.0)) {
    emlrtIntegerCheckR2012b(d1 + 1.0, &m_emlrtDCI, &st);
  }
  if (((int8_T)(d1 + 1.0) < 1) || ((int8_T)(d1 + 1.0) > 48)) {
    emlrtDynamicBoundsCheckR2012b((int8_T)(d1 + 1.0), 1, 48, &q_emlrtBCI, &st);
  }
  xs_tmp = u[(int8_T)d1 - 1];
  xs[0] = xs_tmp;
  b_xs_tmp = u[(int8_T)(d1 + 1.0) - 1];
  xs[1] = b_xs_tmp;
  /*  ===================================================================== */
  /*  INJEÇÃO DO MAPEAMENTO ANALÍTICO DE EQUILÍBRIO (gu) */
  /*  ===================================================================== */
  /*  Novos índices de leitura (reduzidos em 2 posições) */
  idx_r1 = 2.0 * params[7] + 3.0;
  idx_r2 = 2.0 * params[7] + 5.0;
  idx_r3 = 2.0 * params[7] + 7.0;
  if (idx_r1 != (int32_T)muDoubleScalarFloor(idx_r1)) {
    emlrtIntegerCheckR2012b(idx_r1, &l_emlrtDCI, &st);
  }
  if (((int8_T)idx_r1 < 1) || ((int8_T)idx_r1 > 48)) {
    emlrtDynamicBoundsCheckR2012b((int8_T)idx_r1, 1, 48, &p_emlrtBCI, &st);
  }
  if (idx_r1 + 1.0 != (int32_T)muDoubleScalarFloor(idx_r1 + 1.0)) {
    emlrtIntegerCheckR2012b(idx_r1 + 1.0, &l_emlrtDCI, &st);
  }
  if (((int8_T)(idx_r1 + 1.0) < 1) || ((int8_T)(idx_r1 + 1.0) > 48)) {
    emlrtDynamicBoundsCheckR2012b((int8_T)(idx_r1 + 1.0), 1, 48, &p_emlrtBCI,
                                  &st);
  }
  r1[0] = u[(int8_T)idx_r1 - 1];
  r1[1] = u[(int8_T)(idx_r1 + 1.0) - 1];
  if (idx_r2 != (int32_T)muDoubleScalarFloor(idx_r2)) {
    emlrtIntegerCheckR2012b(idx_r2, &k_emlrtDCI, &st);
  }
  if (((int8_T)idx_r2 < 1) || ((int8_T)idx_r2 > 48)) {
    emlrtDynamicBoundsCheckR2012b((int8_T)idx_r2, 1, 48, &o_emlrtBCI, &st);
  }
  if (idx_r2 + 1.0 != (int32_T)muDoubleScalarFloor(idx_r2 + 1.0)) {
    emlrtIntegerCheckR2012b(idx_r2 + 1.0, &k_emlrtDCI, &st);
  }
  if (((int8_T)(idx_r2 + 1.0) < 1) || ((int8_T)(idx_r2 + 1.0) > 48)) {
    emlrtDynamicBoundsCheckR2012b((int8_T)(idx_r2 + 1.0), 1, 48, &o_emlrtBCI,
                                  &st);
  }
  r2[0] = u[(int8_T)idx_r2 - 1];
  r2[1] = u[(int8_T)(idx_r2 + 1.0) - 1];
  if (idx_r3 != (int32_T)muDoubleScalarFloor(idx_r3)) {
    emlrtIntegerCheckR2012b(idx_r3, &j_emlrtDCI, &st);
  }
  if (((int8_T)idx_r3 < 1) || ((int8_T)idx_r3 > 48)) {
    emlrtDynamicBoundsCheckR2012b((int8_T)idx_r3, 1, 48, &n_emlrtBCI, &st);
  }
  if (idx_r3 + 1.0 != (int32_T)muDoubleScalarFloor(idx_r3 + 1.0)) {
    emlrtIntegerCheckR2012b(idx_r3 + 1.0, &j_emlrtDCI, &st);
  }
  if (((int8_T)(idx_r3 + 1.0) < 1) || ((int8_T)(idx_r3 + 1.0) > 48)) {
    emlrtDynamicBoundsCheckR2012b((int8_T)(idx_r3 + 1.0), 1, 48, &n_emlrtBCI,
                                  &st);
  }
  r3[0] = u[(int8_T)idx_r3 - 1];
  r3[1] = u[(int8_T)(idx_r3 + 1.0) - 1];
  emxInit_real_T(&st, &X_hist, 2, &d_emlrtRTEI);
  i1 = X_hist->size[0] * X_hist->size[1];
  X_hist->size[0] = 3;
  emxEnsureCapacity_real_T(&st, X_hist, i1, &d_emlrtRTEI);
  if (!(params[7] + 1.0 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(params[7] + 1.0, &f_emlrtDCI, &st);
  }
  d2 = (int32_T)muDoubleScalarFloor(params[7] + 1.0);
  if (params[7] + 1.0 != d2) {
    emlrtIntegerCheckR2012b(params[7] + 1.0, &e_emlrtDCI, &st);
  }
  i1 = X_hist->size[0] * X_hist->size[1];
  X_hist->size[1] = (int32_T)(params[7] + 1.0);
  emxEnsureCapacity_real_T(&st, X_hist, i1, &d_emlrtRTEI);
  X_hist_data = X_hist->data;
  if (params[7] + 1.0 != d2) {
    emlrtIntegerCheckR2012b(params[7] + 1.0, &g_emlrtDCI, &st);
  }
  loop_ub = 3 * (int32_T)(params[7] + 1.0);
  for (i1 = 0; i1 < loop_ub; i1++) {
    X_hist_data[i1] = 0.0;
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
  i1 = (int32_T)params[7];
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, params[7], mxDOUBLE_CLASS,
                                (int32_T)params[7], &b_emlrtRTEI, &st);
  for (n = 0; n < i1; n++) {
    b_i = (int32_T)(((uint32_T)n << 1) + 1U);
    if ((b_i < 1) || (b_i > i)) {
      emlrtDynamicBoundsCheckR2012b(b_i, 1, i, &j_emlrtBCI, &st);
    }
    loop_ub = (int32_T)((((real_T)n + 1.0) - 1.0) * 2.0 + 2.0);
    if ((loop_ub < 1) || (loop_ub > i)) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i, &k_emlrtBCI, &st);
    }
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
    g_corridor = get_single_block_p2s(&x_k[0], b_params, gPa);
    b_params[0] = params[14];
    b_params[1] = params[15];
    b_params[2] = params[16];
    b_params[3] = params[17];
    Pv = get_single_block_p2s(&x_k[0], b_params, gPv);
    b_params[0] = params[18];
    b_params[1] = params[19];
    b_params[2] = params[20];
    b_params[3] = params[21];
    Pg = get_single_block_p2s(&x_k[0], b_params, gPg);
    b_params[0] = params[22];
    b_params[1] = params[23];
    b_params[2] = params[24];
    b_params[3] = params[25];
    Pc = get_single_block_p2s(&x_k[0], b_params, gPc);
    c_st.site = &p_emlrtRSI;
    g_corridor = smooth_min_func(&c_st, g_corridor, Pv, gPa, gPv, g1);
    c_st.site = &q_emlrtRSI;
    P2 = smooth_min_func(&c_st, Pg, Pc, gPg, gPc, gPv);
    c_st.site = &r_emlrtRSI;
    smooth_min_func(&c_st, g_corridor, P2, g1, gPv, grad_P);
    g_corridor = Ts * u[b_i - 1];
    x_next[0] = x_k[0] + g_corridor * muDoubleScalarCos(x_k[2]);
    x_next[1] = x_k[1] + g_corridor * muDoubleScalarSin(x_k[2]);
    x_next[2] = x_k[2] + Ts * u[loop_ub - 1];
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
    g_corridor = get_single_block_p2s(&x_next[0], b_params, gPa);
    b_params[0] = params[14];
    b_params[1] = params[15];
    b_params[2] = params[16];
    b_params[3] = params[17];
    Pv = get_single_block_p2s(&x_next[0], b_params, gPv);
    b_params[0] = params[18];
    b_params[1] = params[19];
    b_params[2] = params[20];
    b_params[3] = params[21];
    Pg = get_single_block_p2s(&x_next[0], b_params, gPg);
    b_params[0] = params[22];
    b_params[1] = params[23];
    b_params[2] = params[24];
    b_params[3] = params[25];
    Pc = get_single_block_p2s(&x_next[0], b_params, gPc);
    c_st.site = &p_emlrtRSI;
    g_corridor = smooth_min_func(&c_st, g_corridor, Pv, gPa, gPv, g1);
    c_st.site = &q_emlrtRSI;
    P2 = smooth_min_func(&c_st, Pg, Pc, gPg, gPc, gPv);
    c_st.site = &r_emlrtRSI;
    smooth_min_func(&c_st, g_corridor, P2, g1, gPv, grad_P);
    b_st.site = &d_emlrtRSI;
    b_st.site = &e_emlrtRSI;
    b_st.site = &e_emlrtRSI;
    b_st.site = &e_emlrtRSI;
    b_st.site = &e_emlrtRSI;
    x_k[0] = x_next[0];
    x_k[1] = x_next[1];
    x_k[2] = x_next[2];
    if (((int32_T)((uint32_T)n + 2U) < 1) ||
        ((int32_T)((uint32_T)n + 2U) > X_hist->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)n + 2U), 1,
                                    X_hist->size[1], &g_emlrtBCI, &st);
    }
    b_i = 3 * (n + 1);
    X_hist_data[b_i] = x_next[0];
    X_hist_data[b_i + 1] = x_next[1];
    X_hist_data[b_i + 2] = x_next[2];
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }
  /*  ===================================================================== */
  /*  TERMINAL E BACKWARD PASS */
  /*  ===================================================================== */
  if (params[7] + 1.0 != d2) {
    emlrtIntegerCheckR2012b(params[7] + 1.0, &c_emlrtDCI, &st);
  }
  if (((int32_T)(params[7] + 1.0) < 1) ||
      ((int32_T)(params[7] + 1.0) > X_hist->size[1])) {
    emlrtDynamicBoundsCheckR2012b((int32_T)(params[7] + 1.0), 1,
                                  X_hist->size[1], &f_emlrtBCI, &st);
  }
  /*  Penalidade eta_eq * Ts^2 * (v_s^2 + w_s^2) removida! */
  /*  ===================================================================== */
  /*  GEOFENCE DE SEGMENTOS (Contenção Convexa Suavizada) */
  /*  ===================================================================== */
  b_st.site = &f_emlrtRSI;
  calc_segment_p2s_penalty(&b_st, xs, r1, &params[10], gPv, gPg);
  b_st.site = &g_emlrtRSI;
  calc_segment_p2s_penalty(&b_st, r1, r2, &params[10], gPc, g1);
  b_st.site = &h_emlrtRSI;
  calc_segment_p2s_penalty(&b_st, r2, r3, &params[10], grad_P, gP_seg2_r3);
  b_st.site = &i_emlrtRSI;
  calc_segment_p2s_penalty(&b_st, r3, &params[3], &params[10], gP_seg3_r3, gPa);
  memset(&grad[0], 0, 48U * sizeof(real_T));
  emxInit_real_T(&st, &grad_U, 1, &e_emlrtRTEI);
  if (!(d >= 0.0)) {
    emlrtNonNegativeCheckR2012b(d, &i_emlrtDCI, &st);
  }
  d2 = (int32_T)muDoubleScalarFloor(d);
  if (d != d2) {
    emlrtIntegerCheckR2012b(d, &h_emlrtDCI, &st);
  }
  i1 = grad_U->size[0];
  grad_U->size[0] = (int32_T)d;
  emxEnsureCapacity_real_T(&st, grad_U, i1, &e_emlrtRTEI);
  grad_U_data = grad_U->data;
  if (d != d2) {
    emlrtIntegerCheckR2012b(d, &h_emlrtDCI, &st);
  }
  loop_ub = (int32_T)d;
  for (i1 = 0; i1 < loop_ub; i1++) {
    grad_U_data[i1] = 0.0;
  }
  __m128d b_r2;
  __m128d b_r3;
  __m128d r4;
  __m128d r5;
  __m128d r7;
  __m128d r8;
  /*  (Inicialização existente de p_n) */
  x_k[0] = 0.0;
  x_k[1] = 0.0;
  x_k[2] = 0.0;
  /*  (Inicialização existente de grad_xs e grad_r1) */
  /*  Acumulação Incondicional dos Gradientes de Segmento */
  /*  Cada ponto r intermediário acumula gradiente das duas retas conectadas a
   * ele */
  r = _mm_loadu_pd(&X_hist_data[3 * ((int32_T)(params[7] + 1.0) - 1)]);
  b_r1 = _mm_loadu_pd(&xs[0]);
  r = _mm_mul_pd(_mm_set1_pd(2.0 * params[26]), _mm_sub_pd(r, b_r1));
  _mm_storeu_pd(&x_k[0], r);
  b_r2 = _mm_loadu_pd(&r1[0]);
  b_r3 = _mm_loadu_pd(&gPv[0]);
  r4 = _mm_set1_pd(2.0 * params[28]);
  r5 = _mm_set1_pd(params[27]);
  r6 = _mm_set1_pd(-1.0);
  _mm_storeu_pd(&grad_xs[0],
                _mm_add_pd(_mm_sub_pd(_mm_mul_pd(r, r6),
                                      _mm_mul_pd(r4, _mm_sub_pd(b_r2, b_r1))),
                           _mm_mul_pd(r5, b_r3)));
  r = _mm_loadu_pd(&r2[0]);
  b_r3 = _mm_loadu_pd(&gPg[0]);
  r7 = _mm_loadu_pd(&gPc[0]);
  r8 = _mm_set1_pd(2.0);
  _mm_storeu_pd(
      &xs[0],
      _mm_add_pd(
          _mm_mul_pd(r4, _mm_sub_pd(_mm_sub_pd(_mm_mul_pd(r8, b_r2), b_r1), r)),
          _mm_mul_pd(r5, _mm_add_pd(b_r3, r7))));
  b_r1 = _mm_loadu_pd(&r3[0]);
  b_r3 = _mm_loadu_pd(&g1[0]);
  r7 = _mm_loadu_pd(&grad_P[0]);
  _mm_storeu_pd(
      &r1[0],
      _mm_add_pd(
          _mm_mul_pd(r4, _mm_sub_pd(_mm_sub_pd(_mm_mul_pd(r8, r), b_r2), b_r1)),
          _mm_mul_pd(r5, _mm_add_pd(b_r3, r7))));
  b_r2 = _mm_loadu_pd(&gP_seg2_r3[0]);
  b_r3 = _mm_loadu_pd(&gP_seg3_r3[0]);
  _mm_storeu_pd(
      &r3[0],
      _mm_add_pd(_mm_mul_pd(r4, _mm_sub_pd(_mm_sub_pd(_mm_mul_pd(r8, b_r1), r),
                                           _mm_loadu_pd(&params[3]))),
                 _mm_mul_pd(r5, _mm_add_pd(b_r2, b_r3))));
  i1 = (int32_T) - ((-1.0 - params[7]) + 1.0);
  emlrtForLoopVectorCheckR2021a(params[7], -1.0, 1.0, mxDOUBLE_CLASS,
                                (int32_T) - ((-1.0 - params[7]) + 1.0),
                                &emlrtRTEI, &st);
  if ((int32_T) - ((-1.0 - params[7]) + 1.0) - 1 >= 0) {
    b_Ts[4] = 0.0;
    b_Ts[1] = 0.0;
    b_Ts[3] = 0.0;
    b_Ts[5] = params[8];
  }
  if (i1 - 1 >= 0) {
    dv[0] = 1.0;
    dv[1] = 0.0;
    dv[3] = 0.0;
    dv[4] = 1.0;
    dv[6] = 0.0;
    dv[7] = 0.0;
    dv[8] = 1.0;
  }
  for (n = 0; n < i1; n++) {
    real_T P_k;
    real_T b_grad_xs_tmp;
    real_T b_n;
    real_T grad_xs_tmp;
    real_T v_n;
    uint32_T b_u;
    uint32_T u1;
    b_n = params[7] - (real_T)n;
    if (b_n != (int32_T)muDoubleScalarFloor(b_n)) {
      emlrtIntegerCheckR2012b(b_n, &b_emlrtDCI, &st);
    }
    if (((int32_T)b_n < 1) || ((int32_T)b_n > X_hist->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)b_n, 1, X_hist->size[1],
                                    &e_emlrtBCI, &st);
    }
    if (((int32_T)(b_n + 1.0) < 1) ||
        ((int32_T)(b_n + 1.0) > X_hist->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_n + 1.0), 1, X_hist->size[1],
                                    &d_emlrtBCI, &st);
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
    grad_xs_tmp = 80.0 * (X_hist_data[loop_ub] - xs_tmp);
    grad_xs[0] -= grad_xs_tmp;
    b_grad_xs_tmp = 80.0 * (X_hist_data[loop_ub + 1] - b_xs_tmp);
    grad_xs[1] -= b_grad_xs_tmp;
    /*  Avaliação Suavizada Ponto a Ponto para CBF */
    b_st.site = &j_emlrtRSI;
    /*  =========================================================================
     */
    /*  FUNÇÃO AUXILIAR: Penalidade Ponto a Ponto (Smooth Min para a CBF) */
    /*  =========================================================================
     */
    b_params[0] = params[10];
    b_params[1] = params[11];
    b_params[2] = params[12];
    b_params[3] = params[13];
    g_corridor = get_single_block_p2s(
        &(*(real_T(*)[3]) & X_hist_data[3 * ((int32_T)b_n - 1)])[0], b_params,
        gPa);
    b_params[0] = params[14];
    b_params[1] = params[15];
    b_params[2] = params[16];
    b_params[3] = params[17];
    Pv = get_single_block_p2s(
        &(*(real_T(*)[3]) & X_hist_data[3 * ((int32_T)b_n - 1)])[0], b_params,
        gPv);
    b_params[0] = params[18];
    b_params[1] = params[19];
    b_params[2] = params[20];
    b_params[3] = params[21];
    Pg = get_single_block_p2s(
        &(*(real_T(*)[3]) & X_hist_data[3 * ((int32_T)b_n - 1)])[0], b_params,
        gPg);
    b_params[0] = params[22];
    b_params[1] = params[23];
    b_params[2] = params[24];
    b_params[3] = params[25];
    Pc = get_single_block_p2s(
        &(*(real_T(*)[3]) & X_hist_data[3 * ((int32_T)b_n - 1)])[0], b_params,
        gPc);
    c_st.site = &p_emlrtRSI;
    g_corridor = smooth_min_func(&c_st, g_corridor, Pv, gPa, gPv, g1);
    c_st.site = &q_emlrtRSI;
    P2 = smooth_min_func(&c_st, Pg, Pc, gPg, gPc, gPv);
    c_st.site = &r_emlrtRSI;
    P_k = smooth_min_func(&c_st, g_corridor, P2, g1, gPv, grad_P);
    b_st.site = &k_emlrtRSI;
    /*  =========================================================================
     */
    /*  FUNÇÃO AUXILIAR: Penalidade Ponto a Ponto (Smooth Min para a CBF) */
    /*  =========================================================================
     */
    b_params[0] = params[10];
    b_params[1] = params[11];
    b_params[2] = params[12];
    b_params[3] = params[13];
    g_corridor = get_single_block_p2s(
        &(*(real_T(*)[3]) & X_hist_data[3 * (int32_T)b_n])[0], b_params, gPa);
    b_params[0] = params[14];
    b_params[1] = params[15];
    b_params[2] = params[16];
    b_params[3] = params[17];
    Pv = get_single_block_p2s(
        &(*(real_T(*)[3]) & X_hist_data[3 * (int32_T)b_n])[0], b_params, gPv);
    b_params[0] = params[18];
    b_params[1] = params[19];
    b_params[2] = params[20];
    b_params[3] = params[21];
    Pg = get_single_block_p2s(
        &(*(real_T(*)[3]) & X_hist_data[3 * (int32_T)b_n])[0], b_params, gPg);
    b_params[0] = params[22];
    b_params[1] = params[23];
    b_params[2] = params[24];
    b_params[3] = params[25];
    Pc = get_single_block_p2s(
        &(*(real_T(*)[3]) & X_hist_data[3 * (int32_T)b_n])[0], b_params, gPc);
    c_st.site = &p_emlrtRSI;
    g_corridor = smooth_min_func(&c_st, g_corridor, Pv, gPa, gPv, g1);
    c_st.site = &q_emlrtRSI;
    P2 = smooth_min_func(&c_st, Pg, Pc, gPg, gPc, gPv);
    c_st.site = &r_emlrtRSI;
    g_corridor = smooth_min_func(&c_st, g_corridor, P2, g1, gPv, gPa);
    g_corridor = (1.0 - gamma_safe) * -P_k - (-g_corridor);
    x_next[0] = 0.0;
    grad_x_next_cbf[0] = 0.0;
    x_next[1] = 0.0;
    grad_x_next_cbf[1] = 0.0;
    x_next[2] = 0.0;
    grad_x_next_cbf[2] = 0.0;
    if (g_corridor > 0.0) {
      r = _mm_loadu_pd(&grad_P[0]);
      b_r1 = _mm_set1_pd(2.0 * eta_safe * g_corridor);
      _mm_storeu_pd(&x_next[0],
                    _mm_mul_pd(b_r1, _mm_mul_pd(_mm_set1_pd(1.0 - gamma_safe),
                                                _mm_mul_pd(r, r6))));
      r = _mm_loadu_pd(&gPa[0]);
      _mm_storeu_pd(&grad_x_next_cbf[0], _mm_mul_pd(b_r1, r));
    }
    g_corridor = X_hist_data[loop_ub + 2];
    Pc = muDoubleScalarCos(g_corridor);
    Pg = muDoubleScalarSin(g_corridor);
    grad_x_next_cbf[0] += x_k[0];
    grad_x_next_cbf[1] += x_k[1];
    grad_x_next_cbf[2] += x_k[2];
    dv[2] = -Ts * v_n * Pg;
    dv[5] = Ts * v_n * Pc;
    dv1[0] = grad_xs_tmp + x_next[0];
    dv1[1] = b_grad_xs_tmp + x_next[1];
    dv1[2] = x_next[2];
    g_corridor = grad_x_next_cbf[0];
    Pv = grad_x_next_cbf[1];
    P2 = grad_x_next_cbf[2];
    r = _mm_loadu_pd(&dv[0]);
    r = _mm_mul_pd(r, _mm_set1_pd(g_corridor));
    b_r1 = _mm_loadu_pd(&dv[3]);
    b_r1 = _mm_mul_pd(b_r1, _mm_set1_pd(Pv));
    r = _mm_add_pd(r, b_r1);
    b_r1 = _mm_loadu_pd(&dv[6]);
    b_r1 = _mm_mul_pd(b_r1, _mm_set1_pd(P2));
    r = _mm_add_pd(r, b_r1);
    b_r1 = _mm_loadu_pd(&dv1[0]);
    r = _mm_add_pd(r, b_r1);
    _mm_storeu_pd(&x_k[0], r);
    x_k[2] = ((dv[2] * g_corridor + dv[5] * Pv) + dv[8] * P2) + dv1[2];
    u1 = (uint32_T)b_n << 1;
    if (b_u + 1U > u1) {
      b_i = 0;
      loop_ub = 0;
    } else {
      if (((int32_T)(b_u + 1U) < 1) ||
          ((int32_T)(b_u + 1U) > grad_U->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(b_u + 1U), 1, grad_U->size[0],
                                      &c_emlrtBCI, &st);
      }
      b_i = (int32_T)b_u;
      if (((int32_T)u1 < 1) || ((int32_T)u1 > grad_U->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)u1, 1, grad_U->size[0],
                                      &b_emlrtBCI, &st);
      }
      loop_ub = (int32_T)u1;
    }
    loop_ub -= b_i;
    if (loop_ub != 2) {
      emlrtSubAssignSizeCheck1dR2017a(loop_ub, 2, &b_emlrtECI, &st);
    }
    b_Ts[0] = Ts * Pc;
    b_Ts[2] = Ts * Pg;
    g_corridor = grad_x_next_cbf[0];
    Pv = grad_x_next_cbf[1];
    P2 = grad_x_next_cbf[2];
    r = _mm_loadu_pd(&b_Ts[0]);
    r = _mm_mul_pd(r, _mm_set1_pd(g_corridor));
    b_r1 = _mm_loadu_pd(&b_Ts[2]);
    b_r1 = _mm_mul_pd(b_r1, _mm_set1_pd(Pv));
    r = _mm_add_pd(r, b_r1);
    b_r1 = _mm_loadu_pd(&b_Ts[4]);
    b_r1 = _mm_mul_pd(b_r1, _mm_set1_pd(P2));
    r = _mm_add_pd(r, b_r1);
    _mm_storeu_pd(&r2[0], r);
    gPa[0] = 10.0 * v_n;
    gPa[1] = 0.02 * u[(int32_T)b_u + 1];
    r = _mm_loadu_pd(&r2[0]);
    b_r1 = _mm_loadu_pd(&gPa[0]);
    _mm_storeu_pd(&grad_U_data[b_i], _mm_add_pd(r, b_r1));
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }
  emxFree_real_T(&st, &X_hist);
  if (d < 1.0) {
    loop_ub = 0;
  } else {
    if (d != d2) {
      emlrtIntegerCheckR2012b(d, &emlrtDCI, &st);
    }
    if (((int32_T)d < 1) || ((int32_T)d > 48)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, 48, &emlrtBCI, &st);
    }
    loop_ub = (int32_T)d;
  }
  if (loop_ub != grad_U->size[0]) {
    emlrtSubAssignSizeCheck1dR2017a(loop_ub, grad_U->size[0], &emlrtECI, &st);
  }
  for (i = 0; i < loop_ub; i++) {
    grad[i] = grad_U_data[i];
  }
  emxFree_real_T(&st, &grad_U);
  grad[(int8_T)d1 - 1] = grad_xs[0];
  grad[(int8_T)(d1 + 1.0) - 1] = grad_xs[1];
  grad[(int8_T)idx_r1 - 1] = xs[0];
  grad[(int8_T)(idx_r1 + 1.0) - 1] = xs[1];
  grad[(int8_T)idx_r2 - 1] = r1[0];
  grad[(int8_T)(idx_r2 + 1.0) - 1] = r1[1];
  grad[(int8_T)idx_r3 - 1] = r3[0];
  grad[(int8_T)(idx_r3 + 1.0) - 1] = r3[1];
  memset(&grad_smooth[0], 0, 48U * sizeof(real_T));
  /*  Calcula as derivadas parciais  */
  for (b_i = 0; b_i < 23; b_i++) {
    /*  Derivada em relação a v */
    loop_ub = (b_i + 1) << 1;
    g_corridor = u[loop_ub] - u[loop_ub - 2];
    /*  v_{i+1} - v_i */
    grad_smooth[loop_ub - 2] -= 0.4 * g_corridor;
    grad_smooth[loop_ub] += 0.4 * g_corridor;
    /*  Derivada em relação a w */
    g_corridor = u[loop_ub + 1] - u[loop_ub - 1];
    /*  w_{i+1} - w_i */
    grad_smooth[loop_ub - 1] -= 0.4 * g_corridor;
    grad_smooth[loop_ub + 1] += 0.4 * g_corridor;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
  /*  5. Gradiente total */
  for (i = 0; i <= 46; i += 2) {
    r = _mm_loadu_pd(&grad[i]);
    b_r1 = _mm_loadu_pd(&grad_smooth[i]);
    _mm_storeu_pd(&grad[i], _mm_add_pd(r, b_r1));
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

/* End of code generation (wrapper_grad.c) */
