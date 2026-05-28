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
#include "sumMatrixIncludeNaN.h"
#include "wrapper_grad_data.h"
#include "wrapper_grad_emxutil.h"
#include "wrapper_grad_types.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <string.h>

/* Variable Definitions */
static emlrtDCInfo emlrtDCI = {
    26,                           /* lineNo */
    14,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\cbf_cruz_waypoints_tracking\\build_robot_cb"
    "f_experiment.m", /* pName */
    1                 /* checkKind */
};

static emlrtBCInfo emlrtBCI = {
    1,                            /* iFirst */
    51,                           /* iLast */
    26,                           /* lineNo */
    14,                           /* colNo */
    "W",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\cbf_cruz_waypoints_tracking\\build_robot_cb"
    "f_experiment.m", /* pName */
    0                 /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = {
    47,                           /* lineNo */
    23,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\cbf_cruz_waypoints_tracking\\build_robot_cb"
    "f_experiment.m", /* pName */
    4                 /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = {
    47,                           /* lineNo */
    23,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\cbf_cruz_waypoints_tracking\\build_robot_cb"
    "f_experiment.m", /* pName */
    1                 /* checkKind */
};

static emlrtRTEInfo emlrtRTEI = {
    54,                           /* lineNo */
    13,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\cbf_cruz_waypoints_tracking\\build_robot_cb"
    "f_experiment.m" /* pName */
};

static emlrtBCInfo b_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    48,                           /* lineNo */
    15,                           /* colNo */
    "X_hist",                     /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\cbf_cruz_waypoints_tracking\\build_robot_cb"
    "f_experiment.m", /* pName */
    0                 /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    114,                          /* lineNo */
    19,                           /* colNo */
    "X_hist",                     /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\cbf_cruz_waypoints_tracking\\build_robot_cb"
    "f_experiment.m", /* pName */
    0                 /* checkKind */
};

static emlrtDCInfo d_emlrtDCI = {
    122,                          /* lineNo */
    21,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\cbf_cruz_waypoints_tracking\\build_robot_cb"
    "f_experiment.m", /* pName */
    1                 /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    122,                          /* lineNo */
    21,                           /* colNo */
    "X_hist",                     /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\cbf_cruz_waypoints_tracking\\build_robot_cb"
    "f_experiment.m", /* pName */
    0                 /* checkKind */
};

static emlrtRTEInfo b_emlrtRTEI = {
    230,                          /* lineNo */
    13,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\cbf_cruz_waypoints_tracking\\build_robot_cb"
    "f_experiment.m" /* pName */
};

static emlrtDCInfo e_emlrtDCI = {
    231,                          /* lineNo */
    25,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\cbf_cruz_waypoints_tracking\\build_robot_cb"
    "f_experiment.m", /* pName */
    1                 /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    231,                          /* lineNo */
    25,                           /* colNo */
    "X_hist",                     /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\cbf_cruz_waypoints_tracking\\build_robot_cb"
    "f_experiment.m", /* pName */
    0                 /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    232,                          /* lineNo */
    28,                           /* colNo */
    "X_hist",                     /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\cbf_cruz_waypoints_tracking\\build_robot_cb"
    "f_experiment.m", /* pName */
    0                 /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    380,                          /* lineNo */
    16,                           /* colNo */
    "grad_U",                     /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\cbf_cruz_waypoints_tracking\\build_robot_cb"
    "f_experiment.m", /* pName */
    0                 /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    380,                          /* lineNo */
    30,                           /* colNo */
    "grad_U",                     /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\cbf_cruz_waypoints_tracking\\build_robot_cb"
    "f_experiment.m", /* pName */
    0                 /* checkKind */
};

static emlrtECInfo emlrtECI = {
    -1,                           /* nDims */
    380,                          /* lineNo */
    9,                            /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\cbf_cruz_waypoints_tracking\\build_robot_cb"
    "f_experiment.m" /* pName */
};

static emlrtDCInfo f_emlrtDCI = {
    384,                          /* lineNo */
    12,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\cbf_cruz_waypoints_tracking\\build_robot_cb"
    "f_experiment.m", /* pName */
    1                 /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = {
    1,                            /* iFirst */
    51,                           /* iLast */
    384,                          /* lineNo */
    12,                           /* colNo */
    "grad",                       /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\cbf_cruz_waypoints_tracking\\build_robot_cb"
    "f_experiment.m", /* pName */
    0                 /* checkKind */
};

static emlrtECInfo b_emlrtECI = {
    -1,                           /* nDims */
    384,                          /* lineNo */
    5,                            /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\cbf_cruz_waypoints_tracking\\build_robot_cb"
    "f_experiment.m" /* pName */
};

static emlrtBCInfo j_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    55,                           /* lineNo */
    17,                           /* colNo */
    "u",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\cbf_cruz_waypoints_tracking\\build_robot_cb"
    "f_experiment.m", /* pName */
    0                 /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    56,                           /* lineNo */
    17,                           /* colNo */
    "u",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\cbf_cruz_waypoints_tracking\\build_robot_cb"
    "f_experiment.m", /* pName */
    0                 /* checkKind */
};

static emlrtDCInfo g_emlrtDCI = {
    172,                          /* lineNo */
    5,                            /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\cbf_cruz_waypoints_tracking\\build_robot_cb"
    "f_experiment.m", /* pName */
    1                 /* checkKind */
};

static emlrtDCInfo h_emlrtDCI = {
    172,                          /* lineNo */
    5,                            /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\cbf_cruz_waypoints_tracking\\build_robot_cb"
    "f_experiment.m", /* pName */
    4                 /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    233,                          /* lineNo */
    17,                           /* colNo */
    "u",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\cbf_cruz_waypoints_tracking\\build_robot_cb"
    "f_experiment.m", /* pName */
    0                 /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    233,                          /* lineNo */
    39,                           /* colNo */
    "u",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\cbf_cruz_waypoints_tracking\\build_robot_cb"
    "f_experiment.m", /* pName */
    0                 /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = {
    1,                            /* iFirst */
    51,                           /* iLast */
    40,                           /* lineNo */
    12,                           /* colNo */
    "W",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\cbf_cruz_waypoints_tracking\\build_robot_cb"
    "f_experiment.m", /* pName */
    0                 /* checkKind */
};

static emlrtDCInfo i_emlrtDCI = {
    40,                           /* lineNo */
    12,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\cbf_cruz_waypoints_tracking\\build_robot_cb"
    "f_experiment.m", /* pName */
    1                 /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = {
    1,                            /* iFirst */
    51,                           /* iLast */
    39,                           /* lineNo */
    12,                           /* colNo */
    "W",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\cbf_cruz_waypoints_tracking\\build_robot_cb"
    "f_experiment.m", /* pName */
    0                 /* checkKind */
};

static emlrtDCInfo j_emlrtDCI = {
    39,                           /* lineNo */
    12,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\cbf_cruz_waypoints_tracking\\build_robot_cb"
    "f_experiment.m", /* pName */
    1                 /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = {
    1,                            /* iFirst */
    51,                           /* iLast */
    38,                           /* lineNo */
    12,                           /* colNo */
    "W",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\cbf_cruz_waypoints_tracking\\build_robot_cb"
    "f_experiment.m", /* pName */
    0                 /* checkKind */
};

static emlrtDCInfo k_emlrtDCI = {
    38,                           /* lineNo */
    12,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\cbf_cruz_waypoints_tracking\\build_robot_cb"
    "f_experiment.m", /* pName */
    1                 /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = {
    1,                            /* iFirst */
    51,                           /* iLast */
    28,                           /* lineNo */
    12,                           /* colNo */
    "W",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\cbf_cruz_waypoints_tracking\\build_robot_cb"
    "f_experiment.m", /* pName */
    0                 /* checkKind */
};

static emlrtDCInfo l_emlrtDCI = {
    28,                           /* lineNo */
    12,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\cbf_cruz_waypoints_tracking\\build_robot_cb"
    "f_experiment.m", /* pName */
    1                 /* checkKind */
};

static emlrtBCInfo r_emlrtBCI = {
    1,                            /* iFirst */
    51,                           /* iLast */
    27,                           /* lineNo */
    12,                           /* colNo */
    "W",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\cbf_cruz_waypoints_tracking\\build_robot_cb"
    "f_experiment.m", /* pName */
    0                 /* checkKind */
};

static emlrtDCInfo m_emlrtDCI = {
    27,                           /* lineNo */
    12,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\cbf_cruz_waypoints_tracking\\build_robot_cb"
    "f_experiment.m", /* pName */
    1                 /* checkKind */
};

static emlrtRTEInfo c_emlrtRTEI = {
    47,                           /* lineNo */
    5,                            /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\cbf_cruz_waypoints_tracking\\build_robot_cb"
    "f_experiment.m" /* pName */
};

static emlrtRTEInfo d_emlrtRTEI = {
    172,                          /* lineNo */
    5,                            /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\cbf_cruz_waypoints_tracking\\build_robot_cb"
    "f_experiment.m" /* pName */
};

/* Function Declarations */
static real_T calc_cross_penalty(const real_T pt[2], const real_T x_obs[2],
                                 real_T L_safe, real_T W_safe,
                                 real_T grad_P[2]);

/* Function Definitions */
static real_T calc_cross_penalty(const real_T pt[2], const real_T x_obs[2],
                                 real_T L_safe, real_T W_safe, real_T grad_P[2])
{
  real_T gP2[2];
  real_T P1;
  real_T P2;
  real_T P_cross;
  real_T delta;
  real_T diff_P;
  real_T dx1;
  real_T dx2;
  real_T dy1;
  real_T dy2;
  real_T x_pos;
  real_T y_pos;
  x_pos = pt[0] - x_obs[0];
  y_pos = pt[1] - x_obs[1];
  P2 = muDoubleScalarAbs(x_pos);
  dx1 = muDoubleScalarMax(0.0, P2 - L_safe);
  P_cross = muDoubleScalarAbs(y_pos);
  dy1 = muDoubleScalarMax(0.0, P_cross - W_safe);
  P1 = dx1 * dx1 + dy1 * dy1;
  dx2 = muDoubleScalarMax(0.0, P2 - W_safe);
  dy2 = muDoubleScalarMax(0.0, P_cross - L_safe);
  P2 = dx2 * dx2 + dy2 * dy2;
  /*  --- Mínimo Suave Analítico (Smooth Min) --- */
  /*  Fator de suavização para o L-BFGS não travar */
  diff_P = P1 - P2;
  delta = muDoubleScalarSqrt(diff_P * diff_P + 0.0001);
  P_cross = 0.5 * ((P1 + P2) - delta);
  /*  Truncamento suave: só aplica penalidade se estiver fora da cruz */
  if (P_cross <= 0.0) {
    P_cross = 0.0;
    grad_P[0] = 0.0;
    grad_P[1] = 0.0;
  } else {
    __m128d r;
    __m128d r1;
    grad_P[0] = 0.0;
    gP2[0] = 0.0;
    grad_P[1] = 0.0;
    gP2[1] = 0.0;
    if (dx1 > 0.0) {
      grad_P[0] = 2.0 * dx1 * muDoubleScalarSign(x_pos);
    }
    if (dy1 > 0.0) {
      grad_P[1] = 2.0 * dy1 * muDoubleScalarSign(y_pos);
    }
    if (dx2 > 0.0) {
      gP2[0] = 2.0 * dx2 * muDoubleScalarSign(x_pos);
    }
    if (dy2 > 0.0) {
      gP2[1] = 2.0 * dy2 * muDoubleScalarSign(y_pos);
    }
    /*  Regra da cadeia para o Smooth Min */
    r = _mm_loadu_pd(&grad_P[0]);
    r1 = _mm_loadu_pd(&gP2[0]);
    _mm_storeu_pd(&grad_P[0],
                  _mm_mul_pd(_mm_set1_pd(0.5),
                             _mm_sub_pd(_mm_add_pd(r, r1),
                                        _mm_mul_pd(_mm_set1_pd(diff_P / delta),
                                                   _mm_sub_pd(r, r1)))));
  }
  return P_cross;
}

real_T build_robot_cbf_experiment(const emlrtStack *sp, const real_T W[51],
                                  const real_T params[30], real_T grad[51])
{
  __m128d b_r1;
  __m128d b_r2;
  __m128d b_r3;
  __m128d r;
  __m128d r4;
  __m128d r5;
  emxArray_real_T *X_hist;
  emxArray_real_T *grad_U;
  real_T dv[9];
  real_T b_Ts[6];
  real_T gP2_n[3];
  real_T grad_xs[3];
  real_T p_n[3];
  real_T x_k[3];
  real_T x_next[3];
  real_T xs[3];
  real_T b_y[2];
  real_T c_y[2];
  real_T cost_tmp[2];
  real_T g_cross_r1[2];
  real_T g_cross_r2[2];
  real_T g_cross_r3[2];
  real_T g_cross_xs[2];
  real_T grad_r1[2];
  real_T r1[2];
  real_T r2[2];
  real_T r3[2];
  real_T y[2];
  real_T L_safe;
  real_T P1_k;
  real_T P1_next;
  real_T P2_k;
  real_T P2_next;
  real_T P_cross_k;
  real_T P_cross_next;
  real_T R_safe;
  real_T Ts;
  real_T W_safe;
  real_T b_r2_tmp;
  real_T b_r3_tmp;
  real_T b_xs_tmp;
  real_T cost;
  real_T d;
  real_T d1;
  real_T dx1_k;
  real_T dx1_next;
  real_T dx2_k;
  real_T dx2_next;
  real_T dy1_k;
  real_T dy1_next;
  real_T dy2_k;
  real_T dy2_next;
  real_T eta_obs;
  real_T eta_safe;
  real_T g_circ;
  real_T g_cross;
  real_T gamma_obs;
  real_T gamma_safe;
  real_T grad_us_idx_0;
  real_T l_u;
  real_T r1_tmp;
  real_T r2_tmp;
  real_T r3_tmp;
  real_T v_circ_k;
  real_T v_circ_k_tmp = 0.0;
  real_T v_n;
  real_T v_s;
  real_T w_n;
  real_T w_s;
  real_T x_pos_k;
  real_T x_pos_next;
  real_T xs_tmp;
  real_T y_pos_k;
  real_T y_pos_next;
  real_T *X_hist_data;
  real_T *grad_U_data;
  int32_T b_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T loop_ub;
  int32_T n;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  Ts = params[15];
  x_k[0] = params[0];
  x_k[1] = params[1];
  x_k[2] = params[2];
  eta_safe = params[10];
  eta_obs = params[11];
  gamma_safe = params[12];
  gamma_obs = params[13];
  d = 2.0 * params[14];
  if (d < 1.0) {
    i = 0;
  } else {
    if (d != (int32_T)muDoubleScalarFloor(d)) {
      emlrtIntegerCheckR2012b(d, &emlrtDCI, (emlrtConstCTX)sp);
    }
    if (((int32_T)d < 1) || ((int32_T)d > 51)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, 51, &emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    i = (int32_T)d;
  }
  if (d + 1.0 != (int32_T)muDoubleScalarFloor(d + 1.0)) {
    emlrtIntegerCheckR2012b(d + 1.0, &m_emlrtDCI, (emlrtConstCTX)sp);
  }
  if (((int8_T)(d + 1.0) < 1) || ((int8_T)(d + 1.0) > 51)) {
    emlrtDynamicBoundsCheckR2012b((int8_T)(d + 1.0), 1, 51, &r_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  if ((d + 1.0) + 1.0 != (int32_T)muDoubleScalarFloor((d + 1.0) + 1.0)) {
    emlrtIntegerCheckR2012b((d + 1.0) + 1.0, &m_emlrtDCI, (emlrtConstCTX)sp);
  }
  if (((int8_T)((d + 1.0) + 1.0) < 1) || ((int8_T)((d + 1.0) + 1.0) > 51)) {
    emlrtDynamicBoundsCheckR2012b((int8_T)((d + 1.0) + 1.0), 1, 51, &r_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  if ((d + 1.0) + 2.0 != (int32_T)muDoubleScalarFloor((d + 1.0) + 2.0)) {
    emlrtIntegerCheckR2012b((d + 1.0) + 2.0, &m_emlrtDCI, (emlrtConstCTX)sp);
  }
  if (((int8_T)((d + 1.0) + 2.0) < 1) || ((int8_T)((d + 1.0) + 2.0) > 51)) {
    emlrtDynamicBoundsCheckR2012b((int8_T)((d + 1.0) + 2.0), 1, 51, &r_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  xs_tmp = W[(int8_T)(d + 1.0) - 1];
  xs[0] = xs_tmp;
  b_xs_tmp = W[(int8_T)((d + 1.0) + 1.0) - 1];
  xs[1] = b_xs_tmp;
  xs[2] = W[(int8_T)((d + 1.0) + 2.0) - 1];
  if (d + 4.0 != (int32_T)muDoubleScalarFloor(d + 4.0)) {
    emlrtIntegerCheckR2012b(d + 4.0, &l_emlrtDCI, (emlrtConstCTX)sp);
  }
  if (((int8_T)(d + 4.0) < 1) || ((int8_T)(d + 4.0) > 51)) {
    emlrtDynamicBoundsCheckR2012b((int8_T)(d + 4.0), 1, 51, &q_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  if ((d + 4.0) + 1.0 != (int32_T)muDoubleScalarFloor((d + 4.0) + 1.0)) {
    emlrtIntegerCheckR2012b((d + 4.0) + 1.0, &l_emlrtDCI, (emlrtConstCTX)sp);
  }
  if (((int8_T)((d + 4.0) + 1.0) < 1) || ((int8_T)((d + 4.0) + 1.0) > 51)) {
    emlrtDynamicBoundsCheckR2012b((int8_T)((d + 4.0) + 1.0), 1, 51, &q_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  v_s = W[(int8_T)(d + 4.0) - 1];
  w_s = W[(int8_T)((d + 4.0) + 1.0) - 1];
  /*  Definição dos índices (ponteiros) para os nós do caminho (r) */
  /*  Desempacotamento dos nós intermediários */
  if (d + 6.0 != (int32_T)muDoubleScalarFloor(d + 6.0)) {
    emlrtIntegerCheckR2012b(d + 6.0, &k_emlrtDCI, (emlrtConstCTX)sp);
  }
  if (((int8_T)(d + 6.0) < 1) || ((int8_T)(d + 6.0) > 51)) {
    emlrtDynamicBoundsCheckR2012b((int8_T)(d + 6.0), 1, 51, &p_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  if ((d + 6.0) + 1.0 != (int32_T)muDoubleScalarFloor((d + 6.0) + 1.0)) {
    emlrtIntegerCheckR2012b((d + 6.0) + 1.0, &k_emlrtDCI, (emlrtConstCTX)sp);
  }
  if (((int8_T)((d + 6.0) + 1.0) < 1) || ((int8_T)((d + 6.0) + 1.0) > 51)) {
    emlrtDynamicBoundsCheckR2012b((int8_T)((d + 6.0) + 1.0), 1, 51, &p_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  P1_k = W[(int8_T)(d + 6.0) - 1];
  r1[0] = P1_k;
  r1_tmp = W[(int8_T)((d + 6.0) + 1.0) - 1];
  r1[1] = r1_tmp;
  if (d + 8.0 != (int32_T)muDoubleScalarFloor(d + 8.0)) {
    emlrtIntegerCheckR2012b(d + 8.0, &j_emlrtDCI, (emlrtConstCTX)sp);
  }
  if (((int8_T)(d + 8.0) < 1) || ((int8_T)(d + 8.0) > 51)) {
    emlrtDynamicBoundsCheckR2012b((int8_T)(d + 8.0), 1, 51, &o_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  if ((d + 8.0) + 1.0 != (int32_T)muDoubleScalarFloor((d + 8.0) + 1.0)) {
    emlrtIntegerCheckR2012b((d + 8.0) + 1.0, &j_emlrtDCI, (emlrtConstCTX)sp);
  }
  if (((int8_T)((d + 8.0) + 1.0) < 1) || ((int8_T)((d + 8.0) + 1.0) > 51)) {
    emlrtDynamicBoundsCheckR2012b((int8_T)((d + 8.0) + 1.0), 1, 51, &o_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  r2_tmp = W[(int8_T)(d + 8.0) - 1];
  r2[0] = r2_tmp;
  b_r2_tmp = W[(int8_T)((d + 8.0) + 1.0) - 1];
  r2[1] = b_r2_tmp;
  if (d + 10.0 != (int32_T)muDoubleScalarFloor(d + 10.0)) {
    emlrtIntegerCheckR2012b(d + 10.0, &i_emlrtDCI, (emlrtConstCTX)sp);
  }
  if (((int8_T)(d + 10.0) < 1) || ((int8_T)(d + 10.0) > 51)) {
    emlrtDynamicBoundsCheckR2012b((int8_T)(d + 10.0), 1, 51, &n_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  if ((d + 10.0) + 1.0 != (int32_T)muDoubleScalarFloor((d + 10.0) + 1.0)) {
    emlrtIntegerCheckR2012b((d + 10.0) + 1.0, &i_emlrtDCI, (emlrtConstCTX)sp);
  }
  if (((int8_T)((d + 10.0) + 1.0) < 1) || ((int8_T)((d + 10.0) + 1.0) > 51)) {
    emlrtDynamicBoundsCheckR2012b((int8_T)((d + 10.0) + 1.0), 1, 51,
                                  &n_emlrtBCI, (emlrtConstCTX)sp);
  }
  r3_tmp = W[(int8_T)(d + 10.0) - 1];
  r3[0] = r3_tmp;
  b_r3_tmp = W[(int8_T)((d + 10.0) + 1.0) - 1];
  r3[1] = b_r3_tmp;
  /*  Limites Seguros */
  L_safe = params[7] - params[16];
  W_safe = params[8] - params[16];
  R_safe = params[9] + params[16];
  if (!(params[14] + 1.0 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(params[14] + 1.0, &b_emlrtDCI,
                                (emlrtConstCTX)sp);
  }
  i1 = (int32_T)muDoubleScalarFloor(params[14] + 1.0);
  if (params[14] + 1.0 != i1) {
    emlrtIntegerCheckR2012b(params[14] + 1.0, &c_emlrtDCI, (emlrtConstCTX)sp);
  }
  emxInit_real_T(sp, &X_hist, 2, &c_emlrtRTEI);
  loop_ub = X_hist->size[0] * X_hist->size[1];
  X_hist->size[0] = 3;
  X_hist->size[1] = (int32_T)(params[14] + 1.0);
  emxEnsureCapacity_real_T(sp, X_hist, loop_ub, &c_emlrtRTEI);
  X_hist_data = X_hist->data;
  loop_ub = 3 * (int32_T)(params[14] + 1.0);
  for (n = 0; n < loop_ub; n++) {
    X_hist_data[n] = 0.0;
  }
  if ((int32_T)(params[14] + 1.0) < 1) {
    emlrtDynamicBoundsCheckR2012b(1, 1, (int32_T)(params[14] + 1.0),
                                  &b_emlrtBCI, (emlrtConstCTX)sp);
  }
  X_hist_data[0] = params[0];
  X_hist_data[1] = params[1];
  X_hist_data[2] = params[2];
  l_u = 0.0;
  /*  ===================================================================== */
  /*  FORWARD PASS */
  /*  ===================================================================== */
  b_loop_ub = (int32_T)params[14];
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, params[14], mxDOUBLE_CLASS,
                                (int32_T)params[14], &emlrtRTEI,
                                (emlrtConstCTX)sp);
  for (n = 0; n < b_loop_ub; n++) {
    loop_ub = (int32_T)(((uint32_T)n << 1) + 1U);
    if ((loop_ub < 1) || (loop_ub > i)) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i, &j_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    v_n = W[loop_ub - 1];
    loop_ub = (n << 1) + 2;
    if ((loop_ub < 1) || (loop_ub > i)) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i, &k_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    w_n = W[loop_ub - 1];
    x_pos_k = x_k[0] - params[5];
    y_pos_k = x_k[1] - params[6];
    /*  --- Estado Atual (k) --- */
    /*  Cruz */
    dy2_next = muDoubleScalarAbs(x_pos_k);
    v_circ_k = muDoubleScalarMax(0.0, dy2_next - L_safe);
    P2_next = muDoubleScalarAbs(y_pos_k);
    g_circ = muDoubleScalarMax(0.0, P2_next - W_safe);
    dy1_next = muDoubleScalarMax(0.0, dy2_next - W_safe);
    P_cross_k = muDoubleScalarMax(0.0, P2_next - L_safe);
    /* P_cross_k = P1_k * P2_k; */
    /*  Círculo */
    dy2_k = R_safe * R_safe;
    P2_k =
        muDoubleScalarMax(0.0, dy2_k - (x_pos_k * x_pos_k + y_pos_k * y_pos_k));
    /*  Dinâmica */
    dy2_next = Ts * v_n;
    dx2_k = x_k[0] + dy2_next * muDoubleScalarCos(x_k[2]);
    dx1_next = x_k[1] + dy2_next * muDoubleScalarSin(x_k[2]);
    P1_next = x_k[2] + Ts * w_n;
    x_pos_next = dx2_k - params[5];
    y_pos_next = dx1_next - params[6];
    /*  --- Estado Futuro (next) --- */
    /*  Cruz */
    dy2_next = muDoubleScalarAbs(x_pos_next);
    g_cross = muDoubleScalarMax(0.0, dy2_next - L_safe);
    P2_next = muDoubleScalarAbs(y_pos_next);
    dx2_next = muDoubleScalarMax(0.0, P2_next - W_safe);
    P_cross_next = muDoubleScalarMax(0.0, dy2_next - W_safe);
    P2_next = muDoubleScalarMax(0.0, P2_next - L_safe);
    /* P_cross_next = P1_next * P2_next; */
    /*  Círculo */
    dy2_next = muDoubleScalarMax(
        0.0, dy2_k - (x_pos_next * x_pos_next + y_pos_next * y_pos_next));
    /*  --- Restrições CBF Separadas --- */
    dy2_k = muDoubleScalarMax(
        0.0,
        (1.0 - gamma_safe) * -muDoubleScalarMin(
                                 v_circ_k * v_circ_k + g_circ * g_circ,
                                 dy1_next * dy1_next + P_cross_k * P_cross_k) -
            (-muDoubleScalarMin(g_cross * g_cross + dx2_next * dx2_next,
                                P_cross_next * P_cross_next +
                                    P2_next * P2_next)));
    P_cross_next = muDoubleScalarMax(0.0, (1.0 - gamma_obs) * -(P2_k * P2_k) -
                                              (-(dy2_next * dy2_next)));
    g_cross = x_k[0] - xs_tmp;
    dx2_next = x_k[1] - b_xs_tmp;
    P2_next = v_n - v_s;
    dy2_next = w_n - w_s;
    l_u = ((l_u + ((0.8 * (g_cross * g_cross + dx2_next * dx2_next) +
                    0.5 * (P2_next * P2_next)) +
                   0.001 * (dy2_next * dy2_next))) +
           eta_safe * (dy2_k * dy2_k)) +
          eta_obs * (P_cross_next * P_cross_next);
    x_k[0] = dx2_k;
    x_k[1] = dx1_next;
    x_k[2] = P1_next;
    if (((int32_T)((uint32_T)n + 2U) < 1) ||
        ((int32_T)((uint32_T)n + 2U) > X_hist->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)n + 2U), 1,
                                    X_hist->size[1], &c_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    loop_ub = 3 * (n + 1);
    X_hist_data[loop_ub] = dx2_k;
    X_hist_data[loop_ub + 1] = dx1_next;
    X_hist_data[loop_ub + 2] = P1_next;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
  /*  ===================================================================== */
  /*  TERMINAL E BACKWARD PASS */
  /*  ===================================================================== */
  if (params[14] + 1.0 != i1) {
    emlrtIntegerCheckR2012b(params[14] + 1.0, &d_emlrtDCI, (emlrtConstCTX)sp);
  }
  i2 = X_hist->size[1];
  if (((int32_T)(params[14] + 1.0) < 1) ||
      ((int32_T)(params[14] + 1.0) > X_hist->size[1])) {
    emlrtDynamicBoundsCheckR2012b((int32_T)(params[14] + 1.0), 1,
                                  X_hist->size[1], &d_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  loop_ub = 3 * ((int32_T)(params[14] + 1.0) - 1);
  r = _mm_loadu_pd(&X_hist_data[loop_ub]);
  b_r1 = _mm_loadu_pd(&xs[0]);
  r = _mm_sub_pd(r, b_r1);
  _mm_storeu_pd(&grad_xs[0], r);
  _mm_storeu_pd(&x_k[0], _mm_mul_pd(r, r));
  P2_next = X_hist_data[loop_ub + 2] - xs[2];
  grad_xs[2] = P2_next;
  x_k[2] = P2_next * P2_next;
  /*  Custo de Equilíbrio */
  /*  Custo de obstaculo para x_s */
  dx1_k = xs_tmp - params[5];
  dy1_k = b_xs_tmp - params[6];
  dy2_next = params[9] * params[9];
  P1_next = muDoubleScalarMax(0.0, dy2_next - (dx1_k * dx1_k + dy1_k * dy1_k));
  /*  Custos de obstaculo para r1, r2 e r3 */
  P1_k -= params[5];
  w_n = r1_tmp - params[6];
  v_circ_k = muDoubleScalarMax(0.0, dy2_next - (P1_k * P1_k + w_n * w_n));
  dx2_k = r2_tmp - params[5];
  g_circ = b_r2_tmp - params[6];
  P_cross_k =
      muDoubleScalarMax(0.0, dy2_next - (dx2_k * dx2_k + g_circ * g_circ));
  dx1_next = r3_tmp - params[5];
  dy1_next = b_r3_tmp - params[6];
  dy2_k = muDoubleScalarMax(
      0.0, dy2_next - (dx1_next * dx1_next + dy1_next * dy1_next));
  /*  Custo de Offset do Caminho Mais Curto */
  /*  O alvo artificial é a âncora inicial */
  /*  O alvo real é a âncora final */
  /*  Somatória das distâncias quadráticas entre os segmentos */
  b_r1 = _mm_loadu_pd(&r1[0]);
  r = _mm_loadu_pd(&xs[0]);
  r = _mm_sub_pd(b_r1, r);
  _mm_storeu_pd(&cost_tmp[0], r);
  _mm_storeu_pd(&grad_r1[0], _mm_mul_pd(r, r));
  b_r2 = _mm_loadu_pd(&r2[0]);
  r = _mm_sub_pd(b_r2, b_r1);
  _mm_storeu_pd(&y[0], _mm_mul_pd(r, r));
  b_r1 = _mm_loadu_pd(&r3[0]);
  r = _mm_sub_pd(b_r1, b_r2);
  _mm_storeu_pd(&b_y[0], _mm_mul_pd(r, r));
  r = _mm_sub_pd(_mm_loadu_pd(&params[3]), b_r1);
  _mm_storeu_pd(&c_y[0], _mm_mul_pd(r, r));
  /*  --- NOVO: Custos da Geofence (Cruz) para os nós artificiais --- */
  P_cross_next =
      calc_cross_penalty(&xs[0], &params[5], L_safe, W_safe, g_cross_xs);
  g_cross = calc_cross_penalty(r1, &params[5], L_safe, W_safe, g_cross_r1);
  dx2_next = calc_cross_penalty(r2, &params[5], L_safe, W_safe, g_cross_r2);
  P2_k = calc_cross_penalty(r3, &params[5], L_safe, W_safe, g_cross_r3);
  P2_next = params[15] * params[15];
  cost =
      ((((((((((l_u + 1000.0 * sumColumnB(x_k)) +
               100.0 * P2_next * (v_s * v_s + w_s * w_s)) +
              50000.0 * (P1_next * P1_next)) +
             50000.0 * (v_circ_k * v_circ_k)) +
            50000.0 * (P_cross_k * P_cross_k)) +
           50000.0 * (dy2_k * dy2_k)) +
          1000.0 *
              (((b_sumColumnB(grad_r1) + b_sumColumnB(y)) + b_sumColumnB(b_y)) +
               b_sumColumnB(c_y))) +
         500.0 * P_cross_next) +
        500.0 * g_cross) +
       500.0 * dx2_next) +
      500.0 * P2_k;
  memset(&grad[0], 0, 51U * sizeof(real_T));
  emxInit_real_T(sp, &grad_U, 1, &d_emlrtRTEI);
  if (!(d >= 0.0)) {
    emlrtNonNegativeCheckR2012b(d, &h_emlrtDCI, (emlrtConstCTX)sp);
  }
  d1 = (int32_T)muDoubleScalarFloor(d);
  if (d != d1) {
    emlrtIntegerCheckR2012b(d, &g_emlrtDCI, (emlrtConstCTX)sp);
  }
  loop_ub = grad_U->size[0];
  b_loop_ub = (int32_T)d;
  grad_U->size[0] = (int32_T)d;
  emxEnsureCapacity_real_T(sp, grad_U, loop_ub, &d_emlrtRTEI);
  grad_U_data = grad_U->data;
  if (d != d1) {
    emlrtIntegerCheckR2012b(d, &g_emlrtDCI, (emlrtConstCTX)sp);
  }
  for (n = 0; n < b_loop_ub; n++) {
    grad_U_data[n] = 0.0;
  }
  r = _mm_loadu_pd(&grad_xs[0]);
  b_r3 = _mm_set1_pd(2000.0);
  r = _mm_mul_pd(b_r3, r);
  _mm_storeu_pd(&p_n[0], r);
  r4 = _mm_set1_pd(-1.0);
  _mm_storeu_pd(&grad_xs[0], _mm_mul_pd(r, r4));
  dy2_next = 2000.0 * grad_xs[2];
  p_n[2] = dy2_next;
  dy2_next = -dy2_next;
  grad_xs[2] = dy2_next;
  /*  Derivada de Vo em relacao a r1 */
  /*  Derivada de Vo em relacao a r2 */
  r = _mm_loadu_pd(&cost_tmp[0]);
  b_r1 = _mm_loadu_pd(&grad_xs[0]);
  _mm_storeu_pd(&grad_xs[0], _mm_sub_pd(b_r1, _mm_mul_pd(b_r3, r)));
  b_r1 = _mm_loadu_pd(&r1[0]);
  r = _mm_loadu_pd(&xs[0]);
  b_r2 = _mm_loadu_pd(&r2[0]);
  r5 = _mm_set1_pd(2.0);
  _mm_storeu_pd(
      &grad_r1[0],
      _mm_mul_pd(b_r3, _mm_sub_pd(_mm_sub_pd(_mm_mul_pd(r5, b_r1), r), b_r2)));
  r = _mm_loadu_pd(&r3[0]);
  _mm_storeu_pd(
      &r1[0],
      _mm_mul_pd(b_r3, _mm_sub_pd(_mm_sub_pd(_mm_mul_pd(r5, b_r2), b_r1), r)));
  _mm_storeu_pd(&r3[0],
                _mm_mul_pd(b_r3, _mm_sub_pd(_mm_sub_pd(_mm_mul_pd(r5, r), b_r2),
                                            _mm_loadu_pd(&params[3]))));
  dy2_next = 200.0 * P2_next;
  grad_us_idx_0 = dy2_next * v_s;
  l_u = dy2_next * w_s;
  if (P1_next > 0.0) {
    dy2_next = 100000.0 * P1_next;
    grad_xs[0] += dy2_next * (-2.0 * dx1_k);
    grad_xs[1] += dy2_next * (-2.0 * dy1_k);
  }
  if (v_circ_k > 0.0) {
    dy2_next = 100000.0 * v_circ_k;
    grad_r1[0] += dy2_next * (-2.0 * P1_k);
    grad_r1[1] += dy2_next * (-2.0 * w_n);
  }
  if (P_cross_k > 0.0) {
    P2_next = 100000.0 * P_cross_k;
    r1[0] += P2_next * (-2.0 * dx2_k);
    r1[1] += P2_next * (-2.0 * g_circ);
  }
  if (dy2_k > 0.0) {
    P2_next = 100000.0 * dy2_k;
    r3[0] += P2_next * (-2.0 * dx1_next);
    r3[1] += P2_next * (-2.0 * dy1_next);
  }
  /*  --- NOVO: Gradientes da Geofence (Cruz) para os nós --- */
  /*  A derivada de (mu/2)*P^2 em relação a r é: mu * P * grad_P */
  if (P_cross_next > 0.0) {
    r = _mm_loadu_pd(&g_cross_xs[0]);
    b_r1 = _mm_loadu_pd(&grad_xs[0]);
    _mm_storeu_pd(&grad_xs[0],
                  _mm_add_pd(b_r1, _mm_mul_pd(_mm_set1_pd(500.0), r)));
  }
  if (g_cross > 0.0) {
    r = _mm_loadu_pd(&g_cross_r1[0]);
    b_r1 = _mm_loadu_pd(&grad_r1[0]);
    _mm_storeu_pd(&grad_r1[0],
                  _mm_add_pd(b_r1, _mm_mul_pd(_mm_set1_pd(500.0), r)));
  }
  if (dx2_next > 0.0) {
    r = _mm_loadu_pd(&g_cross_r2[0]);
    b_r1 = _mm_loadu_pd(&r1[0]);
    _mm_storeu_pd(&r1[0], _mm_add_pd(b_r1, _mm_mul_pd(_mm_set1_pd(500.0), r)));
  }
  if (P2_k > 0.0) {
    r = _mm_loadu_pd(&g_cross_r3[0]);
    b_r1 = _mm_loadu_pd(&r3[0]);
    _mm_storeu_pd(&r3[0], _mm_add_pd(b_r1, _mm_mul_pd(_mm_set1_pd(500.0), r)));
  }
  i1 = (int32_T) - ((-1.0 - params[14]) + 1.0);
  emlrtForLoopVectorCheckR2021a(params[14], -1.0, 1.0, mxDOUBLE_CLASS,
                                (int32_T) - ((-1.0 - params[14]) + 1.0),
                                &b_emlrtRTEI, (emlrtConstCTX)sp);
  if ((int32_T) - ((-1.0 - params[14]) + 1.0) - 1 >= 0) {
    b_Ts[4] = 0.0;
    b_Ts[1] = 0.0;
    b_Ts[3] = 0.0;
    b_Ts[5] = params[15];
  }
  if (i1 - 1 >= 0) {
    v_circ_k_tmp = R_safe * R_safe;
    dv[0] = 1.0;
    dv[1] = 0.0;
    dv[3] = 0.0;
    dv[4] = 1.0;
    dv[6] = 0.0;
    dv[7] = 0.0;
    dv[8] = 1.0;
  }
  for (n = 0; n < i1; n++) {
    uint32_T u;
    uint32_T u1;
    r1_tmp = params[14] - (real_T)n;
    if (r1_tmp != (int32_T)muDoubleScalarFloor(r1_tmp)) {
      emlrtIntegerCheckR2012b(r1_tmp, &e_emlrtDCI, (emlrtConstCTX)sp);
    }
    if (((int32_T)r1_tmp < 1) || ((int32_T)r1_tmp > i2)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)r1_tmp, 1, i2, &e_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    if (((int32_T)(r1_tmp + 1.0) < 1) || ((int32_T)(r1_tmp + 1.0) > i2)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(r1_tmp + 1.0), 1, i2, &f_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    u = (uint32_T)((int32_T)r1_tmp - 1) << 1;
    if (((int32_T)(u + 1U) < 1) || ((int32_T)(u + 1U) > i)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(u + 1U), 1, i, &l_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    v_n = W[(int32_T)u];
    if (((int32_T)(u + 2U) < 1) || ((int32_T)(u + 2U) > i)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(u + 2U), 1, i, &m_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    loop_ub = 3 * ((int32_T)r1_tmp - 1);
    P2_next = X_hist_data[loop_ub];
    r2_tmp = 1.6 * (P2_next - xs_tmp);
    grad_xs[0] -= r2_tmp;
    dy2_next = X_hist_data[loop_ub + 1];
    b_r2_tmp = 1.6 * (dy2_next - b_xs_tmp);
    grad_xs[1] -= b_r2_tmp;
    r3_tmp = v_n - v_s;
    grad_us_idx_0 -= r3_tmp;
    b_r3_tmp = 0.002 * (W[(int32_T)u + 1] - w_s);
    l_u -= b_r3_tmp;
    x_pos_k = P2_next - params[5];
    y_pos_k = dy2_next - params[6];
    b_loop_ub = 3 * (int32_T)r1_tmp;
    x_pos_next = X_hist_data[b_loop_ub] - params[5];
    y_pos_next = X_hist_data[b_loop_ub + 1] - params[6];
    /*  Recalcula k */
    dy2_next = muDoubleScalarAbs(x_pos_k);
    dx1_k = muDoubleScalarMax(0.0, dy2_next - L_safe);
    P2_next = muDoubleScalarAbs(y_pos_k);
    dy1_k = muDoubleScalarMax(0.0, P2_next - W_safe);
    P1_k = dx1_k * dx1_k + dy1_k * dy1_k;
    dx2_k = muDoubleScalarMax(0.0, dy2_next - W_safe);
    dy2_k = muDoubleScalarMax(0.0, P2_next - L_safe);
    P2_k = dx2_k * dx2_k + dy2_k * dy2_k;
    v_circ_k = muDoubleScalarMax(
        0.0, v_circ_k_tmp - (x_pos_k * x_pos_k + y_pos_k * y_pos_k));
    P_cross_k = muDoubleScalarMin(P1_k, P2_k);
    /*  Recalcula next */
    dy2_next = muDoubleScalarAbs(x_pos_next);
    dx1_next = muDoubleScalarMax(0.0, dy2_next - L_safe);
    P2_next = muDoubleScalarAbs(y_pos_next);
    dy1_next = muDoubleScalarMax(0.0, P2_next - W_safe);
    P1_next = dx1_next * dx1_next + dy1_next * dy1_next;
    dx2_next = muDoubleScalarMax(0.0, dy2_next - W_safe);
    dy2_next = muDoubleScalarMax(0.0, P2_next - L_safe);
    P2_next = dx2_next * dx2_next + dy2_next * dy2_next;
    w_n = muDoubleScalarMax(0.0, v_circ_k_tmp - (x_pos_next * x_pos_next +
                                                 y_pos_next * y_pos_next));
    P_cross_next = muDoubleScalarMin(P1_next, P2_next);
    g_cross = (1.0 - gamma_safe) * -P_cross_k - (-P_cross_next);
    g_circ = (1.0 - gamma_obs) * -(v_circ_k * v_circ_k) - (-(w_n * w_n));
    xs[0] = 0.0;
    gP2_n[0] = 0.0;
    xs[1] = 0.0;
    gP2_n[1] = 0.0;
    xs[2] = 0.0;
    gP2_n[2] = 0.0;
    /*  --- Gradientes da Geofence (Cruz) --- */
    /*  if g_cross > 0 */
    /*      gP_cross_k = [0; 0; 0]; */
    /*      gP_cross_next = [0; 0; 0]; */
    /*   */
    /*      if (P1_k * P2_k > 0) || P1_k > 0 || P2_k > 0 */
    /*          gP1 = [0;0;0]; gP2 = [0;0;0]; */
    /*          if dx1_k > 0, gP1(1) = 2*dx1_k*sign(x_pos_k); end */
    /*          if dy1_k > 0, gP1(2) = 2*dy1_k*sign(y_pos_k); end */
    /*          if dx2_k > 0, gP2(1) = 2*dx2_k*sign(x_pos_k); end */
    /*          if dy2_k > 0, gP2(2) = 2*dy2_k*sign(y_pos_k); end */
    /*          gP_cross_k = (P2_k * gP1) + (P1_k * gP2); */
    /*      end */
    /*   */
    /*      if (P1_next * P2_next > 0) || P1_next > 0 || P2_next > 0 */
    /*          gP1_n = [0;0;0]; gP2_n = [0;0;0]; */
    /*          if dx1_next > 0, gP1_n(1) = 2*dx1_next*sign(x_pos_next); end */
    /*          if dy1_next > 0, gP1_n(2) = 2*dy1_next*sign(y_pos_next); end */
    /*          if dx2_next > 0, gP2_n(1) = 2*dx2_next*sign(x_pos_next); end */
    /*          if dy2_next > 0, gP2_n(2) = 2*dy2_next*sign(y_pos_next); end */
    /*          gP_cross_next = (P2_next * gP1_n) + (P1_next * gP2_n); */
    /*      end */
    /*   */
    /*      gh_k = -gP_cross_k; */
    /*      gh_next = -gP_cross_next; */
    /*   */
    /*      gg_k = (1 - gamma_safe) * gh_k; */
    /*      gg_next = -1 * gh_next; */
    /*   */
    /*      grad_x_k_cbf = grad_x_k_cbf + (2 * eta_safe * g_cross * gg_k); */
    /*      grad_x_next_cbf = grad_x_next_cbf + (2 * eta_safe * g_cross *
     * gg_next); */
    /*  end */
    if (g_cross > 0.0) {
      xs[0] = 0.0;
      gP2_n[0] = 0.0;
      xs[1] = 0.0;
      gP2_n[1] = 0.0;
      xs[2] = 0.0;
      gP2_n[2] = 0.0;
      /*  Gradiente para o estado k */
      if (P_cross_k > 0.0) {
        x_k[0] = 0.0;
        xs[0] = 0.0;
        x_k[1] = 0.0;
        xs[1] = 0.0;
        xs[2] = 0.0;
        if (dx1_k > 0.0) {
          x_k[0] = 2.0 * dx1_k * muDoubleScalarSign(x_pos_k);
        }
        if (dy1_k > 0.0) {
          x_k[1] = 2.0 * dy1_k * muDoubleScalarSign(y_pos_k);
        }
        if (dx2_k > 0.0) {
          xs[0] = 2.0 * dx2_k * muDoubleScalarSign(x_pos_k);
        }
        if (dy2_k > 0.0) {
          xs[1] = 2.0 * dy2_k * muDoubleScalarSign(y_pos_k);
        }
        /*  Direciona o gradiente para o retângulo mais próximo */
        if (P1_k <= P2_k) {
          xs[0] = x_k[0];
          xs[1] = x_k[1];
          xs[2] = 0.0;
        }
      }
      /*  Gradiente para o estado next */
      if (P_cross_next > 0.0) {
        x_k[0] = 0.0;
        gP2_n[0] = 0.0;
        x_k[1] = 0.0;
        gP2_n[1] = 0.0;
        gP2_n[2] = 0.0;
        if (dx1_next > 0.0) {
          x_k[0] = 2.0 * dx1_next * muDoubleScalarSign(x_pos_next);
        }
        if (dy1_next > 0.0) {
          x_k[1] = 2.0 * dy1_next * muDoubleScalarSign(y_pos_next);
        }
        if (dx2_next > 0.0) {
          gP2_n[0] = 2.0 * dx2_next * muDoubleScalarSign(x_pos_next);
        }
        if (dy2_next > 0.0) {
          gP2_n[1] = 2.0 * dy2_next * muDoubleScalarSign(y_pos_next);
        }
        /*  Direciona o gradiente para o retângulo mais próximo */
        if (P1_next <= P2_next) {
          gP2_n[0] = x_k[0];
          gP2_n[1] = x_k[1];
          gP2_n[2] = 0.0;
        }
      }
      dy2_next = 2.0 * eta_safe * g_cross;
      r = _mm_loadu_pd(&xs[0]);
      b_r1 = _mm_set1_pd(dy2_next);
      _mm_storeu_pd(&xs[0],
                    _mm_mul_pd(b_r1, _mm_mul_pd(_mm_set1_pd(1.0 - gamma_safe),
                                                _mm_mul_pd(r, r4))));
      r = _mm_loadu_pd(&gP2_n[0]);
      _mm_storeu_pd(&gP2_n[0], _mm_mul_pd(b_r1, r));
      xs[2] = dy2_next * ((1.0 - gamma_safe) * -xs[2]);
      gP2_n[2] *= dy2_next;
    }
    /*  --- Gradientes do Obstáculo (Círculo) --- */
    if (g_circ > 0.0) {
      x_k[0] = 0.0;
      x_next[0] = 0.0;
      x_k[1] = 0.0;
      x_next[1] = 0.0;
      x_k[2] = 0.0;
      x_next[2] = 0.0;
      if (v_circ_k > 0.0) {
        dy2_next = -4.0 * v_circ_k;
        x_k[0] = dy2_next * x_pos_k;
        x_k[1] = dy2_next * y_pos_k;
      }
      if (w_n > 0.0) {
        P2_next = -4.0 * w_n;
        x_next[0] = P2_next * x_pos_next;
        x_next[1] = P2_next * y_pos_next;
      }
      P2_next = 2.0 * eta_obs * g_circ;
      r = _mm_loadu_pd(&x_k[0]);
      b_r1 = _mm_loadu_pd(&xs[0]);
      b_r2 = _mm_set1_pd(P2_next);
      _mm_storeu_pd(
          &xs[0],
          _mm_add_pd(b_r1,
                     _mm_mul_pd(b_r2, _mm_mul_pd(_mm_set1_pd(1.0 - gamma_obs),
                                                 _mm_mul_pd(r, r4)))));
      r = _mm_loadu_pd(&x_next[0]);
      b_r1 = _mm_loadu_pd(&gP2_n[0]);
      _mm_storeu_pd(&gP2_n[0], _mm_add_pd(b_r1, _mm_mul_pd(b_r2, r)));
      xs[2] += P2_next * ((1.0 - gamma_obs) * -0.0);
      gP2_n[2] += P2_next * 0.0;
    }
    P2_next = X_hist_data[loop_ub + 2];
    dy2_next = muDoubleScalarCos(P2_next);
    P2_next = muDoubleScalarSin(P2_next);
    gP2_n[0] += p_n[0];
    gP2_n[1] += p_n[1];
    gP2_n[2] += p_n[2];
    dv[2] = -Ts * v_n * P2_next;
    dv[5] = Ts * v_n * dy2_next;
    memset(&p_n[0], 0, 3U * sizeof(real_T));
    r = _mm_loadu_pd(&dv[0]);
    b_r1 = _mm_loadu_pd(&p_n[0]);
    b_r2 = _mm_set1_pd(gP2_n[0]);
    _mm_storeu_pd(&p_n[0], _mm_add_pd(b_r1, _mm_mul_pd(r, b_r2)));
    p_n[2] += gP2_n[0] * dv[2];
    r = _mm_loadu_pd(&dv[3]);
    b_r1 = _mm_loadu_pd(&p_n[0]);
    r5 = _mm_set1_pd(gP2_n[1]);
    _mm_storeu_pd(&p_n[0], _mm_add_pd(b_r1, _mm_mul_pd(r, r5)));
    p_n[2] += gP2_n[1] * dv[5];
    r = _mm_loadu_pd(&dv[6]);
    b_r1 = _mm_loadu_pd(&p_n[0]);
    b_r3 = _mm_set1_pd(gP2_n[2]);
    _mm_storeu_pd(&p_n[0], _mm_add_pd(b_r1, _mm_mul_pd(r, b_r3)));
    p_n[2] += gP2_n[2];
    xs[0] += r2_tmp;
    xs[1] += b_r2_tmp;
    r = _mm_loadu_pd(&p_n[0]);
    b_r1 = _mm_loadu_pd(&xs[0]);
    _mm_storeu_pd(&p_n[0], _mm_add_pd(r, b_r1));
    p_n[2] += xs[2];
    u1 = (uint32_T)r1_tmp << 1;
    if (u + 1U > u1) {
      b_loop_ub = 0;
      loop_ub = 0;
    } else {
      if (((int32_T)(u + 1U) < 1) || ((int32_T)(u + 1U) > grad_U->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(u + 1U), 1, grad_U->size[0],
                                      &g_emlrtBCI, (emlrtConstCTX)sp);
      }
      b_loop_ub = (int32_T)u;
      if (((int32_T)u1 < 1) || ((int32_T)u1 > grad_U->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)u1, 1, grad_U->size[0],
                                      &h_emlrtBCI, (emlrtConstCTX)sp);
      }
      loop_ub = (int32_T)u1;
    }
    loop_ub -= b_loop_ub;
    if (loop_ub != 2) {
      emlrtSubAssignSizeCheck1dR2017a(loop_ub, 2, &emlrtECI, (emlrtConstCTX)sp);
    }
    b_Ts[0] = Ts * dy2_next;
    b_Ts[2] = Ts * P2_next;
    memset(&r2[0], 0, sizeof(real_T) << 1);
    r = _mm_loadu_pd(&b_Ts[0]);
    b_r1 = _mm_loadu_pd(&r2[0]);
    _mm_storeu_pd(&r2[0], _mm_add_pd(b_r1, _mm_mul_pd(r, b_r2)));
    r = _mm_loadu_pd(&b_Ts[2]);
    b_r1 = _mm_loadu_pd(&r2[0]);
    _mm_storeu_pd(&r2[0], _mm_add_pd(b_r1, _mm_mul_pd(r, r5)));
    r = _mm_loadu_pd(&b_Ts[4]);
    b_r1 = _mm_loadu_pd(&r2[0]);
    _mm_storeu_pd(&r2[0], _mm_add_pd(b_r1, _mm_mul_pd(r, b_r3)));
    cost_tmp[0] = r3_tmp;
    cost_tmp[1] = b_r3_tmp;
    r = _mm_loadu_pd(&r2[0]);
    b_r1 = _mm_loadu_pd(&cost_tmp[0]);
    _mm_storeu_pd(&grad_U_data[b_loop_ub], _mm_add_pd(r, b_r1));
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
  emxFree_real_T(sp, &X_hist);
  /*  Empacota o gradiente final */
  if (d < 1.0) {
    loop_ub = 0;
  } else {
    if (d != d1) {
      emlrtIntegerCheckR2012b(d, &f_emlrtDCI, (emlrtConstCTX)sp);
    }
    if (((int32_T)d < 1) || ((int32_T)d > 51)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, 51, &i_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    loop_ub = (int32_T)d;
  }
  if (loop_ub != grad_U->size[0]) {
    emlrtSubAssignSizeCheck1dR2017a(loop_ub, grad_U->size[0], &b_emlrtECI,
                                    (emlrtConstCTX)sp);
  }
  for (n = 0; n < loop_ub; n++) {
    grad[n] = grad_U_data[n];
  }
  emxFree_real_T(sp, &grad_U);
  grad[(int8_T)(d + 1.0) - 1] = grad_xs[0];
  grad[(int8_T)((d + 1.0) + 1.0) - 1] = grad_xs[1];
  grad[(int8_T)((d + 1.0) + 2.0) - 1] = grad_xs[2];
  grad[(int8_T)(d + 4.0) - 1] = grad_us_idx_0;
  grad[(int8_T)((d + 4.0) + 1.0) - 1] = l_u;
  grad[(int8_T)(d + 6.0) - 1] = grad_r1[0];
  grad[(int8_T)((d + 6.0) + 1.0) - 1] = grad_r1[1];
  grad[(int8_T)(d + 8.0) - 1] = r1[0];
  grad[(int8_T)((d + 8.0) + 1.0) - 1] = r1[1];
  grad[(int8_T)(d + 10.0) - 1] = r3[0];
  grad[(int8_T)((d + 10.0) + 1.0) - 1] = r3[1];
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
  return cost;
}

/* End of code generation (build_robot_cbf_experiment.c) */
