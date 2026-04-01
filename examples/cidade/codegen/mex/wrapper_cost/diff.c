/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * diff.c
 *
 * Code generation for function 'diff'
 *
 */

/* Include files */
#include "diff.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void diff(const real_T x[75], real_T y[74])
{
  real_T work;
  int32_T m;
  work = x[0];
  for (m = 0; m < 74; m++) {
    real_T tmp2;
    tmp2 = work;
    work = x[m + 1];
    y[m] = work - tmp2;
  }
}

/* End of code generation (diff.c) */
