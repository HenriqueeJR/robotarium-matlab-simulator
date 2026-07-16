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
      "789ced543d6fd340187e8c0a6229840106a68c2c458809b1414311a0d24a0d028920e38f"
      "4be3d6e7739c736b9818d9baf41774e26ff04318f91f3c77b6933470"
      "4aa48ab27091f3becffbf9dcdd6bc37bb1ed01b8817abdbb5ecbf506771a7905e7d7a2df"
      "73c8765dc5dab9bcd67fd2c848655a54ba065920c534335632c9824c",
      "f73fe5028598a8f448c4d6334c52d14fa4d89b07af0d925b73ae29302ea36f8e4474b857"
      "4a14a3c98c613a0fa6e7f1d5fbf37ed7563c8f53c779dc6ae4bdc6f1"
      "1ecff0019b788c01de60026e95ff038ca865d413ea3bd4047a161d511be03b7581005dc4"
      "945df48903847c52662a463ca1658cd2662856ec628bde8896943981",
      "cd1b3046314b41d362aa9790d8e013d092da8a1bcc4d68292dd68c2d9827501149e4b40a"
      "cb57322ab3bd237a7cbb937d5acd2e34b1b60c0fe93571fbb4e478c8"
      "289f48316acc1ac73626e7cf9c82cf58c35ce33eebb4f7f2c571eeabdecb5dc7bd7416fc"
      "6199a4b15fa850693f0a87bea872517096b266545b3e1f2fc8e79a93",
      "4fed895519a662d6efdb05e7f2ccd1af9dcbdeffb9fc6d2e43cbd7f0f3e79899f90c31a4"
      "345deb994da695cdcc9ab56c4e6eae786faeefeb3aea0f77eff60fef"
      "32fb9d3cfa292fb35fbbfe55bfca516fd5f7ee8ea35f67c1af7772fdf955598dc3dd83e1"
      "83a7bd8397d9f8edf3198fdd257d96f18003ffedfabf0049afc3ac",
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
                emlrtMxCreateString("lN7oOOXjNlWp3N90jU6KZH"));
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

/* End of code generation (_coder_wrapper_cost_info.c) */
