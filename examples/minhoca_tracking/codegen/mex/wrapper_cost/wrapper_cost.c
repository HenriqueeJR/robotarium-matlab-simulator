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
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "tracking\\wra"
    "pper_cost.m" /* pathName */
};

static emlrtBCInfo emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    77,                           /* lineNo */
    21,                           /* colNo */
    "X_hist",                     /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "tracking\\bui"
    "ld_robot_cbf_experiment.m", /* pName */
    0                            /* checkKind */
};

static emlrtDCInfo emlrtDCI = {
    77,                           /* lineNo */
    21,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "tracking\\bui"
    "ld_robot_cbf_experiment.m", /* pName */
    1                            /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    69,                           /* lineNo */
    19,                           /* colNo */
    "X_hist",                     /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "tracking\\bui"
    "ld_robot_cbf_experiment.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    36,                           /* lineNo */
    15,                           /* colNo */
    "X_hist",                     /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "tracking\\bui"
    "ld_robot_cbf_experiment.m", /* pName */
    0                            /* checkKind */
};

static emlrtRTEInfo emlrtRTEI = {
    45,                           /* lineNo */
    13,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "tracking\\bui"
    "ld_robot_cbf_experiment.m" /* pName */
};

static emlrtDCInfo b_emlrtDCI = {
    35,                           /* lineNo */
    23,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "tracking\\bui"
    "ld_robot_cbf_experiment.m", /* pName */
    1                            /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = {
    35,                           /* lineNo */
    23,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "tracking\\bui"
    "ld_robot_cbf_experiment.m", /* pName */
    4                            /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = {
    1,                            /* iFirst */
    50,                           /* iLast */
    21,                           /* lineNo */
    14,                           /* colNo */
    "W",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "tracking\\bui"
    "ld_robot_cbf_experiment.m", /* pName */
    0                            /* checkKind */
};

static emlrtDCInfo d_emlrtDCI = {
    21,                           /* lineNo */
    14,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "tracking\\bui"
    "ld_robot_cbf_experiment.m", /* pName */
    1                            /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    46,                           /* lineNo */
    17,                           /* colNo */
    "u",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "tracking\\bui"
    "ld_robot_cbf_experiment.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    47,                           /* lineNo */
    17,                           /* colNo */
    "u",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "tracking\\bui"
    "ld_robot_cbf_experiment.m", /* pName */
    0                            /* checkKind */
};

static emlrtDCInfo e_emlrtDCI = {
    23,                           /* lineNo */
    12,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "tracking\\bui"
    "ld_robot_cbf_experiment.m", /* pName */
    1                            /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = {
    1,                            /* iFirst */
    50,                           /* iLast */
    23,                           /* lineNo */
    12,                           /* colNo */
    "W",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "tracking\\bui"
    "ld_robot_cbf_experiment.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = {
    1,                            /* iFirst */
    50,                           /* iLast */
    33,                           /* lineNo */
    12,                           /* colNo */
    "W",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "tracking\\bui"
    "ld_robot_cbf_experiment.m", /* pName */
    0                            /* checkKind */
};

static emlrtDCInfo f_emlrtDCI = {
    33,                           /* lineNo */
    12,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "tracking\\bui"
    "ld_robot_cbf_experiment.m", /* pName */
    1                            /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = {
    1,                            /* iFirst */
    50,                           /* iLast */
    32,                           /* lineNo */
    12,                           /* colNo */
    "W",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "tracking\\bui"
    "ld_robot_cbf_experiment.m", /* pName */
    0                            /* checkKind */
};

static emlrtDCInfo g_emlrtDCI = {
    32,                           /* lineNo */
    12,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "tracking\\bui"
    "ld_robot_cbf_experiment.m", /* pName */
    1                            /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = {
    1,                            /* iFirst */
    50,                           /* iLast */
    31,                           /* lineNo */
    12,                           /* colNo */
    "W",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "tracking\\bui"
    "ld_robot_cbf_experiment.m", /* pName */
    0                            /* checkKind */
};

static emlrtDCInfo h_emlrtDCI = {
    31,                           /* lineNo */
    12,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "tracking\\bui"
    "ld_robot_cbf_experiment.m", /* pName */
    1                            /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = {
    1,                            /* iFirst */
    50,                           /* iLast */
    22,                           /* lineNo */
    12,                           /* colNo */
    "W",                          /* aName */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "tracking\\bui"
    "ld_robot_cbf_experiment.m", /* pName */
    0                            /* checkKind */
};

static emlrtDCInfo i_emlrtDCI = {
    22,                           /* lineNo */
    12,                           /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "tracking\\bui"
    "ld_robot_cbf_experiment.m", /* pName */
    1                            /* checkKind */
};

static emlrtRTEInfo b_emlrtRTEI = {
    35,                           /* lineNo */
    5,                            /* colNo */
    "build_robot_cbf_experiment", /* fName */
    "C:\\Users\\henri\\Dropbox\\HenriqueJr\\codigos-"
    "modelos\\robotarium\\robotarium-matlab-simulator\\examples\\minhoca_"
    "tracking\\bui"
    "ld_robot_cbf_experiment.m" /* pName */
};

/* Function Definitions */
real_T wrapper_cost(const emlrtStack *sp, const real_T u[50],
                    const real_T params[30])
{
  __m128d b_r1;
  __m128d b_r2;
  __m128d r;
  emlrtStack st;
  emxArray_real_T *X_hist;
  real_T b_a[24];
  real_T f_y[24];
  real_T g_y[24];
  real_T varargin_1[4];
  real_T x_k[3];
  real_T x_next[3];
  real_T a[2];
  real_T b_y[2];
  real_T c_y[2];
  real_T d_y[2];
  real_T e_y[2];
  real_T r1[2];
  real_T r2[2];
  real_T r3[2];
  real_T xs[2];
  real_T y[2];
  real_T P_k;
  real_T P_next;
  real_T Pa;
  real_T Pc;
  real_T Pg;
  real_T Pv;
  real_T Ts;
  real_T b_Pa;
  real_T b_Pc;
  real_T b_Pg;
  real_T b_Pv;
  real_T b_tmp2;
  real_T b_xs_tmp;
  real_T c_Pa;
  real_T c_Pc;
  real_T c_Pg;
  real_T c_Pv;
  real_T cost;
  real_T d_Pa;
  real_T l_u;
  real_T tmp2;
  real_T v_n;
  real_T v_s_tmp;
  real_T w_n;
  real_T w_s;
  real_T xs_tmp;
  real_T *X_hist_data;
  int32_T i;
  int32_T i1;
  int32_T idx;
  int32_T k;
  int32_T n;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  st.site = &emlrtRSI;
  /*  Desempacotamento do vetor params (Tamanho: 30) */
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
  Pa = (int32_T)muDoubleScalarFloor(params[7] + 1.0);
  if (params[7] + 1.0 != Pa) {
    emlrtIntegerCheckR2012b(params[7] + 1.0, &b_emlrtDCI, &st);
  }
  emxInit_real_T(&st, &X_hist, &b_emlrtRTEI);
  idx = X_hist->size[0] * X_hist->size[1];
  X_hist->size[0] = 3;
  X_hist->size[1] = (int32_T)(params[7] + 1.0);
  emxEnsureCapacity_real_T(&st, X_hist, idx, &b_emlrtRTEI);
  X_hist_data = X_hist->data;
  idx = 3 * (int32_T)(params[7] + 1.0);
  for (k = 0; k < idx; k++) {
    X_hist_data[k] = 0.0;
  }
  if ((int32_T)(params[7] + 1.0) < 1) {
    emlrtDynamicBoundsCheckR2012b(1, 1, (int32_T)(params[7] + 1.0), &c_emlrtBCI,
                                  &st);
  }
  X_hist_data[0] = params[0];
  X_hist_data[1] = params[1];
  X_hist_data[2] = params[2];
  l_u = 0.0;
  /*  Parâmetro h para a Generalized P2S-HSD (suavização) */
  /*  ===================================================================== */
  /*  FORWARD PASS (Dinâmica com CBF - Mantém a Distância Exata Quadratica) */
  /*  ===================================================================== */
  i1 = (int32_T)params[7];
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, params[7], mxDOUBLE_CLASS,
                                (int32_T)params[7], &emlrtRTEI, &st);
  for (n = 0; n < i1; n++) {
    int32_T b_k;
    boolean_T exitg1;
    idx = (int32_T)(((uint32_T)n << 1) + 1U);
    if ((idx < 1) || (idx > i)) {
      emlrtDynamicBoundsCheckR2012b(idx, 1, i, &e_emlrtBCI, &st);
    }
    v_n = u[idx - 1];
    idx = (n << 1) + 2;
    if ((idx < 1) || (idx > i)) {
      emlrtDynamicBoundsCheckR2012b(idx, 1, i, &f_emlrtBCI, &st);
    }
    w_n = u[idx - 1];
    P_k = get_exact_blocks_P(&x_k[0], &params[10], &cost, &tmp2, &b_tmp2);
    varargin_1[0] = P_k;
    varargin_1[1] = cost;
    varargin_1[2] = tmp2;
    varargin_1[3] = b_tmp2;
    if (!muDoubleScalarIsNaN(P_k)) {
      idx = 1;
    } else {
      idx = 0;
      b_k = 2;
      exitg1 = false;
      while ((!exitg1) && (b_k < 5)) {
        if (!muDoubleScalarIsNaN(varargin_1[b_k - 1])) {
          idx = b_k;
          exitg1 = true;
        } else {
          b_k++;
        }
      }
    }
    if (idx != 0) {
      P_k = varargin_1[idx - 1];
      idx++;
      for (k = idx; k < 5; k++) {
        cost = varargin_1[k - 1];
        if (P_k > cost) {
          P_k = cost;
        }
      }
    }
    cost = Ts * v_n;
    x_next[0] = x_k[0] + cost * muDoubleScalarCos(x_k[2]);
    x_next[1] = x_k[1] + cost * muDoubleScalarSin(x_k[2]);
    x_next[2] = x_k[2] + Ts * w_n;
    P_next = get_exact_blocks_P(&x_next[0], &params[10], &cost, &tmp2, &b_tmp2);
    varargin_1[0] = P_next;
    varargin_1[1] = cost;
    varargin_1[2] = tmp2;
    varargin_1[3] = b_tmp2;
    if (!muDoubleScalarIsNaN(P_next)) {
      idx = 1;
    } else {
      idx = 0;
      b_k = 2;
      exitg1 = false;
      while ((!exitg1) && (b_k < 5)) {
        if (!muDoubleScalarIsNaN(varargin_1[b_k - 1])) {
          idx = b_k;
          exitg1 = true;
        } else {
          b_k++;
        }
      }
    }
    if (idx != 0) {
      P_next = varargin_1[idx - 1];
      idx++;
      for (k = idx; k < 5; k++) {
        cost = varargin_1[k - 1];
        if (P_next > cost) {
          P_next = cost;
        }
      }
    }
    b_tmp2 = muDoubleScalarMax(0.0, (1.0 - params[6]) * -P_k - (-P_next));
    P_next = x_k[0] - xs_tmp;
    P_k = x_k[1] - b_xs_tmp;
    tmp2 = v_n - v_s_tmp;
    cost = w_n - w_s;
    l_u = (l_u + ((5.0 * (P_next * P_next + P_k * P_k) + 0.5 * (tmp2 * tmp2)) +
                  cost * cost)) +
          params[5] * (b_tmp2 * b_tmp2);
    x_k[0] = x_next[0];
    x_k[1] = x_next[1];
    x_k[2] = x_next[2];
    if (((int32_T)((uint32_T)n + 2U) < 1) ||
        ((int32_T)((uint32_T)n + 2U) > X_hist->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)n + 2U), 1,
                                    X_hist->size[1], &b_emlrtBCI, &st);
    }
    idx = 3 * (n + 1);
    X_hist_data[idx] = x_next[0];
    X_hist_data[idx + 1] = x_next[1];
    X_hist_data[idx + 2] = x_next[2];
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }
  /*  ===================================================================== */
  /*  TERMINAL E BACKWARD PASS */
  /*  ===================================================================== */
  if (params[7] + 1.0 != Pa) {
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
  /*  GEOFENCE PONTO A PONTO USANDO GENERALIZED P2S-HSD */
  /*  ===================================================================== */
  /*  =========================================================================
   */
  /*  FUNÇÃO AUXILIAR: Penalidade Ponto a Ponto (Regra do Produto com P2S) */
  /*  =========================================================================
   */
  varargin_1[0] = params[10];
  varargin_1[1] = params[11];
  varargin_1[2] = params[12];
  varargin_1[3] = params[13];
  P_next = get_single_block_p2s(xs, varargin_1, a);
  varargin_1[0] = params[14];
  varargin_1[1] = params[15];
  varargin_1[2] = params[16];
  varargin_1[3] = params[17];
  P_k = get_single_block_p2s(xs, varargin_1, a);
  varargin_1[0] = params[18];
  varargin_1[1] = params[19];
  varargin_1[2] = params[20];
  varargin_1[3] = params[21];
  v_n = get_single_block_p2s(xs, varargin_1, a);
  varargin_1[0] = params[22];
  varargin_1[1] = params[23];
  varargin_1[2] = params[24];
  varargin_1[3] = params[25];
  w_n = get_single_block_p2s(xs, varargin_1, a);
  /*  Multiplicatório P(p) da união */
  /*  =========================================================================
   */
  /*  FUNÇÃO AUXILIAR: Penalidade Ponto a Ponto (Regra do Produto com P2S) */
  /*  =========================================================================
   */
  varargin_1[0] = params[10];
  varargin_1[1] = params[11];
  varargin_1[2] = params[12];
  varargin_1[3] = params[13];
  Pa = get_single_block_p2s(r1, varargin_1, a);
  varargin_1[0] = params[14];
  varargin_1[1] = params[15];
  varargin_1[2] = params[16];
  varargin_1[3] = params[17];
  Ts = get_single_block_p2s(r1, varargin_1, a);
  varargin_1[0] = params[18];
  varargin_1[1] = params[19];
  varargin_1[2] = params[20];
  varargin_1[3] = params[21];
  xs_tmp = get_single_block_p2s(r1, varargin_1, a);
  varargin_1[0] = params[22];
  varargin_1[1] = params[23];
  varargin_1[2] = params[24];
  varargin_1[3] = params[25];
  b_xs_tmp = get_single_block_p2s(r1, varargin_1, a);
  /*  Multiplicatório P(p) da união */
  /*  =========================================================================
   */
  /*  FUNÇÃO AUXILIAR: Penalidade Ponto a Ponto (Regra do Produto com P2S) */
  /*  =========================================================================
   */
  varargin_1[0] = params[10];
  varargin_1[1] = params[11];
  varargin_1[2] = params[12];
  varargin_1[3] = params[13];
  b_Pa = get_single_block_p2s(r2, varargin_1, a);
  varargin_1[0] = params[14];
  varargin_1[1] = params[15];
  varargin_1[2] = params[16];
  varargin_1[3] = params[17];
  Pv = get_single_block_p2s(r2, varargin_1, a);
  varargin_1[0] = params[18];
  varargin_1[1] = params[19];
  varargin_1[2] = params[20];
  varargin_1[3] = params[21];
  Pg = get_single_block_p2s(r2, varargin_1, a);
  varargin_1[0] = params[22];
  varargin_1[1] = params[23];
  varargin_1[2] = params[24];
  varargin_1[3] = params[25];
  Pc = get_single_block_p2s(r2, varargin_1, a);
  /*  Multiplicatório P(p) da união */
  /*  =========================================================================
   */
  /*  FUNÇÃO AUXILIAR: Penalidade Ponto a Ponto (Regra do Produto com P2S) */
  /*  =========================================================================
   */
  varargin_1[0] = params[10];
  varargin_1[1] = params[11];
  varargin_1[2] = params[12];
  varargin_1[3] = params[13];
  c_Pa = get_single_block_p2s(r3, varargin_1, a);
  varargin_1[0] = params[14];
  varargin_1[1] = params[15];
  varargin_1[2] = params[16];
  varargin_1[3] = params[17];
  b_Pv = get_single_block_p2s(r3, varargin_1, a);
  varargin_1[0] = params[18];
  varargin_1[1] = params[19];
  varargin_1[2] = params[20];
  varargin_1[3] = params[21];
  b_Pg = get_single_block_p2s(r3, varargin_1, a);
  varargin_1[0] = params[22];
  varargin_1[1] = params[23];
  varargin_1[2] = params[24];
  varargin_1[3] = params[25];
  b_Pc = get_single_block_p2s(r3, varargin_1, a);
  /*  Multiplicatório P(p) da união */
  /*  =========================================================================
   */
  /*  FUNÇÃO AUXILIAR: Penalidade Ponto a Ponto (Regra do Produto com P2S) */
  /*  =========================================================================
   */
  varargin_1[0] = params[10];
  varargin_1[1] = params[11];
  varargin_1[2] = params[12];
  varargin_1[3] = params[13];
  d_Pa = get_single_block_p2s(&params[3], varargin_1, a);
  varargin_1[0] = params[14];
  varargin_1[1] = params[15];
  varargin_1[2] = params[16];
  varargin_1[3] = params[17];
  c_Pv = get_single_block_p2s(&params[3], varargin_1, a);
  varargin_1[0] = params[18];
  varargin_1[1] = params[19];
  varargin_1[2] = params[20];
  varargin_1[3] = params[21];
  c_Pg = get_single_block_p2s(&params[3], varargin_1, a);
  varargin_1[0] = params[22];
  varargin_1[1] = params[23];
  varargin_1[2] = params[24];
  varargin_1[3] = params[25];
  c_Pc = get_single_block_p2s(&params[3], varargin_1, a);
  /*  Multiplicatório P(p) da união */
  /*  Pesos de suavização  */
  cost = u[0];
  for (k = 0; k < 24; k++) {
    tmp2 = cost;
    cost = u[(k + 1) << 1];
    b_a[k] = cost - tmp2;
  }
  for (k = 0; k <= 22; k += 2) {
    r = _mm_loadu_pd(&b_a[k]);
    _mm_storeu_pd(&f_y[k], _mm_mul_pd(r, r));
  }
  cost = u[1];
  for (k = 0; k < 24; k++) {
    b_tmp2 = cost;
    cost = u[((k + 1) << 1) + 1];
    b_a[k] = cost - b_tmp2;
  }
  for (k = 0; k <= 22; k += 2) {
    r = _mm_loadu_pd(&b_a[k]);
    _mm_storeu_pd(&g_y[k], _mm_mul_pd(r, r));
  }
  /*  Custo total */
  cost = ((((((((l_u + params[26] * sumColumnB(y)) +
                params[27] * (params[8] * params[8]) *
                    (v_s_tmp * v_s_tmp + w_s * w_s)) +
               params[29] *
                   (((sumColumnB(b_y) + sumColumnB(c_y)) + sumColumnB(d_y)) +
                    sumColumnB(e_y))) +
              params[28] * (P_next * P_k * v_n * w_n)) +
             params[28] * (Pa * Ts * xs_tmp * b_xs_tmp)) +
            params[28] * (b_Pa * Pv * Pg * Pc)) +
           params[28] * (c_Pa * b_Pv * b_Pg * b_Pc)) +
          params[28] * (d_Pa * c_Pv * c_Pg * c_Pc)) +
         (0.2 * b_sumColumnB(f_y) + 0.2 * b_sumColumnB(g_y));
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
  return cost;
}

/* End of code generation (wrapper_cost.c) */
