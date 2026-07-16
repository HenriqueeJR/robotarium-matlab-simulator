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
      "4b8e2ea33c22c9a863d6f8686272fef429788cd5cc151eb14e732f9f2ce7bee9bddcb7dc"
      "4b6bc51f94711279850ca4f2c260e889592e0ace52568f6ac3e7c325",
      "f9dcb0f2a93c912c83442cfa7dbfe45c7eb3f46be6b2f77f2e7f9bcbc0f0d5fcbc25667a"
      "3e030c2975d76a66e379653db37aad9b93db1bde9bedfbba8deac3dd"
      "bffbc3b9ca7ee7dd873fafb25fb3fe55bf99a5dea6efdd3d4bbfd68affe8b1df791db965"
      "77af33e9bc1c9dbe50ee51d05bf078b5a6cf3a1eb0e0bf5dff178ac2",
      "c2c4",
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
                emlrtMxCreateString("WMaPswDAi1kL6kyURb75eG"));
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

/* End of code generation (_coder_wrapper_cost_info.c) */
