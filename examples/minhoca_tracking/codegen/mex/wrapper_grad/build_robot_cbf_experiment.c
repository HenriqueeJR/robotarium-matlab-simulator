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
    182,                          /* lineNo */
    5,                            /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "tracking\\bui"
    "ld_robot_cbf_experiment.m" /* pName */
};

static emlrtBCInfo emlrtBCI = {
    1,                            /* iFirst */
    50,                           /* iLast */
    182,                          /* lineNo */
    12,                           /* colNo */
    "grad",                       /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "tracking\\bui"
    "ld_robot_cbf_experiment.m", /* pName */
    0                            /* checkKind */
};

static emlrtDCInfo emlrtDCI = {
    182,                          /* lineNo */
    12,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "tracking\\bui"
    "ld_robot_cbf_experiment.m", /* pName */
    1                            /* checkKind */
};

static emlrtECInfo b_emlrtECI = {
    -1,                           /* nDims */
    179,                          /* lineNo */
    9,                            /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "tracking\\bui"
    "ld_robot_cbf_experiment.m" /* pName */
};

static emlrtBCInfo b_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    179,                          /* lineNo */
    30,                           /* colNo */
    "grad_U",                     /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "tracking\\bui"
    "ld_robot_cbf_experiment.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    179,                          /* lineNo */
    16,                           /* colNo */
    "grad_U",                     /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "tracking\\bui"
    "ld_robot_cbf_experiment.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    134,                          /* lineNo */
    28,                           /* colNo */
    "X_hist",                     /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "tracking\\bui"
    "ld_robot_cbf_experiment.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    133,                          /* lineNo */
    25,                           /* colNo */
    "X_hist",                     /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "tracking\\bui"
    "ld_robot_cbf_experiment.m", /* pName */
    0                            /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = {
    133,                          /* lineNo */
    25,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "tracking\\bui"
    "ld_robot_cbf_experiment.m", /* pName */
    1                            /* checkKind */
};

static emlrtRTEInfo emlrtRTEI = {
    132,                          /* lineNo */
    13,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "tracking\\bui"
    "ld_robot_cbf_experiment.m" /* pName */
};

static emlrtBCInfo f_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    77,                           /* lineNo */
    21,                           /* colNo */
    "X_hist",                     /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "tracking\\bui"
    "ld_robot_cbf_experiment.m", /* pName */
    0                            /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = {
    77,                           /* lineNo */
    21,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "tracking\\bui"
    "ld_robot_cbf_experiment.m", /* pName */
    1                            /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    69,                           /* lineNo */
    19,                           /* colNo */
    "X_hist",                     /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "tracking\\bui"
    "ld_robot_cbf_experiment.m", /* pName */
    0                            /* checkKind */
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
    "tracking\\bui"
    "ld_robot_cbf_experiment.m", /* pName */
    0                            /* checkKind */
};

static emlrtRTEInfo b_emlrtRTEI = {
    45,                           /* lineNo */
    13,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "tracking\\bui"
    "ld_robot_cbf_experiment.m" /* pName */
};

static emlrtDCInfo d_emlrtDCI = {
    35,                           /* lineNo */
    23,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "tracking\\bui"
    "ld_robot_cbf_experiment.m", /* pName */
    1                            /* checkKind */
};

static emlrtDCInfo e_emlrtDCI = {
    35,                           /* lineNo */
    23,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "tracking\\bui"
    "ld_robot_cbf_experiment.m", /* pName */
    4                            /* checkKind */
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
    "tracking\\bui"
    "ld_robot_cbf_experiment.m", /* pName */
    0                            /* checkKind */
};

static emlrtDCInfo f_emlrtDCI = {
    21,                           /* lineNo */
    14,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "tracking\\bui"
    "ld_robot_cbf_experiment.m", /* pName */
    1                            /* checkKind */
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
    "tracking\\bui"
    "ld_robot_cbf_experiment.m", /* pName */
    0                            /* checkKind */
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
    "tracking\\bui"
    "ld_robot_cbf_experiment.m", /* pName */
    0                            /* checkKind */
};

static emlrtDCInfo g_emlrtDCI = {
    110,                          /* lineNo */
    5,                            /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "tracking\\bui"
    "ld_robot_cbf_experiment.m", /* pName */
    1                            /* checkKind */
};

static emlrtDCInfo h_emlrtDCI = {
    110,                          /* lineNo */
    5,                            /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "tracking\\bui"
    "ld_robot_cbf_experiment.m", /* pName */
    4                            /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    135,                          /* lineNo */
    17,                           /* colNo */
    "u",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "tracking\\bui"
    "ld_robot_cbf_experiment.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    135,                          /* lineNo */
    39,                           /* colNo */
    "u",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "tracking\\bui"
    "ld_robot_cbf_experiment.m", /* pName */
    0                            /* checkKind */
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
    "tracking\\bui"
    "ld_robot_cbf_experiment.m", /* pName */
    0                            /* checkKind */
};

