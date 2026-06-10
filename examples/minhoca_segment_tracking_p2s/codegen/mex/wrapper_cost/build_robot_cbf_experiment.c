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

/* Function Declarations */
static real_T phi_func(real_T s, real_T *grad);

/* Function Definitions */
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

real_T calc_point_p2s_penalty(const real_T pt[2], const real_T blocks[16],
                              real_T grad_P[2])
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
  /*  FUNÇÃO AUXILIAR: Penalidade Ponto a Ponto (Smooth Min para a CBF) */
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
  b_delta = muDoubleScalarSqrt(P_total * P_total + 1.0E-10);
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
  delta = muDoubleScalarSqrt(P_total * P_total + 1.0E-10);
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
  b_delta = muDoubleScalarSqrt(delta * delta + 1.0E-10);
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
  return P_total;
}

real_T calc_segment_p2s_penalty(const real_T pa[2], const real_T pb[2],
                                const real_T blocks[16], real_T grad_pa[2],
                                real_T grad_pb[2])
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
  /*  FUNÇÃO AUXILIAR: Penalidade de Segmento (Contenção Convexa Suavizada) */
  /*  =========================================================================
   */
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
  d_v2 = 0.25 * (((Cost + delta) + b_delta) + v4) +
         0.25 * (((d_v1 + d_v2) + d_v3) + e_v4);
  delta =
      0.25 * (((v1 + v2) + v3) + b_v4) + 0.25 * (((e_v1 + e_v2) + e_v3) + f_v4);
  d_v1 = 0.25 * (((b_v1 + b_v2) + b_v3) + c_v4) +
         0.25 * (((f_v1 + f_v2) + f_v3) + g_v4);
  v4 = 0.25 * (((c_v1 + c_v2) + c_v3) + d_v4) +
       0.25 * (((g_v1 + g_v2) + g_v3) + h_v4);
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
  grad_pa[0] = gC1[0];
  grad_pb[0] = gC1[2];
  grad_pa[1] = gC1[1];
  grad_pb[1] = gC1[3];
  return Cost;
}

/* End of code generation (build_robot_cbf_experiment.c) */
