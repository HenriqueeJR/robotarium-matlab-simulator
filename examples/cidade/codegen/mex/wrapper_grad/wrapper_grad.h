/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * wrapper_grad.h
 *
 * Code generation for function 'wrapper_grad'
 *
 */

#pragma once

/* Include files */
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void wrapper_grad(const emlrtStack *sp, const real_T u[150],
                  const real_T params[8], real_T grad[150]);

/* End of code generation (wrapper_grad.h) */
