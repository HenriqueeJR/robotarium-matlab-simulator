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
  const char_T *data[6] = {
      "789ced54cb6ed340143d462d62d31224c48255966c5a5515aa103b68a814a0a552835489"
      "20d78f4963c5f6b8ceb8a4ac58b2eb862f800dbfc0920fe13bbae5cc"
      "d84ed294512255940d1339f79efb3c33736d38ed5d07c02aca7578a7942b156e54f2162e"
      "af59bf6391f55ac6d2a5bcda7f5ec940a64a8c5409522f11e3cc5026",
      "51eaa5aa739609e46228e353111a4f2f8a45274ac4c134d8d328d999728d8176697dbb2f"
      "82c1419120ef0f270ce369303e8fcfce9ff7bbb4e0797cb19cc7bd4a"
      "3eaa1ceff002efb18da7e8e22d86e056f9df459f5a4a3da2fe869a40cba0536a5dfca42e"
      "e0a18990b2890eb1079f4fcc4cc98867b49ca0301992159bd8a137a0",
      "25668e67f2ba8c91cc9250b4e8ea0512acf1f168894dc535e646b414062bc6e6cc131811"
      "25c86815866fc2a8d4f40ee871cd4e8e69d5bb50c4ca301cd0abe38e"
      "69c9b0c928974832ea84353e98988c3f7d0a2ea372c3749d75ea7bf96439f745efe5a1e5"
      "5e1a337ebf88e2d0cda52f951bf83d578c32917396d26a546b3e47d7",
      "e473dbcaa7f484b2f06331e9f7fd9a73f9d5d2af9ecbd6ffb9bc3297bee1abf9b953cc5c"
      "e6f8e851eaaee5cc46e3ca7a66f59a37277717bc37dbf77505e587bb"
      "77ff977393fdbe5dfc787593fdeaf5affa8d2cf5167def1e58fa3566fcea75e117cf9f6c"
      "b43fee9f6dbd6c3f0ee56e7fd09af0d89fd3671e0f58f0dfaeff1b8c",
      "91c37a",
      ""};
  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(&data[0], 2160U, &nameCaptureInfo);
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
          "trakcing_p2s_noeq\\wrapper_grad.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp",
                emlrtMxCreateDoubleScalar(740172.82792824076));
  xResult =
      emlrtCreateStructMatrix(1, 1, 7, (const char_T **)&propFieldName[0]);
  emlrtSetField(xResult, 0, "Version",
                emlrtMxCreateString("9.14.0.2206163 (R2023a)"));
  emlrtSetField(xResult, 0, "ResolvedFunctions",
                (mxArray *)emlrtMexFcnResolvedFunctionsInfo());
  emlrtSetField(xResult, 0, "Checksum",
                emlrtMxCreateString("i8fug5VhUnHgvg07qPMKfH"));
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

/* End of code generation (_coder_wrapper_grad_info.c) */
