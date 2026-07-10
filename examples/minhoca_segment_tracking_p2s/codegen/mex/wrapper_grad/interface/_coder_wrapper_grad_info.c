/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_wrapper_grad_info.c
 *
 * Code generation for function 'wrapper_grad'
 *
 */

/* Include files */
#include "_coder_wrapper_grad_info.h"
#include "emlrt.h"
#include "tmwtypes.h"

/* Function Declarations */
static const mxArray *emlrtMexFcnResolvedFunctionsInfo(void);

/* Function Definitions */
static const mxArray *emlrtMexFcnResolvedFunctionsInfo(void)
{
  const mxArray *nameCaptureInfo;
  const char_T *data[5] = {
      "789ced54cd6ed34010fe8c0ae25208170e2095bc409140c0a13754da82042528299520c8"
      "f867d358ddf51ac70ee1c61bf4099078005e8207e15df8766d276ec4"
      "2a912aca85899c996fbe999dd9ddb1e1bd78e501b8814a9e5faff4668d3bb5be82f3b2cc"
      "7b0eddc8556c9ccb6bf8b35a473a2dc4aca8401a2831cf8cb54ad220",
      "2d065f32815c4cb49c8ad832a3448a41a244bf0d0e0d52fb2d6a0e0c65ecddb1884efba5"
      "423e9e2c3a946d303f8fafde9ff7bbb1e6799c2de1466ed57aab26de"
      "630f1fb08b1d0c718409b855fe0f31a695d24e68bfa625f0cca229ad217ed21608d0454c"
      "ddc5803840c847325333e2293d9f50da0ccd15bbd8271bd1239913d8",
      "bc216334b3340a7accea2514b6f904f448bbe23673137a4a8b0bc6e6cc1398112964f40a"
      "dbaf62546a6b47647cbb93137acd2e0ae2c27618e1d4c69dd093e1a1"
      "cdfc6c998c3fb3779f5c6efbbbcfecd67d38ce7bddfbb8e3b88fce121f96898cfd5c87ba"
      "f0a370e48b592672ce505a8f68d3cfc70bf673cdd94fc5c4ba0ca558",
      "d4fb7ec179fce6a8d7cce3ceff79ace731b45d9aaefc563f3e63438ca84dad6a5693f97a"
      "d5ac1a59351f37d7bc2fd7f77413d587fa47e7977799f5ee6ef5ef5d"
      "66bd46fe55bd9963bd75dfb7db8e7a9d255e1e076fdef61e1cbf54d3f8f1e1d1bb278ff6"
      "7ac9c1a28fde8a3aabfa8003ffedf57f035b79bd08",
      ""};
  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(&data[0], 2144U, &nameCaptureInfo);
  return nameCaptureInfo;
}

mxArray *emlrtMexFcnProperties(void)
{
  mxArray *xEntryPoints;
  mxArray *xInputs;
  mxArray *xResult;
  const char_T *propFieldName[7] = {
      "Version",      "ResolvedFunctions", "Checksum",    "EntryPoints",
      "CoverageInfo", "IsPolymorphic",     "PropertyList"};
  const char_T *epFieldName[6] = {
      "Name",           "NumberOfInputs", "NumberOfOutputs",
      "ConstantInputs", "FullPath",       "TimeStamp"};
  xEntryPoints =
      emlrtCreateStructMatrix(1, 1, 6, (const char_T **)&epFieldName[0]);
  xInputs = emlrtCreateLogicalMatrix(1, 2);
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("wrapper_grad"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(2.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 0, "FullPath",
      emlrtMxCreateString(
          "C:\\Users\\henri\\OneDrive\\\xc3\x81rea de Trabalho\\Arquivos "
          "Faculdade\\robotarium-matlab-simulator\\examples\\minhoca_segment_"
          "tracking_p2s\\wrapper_grad.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp",
                emlrtMxCreateDoubleScalar(740172.82792824076));
  xResult =
      emlrtCreateStructMatrix(1, 1, 7, (const char_T **)&propFieldName[0]);
  emlrtSetField(xResult, 0, "Version",
                emlrtMxCreateString("9.14.0.2206163 (R2023a)"));
  emlrtSetField(xResult, 0, "ResolvedFunctions",
                (mxArray *)emlrtMexFcnResolvedFunctionsInfo());
  emlrtSetField(xResult, 0, "Checksum",
                emlrtMxCreateString("LYJwNmXF23JfD4vahd6O7D"));
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

/* End of code generation (_coder_wrapper_grad_info.c) */
