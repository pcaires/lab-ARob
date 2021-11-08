/*
 * ARDroneHover_private.h
 *
 * Code generation for model "ARDroneHover".
 *
 * Model version              : $Id: UAV_PIL.mdl 965 2013-03-21 01:08:53Z escobar $
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C source code generated on : Wed Mar 14 13:33:32 2018
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Mac OS X)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ARDroneHover_private_h_
#define RTW_HEADER_ARDroneHover_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "ARDroneHover.h"

extern real_T rt_roundd_snf(real_T u);
extern real_T rt_powd_snf(real_T u0, real_T u1);
void ARDroneHover_output0(void);
void ARDroneHover_update0(void);
void ARDroneHover_output2(void);
void ARDroneHover_update2(void);       /* private model entry point functions */
extern void ARDroneHover_derivatives(void);

#endif                                 /* RTW_HEADER_ARDroneHover_private_h_ */
