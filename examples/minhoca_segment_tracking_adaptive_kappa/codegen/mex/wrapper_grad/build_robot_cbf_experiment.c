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
#include "sumMatrixIncludeNaN.h"
#include "wrapper_grad_data.h"
#include "wrapper_grad_emxutil.h"
#include "wrapper_grad_types.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo c_emlrtRSI = {
    63,                           /* lineNo */
    "build_robot_cbf_experiment", /* fcnName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m" /* pathName */
};

static emlrtRSInfo d_emlrtRSI = {
    71,                           /* lineNo */
    "build_robot_cbf_experiment", /* fcnName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m" /* pathName */
};

static emlrtRSInfo h_emlrtRSI = {
    105,                          /* lineNo */
    "build_robot_cbf_experiment", /* fcnName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m" /* pathName */
};

static emlrtRSInfo i_emlrtRSI = {
    109,                          /* lineNo */
    "build_robot_cbf_experiment", /* fcnName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m" /* pathName */
};

static emlrtRSInfo j_emlrtRSI = {
    113,                          /* lineNo */
    "build_robot_cbf_experiment", /* fcnName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m" /* pathName */
};

static emlrtRSInfo k_emlrtRSI = {
    117,                          /* lineNo */
    "build_robot_cbf_experiment", /* fcnName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m" /* pathName */
};

static emlrtRSInfo n_emlrtRSI = {
    163,                          /* lineNo */
    "build_robot_cbf_experiment", /* fcnName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m" /* pathName */
};

static emlrtRSInfo o_emlrtRSI = {
    166,                          /* lineNo */
    "build_robot_cbf_experiment", /* fcnName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m" /* pathName */
};

static emlrtRSInfo cb_emlrtRSI = {
    298,                      /* lineNo */
    "calc_point_p2s_penalty", /* fcnName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m" /* pathName */
};

static emlrtRSInfo db_emlrtRSI = {
    299,                      /* lineNo */
    "calc_point_p2s_penalty", /* fcnName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m" /* pathName */
};

static emlrtRSInfo eb_emlrtRSI = {
    300,                      /* lineNo */
    "calc_point_p2s_penalty", /* fcnName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m" /* pathName */
};

static emlrtRSInfo fb_emlrtRSI = {
    248,               /* lineNo */
    "smooth_min_func", /* fcnName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m" /* pathName */
};

static emlrtRSInfo ob_emlrtRSI = {
    279,                        /* lineNo */
    "calc_segment_p2s_penalty", /* fcnName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m" /* pathName */
};

static emlrtRSInfo pb_emlrtRSI = {
    280,                        /* lineNo */
    "calc_segment_p2s_penalty", /* fcnName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m" /* pathName */
};

static emlrtRSInfo qb_emlrtRSI = {
    282,                        /* lineNo */
    "calc_segment_p2s_penalty", /* fcnName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m" /* pathName */
};

static emlrtECInfo emlrtECI = {
    -1,                           /* nDims */
    195,                          /* lineNo */
    5,                            /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m" /* pName */
};

static emlrtBCInfo emlrtBCI = {
    1,                            /* iFirst */
    50,                           /* iLast */
    195,                          /* lineNo */
    12,                           /* colNo */
    "grad",                       /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m", /* pName */
    0                                             /* checkKind */
};

static emlrtDCInfo emlrtDCI = {
    195,                          /* lineNo */
    12,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m", /* pName */
    1                                             /* checkKind */
};

static emlrtECInfo b_emlrtECI = {
    -1,                           /* nDims */
    192,                          /* lineNo */
    9,                            /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m" /* pName */
};

static emlrtBCInfo b_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    192,                          /* lineNo */
    30,                           /* colNo */
    "grad_U",                     /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m", /* pName */
    0                                             /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    192,                          /* lineNo */
    16,                           /* colNo */
    "grad_U",                     /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m", /* pName */
    0                                             /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    151,                          /* lineNo */
    28,                           /* colNo */
    "X_hist",                     /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m", /* pName */
    0                                             /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    150,                          /* lineNo */
    25,                           /* colNo */
    "X_hist",                     /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m", /* pName */
    0                                             /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = {
    150,                          /* lineNo */
    25,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m", /* pName */
    1                                             /* checkKind */
};

static emlrtRTEInfo emlrtRTEI = {
    149,                          /* lineNo */
    13,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m" /* pName */
};

