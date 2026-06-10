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
static emlrtECInfo emlrtECI = {
    -1,                           /* nDims */
    186,                          /* lineNo */
    5,                            /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_segment_tracking\\build_robot_cbf_e"
    "xperiment.m" /* pName */
};

static emlrtBCInfo emlrtBCI = {
    1,                            /* iFirst */
    50,                           /* iLast */
    186,                          /* lineNo */
    12,                           /* colNo */
    "grad",                       /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_segment_tracking\\build_robot_cbf_e"
    "xperiment.m", /* pName */
    0              /* checkKind */
};

static emlrtDCInfo emlrtDCI = {
    186,                          /* lineNo */
    12,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_segment_tracking\\build_robot_cbf_e"
    "xperiment.m", /* pName */
    1              /* checkKind */
};

static emlrtECInfo b_emlrtECI = {
    -1,                           /* nDims */
    183,                          /* lineNo */
    9,                            /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_segment_tracking\\build_robot_cbf_e"
    "xperiment.m" /* pName */
};

static emlrtBCInfo b_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    183,                          /* lineNo */
    30,                           /* colNo */
    "grad_U",                     /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_segment_tracking\\build_robot_cbf_e"
    "xperiment.m", /* pName */
    0              /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    183,                          /* lineNo */
    16,                           /* colNo */
    "grad_U",                     /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_segment_tracking\\build_robot_cbf_e"
    "xperiment.m", /* pName */
    0              /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    138,                          /* lineNo */
    28,                           /* colNo */
    "X_hist",                     /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_segment_tracking\\build_robot_cbf_e"
    "xperiment.m", /* pName */
    0              /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    137,                          /* lineNo */
    25,                           /* colNo */
    "X_hist",                     /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_segment_tracking\\build_robot_cbf_e"
    "xperiment.m", /* pName */
    0              /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = {
    137,                          /* lineNo */
    25,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_segment_tracking\\build_robot_cbf_e"
    "xperiment.m", /* pName */
    1              /* checkKind */
};

static emlrtRTEInfo emlrtRTEI = {
    136,                          /* lineNo */
    13,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_segment_tracking\\build_robot_cbf_e"
    "xperiment.m" /* pName */
};

static emlrtBCInfo f_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    77,                           /* lineNo */
    21,                           /* colNo */
    "X_hist",                     /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_segment_tracking\\build_robot_cbf_e"
    "xperiment.m", /* pName */
    0              /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = {
    77,                           /* lineNo */
    21,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_segment_tracking\\build_robot_cbf_e"
    "xperiment.m", /* pName */
    1              /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    69,                           /* lineNo */
    19,                           /* colNo */
    "X_hist",                     /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_segment_tracking\\build_robot_cbf_e"
    "xperiment.m", /* pName */
    0              /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    36,                           /* lineNo */
    15,                           /* colNo */
    "X_hist",                     /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_segment_tracking\\build_robot_cbf_e"
    "xperiment.m", /* pName */
    0              /* checkKind */
};

static emlrtRTEInfo b_emlrtRTEI = {
    45,                           /* lineNo */
    13,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_segment_tracking\\build_robot_cbf_e"
    "xperiment.m" /* pName */
};

static emlrtDCInfo d_emlrtDCI = {
    35,                           /* lineNo */
    23,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_segment_tracking\\build_robot_cbf_e"
    "xperiment.m", /* pName */
    1              /* checkKind */
};

