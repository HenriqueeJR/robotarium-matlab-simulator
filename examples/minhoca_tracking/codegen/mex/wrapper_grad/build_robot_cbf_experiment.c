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

/* Function Definitions */
real_T calc_corridor_penalty(const real_T pt[2], const real_T blocks[16],
                             real_T grad_P[2])
{
  __m128d r;
  __m128d r1;
  __m128d r2;
  real_T gP_c[2];
  real_T gP_g[2];
  real_T gP_v[2];
  real_T P_c;
  real_T P_g;
  real_T P_total;
  real_T S1;
  real_T S2;
  real_T delta_1;
  real_T delta_3;
  /*  =========================================================================
   */
  /*  FUNÇÃO AUXILIAR 3: Smooth Min Hierárquico (Para os Custos Terminais) */
  /*  =========================================================================
   */
  delta_3 = get_blocks_P(pt, blocks, &S2, &P_g, &P_c);
  grad_P[0] = 0.0;
  grad_P[1] = 0.0;
  P_total = blocks[0] - pt[0];
  if (P_total > 0.0) {
    grad_P[0] = -(2.0 * P_total);
  }
  P_total = pt[0] - blocks[1];
  if (P_total > 0.0) {
    grad_P[0] += 2.0 * P_total;
  }
  P_total = blocks[2] - pt[1];
  if (P_total > 0.0) {
    grad_P[1] = -(2.0 * P_total);
  }
  P_total = pt[1] - blocks[3];
  if (P_total > 0.0) {
    grad_P[1] += 2.0 * P_total;
  }
  gP_v[0] = 0.0;
  gP_v[1] = 0.0;
  P_total = blocks[4] - pt[0];
  if (P_total > 0.0) {
    gP_v[0] = -(2.0 * P_total);
  }
  P_total = pt[0] - blocks[5];
  if (P_total > 0.0) {
    gP_v[0] += 2.0 * P_total;
  }
  P_total = blocks[6] - pt[1];
  if (P_total > 0.0) {
    gP_v[1] = -(2.0 * P_total);
  }
  P_total = pt[1] - blocks[7];
  if (P_total > 0.0) {
    gP_v[1] += 2.0 * P_total;
  }
  gP_g[0] = 0.0;
  gP_g[1] = 0.0;
  P_total = blocks[8] - pt[0];
  if (P_total > 0.0) {
    gP_g[0] = -(2.0 * P_total);
  }
  P_total = pt[0] - blocks[9];
  if (P_total > 0.0) {
    gP_g[0] += 2.0 * P_total;
  }
  P_total = blocks[10] - pt[1];
  if (P_total > 0.0) {
    gP_g[1] = -(2.0 * P_total);
  }
  P_total = pt[1] - blocks[11];
  if (P_total > 0.0) {
    gP_g[1] += 2.0 * P_total;
  }
  gP_c[0] = 0.0;
  gP_c[1] = 0.0;
  P_total = blocks[12] - pt[0];
  if (P_total > 0.0) {
    gP_c[0] = -(2.0 * P_total);
  }
  P_total = pt[0] - blocks[13];
  if (P_total > 0.0) {
    gP_c[0] += 2.0 * P_total;
  }
  P_total = blocks[14] - pt[1];
  if (P_total > 0.0) {
    gP_c[1] = -(2.0 * P_total);
  }
  P_total = pt[1] - blocks[15];
  if (P_total > 0.0) {
    gP_c[1] += 2.0 * P_total;
  }
  /*  Nível 1A: Smooth Min entre Azul e Vermelho */
  P_total = delta_3 - S2;
  delta_1 = muDoubleScalarSqrt(P_total * P_total + 0.0001);
  S1 = 0.5 * ((delta_3 + S2) - delta_1);
  r = _mm_loadu_pd(&grad_P[0]);
  r1 = _mm_loadu_pd(&gP_v[0]);
  r2 = _mm_set1_pd(0.5);
  _mm_storeu_pd(
      &grad_P[0],
      _mm_mul_pd(r2, _mm_sub_pd(_mm_add_pd(r, r1),
                                _mm_mul_pd(_mm_set1_pd(P_total / delta_1),
                                           _mm_sub_pd(r, r1)))));
  /*  Nível 1B: Smooth Min entre Verde e Ciano */
  P_total = P_g - P_c;
  delta_1 = muDoubleScalarSqrt(P_total * P_total + 0.0001);
  S2 = 0.5 * ((P_g + P_c) - delta_1);
  r = _mm_loadu_pd(&gP_g[0]);
  r1 = _mm_loadu_pd(&gP_c[0]);
  _mm_storeu_pd(
      &gP_g[0],
      _mm_mul_pd(r2, _mm_sub_pd(_mm_add_pd(r, r1),
                                _mm_mul_pd(_mm_set1_pd(P_total / delta_1),
                                           _mm_sub_pd(r, r1)))));
  /*  Nível 2: Smooth Min entre Resultados */
  delta_1 = S1 - S2;
  delta_3 = muDoubleScalarSqrt(delta_1 * delta_1 + 0.0001);
  P_total = 0.5 * ((S1 + S2) - delta_3);
  r = _mm_loadu_pd(&grad_P[0]);
  r1 = _mm_loadu_pd(&gP_g[0]);
  _mm_storeu_pd(
      &grad_P[0],
      _mm_mul_pd(r2, _mm_sub_pd(_mm_add_pd(r, r1),
                                _mm_mul_pd(_mm_set1_pd(delta_1 / delta_3),
                                           _mm_sub_pd(r, r1)))));
  if (P_total <= 0.0) {
    P_total = 0.0;
    grad_P[0] = 0.0;
    grad_P[1] = 0.0;
  }
  return P_total;
}

