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
      "789ced54cb6ed340143d4605b12984052c586589908a94486cd8a1864808da826a242482"
      "8c1f93c48ded719d7149772cd9b1e10b58f11bfd807e02dfc02f7066"
      "6c27696094481565c344cebde73ecfcc5c1bcef33d07c02d54ebedcd4a6ed7b855cb6bb8"
      "b856fd8e4536eb3ab62ee435fe2fb50c65a6c44c5520f35331cf8c64",
      "1a677ea6dcd35ca01053999c88c878867122dc381587cb605fa3b4bfe49a03edd2faee58"
      "8493c33245319e2e1826cb607e1e9f9d3fef776bc3f3f86a398f3bb5"
      "7c503bdee119de63174f30c01b4cc1adf27f8031b58c7a4cfd809a40cfa0136a039c5117"
      "f0d14644d9864bec23e093305332e2292dc7284d8664c536faf486b4",
      "24ccf14dde80319259128a165dbd448a1d3e3e2d89a9b8c3dc9896d260c5d882790233a2"
      "1439adc2f04d199599de213d9ed9c98856bd0b45ac0cc309bd3a6e44"
      "4b8e2ea33c22c9a863d6f8686272fef429788c2a0cd347acd3dccb27cbb96f7a2ff72df7"
      "d25af107659c445e2103a9bc30187a62968b82b394d5a3daf0f97049",
      "3e37ac7c2a4f24cb20118b7edf2f3997df2cfd9ab9ecfd9fcbdfe632307c353f6f8999c7"
      "9c00434addb59ad9785e59cfac5eebe6e4f686f766fbbe6ea3fa70f7"
      "effe70aeb2df79f7e1cfabecd7ac7fd56f66a9b7e97b77cfd2afb5e23f7aec775e476ed9"
      "ddeb4c3a2f47a72f947b14f4163c5eade9b38e072cf86fd7ff05eed1",
      "c2a9",
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
                emlrtMxCreateString("WMaPswDAi1kL6kyURb75eG"));
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

/* End of code generation (_coder_wrapper_grad_info.c) */
