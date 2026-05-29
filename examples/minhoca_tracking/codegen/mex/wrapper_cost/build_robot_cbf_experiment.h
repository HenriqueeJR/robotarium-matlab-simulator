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
real_T get_exact_blocks_P(const real_T pt[2], const real_T blocks[16],
                          real_T *P_v, real_T *P_g, real_T *P_c);

real_T get_single_block_p2s(const real_T pt[2], const real_T blk[4],
                            real_T gP[2]);

/* End of code generation (build_robot_cbf_experiment.h) */
