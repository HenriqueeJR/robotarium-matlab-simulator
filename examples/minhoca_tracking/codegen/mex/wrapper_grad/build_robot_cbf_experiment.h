/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * build_robot_cbf_experiment.h
 *
 * Code generation for function 'build_robot_cbf_experiment'
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
real_T calc_corridor_penalty(const real_T pt[2], const real_T blocks[16],
                             real_T grad_P[2]);

real_T get_blocks_P(const real_T pt[2], const real_T blocks[16], real_T *P_v,
                    real_T *P_g, real_T *P_c);

void get_exact_grad(const real_T pt[2], const real_T blocks[16], real_T P_a,
                    real_T P_v, real_T P_g, real_T P_c, real_T gP_min[2]);

/* End of code generation (build_robot_cbf_experiment.h) */