real_T get_blocks_P(const real_T pt[2], const real_T blocks[16], real_T *P_v,
                    real_T *P_g, real_T *P_c)
{
  real_T P_a;
  real_T a;
  real_T b_a;
  real_T c_a;
  real_T d_a;
  /*  =========================================================================
   */
  /*  FUNÇÃO AUXILIAR 1: Avalia Distância P para cada bloco */
  /*  =========================================================================
   */
  /*  Bloco Azul */
  a = muDoubleScalarMax(0.0, blocks[0] - pt[0]);
  b_a = muDoubleScalarMax(0.0, pt[0] - blocks[1]);
  c_a = muDoubleScalarMax(0.0, blocks[2] - pt[1]);
  d_a = muDoubleScalarMax(0.0, pt[1] - blocks[3]);
  P_a = ((a * a + b_a * b_a) + c_a * c_a) + d_a * d_a;
  /*  Bloco Vermelho */
  a = muDoubleScalarMax(0.0, blocks[4] - pt[0]);
  b_a = muDoubleScalarMax(0.0, pt[0] - blocks[5]);
  c_a = muDoubleScalarMax(0.0, blocks[6] - pt[1]);
  d_a = muDoubleScalarMax(0.0, pt[1] - blocks[7]);
  *P_v = ((a * a + b_a * b_a) + c_a * c_a) + d_a * d_a;
  /*  Bloco Verde */
  a = muDoubleScalarMax(0.0, blocks[8] - pt[0]);
  b_a = muDoubleScalarMax(0.0, pt[0] - blocks[9]);
  c_a = muDoubleScalarMax(0.0, blocks[10] - pt[1]);
  d_a = muDoubleScalarMax(0.0, pt[1] - blocks[11]);
  *P_g = ((a * a + b_a * b_a) + c_a * c_a) + d_a * d_a;
  /*  Bloco Ciano */
  a = muDoubleScalarMax(0.0, blocks[12] - pt[0]);
  b_a = muDoubleScalarMax(0.0, pt[0] - blocks[13]);
  c_a = muDoubleScalarMax(0.0, blocks[14] - pt[1]);
  d_a = muDoubleScalarMax(0.0, pt[1] - blocks[15]);
  *P_c = ((a * a + b_a * b_a) + c_a * c_a) + d_a * d_a;
  return P_a;
}

void get_exact_grad(const real_T pt[2], const real_T blocks[16], real_T P_a,
                    real_T P_v, real_T P_g, real_T P_c, real_T gP_min[2])
{
  real_T P_min;
  /*  =========================================================================
   */
  /*  FUNÇÃO AUXILIAR 2: Gradiente Mínimo Exato (Para o CBF Dinâmico) */
  /*  =========================================================================
   */
  P_min = muDoubleScalarMin(muDoubleScalarMin(P_a, P_v),
                            muDoubleScalarMin(P_g, P_c));
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

/* End of code generation (build_robot_cbf_experiment.c) */