static emlrtDCInfo i_emlrtDCI = {
    33,                           /* lineNo */
    12,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "tracking\\bui"
    "ld_robot_cbf_experiment.m", /* pName */
    1                            /* checkKind */
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
    "tracking\\bui"
    "ld_robot_cbf_experiment.m", /* pName */
    0                            /* checkKind */
};

static emlrtDCInfo j_emlrtDCI = {
    32,                           /* lineNo */
    12,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "tracking\\bui"
    "ld_robot_cbf_experiment.m", /* pName */
    1                            /* checkKind */
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
    "tracking\\bui"
    "ld_robot_cbf_experiment.m", /* pName */
    0                            /* checkKind */
};

static emlrtDCInfo k_emlrtDCI = {
    31,                           /* lineNo */
    12,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "tracking\\bui"
    "ld_robot_cbf_experiment.m", /* pName */
    1                            /* checkKind */
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
    "tracking\\bui"
    "ld_robot_cbf_experiment.m", /* pName */
    0                            /* checkKind */
};

static emlrtDCInfo l_emlrtDCI = {
    23,                           /* lineNo */
    12,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "tracking\\bui"
    "ld_robot_cbf_experiment.m", /* pName */
    1                            /* checkKind */
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
    "tracking\\bui"
    "ld_robot_cbf_experiment.m", /* pName */
    0                            /* checkKind */
};

static emlrtDCInfo m_emlrtDCI = {
    22,                           /* lineNo */
    12,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "tracking\\bui"
    "ld_robot_cbf_experiment.m", /* pName */
    1                            /* checkKind */
};

static emlrtRTEInfo c_emlrtRTEI = {
    35,                           /* lineNo */
    5,                            /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "tracking\\bui"
    "ld_robot_cbf_experiment.m" /* pName */
};

static emlrtRTEInfo d_emlrtRTEI = {
    110,                          /* lineNo */
    5,                            /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "tracking\\bui"
    "ld_robot_cbf_experiment.m" /* pName */
};

/* Function Declarations */
static real_T calc_point_p2s_penalty(const real_T pt[2],
                                     const real_T blocks[16], real_T grad_P[2]);

static real_T get_exact_blocks_P(const real_T pt[2], const real_T blocks[16],
                                 real_T *P_v, real_T *P_g, real_T *P_c);

static void get_exact_grad(const real_T pt[2], const real_T blocks[16],
                           real_T P_a, real_T P_v, real_T P_g, real_T P_c,
                           real_T gP_min[2]);

static real_T phi_func(real_T s, real_T *grad);

