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
    "simulator\\examples\\minhoca_tracking\\wrapper_cost.m" /* pathName */
};

static emlrtDCInfo emlrtDCI = {
    22,                           /* lineNo */
    14,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_tracking\\build_robot_cbf_experimen"
    "t.m", /* pName */
    1      /* checkKind */
};

static emlrtBCInfo emlrtBCI = {
    1,                            /* iFirst */
    51,                           /* iLast */
    22,                           /* lineNo */
    14,                           /* colNo */
    "W",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_tracking\\build_robot_cbf_experimen"
    "t.m", /* pName */
    0      /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = {
    36,                           /* lineNo */
    23,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_tracking\\build_robot_cbf_experimen"
    "t.m", /* pName */
    4      /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = {
    36,                           /* lineNo */
    23,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_tracking\\build_robot_cbf_experimen"
    "t.m", /* pName */
    1      /* checkKind */
};

static emlrtRTEInfo emlrtRTEI = {
    43,                           /* lineNo */
    13,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_tracking\\build_robot_cbf_experimen"
    "t.m" /* pName */
};

static emlrtBCInfo b_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    37,                           /* lineNo */
    15,                           /* colNo */
    "X_hist",                     /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_tracking\\build_robot_cbf_experimen"
    "t.m", /* pName */
    0      /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    71,                           /* lineNo */
    19,                           /* colNo */
    "X_hist",                     /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_tracking\\build_robot_cbf_experimen"
    "t.m", /* pName */
    0      /* checkKind */
};

static emlrtDCInfo d_emlrtDCI = {
    79,                           /* lineNo */
    21,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_tracking\\build_robot_cbf_experimen"
    "t.m", /* pName */
    1      /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    79,                           /* lineNo */
    21,                           /* colNo */
    "X_hist",                     /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_tracking\\build_robot_cbf_experimen"
    "t.m", /* pName */
    0      /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    44,                           /* lineNo */
    17,                           /* colNo */
    "u",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_tracking\\build_robot_cbf_experimen"
    "t.m", /* pName */
    0      /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    45,                           /* lineNo */
    17,                           /* colNo */
    "u",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_tracking\\build_robot_cbf_experimen"
    "t.m", /* pName */
    0      /* checkKind */
};

static emlrtDCInfo e_emlrtDCI = {
    24,                           /* lineNo */
    12,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_tracking\\build_robot_cbf_experimen"
    "t.m", /* pName */
    1      /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = {
    1,                            /* iFirst */
    51,                           /* iLast */
    24,                           /* lineNo */
    12,                           /* colNo */
    "W",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_tracking\\build_robot_cbf_experimen"
    "t.m", /* pName */
    0      /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = {
    1,                            /* iFirst */
    51,                           /* iLast */
    34,                           /* lineNo */
    12,                           /* colNo */
    "W",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_tracking\\build_robot_cbf_experimen"
    "t.m", /* pName */
    0      /* checkKind */
};

static emlrtDCInfo f_emlrtDCI = {
    34,                           /* lineNo */
    12,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_tracking\\build_robot_cbf_experimen"
    "t.m", /* pName */
    1      /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = {
    1,                            /* iFirst */
    51,                           /* iLast */
    33,                           /* lineNo */
    12,                           /* colNo */
    "W",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_tracking\\build_robot_cbf_experimen"
    "t.m", /* pName */
    0      /* checkKind */
};

static emlrtDCInfo g_emlrtDCI = {
    33,                           /* lineNo */
    12,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_tracking\\build_robot_cbf_experimen"
    "t.m", /* pName */
    1      /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = {
    1,                            /* iFirst */
    51,                           /* iLast */
    32,                           /* lineNo */
    12,                           /* colNo */
    "W",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_tracking\\build_robot_cbf_experimen"
    "t.m", /* pName */
    0      /* checkKind */
};

static emlrtDCInfo h_emlrtDCI = {
    32,                           /* lineNo */
    12,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_tracking\\build_robot_cbf_experimen"
    "t.m", /* pName */
    1      /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = {
    1,                            /* iFirst */
    51,                           /* iLast */
    23,                           /* lineNo */
    12,                           /* colNo */
    "W",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_tracking\\build_robot_cbf_experimen"
    "t.m", /* pName */
    0      /* checkKind */
};

static emlrtDCInfo i_emlrtDCI = {
    23,                           /* lineNo */
    12,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_tracking\\build_robot_cbf_experimen"
    "t.m", /* pName */
    1      /* checkKind */
};

static emlrtRTEInfo b_emlrtRTEI = {
    36,                           /* lineNo */
    5,                            /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_tracking\\build_robot_cbf_experimen"
    "t.m" /* pName */
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
  real_T i_y[24];
  real_T j_y[24];
  real_T k_y[24];
  real_T x_k[3];
  real_T x_next[3];
  real_T xs[3];
  real_T a[2];
  real_T e_y[2];
  real_T f_y[2];
  real_T g_y[2];
  real_T h_y[2];
  real_T r1[2];
  real_T r2[2];
  real_T r3[2];
  real_T y[2];
  real_T Ts;
  real_T b_xs_tmp;
  real_T b_y;
  real_T c_x;
  real_T c_y;
  real_T cost;
  real_T d_y;
  real_T l_u;
  real_T tmp2;
  real_T v_s_tmp;
  real_T w_s;
  real_T x;
  real_T xs_tmp;
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
  /*  Desempacotamento limpo do vetor params (Tamanho: 30) */
  x_k[0] = params[0];
  x_k[1] = params[1];
  x_k[2] = params[2];
  Ts = params[8];
  /*  params(10) era o r_rob. Não subtraímos mais aqui para não inverter os
   * blocos.      */
  /*  Limites [xmin, xmax, ymin, ymax] dos 4 blocos */
  cost = 2.0 * params[7];
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
  v_s_tmp = u[(int32_T)(cost + 4.0) - 1];
  w_s = u[(int32_T)((cost + 4.0) + 1.0) - 1];
  if (cost + 6.0 != (int32_T)muDoubleScalarFloor(cost + 6.0)) {
    emlrtIntegerCheckR2012b(cost + 6.0, &h_emlrtDCI, &st);
  }
  if (((int32_T)(cost + 6.0) < 1) || ((int32_T)(cost + 6.0) > 51)) {
    emlrtDynamicBoundsCheckR2012b((int32_T)(cost + 6.0), 1, 51, &j_emlrtBCI,
                                  &st);
  }
  r1[0] = u[(int32_T)(cost + 6.0) - 1];
  if ((cost + 6.0) + 1.0 != (int32_T)muDoubleScalarFloor((cost + 6.0) + 1.0)) {
    emlrtIntegerCheckR2012b((cost + 6.0) + 1.0, &h_emlrtDCI, &st);
  }
  if (((int32_T)((cost + 6.0) + 1.0) < 1) ||
      ((int32_T)((cost + 6.0) + 1.0) > 51)) {
    emlrtDynamicBoundsCheckR2012b((int32_T)((cost + 6.0) + 1.0), 1, 51,
                                  &j_emlrtBCI, &st);
  }
  r1[1] = u[(int32_T)((cost + 6.0) + 1.0) - 1];
  if (cost + 8.0 != (int32_T)muDoubleScalarFloor(cost + 8.0)) {
    emlrtIntegerCheckR2012b(cost + 8.0, &g_emlrtDCI, &st);
  }
  if (((int32_T)(cost + 8.0) < 1) || ((int32_T)(cost + 8.0) > 51)) {
    emlrtDynamicBoundsCheckR2012b((int32_T)(cost + 8.0), 1, 51, &i_emlrtBCI,
                                  &st);
  }
  r2[0] = u[(int32_T)(cost + 8.0) - 1];
  if ((cost + 8.0) + 1.0 != (int32_T)muDoubleScalarFloor((cost + 8.0) + 1.0)) {
    emlrtIntegerCheckR2012b((cost + 8.0) + 1.0, &g_emlrtDCI, &st);
  }
  if (((int32_T)((cost + 8.0) + 1.0) < 1) ||
      ((int32_T)((cost + 8.0) + 1.0) > 51)) {
    emlrtDynamicBoundsCheckR2012b((int32_T)((cost + 8.0) + 1.0), 1, 51,
                                  &i_emlrtBCI, &st);
  }
  r2[1] = u[(int32_T)((cost + 8.0) + 1.0) - 1];
  if (cost + 10.0 != (int32_T)muDoubleScalarFloor(cost + 10.0)) {
    emlrtIntegerCheckR2012b(cost + 10.0, &f_emlrtDCI, &st);
  }
  if (((int32_T)(cost + 10.0) < 1) || ((int32_T)(cost + 10.0) > 51)) {
    emlrtDynamicBoundsCheckR2012b((int32_T)(cost + 10.0), 1, 51, &h_emlrtBCI,
                                  &st);
  }
  r3[0] = u[(int32_T)(cost + 10.0) - 1];
  if ((cost + 10.0) + 1.0 !=
      (int32_T)muDoubleScalarFloor((cost + 10.0) + 1.0)) {
    emlrtIntegerCheckR2012b((cost + 10.0) + 1.0, &f_emlrtDCI, &st);
  }
  if (((int32_T)((cost + 10.0) + 1.0) < 1) ||
      ((int32_T)((cost + 10.0) + 1.0) > 51)) {
    emlrtDynamicBoundsCheckR2012b((int32_T)((cost + 10.0) + 1.0), 1, 51,
                                  &h_emlrtBCI, &st);
  }
  r3[1] = u[(int32_T)((cost + 10.0) + 1.0) - 1];
  if (!(params[7] + 1.0 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(params[7] + 1.0, &b_emlrtDCI, &st);
  }
  i1 = (int32_T)muDoubleScalarFloor(params[7] + 1.0);
  if (params[7] + 1.0 != i1) {
    emlrtIntegerCheckR2012b(params[7] + 1.0, &c_emlrtDCI, &st);
  }
  emxInit_real_T(&st, &X_hist, &b_emlrtRTEI);
  loop_ub = X_hist->size[0] * X_hist->size[1];
  X_hist->size[0] = 3;
  X_hist->size[1] = (int32_T)(params[7] + 1.0);
  emxEnsureCapacity_real_T(&st, X_hist, loop_ub, &b_emlrtRTEI);
  X_hist_data = X_hist->data;
  loop_ub = 3 * (int32_T)(params[7] + 1.0);
  for (n = 0; n < loop_ub; n++) {
    X_hist_data[n] = 0.0;
  }
  if ((int32_T)(params[7] + 1.0) < 1) {
    emlrtDynamicBoundsCheckR2012b(1, 1, (int32_T)(params[7] + 1.0), &b_emlrtBCI,
                                  &st);
  }
  X_hist_data[0] = params[0];
  X_hist_data[1] = params[1];
  X_hist_data[2] = params[2];
  l_u = 0.0;
  /*  ===================================================================== */
  /*  FORWARD PASS */
  /*  ===================================================================== */
  i2 = (int32_T)params[7];
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, params[7], mxDOUBLE_CLASS,
                                (int32_T)params[7], &emlrtRTEI, &st);
  for (n = 0; n < i2; n++) {
    real_T b_x;
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
    /*  --- Estado Atual (k) --- Usa o Mínimo Exato para CBF */
    b_x = get_blocks_P(&x_k[0], &params[10], &b_y, &x, &c_y);
    /*  Dinâmica */
    cost = Ts * v_n;
    x_next[0] = x_k[0] + cost * muDoubleScalarCos(x_k[2]);
    x_next[1] = x_k[1] + cost * muDoubleScalarSin(x_k[2]);
    x_next[2] = x_k[2] + Ts * w_n;
    /*  --- Estado Futuro (next) --- */
    c_x = get_blocks_P(&x_next[0], &params[10], &cost, &tmp2, &d_y);
    /*  --- Restrição CBF --- */
    c_x = muDoubleScalarMax(
        0.0, (1.0 - params[6]) * -muDoubleScalarMin(muDoubleScalarMin(b_x, b_y),
                                                    muDoubleScalarMin(x, c_y)) -
                 (-muDoubleScalarMin(muDoubleScalarMin(c_x, cost),
                                     muDoubleScalarMin(tmp2, d_y))));
    b_y = x_k[0] - xs_tmp;
    x = x_k[1] - b_xs_tmp;
    tmp2 = v_n - v_s_tmp;
    cost = w_n - w_s;
    l_u = (l_u + ((5.0 * (b_y * b_y + x * x) + 0.5 * (tmp2 * tmp2)) +
                  1.5 * (cost * cost))) +
          params[5] * (c_x * c_x);
    x_k[0] = x_next[0];
    x_k[1] = x_next[1];
    x_k[2] = x_next[2];
    if (((int32_T)((uint32_T)n + 2U) < 1) ||
        ((int32_T)((uint32_T)n + 2U) > X_hist->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)n + 2U), 1,
                                    X_hist->size[1], &c_emlrtBCI, &st);
    }
    loop_ub = 3 * (n + 1);
    X_hist_data[loop_ub] = x_next[0];
    X_hist_data[loop_ub + 1] = x_next[1];
    X_hist_data[loop_ub + 2] = x_next[2];
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }
  /*  ===================================================================== */
  /*  TERMINAL E BACKWARD PASS */
  /*  ===================================================================== */
  if (params[7] + 1.0 != i1) {
    emlrtIntegerCheckR2012b(params[7] + 1.0, &d_emlrtDCI, &st);
  }
  if (((int32_T)(params[7] + 1.0) < 1) ||
      ((int32_T)(params[7] + 1.0) > X_hist->size[1])) {
    emlrtDynamicBoundsCheckR2012b((int32_T)(params[7] + 1.0), 1,
                                  X_hist->size[1], &d_emlrtBCI, &st);
  }
  r = _mm_loadu_pd(&X_hist_data[3 * ((int32_T)(params[7] + 1.0) - 1)]);
  emxFree_real_T(&st, &X_hist);
  b_r1 = _mm_loadu_pd(&xs[0]);
  r = _mm_sub_pd(r, b_r1);
  _mm_storeu_pd(&y[0], _mm_mul_pd(r, r));
  b_r1 = _mm_loadu_pd(&r1[0]);
  r = _mm_loadu_pd(&xs[0]);
  r = _mm_sub_pd(b_r1, r);
  _mm_storeu_pd(&e_y[0], _mm_mul_pd(r, r));
  b_r2 = _mm_loadu_pd(&r2[0]);
  r = _mm_sub_pd(b_r2, b_r1);
  _mm_storeu_pd(&f_y[0], _mm_mul_pd(r, r));
  b_r1 = _mm_loadu_pd(&r3[0]);
  r = _mm_sub_pd(b_r1, b_r2);
  _mm_storeu_pd(&g_y[0], _mm_mul_pd(r, r));
  r = _mm_sub_pd(_mm_loadu_pd(&params[3]), b_r1);
  _mm_storeu_pd(&h_y[0], _mm_mul_pd(r, r));
  /*  Custos da Geofence para nós terminais (AQUI USA O SMOOTH MIN) */
  c_x = calc_corridor_penalty(&xs[0], &params[10], a);
  b_y = calc_corridor_penalty(r1, &params[10], a);
  x = calc_corridor_penalty(r2, &params[10], a);
  d_y = calc_corridor_penalty(r3, &params[10], a);
  /*  Pesos de suavização  */
  cost = u[0];
  for (n = 0; n < 24; n++) {
    tmp2 = cost;
    cost = u[(n + 1) << 1];
    i_y[n] = cost - tmp2;
  }
  for (n = 0; n <= 22; n += 2) {
    r = _mm_loadu_pd(&i_y[n]);
    _mm_storeu_pd(&j_y[n], _mm_mul_pd(r, r));
  }
  cost = u[1];
  for (n = 0; n < 24; n++) {
    tmp2 = cost;
    cost = u[((n + 1) << 1) + 1];
    i_y[n] = cost - tmp2;
  }
  for (n = 0; n <= 22; n += 2) {
    r = _mm_loadu_pd(&i_y[n]);
    _mm_storeu_pd(&k_y[n], _mm_mul_pd(r, r));
  }
  /*  Custo total */
  cost = params[28] / 2.0;
  cost = (((((((l_u + params[26] * sumColumnB(y)) +
               params[27] * (params[8] * params[8]) *
                   (v_s_tmp * v_s_tmp + w_s * w_s)) +
              params[29] *
                  (((sumColumnB(e_y) + sumColumnB(f_y)) + sumColumnB(g_y)) +
                   sumColumnB(h_y))) +
             cost * c_x) +
            cost * b_y) +
           cost * x) +
          cost * d_y) +
         (0.2 * b_sumColumnB(j_y) + 0.2 * b_sumColumnB(k_y));
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
  return cost;
}

/* End of code generation (wrapper_cost.c) */
