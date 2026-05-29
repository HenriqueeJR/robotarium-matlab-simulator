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

/* Function Declarations */
static real_T phi_func(real_T s, real_T *grad);

/* Function Definitions */
static real_T phi_func(real_T s, real_T *grad)
{
  real_T val;
  /*  =========================================================================
   */
  /*  FUNÇÃO BASE: Generalized P2S-HSD (Função Phi e sua Derivada) */
  /*  =========================================================================
   */
  if (s >= 0.0) {
    /*  Função Phi(s) */
    val = muDoubleScalarPower(s, 3.0) / (2.0 * (s + 1.0E-5));
    /*  Derivada Analítica Phi'(s) */
    *grad = s * s * (2.0 * s + 3.0000000000000004E-5) /
            (2.0 * ((s + 1.0E-5) * (s + 1.0E-5)));
  } else {
    val = 0.0;
    *grad = 0.0;
  }
  return val;
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
  /*  FUNÇÕES DO CBF (Avaliação Exata Mantida para Freios Corretos da Dinâmica)
   */
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

real_T get_single_block_p2s(const real_T pt[2], const real_T blk[4],
                            real_T gP[2])
{
  real_T P;
  real_T g1;
  real_T g2;
  real_T g3;
  real_T g4;
  real_T v2;
  real_T v3;
  real_T v4;
  /*  =========================================================================
   */
  /*  FUNÇÃO AUXILIAR: P2S-HSD para UM Polítopo Convexo (Bloco 2D) */
  /*  =========================================================================
   */
  /*  Distâncias para as 4 faces do bloco (a_i^T p - b_i <= 0) */
  /*  Face esquerda */
  /*  Face direita */
  /*  Face inferior */
  /*  Face superior */
  P = phi_func(blk[0] - pt[0], &g1);
  v2 = phi_func(pt[0] - blk[1], &g2);
  v3 = phi_func(blk[2] - pt[1], &g3);
  v4 = phi_func(pt[1] - blk[3], &g4);
  /*  Weak Generalized P2S-HSD: (1/N) * Sum(Phi) */
  /*  Como temos 4 faces (N=4), multiplicamos por 1/4 = 0.25 */
  P = 0.25 * (((P + v2) + v3) + v4);
  /*  Derivadas da cadeia considerando a normal de cada face */
  gP[0] = 0.25 * (-g1 + g2);
  gP[1] = 0.25 * (-g3 + g4);
  return P;
}

/* End of code generation (build_robot_cbf_experiment.c) */
