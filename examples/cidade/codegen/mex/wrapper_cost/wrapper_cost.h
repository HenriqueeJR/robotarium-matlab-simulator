/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * wrapper_cost.h
 *
 * Code generation for function 'wrapper_cost'
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
real_T wrapper_cost(const emlrtStack *sp, const real_T u[100],
                    const real_T params[8]);

/* End of code generation (wrapper_cost.h) */
