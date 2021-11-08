/*
 * ARDroneWPTracking_V2_private.h
 *
 * Code generation for model "ARDroneWPTracking_V2".
 *
 * Model version              : $Id: UAV_PIL.mdl 965 2013-03-21 01:08:53Z escobar $
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C source code generated on : Wed Apr  4 16:06:22 2018
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Mac OS X)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ARDroneWPTracking_V2_private_h_
#define RTW_HEADER_ARDroneWPTracking_V2_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "ARDroneWPTracking_V2.h"

extern real_T rt_roundd_snf(real_T u);
extern real_T rt_powd_snf(real_T u0, real_T u1);
void ARDroneWPTracking_V2_output0(void);
void ARDroneWPTracking_V2_update0(void);
void ARDroneWPTracking_V2_output2(void);
void ARDroneWPTracking_V2_update2(void);/* private model entry point functions */
extern void ARDroneWPTracking_V2_derivatives(void);

#endif                                 /* RTW_HEADER_ARDroneWPTracking_V2_private_h_ */
