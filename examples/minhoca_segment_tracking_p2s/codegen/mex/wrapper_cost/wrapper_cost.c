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
    "simulator\\examples\\minhoca_segment_tracking_p2s\\wrapper_cost."
    "m" /* pathName */
};

static emlrtBCInfo emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    89,                           /* lineNo */
    21,                           /* colNo */
    "X_hist",                     /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_segment_tracking_p2s\\build_robot_c"
    "bf_experiment.m", /* pName */
    0                  /* checkKind */
};

static emlrtDCInfo emlrtDCI = {
    89,                           /* lineNo */
    21,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_segment_tracking_p2s\\build_robot_c"
    "bf_experiment.m", /* pName */
    1                  /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    81,                           /* lineNo */
    19,                           /* colNo */
    "X_hist",                     /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_segment_tracking_p2s\\build_robot_c"
    "bf_experiment.m", /* pName */
    0                  /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    37,                           /* lineNo */
    15,                           /* colNo */
    "X_hist",                     /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_segment_tracking_p2s\\build_robot_c"
    "bf_experiment.m", /* pName */
    0                  /* checkKind */
};

static emlrtRTEInfo emlrtRTEI = {
    59,                           /* lineNo */
    13,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_segment_tracking_p2s\\build_robot_c"
    "bf_experiment.m" /* pName */
};

