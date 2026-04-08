/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_wrapper_cost_mex.c
 *
 * Code generation for function '_coder_wrapper_cost_mex'
 *
 */

/* Include files */
#include "_coder_wrapper_cost_mex.h"
#include "_coder_wrapper_cost_api.h"
#include "rt_nonfinite.h"
#include "wrapper_cost_data.h"
#include "wrapper_cost_initialize.h"
#include "wrapper_cost_terminate.h"

/* Function Definitions */
void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  mexAtExit(&wrapper_cost_atexit);
  wrapper_cost_initialize();
  wrapper_cost_mexFunction(nlhs, plhs, nrhs, prhs);
  wrapper_cost_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2022a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
                           NULL, "windows-1252", true);
  return emlrtRootTLSGlobal;
}

void wrapper_cost_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
                              const mxArray *prhs[2])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *outputs;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 2, 4,
                        12, "wrapper_cost");
  }
  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 12,
                        "wrapper_cost");
  }
  /* Call the function. */
  wrapper_cost_api(prhs, &outputs);
  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, &plhs[0], &outputs);
}

/* End of code generation (_coder_wrapper_cost_mex.c) */
