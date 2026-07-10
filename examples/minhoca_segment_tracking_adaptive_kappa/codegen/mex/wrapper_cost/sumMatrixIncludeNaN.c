/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sumMatrixIncludeNaN.c
 *
 * Code generation for function 'sumMatrixIncludeNaN'
 *
 */

/* Include files */
#include "sumMatrixIncludeNaN.h"
#include "rt_nonfinite.h"

/* Function Definitions */
real_T b_sumColumnB(const real_T x[24])
{
  real_T y;
  int32_T k;
  y = x[0];
  for (k = 0; k < 23; k++) {
    y += x[k + 1];
  }
  return y;
}

real_T sumColumnB(const real_T x[2])
{
  return x[0] + x[1];
}

/* End of code generation (sumMatrixIncludeNaN.c) */
