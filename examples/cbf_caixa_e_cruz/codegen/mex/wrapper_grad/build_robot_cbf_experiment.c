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
#include "wrapper_grad_data.h"
#include "wrapper_grad_emxutil.h"
#include "wrapper_grad_types.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <string.h>

/* Variable Definitions */
static emlrtDCInfo emlrtDCI = {
    30,                           /* lineNo */
    23,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws\\robotarium-matlab-"
    "simulator\\examples\\cbf_caixa\\build_robot_cbf_experiment.m", /* pName */
    4 /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = {
    30,                           /* lineNo */
    23,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws\\robotarium-matlab-"
    "simulator\\examples\\cbf_caixa\\build_robot_cbf_experiment.m", /* pName */
    1 /* checkKind */
};

static emlrtRTEInfo emlrtRTEI = {
    37,                           /* lineNo */
    13,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws\\robotarium-matlab-"
    "simulator\\examples\\cbf_caixa\\build_robot_cbf_experiment.m" /* pName */
};

static emlrtBCInfo emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    31,                           /* lineNo */
    15,                           /* colNo */
    "X_hist",                     /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws\\robotarium-matlab-"
    "simulator\\examples\\cbf_caixa\\build_robot_cbf_experiment.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    95,                           /* lineNo */
    19,                           /* colNo */
    "X_hist",                     /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws\\robotarium-matlab-"
    "simulator\\examples\\cbf_caixa\\build_robot_cbf_experiment.m", /* pName */
    0 /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = {
    103,                          /* lineNo */
    21,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws\\robotarium-matlab-"
    "simulator\\examples\\cbf_caixa\\build_robot_cbf_experiment.m", /* pName */
    1 /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    103,                          /* lineNo */
    21,                           /* colNo */
    "X_hist",                     /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws\\robotarium-matlab-"
    "simulator\\examples\\cbf_caixa\\build_robot_cbf_experiment.m", /* pName */
    0 /* checkKind */
};

static emlrtRTEInfo b_emlrtRTEI = {
    112,                          /* lineNo */
    13,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws\\robotarium-matlab-"
    "simulator\\examples\\cbf_caixa\\build_robot_cbf_experiment.m" /* pName */
};

static emlrtDCInfo d_emlrtDCI = {
    113,                          /* lineNo */
    25,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws\\robotarium-matlab-"
    "simulator\\examples\\cbf_caixa\\build_robot_cbf_experiment.m", /* pName */
    1 /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    113,                          /* lineNo */
    25,                           /* colNo */
    "X_hist",                     /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws\\robotarium-matlab-"
    "simulator\\examples\\cbf_caixa\\build_robot_cbf_experiment.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    114,                          /* lineNo */
    28,                           /* colNo */
    "X_hist",                     /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws\\robotarium-matlab-"
    "simulator\\examples\\cbf_caixa\\build_robot_cbf_experiment.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = {
    1,                            /* iFirst */
    40,                           /* iLast */
    210,                          /* lineNo */
    14,                           /* colNo */
    "grad",                       /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws\\robotarium-matlab-"
    "simulator\\examples\\cbf_caixa\\build_robot_cbf_experiment.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = {
    1,                            /* iFirst */
    40,                           /* iLast */
    210,                          /* lineNo */
    28,                           /* colNo */
    "grad",                       /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws\\robotarium-matlab-"
    "simulator\\examples\\cbf_caixa\\build_robot_cbf_experiment.m", /* pName */
    0 /* checkKind */
};

static emlrtECInfo emlrtECI = {
    -1,                           /* nDims */
    210,                          /* lineNo */
    9,                            /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws\\robotarium-matlab-"
    "simulator\\examples\\cbf_caixa\\build_robot_cbf_experiment.m" /* pName */
};

static emlrtBCInfo h_emlrtBCI = {
    1,                            /* iFirst */
    40,                           /* iLast */
    38,                           /* lineNo */
    17,                           /* colNo */
    "u",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws\\robotarium-matlab-"
    "simulator\\examples\\cbf_caixa\\build_robot_cbf_experiment.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = {
    1,                            /* iFirst */
    40,                           /* iLast */
    39,                           /* lineNo */
    17,                           /* colNo */
    "u",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws\\robotarium-matlab-"
    "simulator\\examples\\cbf_caixa\\build_robot_cbf_experiment.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = {
    1,                            /* iFirst */
    40,                           /* iLast */
    115,                          /* lineNo */
    17,                           /* colNo */
    "u",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws\\robotarium-matlab-"
    "simulator\\examples\\cbf_caixa\\build_robot_cbf_experiment.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = {
    1,                            /* iFirst */
    40,                           /* iLast */
    115,                          /* lineNo */
    39,                           /* colNo */
    "u",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws\\robotarium-matlab-"
    "simulator\\examples\\cbf_caixa\\build_robot_cbf_experiment.m", /* pName */
    0 /* checkKind */
};

static emlrtRTEInfo c_emlrtRTEI = {
    30,                           /* lineNo */
    5,                            /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws\\robotarium-matlab-"
    "simulator\\examples\\cbf_caixa\\build_robot_cbf_experiment.m" /* pName */
};

/* Function Definitions */
real_T build_robot_cbf_experiment(const emlrtStack *sp, const real_T u[40],
                                  const real_T params[17], real_T grad[40])
{
  emxArray_real_T *X_hist;
  real_T dv[9];
  real_T b_Ts[6];
  real_T gP1[3];
  real_T gP1_n[3];
  real_T p_n[3];
  real_T x_k[3];
  real_T x_next[3];
  real_T b_v_n[2];
  real_T c_Ts[2];
  real_T L_safe;
  real_T P1_next;
  real_T P2_k;
  real_T P2_next;
  real_T R_safe;
  real_T Ts;
  real_T W_safe;
  real_T a;
  real_T b_a;
  real_T cost;
  real_T dx1_next;
  real_T dx2_k;
  real_T dx2_next;
  real_T dy1_next;
  real_T dy2_k;
  real_T dy2_next;
  real_T eta_obs;
  real_T eta_safe;
  real_T g_cross;
  real_T gamma_obs;
  real_T gamma_safe;
  real_T l_u;
  real_T v_circ_k;
  real_T v_circ_k_tmp = 0.0;
  real_T v_circ_next;
  real_T v_n;
  real_T w_n;
  real_T x_pos_k;
  real_T x_pos_next;
  real_T y_pos_k;
  real_T y_pos_next;
  real_T *X_hist_data;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  int32_T n;
  int32_T x_pos_next_tmp;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  /*  =========================================================================
   */
  /*  Algoritmo: Backward AD - Geofence (Cruz) + Obstáculo (Círculo) via CBF */
  /*  =========================================================================
   */
  /*  Horizonte longo para enxergar o corredor */
  Ts = params[15];
  /*  Tempo de predição */
  /*  Peso para suavizar a velocidade linear */
  /*  Peso ALTO para evitar zigue-zague */
  x_k[0] = params[0];
  x_k[1] = params[1];
  x_k[2] = params[2];
  /*  Centro (Cruz e Círculo) */
  eta_safe = params[10];
  /*  Peso da Barreira CBF */
  eta_obs = params[11];
  gamma_safe = params[12];
  gamma_obs = params[13];
  /*  Limites Seguros */
  L_safe = params[7] - params[16];
  /*  Geofence (Encolhe) */
  W_safe = params[8] - params[16];
  /*  Geofence (Encolhe) */
  R_safe = params[9] + params[16];
  /*  Obstáculo (Incha) */
  if (!(params[14] + 1.0 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(params[14] + 1.0, &emlrtDCI, (emlrtConstCTX)sp);
  }
  i = (int32_T)muDoubleScalarFloor(params[14] + 1.0);
  if (params[14] + 1.0 != i) {
    emlrtIntegerCheckR2012b(params[14] + 1.0, &b_emlrtDCI, (emlrtConstCTX)sp);
  }
  emxInit_real_T(sp, &X_hist, &c_emlrtRTEI);
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
    emlrtDynamicBoundsCheckR2012b(1, 1, (int32_T)(params[14] + 1.0), &emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  X_hist_data[0] = params[0];
  X_hist_data[1] = params[1];
  X_hist_data[2] = params[2];
  l_u = 0.0;
  /*  ===================================================================== */
  /*  FORWARD PASS */
  /*  ===================================================================== */
  x_pos_next_tmp = (int32_T)params[14];
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, params[14], mxDOUBLE_CLASS,
                                (int32_T)params[14], &emlrtRTEI,
                                (emlrtConstCTX)sp);
  for (n = 0; n < x_pos_next_tmp; n++) {
    loop_ub = (int32_T)(((uint32_T)n << 1) + 1U);
    if ((loop_ub < 1) || (loop_ub > 40)) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, 40, &h_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    v_n = u[loop_ub - 1];
    loop_ub = (n << 1) + 2;
    if ((loop_ub < 1) || (loop_ub > 40)) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, 40, &i_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    w_n = u[loop_ub - 1];
    x_pos_k = x_k[0] - params[5];
    y_pos_k = x_k[1] - params[6];
    /*  --- Estado Atual (k) --- */
    /*  Cruz */
    dy2_next = muDoubleScalarAbs(x_pos_k);
    v_circ_next = muDoubleScalarMax(0.0, dy2_next - L_safe);
    P2_next = muDoubleScalarAbs(y_pos_k);
    dx2_k = muDoubleScalarMax(0.0, P2_next - W_safe);
    dx1_next = muDoubleScalarMax(0.0, dy2_next - W_safe);
    P2_k = muDoubleScalarMax(0.0, P2_next - L_safe);
    /*  Círculo */
    dx2_next = R_safe * R_safe;
    dy2_k = muDoubleScalarMax(0.0, dx2_next -
                                       (x_pos_k * x_pos_k + y_pos_k * y_pos_k));
    /*  Dinâmica */
    dy2_next = Ts * v_n;
    v_circ_k = x_k[0] + dy2_next * muDoubleScalarCos(x_k[2]);
    dy1_next = x_k[1] + dy2_next * muDoubleScalarSin(x_k[2]);
    P1_next = x_k[2] + Ts * w_n;
    x_pos_next = v_circ_k - params[5];
    y_pos_next = dy1_next - params[6];
    /*  --- Estado Futuro (next) --- */
    /*  Cruz */
    dy2_next = muDoubleScalarAbs(x_pos_next);
    a = muDoubleScalarMax(0.0, dy2_next - L_safe);
    P2_next = muDoubleScalarAbs(y_pos_next);
    g_cross = muDoubleScalarMax(0.0, P2_next - W_safe);
    b_a = muDoubleScalarMax(0.0, dy2_next - W_safe);
    P2_next = muDoubleScalarMax(0.0, P2_next - L_safe);
    /*  Círculo */
    dy2_next = muDoubleScalarMax(
        0.0, dx2_next - (x_pos_next * x_pos_next + y_pos_next * y_pos_next));
    /*  --- Restrições CBF Separadas --- */
    a = muDoubleScalarMax(
        0.0,
        (1.0 - gamma_safe) * -((v_circ_next * v_circ_next + dx2_k * dx2_k) *
                               (dx1_next * dx1_next + P2_k * P2_k)) -
            (-((a * a + g_cross * g_cross) * (b_a * b_a + P2_next * P2_next))));
    dy2_next = muDoubleScalarMax(0.0, (1.0 - gamma_obs) * -(dy2_k * dy2_k) -
                                          (-(dy2_next * dy2_next)));
    P2_next = x_k[0] - params[3];
    b_a = x_k[1] - params[4];
    l_u = ((l_u + ((2.0 * (P2_next * P2_next + b_a * b_a) + 0.5 * (v_n * v_n)) +
                   0.01 * (w_n * w_n))) +
           eta_safe * (a * a)) +
          eta_obs * (dy2_next * dy2_next);
    x_k[0] = v_circ_k;
    x_k[1] = dy1_next;
    x_k[2] = P1_next;
    if (((int32_T)((uint32_T)n + 2U) < 1) ||
        ((int32_T)((uint32_T)n + 2U) > X_hist->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)n + 2U), 1,
                                    X_hist->size[1], &b_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    loop_ub = 3 * (n + 1);
    X_hist_data[loop_ub] = v_circ_k;
    X_hist_data[loop_ub + 1] = dy1_next;
    X_hist_data[loop_ub + 2] = P1_next;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
  /*  ===================================================================== */
  /*  TERMINAL E BACKWARD PASS */
  /*  ===================================================================== */
  if (params[14] + 1.0 != i) {
    emlrtIntegerCheckR2012b(params[14] + 1.0, &c_emlrtDCI, (emlrtConstCTX)sp);
  }
  i1 = X_hist->size[1];
  if (((int32_T)(params[14] + 1.0) < 1) ||
      ((int32_T)(params[14] + 1.0) > X_hist->size[1])) {
    emlrtDynamicBoundsCheckR2012b((int32_T)(params[14] + 1.0), 1,
                                  X_hist->size[1], &c_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  loop_ub = 3 * ((int32_T)(params[14] + 1.0) - 1);
  dy2_next = X_hist_data[loop_ub] - params[3];
  P2_next = X_hist_data[loop_ub + 1] - params[4];
  cost = l_u + 2.0 * (dy2_next * dy2_next + P2_next * P2_next);
  p_n[0] = 4.0 * dy2_next;
  p_n[1] = 4.0 * P2_next;
  p_n[2] = 0.0;
  memset(&grad[0], 0, 40U * sizeof(real_T));
  i = (int32_T) - ((-1.0 - params[14]) + 1.0);
  emlrtForLoopVectorCheckR2021a(params[14], -1.0, 1.0, mxDOUBLE_CLASS,
                                (int32_T) - ((-1.0 - params[14]) + 1.0),
                                &b_emlrtRTEI, (emlrtConstCTX)sp);
  if ((int32_T) - ((-1.0 - params[14]) + 1.0) - 1 >= 0) {
    b_Ts[4] = 0.0;
    b_Ts[1] = 0.0;
    b_Ts[3] = 0.0;
    b_Ts[5] = params[15];
  }
  if (i - 1 >= 0) {
    v_circ_k_tmp = R_safe * R_safe;
    dv[0] = 1.0;
    dv[1] = 0.0;
    dv[3] = 0.0;
    dv[4] = 1.0;
    dv[6] = 0.0;
    dv[7] = 0.0;
    dv[8] = 1.0;
  }
  for (n = 0; n < i; n++) {
    __m128d r;
    __m128d r1;
    __m128d r2;
    __m128d r3;
    __m128d r4;
    real_T P1_k;
    real_T b_n;
    real_T x_pos_k_tmp;
    real_T y_pos_k_tmp;
    uint32_T b_u;
    uint32_T u1;
    boolean_T b;
    b_n = params[14] - (real_T)n;
    if (b_n != (int32_T)muDoubleScalarFloor(b_n)) {
      emlrtIntegerCheckR2012b(b_n, &d_emlrtDCI, (emlrtConstCTX)sp);
    }
    if (((int32_T)b_n < 1) || ((int32_T)b_n > i1)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)b_n, 1, i1, &d_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    if (((int32_T)(b_n + 1.0) < 1) || ((int32_T)(b_n + 1.0) > i1)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_n + 1.0), 1, i1, &e_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    b_u = (uint32_T)((int32_T)b_n - 1) << 1;
    b = (((int32_T)(b_u + 1U) < 1) || ((int32_T)(b_u + 1U) > 40));
    if (b) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_u + 1U), 1, 40, &j_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    v_n = u[(int32_T)b_u];
    if (((int32_T)(b_u + 2U) < 1) || ((int32_T)(b_u + 2U) > 40)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_u + 2U), 1, 40, &k_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    loop_ub = 3 * ((int32_T)b_n - 1);
    x_pos_k_tmp = X_hist_data[loop_ub];
    x_pos_k = x_pos_k_tmp - params[5];
    y_pos_k_tmp = X_hist_data[loop_ub + 1];
    y_pos_k = y_pos_k_tmp - params[6];
    x_pos_next_tmp = 3 * (int32_T)b_n;
    x_pos_next = X_hist_data[x_pos_next_tmp] - params[5];
    y_pos_next = X_hist_data[x_pos_next_tmp + 1] - params[6];
    /*  Recalcula k */
    dy2_next = muDoubleScalarAbs(x_pos_k);
    l_u = muDoubleScalarMax(0.0, dy2_next - L_safe);
    P2_next = muDoubleScalarAbs(y_pos_k);
    R_safe = muDoubleScalarMax(0.0, P2_next - W_safe);
    P1_k = l_u * l_u + R_safe * R_safe;
    dx2_k = muDoubleScalarMax(0.0, dy2_next - W_safe);
    dy2_k = muDoubleScalarMax(0.0, P2_next - L_safe);
    P2_k = dx2_k * dx2_k + dy2_k * dy2_k;
    v_circ_k = muDoubleScalarMax(
        0.0, v_circ_k_tmp - (x_pos_k * x_pos_k + y_pos_k * y_pos_k));
    /*  Recalcula next */
    dy2_next = muDoubleScalarAbs(x_pos_next);
    dx1_next = muDoubleScalarMax(0.0, dy2_next - L_safe);
    P2_next = muDoubleScalarAbs(y_pos_next);
    dy1_next = muDoubleScalarMax(0.0, P2_next - W_safe);
    P1_next = dx1_next * dx1_next + dy1_next * dy1_next;
    dx2_next = muDoubleScalarMax(0.0, dy2_next - W_safe);
    dy2_next = muDoubleScalarMax(0.0, P2_next - L_safe);
    P2_next = dx2_next * dx2_next + dy2_next * dy2_next;
    v_circ_next =
        muDoubleScalarMax(0.0, v_circ_k_tmp - (x_pos_next * x_pos_next +
                                               y_pos_next * y_pos_next));
    b_a = P1_k * P2_k;
    a = P1_next * P2_next;
    g_cross = (1.0 - gamma_safe) * -b_a - (-a);
    w_n = (1.0 - gamma_obs) * -(v_circ_k * v_circ_k) -
          (-(v_circ_next * v_circ_next));
    gP1[0] = 0.0;
    gP1_n[0] = 0.0;
    gP1[1] = 0.0;
    gP1_n[1] = 0.0;
    gP1[2] = 0.0;
    gP1_n[2] = 0.0;
    /*  --- Gradientes da Geofence (Cruz) --- */
    if (g_cross > 0.0) {
      gP1[0] = 0.0;
      gP1_n[0] = 0.0;
      gP1[1] = 0.0;
      gP1_n[1] = 0.0;
      gP1[2] = 0.0;
      gP1_n[2] = 0.0;
      if ((b_a > 0.0) || (P1_k > 0.0) || (P2_k > 0.0)) {
        gP1[0] = 0.0;
        x_k[0] = 0.0;
        gP1[1] = 0.0;
        x_k[1] = 0.0;
        gP1[2] = 0.0;
        x_k[2] = 0.0;
        if (l_u > 0.0) {
          gP1[0] = 2.0 * l_u * muDoubleScalarSign(x_pos_k);
        }
        if (R_safe > 0.0) {
          gP1[1] = 2.0 * R_safe * muDoubleScalarSign(y_pos_k);
        }
        if (dx2_k > 0.0) {
          x_k[0] = 2.0 * dx2_k * muDoubleScalarSign(x_pos_k);
        }
        if (dy2_k > 0.0) {
          x_k[1] = 2.0 * dy2_k * muDoubleScalarSign(y_pos_k);
        }
        r = _mm_loadu_pd(&gP1[0]);
        r1 = _mm_loadu_pd(&x_k[0]);
        _mm_storeu_pd(&gP1[0], _mm_add_pd(_mm_mul_pd(_mm_set1_pd(P2_k), r),
                                          _mm_mul_pd(_mm_set1_pd(P1_k), r1)));
        gP1[2] = P2_k * gP1[2] + P1_k * 0.0;
      }
      if ((a > 0.0) || (P1_next > 0.0) || (P2_next > 0.0)) {
        gP1_n[0] = 0.0;
        x_k[0] = 0.0;
        gP1_n[1] = 0.0;
        x_k[1] = 0.0;
        gP1_n[2] = 0.0;
        x_k[2] = 0.0;
        if (dx1_next > 0.0) {
          gP1_n[0] = 2.0 * dx1_next * muDoubleScalarSign(x_pos_next);
        }
        if (dy1_next > 0.0) {
          gP1_n[1] = 2.0 * dy1_next * muDoubleScalarSign(y_pos_next);
        }
        if (dx2_next > 0.0) {
          x_k[0] = 2.0 * dx2_next * muDoubleScalarSign(x_pos_next);
        }
        if (dy2_next > 0.0) {
          x_k[1] = 2.0 * dy2_next * muDoubleScalarSign(y_pos_next);
        }
        r = _mm_loadu_pd(&gP1_n[0]);
        r1 = _mm_loadu_pd(&x_k[0]);
        _mm_storeu_pd(&gP1_n[0],
                      _mm_add_pd(_mm_mul_pd(_mm_set1_pd(P2_next), r),
                                 _mm_mul_pd(_mm_set1_pd(P1_next), r1)));
        gP1_n[2] = P2_next * gP1_n[2] + P1_next * 0.0;
      }
      dy2_next = 2.0 * eta_safe * g_cross;
      r = _mm_loadu_pd(&gP1[0]);
      r1 = _mm_set1_pd(dy2_next);
      _mm_storeu_pd(
          &gP1[0],
          _mm_mul_pd(r1, _mm_mul_pd(_mm_set1_pd(1.0 - gamma_safe),
                                    _mm_mul_pd(r, _mm_set1_pd(-1.0)))));
      r = _mm_loadu_pd(&gP1_n[0]);
      _mm_storeu_pd(&gP1_n[0], _mm_mul_pd(r1, r));
      gP1[2] = dy2_next * ((1.0 - gamma_safe) * -gP1[2]);
      gP1_n[2] *= dy2_next;
    }
    /*  --- Gradientes do Obstáculo (Círculo) --- */
    if (w_n > 0.0) {
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
      if (v_circ_next > 0.0) {
        dy2_next = -4.0 * v_circ_next;
        x_next[0] = dy2_next * x_pos_next;
        x_next[1] = dy2_next * y_pos_next;
      }
      dy2_next = 2.0 * eta_obs * w_n;
      r = _mm_loadu_pd(&x_k[0]);
      r1 = _mm_loadu_pd(&gP1[0]);
      r2 = _mm_set1_pd(dy2_next);
      _mm_storeu_pd(
          &gP1[0],
          _mm_add_pd(
              r1,
              _mm_mul_pd(r2, _mm_mul_pd(_mm_set1_pd(1.0 - gamma_obs),
                                        _mm_mul_pd(r, _mm_set1_pd(-1.0))))));
      r = _mm_loadu_pd(&x_next[0]);
      r1 = _mm_loadu_pd(&gP1_n[0]);
      _mm_storeu_pd(&gP1_n[0], _mm_add_pd(r1, _mm_mul_pd(r2, r)));
      gP1[2] += dy2_next * ((1.0 - gamma_obs) * -0.0);
      gP1_n[2] += dy2_next * 0.0;
    }
    dy2_next = X_hist_data[loop_ub + 2];
    P2_next = muDoubleScalarCos(dy2_next);
    dy2_next = muDoubleScalarSin(dy2_next);
    gP1_n[0] += p_n[0];
    gP1_n[1] += p_n[1];
    gP1_n[2] += p_n[2];
    dv[2] = -Ts * v_n * dy2_next;
    dv[5] = Ts * v_n * P2_next;
    memset(&p_n[0], 0, 3U * sizeof(real_T));
    r = _mm_loadu_pd(&dv[0]);
    r1 = _mm_loadu_pd(&p_n[0]);
    r2 = _mm_set1_pd(gP1_n[0]);
    _mm_storeu_pd(&p_n[0], _mm_add_pd(r1, _mm_mul_pd(r, r2)));
    p_n[2] += gP1_n[0] * dv[2];
    r = _mm_loadu_pd(&dv[3]);
    r1 = _mm_loadu_pd(&p_n[0]);
    r3 = _mm_set1_pd(gP1_n[1]);
    _mm_storeu_pd(&p_n[0], _mm_add_pd(r1, _mm_mul_pd(r, r3)));
    p_n[2] += gP1_n[1] * dv[5];
    r = _mm_loadu_pd(&dv[6]);
    r1 = _mm_loadu_pd(&p_n[0]);
    r4 = _mm_set1_pd(gP1_n[2]);
    _mm_storeu_pd(&p_n[0], _mm_add_pd(r1, _mm_mul_pd(r, r4)));
    p_n[2] += gP1_n[2];
    gP1[0] += 4.0 * (x_pos_k_tmp - params[3]);
    gP1[1] += 4.0 * (y_pos_k_tmp - params[4]);
    r = _mm_loadu_pd(&p_n[0]);
    r1 = _mm_loadu_pd(&gP1[0]);
    _mm_storeu_pd(&p_n[0], _mm_add_pd(r, r1));
    p_n[2] += gP1[2];
    u1 = (uint32_T)b_n << 1;
    if (b_u + 1U > u1) {
      x_pos_next_tmp = 0;
      loop_ub = 0;
    } else {
      if (b) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(b_u + 1U), 1, 40, &f_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      x_pos_next_tmp = (int32_T)b_u;
      if (((int32_T)u1 < 1) || ((int32_T)u1 > 40)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)u1, 1, 40, &g_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      loop_ub = (int32_T)u1;
    }
    loop_ub -= x_pos_next_tmp;
    if (loop_ub != 2) {
      emlrtSubAssignSizeCheck1dR2017a(loop_ub, 2, &emlrtECI, (emlrtConstCTX)sp);
    }
    b_Ts[0] = Ts * P2_next;
    b_Ts[2] = Ts * dy2_next;
    memset(&c_Ts[0], 0, sizeof(real_T) << 1);
    r = _mm_loadu_pd(&b_Ts[0]);
    r1 = _mm_loadu_pd(&c_Ts[0]);
    _mm_storeu_pd(&c_Ts[0], _mm_add_pd(r1, _mm_mul_pd(r, r2)));
    r = _mm_loadu_pd(&b_Ts[2]);
    r1 = _mm_loadu_pd(&c_Ts[0]);
    _mm_storeu_pd(&c_Ts[0], _mm_add_pd(r1, _mm_mul_pd(r, r3)));
    r = _mm_loadu_pd(&b_Ts[4]);
    r1 = _mm_loadu_pd(&c_Ts[0]);
    _mm_storeu_pd(&c_Ts[0], _mm_add_pd(r1, _mm_mul_pd(r, r4)));
    b_v_n[0] = v_n;
    b_v_n[1] = 0.02 * u[(int32_T)b_u + 1];
    r = _mm_loadu_pd(&c_Ts[0]);
    r1 = _mm_loadu_pd(&b_v_n[0]);
    _mm_storeu_pd(&grad[x_pos_next_tmp], _mm_add_pd(r, r1));
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
  emxFree_real_T(sp, &X_hist);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
  return cost;
}

/* End of code generation (build_robot_cbf_experiment.c) */
