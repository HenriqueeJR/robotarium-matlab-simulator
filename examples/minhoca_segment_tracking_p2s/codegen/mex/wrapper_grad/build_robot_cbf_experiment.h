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
real_T calc_point_p2s_penalty(const real_T pt[2], const real_T blocks[16],
                              real_T grad_P[2]);

real_T calc_segment_p2s_penalty(const real_T pa[2], const real_T pb[2],
                                const real_T blocks[16], real_T grad_pa[2],
                                real_T grad_pb[2]);

real_T phi_func(real_T s, real_T *grad);

/* End of code generation (build_robot_cbf_experiment.h) */