static emlrtDCInfo b_emlrtDCI = {
    36,                           /* lineNo */
    23,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_segment_tracking_p2s\\build_robot_c"
    "bf_experiment.m", /* pName */
    1                  /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = {
    36,                           /* lineNo */
    23,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_segment_tracking_p2s\\build_robot_c"
    "bf_experiment.m", /* pName */
    4                  /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = {
    1,                            /* iFirst */
    50,                           /* iLast */
    22,                           /* lineNo */
    14,                           /* colNo */
    "W",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_segment_tracking_p2s\\build_robot_c"
    "bf_experiment.m", /* pName */
    0                  /* checkKind */
};

static emlrtDCInfo d_emlrtDCI = {
    22,                           /* lineNo */
    14,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_segment_tracking_p2s\\build_robot_c"
    "bf_experiment.m", /* pName */
    1                  /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    60,                           /* lineNo */
    17,                           /* colNo */
    "u",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_segment_tracking_p2s\\build_robot_c"
    "bf_experiment.m", /* pName */
    0                  /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    61,                           /* lineNo */
    17,                           /* colNo */
    "u",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_segment_tracking_p2s\\build_robot_c"
    "bf_experiment.m", /* pName */
    0                  /* checkKind */
};

static emlrtDCInfo e_emlrtDCI = {
    24,                           /* lineNo */
    12,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_segment_tracking_p2s\\build_robot_c"
    "bf_experiment.m", /* pName */
    1                  /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = {
    1,                            /* iFirst */
    50,                           /* iLast */
    24,                           /* lineNo */
    12,                           /* colNo */
    "W",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_segment_tracking_p2s\\build_robot_c"
    "bf_experiment.m", /* pName */
    0                  /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = {
    1,                            /* iFirst */
    50,                           /* iLast */
    34,                           /* lineNo */
    12,                           /* colNo */
    "W",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_segment_tracking_p2s\\build_robot_c"
    "bf_experiment.m", /* pName */
    0                  /* checkKind */
};

static emlrtDCInfo f_emlrtDCI = {
    34,                           /* lineNo */
    12,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_segment_tracking_p2s\\build_robot_c"
    "bf_experiment.m", /* pName */
    1                  /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = {
    1,                            /* iFirst */
    50,                           /* iLast */
    33,                           /* lineNo */
    12,                           /* colNo */
    "W",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_segment_tracking_p2s\\build_robot_c"
    "bf_experiment.m", /* pName */
    0                  /* checkKind */
};

static emlrtDCInfo g_emlrtDCI = {
    33,                           /* lineNo */
    12,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_segment_tracking_p2s\\build_robot_c"
    "bf_experiment.m", /* pName */
    1                  /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = {
    1,                            /* iFirst */
    50,                           /* iLast */
    32,                           /* lineNo */
    12,                           /* colNo */
    "W",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_segment_tracking_p2s\\build_robot_c"
    "bf_experiment.m", /* pName */
    0                  /* checkKind */
};

static emlrtDCInfo h_emlrtDCI = {
    32,                           /* lineNo */
    12,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_segment_tracking_p2s\\build_robot_c"
    "bf_experiment.m", /* pName */
    1                  /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = {
    1,                            /* iFirst */
    50,                           /* iLast */
    23,                           /* lineNo */
    12,                           /* colNo */
    "W",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_segment_tracking_p2s\\build_robot_c"
    "bf_experiment.m", /* pName */
    0                  /* checkKind */
};

static emlrtDCInfo i_emlrtDCI = {
    23,                           /* lineNo */
    12,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_segment_tracking_p2s\\build_robot_c"
    "bf_experiment.m", /* pName */
    1                  /* checkKind */
};

static emlrtRTEInfo b_emlrtRTEI = {
    36,                           /* lineNo */
    5,                            /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
    "simulator\\examples\\minhoca_segment_tracking_p2s\\build_robot_c"
    "bf_experiment.m" /* pName */
};

/* Function Definitions */
real_T wrapper_cost(const emlrtStack *sp, const real_T u[50],
                    const real_T params[36])
{
  __m128d b_r1;
  __m128d b_r2;
  __m128d r;
  emlrtStack st;
  emxArray_real_T *X_hist;
  real_T f_y[24];
  real_T g_y[24];
  real_T h_y[24];
  real_T x_k[3];
  real_T x_next[3];
  real_T a__2[2];
  real_T b_y[2];
  real_T c_y[2];
  real_T d_y[2];
  real_T e_y[2];
  real_T gP_seg0_r1[2];
  real_T r1[2];
  real_T r2[2];
  real_T r3[2];
  real_T xs[2];
  real_T y[2];
  real_T Ts;
  real_T a;
  real_T b_a;
  real_T b_xs_tmp;
  real_T c_a;
  real_T cost;
  real_T d;
  real_T l_u;
  real_T tmp2;
  real_T v1;
  real_T v2;
  real_T v3;
  real_T v4;
  real_T v_n;
  real_T v_s_tmp;
  real_T w_s;
  real_T xs_tmp;
  real_T *X_hist_data;
  int32_T i;
  int32_T i1;
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
  /*  Limites [xmin, xmax, ymin, ymax] dos 4 blocos */
  cost = 2.0 * params[7];
  if (cost < 1.0) {
    i = 0;
  } else {
    if (cost != (int32_T)muDoubleScalarFloor(cost)) {
      emlrtIntegerCheckR2012b(cost, &d_emlrtDCI, &st);
    }
    if (((int32_T)cost < 1) || ((int32_T)cost > 50)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)cost, 1, 50, &d_emlrtBCI, &st);
    }
    i = (int32_T)cost;
  }
  if (cost + 1.0 != (int32_T)muDoubleScalarFloor(cost + 1.0)) {
    emlrtIntegerCheckR2012b(cost + 1.0, &i_emlrtDCI, &st);
  }
  if (((int32_T)(cost + 1.0) < 1) || ((int32_T)(cost + 1.0) > 50)) {
    emlrtDynamicBoundsCheckR2012b((int32_T)(cost + 1.0), 1, 50, &k_emlrtBCI,
                                  &st);
  }
  xs_tmp = u[(int32_T)(cost + 1.0) - 1];
  xs[0] = xs_tmp;
  if ((cost + 1.0) + 1.0 != (int32_T)muDoubleScalarFloor((cost + 1.0) + 1.0)) {
    emlrtIntegerCheckR2012b((cost + 1.0) + 1.0, &i_emlrtDCI, &st);
  }
  if (((int32_T)((cost + 1.0) + 1.0) < 1) ||
      ((int32_T)((cost + 1.0) + 1.0) > 50)) {
    emlrtDynamicBoundsCheckR2012b((int32_T)((cost + 1.0) + 1.0), 1, 50,
                                  &k_emlrtBCI, &st);
  }
  b_xs_tmp = u[(int32_T)((cost + 1.0) + 1.0) - 1];
  xs[1] = b_xs_tmp;
  r1[0] = 0.0;
  r1[1] = 1.0;
  r = _mm_loadu_pd(&r1[0]);
  _mm_storeu_pd(&r2[0], _mm_add_pd(_mm_set1_pd(cost + 3.0), r));
  if (r2[0] != (int32_T)muDoubleScalarFloor(r2[0])) {
    emlrtIntegerCheckR2012b(r2[0], &e_emlrtDCI, &st);
  }
  if (r2[1] != (int32_T)muDoubleScalarFloor(r2[1])) {
    emlrtIntegerCheckR2012b(r2[1], &e_emlrtDCI, &st);
  }
  if (((int32_T)r2[0] < 1) || ((int32_T)r2[0] > 50)) {
    emlrtDynamicBoundsCheckR2012b((int32_T)r2[0], 1, 50, &g_emlrtBCI, &st);
  }
  if (((int32_T)r2[1] < 1) || ((int32_T)r2[1] > 50)) {
    emlrtDynamicBoundsCheckR2012b((int32_T)r2[1], 1, 50, &g_emlrtBCI, &st);
  }
  v_s_tmp = u[(int32_T)(cost + 3.0) - 1];
  w_s = u[(int32_T)((cost + 3.0) + 1.0) - 1];
  if (cost + 5.0 != (int32_T)muDoubleScalarFloor(cost + 5.0)) {
    emlrtIntegerCheckR2012b(cost + 5.0, &h_emlrtDCI, &st);
  }
  if (((int32_T)(cost + 5.0) < 1) || ((int32_T)(cost + 5.0) > 50)) {
    emlrtDynamicBoundsCheckR2012b((int32_T)(cost + 5.0), 1, 50, &j_emlrtBCI,
                                  &st);
  }
  r1[0] = u[(int32_T)(cost + 5.0) - 1];
  if ((cost + 5.0) + 1.0 != (int32_T)muDoubleScalarFloor((cost + 5.0) + 1.0)) {
    emlrtIntegerCheckR2012b((cost + 5.0) + 1.0, &h_emlrtDCI, &st);
  }
  if (((int32_T)((cost + 5.0) + 1.0) < 1) ||
      ((int32_T)((cost + 5.0) + 1.0) > 50)) {
    emlrtDynamicBoundsCheckR2012b((int32_T)((cost + 5.0) + 1.0), 1, 50,
                                  &j_emlrtBCI, &st);
  }
  r1[1] = u[(int32_T)((cost + 5.0) + 1.0) - 1];
  if (cost + 7.0 != (int32_T)muDoubleScalarFloor(cost + 7.0)) {
    emlrtIntegerCheckR2012b(cost + 7.0, &g_emlrtDCI, &st);
  }
  if (((int32_T)(cost + 7.0) < 1) || ((int32_T)(cost + 7.0) > 50)) {
    emlrtDynamicBoundsCheckR2012b((int32_T)(cost + 7.0), 1, 50, &i_emlrtBCI,
                                  &st);
  }
  r2[0] = u[(int32_T)(cost + 7.0) - 1];
  if ((cost + 7.0) + 1.0 != (int32_T)muDoubleScalarFloor((cost + 7.0) + 1.0)) {
    emlrtIntegerCheckR2012b((cost + 7.0) + 1.0, &g_emlrtDCI, &st);
  }
  if (((int32_T)((cost + 7.0) + 1.0) < 1) ||
      ((int32_T)((cost + 7.0) + 1.0) > 50)) {
    emlrtDynamicBoundsCheckR2012b((int32_T)((cost + 7.0) + 1.0), 1, 50,
                                  &i_emlrtBCI, &st);
  }
  r2[1] = u[(int32_T)((cost + 7.0) + 1.0) - 1];
  if (cost + 9.0 != (int32_T)muDoubleScalarFloor(cost + 9.0)) {
    emlrtIntegerCheckR2012b(cost + 9.0, &f_emlrtDCI, &st);
  }
  if (((int32_T)(cost + 9.0) < 1) || ((int32_T)(cost + 9.0) > 50)) {
    emlrtDynamicBoundsCheckR2012b((int32_T)(cost + 9.0), 1, 50, &h_emlrtBCI,
                                  &st);
  }
  r3[0] = u[(int32_T)(cost + 9.0) - 1];
  if ((cost + 9.0) + 1.0 != (int32_T)muDoubleScalarFloor((cost + 9.0) + 1.0)) {
    emlrtIntegerCheckR2012b((cost + 9.0) + 1.0, &f_emlrtDCI, &st);
  }
  if (((int32_T)((cost + 9.0) + 1.0) < 1) ||
      ((int32_T)((cost + 9.0) + 1.0) > 50)) {
    emlrtDynamicBoundsCheckR2012b((int32_T)((cost + 9.0) + 1.0), 1, 50,
                                  &h_emlrtBCI, &st);
  }
  r3[1] = u[(int32_T)((cost + 9.0) + 1.0) - 1];
  if (!(params[7] + 1.0 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(params[7] + 1.0, &c_emlrtDCI, &st);
  }
  d = (int32_T)muDoubleScalarFloor(params[7] + 1.0);
  if (params[7] + 1.0 != d) {
    emlrtIntegerCheckR2012b(params[7] + 1.0, &b_emlrtDCI, &st);
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
    emlrtDynamicBoundsCheckR2012b(1, 1, (int32_T)(params[7] + 1.0), &c_emlrtBCI,
                                  &st);
  }
  X_hist_data[0] = params[0];
  X_hist_data[1] = params[1];
  X_hist_data[2] = params[2];
  l_u = 0.0;
  /*  Parâmetro h para a Generalized P2S-HSD */
  /*  ===================================================================== */
  /*  ADAPTAÇÃO SUAVE DE PARÂMETROS (State-Dependent Weight) */
  /*  ===================================================================== */
  /*  =========================================================================
   */
  /*  FUNÇÃO AUXILIAR: P2S-HSD para UM Polítopo Convexo */
  /*  =========================================================================
   */
  v1 = phi_func(params[32] - params[0], &cost);
  v2 = phi_func(params[0] - params[33], &cost);
  v3 = phi_func(params[34] - params[1], &cost);
  v4 = phi_func(params[1] - params[35], &cost);
  /*  Ajuste para definir quão "firme" é a transição */
  /*  Substitui o IF/ELSE por uma transição C1 estrita */
  /*  ===================================================================== */
  /*  FORWARD PASS (Dinâmica com CBF - Ponto a Ponto Suavizado) */
  /*  ===================================================================== */
  i1 = (int32_T)params[7];
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, params[7], mxDOUBLE_CLASS,
                                (int32_T)params[7], &emlrtRTEI, &st);
  for (n = 0; n < i1; n++) {
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
    tmp2 = calc_point_p2s_penalty(&x_k[0], &params[10], a__2);
    cost = Ts * v_n;
    x_next[0] = x_k[0] + cost * muDoubleScalarCos(x_k[2]);
    x_next[1] = x_k[1] + cost * muDoubleScalarSin(x_k[2]);
    x_next[2] = x_k[2] + Ts * w_n;
    cost = calc_point_p2s_penalty(&x_next[0], &params[10], a__2);
    a = muDoubleScalarMax(0.0, (1.0 - params[6]) * -tmp2 - (-cost));
    b_a = x_k[0] - xs_tmp;
    c_a = x_k[1] - b_xs_tmp;
    tmp2 = v_n - v_s_tmp;
    cost = w_n - w_s;
    l_u = (l_u + (((b_a * b_a + c_a * c_a) + 0.5 * (tmp2 * tmp2)) +
                  0.5 * (cost * cost))) +
          params[5] * (a * a);
    x_k[0] = x_next[0];
    x_k[1] = x_next[1];
    x_k[2] = x_next[2];
    if (((int32_T)((uint32_T)n + 2U) < 1) ||
        ((int32_T)((uint32_T)n + 2U) > X_hist->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)n + 2U), 1,
                                    X_hist->size[1], &b_emlrtBCI, &st);
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
  if (params[7] + 1.0 != d) {
    emlrtIntegerCheckR2012b(params[7] + 1.0, &emlrtDCI, &st);
  }
  if (((int32_T)(params[7] + 1.0) < 1) ||
      ((int32_T)(params[7] + 1.0) > X_hist->size[1])) {
    emlrtDynamicBoundsCheckR2012b((int32_T)(params[7] + 1.0), 1,
                                  X_hist->size[1], &emlrtBCI, &st);
  }
  r = _mm_loadu_pd(&X_hist_data[3 * ((int32_T)(params[7] + 1.0) - 1)]);
  emxFree_real_T(&st, &X_hist);
  b_r1 = _mm_loadu_pd(&xs[0]);
  r = _mm_sub_pd(r, b_r1);
  _mm_storeu_pd(&y[0], _mm_mul_pd(r, r));
  b_r1 = _mm_loadu_pd(&r1[0]);
  r = _mm_loadu_pd(&xs[0]);
  r = _mm_sub_pd(b_r1, r);
  _mm_storeu_pd(&b_y[0], _mm_mul_pd(r, r));
  b_r2 = _mm_loadu_pd(&r2[0]);
  r = _mm_sub_pd(b_r2, b_r1);
  _mm_storeu_pd(&c_y[0], _mm_mul_pd(r, r));
  b_r1 = _mm_loadu_pd(&r3[0]);
  r = _mm_sub_pd(b_r1, b_r2);
  _mm_storeu_pd(&d_y[0], _mm_mul_pd(r, r));
  r = _mm_sub_pd(_mm_loadu_pd(&params[3]), b_r1);
  _mm_storeu_pd(&e_y[0], _mm_mul_pd(r, r));
  /*  ===================================================================== */
  /*  GEOFENCE DE SEGMENTOS (Contenção Convexa Suavizada) */
  /*  ===================================================================== */
  /*  Segmento 1: xs até r1 */
  a = calc_segment_p2s_penalty(xs, r1, &params[10], a__2, gP_seg0_r1);
  /*  Segmento 2: r1 até r2 */
  b_a = calc_segment_p2s_penalty(r1, r2, &params[10], a__2, gP_seg0_r1);
  /*  Segmento 3: r2 até r3 */
  c_a = calc_segment_p2s_penalty(r2, r3, &params[10], a__2, gP_seg0_r1);
  /*  Segmento 4: r3 até r4 (x_ref) */
  v_n = calc_segment_p2s_penalty(r3, &params[3], &params[10], a__2, gP_seg0_r1);
  /*  Pesos de suavização  */
  cost = u[0];
  for (n = 0; n < 24; n++) {
    tmp2 = cost;
    cost = u[(n + 1) << 1];
    f_y[n] = cost - tmp2;
  }
  for (n = 0; n <= 22; n += 2) {
    r = _mm_loadu_pd(&f_y[n]);
    _mm_storeu_pd(&g_y[n], _mm_mul_pd(r, r));
  }
  cost = u[1];
  for (n = 0; n < 24; n++) {
    tmp2 = cost;
    cost = u[((n + 1) << 1) + 1];
    f_y[n] = cost - tmp2;
  }
  for (n = 0; n <= 22; n += 2) {
    r = _mm_loadu_pd(&f_y[n]);
    _mm_storeu_pd(&h_y[n], _mm_mul_pd(r, r));
  }
  /*  Custo total */
  cost =
      (((((((l_u + params[26] * sumColumnB(y)) +
            params[27] * (params[8] * params[8]) *
                (v_s_tmp * v_s_tmp + w_s * w_s)) +
           (params[29] +
            params[30] * muDoubleScalarExp(-params[31] *
                                           (0.25 * (((v1 + v2) + v3) + v4)))) *
               (((sumColumnB(b_y) + sumColumnB(c_y)) + sumColumnB(d_y)) +
                sumColumnB(e_y))) +
          params[28] * a) +
         params[28] * b_a) +
        params[28] * c_a) +
       params[28] * v_n) +
      (0.2 * b_sumColumnB(g_y) + 0.2 * b_sumColumnB(h_y));
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
  return cost;
}

/* End of code generation (wrapper_cost.c) */
