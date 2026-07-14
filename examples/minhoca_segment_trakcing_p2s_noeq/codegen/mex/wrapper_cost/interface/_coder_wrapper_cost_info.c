/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_wrapper_cost_info.c
 *
 * Code generation for function 'wrapper_cost'
 *
 */

/* Include files */
#include "_coder_wrapper_cost_info.h"
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
      "dc112d191e33ca25928c3a668d0f2626e34f9f82cb58cd5ce121ebd4f7726639f745ef65"
      "dd722f8d19bf5f4471e8e6d297ca0dfc9e2b4699c8394b6935aa359f",
      "f757e4b362e5537a4259f8b198f4fb7ac5b9bcb0f4abe7b2f57f2eff984bdff0d5fcdc29"
      "667a3e7df42875d77266a371653db37acd9b933b0bde9bedfbba86f2"
      "c3fdedde2fe726fb9d7f5ff97993fdeaf5affa8d2cf5167defee5bfa3566fcea65e1172f"
      "361fb53f1e9c3edd6d3f09e55e7fd09af03898d3671e0f58f075d7ff",
      "0df4ecc36e",
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
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("wrapper_cost"));
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
          "trakcing_p2s_noeq\\wrapper_cost.m"));
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

/* End of code generation (_coder_wrapper_cost_info.c) */
