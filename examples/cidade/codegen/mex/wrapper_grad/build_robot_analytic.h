/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * build_robot_analytic.h
 *
 * Code generation for function 'build_robot_analytic'
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
real_T build_robot_analytic(const emlrtStack *sp, const real_T u[150],
                            const real_T params[8], real_T grad[150]);

/* End of code generation (build_robot_analytic.h) */
