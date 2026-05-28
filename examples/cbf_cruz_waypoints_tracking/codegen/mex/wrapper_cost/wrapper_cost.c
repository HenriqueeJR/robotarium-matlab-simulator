/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * wrapper_cost.c
 *
 * Code generation for function 'wrapper_cost'
 *
 */

/* Include files */
#include "wrapper_cost.h"
#include "build_robot_cbf_experiment.h"
#include "diff.h"
#include "rt_nonfinite.h"
#include "sumMatrixIncludeNaN.h"
#include "wrapper_cost_data.h"
#include "wrapper_cost_emxutil.h"
#include "wrapper_cost_types.h"
#include "mwmathutil.h"
#include <emmintrin.h>

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = {
    3,              /* lineNo */
    "wrapper_cost", /* fcnName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\cbf_cruz_waypoints_tracking\\wrapper_cost.m" /* pathName
                                                                        */
};

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

static emlrtBCInfo e_emlrtBCI = {
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

static emlrtBCInfo f_emlrtBCI = {
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

static emlrtDCInfo e_emlrtDCI = {
    28,                           /* lineNo */
    12,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\cbf_cruz_waypoints_tracking\\build_robot_cb"
    "f_experiment.m", /* pName */
    1                 /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = {
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

static emlrtBCInfo h_emlrtBCI = {
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

static emlrtDCInfo f_emlrtDCI = {
    40,                           /* lineNo */
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
    39,                           /* lineNo */
    12,                           /* colNo */
    "W",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\cbf_cruz_waypoints_tracking\\build_robot_cb"
    "f_experiment.m", /* pName */
    0                 /* checkKind */
};

static emlrtDCInfo g_emlrtDCI = {
    39,                           /* lineNo */
    12,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\cbf_cruz_waypoints_tracking\\build_robot_cb"
    "f_experiment.m", /* pName */
    1                 /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = {
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

static emlrtDCInfo h_emlrtDCI = {
    38,                           /* lineNo */
    12,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\cbf_cruz_waypoints_tracking\\build_robot_cb"
    "f_experiment.m", /* pName */
    1                 /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = {
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

static emlrtDCInfo i_emlrtDCI = {
    27,                           /* lineNo */
    12,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\cbf_cruz_waypoints_tracking\\build_robot_cb"
    "f_experiment.m", /* pName */
    1                 /* checkKind */
};

static emlrtRTEInfo b_emlrtRTEI = {
    47,                           /* lineNo */
    5,                            /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\cbf_cruz_waypoints_tracking\\build_robot_cb"
    "f_experiment.m" /* pName */
};

/* Function Definitions */
real_T wrapper_cost(const emlrtStack *sp, const real_T u[51],
                    const real_T params[30])
{
  __m128d b_r1;
  __m128d b_r2;
  __m128d r;
  emlrtStack st;
  emxArray_real_T *X_hist;
  real_T b_u[25];
  real_T e_y[24];
  real_T f_y[24];
  real_T h_a[24];
  real_T x_next[3];
  real_T xs[3];
  real_T b_y[2];
  real_T c_y[2];
  real_T d_y[2];
  real_T g_a[2];
  real_T r1[2];
  real_T r2[2];
  real_T r3[2];
  real_T y[2];
  real_T L_safe;
  real_T R_safe;
  real_T Ts;
  real_T W_safe;
  real_T b_r1_tmp;
  real_T b_r2_tmp;
  real_T b_r3_tmp;
  real_T b_xs_tmp;
  real_T cost;
  real_T dy1_k_tmp;
  real_T dy1_next_tmp;
  real_T e_a;
  real_T l_u;
  real_T r1_tmp;
  real_T r2_tmp;
  real_T r3_tmp;
  real_T v_s;
  real_T w_s;
  real_T x_k_idx_0;
  real_T x_k_idx_1;
  real_T x_k_idx_2;
  real_T x_pos_k;
  real_T x_pos_next;
  real_T xs_tmp;
  real_T y_pos_k;
  real_T y_pos_next;
  real_T *X_hist_data;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T loop_ub;
  int32_T n;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  st.site = &emlrtRSI;
  Ts = params[15];
  x_k_idx_0 = params[0];
  x_k_idx_1 = params[1];
  x_k_idx_2 = params[2];
  cost = 2.0 * params[14];
  if (cost < 1.0) {
    i = 0;
  } else {
    if (cost != (int32_T)muDoubleScalarFloor(cost)) {
      emlrtIntegerCheckR2012b(cost, &emlrtDCI, &st);
    }
    if (((int32_T)cost < 1) || ((int32_T)cost > 51)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)cost, 1, 51, &emlrtBCI, &st);
    }
    i = (int32_T)cost;
  }
  if (cost + 1.0 != (int32_T)muDoubleScalarFloor(cost + 1.0)) {
    emlrtIntegerCheckR2012b(cost + 1.0, &i_emlrtDCI, &st);
  }
  if (((int32_T)(cost + 1.0) < 1) || ((int32_T)(cost + 1.0) > 51)) {
    emlrtDynamicBoundsCheckR2012b((int32_T)(cost + 1.0), 1, 51, &k_emlrtBCI,
                                  &st);
  }
  xs_tmp = u[(int32_T)(cost + 1.0) - 1];
  xs[0] = xs_tmp;
  if ((cost + 1.0) + 1.0 != (int32_T)muDoubleScalarFloor((cost + 1.0) + 1.0)) {
    emlrtIntegerCheckR2012b((cost + 1.0) + 1.0, &i_emlrtDCI, &st);
  }
  if (((int32_T)((cost + 1.0) + 1.0) < 1) ||
      ((int32_T)((cost + 1.0) + 1.0) > 51)) {
    emlrtDynamicBoundsCheckR2012b((int32_T)((cost + 1.0) + 1.0), 1, 51,
                                  &k_emlrtBCI, &st);
  }
  b_xs_tmp = u[(int32_T)((cost + 1.0) + 1.0) - 1];
  xs[1] = b_xs_tmp;
  if ((cost + 1.0) + 2.0 != (int32_T)muDoubleScalarFloor((cost + 1.0) + 2.0)) {
    emlrtIntegerCheckR2012b((cost + 1.0) + 2.0, &i_emlrtDCI, &st);
  }
  if (((int32_T)((cost + 1.0) + 2.0) < 1) ||
      ((int32_T)((cost + 1.0) + 2.0) > 51)) {
    emlrtDynamicBoundsCheckR2012b((int32_T)((cost + 1.0) + 2.0), 1, 51,
                                  &k_emlrtBCI, &st);
  }
  xs[2] = u[(int32_T)((cost + 1.0) + 2.0) - 1];
  r1[0] = 0.0;
  r1[1] = 1.0;
  r = _mm_loadu_pd(&r1[0]);
  _mm_storeu_pd(&r2[0], _mm_add_pd(_mm_set1_pd(cost + 4.0), r));
  if (r2[0] != (int32_T)muDoubleScalarFloor(r2[0])) {
    emlrtIntegerCheckR2012b(r2[0], &e_emlrtDCI, &st);
  }
  if (r2[1] != (int32_T)muDoubleScalarFloor(r2[1])) {
    emlrtIntegerCheckR2012b(r2[1], &e_emlrtDCI, &st);
  }
  if (((int32_T)r2[0] < 1) || ((int32_T)r2[0] > 51)) {
    emlrtDynamicBoundsCheckR2012b((int32_T)r2[0], 1, 51, &g_emlrtBCI, &st);
  }
  if (((int32_T)r2[1] < 1) || ((int32_T)r2[1] > 51)) {
    emlrtDynamicBoundsCheckR2012b((int32_T)r2[1], 1, 51, &g_emlrtBCI, &st);
  }
  v_s = u[(int32_T)(cost + 4.0) - 1];
  w_s = u[(int32_T)((cost + 4.0) + 1.0) - 1];
  /*  Definição dos índices (ponteiros) para os nós do caminho (r) */
  /*  Desempacotamento dos nós intermediários */
  if (cost + 6.0 != (int32_T)muDoubleScalarFloor(cost + 6.0)) {
    emlrtIntegerCheckR2012b(cost + 6.0, &h_emlrtDCI, &st);
  }
  if (((int32_T)(cost + 6.0) < 1) || ((int32_T)(cost + 6.0) > 51)) {
    emlrtDynamicBoundsCheckR2012b((int32_T)(cost + 6.0), 1, 51, &j_emlrtBCI,
                                  &st);
  }
  r1_tmp = u[(int32_T)(cost + 6.0) - 1];
  r1[0] = r1_tmp;
  if ((cost + 6.0) + 1.0 != (int32_T)muDoubleScalarFloor((cost + 6.0) + 1.0)) {
    emlrtIntegerCheckR2012b((cost + 6.0) + 1.0, &h_emlrtDCI, &st);
  }
  if (((int32_T)((cost + 6.0) + 1.0) < 1) ||
      ((int32_T)((cost + 6.0) + 1.0) > 51)) {
    emlrtDynamicBoundsCheckR2012b((int32_T)((cost + 6.0) + 1.0), 1, 51,
                                  &j_emlrtBCI, &st);
  }
  b_r1_tmp = u[(int32_T)((cost + 6.0) + 1.0) - 1];
  r1[1] = b_r1_tmp;
  if (cost + 8.0 != (int32_T)muDoubleScalarFloor(cost + 8.0)) {
    emlrtIntegerCheckR2012b(cost + 8.0, &g_emlrtDCI, &st);
  }
  if (((int32_T)(cost + 8.0) < 1) || ((int32_T)(cost + 8.0) > 51)) {
    emlrtDynamicBoundsCheckR2012b((int32_T)(cost + 8.0), 1, 51, &i_emlrtBCI,
                                  &st);
  }
  r2_tmp = u[(int32_T)(cost + 8.0) - 1];
  r2[0] = r2_tmp;
  if ((cost + 8.0) + 1.0 != (int32_T)muDoubleScalarFloor((cost + 8.0) + 1.0)) {
    emlrtIntegerCheckR2012b((cost + 8.0) + 1.0, &g_emlrtDCI, &st);
  }
  if (((int32_T)((cost + 8.0) + 1.0) < 1) ||
      ((int32_T)((cost + 8.0) + 1.0) > 51)) {
    emlrtDynamicBoundsCheckR2012b((int32_T)((cost + 8.0) + 1.0), 1, 51,
                                  &i_emlrtBCI, &st);
  }
  b_r2_tmp = u[(int32_T)((cost + 8.0) + 1.0) - 1];
  r2[1] = b_r2_tmp;
  if (cost + 10.0 != (int32_T)muDoubleScalarFloor(cost + 10.0)) {
    emlrtIntegerCheckR2012b(cost + 10.0, &f_emlrtDCI, &st);
  }
  if (((int32_T)(cost + 10.0) < 1) || ((int32_T)(cost + 10.0) > 51)) {
    emlrtDynamicBoundsCheckR2012b((int32_T)(cost + 10.0), 1, 51, &h_emlrtBCI,
                                  &st);
  }
  r3_tmp = u[(int32_T)(cost + 10.0) - 1];
  r3[0] = r3_tmp;
  if ((cost + 10.0) + 1.0 !=
      (int32_T)muDoubleScalarFloor((cost + 10.0) + 1.0)) {
    emlrtIntegerCheckR2012b((cost + 10.0) + 1.0, &f_emlrtDCI, &st);
  }
  if (((int32_T)((cost + 10.0) + 1.0) < 1) ||
      ((int32_T)((cost + 10.0) + 1.0) > 51)) {
    emlrtDynamicBoundsCheckR2012b((int32_T)((cost + 10.0) + 1.0), 1, 51,
                                  &h_emlrtBCI, &st);
  }
  b_r3_tmp = u[(int32_T)((cost + 10.0) + 1.0) - 1];
  r3[1] = b_r3_tmp;
  /*  Limites Seguros */
  L_safe = params[7] - params[16];
  W_safe = params[8] - params[16];
  R_safe = params[9] + params[16];
  if (!(params[14] + 1.0 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(params[14] + 1.0, &b_emlrtDCI, &st);
  }
  i1 = (int32_T)muDoubleScalarFloor(params[14] + 1.0);
  if (params[14] + 1.0 != i1) {
    emlrtIntegerCheckR2012b(params[14] + 1.0, &c_emlrtDCI, &st);
  }
  emxInit_real_T(&st, &X_hist, &b_emlrtRTEI);
  loop_ub = X_hist->size[0] * X_hist->size[1];
  X_hist->size[0] = 3;
  X_hist->size[1] = (int32_T)(params[14] + 1.0);
  emxEnsureCapacity_real_T(&st, X_hist, loop_ub, &b_emlrtRTEI);
  X_hist_data = X_hist->data;
  loop_ub = 3 * (int32_T)(params[14] + 1.0);
  for (n = 0; n < loop_ub; n++) {
    X_hist_data[n] = 0.0;
  }
  if ((int32_T)(params[14] + 1.0) < 1) {
    emlrtDynamicBoundsCheckR2012b(1, 1, (int32_T)(params[14] + 1.0),
                                  &b_emlrtBCI, &st);
  }
  X_hist_data[0] = params[0];
  X_hist_data[1] = params[1];
  X_hist_data[2] = params[2];
  l_u = 0.0;
  /*  ===================================================================== */
  /*  FORWARD PASS */
  /*  ===================================================================== */
  i2 = (int32_T)params[14];
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, params[14], mxDOUBLE_CLASS,
                                (int32_T)params[14], &emlrtRTEI, &st);
  for (n = 0; n < i2; n++) {
    real_T a;
    real_T a_tmp;
    real_T b_a;
    real_T c_a;
    real_T d;
    real_T d1;
    real_T d_a;
    real_T f_a;
    real_T v_n;
    real_T w_n;
    loop_ub = (int32_T)(((uint32_T)n << 1) + 1U);
    if ((loop_ub < 1) || (loop_ub > i)) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i, &e_emlrtBCI, &st);
    }
    v_n = u[loop_ub - 1];
    loop_ub = (n << 1) + 2;
    if ((loop_ub < 1) || (loop_ub > i)) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i, &f_emlrtBCI, &st);
    }
    w_n = u[loop_ub - 1];
    x_pos_k = x_k_idx_0 - params[5];
    y_pos_k = x_k_idx_1 - params[6];
    /*  --- Estado Atual (k) --- */
    /*  Cruz */
    cost = muDoubleScalarAbs(x_pos_k);
    a = muDoubleScalarMax(0.0, cost - L_safe);
    dy1_k_tmp = muDoubleScalarAbs(y_pos_k);
    b_a = muDoubleScalarMax(0.0, dy1_k_tmp - W_safe);
    c_a = muDoubleScalarMax(0.0, cost - W_safe);
    d_a = muDoubleScalarMax(0.0, dy1_k_tmp - L_safe);
    /* P_cross_k = P1_k * P2_k; */
    /*  Círculo */
    a_tmp = R_safe * R_safe;
    f_a =
        muDoubleScalarMax(0.0, a_tmp - (x_pos_k * x_pos_k + y_pos_k * y_pos_k));
    /*  Dinâmica */
    cost = Ts * v_n;
    d = x_k_idx_0 + cost * muDoubleScalarCos(x_k_idx_2);
    d1 = x_k_idx_1 + cost * muDoubleScalarSin(x_k_idx_2);
    x_k_idx_2 += Ts * w_n;
    x_pos_next = d - params[5];
    y_pos_next = d1 - params[6];
    /*  --- Estado Futuro (next) --- */
    /*  Cruz */
    cost = muDoubleScalarAbs(x_pos_next);
    y_pos_k = muDoubleScalarMax(0.0, cost - L_safe);
    dy1_next_tmp = muDoubleScalarAbs(y_pos_next);
    e_a = muDoubleScalarMax(0.0, dy1_next_tmp - W_safe);
    x_pos_k = muDoubleScalarMax(0.0, cost - W_safe);
    dy1_k_tmp = muDoubleScalarMax(0.0, dy1_next_tmp - L_safe);
    /* P_cross_next = P1_next * P2_next; */
    /*  Círculo */
    cost = muDoubleScalarMax(
        0.0, a_tmp - (x_pos_next * x_pos_next + y_pos_next * y_pos_next));
    /*  --- Restrições CBF Separadas --- */
    e_a = muDoubleScalarMax(
        0.0,
        (1.0 - params[12]) *
                -muDoubleScalarMin(a * a + b_a * b_a, c_a * c_a + d_a * d_a) -
            (-muDoubleScalarMin(y_pos_k * y_pos_k + e_a * e_a,
                                x_pos_k * x_pos_k + dy1_k_tmp * dy1_k_tmp)));
    y_pos_next = muDoubleScalarMax(0.0, (1.0 - params[13]) * -(f_a * f_a) -
                                            (-(cost * cost)));
    x_pos_next = x_k_idx_0 - xs_tmp;
    dy1_next_tmp = x_k_idx_1 - b_xs_tmp;
    y_pos_k = v_n - v_s;
    cost = w_n - w_s;
    l_u = ((l_u +
            ((0.8 * (x_pos_next * x_pos_next + dy1_next_tmp * dy1_next_tmp) +
              0.5 * (y_pos_k * y_pos_k)) +
             0.001 * (cost * cost))) +
           params[10] * (e_a * e_a)) +
          params[11] * (y_pos_next * y_pos_next);
    x_k_idx_0 = d;
    x_k_idx_1 = d1;
    if (((int32_T)((uint32_T)n + 2U) < 1) ||
        ((int32_T)((uint32_T)n + 2U) > X_hist->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)n + 2U), 1,
                                    X_hist->size[1], &c_emlrtBCI, &st);
    }
    loop_ub = 3 * (n + 1);
    X_hist_data[loop_ub] = d;
    X_hist_data[loop_ub + 1] = d1;
    X_hist_data[loop_ub + 2] = x_k_idx_2;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }
  /*  ===================================================================== */
  /*  TERMINAL E BACKWARD PASS */
  /*  ===================================================================== */
  if (params[14] + 1.0 != i1) {
    emlrtIntegerCheckR2012b(params[14] + 1.0, &d_emlrtDCI, &st);
  }
  if (((int32_T)(params[14] + 1.0) < 1) ||
      ((int32_T)(params[14] + 1.0) > X_hist->size[1])) {
    emlrtDynamicBoundsCheckR2012b((int32_T)(params[14] + 1.0), 1,
                                  X_hist->size[1], &d_emlrtBCI, &st);
  }
  loop_ub = 3 * ((int32_T)(params[14] + 1.0) - 1);
  r = _mm_loadu_pd(&X_hist_data[loop_ub]);
  b_r1 = _mm_loadu_pd(&xs[0]);
  r = _mm_sub_pd(r, b_r1);
  _mm_storeu_pd(&x_next[0], _mm_mul_pd(r, r));
  cost = X_hist_data[loop_ub + 2] - xs[2];
  emxFree_real_T(&st, &X_hist);
  x_next[2] = cost * cost;
  /*  Custo de Equilíbrio */
  /*  Custo de obstaculo para x_s */
  dy1_k_tmp = xs_tmp - params[5];
  cost = b_xs_tmp - params[6];
  x_pos_k = params[9] * params[9];
  e_a = muDoubleScalarMax(0.0, x_pos_k - (dy1_k_tmp * dy1_k_tmp + cost * cost));
  /*  Custos de obstaculo para r1, r2 e r3 */
  dy1_next_tmp = r1_tmp - params[5];
  cost = b_r1_tmp - params[6];
  y_pos_next = muDoubleScalarMax(
      0.0, x_pos_k - (dy1_next_tmp * dy1_next_tmp + cost * cost));
  dy1_next_tmp = r2_tmp - params[5];
  cost = b_r2_tmp - params[6];
  x_pos_next = muDoubleScalarMax(
      0.0, x_pos_k - (dy1_next_tmp * dy1_next_tmp + cost * cost));
  dy1_next_tmp = r3_tmp - params[5];
  cost = b_r3_tmp - params[6];
  dy1_next_tmp = muDoubleScalarMax(
      0.0, x_pos_k - (dy1_next_tmp * dy1_next_tmp + cost * cost));
  /*  Custo de Offset do Caminho Mais Curto */
  /*  O alvo artificial é a âncora inicial */
  /*  O alvo real é a âncora final */
  /*  Somatória das distâncias quadráticas entre os segmentos */
  b_r1 = _mm_loadu_pd(&r1[0]);
  r = _mm_loadu_pd(&xs[0]);
  r = _mm_sub_pd(b_r1, r);
  _mm_storeu_pd(&y[0], _mm_mul_pd(r, r));
  b_r2 = _mm_loadu_pd(&r2[0]);
  r = _mm_sub_pd(b_r2, b_r1);
  _mm_storeu_pd(&b_y[0], _mm_mul_pd(r, r));
  b_r1 = _mm_loadu_pd(&r3[0]);
  r = _mm_sub_pd(b_r1, b_r2);
  _mm_storeu_pd(&c_y[0], _mm_mul_pd(r, r));
  r = _mm_sub_pd(_mm_loadu_pd(&params[3]), b_r1);
  _mm_storeu_pd(&d_y[0], _mm_mul_pd(r, r));
  /*  --- NOVO: Custos da Geofence (Cruz) para os nós artificiais --- */
  dy1_k_tmp = calc_cross_penalty(&xs[0], &params[5], L_safe, W_safe, g_a);
  x_pos_k = calc_cross_penalty(r1, &params[5], L_safe, W_safe, g_a);
  y_pos_k = calc_cross_penalty(r2, &params[5], L_safe, W_safe, g_a);
  cost = calc_cross_penalty(r3, &params[5], L_safe, W_safe, g_a);
  /*  Pesos de suavização  */
  for (n = 0; n < 25; n++) {
    b_u[n] = u[n << 1];
  }
  diff(b_u, h_a);
  for (n = 0; n <= 22; n += 2) {
    r = _mm_loadu_pd(&h_a[n]);
    _mm_storeu_pd(&e_y[n], _mm_mul_pd(r, r));
  }
  for (n = 0; n < 25; n++) {
    b_u[n] = u[(n << 1) + 1];
  }
  diff(b_u, h_a);
  for (n = 0; n <= 22; n += 2) {
    r = _mm_loadu_pd(&h_a[n]);
    _mm_storeu_pd(&f_y[n], _mm_mul_pd(r, r));
  }
  /*  Custo total */
  cost =
      (((((((((((l_u + 1000.0 * sumColumnB(x_next)) +
                100.0 * (params[15] * params[15]) * (v_s * v_s + w_s * w_s)) +
               50000.0 * (e_a * e_a)) +
              50000.0 * (y_pos_next * y_pos_next)) +
             50000.0 * (x_pos_next * x_pos_next)) +
            50000.0 * (dy1_next_tmp * dy1_next_tmp)) +
           1000.0 *
               (((b_sumColumnB(y) + b_sumColumnB(b_y)) + b_sumColumnB(c_y)) +
                b_sumColumnB(d_y))) +
          500.0 * dy1_k_tmp) +
         500.0 * x_pos_k) +
        500.0 * y_pos_k) +
       500.0 * cost) +
      (0.2 * c_sumColumnB(e_y) + 0.2 * c_sumColumnB(f_y));
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
  return cost;
}

/* End of code generation (wrapper_cost.c) */
