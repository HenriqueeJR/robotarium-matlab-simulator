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
    "C:\\Users\\henri\\Desktop\\robotarium_ws\\robotarium-matlab-"
    "simulator\\examples\\cbf_cruz_waypoints\\wrapper_cost.m" /* pathName */
};

static emlrtRSInfo m_emlrtRSI = {
    104,                          /* lineNo */
    "build_robot_cbf_experiment", /* fcnName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws\\robotarium-matlab-"
    "simulator\\examples\\cbf_cruz_waypoints\\build_robot_cbf_experiment."
    "m" /* pathName */
};

static emlrtDCInfo emlrtDCI = {
    30,                           /* lineNo */
    23,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws\\robotarium-matlab-"
    "simulator\\examples\\cbf_cruz_waypoints\\build_robot_cbf_experiment."
    "m", /* pName */
    4    /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = {
    30,                           /* lineNo */
    23,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws\\robotarium-matlab-"
    "simulator\\examples\\cbf_cruz_waypoints\\build_robot_cbf_experiment."
    "m", /* pName */
    1    /* checkKind */
};

static emlrtRTEInfo emlrtRTEI = {
    37,                           /* lineNo */
    13,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws\\robotarium-matlab-"
    "simulator\\examples\\cbf_cruz_waypoints\\build_robot_cbf_experiment."
    "m" /* pName */
};

static emlrtBCInfo emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    31,                           /* lineNo */
    15,                           /* colNo */
    "X_hist",                     /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws\\robotarium-matlab-"
    "simulator\\examples\\cbf_cruz_waypoints\\build_robot_cbf_experiment."
    "m", /* pName */
    0    /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    95,                           /* lineNo */
    19,                           /* colNo */
    "X_hist",                     /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws\\robotarium-matlab-"
    "simulator\\examples\\cbf_cruz_waypoints\\build_robot_cbf_experiment."
    "m", /* pName */
    0    /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = {
    103,                          /* lineNo */
    21,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws\\robotarium-matlab-"
    "simulator\\examples\\cbf_cruz_waypoints\\build_robot_cbf_experiment."
    "m", /* pName */
    1    /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    103,                          /* lineNo */
    21,                           /* colNo */
    "X_hist",                     /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws\\robotarium-matlab-"
    "simulator\\examples\\cbf_cruz_waypoints\\build_robot_cbf_experiment."
    "m", /* pName */
    0    /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = {
    1,                            /* iFirst */
    40,                           /* iLast */
    38,                           /* lineNo */
    17,                           /* colNo */
    "u",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws\\robotarium-matlab-"
    "simulator\\examples\\cbf_cruz_waypoints\\build_robot_cbf_experiment."
    "m", /* pName */
    0    /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = {
    1,                            /* iFirst */
    40,                           /* iLast */
    39,                           /* lineNo */
    17,                           /* colNo */
    "u",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws\\robotarium-matlab-"
    "simulator\\examples\\cbf_cruz_waypoints\\build_robot_cbf_experiment."
    "m", /* pName */
    0    /* checkKind */
};

static emlrtRTEInfo b_emlrtRTEI = {
    30,                           /* lineNo */
    5,                            /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws\\robotarium-matlab-"
    "simulator\\examples\\cbf_cruz_waypoints\\build_robot_cbf_experiment."
    "m" /* pName */
};

/* Function Definitions */
real_T wrapper_cost(const emlrtStack *sp, const real_T u[40],
                    const real_T params[17])
{
  __m128d r;
  emlrtStack b_st;
  emlrtStack st;
  emxArray_real_T *X_hist;
  real_T b_y[19];
  real_T e_a[19];
  real_T y[19];
  real_T L_safe;
  real_T R_safe;
  real_T Ts;
  real_T W_safe;
  real_T cost;
  real_T l_u;
  real_T tmp2;
  real_T x_k_idx_0;
  real_T x_k_idx_1;
  real_T x_next_idx_2;
  real_T x_pos_k;
  real_T y_pos_k;
  real_T *X_hist_data;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  int32_T n;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  /*  1. Calcula o custo original (distância, obstáculo, etc) */
  st.site = &emlrtRSI;
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
  x_k_idx_0 = params[0];
  x_k_idx_1 = params[1];
  x_next_idx_2 = params[2];
  /*  Centro (Cruz e Círculo) */
  /*  Peso da Barreira CBF */
  /*  Limites Seguros */
  L_safe = params[7] - params[16];
  /*  Geofence (Encolhe) */
  W_safe = params[8] - params[16];
  /*  Geofence (Encolhe) */
  R_safe = params[9] + params[16];
  /*  Obstáculo (Incha) */
  if (!(params[14] + 1.0 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(params[14] + 1.0, &emlrtDCI, &st);
  }
  i = (int32_T)muDoubleScalarFloor(params[14] + 1.0);
  if (params[14] + 1.0 != i) {
    emlrtIntegerCheckR2012b(params[14] + 1.0, &b_emlrtDCI, &st);
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
    emlrtDynamicBoundsCheckR2012b(1, 1, (int32_T)(params[14] + 1.0), &emlrtBCI,
                                  &st);
  }
  X_hist_data[0] = params[0];
  X_hist_data[1] = params[1];
  X_hist_data[2] = params[2];
  l_u = 0.0;
  /*  ===================================================================== */
  /*  FORWARD PASS */
  /*  ===================================================================== */
  i1 = (int32_T)params[14];
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, params[14], mxDOUBLE_CLASS,
                                (int32_T)params[14], &emlrtRTEI, &st);
  for (n = 0; n < i1; n++) {
    real_T a;
    real_T a_tmp;
    real_T b_a;
    real_T c_a;
    real_T d;
    real_T d1;
    real_T d_a;
    real_T f_a;
    real_T g_a;
    real_T h_a;
    real_T i_a;
    real_T v_n;
    real_T w_n;
    loop_ub = (int32_T)(((uint32_T)n << 1) + 1U);
    if ((loop_ub < 1) || (loop_ub > 40)) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, 40, &d_emlrtBCI, &st);
    }
    v_n = u[loop_ub - 1];
    loop_ub = (n << 1) + 2;
    if ((loop_ub < 1) || (loop_ub > 40)) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, 40, &e_emlrtBCI, &st);
    }
    w_n = u[loop_ub - 1];
    x_pos_k = x_k_idx_0 - params[5];
    y_pos_k = x_k_idx_1 - params[6];
    /*  --- Estado Atual (k) --- */
    /*  Cruz */
    cost = muDoubleScalarAbs(x_pos_k);
    a = muDoubleScalarMax(0.0, cost - L_safe);
    tmp2 = muDoubleScalarAbs(y_pos_k);
    b_a = muDoubleScalarMax(0.0, tmp2 - W_safe);
    c_a = muDoubleScalarMax(0.0, cost - W_safe);
    d_a = muDoubleScalarMax(0.0, tmp2 - L_safe);
    /*  Círculo */
    a_tmp = R_safe * R_safe;
    f_a =
        muDoubleScalarMax(0.0, a_tmp - (x_pos_k * x_pos_k + y_pos_k * y_pos_k));
    /*  Dinâmica */
    cost = Ts * v_n;
    d = x_k_idx_0 + cost * muDoubleScalarCos(x_next_idx_2);
    d1 = x_k_idx_1 + cost * muDoubleScalarSin(x_next_idx_2);
    x_next_idx_2 += Ts * w_n;
    x_pos_k = d - params[5];
    y_pos_k = d1 - params[6];
    /*  --- Estado Futuro (next) --- */
    /*  Cruz */
    cost = muDoubleScalarAbs(x_pos_k);
    g_a = muDoubleScalarMax(0.0, cost - L_safe);
    tmp2 = muDoubleScalarAbs(y_pos_k);
    h_a = muDoubleScalarMax(0.0, tmp2 - W_safe);
    i_a = muDoubleScalarMax(0.0, cost - W_safe);
    tmp2 = muDoubleScalarMax(0.0, tmp2 - L_safe);
    /*  Círculo */
    cost =
        muDoubleScalarMax(0.0, a_tmp - (x_pos_k * x_pos_k + y_pos_k * y_pos_k));
    /*  --- Restrições CBF Separadas --- */
    y_pos_k = muDoubleScalarMax(
        0.0,
        (1.0 - params[12]) * -((a * a + b_a * b_a) * (c_a * c_a + d_a * d_a)) -
            (-((g_a * g_a + h_a * h_a) * (i_a * i_a + tmp2 * tmp2))));
    x_pos_k = muDoubleScalarMax(0.0, (1.0 - params[13]) * -(f_a * f_a) -
                                         (-(cost * cost)));
    tmp2 = x_k_idx_0 - params[3];
    cost = x_k_idx_1 - params[4];
    l_u = ((l_u + ((1.8 * (tmp2 * tmp2 + cost * cost) + 0.5 * (v_n * v_n)) +
                   0.001 * (w_n * w_n))) +
           params[10] * (y_pos_k * y_pos_k)) +
          params[11] * (x_pos_k * x_pos_k);
    x_k_idx_0 = d;
    x_k_idx_1 = d1;
    if (((int32_T)((uint32_T)n + 2U) < 1) ||
        ((int32_T)((uint32_T)n + 2U) > X_hist->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)n + 2U), 1,
                                    X_hist->size[1], &b_emlrtBCI, &st);
    }
    loop_ub = 3 * (n + 1);
    X_hist_data[loop_ub] = d;
    X_hist_data[loop_ub + 1] = d1;
    X_hist_data[loop_ub + 2] = x_next_idx_2;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }
  /*  ===================================================================== */
  /*  TERMINAL E BACKWARD PASS */
  /*  ===================================================================== */
  if (params[14] + 1.0 != i) {
    emlrtIntegerCheckR2012b(params[14] + 1.0, &c_emlrtDCI, &st);
  }
  if (((int32_T)(params[14] + 1.0) < 1) ||
      ((int32_T)(params[14] + 1.0) > X_hist->size[1])) {
    emlrtDynamicBoundsCheckR2012b((int32_T)(params[14] + 1.0), 1,
                                  X_hist->size[1], &c_emlrtBCI, &st);
  }
  loop_ub = 3 * ((int32_T)(params[14] + 1.0) - 1);
  x_pos_k = X_hist_data[loop_ub] - params[3];
  b_st.site = &m_emlrtRSI;
  y_pos_k = X_hist_data[loop_ub + 1] - params[4];
  emxFree_real_T(&b_st, &X_hist);
  /*  2. Pesos de suavização (Tuning) */
  /*  Aumente esses valores se o robô continuar tremendo. */
  /*  Diminua se ele ficar "preguiçoso" demais para desviar. */
  /*  Penalidade para variação de velocidade linear */
  /*  Penalidade para variação de velocidade angular (Alta para matar o
   * zigue-zague) */
  /*  3. Separa as variáveis v e w do vetor u */
  /*  u tem o formato [v1; w1; v2; w2; ...] */
  /*  4. Calcula a variação quadrática (Delta u) ao longo do horizonte */
  /*  A função diff() do MATLAB faz exatamente v(2)-v(1), v(3)-v(2)... */
  cost = u[0];
  for (n = 0; n < 19; n++) {
    tmp2 = cost;
    cost = u[(n + 1) << 1];
    e_a[n] = cost - tmp2;
  }
  for (n = 0; n <= 16; n += 2) {
    r = _mm_loadu_pd(&e_a[n]);
    _mm_storeu_pd(&y[n], _mm_mul_pd(r, r));
  }
  y[18] = e_a[18] * e_a[18];
  cost = u[1];
  for (n = 0; n < 19; n++) {
    tmp2 = cost;
    cost = u[((n + 1) << 1) + 1];
    e_a[n] = cost - tmp2;
  }
  for (n = 0; n <= 16; n += 2) {
    r = _mm_loadu_pd(&e_a[n]);
    _mm_storeu_pd(&b_y[n], _mm_mul_pd(r, r));
  }
  b_y[18] = e_a[18] * e_a[18];
  /*  5. Custo total */
  cost = (l_u + 1.8 * (x_pos_k * x_pos_k + y_pos_k * y_pos_k)) +
         (0.2 * sumColumnB(y) + 0.2 * sumColumnB(b_y));
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
  return cost;
}

/* End of code generation (wrapper_cost.c) */
