/*
 * ARDroneWPTracking_V2_data.c
 *
 * Code generation for model "ARDroneWPTracking_V2".
 *
 * Model version              : $Id: UAV_PIL.mdl 965 2013-03-21 01:08:53Z escobar $
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C source code generated on : Tue Apr  3 11:27:39 2018
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Mac OS X)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ARDroneWPTracking_V2.h"
#include "ARDroneWPTracking_V2_private.h"

/* Block parameters (auto storage) */
P_ARDroneWPTracking_V2_T ARDroneWPTracking_V2_P = {
  /* Variable: waypoints
   * Referenced by: '<S3>/Constant5'
   */
  { 0.0, 0.0, 1.0, 0.0, 5.0, 0.5, 0.0, 1.0, 0.0, 5.0, 0.5, 0.5, 1.0,
    1.5707963267948966, 5.0, 0.0, 0.5, 1.0, 1.5707963267948966, 5.0, 0.0, 0.0,
    1.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /* Mask Parameter: PacketInput_MaxMissedTicks
   * Referenced by: '<S1>/Packet Input'
   */
  100.0,

  /* Mask Parameter: PacketOutput_MaxMissedTicks
   * Referenced by: '<S8>/Packet Output'
   */
  100.0,

  /* Mask Parameter: PacketOutput1_MaxMissedTicks
   * Referenced by: '<S11>/Packet Output1'
   */
  100.0,

  /* Mask Parameter: PacketInput_YieldWhenWaiting
   * Referenced by: '<S1>/Packet Input'
   */
  0.0,

  /* Mask Parameter: PacketOutput_YieldWhenWaiting
   * Referenced by: '<S8>/Packet Output'
   */
  0.0,

  /* Mask Parameter: PacketOutput1_YieldWhenWaiting
   * Referenced by: '<S11>/Packet Output1'
   */
  0.0,

  /* Mask Parameter: PacketInput_PacketID
   * Referenced by: '<S1>/Packet Input'
   */
  1,

  /* Mask Parameter: PacketOutput_PacketID
   * Referenced by: '<S8>/Packet Output'
   */
  1,

  /* Mask Parameter: PacketOutput1_PacketID
   * Referenced by: '<S11>/Packet Output1'
   */
  1,

  /* Expression: 1
   * Referenced by: '<Root>/commands enabled'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/commands disabled'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/take off'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/land'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/stop'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/_'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Unit Delay to avoid algebraic loop'
   */
  0.0,

  /* Expression: [0 0]
   * Referenced by: '<S19>/Constant1'
   */
  { 0.0, 0.0 },

  /* Expression: pi/180
   * Referenced by: '<Root>/deg 2 rad'
   */
  0.017453292519943295,

  /* Expression: 180/pi
   * Referenced by: '<S5>/deg 2 rad1'
   */
  57.295779513082323,

  /* Expression: 1
   * Referenced by: '<S16>/Gain3'
   */
  1.0,

  /* Expression: 0.4
   * Referenced by: '<S15>/Gain1'
   */
  0.4,

  /* Expression: 1
   * Referenced by: '<S1>/Saturation 1'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S1>/Saturation 1'
   */
  -1.0,

  /* Expression: 1
   * Referenced by: '<S16>/Gain2'
   */
  1.0,

  /* Expression: -0.5
   * Referenced by: '<S12>/Gain'
   */
  -0.5,

  /* Expression: 1
   * Referenced by: '<S1>/Saturation 2'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S1>/Saturation 2'
   */
  -1.0,

  /* Expression: 1.5
   * Referenced by: '<S13>/proportional control gain - yaw'
   */
  1.5,

  /* Expression: 1
   * Referenced by: '<S1>/Saturation 3'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S1>/Saturation 3'
   */
  -1.0,

  /* Expression: 1
   * Referenced by: '<S14>/proportional control gain'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S1>/Saturation 4'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S1>/Saturation 4'
   */
  -1.0,

  /* Computed Parameter: ManualSwitch2_CurrentSetting
   * Referenced by: '<Root>/Manual Switch2'
   */
  1U,

  /* Computed Parameter: ManualSwitch1_CurrentSetting
   * Referenced by: '<Root>/Manual Switch1'
   */
  1U,

  /* Computed Parameter: ManualSwitch_CurrentSetting
   * Referenced by: '<Root>/Manual Switch'
   */
  1U,

  /* Computed Parameter: Constant_Value
   * Referenced by: '<S11>/Constant'
   */
  { 1U, 13U }
};
