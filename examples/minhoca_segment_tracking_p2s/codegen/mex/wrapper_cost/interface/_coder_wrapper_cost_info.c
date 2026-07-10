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
  const char_T *data[5] = {
      "789ced544d6ed34014fe8c0a6253081b1620955ca0482060d11d2a6d41821294944a1064"
      "fc3369ac8e3dc61987b0e3063d011207e0121c84bbf0cdd84edc8851"
      "2255940d2f72defbdecfbc6f669e0defc52b0fc00d54f2fc7aa5376bdca9f5159c97e5b8"
      "e7d08d5cc5c6b9ba267e56eb48655acc7405b22015f3ca58a5491664",
      "7af0251728c444c9a9886d649448314852d16f834383d2fd56680e4cc8d8bb63119df6cb"
      "14c578b26028db607e1e5fbd3fef7763cdf3385bc28ddcaaf5561d78"
      "8f3d7cc02e7630c41126e056f93fc49856463ba1fd9a96c0338ba6b486f8495b20401731"
      "751703e200211fc94ac58ca7f47c42692b1457ec629fd1881ec99ac0",
      "d60d99a358a5a0e931ab9748b1cd27a047da15b7599bd0535aac995bb04e60469422a757"
      "58be29b332db3b62c4b73b39a1d7ec42136bcb30c2a9cd3ba127c743"
      "5bf9d94672feccde7de618be1af759ddba0fc779af7b1f771cf7d1598a87652263bf50a1"
      "d27e148e7c31cb45c119caea116df87cbc209f6b4e3e5524566528c5",
      "a2dff70bcee33747bf661e77fecf633d8fa1656958f92d3e662e438ca84daf6a5693f97a"
      "d5ac1a59351f37d7bc2fd7f77413d587fa47e7977799fdee6ef5ef5d"
      "66bf46fe55bf9963bd75dfb7db8e7e9da5b83c0edebced3d387e994ee3c78747ef9e3cda"
      "eb25070b1ebd157d56f18003ffedf57f03f6b9bd23",
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
          "tracking_p2s\\wrapper_cost.m"));
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

/* End of code generation (_coder_wrapper_cost_info.c) */
