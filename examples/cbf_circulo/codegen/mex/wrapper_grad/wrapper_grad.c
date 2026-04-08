/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * wrapper_grad.c
 *
 * Code generation for function 'wrapper_grad'
 *
 */

/* Include files */
#include "wrapper_grad.h"
#include "rt_nonfinite.h"
#include "wrapper_grad_data.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = {
    2,              /* lineNo */
    "wrapper_grad", /* fcnName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws\\robotarium-matlab-"
    "simulator\\examples\\cbf_circulo\\wrapper_grad.m" /* pathName */
};

static emlrtECInfo emlrtECI = {
    -1,                         /* nDims */
    145,                        /* lineNo */
    9,                          /* colNo */
    "build_robot_cbf_circular", /* fName */
    "C:\\Users\\henri\\Desktop\\robotarium_ws\\robotarium-matlab-"
    "simulator\\examples\\cbf_circulo\\build_robot_cbf_circular.m" /* pName */
};

/* Function Definitions */
void wrapper_grad(const emlrtStack *sp, const real_T u[20],
                  const real_T params[9], real_T grad[20])
{
  emlrtStack st;
  real_T X_hist[33];
  real_T dv[9];
  real_T dv1[6];
  real_T dv2[3];
  real_T x_k[3];
  real_T dv3[2];
  real_T dv4[2];
  real_T R_obs;
  real_T d;
  real_T d1;
  real_T g_cbf_tmp;
  real_T multiplicador;
  real_T x_next_idx_0;
  real_T x_next_idx_1;
  real_T x_next_idx_2;
  int32_T n;
  int32_T v_n_tmp;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &emlrtRSI;
  /*  =========================================================================
   */
  /*  Algoritmo: Backward AD - Desvio de Obstáculo Circular (CBF) */
  /*  =========================================================================
   */
  x_k[0] = params[0];
  x_k[1] = params[1];
  x_k[2] = params[2];
  /*  Estado inicial x_0 */
  /*  Alvo [x; y] */
  /*  Centro do obstáculo circular */
  R_obs = params[7];
  /*  Raio do obstáculo */
  /*  Peso da penalidade (Barreira) */
  /*  --- Dimensões e Parâmetros da Barreira --- */
  /*  Raio do robô (margem de segurança) */
  /*  Distância mínima segura centro a centro */
  /*  Taxa de decaimento da CBF.  */
  /*  Nota: Geralmente 0 < gamma <= 1 em tempo discreto. Ajuste conforme
   * necessário. */
  memset(&X_hist[0], 0, 33U * sizeof(real_T));
  X_hist[0] = params[0];
  X_hist[1] = params[1];
  X_hist[2] = params[2];
  /*  ===================================================================== */
  /*  FORWARD PASS (Avaliação do Custo) */
  /*  ===================================================================== */
  for (n = 0; n < 10; n++) {
    v_n_tmp = n << 1;
    /*  1. Barreira no estado atual (h_k) */
    /*  Simula 1 passo da cinemática */
    multiplicador = 0.033 * u[v_n_tmp];
    x_next_idx_0 = x_k[0] + multiplicador * muDoubleScalarCos(x_k[2]);
    x_next_idx_1 = x_k[1] + multiplicador * muDoubleScalarSin(x_k[2]);
    x_next_idx_2 = x_k[2] + 0.033 * u[v_n_tmp + 1];
    /*  2. Barreira no estado futuro (h_{k+1}) */
    /*  3. Restrição de Barreira (g_k <= 0) */
    /*  g_k = (1 - gamma)*h_k - h_{k+1} */
    /*  4. Penalidade */
    /*  Custo de estágio normal */
    /*  Atualiza estado para o próximo passo */
    x_k[0] = x_next_idx_0;
    v_n_tmp = 3 * (n + 1);
    X_hist[v_n_tmp] = x_next_idx_0;
    x_k[1] = x_next_idx_1;
    X_hist[v_n_tmp + 1] = x_next_idx_1;
    x_k[2] = x_next_idx_2;
    X_hist[v_n_tmp + 2] = x_next_idx_2;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }
  /*  ===================================================================== */
  /*  TERMINAL E INICIALIZAÇÃO DO BACKWARD */
  /*  ===================================================================== */
  x_k[0] = 60.0 * (X_hist[30] - params[3]);
  x_k[1] = 60.0 * (X_hist[31] - params[4]);
  x_k[2] = 0.0;
  /*  ===================================================================== */
  /*  BACKWARD PASS (Método Adjunto) */
  /*  ===================================================================== */
  memset(&grad[0], 0, 20U * sizeof(real_T));
  d = params[5];
  d1 = params[6];
  g_cbf_tmp = (R_obs + 0.5) * (R_obs + 0.5);
  dv[0] = 1.0;
  dv[1] = 0.0;
  dv[3] = 0.0;
  dv[4] = 1.0;
  dv[6] = 0.0;
  dv[7] = 0.0;
  dv[8] = 1.0;
  dv1[4] = 0.0;
  dv1[1] = 0.0;
  dv1[3] = 0.0;
  dv1[5] = 0.033;
  for (n = 0; n < 10; n++) {
    __m128d r;
    __m128d r1;
    __m128d r2;
    __m128d r3;
    __m128d r4;
    real_T d2;
    real_T d3;
    real_T dx_k;
    real_T dx_next;
    real_T dy_k;
    real_T dy_next;
    real_T grad_x_next_cbf_idx_0;
    real_T grad_x_next_cbf_idx_1;
    real_T grad_x_next_cbf_idx_2;
    real_T v_n;
    int32_T b_v_n_tmp;
    int32_T dx_next_tmp;
    /*  Estado atual (p_k) */
    /*  Estado futuro (p_{k+1}) */
    b_v_n_tmp = (9 - n) << 1;
    v_n = u[b_v_n_tmp];
    /*  1. Recalcular a Violação da Barreira */
    v_n_tmp = 3 * (9 - n);
    d2 = X_hist[v_n_tmp];
    dx_k = d2 - d;
    d3 = X_hist[v_n_tmp + 1];
    dy_k = d3 - d1;
    dx_next_tmp = 3 * (10 - n);
    dx_next = X_hist[dx_next_tmp] - d;
    dy_next = X_hist[dx_next_tmp + 1] - d1;
    R_obs = 0.7 * ((dx_k * dx_k + dy_k * dy_k) - g_cbf_tmp) -
            ((dx_next * dx_next + dy_next * dy_next) - g_cbf_tmp);
    x_next_idx_0 = 0.0;
    grad_x_next_cbf_idx_0 = 0.0;
    x_next_idx_1 = 0.0;
    grad_x_next_cbf_idx_1 = 0.0;
    x_next_idx_2 = 0.0;
    grad_x_next_cbf_idx_2 = 0.0;
    /*  2. Gradientes da Barreira (Apenas se violada) */
    if (R_obs > 0.0) {
      /*  Derivadas de h em relação aos estados x e y */
      /*  Derivadas de g = (1-gamma)*h_k - h_{k+1} */
      /*  Aplica a Regra da Cadeia: dP/dx = 2 * eta * g * dg/dx */
      multiplicador = 2.0 * params[8] * R_obs;
      x_next_idx_0 = multiplicador * (0.7 * (2.0 * dx_k));
      x_next_idx_1 = multiplicador * (0.7 * (2.0 * dy_k));
      x_next_idx_2 = multiplicador * 0.0;
      grad_x_next_cbf_idx_0 = multiplicador * -(2.0 * dx_next);
      grad_x_next_cbf_idx_1 = multiplicador * -(2.0 * dy_next);
      grad_x_next_cbf_idx_2 = multiplicador * -0.0;
    }
    /*  3. Propagação pelo Adjunto */
    /*  Gradiente total em relação ao estado atual */
    /*  Jacobianas Cinemáticas */
    multiplicador = X_hist[v_n_tmp + 2];
    R_obs = muDoubleScalarCos(multiplicador);
    multiplicador = muDoubleScalarSin(multiplicador);
    /*  Atualiza as variáveis co-estado para o próximo passo da iteração reversa
     */
    grad_x_next_cbf_idx_0 += x_k[0];
    grad_x_next_cbf_idx_1 += x_k[1];
    grad_x_next_cbf_idx_2 += x_k[2];
    dv[2] = -0.033 * v_n * multiplicador;
    dv[5] = 0.033 * v_n * R_obs;
    memset(&x_k[0], 0, 3U * sizeof(real_T));
    r = _mm_loadu_pd(&dv[0]);
    r1 = _mm_loadu_pd(&x_k[0]);
    r2 = _mm_set1_pd(grad_x_next_cbf_idx_0);
    _mm_storeu_pd(&x_k[0], _mm_add_pd(r1, _mm_mul_pd(r, r2)));
    x_k[2] += dv[2] * grad_x_next_cbf_idx_0;
    r = _mm_loadu_pd(&dv[3]);
    r1 = _mm_loadu_pd(&x_k[0]);
    r3 = _mm_set1_pd(grad_x_next_cbf_idx_1);
    _mm_storeu_pd(&x_k[0], _mm_add_pd(r1, _mm_mul_pd(r, r3)));
    x_k[2] += dv[5] * grad_x_next_cbf_idx_1;
    r = _mm_loadu_pd(&dv[6]);
    r1 = _mm_loadu_pd(&x_k[0]);
    r4 = _mm_set1_pd(grad_x_next_cbf_idx_2);
    _mm_storeu_pd(&x_k[0], _mm_add_pd(r1, _mm_mul_pd(r, r4)));
    x_k[2] += grad_x_next_cbf_idx_2;
    dv2[0] = 60.0 * (d2 - params[3]) + x_next_idx_0;
    dv2[1] = 60.0 * (d3 - params[4]) + x_next_idx_1;
    dv2[2] = x_next_idx_2;
    r = _mm_loadu_pd(&x_k[0]);
    r1 = _mm_loadu_pd(&dv2[0]);
    _mm_storeu_pd(&x_k[0], _mm_add_pd(r, r1));
    x_k[2] += x_next_idx_2;
    /*  Salva o gradiente do controle no vetor final */
    v_n_tmp = (10 - n) << 1;
    if (b_v_n_tmp + 1 > v_n_tmp) {
      dx_next_tmp = 0;
      v_n_tmp = 0;
    } else {
      dx_next_tmp = b_v_n_tmp;
    }
    v_n_tmp -= dx_next_tmp;
    if (v_n_tmp != 2) {
      emlrtSubAssignSizeCheck1dR2017a(v_n_tmp, 2, &emlrtECI, &st);
    }
    dv1[0] = 0.033 * R_obs;
    dv1[2] = 0.033 * multiplicador;
    memset(&dv3[0], 0, sizeof(real_T) << 1);
    r = _mm_loadu_pd(&dv1[0]);
    r1 = _mm_loadu_pd(&dv3[0]);
    _mm_storeu_pd(&dv3[0], _mm_add_pd(r1, _mm_mul_pd(r, r2)));
    r = _mm_loadu_pd(&dv1[2]);
    r1 = _mm_loadu_pd(&dv3[0]);
    _mm_storeu_pd(&dv3[0], _mm_add_pd(r1, _mm_mul_pd(r, r3)));
    r = _mm_loadu_pd(&dv1[4]);
    r1 = _mm_loadu_pd(&dv3[0]);
    _mm_storeu_pd(&dv3[0], _mm_add_pd(r1, _mm_mul_pd(r, r4)));
    dv4[0] = 0.02 * v_n;
    dv4[1] = 0.02 * u[b_v_n_tmp + 1];
    r = _mm_loadu_pd(&dv3[0]);
    r1 = _mm_loadu_pd(&dv4[0]);
    _mm_storeu_pd(&grad[dx_next_tmp], _mm_add_pd(r, r1));
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }
}

/* End of code generation (wrapper_grad.c) */