static emlrtBCInfo f_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    89,                           /* lineNo */
    21,                           /* colNo */
    "X_hist",                     /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m", /* pName */
    0                                             /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = {
    89,                           /* lineNo */
    21,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m", /* pName */
    1                                             /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    81,                           /* lineNo */
    19,                           /* colNo */
    "X_hist",                     /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m", /* pName */
    0                                             /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = {
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

static emlrtRTEInfo b_emlrtRTEI = {
    59,                           /* lineNo */
    13,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m" /* pName */
};

static emlrtBCInfo i_emlrtBCI = {
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

static emlrtDCInfo d_emlrtDCI = {
    22,                           /* lineNo */
    14,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m", /* pName */
    1                                             /* checkKind */
};

static emlrtDCInfo e_emlrtDCI = {
    36,                           /* lineNo */
    23,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m", /* pName */
    1                                             /* checkKind */
};

static emlrtDCInfo f_emlrtDCI = {
    36,                           /* lineNo */
    23,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m", /* pName */
    4                                             /* checkKind */
};

static emlrtDCInfo g_emlrtDCI = {
    36,                           /* lineNo */
    5,                            /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m", /* pName */
    1                                             /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    60,                           /* lineNo */
    17,                           /* colNo */
    "u",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m", /* pName */
    0                                             /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    61,                           /* lineNo */
    17,                           /* colNo */
    "u",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m", /* pName */
    0                                             /* checkKind */
};

static emlrtDCInfo h_emlrtDCI = {
    123,                          /* lineNo */
    5,                            /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m", /* pName */
    1                                             /* checkKind */
};

static emlrtDCInfo i_emlrtDCI = {
    123,                          /* lineNo */
    5,                            /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m", /* pName */
    4                                             /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    152,                          /* lineNo */
    17,                           /* colNo */
    "u",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m", /* pName */
    0                                             /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    152,                          /* lineNo */
    39,                           /* colNo */
    "u",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m", /* pName */
    0                                             /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = {
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

static emlrtDCInfo j_emlrtDCI = {
    34,                           /* lineNo */
    12,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m", /* pName */
    1                                             /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = {
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

static emlrtDCInfo k_emlrtDCI = {
    33,                           /* lineNo */
    12,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m", /* pName */
    1                                             /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = {
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

static emlrtDCInfo l_emlrtDCI = {
    32,                           /* lineNo */
    12,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m", /* pName */
    1                                             /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = {
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

static emlrtDCInfo m_emlrtDCI = {
    24,                           /* lineNo */
    12,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m", /* pName */
    1                                             /* checkKind */
};

static emlrtBCInfo r_emlrtBCI = {
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

static emlrtDCInfo n_emlrtDCI = {
    23,                           /* lineNo */
    12,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m", /* pName */
    1                                             /* checkKind */
};

static emlrtRTEInfo c_emlrtRTEI = {
    13,     /* lineNo */
    9,      /* colNo */
    "sqrt", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\elfun\\sqrt.m" /* pName
                                                                       */
};

static emlrtRTEInfo d_emlrtRTEI = {
    36,                           /* lineNo */
    5,                            /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m" /* pName */
};

static emlrtRTEInfo e_emlrtRTEI = {
    123,                          /* lineNo */
    5,                            /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m" /* pName */
};

/* Function Declarations */
static real_T b_smooth_min_func(const emlrtStack *sp, real_T a, real_T b,
                                const real_T ga[4], const real_T gb[4],
                                real_T gM[4]);

static real_T calc_point_p2s_penalty(const emlrtStack *sp, const real_T pt[2],
                                     const real_T blocks[16], real_T grad_P[2]);

static real_T calc_segment_p2s_penalty(const emlrtStack *sp, const real_T pa[2],
                                       const real_T pb[2],
                                       const real_T blocks[16],
                                       real_T grad_pa[2], real_T grad_pb[2]);

static real_T get_single_block_p2s(const real_T pt[2], const real_T blk[4],
                                   real_T gP[2]);

static real_T phi_func(real_T s, real_T *grad);

static real_T smooth_min_func(const emlrtStack *sp, real_T a, real_T b,
                              const real_T ga[2], const real_T gb[2],
                              real_T gM[2]);

/* Function Definitions */
static real_T b_smooth_min_func(const emlrtStack *sp, real_T a, real_T b,
                                const real_T ga[4], const real_T gb[4],
                                real_T gM[4])
{
  __m128d r;
  __m128d r1;
  __m128d r2;
  __m128d r3;
  emlrtStack st;
  real_T M;
  real_T delta;
  real_T diff;
  st.prev = sp;
  st.tls = sp->tls;
  /*  =========================================================================
   */
  /*  FUNÇÃO AUXILIAR: Mínimo Suave Base (Smooth Min) */
  /*  =========================================================================
   */
  /*  Fator de suavização Numérica */
  diff = a - b;
  delta = diff * diff;
  st.site = &fb_emlrtRSI;
  if (delta + 1.0E-10 < 0.0) {
    emlrtErrorWithMessageIdR2018a(
        &st, &c_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
        "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
  }
  delta = muDoubleScalarSqrt(delta + 1.0E-10);
  M = 0.5 * ((a + b) - delta);
  /*  O gradiente repassa perfeitamente a direção correspondente ao menor valor
   */
  r = _mm_loadu_pd(&ga[0]);
  r1 = _mm_loadu_pd(&gb[0]);
  r2 = _mm_set1_pd(0.5);
  r3 = _mm_set1_pd(diff / delta);
  _mm_storeu_pd(&gM[0],
                _mm_mul_pd(r2, _mm_sub_pd(_mm_add_pd(r, r1),
                                          _mm_mul_pd(r3, _mm_sub_pd(r, r1)))));
  r = _mm_loadu_pd(&ga[2]);
  r1 = _mm_loadu_pd(&gb[2]);
  _mm_storeu_pd(&gM[2],
                _mm_mul_pd(r2, _mm_sub_pd(_mm_add_pd(r, r1),
                                          _mm_mul_pd(r3, _mm_sub_pd(r, r1)))));
  return M;
}

static real_T calc_point_p2s_penalty(const emlrtStack *sp, const real_T pt[2],
                                     const real_T blocks[16], real_T grad_P[2])
{
  emlrtStack st;
  real_T b_g1[2];
  real_T gPa[2];
  real_T gPc[2];
  real_T gPg[2];
  real_T gPv[2];
  real_T b_v1;
  real_T b_v2;
  real_T b_v3;
  real_T b_v4;
  real_T c_v1;
  real_T c_v2;
  real_T c_v3;
  real_T c_v4;
  real_T d_v1;
  real_T d_v2;
  real_T d_v3;
  real_T d_v4;
  real_T g1;
  real_T g2;
  real_T g3;
  real_T g4;
  real_T v1;
  real_T v2;
  real_T v3;
  real_T v4;
  st.prev = sp;
  st.tls = sp->tls;
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
  v1 = phi_func(blocks[0] - pt[0], &g1);
  v2 = phi_func(pt[0] - blocks[1], &g2);
  v3 = phi_func(blocks[2] - pt[1], &g3);
  v4 = phi_func(pt[1] - blocks[3], &g4);
  gPa[0] = 0.25 * (-g1 + g2);
  gPa[1] = 0.25 * (-g3 + g4);
  /*  =========================================================================
   */
  /*  FUNÇÃO AUXILIAR: P2S-HSD para UM Polítopo Convexo */
  /*  =========================================================================
   */
  b_v1 = phi_func(blocks[4] - pt[0], &g1);
  b_v2 = phi_func(pt[0] - blocks[5], &g2);
  b_v3 = phi_func(blocks[6] - pt[1], &g3);
  b_v4 = phi_func(pt[1] - blocks[7], &g4);
  gPv[0] = 0.25 * (-g1 + g2);
  gPv[1] = 0.25 * (-g3 + g4);
  /*  =========================================================================
   */
  /*  FUNÇÃO AUXILIAR: P2S-HSD para UM Polítopo Convexo */
  /*  =========================================================================
   */
  c_v1 = phi_func(blocks[8] - pt[0], &g1);
  c_v2 = phi_func(pt[0] - blocks[9], &g2);
  c_v3 = phi_func(blocks[10] - pt[1], &g3);
  c_v4 = phi_func(pt[1] - blocks[11], &g4);
  gPg[0] = 0.25 * (-g1 + g2);
  gPg[1] = 0.25 * (-g3 + g4);
  /*  =========================================================================
   */
  /*  FUNÇÃO AUXILIAR: P2S-HSD para UM Polítopo Convexo */
  /*  =========================================================================
   */
  d_v1 = phi_func(blocks[12] - pt[0], &g1);
  d_v2 = phi_func(pt[0] - blocks[13], &g2);
  d_v3 = phi_func(blocks[14] - pt[1], &g3);
  d_v4 = phi_func(pt[1] - blocks[15], &g4);
  gPc[0] = 0.25 * (-g1 + g2);
  gPc[1] = 0.25 * (-g3 + g4);
  st.site = &cb_emlrtRSI;
  g2 = smooth_min_func(&st, 0.25 * (((v1 + v2) + v3) + v4),
                       0.25 * (((b_v1 + b_v2) + b_v3) + b_v4), gPa, gPv, b_g1);
  st.site = &db_emlrtRSI;
  g1 = smooth_min_func(&st, 0.25 * (((c_v1 + c_v2) + c_v3) + c_v4),
                       0.25 * (((d_v1 + d_v2) + d_v3) + d_v4), gPg, gPc, gPa);
  st.site = &eb_emlrtRSI;
  return smooth_min_func(&st, g2, g1, b_g1, gPa, grad_P);
}

static real_T calc_segment_p2s_penalty(const emlrtStack *sp, const real_T pa[2],
                                       const real_T pb[2],
                                       const real_T blocks[16],
                                       real_T grad_pa[2], real_T grad_pb[2])
{
  emlrtStack st;
  real_T gM12[4];
  real_T gM34[4];
  real_T gPa1[4];
  real_T gPa2[4];
  real_T Cost;
  real_T b_g1;
  real_T b_g2;
  real_T b_g3;
  real_T b_g4;
  real_T b_v1;
  real_T b_v2;
  real_T b_v3;
  real_T b_v4;
  real_T c_g1;
  real_T c_g2;
  real_T c_g3;
  real_T c_g4;
  real_T c_v1;
  real_T c_v2;
  real_T c_v3;
  real_T c_v4;
  real_T d_g1;
  real_T d_g2;
  real_T d_g3;
  real_T d_g4;
  real_T d_v1;
  real_T d_v2;
  real_T d_v3;
  real_T d_v4;
  real_T e_g1;
  real_T e_g2;
  real_T e_g3;
  real_T e_g4;
  real_T e_v1;
  real_T e_v2;
  real_T e_v3;
  real_T e_v4;
  real_T f_g1;
  real_T f_g2;
  real_T f_g3;
  real_T f_g4;
  real_T f_v1;
  real_T f_v2;
  real_T f_v3;
  real_T f_v4;
  real_T g1;
  real_T g2;
  real_T g3;
  real_T g4;
  real_T g_g1;
  real_T g_g2;
  real_T g_g3;
  real_T g_g4;
  real_T g_v1;
  real_T g_v2;
  real_T g_v3;
  real_T g_v4;
  real_T h_g1;
  real_T h_g2;
  real_T h_g3;
  real_T h_g4;
  real_T h_v1;
  real_T h_v2;
  real_T h_v3;
  real_T h_v4;
  real_T v1;
  real_T v2;
  real_T v3;
  real_T v4;
  st.prev = sp;
  st.tls = sp->tls;
  /*  =========================================================================
   */
  /*  FUNÇÃO AUXILIAR: Penalidade de Segmento (Contenção Convexa Suavizada) */
  /*  =========================================================================
   */
  /*  =========================================================================
   */
  /*  FUNÇÃO AUXILIAR: P2S-HSD para UM Polítopo Convexo */
  /*  =========================================================================
   */
  v1 = phi_func(blocks[0] - pa[0], &g1);
  v2 = phi_func(pa[0] - blocks[1], &g2);
  v3 = phi_func(blocks[2] - pa[1], &g3);
  v4 = phi_func(pa[1] - blocks[3], &g4);
  /*  =========================================================================
   */
  /*  FUNÇÃO AUXILIAR: P2S-HSD para UM Polítopo Convexo */
  /*  =========================================================================
   */
  b_v1 = phi_func(blocks[4] - pa[0], &b_g1);
  b_v2 = phi_func(pa[0] - blocks[5], &b_g2);
  b_v3 = phi_func(blocks[6] - pa[1], &b_g3);
  b_v4 = phi_func(pa[1] - blocks[7], &b_g4);
  /*  =========================================================================
   */
  /*  FUNÇÃO AUXILIAR: P2S-HSD para UM Polítopo Convexo */
  /*  =========================================================================
   */
  c_v1 = phi_func(blocks[8] - pa[0], &c_g1);
  c_v2 = phi_func(pa[0] - blocks[9], &c_g2);
  c_v3 = phi_func(blocks[10] - pa[1], &c_g3);
  c_v4 = phi_func(pa[1] - blocks[11], &c_g4);
  /*  =========================================================================
   */
  /*  FUNÇÃO AUXILIAR: P2S-HSD para UM Polítopo Convexo */
  /*  =========================================================================
   */
  d_v1 = phi_func(blocks[12] - pa[0], &d_g1);
  d_v2 = phi_func(pa[0] - blocks[13], &d_g2);
  d_v3 = phi_func(blocks[14] - pa[1], &d_g3);
  d_v4 = phi_func(pa[1] - blocks[15], &d_g4);
  /*  =========================================================================
   */
  /*  FUNÇÃO AUXILIAR: P2S-HSD para UM Polítopo Convexo */
  /*  =========================================================================
   */
  e_v1 = phi_func(blocks[0] - pb[0], &e_g1);
  e_v2 = phi_func(pb[0] - blocks[1], &e_g2);
  e_v3 = phi_func(blocks[2] - pb[1], &e_g3);
  e_v4 = phi_func(pb[1] - blocks[3], &e_g4);
  /*  =========================================================================
   */
  /*  FUNÇÃO AUXILIAR: P2S-HSD para UM Polítopo Convexo */
  /*  =========================================================================
   */
  f_v1 = phi_func(blocks[4] - pb[0], &f_g1);
  f_v2 = phi_func(pb[0] - blocks[5], &f_g2);
  f_v3 = phi_func(blocks[6] - pb[1], &f_g3);
  f_v4 = phi_func(pb[1] - blocks[7], &f_g4);
  /*  =========================================================================
   */
  /*  FUNÇÃO AUXILIAR: P2S-HSD para UM Polítopo Convexo */
  /*  =========================================================================
   */
  g_v1 = phi_func(blocks[8] - pb[0], &g_g1);
  g_v2 = phi_func(pb[0] - blocks[9], &g_g2);
  g_v3 = phi_func(blocks[10] - pb[1], &g_g3);
  g_v4 = phi_func(pb[1] - blocks[11], &g_g4);
  /*  =========================================================================
   */
  /*  FUNÇÃO AUXILIAR: P2S-HSD para UM Polítopo Convexo */
  /*  =========================================================================
   */
  h_v1 = phi_func(blocks[12] - pb[0], &h_g1);
  h_v2 = phi_func(pb[0] - blocks[13], &h_g2);
  h_v3 = phi_func(blocks[14] - pb[1], &h_g3);
  h_v4 = phi_func(pb[1] - blocks[15], &h_g4);
  gPa1[0] = 0.25 * (-g1 + g2);
  gPa1[2] = 0.25 * (-e_g1 + e_g2);
  gPa2[0] = 0.25 * (-b_g1 + b_g2);
  gPa2[2] = 0.25 * (-f_g1 + f_g2);
  gPa1[1] = 0.25 * (-g3 + g4);
  gPa1[3] = 0.25 * (-e_g3 + e_g4);
  gPa2[1] = 0.25 * (-b_g3 + b_g4);
  gPa2[3] = 0.25 * (-f_g3 + f_g4);
  st.site = &ob_emlrtRSI;
  g2 = b_smooth_min_func(&st,
                         0.25 * (((v1 + v2) + v3) + v4) +
                             0.25 * (((e_v1 + e_v2) + e_v3) + e_v4),
                         0.25 * (((b_v1 + b_v2) + b_v3) + b_v4) +
                             0.25 * (((f_v1 + f_v2) + f_v3) + f_v4),
                         gPa1, gPa2, gM12);
  gPa1[0] = 0.25 * (-c_g1 + c_g2);
  gPa1[2] = 0.25 * (-g_g1 + g_g2);
  gPa2[0] = 0.25 * (-d_g1 + d_g2);
  gPa2[2] = 0.25 * (-h_g1 + h_g2);
  gPa1[1] = 0.25 * (-c_g3 + c_g4);
  gPa1[3] = 0.25 * (-g_g3 + g_g4);
  gPa2[1] = 0.25 * (-d_g3 + d_g4);
  gPa2[3] = 0.25 * (-h_g3 + h_g4);
  st.site = &pb_emlrtRSI;
  g1 = b_smooth_min_func(&st,
                         0.25 * (((c_v1 + c_v2) + c_v3) + c_v4) +
                             0.25 * (((g_v1 + g_v2) + g_v3) + g_v4),
                         0.25 * (((d_v1 + d_v2) + d_v3) + d_v4) +
                             0.25 * (((h_v1 + h_v2) + h_v3) + h_v4),
                         gPa1, gPa2, gM34);
  st.site = &qb_emlrtRSI;
  Cost = b_smooth_min_func(&st, g2, g1, gM12, gM34, gPa1);
  grad_pa[0] = gPa1[0];
  grad_pb[0] = gPa1[2];
  grad_pa[1] = gPa1[1];
  grad_pb[1] = gPa1[3];
  return Cost;
}

static real_T get_single_block_p2s(const real_T pt[2], const real_T blk[4],
                                   real_T gP[2])
{
  real_T P;
  real_T g1;
  real_T g2;
  real_T g3;
  real_T g4;
  real_T v1;
  real_T v2;
  real_T v3;
  real_T v4;
  /*  =========================================================================
   */
  /*  FUNÇÃO AUXILIAR: P2S-HSD para UM Polítopo Convexo */
  /*  =========================================================================
   */
  v1 = phi_func(blk[0] - pt[0], &g1);
  v2 = phi_func(pt[0] - blk[1], &g2);
  v3 = phi_func(blk[2] - pt[1], &g3);
  v4 = phi_func(pt[1] - blk[3], &g4);
  P = 0.25 * (((v1 + v2) + v3) + v4);
  gP[0] = 0.25 * (-g1 + g2);
  gP[1] = 0.25 * (-g3 + g4);
  return P;
}

static real_T phi_func(real_T s, real_T *grad)
{
  real_T val;
  /*  =========================================================================
   */
  /*  FUNÇÃO BASE: Generalized P2S-HSD (Phi e Phi') */
  /*  =========================================================================
   */
  if (s >= 0.0) {
    val = muDoubleScalarPower(s, 3.0) / (2.0 * (s + 0.05));
    *grad = s * s * (2.0 * s + 0.15000000000000002) /
            (2.0 * ((s + 0.05) * (s + 0.05)));
  } else {
    val = 0.0;
    *grad = 0.0;
  }
  return val;
}

static real_T smooth_min_func(const emlrtStack *sp, real_T a, real_T b,
                              const real_T ga[2], const real_T gb[2],
                              real_T gM[2])
{
  __m128d r;
  __m128d r1;
  emlrtStack st;
  real_T M;
  real_T delta;
  real_T diff;
  st.prev = sp;
  st.tls = sp->tls;
  /*  =========================================================================
   */
  /*  FUNÇÃO AUXILIAR: Mínimo Suave Base (Smooth Min) */
  /*  =========================================================================
   */
  /*  Fator de suavização Numérica */
  diff = a - b;
  delta = diff * diff;
  st.site = &fb_emlrtRSI;
  if (delta + 1.0E-10 < 0.0) {
    emlrtErrorWithMessageIdR2018a(
        &st, &c_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
        "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
  }
  delta = muDoubleScalarSqrt(delta + 1.0E-10);
  M = 0.5 * ((a + b) - delta);
  /*  O gradiente repassa perfeitamente a direção correspondente ao menor valor
   */
  r = _mm_loadu_pd(&ga[0]);
  r1 = _mm_loadu_pd(&gb[0]);
  _mm_storeu_pd(&gM[0],
                _mm_mul_pd(_mm_set1_pd(0.5),
                           _mm_sub_pd(_mm_add_pd(r, r1),
                                      _mm_mul_pd(_mm_set1_pd(diff / delta),
                                                 _mm_sub_pd(r, r1)))));
  return M;
}

real_T build_robot_cbf_experiment(const emlrtStack *sp, const real_T W[50],
                                  const real_T params[36], real_T grad[50])
{
  __m128d b_r1;
  __m128d r;
  __m128d r5;
  emlrtStack st;
  emxArray_real_T *X_hist;
  emxArray_real_T *grad_U;
  real_T dv[9];
  real_T b_Ts[6];
  real_T dv1[3];
  real_T grad_x_next_cbf[3];
  real_T x_k[3];
  real_T x_next[3];
  real_T E_k_tmp[2];
  real_T a__1[2];
  real_T a__4[2];
  real_T b_params[2];
  real_T b_y[2];
  real_T c_y[2];
  real_T d_y[2];
  real_T gP_seg0_r1[2];
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
  real_T y[2];
  real_T P_k;
  real_T P_next;
  real_T Ts;
  real_T a;
  real_T b_a;
  real_T b_xs_tmp;
  real_T cost;
  real_T d;
  real_T d1;
  real_T d2;
  real_T d3;
  real_T eta_safe;
  real_T g_corridor;
  real_T gamma_safe;
  real_T grad_us_idx_0;
  real_T grad_us_idx_0_tmp;
  real_T grad_us_idx_1;
  real_T idx_r1;
  real_T idx_r2;
  real_T idx_r3;
  real_T kappa_s;
  real_T l_u;
  real_T v_n;
  real_T v_s_tmp;
  real_T w_n;
  real_T w_s_tmp;
  real_T xs_tmp;
  real_T *X_hist_data;
  real_T *grad_U_data;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T loop_ub;
  int32_T n;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
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
      emlrtIntegerCheckR2012b(d, &d_emlrtDCI, (emlrtConstCTX)sp);
    }
    if (((int32_T)d < 1) || ((int32_T)d > 50)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, 50, &i_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    i = (int32_T)d;
  }
  d1 = 2.0 * params[7] + 1.0;
  if (d1 != (int32_T)muDoubleScalarFloor(d1)) {
    emlrtIntegerCheckR2012b(d1, &n_emlrtDCI, (emlrtConstCTX)sp);
  }
  if (((int8_T)d1 < 1) || ((int8_T)d1 > 50)) {
    emlrtDynamicBoundsCheckR2012b((int8_T)d1, 1, 50, &r_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  if (d1 + 1.0 != (int32_T)muDoubleScalarFloor(d1 + 1.0)) {
    emlrtIntegerCheckR2012b(d1 + 1.0, &n_emlrtDCI, (emlrtConstCTX)sp);
  }
  if (((int8_T)(d1 + 1.0) < 1) || ((int8_T)(d1 + 1.0) > 50)) {
    emlrtDynamicBoundsCheckR2012b((int8_T)(d1 + 1.0), 1, 50, &r_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  xs_tmp = W[(int8_T)d1 - 1];
  xs[0] = xs_tmp;
  b_xs_tmp = W[(int8_T)(d1 + 1.0) - 1];
  xs[1] = b_xs_tmp;
  d2 = 2.0 * params[7] + 3.0;
  if (d2 != (int32_T)muDoubleScalarFloor(d2)) {
    emlrtIntegerCheckR2012b(d2, &m_emlrtDCI, (emlrtConstCTX)sp);
  }
  if (((int8_T)d2 < 1) || ((int8_T)d2 > 50)) {
    emlrtDynamicBoundsCheckR2012b((int8_T)d2, 1, 50, &q_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  if (d2 + 1.0 != (int32_T)muDoubleScalarFloor(d2 + 1.0)) {
    emlrtIntegerCheckR2012b(d2 + 1.0, &m_emlrtDCI, (emlrtConstCTX)sp);
  }
  if (((int8_T)(d2 + 1.0) < 1) || ((int8_T)(d2 + 1.0) > 50)) {
    emlrtDynamicBoundsCheckR2012b((int8_T)(d2 + 1.0), 1, 50, &q_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  v_s_tmp = W[(int8_T)d2 - 1];
  w_s_tmp = W[(int8_T)(d2 + 1.0) - 1];
  idx_r1 = 2.0 * params[7] + 5.0;
  idx_r2 = 2.0 * params[7] + 7.0;
  idx_r3 = 2.0 * params[7] + 9.0;
  if (idx_r1 != (int32_T)muDoubleScalarFloor(idx_r1)) {
    emlrtIntegerCheckR2012b(idx_r1, &l_emlrtDCI, (emlrtConstCTX)sp);
  }
  if (((int8_T)idx_r1 < 1) || ((int8_T)idx_r1 > 50)) {
    emlrtDynamicBoundsCheckR2012b((int8_T)idx_r1, 1, 50, &p_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  if (idx_r1 + 1.0 != (int32_T)muDoubleScalarFloor(idx_r1 + 1.0)) {
    emlrtIntegerCheckR2012b(idx_r1 + 1.0, &l_emlrtDCI, (emlrtConstCTX)sp);
  }
  if (((int8_T)(idx_r1 + 1.0) < 1) || ((int8_T)(idx_r1 + 1.0) > 50)) {
    emlrtDynamicBoundsCheckR2012b((int8_T)(idx_r1 + 1.0), 1, 50, &p_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  r1[0] = W[(int8_T)idx_r1 - 1];
  r1[1] = W[(int8_T)(idx_r1 + 1.0) - 1];
  if (idx_r2 != (int32_T)muDoubleScalarFloor(idx_r2)) {
    emlrtIntegerCheckR2012b(idx_r2, &k_emlrtDCI, (emlrtConstCTX)sp);
  }
  if (((int8_T)idx_r2 < 1) || ((int8_T)idx_r2 > 50)) {
    emlrtDynamicBoundsCheckR2012b((int8_T)idx_r2, 1, 50, &o_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  if (idx_r2 + 1.0 != (int32_T)muDoubleScalarFloor(idx_r2 + 1.0)) {
    emlrtIntegerCheckR2012b(idx_r2 + 1.0, &k_emlrtDCI, (emlrtConstCTX)sp);
  }
  if (((int8_T)(idx_r2 + 1.0) < 1) || ((int8_T)(idx_r2 + 1.0) > 50)) {
    emlrtDynamicBoundsCheckR2012b((int8_T)(idx_r2 + 1.0), 1, 50, &o_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  r2[0] = W[(int8_T)idx_r2 - 1];
  r2[1] = W[(int8_T)(idx_r2 + 1.0) - 1];
  if (idx_r3 != (int32_T)muDoubleScalarFloor(idx_r3)) {
    emlrtIntegerCheckR2012b(idx_r3, &j_emlrtDCI, (emlrtConstCTX)sp);
  }
  if (((int8_T)idx_r3 < 1) || ((int8_T)idx_r3 > 50)) {
    emlrtDynamicBoundsCheckR2012b((int8_T)idx_r3, 1, 50, &n_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  if (idx_r3 + 1.0 != (int32_T)muDoubleScalarFloor(idx_r3 + 1.0)) {
    emlrtIntegerCheckR2012b(idx_r3 + 1.0, &j_emlrtDCI, (emlrtConstCTX)sp);
  }
  if (((int8_T)(idx_r3 + 1.0) < 1) || ((int8_T)(idx_r3 + 1.0) > 50)) {
    emlrtDynamicBoundsCheckR2012b((int8_T)(idx_r3 + 1.0), 1, 50, &n_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  r3[0] = W[(int8_T)idx_r3 - 1];
  r3[1] = W[(int8_T)(idx_r3 + 1.0) - 1];
  emxInit_real_T(sp, &X_hist, 2, &d_emlrtRTEI);
  i1 = X_hist->size[0] * X_hist->size[1];
  X_hist->size[0] = 3;
  emxEnsureCapacity_real_T(sp, X_hist, i1, &d_emlrtRTEI);
  if (!(params[7] + 1.0 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(params[7] + 1.0, &f_emlrtDCI,
                                (emlrtConstCTX)sp);
  }
  d3 = (int32_T)muDoubleScalarFloor(params[7] + 1.0);
  if (params[7] + 1.0 != d3) {
    emlrtIntegerCheckR2012b(params[7] + 1.0, &e_emlrtDCI, (emlrtConstCTX)sp);
  }
  i1 = X_hist->size[0] * X_hist->size[1];
  X_hist->size[1] = (int32_T)(params[7] + 1.0);
  emxEnsureCapacity_real_T(sp, X_hist, i1, &d_emlrtRTEI);
  X_hist_data = X_hist->data;
  if (params[7] + 1.0 != d3) {
    emlrtIntegerCheckR2012b(params[7] + 1.0, &g_emlrtDCI, (emlrtConstCTX)sp);
  }
  loop_ub = 3 * (int32_T)(params[7] + 1.0);
  for (i1 = 0; i1 < loop_ub; i1++) {
    X_hist_data[i1] = 0.0;
  }
  if ((int32_T)(params[7] + 1.0) < 1) {
    emlrtDynamicBoundsCheckR2012b(1, 1, (int32_T)(params[7] + 1.0), &h_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  X_hist_data[0] = params[0];
  X_hist_data[1] = params[1];
  X_hist_data[2] = params[2];
  l_u = 0.0;
  /*  Parâmetro h para a Generalized P2S-HSD */
  /*  ===================================================================== */
  /*  ADAPTAÇÃO SUAVE DE PARÂMETROS (State-Dependent Weight) */
  /*  ===================================================================== */
  b_params[0] = params[0];
  b_params[1] = params[1];
  g_corridor = get_single_block_p2s(b_params, &params[32], a__1);
  /*  Ajuste para definir quão "firme" é a transição */
  /*  Substitui o IF/ELSE por uma transição C1 estrita */
  kappa_s =
      params[29] + params[30] * muDoubleScalarExp(-params[31] * g_corridor);
  /*  ===================================================================== */
  /*  FORWARD PASS (Dinâmica com CBF - Ponto a Ponto Suavizado) */
  /*  ===================================================================== */
  i1 = (int32_T)params[7];
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, params[7], mxDOUBLE_CLASS,
                                (int32_T)params[7], &b_emlrtRTEI,
                                (emlrtConstCTX)sp);
  for (n = 0; n < i1; n++) {
    i2 = (int32_T)(((uint32_T)n << 1) + 1U);
    if ((i2 < 1) || (i2 > i)) {
      emlrtDynamicBoundsCheckR2012b(i2, 1, i, &j_emlrtBCI, (emlrtConstCTX)sp);
    }
    v_n = W[i2 - 1];
    i2 = (int32_T)((((real_T)n + 1.0) - 1.0) * 2.0 + 2.0);
    if ((i2 < 1) || (i2 > i)) {
      emlrtDynamicBoundsCheckR2012b(i2, 1, i, &k_emlrtBCI, (emlrtConstCTX)sp);
    }
    w_n = W[i2 - 1];
    st.site = &c_emlrtRSI;
    P_k = calc_point_p2s_penalty(&st, &x_k[0], &params[10], a__1);
    g_corridor = Ts * v_n;
    x_next[0] = x_k[0] + g_corridor * muDoubleScalarCos(x_k[2]);
    x_next[1] = x_k[1] + g_corridor * muDoubleScalarSin(x_k[2]);
    x_next[2] = x_k[2] + Ts * w_n;
    st.site = &d_emlrtRSI;
    P_next = calc_point_p2s_penalty(&st, &x_next[0], &params[10], a__1);
    P_k = muDoubleScalarMax(0.0, (1.0 - gamma_safe) * -P_k - (-P_next));
    a = x_k[0] - xs_tmp;
    b_a = x_k[1] - b_xs_tmp;
    P_next = v_n - v_s_tmp;
    g_corridor = w_n - w_s_tmp;
    l_u = (l_u + (((a * a + b_a * b_a) + 0.5 * (P_next * P_next)) +
                  0.5 * (g_corridor * g_corridor))) +
          eta_safe * (P_k * P_k);
    x_k[0] = x_next[0];
    x_k[1] = x_next[1];
    x_k[2] = x_next[2];
    if (((int32_T)((uint32_T)n + 2U) < 1) ||
        ((int32_T)((uint32_T)n + 2U) > X_hist->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)n + 2U), 1,
                                    X_hist->size[1], &g_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    i2 = 3 * (n + 1);
    X_hist_data[i2] = x_next[0];
    X_hist_data[i2 + 1] = x_next[1];
    X_hist_data[i2 + 2] = x_next[2];
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
  /*  ===================================================================== */
  /*  TERMINAL E BACKWARD PASS */
  /*  ===================================================================== */
  if (params[7] + 1.0 != d3) {
    emlrtIntegerCheckR2012b(params[7] + 1.0, &c_emlrtDCI, (emlrtConstCTX)sp);
  }
  if (((int32_T)(params[7] + 1.0) < 1) ||
      ((int32_T)(params[7] + 1.0) > X_hist->size[1])) {
    emlrtDynamicBoundsCheckR2012b((int32_T)(params[7] + 1.0), 1,
                                  X_hist->size[1], &f_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  r = _mm_loadu_pd(&X_hist_data[3 * ((int32_T)(params[7] + 1.0) - 1)]);
  b_r1 = _mm_loadu_pd(&xs[0]);
  r = _mm_sub_pd(r, b_r1);
  _mm_storeu_pd(&grad_xs[0], r);
  _mm_storeu_pd(&y[0], _mm_mul_pd(r, r));
  r = _mm_loadu_pd(&r1[0]);
  b_r1 = _mm_loadu_pd(&xs[0]);
  b_r1 = _mm_sub_pd(r, b_r1);
  _mm_storeu_pd(&E_k_tmp[0], b_r1);
  _mm_storeu_pd(&b_params[0], _mm_mul_pd(b_r1, b_r1));
  b_r1 = _mm_loadu_pd(&r2[0]);
  r = _mm_sub_pd(b_r1, r);
  _mm_storeu_pd(&b_y[0], _mm_mul_pd(r, r));
  r = _mm_loadu_pd(&r3[0]);
  b_r1 = _mm_sub_pd(r, b_r1);
  _mm_storeu_pd(&c_y[0], _mm_mul_pd(b_r1, b_r1));
  r = _mm_sub_pd(_mm_loadu_pd(&params[3]), r);
  _mm_storeu_pd(&d_y[0], _mm_mul_pd(r, r));
  /*  ===================================================================== */
  /*  GEOFENCE DE SEGMENTOS (Contenção Convexa Suavizada) */
  /*  ===================================================================== */
  /*  Segmento 1: xs até r1 */
  st.site = &h_emlrtRSI;
  g_corridor =
      calc_segment_p2s_penalty(&st, xs, r1, &params[10], a__1, gP_seg0_r1);
  /*  Segmento 2: r1 até r2 */
  st.site = &i_emlrtRSI;
  P_next = calc_segment_p2s_penalty(&st, r1, r2, &params[10], gP_seg1_r1,
                                    gP_seg1_r2);
  /*  Segmento 3: r2 até r3 */
  st.site = &j_emlrtRSI;
  P_k = calc_segment_p2s_penalty(&st, r2, r3, &params[10], gP_seg2_r2,
                                 gP_seg2_r3);
  /*  Segmento 4: r3 até r4 (x_ref) */
  st.site = &k_emlrtRSI;
  a = calc_segment_p2s_penalty(&st, r3, &params[3], &params[10], gP_seg3_r3,
                               a__4);
  b_a = params[8] * params[8];
  cost = ((((((l_u + params[26] * sumColumnB(y)) +
              params[27] * b_a * (v_s_tmp * v_s_tmp + w_s_tmp * w_s_tmp)) +
             kappa_s *
                 (((sumColumnB(b_params) + sumColumnB(b_y)) + sumColumnB(c_y)) +
                  sumColumnB(d_y))) +
            params[28] * g_corridor) +
           params[28] * P_next) +
          params[28] * P_k) +
         params[28] * a;
  memset(&grad[0], 0, 50U * sizeof(real_T));
  emxInit_real_T(sp, &grad_U, 1, &e_emlrtRTEI);
  if (!(d >= 0.0)) {
    emlrtNonNegativeCheckR2012b(d, &i_emlrtDCI, (emlrtConstCTX)sp);
  }
  d3 = (int32_T)muDoubleScalarFloor(d);
  if (d != d3) {
    emlrtIntegerCheckR2012b(d, &h_emlrtDCI, (emlrtConstCTX)sp);
  }
  i1 = grad_U->size[0];
  grad_U->size[0] = (int32_T)d;
  emxEnsureCapacity_real_T(sp, grad_U, i1, &e_emlrtRTEI);
  grad_U_data = grad_U->data;
  if (d != d3) {
    emlrtIntegerCheckR2012b(d, &h_emlrtDCI, (emlrtConstCTX)sp);
  }
  loop_ub = (int32_T)d;
  for (i1 = 0; i1 < loop_ub; i1++) {
    grad_U_data[i1] = 0.0;
  }
  __m128d b_r2;
  __m128d b_r3;
  __m128d r4;
  __m128d r6;
  __m128d r7;
  __m128d r8;
  /*  (Inicialização existente de p_n) */
  x_k[0] = 0.0;
  x_k[1] = 0.0;
  x_k[2] = 0.0;
  r = _mm_loadu_pd(&grad_xs[0]);
  r = _mm_mul_pd(_mm_set1_pd(2.0 * params[26]), r);
  _mm_storeu_pd(&grad_xs[0], r);
  _mm_storeu_pd(&x_k[0], r);
  /*  (Inicialização existente de grad_xs e grad_r1) */
  grad_us_idx_0_tmp = 2.0 * params[27] * b_a;
  grad_us_idx_0 = grad_us_idx_0_tmp * v_s_tmp;
  grad_us_idx_1 = grad_us_idx_0_tmp * w_s_tmp;
  /*  Acumulação Incondicional dos Gradientes de Segmento */
  /*  Cada ponto r intermediário acumula gradiente das duas retas conectadas a
   * ele */
  r = _mm_loadu_pd(&grad_xs[0]);
  b_r1 = _mm_loadu_pd(&E_k_tmp[0]);
  b_r2 = _mm_loadu_pd(&a__1[0]);
  b_r3 = _mm_set1_pd(2.0 * kappa_s);
  r4 = _mm_set1_pd(params[28]);
  r5 = _mm_set1_pd(-1.0);
  _mm_storeu_pd(&grad_xs[0], _mm_add_pd(_mm_sub_pd(_mm_mul_pd(r, r5),
                                                   _mm_mul_pd(b_r3, b_r1)),
                                        _mm_mul_pd(r4, b_r2)));
  r = _mm_loadu_pd(&r1[0]);
  b_r1 = _mm_loadu_pd(&xs[0]);
  b_r2 = _mm_loadu_pd(&r2[0]);
  r6 = _mm_loadu_pd(&gP_seg0_r1[0]);
  r7 = _mm_loadu_pd(&gP_seg1_r1[0]);
  r8 = _mm_set1_pd(2.0);
  _mm_storeu_pd(
      &xs[0],
      _mm_add_pd(
          _mm_mul_pd(b_r3,
                     _mm_sub_pd(_mm_sub_pd(_mm_mul_pd(r8, r), b_r1), b_r2)),
          _mm_mul_pd(r4, _mm_add_pd(r6, r7))));
  b_r1 = _mm_loadu_pd(&r3[0]);
  r6 = _mm_loadu_pd(&gP_seg1_r2[0]);
  r7 = _mm_loadu_pd(&gP_seg2_r2[0]);
  _mm_storeu_pd(
      &r1[0],
      _mm_add_pd(
          _mm_mul_pd(b_r3,
                     _mm_sub_pd(_mm_sub_pd(_mm_mul_pd(r8, b_r2), r), b_r1)),
          _mm_mul_pd(r4, _mm_add_pd(r6, r7))));
  r = _mm_loadu_pd(&gP_seg2_r3[0]);
  r6 = _mm_loadu_pd(&gP_seg3_r3[0]);
  _mm_storeu_pd(
      &r3[0],
      _mm_add_pd(
          _mm_mul_pd(b_r3, _mm_sub_pd(_mm_sub_pd(_mm_mul_pd(r8, b_r1), b_r2),
                                      _mm_loadu_pd(&params[3]))),
          _mm_mul_pd(r4, _mm_add_pd(r, r6))));
  i1 = (int32_T) - ((-1.0 - params[7]) + 1.0);
  emlrtForLoopVectorCheckR2021a(params[7], -1.0, 1.0, mxDOUBLE_CLASS,
                                (int32_T) - ((-1.0 - params[7]) + 1.0),
                                &emlrtRTEI, (emlrtConstCTX)sp);
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
    uint32_T u;
    uint32_T u1;
    l_u = params[7] - (real_T)n;
    if (l_u != (int32_T)muDoubleScalarFloor(l_u)) {
      emlrtIntegerCheckR2012b(l_u, &b_emlrtDCI, (emlrtConstCTX)sp);
    }
    if (((int32_T)l_u < 1) || ((int32_T)l_u > X_hist->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)l_u, 1, X_hist->size[1],
                                    &e_emlrtBCI, (emlrtConstCTX)sp);
    }
    if (((int32_T)(l_u + 1.0) < 1) ||
        ((int32_T)(l_u + 1.0) > X_hist->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(l_u + 1.0), 1, X_hist->size[1],
                                    &d_emlrtBCI, (emlrtConstCTX)sp);
    }
    u = (uint32_T)((int32_T)l_u - 1) << 1;
    if (((int32_T)(u + 1U) < 1) || ((int32_T)(u + 1U) > i)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(u + 1U), 1, i, &l_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    v_n = W[(int32_T)u];
    if (((int32_T)(u + 2U) < 1) || ((int32_T)(u + 2U) > i)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(u + 2U), 1, i, &m_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    loop_ub = 3 * ((int32_T)l_u - 1);
    a = 2.0 * (X_hist_data[loop_ub] - xs_tmp);
    grad_xs[0] -= a;
    w_n = 2.0 * (X_hist_data[loop_ub + 1] - b_xs_tmp);
    grad_xs[1] -= w_n;
    grad_us_idx_0_tmp = v_n - v_s_tmp;
    grad_us_idx_0 -= grad_us_idx_0_tmp;
    kappa_s = W[(int32_T)u + 1] - w_s_tmp;
    grad_us_idx_1 -= kappa_s;
    /*  Avaliação Suavizada Ponto a Ponto para CBF */
    st.site = &n_emlrtRSI;
    P_k = calc_point_p2s_penalty(
        &st, &(*(real_T(*)[3]) & X_hist_data[3 * ((int32_T)l_u - 1)])[0],
        &params[10], a__1);
    st.site = &o_emlrtRSI;
    P_next = calc_point_p2s_penalty(
        &st, &(*(real_T(*)[3]) & X_hist_data[3 * (int32_T)l_u])[0], &params[10],
        gP_seg0_r1);
    g_corridor = (1.0 - gamma_safe) * -P_k - (-P_next);
    x_next[0] = 0.0;
    grad_x_next_cbf[0] = 0.0;
    x_next[1] = 0.0;
    grad_x_next_cbf[1] = 0.0;
    x_next[2] = 0.0;
    grad_x_next_cbf[2] = 0.0;
    if (g_corridor > 0.0) {
      r = _mm_loadu_pd(&a__1[0]);
      b_r1 = _mm_set1_pd(2.0 * eta_safe * g_corridor);
      _mm_storeu_pd(&x_next[0],
                    _mm_mul_pd(b_r1, _mm_mul_pd(_mm_set1_pd(1.0 - gamma_safe),
                                                _mm_mul_pd(r, r5))));
      r = _mm_loadu_pd(&gP_seg0_r1[0]);
      _mm_storeu_pd(&grad_x_next_cbf[0], _mm_mul_pd(b_r1, r));
    }
    P_next = X_hist_data[loop_ub + 2];
    g_corridor = muDoubleScalarCos(P_next);
    b_a = muDoubleScalarSin(P_next);
    grad_x_next_cbf[0] += x_k[0];
    grad_x_next_cbf[1] += x_k[1];
    grad_x_next_cbf[2] += x_k[2];
    dv[2] = -Ts * v_n * b_a;
    dv[5] = Ts * v_n * g_corridor;
    dv1[0] = a + x_next[0];
    dv1[1] = w_n + x_next[1];
    dv1[2] = x_next[2];
    P_next = grad_x_next_cbf[0];
    P_k = grad_x_next_cbf[1];
    a = grad_x_next_cbf[2];
    r = _mm_loadu_pd(&dv[0]);
    r = _mm_mul_pd(r, _mm_set1_pd(P_next));
    b_r1 = _mm_loadu_pd(&dv[3]);
    b_r1 = _mm_mul_pd(b_r1, _mm_set1_pd(P_k));
    r = _mm_add_pd(r, b_r1);
    b_r1 = _mm_loadu_pd(&dv[6]);
    b_r1 = _mm_mul_pd(b_r1, _mm_set1_pd(a));
    r = _mm_add_pd(r, b_r1);
    b_r1 = _mm_loadu_pd(&dv1[0]);
    r = _mm_add_pd(r, b_r1);
    _mm_storeu_pd(&x_k[0], r);
    x_k[2] = ((dv[2] * P_next + dv[5] * P_k) + dv[8] * a) + dv1[2];
    u1 = (uint32_T)l_u << 1;
    if (u + 1U > u1) {
      i2 = 0;
      loop_ub = 0;
    } else {
      if (((int32_T)(u + 1U) < 1) || ((int32_T)(u + 1U) > grad_U->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(u + 1U), 1, grad_U->size[0],
                                      &c_emlrtBCI, (emlrtConstCTX)sp);
      }
      i2 = (int32_T)u;
      if (((int32_T)u1 < 1) || ((int32_T)u1 > grad_U->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)u1, 1, grad_U->size[0],
                                      &b_emlrtBCI, (emlrtConstCTX)sp);
      }
      loop_ub = (int32_T)u1;
    }
    loop_ub -= i2;
    if (loop_ub != 2) {
      emlrtSubAssignSizeCheck1dR2017a(loop_ub, 2, &b_emlrtECI,
                                      (emlrtConstCTX)sp);
    }
    b_Ts[0] = Ts * g_corridor;
    b_Ts[2] = Ts * b_a;
    P_next = grad_x_next_cbf[0];
    P_k = grad_x_next_cbf[1];
    a = grad_x_next_cbf[2];
    r = _mm_loadu_pd(&b_Ts[0]);
    r = _mm_mul_pd(r, _mm_set1_pd(P_next));
    b_r1 = _mm_loadu_pd(&b_Ts[2]);
    b_r1 = _mm_mul_pd(b_r1, _mm_set1_pd(P_k));
    r = _mm_add_pd(r, b_r1);
    b_r1 = _mm_loadu_pd(&b_Ts[4]);
    b_r1 = _mm_mul_pd(b_r1, _mm_set1_pd(a));
    r = _mm_add_pd(r, b_r1);
    _mm_storeu_pd(&b_params[0], r);
    y[0] = grad_us_idx_0_tmp;
    y[1] = kappa_s;
    r = _mm_loadu_pd(&b_params[0]);
    b_r1 = _mm_loadu_pd(&y[0]);
    _mm_storeu_pd(&grad_U_data[i2], _mm_add_pd(r, b_r1));
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
  emxFree_real_T(sp, &X_hist);
  if (d < 1.0) {
    loop_ub = 0;
  } else {
    if (d != d3) {
      emlrtIntegerCheckR2012b(d, &emlrtDCI, (emlrtConstCTX)sp);
    }
    if (((int32_T)d < 1) || ((int32_T)d > 50)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, 50, &emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    loop_ub = (int32_T)d;
  }
  if (loop_ub != grad_U->size[0]) {
    emlrtSubAssignSizeCheck1dR2017a(loop_ub, grad_U->size[0], &emlrtECI,
                                    (emlrtConstCTX)sp);
  }
  for (i = 0; i < loop_ub; i++) {
    grad[i] = grad_U_data[i];
  }
  emxFree_real_T(sp, &grad_U);
  grad[(int8_T)d1 - 1] = grad_xs[0];
  grad[(int8_T)(d1 + 1.0) - 1] = grad_xs[1];
  grad[(int8_T)d2 - 1] = grad_us_idx_0;
  grad[(int8_T)(d2 + 1.0) - 1] = grad_us_idx_1;
  grad[(int8_T)idx_r1 - 1] = xs[0];
  grad[(int8_T)(idx_r1 + 1.0) - 1] = xs[1];
  grad[(int8_T)idx_r2 - 1] = r1[0];
  grad[(int8_T)(idx_r2 + 1.0) - 1] = r1[1];
  grad[(int8_T)idx_r3 - 1] = r3[0];
  grad[(int8_T)(idx_r3 + 1.0) - 1] = r3[1];
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
  return cost;
}

/* End of code generation (build_robot_cbf_experiment.c) */
