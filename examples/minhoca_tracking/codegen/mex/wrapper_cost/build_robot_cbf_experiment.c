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
  /*  NENHUM CLAMPING AQUI. Deixamos a matemática suave cuidar dos gradientes.
   */
  return P_total;
}

real_T get_exact_blocks_P(const real_T pt[2], const real_T blocks[16],
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

/* End of code generation (build_robot_cbf_experiment.c) */
