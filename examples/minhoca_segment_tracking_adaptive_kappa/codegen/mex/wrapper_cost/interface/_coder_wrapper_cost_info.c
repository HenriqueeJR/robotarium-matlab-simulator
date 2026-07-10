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
      "789ced54cb6ed340143d4605b1290d4262c102e5078a10484874578556a9100529010911"
      "64fc9834563d1ee38c4bca8a3fe8862d129f021fc22fb063cf99b19d"
      "b811a344aa281b6ee4dc7bee63ee99996bc33b78e601b8814afad72bbd59e34eadafe0bc"
      "2cc73d876ee42a36ced535f1b35a472ad362a62b900552cc2b632593",
      "2cc8f4f0341728c454a52722b69171928a6122c5a00d0e0d92fbadd01c9890b17b13111d"
      "0f4a8962325d304cdb607e1e9fbc3fef7763cdf3385bc28ddcacf5dd"
      "3af0067b788b1e7630c24b4cc1adf27f8409ad8c7642fb392d8127169dd01ae13b6d8100"
      "5dc4d45d0c8903847c52562a66ecd2f31ea5ad505cb18b7d46237a52",
      "d604b66ec41cc52a054d8f59bd84c4369f809ed4aeb8cdda849ed262cddc827502332289"
      "9c5e61f94a6665b677c4886f777244afd98526d6966184639b77444f"
      "8e07b6f2838de4fc99bdfbcc317c35eeb1ba751f8ef35ef73eee38eea3b3140fcb248dfd"
      "42854afb5138f6c52c17056728ab47b4e1f3ee827cae39f954915895",
      "612a16fdbe5e701ebf38fa35f3b8f37f1eeb790c2d4bc3ca6ff1317319624c6d7a55b39a"
      "ccd7ab66d5c8aaf9d85af3be5cdfd34d541fea5f5b3fbccbec77ebe7"
      "b7cf97d9af917fd56fe6586fddf7edb6a35f67292e9e3e7ea8e38ffdfb714f3e7a150f86"
      "93ddfeebbd058f172bfaace20107fedbebff0659e6bf1e",
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
                emlrtMxCreateString("Aok7mXqkWgTl4kAQxIAEx"));
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

/* End of code generation (_coder_wrapper_cost_info.c) */
