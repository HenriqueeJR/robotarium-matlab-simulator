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
      "789ced54cb6ed340143d8682d814c20216acb2645384902a213615f41190cab341542295"
      "f163d2b8b53d8e336edd1d4b766cf80256acf8073e847fe1ccd84ed2"
      "d0512255b41b2672ee3df77966e6da705ebc7400dc44b5766f5472b9c6ad5a5ec1e935eb"
      "772cb259d7b0742aaff17fad652053254a5581d44bc438339449947a",
      "a9ea9e6402b918c9f84884c6d38f62d18d12b1330d5e69946c4db9c640bbb4be3e10c1e1"
      "4e91201f8c260ce369303e8f2fced9fb5d5af03cbe59cee3762defd7"
      "8e8fd8c41ed6f1043dbcc708dc2aff7b18504ba947d45f5313d830e8885a0fbfa80b7868"
      "23a46ca34becc1e713335332e2292d43142643b2621b5bf406b4c4cc",
      "f14c5e8f319259128a165dbd4082153e1e2db1a9b8c2dc8896c260c5d89c79022551828c"
      "5661f8268c4a4def801ed7ec649f56bd0b45ac0cc3437a75dc3e2d19"
      "1e31ca25928c1ab2c6b189c9f8d3a7e0322a374c1fb04e732f9f2de7bee8bddcb3dc4b6b"
      "c6ef17511cbab9f4a57203bfef8a3213396729ad47b5e1f3e99c7cae",
      "5bf9549e50167e2c26fd7e9c732ebf5bfa3573b9f17f2eff9a4bdff0d5fcdc29662e737c"
      "f42975d76a66a371653db37acd9b935b0bde9bedfbba8ceac3bd76e7"
      "b77391fd86577fbebdc87ecdbaac7ea5a5dea2efdd5d4bbfd68cbf5c7d1c6eae1ea893fe"
      "b3dd77a2f3f0a0d3f9b0fd7cc2e3cd9c3ef378c082ff75fd3f5faac1",
      "de",
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
                emlrtMxCreateString("uzZqjtuEmciNkxoWtqDdBF"));
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

/* End of code generation (_coder_wrapper_grad_info.c) */