/* Function Definitions */
static real_T calc_point_p2s_penalty(const real_T pt[2],
                                     const real_T blocks[16], real_T grad_P[2])
{
  __m128d r;
  __m128d r1;
  __m128d r2;
  real_T gPc[2];
  real_T gPg[2];
  real_T gPv[2];
  real_T P_total;
  real_T a;
  real_T b;
  real_T b_a;
  real_T b_delta;
  real_T delta;
  real_T g1;
  real_T g2;
  real_T g3;
  real_T g4;
  real_T v3;
  /*  =========================================================================
   */
  /*  FUNÇÃO AUXILIAR: Penalidade Ponto a Ponto (Smooth Min Incondicional) */
  /*  =========================================================================
   */
  /*  =========================================================================
   */
  /*  FUNÇÃO AUXILIAR: P2S-HSD para UM Polítopo Convexo */
  /*  =========================================================================
   */
  P_total = phi_func(blocks[0] - pt[0], &g1);
  delta = phi_func(pt[0] - blocks[1], &g2);
  v3 = phi_func(blocks[2] - pt[1], &g3);
  b_delta = phi_func(pt[1] - blocks[3], &g4);
  a = 0.25 * (((P_total + delta) + v3) + b_delta);
  grad_P[0] = 0.25 * (-g1 + g2);
  grad_P[1] = 0.25 * (-g3 + g4);
  /*  =========================================================================
   */
  /*  FUNÇÃO AUXILIAR: P2S-HSD para UM Polítopo Convexo */
  /*  =========================================================================
   */
  P_total = phi_func(blocks[4] - pt[0], &g1);
  delta = phi_func(pt[0] - blocks[5], &g2);
  b_delta = phi_func(blocks[6] - pt[1], &g3);
  v3 = phi_func(pt[1] - blocks[7], &g4);
  b = 0.25 * (((P_total + delta) + b_delta) + v3);
  gPv[0] = 0.25 * (-g1 + g2);
  gPv[1] = 0.25 * (-g3 + g4);
  /*  =========================================================================
   */
  /*  FUNÇÃO AUXILIAR: P2S-HSD para UM Polítopo Convexo */
  /*  =========================================================================
   */
  P_total = phi_func(blocks[8] - pt[0], &g1);
  delta = phi_func(pt[0] - blocks[9], &g2);
  b_delta = phi_func(blocks[10] - pt[1], &g3);
  v3 = phi_func(pt[1] - blocks[11], &g4);
  b_a = 0.25 * (((P_total + delta) + b_delta) + v3);
  gPg[0] = 0.25 * (-g1 + g2);
  gPg[1] = 0.25 * (-g3 + g4);
  /*  =========================================================================
   */
  /*  FUNÇÃO AUXILIAR: P2S-HSD para UM Polítopo Convexo */
  /*  =========================================================================
   */
  P_total = phi_func(blocks[12] - pt[0], &g1);
  delta = phi_func(pt[0] - blocks[13], &g2);
  b_delta = phi_func(blocks[14] - pt[1], &g3);
  v3 = phi_func(pt[1] - blocks[15], &g4);
  v3 = 0.25 * (((P_total + delta) + b_delta) + v3);
  gPc[0] = 0.25 * (-g1 + g2);
  gPc[1] = 0.25 * (-g3 + g4);
  /*  =========================================================================
   */
  /*  FUNÇÃO AUXILIAR: Mínimo Suave Base (Smooth Min) */
  /*  =========================================================================
   */
  /*  Fator de suavização Numérica */
  P_total = a - b;
  b_delta = muDoubleScalarSqrt(P_total * P_total + 0.0001);
  g1 = 0.5 * ((a + b) - b_delta);
  /*  O gradiente repassa perfeitamente a direção correspondente ao menor valor
   */
  r = _mm_loadu_pd(&grad_P[0]);
  r1 = _mm_loadu_pd(&gPv[0]);
  r2 = _mm_set1_pd(0.5);
  _mm_storeu_pd(
      &grad_P[0],
      _mm_mul_pd(r2, _mm_sub_pd(_mm_add_pd(r, r1),
                                _mm_mul_pd(_mm_set1_pd(P_total / b_delta),
                                           _mm_sub_pd(r, r1)))));
  /*  =========================================================================
   */
  /*  FUNÇÃO AUXILIAR: Mínimo Suave Base (Smooth Min) */
  /*  =========================================================================
   */
  /*  Fator de suavização Numérica */
  P_total = b_a - v3;
  delta = muDoubleScalarSqrt(P_total * P_total + 0.0001);
  v3 = 0.5 * ((b_a + v3) - delta);
  /*  O gradiente repassa perfeitamente a direção correspondente ao menor valor
   */
  r = _mm_loadu_pd(&gPg[0]);
  r1 = _mm_loadu_pd(&gPc[0]);
  _mm_storeu_pd(
      &gPg[0],
      _mm_mul_pd(r2, _mm_sub_pd(_mm_add_pd(r, r1),
                                _mm_mul_pd(_mm_set1_pd(P_total / delta),
                                           _mm_sub_pd(r, r1)))));
  /*  =========================================================================
   */
  /*  FUNÇÃO AUXILIAR: Mínimo Suave Base (Smooth Min) */
  /*  =========================================================================
   */
  /*  Fator de suavização Numérica */
  delta = g1 - v3;
  b_delta = muDoubleScalarSqrt(delta * delta + 0.0001);
  P_total = 0.5 * ((g1 + v3) - b_delta);
  /*  O gradiente repassa perfeitamente a direção correspondente ao menor valor
   */
  r = _mm_loadu_pd(&grad_P[0]);
  r1 = _mm_loadu_pd(&gPg[0]);
  _mm_storeu_pd(
      &grad_P[0],
      _mm_mul_pd(r2, _mm_sub_pd(_mm_add_pd(r, r1),
                                _mm_mul_pd(_mm_set1_pd(delta / b_delta),
                                           _mm_sub_pd(r, r1)))));
  /*  NENHUM CLAMPING AQUI. Deixamos a matemática suave cuidar dos gradientes.
   */
  return P_total;
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
  real_T gP_r1[2];
  real_T gP_r2[2];
  real_T gP_r3[2];
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
  real_T P_v_n;
  real_T Ts;
  real_T b_P_c_k;
  real_T b_a;
  real_T b_xs_tmp;
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
    P_next = get_exact_blocks_P(&x_next[0], &params[10], &P_v_n, &g_corridor,
                                &P_g_k);
    varargin_1[0] = P_next;
    varargin_1[1] = P_v_n;
    varargin_1[2] = g_corridor;
    varargin_1[3] = P_g_k;
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
    P_v_n = x_k[1] - b_xs_tmp;
    b_a = v_n - v_s;
    g_corridor = w_n - w_s;
    l_u = (l_u + ((5.0 * (P_c_k * P_c_k + P_v_n * P_v_n) + 0.5 * (b_a * b_a)) +
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
  /*  GEOFENCE PONTO A PONTO (Generalized P2S-HSD Incondicional) */
  /*  A matemática resolve sozinha se o gradiente deve atuar ou zerar. */
  /*  ===================================================================== */
  g_corridor = calc_point_p2s_penalty(xs, &params[10], a);
  P_g_k = calc_point_p2s_penalty(r1, &params[10], gP_r1);
  P_c_k = calc_point_p2s_penalty(r2, &params[10], gP_r2);
  b_a = calc_point_p2s_penalty(r3, &params[10], gP_r3);
  P_v_n = calc_point_p2s_penalty(&params[3], &params[10], a__1);
  w_n = params[8] * params[8];
  cost = (((((((l_u + params[26] * sumColumnB(y)) +
               params[27] * w_n * (v_s * v_s + w_s * w_s)) +
              params[29] *
                  (((sumColumnB(b_y) + sumColumnB(c_y)) + sumColumnB(d_y)) +
                   sumColumnB(e_y))) +
             params[28] * g_corridor) +
            params[28] * P_g_k) +
           params[28] * P_c_k) +
          params[28] * b_a) +
         params[28] * P_v_n;
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
  x_k[0] = 0.0;
  x_k[1] = 0.0;
  x_k[2] = 0.0;
  r = _mm_loadu_pd(&grad_xs[0]);
  r = _mm_mul_pd(_mm_set1_pd(2.0 * params[26]), r);
  _mm_storeu_pd(&grad_xs[0], r);
  _mm_storeu_pd(&x_k[0], r);
  g_corridor = 2.0 * params[27] * w_n;
  grad_us_idx_0 = g_corridor * v_s;
  grad_us_idx_1 = g_corridor * w_s;
  /*  Acumulação Incondicional dos Gradientes Nodais */
  r = _mm_loadu_pd(&grad_xs[0]);
  b_r1 = _mm_loadu_pd(&cost_tmp[0]);
  b_r2 = _mm_loadu_pd(&a[0]);
  b_r3 = _mm_set1_pd(2.0 * params[29]);
  r4 = _mm_set1_pd(params[28]);
  r5 = _mm_set1_pd(-1.0);
  _mm_storeu_pd(&grad_xs[0], _mm_add_pd(_mm_sub_pd(_mm_mul_pd(r, r5),
                                                   _mm_mul_pd(b_r3, b_r1)),
                                        _mm_mul_pd(r4, b_r2)));
  b_r2 = _mm_loadu_pd(&r1[0]);
  r = _mm_loadu_pd(&xs[0]);
  r6 = _mm_loadu_pd(&r2[0]);
  b_r1 = _mm_loadu_pd(&gP_r1[0]);
  r7 = _mm_set1_pd(2.0);
  _mm_storeu_pd(
      &xs[0],
      _mm_add_pd(
          _mm_mul_pd(b_r3, _mm_sub_pd(_mm_sub_pd(_mm_mul_pd(r7, b_r2), r), r6)),
          _mm_mul_pd(r4, b_r1)));
  b_r1 = _mm_loadu_pd(&r3[0]);
  r = _mm_loadu_pd(&gP_r2[0]);
  _mm_storeu_pd(
      &r1[0],
      _mm_add_pd(
          _mm_mul_pd(b_r3,
                     _mm_sub_pd(_mm_sub_pd(_mm_mul_pd(r7, r6), b_r2), b_r1)),
          _mm_mul_pd(r4, r)));
  r = _mm_loadu_pd(&gP_r3[0]);
  _mm_storeu_pd(
      &r3[0],
      _mm_add_pd(
          _mm_mul_pd(b_r3, _mm_sub_pd(_mm_sub_pd(_mm_mul_pd(r7, b_r1), r6),
                                      _mm_loadu_pd(&params[3]))),
          _mm_mul_pd(r4, r)));
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
    w_n =
        get_exact_blocks_P(&X_hist_data[i1], &params[10], &P_c_k, &b_a, &P_v_n);
    varargin_1[0] = w_n;
    varargin_1[1] = P_c_k;
    varargin_1[2] = b_a;
    varargin_1[3] = P_v_n;
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
      get_exact_grad(&X_hist_data[i1], &params[10], w_n, P_c_k, b_a, P_v_n, a);
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
