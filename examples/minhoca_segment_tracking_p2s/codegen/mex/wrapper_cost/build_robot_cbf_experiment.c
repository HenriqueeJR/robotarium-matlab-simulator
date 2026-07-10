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
#include "mwmathutil.h"
#include <emmintrin.h>

/* Variable Definitions */
static emlrtRSInfo ab_emlrtRSI = {
    235,               /* lineNo */
    "smooth_min_func", /* fcnName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m" /* pathName */
};

static emlrtRSInfo jb_emlrtRSI = {
    266,                        /* lineNo */
    "calc_segment_p2s_penalty", /* fcnName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m" /* pathName */
};

static emlrtRSInfo kb_emlrtRSI = {
    267,                        /* lineNo */
    "calc_segment_p2s_penalty", /* fcnName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m" /* pathName */
};

static emlrtRSInfo lb_emlrtRSI = {
    269,                        /* lineNo */
    "calc_segment_p2s_penalty", /* fcnName */
    "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
    "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
    "tracking_p2s\\build_robot_cbf_experiment.m" /* pathName */
};

static emlrtRTEInfo b_emlrtRTEI = {
    13,     /* lineNo */
    9,      /* colNo */
    "sqrt", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\elfun\\sqrt.m" /* pName
                                                                       */
};

/* Function Declarations */
static real_T b_smooth_min_func(const emlrtStack *sp, real_T a, real_T b,
                                const real_T ga[4], const real_T gb[4],
                                real_T gM[4]);

static real_T phi_func(real_T s, real_T *grad);

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
  st.site = &ab_emlrtRSI;
  if (delta + 1.0E-10 < 0.0) {
    emlrtErrorWithMessageIdR2018a(
        &st, &b_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
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

real_T calc_segment_p2s_penalty(const emlrtStack *sp, const real_T pa[2],
                                const real_T pb[2], const real_T blocks[16],
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
  st.site = &jb_emlrtRSI;
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
  st.site = &kb_emlrtRSI;
  g1 = b_smooth_min_func(&st,
                         0.25 * (((c_v1 + c_v2) + c_v3) + c_v4) +
                             0.25 * (((g_v1 + g_v2) + g_v3) + g_v4),
                         0.25 * (((d_v1 + d_v2) + d_v3) + d_v4) +
                             0.25 * (((h_v1 + h_v2) + h_v3) + h_v4),
                         gPa1, gPa2, gM34);
  st.site = &lb_emlrtRSI;
  Cost = b_smooth_min_func(&st, g2, g1, gM12, gM34, gPa1);
  grad_pa[0] = gPa1[0];
  grad_pb[0] = gPa1[2];
  grad_pa[1] = gPa1[1];
  grad_pb[1] = gPa1[3];
  return Cost;
}

real_T get_single_block_p2s(const real_T pt[2], const real_T blk[4],
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

real_T smooth_min_func(const emlrtStack *sp, real_T a, real_T b,
                       const real_T ga[2], const real_T gb[2], real_T gM[2])
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
  st.site = &ab_emlrtRSI;
  if (delta + 1.0E-10 < 0.0) {
    emlrtErrorWithMessageIdR2018a(
        &st, &b_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
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

/* End of code generation (build_robot_cbf_experiment.c) */