static emlrtDCInfo e_emlrtDCI = {
    35,                           /* lineNo */
    23,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_segment_tracking\\build_robot_cbf_e"
    "xperiment.m", /* pName */
    4              /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = {
    1,                            /* iFirst */
    50,                           /* iLast */
    21,                           /* lineNo */
    14,                           /* colNo */
    "W",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_segment_tracking\\build_robot_cbf_e"
    "xperiment.m", /* pName */
    0              /* checkKind */
};

static emlrtDCInfo f_emlrtDCI = {
    21,                           /* lineNo */
    14,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_segment_tracking\\build_robot_cbf_e"
    "xperiment.m", /* pName */
    1              /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    46,                           /* lineNo */
    17,                           /* colNo */
    "u",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_segment_tracking\\build_robot_cbf_e"
    "xperiment.m", /* pName */
    0              /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    47,                           /* lineNo */
    17,                           /* colNo */
    "u",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_segment_tracking\\build_robot_cbf_e"
    "xperiment.m", /* pName */
    0              /* checkKind */
};

static emlrtDCInfo g_emlrtDCI = {
    112,                          /* lineNo */
    5,                            /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_segment_tracking\\build_robot_cbf_e"
    "xperiment.m", /* pName */
    1              /* checkKind */
};

static emlrtDCInfo h_emlrtDCI = {
    112,                          /* lineNo */
    5,                            /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_segment_tracking\\build_robot_cbf_e"
    "xperiment.m", /* pName */
    4              /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    139,                          /* lineNo */
    17,                           /* colNo */
    "u",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_segment_tracking\\build_robot_cbf_e"
    "xperiment.m", /* pName */
    0              /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    139,                          /* lineNo */
    39,                           /* colNo */
    "u",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_segment_tracking\\build_robot_cbf_e"
    "xperiment.m", /* pName */
    0              /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = {
    1,                            /* iFirst */
    50,                           /* iLast */
    33,                           /* lineNo */
    12,                           /* colNo */
    "W",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_segment_tracking\\build_robot_cbf_e"
    "xperiment.m", /* pName */
    0              /* checkKind */
};

static emlrtDCInfo i_emlrtDCI = {
    33,                           /* lineNo */
    12,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_segment_tracking\\build_robot_cbf_e"
    "xperiment.m", /* pName */
    1              /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = {
    1,                            /* iFirst */
    50,                           /* iLast */
    32,                           /* lineNo */
    12,                           /* colNo */
    "W",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_segment_tracking\\build_robot_cbf_e"
    "xperiment.m", /* pName */
    0              /* checkKind */
};

static emlrtDCInfo j_emlrtDCI = {
    32,                           /* lineNo */
    12,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_segment_tracking\\build_robot_cbf_e"
    "xperiment.m", /* pName */
    1              /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = {
    1,                            /* iFirst */
    50,                           /* iLast */
    31,                           /* lineNo */
    12,                           /* colNo */
    "W",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_segment_tracking\\build_robot_cbf_e"
    "xperiment.m", /* pName */
    0              /* checkKind */
};

static emlrtDCInfo k_emlrtDCI = {
    31,                           /* lineNo */
    12,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_segment_tracking\\build_robot_cbf_e"
    "xperiment.m", /* pName */
    1              /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = {
    1,                            /* iFirst */
    50,                           /* iLast */
    23,                           /* lineNo */
    12,                           /* colNo */
    "W",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_segment_tracking\\build_robot_cbf_e"
    "xperiment.m", /* pName */
    0              /* checkKind */
};

static emlrtDCInfo l_emlrtDCI = {
    23,                           /* lineNo */
    12,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_segment_tracking\\build_robot_cbf_e"
    "xperiment.m", /* pName */
    1              /* checkKind */
};

static emlrtBCInfo r_emlrtBCI = {
    1,                            /* iFirst */
    50,                           /* iLast */
    22,                           /* lineNo */
    12,                           /* colNo */
    "W",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_segment_tracking\\build_robot_cbf_e"
    "xperiment.m", /* pName */
    0              /* checkKind */
};

static emlrtDCInfo m_emlrtDCI = {
    22,                           /* lineNo */
    12,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_segment_tracking\\build_robot_cbf_e"
    "xperiment.m", /* pName */
    1              /* checkKind */
};

static emlrtRTEInfo c_emlrtRTEI = {
    35,                           /* lineNo */
    5,                            /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_segment_tracking\\build_robot_cbf_e"
    "xperiment.m" /* pName */
};

static emlrtRTEInfo d_emlrtRTEI = {
    112,                          /* lineNo */
    5,                            /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_segment_tracking\\build_robot_cbf_e"
    "xperiment.m" /* pName */
};

/* Function Declarations */
static real_T calc_segment_p2s_penalty(const real_T pa[2], const real_T pb[2],
                                       const real_T blocks[16],
                                       real_T grad_pa[2], real_T grad_pb[2]);

static real_T get_exact_blocks_P(const real_T pt[2], const real_T blocks[16],
                                 real_T *P_v, real_T *P_g, real_T *P_c);

static void get_exact_grad(const real_T pt[2], const real_T blocks[16],
                           real_T P_a, real_T P_v, real_T P_g, real_T P_c,
                           real_T gP_min[2]);

static real_T phi_func(real_T s, real_T *grad);

/* Function Definitions */
static real_T calc_segment_p2s_penalty(const real_T pa[2], const real_T pb[2],
                                       const real_T blocks[16],
                                       real_T grad_pa[2], real_T grad_pb[2])
{
  __m128d r;
  __m128d r1;
  __m128d r2;
  __m128d r3;
  real_T gC1[4];
  real_T gC2[4];
  real_T gC3[4];
  real_T gC4[4];
  real_T Cost;
  real_T b_delta;
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
  real_T delta;
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
  real_T h_v4;
  real_T v1;
  real_T v2;
  real_T v3;
  real_T v4;
  /*  =========================================================================
   */
  /*  FUNÇÃO AUXILIAR: Penalidade Ponto a Ponto (Smooth Min Incondicional) */
  /*  =========================================================================
   */
  /*  FUNÇÃO AUXILIAR: Penalidade de Segmento (Contenção Convexa Exata) */
  /*  =========================================================================
   */
  /*  1. Avaliação das distâncias sinalizadas para o ponto A */
  /*  =========================================================================
   */
  /*  FUNÇÃO AUXILIAR: P2S-HSD para UM Polítopo Convexo */
  /*  =========================================================================
   */
  Cost = phi_func(blocks[0] - pa[0], &g1);
  delta = phi_func(pa[0] - blocks[1], &g2);
  b_delta = phi_func(blocks[2] - pa[1], &g3);
  v4 = phi_func(pa[1] - blocks[3], &g4);
  /*  =========================================================================
   */
  /*  FUNÇÃO AUXILIAR: P2S-HSD para UM Polítopo Convexo */
  /*  =========================================================================
   */
  v1 = phi_func(blocks[4] - pa[0], &b_g1);
  v2 = phi_func(pa[0] - blocks[5], &b_g2);
  v3 = phi_func(blocks[6] - pa[1], &b_g3);
  b_v4 = phi_func(pa[1] - blocks[7], &b_g4);
  /*  =========================================================================
   */
  /*  FUNÇÃO AUXILIAR: P2S-HSD para UM Polítopo Convexo */
  /*  =========================================================================
   */
  b_v1 = phi_func(blocks[8] - pa[0], &c_g1);
  b_v2 = phi_func(pa[0] - blocks[9], &c_g2);
  b_v3 = phi_func(blocks[10] - pa[1], &c_g3);
  c_v4 = phi_func(pa[1] - blocks[11], &c_g4);
  /*  =========================================================================
   */
  /*  FUNÇÃO AUXILIAR: P2S-HSD para UM Polítopo Convexo */
  /*  =========================================================================
   */
  c_v1 = phi_func(blocks[12] - pa[0], &d_g1);
  c_v2 = phi_func(pa[0] - blocks[13], &d_g2);
  c_v3 = phi_func(blocks[14] - pa[1], &d_g3);
  d_v4 = phi_func(pa[1] - blocks[15], &d_g4);
  /*  2. Avaliação das distâncias sinalizadas para o ponto B */
  /*  =========================================================================
   */
  /*  FUNÇÃO AUXILIAR: P2S-HSD para UM Polítopo Convexo */
  /*  =========================================================================
   */
  d_v1 = phi_func(blocks[0] - pb[0], &e_g1);
  d_v2 = phi_func(pb[0] - blocks[1], &e_g2);
  d_v3 = phi_func(blocks[2] - pb[1], &e_g3);
  e_v4 = phi_func(pb[1] - blocks[3], &e_g4);
  /*  =========================================================================
   */
  /*  FUNÇÃO AUXILIAR: P2S-HSD para UM Polítopo Convexo */
  /*  =========================================================================
   */
  e_v1 = phi_func(blocks[4] - pb[0], &f_g1);
  e_v2 = phi_func(pb[0] - blocks[5], &f_g2);
  e_v3 = phi_func(blocks[6] - pb[1], &f_g3);
  f_v4 = phi_func(pb[1] - blocks[7], &f_g4);
  /*  =========================================================================
   */
  /*  FUNÇÃO AUXILIAR: P2S-HSD para UM Polítopo Convexo */
  /*  =========================================================================
   */
  f_v1 = phi_func(blocks[8] - pb[0], &g_g1);
  f_v2 = phi_func(pb[0] - blocks[9], &g_g2);
  f_v3 = phi_func(blocks[10] - pb[1], &g_g3);
  g_v4 = phi_func(pb[1] - blocks[11], &g_g4);
  /*  =========================================================================
   */
  /*  FUNÇÃO AUXILIAR: P2S-HSD para UM Polítopo Convexo */
  /*  =========================================================================
   */
  g_v1 = phi_func(blocks[12] - pb[0], &h_g1);
  g_v2 = phi_func(pb[0] - blocks[13], &h_g2);
  g_v3 = phi_func(blocks[14] - pb[1], &h_g3);
  h_v4 = phi_func(pb[1] - blocks[15], &h_g4);
  /*  3. Custo do segmento por polígono convexo (Soma das violações dos
   * extremos) */
  d_v2 = 0.25 * (((Cost + delta) + b_delta) + v4) +
         0.25 * (((d_v1 + d_v2) + d_v3) + e_v4);
  delta =
      0.25 * (((v1 + v2) + v3) + b_v4) + 0.25 * (((e_v1 + e_v2) + e_v3) + f_v4);
  d_v1 = 0.25 * (((b_v1 + b_v2) + b_v3) + c_v4) +
         0.25 * (((f_v1 + f_v2) + f_v3) + g_v4);
  v4 = 0.25 * (((c_v1 + c_v2) + c_v3) + d_v4) +
       0.25 * (((g_v1 + g_v2) + g_v3) + h_v4);
  /*  4. Concatenamos os gradientes de pa e pb num vetor (4x1) para  */
  /*  aproveitar a vetorização do smooth_min_func */
  gC1[0] = 0.25 * (-g1 + g2);
  gC1[2] = 0.25 * (-e_g1 + e_g2);
  gC2[0] = 0.25 * (-b_g1 + b_g2);
  gC2[2] = 0.25 * (-f_g1 + f_g2);
  gC3[0] = 0.25 * (-c_g1 + c_g2);
  gC3[2] = 0.25 * (-g_g1 + g_g2);
  gC4[0] = 0.25 * (-d_g1 + d_g2);
  gC4[2] = 0.25 * (-h_g1 + h_g2);
  gC1[1] = 0.25 * (-g3 + g4);
  gC1[3] = 0.25 * (-e_g3 + e_g4);
  gC2[1] = 0.25 * (-b_g3 + b_g4);
  gC2[3] = 0.25 * (-f_g3 + f_g4);
  gC3[1] = 0.25 * (-c_g3 + c_g4);
  gC3[3] = 0.25 * (-g_g3 + g_g4);
  gC4[1] = 0.25 * (-d_g3 + d_g4);
  gC4[3] = 0.25 * (-h_g3 + h_g4);
  /*  5. Redução em árvore de Mínimos Suaves para encontrar o "Melhor Polígono"
   */
  /*  =========================================================================
   */
  /*  FUNÇÃO AUXILIAR: Mínimo Suave Base (Smooth Min) */
  /*  =========================================================================
   */
  /*  Fator de suavização Numérica */
  Cost = d_v2 - delta;
  b_delta = muDoubleScalarSqrt(Cost * Cost + 1.0E-10);
  d_v2 = 0.5 * ((d_v2 + delta) - b_delta);
  /*  O gradiente repassa perfeitamente a direção correspondente ao menor valor
   */
  r = _mm_loadu_pd(&gC1[0]);
  r1 = _mm_loadu_pd(&gC2[0]);
  r2 = _mm_set1_pd(0.5);
  r3 = _mm_set1_pd(Cost / b_delta);
  _mm_storeu_pd(&gC1[0],
                _mm_mul_pd(r2, _mm_sub_pd(_mm_add_pd(r, r1),
                                          _mm_mul_pd(r3, _mm_sub_pd(r, r1)))));
  r = _mm_loadu_pd(&gC1[2]);
  r1 = _mm_loadu_pd(&gC2[2]);
  _mm_storeu_pd(&gC1[2],
                _mm_mul_pd(r2, _mm_sub_pd(_mm_add_pd(r, r1),
                                          _mm_mul_pd(r3, _mm_sub_pd(r, r1)))));
  /*  =========================================================================
   */
  /*  FUNÇÃO AUXILIAR: Mínimo Suave Base (Smooth Min) */
  /*  =========================================================================
   */
  /*  Fator de suavização Numérica */
  Cost = d_v1 - v4;
  delta = muDoubleScalarSqrt(Cost * Cost + 1.0E-10);
  v4 = 0.5 * ((d_v1 + v4) - delta);
  /*  O gradiente repassa perfeitamente a direção correspondente ao menor valor
   */
  r = _mm_loadu_pd(&gC3[0]);
  r1 = _mm_loadu_pd(&gC4[0]);
  r3 = _mm_set1_pd(Cost / delta);
  _mm_storeu_pd(&gC3[0],
                _mm_mul_pd(r2, _mm_sub_pd(_mm_add_pd(r, r1),
                                          _mm_mul_pd(r3, _mm_sub_pd(r, r1)))));
  r = _mm_loadu_pd(&gC3[2]);
  r1 = _mm_loadu_pd(&gC4[2]);
  _mm_storeu_pd(&gC3[2],
                _mm_mul_pd(r2, _mm_sub_pd(_mm_add_pd(r, r1),
                                          _mm_mul_pd(r3, _mm_sub_pd(r, r1)))));
  /*  =========================================================================
   */
  /*  FUNÇÃO AUXILIAR: Mínimo Suave Base (Smooth Min) */
  /*  =========================================================================
   */
  /*  Fator de suavização Numérica */
  delta = d_v2 - v4;
  b_delta = muDoubleScalarSqrt(delta * delta + 1.0E-10);
  Cost = 0.5 * ((d_v2 + v4) - b_delta);
  /*  O gradiente repassa perfeitamente a direção correspondente ao menor valor
   */
  r = _mm_loadu_pd(&gC1[0]);
  r1 = _mm_loadu_pd(&gC3[0]);
  r3 = _mm_set1_pd(delta / b_delta);
  _mm_storeu_pd(&gC1[0],
                _mm_mul_pd(r2, _mm_sub_pd(_mm_add_pd(r, r1),
                                          _mm_mul_pd(r3, _mm_sub_pd(r, r1)))));
  r = _mm_loadu_pd(&gC1[2]);
  r1 = _mm_loadu_pd(&gC3[2]);
  _mm_storeu_pd(&gC1[2],
                _mm_mul_pd(r2, _mm_sub_pd(_mm_add_pd(r, r1),
                                          _mm_mul_pd(r3, _mm_sub_pd(r, r1)))));
  /*  6. Desempacotamento dos gradientes propagados */
  grad_pa[0] = gC1[0];
  grad_pb[0] = gC1[2];
  grad_pa[1] = gC1[1];
  grad_pb[1] = gC1[3];
  return Cost;
}

static real_T get_exact_blocks_P(const real_T pt[2], const real_T blocks[16],
                                 real_T *P_v, real_T *P_g, real_T *P_c)
{
  real_T P_a;
  real_T a;
  real_T b_a;
  real_T c_a;
  real_T d_a;
  /*  =========================================================================
   */
  /*  FUNÇÕES DO CBF (Mantidas usando Mínimo Exato para Barreira Precisa) */
  /*  =========================================================================
   */
  a = muDoubleScalarMax(0.0, blocks[0] - pt[0]);
  b_a = muDoubleScalarMax(0.0, pt[0] - blocks[1]);
  c_a = muDoubleScalarMax(0.0, blocks[2] - pt[1]);
  d_a = muDoubleScalarMax(0.0, pt[1] - blocks[3]);
  P_a = ((a * a + b_a * b_a) + c_a * c_a) + d_a * d_a;
  a = muDoubleScalarMax(0.0, blocks[4] - pt[0]);
  b_a = muDoubleScalarMax(0.0, pt[0] - blocks[5]);
  c_a = muDoubleScalarMax(0.0, blocks[6] - pt[1]);
  d_a = muDoubleScalarMax(0.0, pt[1] - blocks[7]);
  *P_v = ((a * a + b_a * b_a) + c_a * c_a) + d_a * d_a;
  a = muDoubleScalarMax(0.0, blocks[8] - pt[0]);
  b_a = muDoubleScalarMax(0.0, pt[0] - blocks[9]);
  c_a = muDoubleScalarMax(0.0, blocks[10] - pt[1]);
  d_a = muDoubleScalarMax(0.0, pt[1] - blocks[11]);
  *P_g = ((a * a + b_a * b_a) + c_a * c_a) + d_a * d_a;
  a = muDoubleScalarMax(0.0, blocks[12] - pt[0]);
  b_a = muDoubleScalarMax(0.0, pt[0] - blocks[13]);
  c_a = muDoubleScalarMax(0.0, blocks[14] - pt[1]);
  d_a = muDoubleScalarMax(0.0, pt[1] - blocks[15]);
  *P_c = ((a * a + b_a * b_a) + c_a * c_a) + d_a * d_a;
  return P_a;
}

static void get_exact_grad(const real_T pt[2], const real_T blocks[16],
                           real_T P_a, real_T P_v, real_T P_g, real_T P_c,
                           real_T gP_min[2])
{
  real_T varargin_1[4];
  real_T P_min;
  int32_T b_k;
  int32_T idx;
  varargin_1[0] = P_a;
  varargin_1[1] = P_v;
  varargin_1[2] = P_g;
  varargin_1[3] = P_c;
  if (!muDoubleScalarIsNaN(P_a)) {
    idx = 1;
  } else {
    int32_T k;
    boolean_T exitg1;
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 5)) {
      if (!muDoubleScalarIsNaN(varargin_1[k - 1])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  if (idx == 0) {
    P_min = P_a;
  } else {
    P_min = varargin_1[idx - 1];
    idx++;
    for (b_k = idx; b_k < 5; b_k++) {
      real_T d;
      d = varargin_1[b_k - 1];
      if (P_min > d) {
        P_min = d;
      }
    }
  }
  gP_min[0] = 0.0;
  gP_min[1] = 0.0;
  if (P_min == P_a) {
    P_min = blocks[0] - pt[0];
    if (P_min > 0.0) {
      gP_min[0] = -(2.0 * P_min);
    }
    P_min = pt[0] - blocks[1];
    if (P_min > 0.0) {
      gP_min[0] += 2.0 * P_min;
    }
    P_min = blocks[2] - pt[1];
    if (P_min > 0.0) {
      gP_min[1] = -(2.0 * P_min);
    }
    P_min = pt[1] - blocks[3];
    if (P_min > 0.0) {
      gP_min[1] += 2.0 * P_min;
    }
  } else if (P_min == P_v) {
    P_min = blocks[4] - pt[0];
    if (P_min > 0.0) {
      gP_min[0] = -(2.0 * P_min);
    }
    P_min = pt[0] - blocks[5];
    if (P_min > 0.0) {
      gP_min[0] += 2.0 * P_min;
    }
    P_min = blocks[6] - pt[1];
    if (P_min > 0.0) {
      gP_min[1] = -(2.0 * P_min);
    }
    P_min = pt[1] - blocks[7];
    if (P_min > 0.0) {
      gP_min[1] += 2.0 * P_min;
    }
  } else if (P_min == P_g) {
    P_min = blocks[8] - pt[0];
    if (P_min > 0.0) {
      gP_min[0] = -(2.0 * P_min);
    }
    P_min = pt[0] - blocks[9];
    if (P_min > 0.0) {
      gP_min[0] += 2.0 * P_min;
    }
    P_min = blocks[10] - pt[1];
    if (P_min > 0.0) {
      gP_min[1] = -(2.0 * P_min);
    }
    P_min = pt[1] - blocks[11];
    if (P_min > 0.0) {
      gP_min[1] += 2.0 * P_min;
    }
  } else {
    P_min = blocks[12] - pt[0];
    if (P_min > 0.0) {
      gP_min[0] = -(2.0 * P_min);
    }
    P_min = pt[0] - blocks[13];
    if (P_min > 0.0) {
      gP_min[0] += 2.0 * P_min;
    }
    P_min = blocks[14] - pt[1];
    if (P_min > 0.0) {
      gP_min[1] = -(2.0 * P_min);
    }
    P_min = pt[1] - blocks[15];
    if (P_min > 0.0) {
      gP_min[1] += 2.0 * P_min;
    }
  }
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

real_T build_robot_cbf_experiment(const emlrtStack *sp, const real_T W[50],
                                  const real_T params[30], real_T grad[50])
{
  __m128d b_r1;
  __m128d b_r2;
  __m128d r;
  __m128d r5;
  __m128d r6;
  __m128d r7;
  emxArray_real_T *X_hist;
  emxArray_real_T *grad_U;
  real_T dv[9];
  real_T b_Ts[6];
  real_T varargin_1[4];
  real_T grad_x_next_cbf[3];
  real_T x_k[3];
  real_T x_next[3];
  real_T a[2];
  real_T a__1[2];
  real_T b_y[2];
  real_T c_y[2];
  real_T cost_tmp[2];
  real_T d_y[2];
  real_T e_y[2];
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
  real_T P_c_k;
  real_T P_g_k;
  real_T P_k;
  real_T P_next;
  real_T P_v_k;
  real_T Ts;
  real_T b_P_c_k;
  real_T b_a;
  real_T b_xs_tmp;
  real_T c_a;
  real_T cost;
  real_T d;
  real_T d1;
  real_T eta_safe;
  real_T g_corridor;
  real_T gamma_safe;
  real_T grad_us_idx_0;
  real_T grad_us_idx_1;
  real_T l_u;
  real_T v_n;
  real_T v_s;
  real_T w_n;
  real_T w_s;
  real_T xs_tmp;
  real_T *X_hist_data;
  real_T *grad_U_data;
  int32_T b_k;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  int32_T idx;
  int32_T k;
  int32_T n;
  boolean_T exitg1;
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
      emlrtIntegerCheckR2012b(d, &f_emlrtDCI, (emlrtConstCTX)sp);
    }
    if (((int32_T)d < 1) || ((int32_T)d > 50)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, 50, &i_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    i = (int32_T)d;
  }
  if (d + 1.0 != (int32_T)muDoubleScalarFloor(d + 1.0)) {
    emlrtIntegerCheckR2012b(d + 1.0, &m_emlrtDCI, (emlrtConstCTX)sp);
  }
  if (((int8_T)(d + 1.0) < 1) || ((int8_T)(d + 1.0) > 50)) {
    emlrtDynamicBoundsCheckR2012b((int8_T)(d + 1.0), 1, 50, &r_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  if ((d + 1.0) + 1.0 != (int32_T)muDoubleScalarFloor((d + 1.0) + 1.0)) {
    emlrtIntegerCheckR2012b((d + 1.0) + 1.0, &m_emlrtDCI, (emlrtConstCTX)sp);
  }
  if (((int8_T)((d + 1.0) + 1.0) < 1) || ((int8_T)((d + 1.0) + 1.0) > 50)) {
    emlrtDynamicBoundsCheckR2012b((int8_T)((d + 1.0) + 1.0), 1, 50, &r_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  xs_tmp = W[(int8_T)(d + 1.0) - 1];
  xs[0] = xs_tmp;
  b_xs_tmp = W[(int8_T)((d + 1.0) + 1.0) - 1];
  xs[1] = b_xs_tmp;
  if (d + 3.0 != (int32_T)muDoubleScalarFloor(d + 3.0)) {
    emlrtIntegerCheckR2012b(d + 3.0, &l_emlrtDCI, (emlrtConstCTX)sp);
  }
  if (((int8_T)(d + 3.0) < 1) || ((int8_T)(d + 3.0) > 50)) {
    emlrtDynamicBoundsCheckR2012b((int8_T)(d + 3.0), 1, 50, &q_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  if ((d + 3.0) + 1.0 != (int32_T)muDoubleScalarFloor((d + 3.0) + 1.0)) {
    emlrtIntegerCheckR2012b((d + 3.0) + 1.0, &l_emlrtDCI, (emlrtConstCTX)sp);
  }
  if (((int8_T)((d + 3.0) + 1.0) < 1) || ((int8_T)((d + 3.0) + 1.0) > 50)) {
    emlrtDynamicBoundsCheckR2012b((int8_T)((d + 3.0) + 1.0), 1, 50, &q_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  v_s = W[(int8_T)(d + 3.0) - 1];
  w_s = W[(int8_T)((d + 3.0) + 1.0) - 1];
  if (d + 5.0 != (int32_T)muDoubleScalarFloor(d + 5.0)) {
    emlrtIntegerCheckR2012b(d + 5.0, &k_emlrtDCI, (emlrtConstCTX)sp);
  }
  if (((int8_T)(d + 5.0) < 1) || ((int8_T)(d + 5.0) > 50)) {
    emlrtDynamicBoundsCheckR2012b((int8_T)(d + 5.0), 1, 50, &p_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  if ((d + 5.0) + 1.0 != (int32_T)muDoubleScalarFloor((d + 5.0) + 1.0)) {
    emlrtIntegerCheckR2012b((d + 5.0) + 1.0, &k_emlrtDCI, (emlrtConstCTX)sp);
  }
  if (((int8_T)((d + 5.0) + 1.0) < 1) || ((int8_T)((d + 5.0) + 1.0) > 50)) {
    emlrtDynamicBoundsCheckR2012b((int8_T)((d + 5.0) + 1.0), 1, 50, &p_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  r1[0] = W[(int8_T)(d + 5.0) - 1];
  r1[1] = W[(int8_T)((d + 5.0) + 1.0) - 1];
  if (d + 7.0 != (int32_T)muDoubleScalarFloor(d + 7.0)) {
    emlrtIntegerCheckR2012b(d + 7.0, &j_emlrtDCI, (emlrtConstCTX)sp);
  }
  if (((int8_T)(d + 7.0) < 1) || ((int8_T)(d + 7.0) > 50)) {
    emlrtDynamicBoundsCheckR2012b((int8_T)(d + 7.0), 1, 50, &o_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  if ((d + 7.0) + 1.0 != (int32_T)muDoubleScalarFloor((d + 7.0) + 1.0)) {
    emlrtIntegerCheckR2012b((d + 7.0) + 1.0, &j_emlrtDCI, (emlrtConstCTX)sp);
  }
  if (((int8_T)((d + 7.0) + 1.0) < 1) || ((int8_T)((d + 7.0) + 1.0) > 50)) {
    emlrtDynamicBoundsCheckR2012b((int8_T)((d + 7.0) + 1.0), 1, 50, &o_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  r2[0] = W[(int8_T)(d + 7.0) - 1];
  r2[1] = W[(int8_T)((d + 7.0) + 1.0) - 1];
  if (d + 9.0 != (int32_T)muDoubleScalarFloor(d + 9.0)) {
    emlrtIntegerCheckR2012b(d + 9.0, &i_emlrtDCI, (emlrtConstCTX)sp);
  }
  if (((int8_T)(d + 9.0) < 1) || ((int8_T)(d + 9.0) > 50)) {
    emlrtDynamicBoundsCheckR2012b((int8_T)(d + 9.0), 1, 50, &n_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  if ((d + 9.0) + 1.0 != (int32_T)muDoubleScalarFloor((d + 9.0) + 1.0)) {
    emlrtIntegerCheckR2012b((d + 9.0) + 1.0, &i_emlrtDCI, (emlrtConstCTX)sp);
  }
  if (((int8_T)((d + 9.0) + 1.0) < 1) || ((int8_T)((d + 9.0) + 1.0) > 50)) {
    emlrtDynamicBoundsCheckR2012b((int8_T)((d + 9.0) + 1.0), 1, 50, &n_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  r3[0] = W[(int8_T)(d + 9.0) - 1];
  r3[1] = W[(int8_T)((d + 9.0) + 1.0) - 1];
  if (!(params[7] + 1.0 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(params[7] + 1.0, &e_emlrtDCI,
                                (emlrtConstCTX)sp);
  }
  P_v_k = (int32_T)muDoubleScalarFloor(params[7] + 1.0);
  if (params[7] + 1.0 != P_v_k) {
    emlrtIntegerCheckR2012b(params[7] + 1.0, &d_emlrtDCI, (emlrtConstCTX)sp);
  }
  emxInit_real_T(sp, &X_hist, 2, &c_emlrtRTEI);
  idx = X_hist->size[0] * X_hist->size[1];
  X_hist->size[0] = 3;
  X_hist->size[1] = (int32_T)(params[7] + 1.0);
  emxEnsureCapacity_real_T(sp, X_hist, idx, &c_emlrtRTEI);
  X_hist_data = X_hist->data;
  idx = 3 * (int32_T)(params[7] + 1.0);
  for (k = 0; k < idx; k++) {
    X_hist_data[k] = 0.0;
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
  /*  FORWARD PASS (Dinâmica com CBF - Mínimo Exato) */
  /*  ===================================================================== */
  i1 = (int32_T)params[7];
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, params[7], mxDOUBLE_CLASS,
                                (int32_T)params[7], &b_emlrtRTEI,
                                (emlrtConstCTX)sp);
  for (n = 0; n < i1; n++) {
    idx = (int32_T)(((uint32_T)n << 1) + 1U);
    if ((idx < 1) || (idx > i)) {
      emlrtDynamicBoundsCheckR2012b(idx, 1, i, &j_emlrtBCI, (emlrtConstCTX)sp);
    }
    v_n = W[idx - 1];
    idx = (n << 1) + 2;
    if ((idx < 1) || (idx > i)) {
      emlrtDynamicBoundsCheckR2012b(idx, 1, i, &k_emlrtBCI, (emlrtConstCTX)sp);
    }
    w_n = W[idx - 1];
    P_k = get_exact_blocks_P(&x_k[0], &params[10], &g_corridor, &P_g_k, &P_c_k);
    varargin_1[0] = P_k;
    varargin_1[1] = g_corridor;
    varargin_1[2] = P_g_k;
    varargin_1[3] = P_c_k;
    if (!muDoubleScalarIsNaN(P_k)) {
      idx = 1;
    } else {
      idx = 0;
      b_k = 2;
      exitg1 = false;
      while ((!exitg1) && (b_k < 5)) {
        if (!muDoubleScalarIsNaN(varargin_1[b_k - 1])) {
          idx = b_k;
          exitg1 = true;
        } else {
          b_k++;
        }
      }
    }
    if (idx != 0) {
      P_k = varargin_1[idx - 1];
      idx++;
      for (k = idx; k < 5; k++) {
        g_corridor = varargin_1[k - 1];
        if (P_k > g_corridor) {
          P_k = g_corridor;
        }
      }
    }
    g_corridor = Ts * v_n;
    x_next[0] = x_k[0] + g_corridor * muDoubleScalarCos(x_k[2]);
    x_next[1] = x_k[1] + g_corridor * muDoubleScalarSin(x_k[2]);
    x_next[2] = x_k[2] + Ts * w_n;
    P_next = get_exact_blocks_P(&x_next[0], &params[10], &g_corridor, &P_g_k,
                                &P_c_k);
    varargin_1[0] = P_next;
    varargin_1[1] = g_corridor;
    varargin_1[2] = P_g_k;
    varargin_1[3] = P_c_k;
    if (!muDoubleScalarIsNaN(P_next)) {
      idx = 1;
    } else {
      idx = 0;
      b_k = 2;
      exitg1 = false;
      while ((!exitg1) && (b_k < 5)) {
        if (!muDoubleScalarIsNaN(varargin_1[b_k - 1])) {
          idx = b_k;
          exitg1 = true;
        } else {
          b_k++;
        }
      }
    }
    if (idx != 0) {
      P_next = varargin_1[idx - 1];
      idx++;
      for (k = idx; k < 5; k++) {
        g_corridor = varargin_1[k - 1];
        if (P_next > g_corridor) {
          P_next = g_corridor;
        }
      }
    }
    P_g_k = muDoubleScalarMax(0.0, (1.0 - gamma_safe) * -P_k - (-P_next));
    P_c_k = x_k[0] - xs_tmp;
    b_a = x_k[1] - b_xs_tmp;
    c_a = v_n - v_s;
    g_corridor = w_n - w_s;
    l_u = (l_u + ((5.0 * (P_c_k * P_c_k + b_a * b_a) + 0.5 * (c_a * c_a)) +
                  g_corridor * g_corridor)) +
          eta_safe * (P_g_k * P_g_k);
    x_k[0] = x_next[0];
    x_k[1] = x_next[1];
    x_k[2] = x_next[2];
    if (((int32_T)((uint32_T)n + 2U) < 1) ||
        ((int32_T)((uint32_T)n + 2U) > X_hist->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)n + 2U), 1,
                                    X_hist->size[1], &g_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    idx = 3 * (n + 1);
    X_hist_data[idx] = x_next[0];
    X_hist_data[idx + 1] = x_next[1];
    X_hist_data[idx + 2] = x_next[2];
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
  /*  ===================================================================== */
  /*  TERMINAL E BACKWARD PASS */
  /*  ===================================================================== */
  i2 = X_hist->size[1];
  if (params[7] + 1.0 != P_v_k) {
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
  b_r1 = _mm_loadu_pd(&r1[0]);
  r = _mm_loadu_pd(&xs[0]);
  r = _mm_sub_pd(b_r1, r);
  _mm_storeu_pd(&cost_tmp[0], r);
  _mm_storeu_pd(&b_y[0], _mm_mul_pd(r, r));
  b_r2 = _mm_loadu_pd(&r2[0]);
  r = _mm_sub_pd(b_r2, b_r1);
  _mm_storeu_pd(&c_y[0], _mm_mul_pd(r, r));
  b_r1 = _mm_loadu_pd(&r3[0]);
  r = _mm_sub_pd(b_r1, b_r2);
  _mm_storeu_pd(&d_y[0], _mm_mul_pd(r, r));
  r = _mm_sub_pd(_mm_loadu_pd(&params[3]), b_r1);
  _mm_storeu_pd(&e_y[0], _mm_mul_pd(r, r));
  /*  ===================================================================== */
  /*  GEOFENCE DE SEGMENTOS (Contenção Convexa) */
  /*  A matemática resolve sozinha se o segmento está em um dos polígonos */
  /*  ===================================================================== */
  /*  Segmento 1: xs até r1 */
  g_corridor = calc_segment_p2s_penalty(xs, r1, &params[10], a, gP_seg0_r1);
  /*  Segmento 2: r1 até r2 */
  P_g_k = calc_segment_p2s_penalty(r1, r2, &params[10], gP_seg1_r1, gP_seg1_r2);
  /*  Segmento 3: r2 até r3 */
  P_c_k = calc_segment_p2s_penalty(r2, r3, &params[10], gP_seg2_r2, gP_seg2_r3);
  /*  Segmento 4: r3 até r4 (x_ref) */
  /*  Nota: o gradiente para r4 é computado mas descartado via ~, pois r4 é
   * parâmetro constante. */
  c_a = calc_segment_p2s_penalty(r3, &params[3], &params[10], gP_seg3_r3, a__1);
  b_a = params[8] * params[8];
  cost = ((((((l_u + params[26] * sumColumnB(y)) +
              params[27] * b_a * (v_s * v_s + w_s * w_s)) +
             params[29] *
                 (((sumColumnB(b_y) + sumColumnB(c_y)) + sumColumnB(d_y)) +
                  sumColumnB(e_y))) +
            params[28] * g_corridor) +
           params[28] * P_g_k) +
          params[28] * P_c_k) +
         params[28] * c_a;
  memset(&grad[0], 0, 50U * sizeof(real_T));
  emxInit_real_T(sp, &grad_U, 1, &d_emlrtRTEI);
  if (!(d >= 0.0)) {
    emlrtNonNegativeCheckR2012b(d, &h_emlrtDCI, (emlrtConstCTX)sp);
  }
  d1 = (int32_T)muDoubleScalarFloor(d);
  if (d != d1) {
    emlrtIntegerCheckR2012b(d, &g_emlrtDCI, (emlrtConstCTX)sp);
  }
  idx = grad_U->size[0];
  b_k = (int32_T)d;
  grad_U->size[0] = (int32_T)d;
  emxEnsureCapacity_real_T(sp, grad_U, idx, &d_emlrtRTEI);
  grad_U_data = grad_U->data;
  if (d != d1) {
    emlrtIntegerCheckR2012b(d, &g_emlrtDCI, (emlrtConstCTX)sp);
  }
  for (k = 0; k < b_k; k++) {
    grad_U_data[k] = 0.0;
  }
  __m128d b_r3;
  __m128d r4;
  __m128d r8;
  x_k[0] = 0.0;
  x_k[1] = 0.0;
  x_k[2] = 0.0;
  r = _mm_loadu_pd(&grad_xs[0]);
  r = _mm_mul_pd(_mm_set1_pd(2.0 * params[26]), r);
  _mm_storeu_pd(&grad_xs[0], r);
  _mm_storeu_pd(&x_k[0], r);
  g_corridor = 2.0 * params[27] * b_a;
  grad_us_idx_0 = g_corridor * v_s;
  grad_us_idx_1 = g_corridor * w_s;
  /*  Acumulação Incondicional dos Gradientes de Segmento */
  /*  Cada ponto r intermediário acumula gradiente das duas retas conectadas a
   * ele */
  r = _mm_loadu_pd(&grad_xs[0]);
  b_r1 = _mm_loadu_pd(&cost_tmp[0]);
  b_r2 = _mm_loadu_pd(&a[0]);
  b_r3 = _mm_set1_pd(2.0 * params[29]);
  r4 = _mm_set1_pd(params[28]);
  r5 = _mm_set1_pd(-1.0);
  _mm_storeu_pd(&grad_xs[0], _mm_add_pd(_mm_sub_pd(_mm_mul_pd(r, r5),
                                                   _mm_mul_pd(b_r3, b_r1)),
                                        _mm_mul_pd(r4, b_r2)));
  r6 = _mm_loadu_pd(&r1[0]);
  r = _mm_loadu_pd(&xs[0]);
  r7 = _mm_loadu_pd(&r2[0]);
  b_r1 = _mm_loadu_pd(&gP_seg0_r1[0]);
  b_r2 = _mm_loadu_pd(&gP_seg1_r1[0]);
  r8 = _mm_set1_pd(2.0);
  _mm_storeu_pd(
      &xs[0],
      _mm_add_pd(
          _mm_mul_pd(b_r3, _mm_sub_pd(_mm_sub_pd(_mm_mul_pd(r8, r6), r), r7)),
          _mm_mul_pd(r4, _mm_add_pd(b_r1, b_r2))));
  b_r2 = _mm_loadu_pd(&r3[0]);
  r = _mm_loadu_pd(&gP_seg1_r2[0]);
  b_r1 = _mm_loadu_pd(&gP_seg2_r2[0]);
  _mm_storeu_pd(
      &r1[0],
      _mm_add_pd(_mm_mul_pd(b_r3, _mm_sub_pd(_mm_sub_pd(_mm_mul_pd(r8, r7), r6),
                                             b_r2)),
                 _mm_mul_pd(r4, _mm_add_pd(r, b_r1))));
  r = _mm_loadu_pd(&gP_seg2_r3[0]);
  b_r1 = _mm_loadu_pd(&gP_seg3_r3[0]);
  _mm_storeu_pd(
      &r3[0],
      _mm_add_pd(
          _mm_mul_pd(b_r3, _mm_sub_pd(_mm_sub_pd(_mm_mul_pd(r8, b_r2), r7),
                                      _mm_loadu_pd(&params[3]))),
          _mm_mul_pd(r4, _mm_add_pd(r, b_r1))));
  i3 = (int32_T) - ((-1.0 - params[7]) + 1.0);
  emlrtForLoopVectorCheckR2021a(params[7], -1.0, 1.0, mxDOUBLE_CLASS,
                                (int32_T) - ((-1.0 - params[7]) + 1.0),
                                &emlrtRTEI, (emlrtConstCTX)sp);
  if ((int32_T) - ((-1.0 - params[7]) + 1.0) - 1 >= 0) {
    b_Ts[4] = 0.0;
    b_Ts[1] = 0.0;
    b_Ts[3] = 0.0;
    b_Ts[5] = params[8];
  }
  if (i3 - 1 >= 0) {
    dv[0] = 1.0;
    dv[1] = 0.0;
    dv[3] = 0.0;
    dv[4] = 1.0;
    dv[6] = 0.0;
    dv[7] = 0.0;
    dv[8] = 1.0;
  }
  for (n = 0; n < i3; n++) {
    real_T P_a_k;
    real_T b_grad_xs_tmp;
    real_T b_n;
    real_T grad_us_idx_0_tmp;
    real_T grad_us_idx_1_tmp;
    real_T grad_xs_tmp;
    int32_T grad_xs_tmp_tmp;
    uint32_T u;
    uint32_T u1;
    b_n = params[7] - (real_T)n;
    if (b_n != (int32_T)muDoubleScalarFloor(b_n)) {
      emlrtIntegerCheckR2012b(b_n, &b_emlrtDCI, (emlrtConstCTX)sp);
    }
    if (((int32_T)b_n < 1) || ((int32_T)b_n > i2)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)b_n, 1, i2, &e_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    if (((int32_T)(b_n + 1.0) < 1) || ((int32_T)(b_n + 1.0) > i2)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_n + 1.0), 1, i2, &d_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    u = (uint32_T)((int32_T)b_n - 1) << 1;
    if (((int32_T)(u + 1U) < 1) || ((int32_T)(u + 1U) > i)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(u + 1U), 1, i, &l_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    v_n = W[(int32_T)u];
    if (((int32_T)(u + 2U) < 1) || ((int32_T)(u + 2U) > i)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(u + 2U), 1, i, &m_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    grad_xs_tmp_tmp = 3 * ((int32_T)b_n - 1);
    grad_xs_tmp = 10.0 * (X_hist_data[grad_xs_tmp_tmp] - xs_tmp);
    grad_xs[0] -= grad_xs_tmp;
    b_grad_xs_tmp = 10.0 * (X_hist_data[grad_xs_tmp_tmp + 1] - b_xs_tmp);
    grad_xs[1] -= b_grad_xs_tmp;
    grad_us_idx_0_tmp = v_n - v_s;
    grad_us_idx_0 -= grad_us_idx_0_tmp;
    grad_us_idx_1_tmp = 2.0 * (W[(int32_T)u + 1] - w_s);
    grad_us_idx_1 -= grad_us_idx_1_tmp;
    P_a_k = get_exact_blocks_P(&X_hist_data[grad_xs_tmp_tmp], &params[10],
                               &P_v_k, &l_u, &b_P_c_k);
    varargin_1[0] = P_a_k;
    varargin_1[1] = P_v_k;
    varargin_1[2] = l_u;
    varargin_1[3] = b_P_c_k;
    if (!muDoubleScalarIsNaN(P_a_k)) {
      idx = 1;
    } else {
      idx = 0;
      b_k = 2;
      exitg1 = false;
      while ((!exitg1) && (b_k < 5)) {
        if (!muDoubleScalarIsNaN(varargin_1[b_k - 1])) {
          idx = b_k;
          exitg1 = true;
        } else {
          b_k++;
        }
      }
    }
    if (idx == 0) {
      P_k = P_a_k;
    } else {
      P_k = varargin_1[idx - 1];
      idx++;
      for (k = idx; k < 5; k++) {
        g_corridor = varargin_1[k - 1];
        if (P_k > g_corridor) {
          P_k = g_corridor;
        }
      }
    }
    i1 = 3 * (int32_T)b_n;
    w_n = get_exact_blocks_P(&X_hist_data[i1], &params[10], &P_c_k, &c_a, &b_a);
    varargin_1[0] = w_n;
    varargin_1[1] = P_c_k;
    varargin_1[2] = c_a;
    varargin_1[3] = b_a;
    if (!muDoubleScalarIsNaN(w_n)) {
      idx = 1;
    } else {
      idx = 0;
      b_k = 2;
      exitg1 = false;
      while ((!exitg1) && (b_k < 5)) {
        if (!muDoubleScalarIsNaN(varargin_1[b_k - 1])) {
          idx = b_k;
          exitg1 = true;
        } else {
          b_k++;
        }
      }
    }
    if (idx == 0) {
      P_next = w_n;
    } else {
      P_next = varargin_1[idx - 1];
      idx++;
      for (k = idx; k < 5; k++) {
        P_g_k = varargin_1[k - 1];
        if (P_next > P_g_k) {
          P_next = P_g_k;
        }
      }
    }
    g_corridor = (1.0 - gamma_safe) * -P_k - (-P_next);
    x_next[0] = 0.0;
    grad_x_next_cbf[0] = 0.0;
    x_next[1] = 0.0;
    grad_x_next_cbf[1] = 0.0;
    x_next[2] = 0.0;
    grad_x_next_cbf[2] = 0.0;
    if (g_corridor > 0.0) {
      get_exact_grad(&X_hist_data[grad_xs_tmp_tmp], &params[10], P_a_k, P_v_k,
                     l_u, b_P_c_k, a);
      r = _mm_loadu_pd(&a[0]);
      b_r1 = _mm_set1_pd(2.0 * eta_safe * g_corridor);
      _mm_storeu_pd(&x_next[0],
                    _mm_mul_pd(b_r1, _mm_mul_pd(_mm_set1_pd(1.0 - gamma_safe),
                                                _mm_mul_pd(r, r5))));
      get_exact_grad(&X_hist_data[i1], &params[10], w_n, P_c_k, c_a, b_a, a);
      r = _mm_loadu_pd(&a[0]);
      _mm_storeu_pd(&grad_x_next_cbf[0], _mm_mul_pd(b_r1, r));
    }
    g_corridor = X_hist_data[grad_xs_tmp_tmp + 2];
    P_g_k = muDoubleScalarCos(g_corridor);
    g_corridor = muDoubleScalarSin(g_corridor);
    grad_x_next_cbf[0] += x_k[0];
    grad_x_next_cbf[1] += x_k[1];
    grad_x_next_cbf[2] += x_k[2];
    dv[2] = -Ts * v_n * g_corridor;
    dv[5] = Ts * v_n * P_g_k;
    memset(&x_k[0], 0, 3U * sizeof(real_T));
    r = _mm_loadu_pd(&dv[0]);
    b_r1 = _mm_loadu_pd(&x_k[0]);
    b_r2 = _mm_set1_pd(grad_x_next_cbf[0]);
    _mm_storeu_pd(&x_k[0], _mm_add_pd(b_r1, _mm_mul_pd(r, b_r2)));
    x_k[2] += grad_x_next_cbf[0] * dv[2];
    r = _mm_loadu_pd(&dv[3]);
    b_r1 = _mm_loadu_pd(&x_k[0]);
    r6 = _mm_set1_pd(grad_x_next_cbf[1]);
    _mm_storeu_pd(&x_k[0], _mm_add_pd(b_r1, _mm_mul_pd(r, r6)));
    x_k[2] += grad_x_next_cbf[1] * dv[5];
    r = _mm_loadu_pd(&dv[6]);
    b_r1 = _mm_loadu_pd(&x_k[0]);
    r7 = _mm_set1_pd(grad_x_next_cbf[2]);
    _mm_storeu_pd(&x_k[0], _mm_add_pd(b_r1, _mm_mul_pd(r, r7)));
    x_k[2] += grad_x_next_cbf[2];
    x_next[0] += grad_xs_tmp;
    x_next[1] += b_grad_xs_tmp;
    r = _mm_loadu_pd(&x_k[0]);
    b_r1 = _mm_loadu_pd(&x_next[0]);
    _mm_storeu_pd(&x_k[0], _mm_add_pd(r, b_r1));
    x_k[2] += x_next[2];
    u1 = (uint32_T)b_n << 1;
    if (u + 1U > u1) {
      b_k = 0;
      idx = 0;
    } else {
      if (((int32_T)(u + 1U) < 1) || ((int32_T)(u + 1U) > grad_U->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(u + 1U), 1, grad_U->size[0],
                                      &c_emlrtBCI, (emlrtConstCTX)sp);
      }
      b_k = (int32_T)u;
      if (((int32_T)u1 < 1) || ((int32_T)u1 > grad_U->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)u1, 1, grad_U->size[0],
                                      &b_emlrtBCI, (emlrtConstCTX)sp);
      }
      idx = (int32_T)u1;
    }
    idx -= b_k;
    if (idx != 2) {
      emlrtSubAssignSizeCheck1dR2017a(idx, 2, &b_emlrtECI, (emlrtConstCTX)sp);
    }
    b_Ts[0] = Ts * P_g_k;
    b_Ts[2] = Ts * g_corridor;
    memset(&r2[0], 0, sizeof(real_T) << 1);
    r = _mm_loadu_pd(&b_Ts[0]);
    b_r1 = _mm_loadu_pd(&r2[0]);
    _mm_storeu_pd(&r2[0], _mm_add_pd(b_r1, _mm_mul_pd(r, b_r2)));
    r = _mm_loadu_pd(&b_Ts[2]);
    b_r1 = _mm_loadu_pd(&r2[0]);
    _mm_storeu_pd(&r2[0], _mm_add_pd(b_r1, _mm_mul_pd(r, r6)));
    r = _mm_loadu_pd(&b_Ts[4]);
    b_r1 = _mm_loadu_pd(&r2[0]);
    _mm_storeu_pd(&r2[0], _mm_add_pd(b_r1, _mm_mul_pd(r, r7)));
    y[0] = grad_us_idx_0_tmp;
    y[1] = grad_us_idx_1_tmp;
    r = _mm_loadu_pd(&r2[0]);
    b_r1 = _mm_loadu_pd(&y[0]);
    _mm_storeu_pd(&grad_U_data[b_k], _mm_add_pd(r, b_r1));
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
  emxFree_real_T(sp, &X_hist);
  if (d < 1.0) {
    idx = 0;
  } else {
    if (d != d1) {
      emlrtIntegerCheckR2012b(d, &emlrtDCI, (emlrtConstCTX)sp);
    }
    if (((int32_T)d < 1) || ((int32_T)d > 50)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, 50, &emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    idx = (int32_T)d;
  }
  if (idx != grad_U->size[0]) {
    emlrtSubAssignSizeCheck1dR2017a(idx, grad_U->size[0], &emlrtECI,
                                    (emlrtConstCTX)sp);
  }
  for (k = 0; k < idx; k++) {
    grad[k] = grad_U_data[k];
  }
  emxFree_real_T(sp, &grad_U);
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
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
  return cost;
}

/* End of code generation (build_robot_cbf_experiment.c) */
