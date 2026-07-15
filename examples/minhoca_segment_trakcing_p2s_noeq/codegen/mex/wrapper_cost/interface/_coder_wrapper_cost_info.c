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
      "789ced54cb6ed340143d4605b169091262c12a4b36ad104208b183864a81bea406098920"
      "e3c7a4b1627b5c67dca6ac58b2eba65fd06efa0b5df2217c075bce8c"
      "ed240d8c12a9a26c98c8b9f7dce799996bc3696f39005650ae0f774bb95ce146256fe1ea"
      "9af53b1659afdb58ba9257fb4f2a19c85489912a41ea25629c19ca24",
      "4abd54758e33815c0c657c2842e3e945b1e84489d89b06db1a251b53ae31d02eadaff745"
      "30d82b12e4fde184613c0dc6e7f1cdf9f37e97163c8f53cb79dcafe4"
      "e3caf1116ff009eb78892ede63086e95ff5df4a9a5d423ea3bd4045a061d52ebe23b7501"
      "0f4d84944d74883df87c62664a46bca2e50085c990acd8c406bd012d",
      "31733c93d7658c649684a245572f9060958f474b6c2aae3237a2a530583136679ec08828"
      "4146ab307c1346a5a677408f6b76b24fabde85225686e1805e1db74f"
      "4b86a78c728924a30e58e3c8c464fce9537019ab992bacb14e7d2f5f2de7bee8bd3cb2dc"
      "4b63c6ef17511cbab9f4a57203bfe78a512672ce525a8d6acde7f335",
      "f9dcb1f2293da12cfc584cfa5d5c732ecf2cfdeab96cfd9fcbdfe6d2377c353f778a999e"
      "4f1f3d4addb59cd9685c59cfac5ef3e6e4de82f766fbbe2ea3fc70f7"
      "1efc706eb2dff9cfcb7737d9af5effaadfc8526fd1f7eea1a55f63c6af360bbf78fde249"
      "fbcbeef1f3b7ed67a1dcea0f5a131ebb73facce3010bfedbf57f0128",
      "82c395",
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
