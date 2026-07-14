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
      "789ced543d6fd340187e5c95aa4b210889a1534696228410aad8a069a554b4546a909008"
      "32feb834566c9feb9c4bcad4918d85b943277e0062e71ff007f82f3c"
      "77b69334704aa4aa65e122e77d9ff7f3b9bbd786d3de7300dc46b9deac9672adc28d4a2e"
      "e1f29af53b1659af5b58be9457fb3f573290a912235582d44bc43833",
      "9449947aa9ea9c6602b918caf84484c6d38b62d1891271380df6354a76a65c63a05d5adf"
      "ea8b60705824c8fbc309c3781a8ccfe393f3f7fd2e2f781e5f2ce771"
      "b7920f2ac75b6ce31db6f00c5dbcc610dc2affbbe8534ba947d45f511368197442ad8b1f"
      "d4053c34115236d121f6e0f389992919f19c9663142643b262133bf4",
      "06b4c4ccf14c5e97319259128a165dbd40820d3e1e2db1a9b8c1dc8896c260c5d89c7902"
      "23a20419adc2f04d18959ade013daed9c911ad7a178a581986037a75"
      "dc112d191e33ca25928c3a668d0f2626e34f9f82cba8dc307dc83af5bd9c59ce7dd17b59"
      "b7dc4b63c6ef17511cbab9f4a57203bfe78a512672ce525a8d6acde7",
      "fd15f9ac58f9949e50167e2c26fdbe5e712e2f2cfdeab96cfd9fcb3fe6d2377c353f778a"
      "99cb1c1f3d4addb59cd9685c59cfac5ef3e6e4ce82f766fbbeaea1fc"
      "707fbbf7cbb9c97ee7df577ede64bf7afdab7e234bbd45dfbbfb967e8d19bf7a59f8c58b"
      "cd47ed8f07a74f77db4f42b9d71fb4263c0ee6f499c703167cddf57f",
      "03590ac353",
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
