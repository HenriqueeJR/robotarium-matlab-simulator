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
static const mxArray *c_emlrtMexFcnResolvedFunctionsI(void);

/* Function Definitions */
static const mxArray *c_emlrtMexFcnResolvedFunctionsI(void)
{
  const mxArray *nameCaptureInfo;
  const char_T *data[5] = {
      "789cdd95cf4bdc4014c727a2c583b69e7a6829bd172c4a05d9f65068ea8f0a2ea5aeb0ab"
      "9138499edd61e797331377ad174f8227fb8ff5de430ffe0385fe09ba"
      "bbc96e1218222e44eabbbcbc7c67e633ef4df206395fb61d84d05334b4af73433f9fc40b"
      "899f42792bea4e619c931f8e66d0746e5eaa5f253e14dc40cf0c038e",
      "198c664682118eb9699c4a400ab4a027100d942342a14118ec64837a3f62eb196914f4a5"
      "feb3db86b0b31333a4da7abc439a0d46f538b4e43b5d528fa215eb51"
      "1c97f2e43d79e9fa7325bc54ef2a2c25283f14da64f98713f29f58f9432512714061ccbb"
      "9e907766e5e5f5fdb503f7bdb7ab4169af0d5c11ef33e88e11d25322",
      "10062b1233bfab7d41a3cc9b45860dc5c1a2262ca6d808e5410f3349417b6170e4872afe"
      "e177f1a914841bed1b85c30ee1dfbd6c71dfb201bfacbecfee986fd1"
      "8fc7cf0efccbdf7f9c2a79e73f7fbdaa9297da43f17a96f5eefabd3eb7f0160afaf25ef4"
      "a9f5add56cd69a4bddadfa166cb41b6b9b993e5dc229db07b2c455ad",
      "7f6d99ff58fffbf309f37d51926faa0731a1913fc8c4ef6f157ab71bbabdfb7872b53e54"
      "9fff3721efd2cacbeb959eb7bdd8c9e957d7a73efcadb6efbff9f8fa"
      "a24a5e6a8fbdefbb2b27f5cd9abb5a73975bee8a7cc765e77869e3ffeffb37c86bff9b",
      ""};
  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(&data[0], 3176U, &nameCaptureInfo);
  return nameCaptureInfo;
}

mxArray *emlrtMexFcnProperties(void)
{
  mxArray *xEntryPoints;
  mxArray *xInputs;
  mxArray *xResult;
  const char_T *epFieldName[7] = {
      "QualifiedName",    "NumberOfInputs", "NumberOfOutputs", "ConstantInputs",
      "ResolvedFilePath", "TimeStamp",      "Visible"};
  const char_T *propFieldName[7] = {
      "Version",      "ResolvedFunctions", "Checksum", "EntryPoints",
      "CoverageInfo", "IsPolymorphic",     "AuxData"};
  uint8_T v[216] = {
      0U,   1U,   73U,  77U,  0U,   0U,   0U,   0U,   14U,  0U,   0U,   0U,
      200U, 0U,   0U,   0U,   6U,   0U,   0U,   0U,   8U,   0U,   0U,   0U,
      2U,   0U,   0U,   0U,   0U,   0U,   0U,   0U,   5U,   0U,   0U,   0U,
      8U,   0U,   0U,   0U,   1U,   0U,   0U,   0U,   1U,   0U,   0U,   0U,
      1U,   0U,   0U,   0U,   0U,   0U,   0U,   0U,   5U,   0U,   4U,   0U,
      17U,  0U,   0U,   0U,   1U,   0U,   0U,   0U,   17U,  0U,   0U,   0U,
      67U,  108U, 97U,  115U, 115U, 69U,  110U, 116U, 114U, 121U, 80U,  111U,
      105U, 110U, 116U, 115U, 0U,   0U,   0U,   0U,   0U,   0U,   0U,   0U,
      14U,  0U,   0U,   0U,   112U, 0U,   0U,   0U,   6U,   0U,   0U,   0U,
      8U,   0U,   0U,   0U,   2U,   0U,   0U,   0U,   0U,   0U,   0U,   0U,
      5U,   0U,   0U,   0U,   8U,   0U,   0U,   0U,   1U,   0U,   0U,   0U,
      0U,   0U,   0U,   0U,   1U,   0U,   0U,   0U,   0U,   0U,   0U,   0U,
      5U,   0U,   4U,   0U,   14U,  0U,   0U,   0U,   1U,   0U,   0U,   0U,
      56U,  0U,   0U,   0U,   81U,  117U, 97U,  108U, 105U, 102U, 105U, 101U,
      100U, 78U,  97U,  109U, 101U, 0U,   77U,  101U, 116U, 104U, 111U, 100U,
      115U, 0U,   0U,   0U,   0U,   0U,   0U,   0U,   80U,  114U, 111U, 112U,
      101U, 114U, 116U, 105U, 101U, 115U, 0U,   0U,   0U,   0U,   72U,  97U,
      110U, 100U, 108U, 101U, 0U,   0U,   0U,   0U,   0U,   0U,   0U,   0U};
  xEntryPoints =
      emlrtCreateStructMatrix(1, 1, 7, (const char_T **)&epFieldName[0]);
  xInputs = emlrtCreateLogicalMatrix(1, 2);
  emlrtSetField(xEntryPoints, 0, "QualifiedName",
                emlrtMxCreateString("wrapper_cost"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(2.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 0, "ResolvedFilePath",
      emlrtMxCreateString(
          "C:\\Users\\henri\\Desktop\\robotarium_ws_old\\robotarium-matlab-"
          "simulator\\examples\\cbf_cruz_waypoints_tracking\\wrapper_cost.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp",
                emlrtMxCreateDoubleScalar(740101.74987268518));
  emlrtSetField(xEntryPoints, 0, "Visible", emlrtMxCreateLogicalScalar(true));
  xResult =
      emlrtCreateStructMatrix(1, 1, 7, (const char_T **)&propFieldName[0]);
  emlrtSetField(xResult, 0, "Version",
                emlrtMxCreateString("25.2.0.3150157 (R2025b) Update 4"));
  emlrtSetField(xResult, 0, "ResolvedFunctions",
                (mxArray *)c_emlrtMexFcnResolvedFunctionsI());
  emlrtSetField(xResult, 0, "Checksum",
                emlrtMxCreateString("EeeVNYuDvaEm9rdmeErnlC"));
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  emlrtSetField(xResult, 0, "AuxData",
                emlrtMxCreateRowVectorUINT8((const uint8_T *)&v, 216U));
  return xResult;
}

/* End of code generation (_coder_wrapper_cost_info.c) */
