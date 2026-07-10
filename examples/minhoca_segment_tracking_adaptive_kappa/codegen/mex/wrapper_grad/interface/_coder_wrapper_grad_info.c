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
      "789ced54cd6ed34010fe8c0ae2521a84c48103ca0b14219090e8ad0aad52210a52021222"
      "c8f867d358f57a8db32e2927dea017ae483c0a3c08afc08d3bdfaeed"
      "c48d58255245b9309133f3cd37b333bb3b36bc83671e801ba8a47fbdd29b35eed4fa0ace"
      "cb32ef39742357b1712eafe1cf6a1da94c8b99ae40164831cf8c954c",
      "b220d3c3d35ca01053959e88d832e32415c3448a411b1c1a24f75bd41c18cad8bd89888e"
      "07a54431992e3a4cdb607e1e9fbc3fef7763cdf3385bc28ddcacf5dd"
      "9a78833dbc450f3b18e125a6e056f93fc28456463ba1fd9c96c0138b4e688df09db64080"
      "2e62ea2e86c401423e2933152376e9798fd26628aed8c53ed9889e94",
      "3981cd1b3146314b41d363562f21b1cd27a027b52b6e3337a1a7b45833b6609ec08c4822"
      "a757d87e25a3325b3b22e3db9d1cd16b76a189b5ed30c2b18d3ba227"
      "c7039bf9c132397f66ef3eb9c2f6778fd9adfb709cf7baf771c7711f9d253e2c9334f60b"
      "152aed47e1d817b35c149ca1ac1ed1a69f7717ece79ab39f8a895519",
      "a66251efeb05e7f18ba35e338f3bffe7b19ec7d07669baf25bfdf88c0d31a636b5aa594d"
      "e6eb55b36a64d57c6cad795faeefe926aa0ff5afad1fde65d6bbf5f3"
      "dbe7cbacd7c8bfaa3773acb7eefb76db51afb3c48ba78f1feaf863ff7edc938f5ec583e1"
      "64b7ff7a6fd1c78b157556f50107fedbebff06be97bf03",
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
                emlrtMxCreateString("Aok7mXqkWgTl4kAQxIAEx"));
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

/* End of code generation (_coder_wrapper_grad_info.c) */
