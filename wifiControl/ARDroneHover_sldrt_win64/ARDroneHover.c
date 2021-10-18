/*
 * ARDroneHover.c
 *
 * Classroom License -- for classroom instructional use only.  Not for
 * government, commercial, academic research, or other organizational use.
 *
 * Code generation for model "ARDroneHover".
 *
 * Model version              : $Id: UAV_PIL.mdl 965 2013-03-21 01:08:53Z escobar $
 * Simulink Coder version : 9.0 (R2018b) 24-May-2018
 * C source code generated on : Mon Oct 11 12:31:06 2021
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ARDroneHover.h"
#include "ARDroneHover_private.h"
#include "ARDroneHover_dt.h"

/* options for Simulink Desktop Real-Time board 0 */
static double SLDRTBoardOptions0[] = {
  3.232235777E+9,
  5554.0,
};

/* options for Simulink Desktop Real-Time board 1 */
static double SLDRTBoardOptions1[] = {
  3.232235777E+9,
  5556.0,
};

/* list of Simulink Desktop Real-Time timers */
const int SLDRTTimerCount = 2;
const double SLDRTTimers[4] = {
  0.065, 0.0,
  0.65, 0.0,
};

/* list of Simulink Desktop Real-Time boards */
const int SLDRTBoardCount = 2;
SLDRTBOARD SLDRTBoards[2] = {
  { "Standard_Devices/UDP_Protocol", 5554U, 2, SLDRTBoardOptions0 },

  { "Standard_Devices/UDP_Protocol", 5556U, 2, SLDRTBoardOptions1 },
};

/* Block signals (default storage) */
B_ARDroneHover_T ARDroneHover_B;

/* Continuous states */
X_ARDroneHover_T ARDroneHover_X;

/* Block states (default storage) */
DW_ARDroneHover_T ARDroneHover_DW;

/* Real-time model */
RT_MODEL_ARDroneHover_T ARDroneHover_M_;
RT_MODEL_ARDroneHover_T *const ARDroneHover_M = &ARDroneHover_M_;

/* Forward declaration for local functions */
static void ARDroneHover_dec2hex(const uint8_T d[4], char_T s_data[], int32_T
  s_size[2]);
static real_T ARDroneHover_hex2dec(const char_T s_data[], const int32_T s_size[2]);
static void ARDroneHover_getString(real_T a, char_T strOut_data[], int32_T
  strOut_size[2]);
static int32_T ARDroneHover_float2IEEE754(real_T fVal);
static void rate_monotonic_scheduler(void);
time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(ARDroneHover_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(ARDroneHover_M, 2);
  UNUSED_PARAMETER(rtmNumSampTimes);
  UNUSED_PARAMETER(rtmTimingData);
  UNUSED_PARAMETER(rtmPerTaskSampleHits);
  return(-1);
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 1 shares data with slower tid rate: 2 */
  if (ARDroneHover_M->Timing.TaskCounters.TID[1] == 0) {
    ARDroneHover_M->Timing.RateInteraction.TID1_2 =
      (ARDroneHover_M->Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    ARDroneHover_M->Timing.perTaskSampleHits[5] =
      ARDroneHover_M->Timing.RateInteraction.TID1_2;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (ARDroneHover_M->Timing.TaskCounters.TID[2])++;
  if ((ARDroneHover_M->Timing.TaskCounters.TID[2]) > 9) {/* Sample time: [0.65s, 0.0s] */
    ARDroneHover_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  ARDroneHover_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Function for MATLAB Function: '<S1>/ARDrone data decoding' */
static void ARDroneHover_dec2hex(const uint8_T d[4], char_T s_data[], int32_T
  s_size[2])
{
  uint8_T di;
  uint8_T r;
  int32_T j;
  int32_T firstcol;
  boolean_T p;
  char_T s_data_0[8];
  boolean_T exitg1;
  s_size[0] = 4;
  s_size[1] = 2;
  for (j = 0; j < 8; j++) {
    s_data[j] = '0';
  }

  di = d[0];
  j = 2;
  exitg1 = false;
  while ((!exitg1) && (j > 0)) {
    r = di;
    di = (uint8_T)((uint32_T)di >> 4);
    r = (uint8_T)((uint32_T)r - (di << 4));
    if (r > 9) {
      r = (uint8_T)(r + 7U);
    }

    s_data[(j - 1) << 2] = (int8_T)(r + 48);
    if (di > 0) {
      j--;
    } else {
      exitg1 = true;
    }
  }

  di = d[1];
  j = 2;
  exitg1 = false;
  while ((!exitg1) && (j > 0)) {
    r = di;
    di = (uint8_T)((uint32_T)di >> 4);
    r = (uint8_T)((uint32_T)r - (di << 4));
    if (r > 9) {
      r = (uint8_T)(r + 7U);
    }

    s_data[1 + ((j - 1) << 2)] = (int8_T)(r + 48);
    if (di > 0) {
      j--;
    } else {
      exitg1 = true;
    }
  }

  di = d[2];
  j = 2;
  exitg1 = false;
  while ((!exitg1) && (j > 0)) {
    r = di;
    di = (uint8_T)((uint32_T)di >> 4);
    r = (uint8_T)((uint32_T)r - (di << 4));
    if (r > 9) {
      r = (uint8_T)(r + 7U);
    }

    s_data[2 + ((j - 1) << 2)] = (int8_T)(r + 48);
    if (di > 0) {
      j--;
    } else {
      exitg1 = true;
    }
  }

  di = d[3];
  j = 2;
  exitg1 = false;
  while ((!exitg1) && (j > 0)) {
    r = di;
    di = (uint8_T)((uint32_T)di >> 4);
    r = (uint8_T)((uint32_T)r - (di << 4));
    if (r > 9) {
      r = (uint8_T)(r + 7U);
    }

    s_data[3 + ((j - 1) << 2)] = (int8_T)(r + 48);
    if (di > 0) {
      j--;
    } else {
      exitg1 = true;
    }
  }

  firstcol = 2;
  j = 0;
  p = false;
  exitg1 = false;
  while ((!exitg1) && (j < 4)) {
    if (s_data[j] != '0') {
      p = true;
      exitg1 = true;
    } else {
      j++;
    }
  }

  if (p) {
    firstcol = 1;
  }

  if (firstcol > 1) {
    s_data[0] = s_data[4];
    s_data_0[0] = s_data[0];
    s_data[1] = s_data[5];
    s_data_0[1] = s_data[1];
    s_data[2] = s_data[6];
    s_data_0[2] = s_data[2];
    s_data[3] = s_data[7];
    s_data_0[3] = s_data[3];
    s_size[0] = 4;
    s_size[1] = 1;
    for (j = 0; j < 4; j++) {
      s_data[j] = s_data_0[j];
    }
  }
}

/* Function for MATLAB Function: '<S1>/ARDrone data decoding' */
static real_T ARDroneHover_hex2dec(const char_T s_data[], const int32_T s_size[2])
{
  real_T x;
  real_T p16;
  int32_T skj;
  int32_T b;
  int32_T b_j;
  x = 0.0;
  p16 = 1.0;
  b = (int32_T)(((-1.0 - (real_T)s_size[1]) + 1.0) / -1.0);
  for (b_j = 1; b_j - 1 < b; b_j++) {
    skj = s_size[1] - b_j;
    if (s_data[skj] != ' ') {
      skj = (uint8_T)s_data[skj];
      if ((skj != 0) && (skj != 48)) {
        if (skj > 57) {
          if (skj > 70) {
            skj -= 39;
          } else {
            skj -= 7;
          }
        }

        x += ((real_T)skj - 48.0) * p16;
      }

      p16 *= 16.0;
    }
  }

  return x;
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T tmp;
  real_T tmp_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = 1.0;
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

/* Function for MATLAB Function: '<S7>/Drone state request' */
static void ARDroneHover_getString(real_T a, char_T strOut_data[], int32_T
  strOut_size[2])
{
  int32_T d;
  uint8_T digit_data[11];
  real_T r;
  int32_T loop_ub;

  /* '<S9>:1:138' */
  d = 1;
  if ((a >= 10.0) && (a < 100.0)) {
    /* '<S9>:1:144' */
    /* '<S9>:1:145' */
    d = 2;
  }

  if ((a >= 100.0) && (a < 1000.0)) {
    /* '<S9>:1:148' */
    /* '<S9>:1:149' */
    d = 3;
  }

  if ((a >= 1000.0) && (a < 10000.0)) {
    /* '<S9>:1:152' */
    /* '<S9>:1:153' */
    d = 4;
  }

  if ((a >= 10000.0) && (a < 100000.0)) {
    /* '<S9>:1:156' */
    /* '<S9>:1:157' */
    d = 5;
  }

  if ((a >= 100000.0) && (a < 1.0E+6)) {
    /* '<S9>:1:160' */
    /* '<S9>:1:161' */
    d = 6;
  }

  if ((a >= 1.0E+6) && (a < 1.0E+7)) {
    /* '<S9>:1:164' */
    /* '<S9>:1:165' */
    d = 7;
  }

  if ((a >= 1.0E+7) && (a < 1.0E+8)) {
    /* '<S9>:1:168' */
    /* '<S9>:1:169' */
    d = 8;
  }

  if ((a >= 1.0E+8) && (a < 1.0E+9)) {
    /* '<S9>:1:172' */
    /* '<S9>:1:173' */
    d = 9;
  }

  if ((a >= 1.0E+9) && (a < 1.0E+10)) {
    /* '<S9>:1:176' */
    /* '<S9>:1:177' */
    d = 10;
  }

  if (a >= 1.0E+10) {
    /* '<S9>:1:180' */
    /* '<S9>:1:181' */
    d = 11;
  }

  /* '<S9>:1:186' */
  loop_ub = d - 1;
  if (0 <= loop_ub) {
    memset(&digit_data[0], 0, (loop_ub + 1) * sizeof(uint8_T));
  }

  /* '<S9>:1:189' */
  for (loop_ub = 0; loop_ub < d; loop_ub++) {
    /* '<S9>:1:189' */
    /* '<S9>:1:191' */
    if (!rtIsInf(a)) {
      if (a == 0.0) {
        r = 0.0;
      } else {
        r = fmod(a, rt_powd_snf(10.0, 1.0 + (real_T)loop_ub));
        if (r == 0.0) {
          r = 0.0;
        }
      }
    } else {
      r = (rtNaN);
    }

    /* '<S9>:1:194' */
    r = r / rt_powd_snf(10.0, (1.0 + (real_T)loop_ub) - 1.0) + 48.0;
    if (r < 0.0) {
      r = ceil(r);
    } else {
      r = floor(r);
    }

    if (rtIsNaN(r)) {
      r = 0.0;
    } else {
      r = fmod(r, 256.0);
    }

    digit_data[(d - loop_ub) - 1] = (uint8_T)(r < 0.0 ? (int32_T)(int8_T)
      -(int8_T)(uint8_T)-r : (int32_T)(int8_T)(uint8_T)r);
  }

  /* '<S9>:1:199' */
  strOut_size[0] = 1;
  strOut_size[1] = d;
  loop_ub = d - 1;
  for (d = 0; d <= loop_ub; d++) {
    strOut_data[d] = (int8_T)digit_data[d];
  }
}

/* Function for MATLAB Function: '<S7>/Drone state request' */
static int32_T ARDroneHover_float2IEEE754(real_T fVal)
{
  int32_T iVal;
  char_T binData[32];
  char_T binData2[32];
  int32_T bit;
  real_T b_iVal;
  uint8_T y[4];
  real32_T x;
  int32_T b_k;

  /* '<S9>:1:209' */
  /* '<S9>:1:207' */
  x = (real32_T)fVal;
  memcpy((void *)&y[0], (void *)&x, (uint32_T)((size_t)4 * sizeof(uint8_T)));
  for (b_k = 0; b_k < 32; b_k++) {
    binData[b_k] = '0';
  }

  for (b_k = 0; b_k < 4; b_k++) {
    for (bit = 0; bit < 8; bit++) {
      if ((1 << bit & y[b_k]) != 0) {
        binData[b_k + ((7 - bit) << 2)] = '1';
      }
    }
  }

  /* '<S9>:1:209' */
  for (b_k = 0; b_k < 8; b_k++) {
    bit = b_k << 2;
    binData2[b_k] = binData[bit + 3];
    binData2[b_k + 8] = binData[bit + 2];
    binData2[b_k + 16] = binData[bit + 1];
    binData2[b_k + 24] = binData[bit];
  }

  /* '<S9>:1:210' */
  b_iVal = 0.0;

  /* '<S9>:1:211' */
  for (b_k = 0; b_k < 32; b_k++) {
    /* '<S9>:1:211' */
    if (binData2[31 - b_k] == '1') {
      /* '<S9>:1:213' */
      /* '<S9>:1:214' */
      bit = 1;
    } else {
      /* '<S9>:1:216' */
      bit = 0;
    }

    if (32 - b_k == 1) {
      /* '<S9>:1:219' */
      /* '<S9>:1:220' */
      b_iVal -= (real_T)bit * 2.147483648E+9;
    } else {
      /* '<S9>:1:222' */
      b_iVal += rt_powd_snf(2.0, 32.0 - (32.0 + -(real_T)b_k)) * (real_T)bit;
    }
  }

  /* '<S9>:1:227' */
  if (b_iVal < 2.147483648E+9) {
    if (b_iVal >= -2.147483648E+9) {
      iVal = (int32_T)b_iVal;
    } else {
      iVal = MIN_int32_T;
    }
  } else {
    iVal = MAX_int32_T;
  }

  return iVal;
}

/* Model output function for TID0 */
void ARDroneHover_output0(void)        /* Sample time: [0.0s, 0.0s] */
{
  real_T bytesToRead;
  real_T bytesLeft;
  int32_T m;
  uint8_T data[496];
  char_T hex_data[8];
  char_T b_hex_data[8];
  real32_T res;
  real32_T b_res;
  char_T cmd_data[148];
  char_T strCmd_data[11];
  int32_T aux;
  char_T strAux_data[12];
  static const char_T c[10] = { 'A', 'T', '*', 'C', 'O', 'N', 'F', 'I', 'G', '='
  };

  static const char_T d[30] = { ',', '\"', 'g', 'e', 'n', 'e', 'r', 'a', 'l',
    ':', 'n', 'a', 'v', 'd', 'a', 't', 'a', '_', 'd', 'e', 'm', 'o', '\"', ',',
    '\"', 'T', 'R', 'U', 'E', '\"' };

  static const char_T e[10] = { 'A', 'T', '*', 'C', 'O', 'M', 'W', 'D', 'G', '='
  };

  static const char_T f[7] = { 'A', 'T', '*', 'R', 'E', 'F', '=' };

  static const char_T g[10] = { ',', '2', '9', '0', '7', '1', '7', '9', '5', '2'
  };

  static const char_T h[30] = { '\"', 'c', 'o', 'n', 'r', 'o', 'l', ':', 'a',
    'l', 't', 'i', 't', 'u', 'd', 'e', '_', 'm', 'a', 'x', '\"', ',', '\"', '1',
    '0', '0', '0', '0', '0', '\"' };

  static const char_T i[9] = { 'A', 'T', '*', 'F', 'T', 'R', 'I', 'M', '=' };

  static const char_T j[10] = { ',', '2', '9', '0', '7', '1', '8', '2', '0', '8'
  };

  static const char_T k[10] = { ',', '2', '9', '0', '7', '1', '7', '6', '9', '6'
  };

  static const char_T l[8] = { 'A', 'T', '*', 'P', 'C', 'M', 'D', '=' };

  real32_T rtb_yawAngle;
  real32_T rtb_u;
  real32_T rtb_v;
  real32_T rtb_w;
  real_T rtb_Saturation1;
  real_T rtb_Saturation2;
  real_T rtb_Saturation3;
  int8_T rtb_status[32];
  int32_T i_0;
  uint8_T tmp_data[1024];
  char_T cmd_data_0[148];
  int32_T loop_ub;
  int32_T loop_ub_0;
  int32_T loop_ub_1;
  int32_T hex_size[2];
  int32_T hex_size_0[2];
  int32_T hex_size_1[2];
  int32_T hex_size_2[2];
  int32_T hex_size_3[2];
  int32_T hex_size_4[2];
  int32_T hex_size_5[2];
  int32_T hex_size_6[2];
  int32_T hex_size_7[2];
  uint32_T x;
  real_T b_tmp;
  boolean_T guard1 = false;
  int32_T exitg1;
  if (rtmIsMajorTimeStep(ARDroneHover_M)) {
    /* set solver stop time */
    if (!(ARDroneHover_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&ARDroneHover_M->solverInfo,
                            ((ARDroneHover_M->Timing.clockTickH0 + 1) *
        ARDroneHover_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&ARDroneHover_M->solverInfo,
                            ((ARDroneHover_M->Timing.clockTick0 + 1) *
        ARDroneHover_M->Timing.stepSize0 + ARDroneHover_M->Timing.clockTickH0 *
        ARDroneHover_M->Timing.stepSize0 * 4294967296.0));
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(ARDroneHover_M)) {
    ARDroneHover_M->Timing.t[0] = rtsiGetT(&ARDroneHover_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(ARDroneHover_M)) {
    /* S-Function (sldrtpi): '<S1>/Packet Input' */
    /* S-Function Block: <S1>/Packet Input */
    {
      uint8_T indata[500U];
      int status = RTBIO_DriverIO(0, STREAMINPUT, IOREAD, 500U,
        &ARDroneHover_P.PacketInput_PacketID, (double*) indata, NULL);
      ARDroneHover_B.PacketInput_o2 = status & 0x1;/* Data Ready port */
      if (status & 0x1) {
        RTWin_ANYTYPEPTR indp;
        indp.p_uint8_T = indata;

        {
          int_T i1;
          uint8_T *y0 = &ARDroneHover_B.PacketInput_o1[0];
          for (i1=0; i1 < 500; i1++) {
            y0[i1] = *indp.p_uint8_T++;
          }
        }
      }
    }

    /* MATLAB Function: '<S1>/Data synchronization ' */
    /* MATLAB Function 'ARDrone Wi-Fi  Block/Data synchronization ': '<S6>:1' */
    /* '<S6>:1:52' */
    for (i_0 = 0; i_0 < 500; i_0++) {
      ARDroneHover_DW.buffer[(int32_T)(ARDroneHover_DW.countBuffer + ((real_T)
        i_0 + 1.0)) - 1] = ARDroneHover_B.PacketInput_o1[i_0];
    }

    /* '<S6>:1:54' */
    bytesToRead = ARDroneHover_DW.countBuffer + 500.0;

    /* '<S6>:1:59' */
    aux = 0;
    do {
      exitg1 = 0;
      m = (int32_T)(ARDroneHover_DW.countBuffer + 500.0);
      if (aux <= m - 1) {
        /* '<S6>:1:59' */
        if ((ARDroneHover_DW.countHeader == 4.0) && (ARDroneHover_DW.count <
             496.0)) {
          /* '<S6>:1:60' */
          /* '<S6>:1:61' */
          bytesLeft = 496.0 - ARDroneHover_DW.count;
          b_tmp = (1.0 + (real_T)aux) + (496.0 - ARDroneHover_DW.count);
          if (1.0 + (real_T)aux > b_tmp - 1.0) {
            m = 1;
            loop_ub = 0;
          } else {
            m = aux + 1;
            loop_ub = (int32_T)(b_tmp - 1.0);
          }

          /* '<S6>:1:62' */
          i_0 = (int32_T)(ARDroneHover_DW.count + 1.0) - 1;
          loop_ub -= m;
          for (loop_ub_0 = 0; loop_ub_0 <= loop_ub; loop_ub_0++) {
            ARDroneHover_DW.frame[i_0 + loop_ub_0] = ARDroneHover_DW.buffer[(m +
              loop_ub_0) - 1];
          }

          /* '<S6>:1:63' */
          ARDroneHover_DW.count = 496.0;

          /* '<S6>:1:64' */
          ARDroneHover_DW.countBuffer = (ARDroneHover_DW.countBuffer + 500.0) -
            bytesLeft;
          b_tmp = (1.0 + (real_T)aux) + bytesLeft;
          if (b_tmp > bytesToRead) {
            aux = 0;
            m = 0;
          } else {
            aux = (int32_T)b_tmp - 1;
            m = (int32_T)bytesToRead;
          }

          /* '<S6>:1:65' */
          loop_ub = m - aux;
          for (i_0 = 0; i_0 < loop_ub; i_0++) {
            tmp_data[i_0] = ARDroneHover_DW.buffer[aux + i_0];
          }

          if (0 <= loop_ub - 1) {
            memcpy(&ARDroneHover_DW.buffer[0], &tmp_data[0], loop_ub * sizeof
                   (uint8_T));
          }

          exitg1 = 1;
        } else if ((ARDroneHover_DW.countHeader == 3.0) &&
                   (ARDroneHover_DW.buffer[aux] == 85)) {
          /* '<S6>:1:70' */
          /* '<S6>:1:72' */
          ARDroneHover_DW.countHeader = 4.0;
          b_tmp = (ARDroneHover_DW.countBuffer + 500.0) - (1.0 + (real_T)aux);
          if (b_tmp > 496.0) {
            /* '<S6>:1:74' */
            /* '<S6>:1:75' */
            ARDroneHover_DW.count = 496.0;

            /* '<S6>:1:76' */
            for (i_0 = 0; i_0 < 496; i_0++) {
              ARDroneHover_DW.frame[(int16_T)i_0] = ARDroneHover_DW.buffer[(i_0
                + aux) + 1];
            }

            /* '<S6>:1:77' */
            ARDroneHover_DW.countBuffer = ((ARDroneHover_DW.countBuffer + 500.0)
              - (1.0 + (real_T)aux)) - 496.0;
            if (((1.0 + (real_T)aux) + 496.0) + 1.0 > bytesToRead) {
              aux = -497;
              m = 0;
            } else {
              m = (int32_T)bytesToRead;
            }

            /* '<S6>:1:78' */
            i_0 = aux + 497;
            loop_ub = m - i_0;
            for (loop_ub_0 = 0; loop_ub_0 < loop_ub; loop_ub_0++) {
              tmp_data[loop_ub_0] = ARDroneHover_DW.buffer[i_0 + loop_ub_0];
            }

            if (0 <= loop_ub - 1) {
              memcpy(&ARDroneHover_DW.buffer[0], &tmp_data[0], loop_ub * sizeof
                     (uint8_T));
            }
          } else {
            /* '<S6>:1:81' */
            ARDroneHover_DW.count = b_tmp;
            if (ARDroneHover_DW.count > 0.0) {
              /* '<S6>:1:82' */
              if ((1.0 + (real_T)aux) + 1.0 > ARDroneHover_DW.countBuffer +
                  500.0) {
                aux = -1;
                m = 0;
              }

              /* '<S6>:1:83' */
              loop_ub = m - aux;
              for (i_0 = 0; i_0 <= loop_ub - 2; i_0++) {
                ARDroneHover_DW.frame[i_0] = ARDroneHover_DW.buffer[(aux + i_0)
                  + 1];
              }
            }

            /* '<S6>:1:85' */
            ARDroneHover_DW.countBuffer = 0.0;
          }

          exitg1 = 1;
        } else {
          if ((ARDroneHover_DW.countHeader == 2.0) &&
              (ARDroneHover_DW.buffer[aux] == 102)) {
            /* '<S6>:1:92' */
            /* '<S6>:1:93' */
            ARDroneHover_DW.countHeader = 3.0;
          }

          if ((ARDroneHover_DW.countHeader == 1.0) &&
              (ARDroneHover_DW.buffer[aux] == 119)) {
            /* '<S6>:1:96' */
            /* '<S6>:1:97' */
            ARDroneHover_DW.countHeader = 2.0;
          }

          if ((ARDroneHover_DW.countHeader == 0.0) &&
              (ARDroneHover_DW.buffer[aux] == 136)) {
            /* '<S6>:1:100' */
            /* '<S6>:1:101' */
            ARDroneHover_DW.countHeader = 1.0;
          }

          aux++;
        }
      } else {
        exitg1 = 1;
      }
    } while (exitg1 == 0);

    if (ARDroneHover_DW.count == 496.0) {
      /* '<S6>:1:106' */
      /* '<S6>:1:107' */
      /* '<S6>:1:108' */
      /* '<S6>:1:109' */
      /* '<S6>:1:110' */
      for (i_0 = 0; i_0 < 496; i_0++) {
        ARDroneHover_DW.lastFrame[i_0] = ARDroneHover_DW.frame[i_0];
        ARDroneHover_DW.frame[i_0] = 0U;
      }

      /* '<S6>:1:111' */
      ARDroneHover_DW.count = 0.0;

      /* '<S6>:1:112' */
      ARDroneHover_DW.countHeader = 0.0;
    } else {
      /* '<S6>:1:115' */
      /* '<S6>:1:116' */
    }

    /* MATLAB Function: '<S1>/ARDrone data decoding' incorporates:
     *  MATLAB Function: '<S1>/Data synchronization '
     */
    memcpy(&data[0], &ARDroneHover_DW.lastFrame[0], 496U * sizeof(uint8_T));

    /* MATLAB Function 'ARDrone Wi-Fi  Block/ARDrone data decoding': '<S5>:1' */
    /* '<S5>:1:23' */
    /* '<S5>:1:25' */
    /* '<S5>:1:27' */
    if (ARDroneHover_DW.lastFrame[14] == 148) {
      /* '<S5>:1:30' */
      /* '<S5>:1:31' */
      memcpy(&ARDroneHover_DW.dataPrev[0], &ARDroneHover_DW.lastFrame[0], 496U *
             sizeof(uint8_T));
    } else {
      /* '<S5>:1:33' */
      memcpy(&data[0], &ARDroneHover_DW.dataPrev[0], 496U * sizeof(uint8_T));
    }

    /* '<S5>:1:37' */
    /* '<S5>:1:74' */
    for (i_0 = 0; i_0 < 32; i_0++) {
      rtb_status[i_0] = 0;
    }

    /* '<S5>:1:75' */
    ARDroneHover_dec2hex(&data[0], hex_data, hex_size);

    /* '<S5>:1:77' */
    loop_ub = hex_size[1];
    m = hex_size[1];
    loop_ub_0 = hex_size[1];
    loop_ub_1 = hex_size[1];
    aux = ((hex_size[1] + hex_size[1]) + hex_size[1]) + hex_size[1];
    for (i_0 = 0; i_0 < loop_ub; i_0++) {
      b_hex_data[i_0] = hex_data[(i_0 << 2) + 3];
    }

    for (i_0 = 0; i_0 < m; i_0++) {
      b_hex_data[i_0 + loop_ub] = hex_data[(i_0 << 2) + 2];
    }

    for (i_0 = 0; i_0 < loop_ub_0; i_0++) {
      b_hex_data[(i_0 + loop_ub) + m] = hex_data[(i_0 << 2) + 1];
    }

    for (i_0 = 0; i_0 < loop_ub_1; i_0++) {
      b_hex_data[((i_0 + loop_ub) + m) + loop_ub_0] = hex_data[i_0 << 2];
    }

    /* '<S5>:1:78' */
    for (m = 0; m < aux; m++) {
      /* '<S5>:1:78' */
      if (b_hex_data[m] == 'F') {
        /* '<S5>:1:79' */
        /* '<S5>:1:80' */
        rtb_status[((1 + m) << 2) - 4] = 1;
        rtb_status[((1 + m) << 2) - 3] = 1;
        rtb_status[((1 + m) << 2) - 2] = 1;
        rtb_status[((1 + m) << 2) - 1] = 1;
      } else if (b_hex_data[m] == 'E') {
        /* '<S5>:1:81' */
        /* '<S5>:1:82' */
        i_0 = ((1 + m) << 2) - 4;
        rtb_status[i_0] = 1;
        rtb_status[1 + i_0] = 1;
        rtb_status[2 + i_0] = 1;
        rtb_status[3 + i_0] = 0;
      } else if (b_hex_data[m] == 'D') {
        /* '<S5>:1:83' */
        /* '<S5>:1:84' */
        i_0 = ((1 + m) << 2) - 4;
        rtb_status[i_0] = 1;
        rtb_status[1 + i_0] = 1;
        rtb_status[2 + i_0] = 0;
        rtb_status[3 + i_0] = 1;
      } else if (b_hex_data[m] == 'C') {
        /* '<S5>:1:85' */
        /* '<S5>:1:86' */
        i_0 = ((1 + m) << 2) - 4;
        rtb_status[i_0] = 1;
        rtb_status[1 + i_0] = 1;
        rtb_status[2 + i_0] = 0;
        rtb_status[3 + i_0] = 0;
      } else if (b_hex_data[m] == 'B') {
        /* '<S5>:1:87' */
        /* '<S5>:1:88' */
        i_0 = ((1 + m) << 2) - 4;
        rtb_status[i_0] = 1;
        rtb_status[1 + i_0] = 0;
        rtb_status[2 + i_0] = 1;
        rtb_status[3 + i_0] = 1;
      } else if (b_hex_data[m] == 'A') {
        /* '<S5>:1:89' */
        /* '<S5>:1:90' */
        i_0 = ((1 + m) << 2) - 4;
        rtb_status[i_0] = 1;
        rtb_status[1 + i_0] = 0;
        rtb_status[2 + i_0] = 1;
        rtb_status[3 + i_0] = 0;
      } else if (b_hex_data[m] == '9') {
        /* '<S5>:1:91' */
        /* '<S5>:1:92' */
        i_0 = ((1 + m) << 2) - 4;
        rtb_status[i_0] = 1;
        rtb_status[1 + i_0] = 0;
        rtb_status[2 + i_0] = 0;
        rtb_status[3 + i_0] = 1;
      } else if (b_hex_data[m] == '8') {
        /* '<S5>:1:93' */
        /* '<S5>:1:94' */
        i_0 = ((1 + m) << 2) - 4;
        rtb_status[i_0] = 1;
        rtb_status[1 + i_0] = 0;
        rtb_status[2 + i_0] = 0;
        rtb_status[3 + i_0] = 0;
      } else if (b_hex_data[m] == '7') {
        /* '<S5>:1:95' */
        /* '<S5>:1:96' */
        i_0 = ((1 + m) << 2) - 4;
        rtb_status[i_0] = 0;
        rtb_status[1 + i_0] = 1;
        rtb_status[2 + i_0] = 1;
        rtb_status[3 + i_0] = 1;
      } else if (b_hex_data[m] == '6') {
        /* '<S5>:1:97' */
        /* '<S5>:1:98' */
        i_0 = ((1 + m) << 2) - 4;
        rtb_status[i_0] = 0;
        rtb_status[1 + i_0] = 1;
        rtb_status[2 + i_0] = 1;
        rtb_status[3 + i_0] = 0;
      } else if (b_hex_data[m] == '5') {
        /* '<S5>:1:99' */
        /* '<S5>:1:100' */
        i_0 = ((1 + m) << 2) - 4;
        rtb_status[i_0] = 0;
        rtb_status[1 + i_0] = 1;
        rtb_status[2 + i_0] = 0;
        rtb_status[3 + i_0] = 1;
      } else if (b_hex_data[m] == '4') {
        /* '<S5>:1:101' */
        /* '<S5>:1:102' */
        i_0 = ((1 + m) << 2) - 4;
        rtb_status[i_0] = 0;
        rtb_status[1 + i_0] = 1;
        rtb_status[2 + i_0] = 0;
        rtb_status[3 + i_0] = 0;
      } else if (b_hex_data[m] == '3') {
        /* '<S5>:1:103' */
        /* '<S5>:1:104' */
        i_0 = ((1 + m) << 2) - 4;
        rtb_status[i_0] = 0;
        rtb_status[1 + i_0] = 0;
        rtb_status[2 + i_0] = 1;
        rtb_status[3 + i_0] = 1;
      } else if (b_hex_data[m] == '2') {
        /* '<S5>:1:105' */
        /* '<S5>:1:106' */
        i_0 = ((1 + m) << 2) - 4;
        rtb_status[i_0] = 0;
        rtb_status[1 + i_0] = 0;
        rtb_status[2 + i_0] = 1;
        rtb_status[3 + i_0] = 0;
      } else if (b_hex_data[m] == '1') {
        /* '<S5>:1:107' */
        /* '<S5>:1:108' */
        i_0 = ((1 + m) << 2) - 4;
        rtb_status[i_0] = 0;
        rtb_status[1 + i_0] = 0;
        rtb_status[2 + i_0] = 0;
        rtb_status[3 + i_0] = 1;
      } else {
        if (b_hex_data[m] == '0') {
          /* '<S5>:1:109' */
          /* '<S5>:1:110' */
          i_0 = (1 + m) << 2;
          rtb_status[i_0 - 4] = 0;
          rtb_status[i_0 - 3] = 0;
          rtb_status[i_0 - 2] = 0;
          rtb_status[i_0 - 1] = 0;
        }
      }
    }

    /* '<S5>:1:38' */
    /* '<S5>:1:64' */
    ARDroneHover_dec2hex(&data[20], hex_data, hex_size);

    /* '<S5>:1:65' */
    /* '<S5>:1:67' */
    loop_ub = hex_size[1];
    m = hex_size[1];
    loop_ub_0 = hex_size[1];
    loop_ub_1 = hex_size[1];
    hex_size_7[0] = 1;
    hex_size_7[1] = ((hex_size[1] + hex_size[1]) + hex_size[1]) + hex_size[1];
    for (i_0 = 0; i_0 < loop_ub; i_0++) {
      b_hex_data[i_0] = hex_data[(i_0 << 2) + 3];
    }

    for (i_0 = 0; i_0 < m; i_0++) {
      b_hex_data[i_0 + loop_ub] = hex_data[(i_0 << 2) + 2];
    }

    for (i_0 = 0; i_0 < loop_ub_0; i_0++) {
      b_hex_data[(i_0 + loop_ub) + m] = hex_data[(i_0 << 2) + 1];
    }

    for (i_0 = 0; i_0 < loop_ub_1; i_0++) {
      b_hex_data[((i_0 + loop_ub) + m) + loop_ub_0] = hex_data[i_0 << 2];
    }

    /* DataTypeConversion: '<S1>/Type Conversion' incorporates:
     *  MATLAB Function: '<S1>/ARDrone data decoding'
     */
    ARDroneHover_B.TypeConversion = ARDroneHover_hex2dec(b_hex_data, hex_size_7);

    /* MATLAB Function: '<S1>/ARDrone data decoding' */
    /* '<S5>:1:39' */
    /* '<S5>:1:64' */
    ARDroneHover_dec2hex(&data[24], hex_data, hex_size);

    /* '<S5>:1:65' */
    /* '<S5>:1:69' */
    loop_ub = hex_size[1];
    m = hex_size[1];
    loop_ub_0 = hex_size[1];
    loop_ub_1 = hex_size[1];
    hex_size_6[0] = 1;
    hex_size_6[1] = ((hex_size[1] + hex_size[1]) + hex_size[1]) + hex_size[1];
    for (i_0 = 0; i_0 < loop_ub; i_0++) {
      b_hex_data[i_0] = hex_data[(i_0 << 2) + 3];
    }

    for (i_0 = 0; i_0 < m; i_0++) {
      b_hex_data[i_0 + loop_ub] = hex_data[(i_0 << 2) + 2];
    }

    for (i_0 = 0; i_0 < loop_ub_0; i_0++) {
      b_hex_data[(i_0 + loop_ub) + m] = hex_data[(i_0 << 2) + 1];
    }

    for (i_0 = 0; i_0 < loop_ub_1; i_0++) {
      b_hex_data[((i_0 + loop_ub) + m) + loop_ub_0] = hex_data[i_0 << 2];
    }

    b_tmp = rt_roundd_snf(ARDroneHover_hex2dec(b_hex_data, hex_size_6));
    if (b_tmp < 4.294967296E+9) {
      if (b_tmp >= 0.0) {
        x = (uint32_T)b_tmp;
      } else {
        x = 0U;
      }
    } else {
      x = MAX_uint32_T;
    }

    memcpy((void *)&res, (void *)&x, (uint32_T)((size_t)1 * sizeof(real32_T)));

    /* '<S5>:1:40' */
    /* '<S5>:1:64' */
    ARDroneHover_dec2hex(&data[28], hex_data, hex_size);

    /* '<S5>:1:65' */
    /* '<S5>:1:69' */
    loop_ub = hex_size[1];
    m = hex_size[1];
    loop_ub_0 = hex_size[1];
    loop_ub_1 = hex_size[1];
    hex_size_5[0] = 1;
    hex_size_5[1] = ((hex_size[1] + hex_size[1]) + hex_size[1]) + hex_size[1];
    for (i_0 = 0; i_0 < loop_ub; i_0++) {
      b_hex_data[i_0] = hex_data[(i_0 << 2) + 3];
    }

    for (i_0 = 0; i_0 < m; i_0++) {
      b_hex_data[i_0 + loop_ub] = hex_data[(i_0 << 2) + 2];
    }

    for (i_0 = 0; i_0 < loop_ub_0; i_0++) {
      b_hex_data[(i_0 + loop_ub) + m] = hex_data[(i_0 << 2) + 1];
    }

    for (i_0 = 0; i_0 < loop_ub_1; i_0++) {
      b_hex_data[((i_0 + loop_ub) + m) + loop_ub_0] = hex_data[i_0 << 2];
    }

    b_tmp = rt_roundd_snf(ARDroneHover_hex2dec(b_hex_data, hex_size_5));
    if (b_tmp < 4.294967296E+9) {
      if (b_tmp >= 0.0) {
        x = (uint32_T)b_tmp;
      } else {
        x = 0U;
      }
    } else {
      x = MAX_uint32_T;
    }

    memcpy((void *)&b_res, (void *)&x, (uint32_T)((size_t)1 * sizeof(real32_T)));

    /* '<S5>:1:41' */
    /* '<S5>:1:64' */
    ARDroneHover_dec2hex(&data[32], hex_data, hex_size);

    /* '<S5>:1:65' */
    /* '<S5>:1:69' */
    loop_ub = hex_size[1];
    m = hex_size[1];
    loop_ub_0 = hex_size[1];
    loop_ub_1 = hex_size[1];
    hex_size_4[0] = 1;
    hex_size_4[1] = ((hex_size[1] + hex_size[1]) + hex_size[1]) + hex_size[1];
    for (i_0 = 0; i_0 < loop_ub; i_0++) {
      b_hex_data[i_0] = hex_data[(i_0 << 2) + 3];
    }

    for (i_0 = 0; i_0 < m; i_0++) {
      b_hex_data[i_0 + loop_ub] = hex_data[(i_0 << 2) + 2];
    }

    for (i_0 = 0; i_0 < loop_ub_0; i_0++) {
      b_hex_data[(i_0 + loop_ub) + m] = hex_data[(i_0 << 2) + 1];
    }

    for (i_0 = 0; i_0 < loop_ub_1; i_0++) {
      b_hex_data[((i_0 + loop_ub) + m) + loop_ub_0] = hex_data[i_0 << 2];
    }

    b_tmp = rt_roundd_snf(ARDroneHover_hex2dec(b_hex_data, hex_size_4));
    if (b_tmp < 4.294967296E+9) {
      if (b_tmp >= 0.0) {
        x = (uint32_T)b_tmp;
      } else {
        x = 0U;
      }
    } else {
      x = MAX_uint32_T;
    }

    memcpy((void *)&rtb_yawAngle, (void *)&x, (uint32_T)((size_t)1 * sizeof
            (real32_T)));

    /* '<S5>:1:42' */
    /* '<S5>:1:64' */
    ARDroneHover_dec2hex(&data[36], hex_data, hex_size);

    /* '<S5>:1:65' */
    /* '<S5>:1:67' */
    loop_ub = hex_size[1];
    m = hex_size[1];
    loop_ub_0 = hex_size[1];
    loop_ub_1 = hex_size[1];
    hex_size_3[0] = 1;
    hex_size_3[1] = ((hex_size[1] + hex_size[1]) + hex_size[1]) + hex_size[1];
    for (i_0 = 0; i_0 < loop_ub; i_0++) {
      b_hex_data[i_0] = hex_data[(i_0 << 2) + 3];
    }

    for (i_0 = 0; i_0 < m; i_0++) {
      b_hex_data[i_0 + loop_ub] = hex_data[(i_0 << 2) + 2];
    }

    for (i_0 = 0; i_0 < loop_ub_0; i_0++) {
      b_hex_data[(i_0 + loop_ub) + m] = hex_data[(i_0 << 2) + 1];
    }

    for (i_0 = 0; i_0 < loop_ub_1; i_0++) {
      b_hex_data[((i_0 + loop_ub) + m) + loop_ub_0] = hex_data[i_0 << 2];
    }

    bytesLeft = ARDroneHover_hex2dec(b_hex_data, hex_size_3) / 1000.0;

    /* '<S5>:1:43' */
    /* '<S5>:1:64' */
    ARDroneHover_dec2hex(&data[40], hex_data, hex_size);

    /* '<S5>:1:65' */
    /* '<S5>:1:69' */
    loop_ub = hex_size[1];
    m = hex_size[1];
    loop_ub_0 = hex_size[1];
    loop_ub_1 = hex_size[1];
    hex_size_2[0] = 1;
    hex_size_2[1] = ((hex_size[1] + hex_size[1]) + hex_size[1]) + hex_size[1];
    for (i_0 = 0; i_0 < loop_ub; i_0++) {
      b_hex_data[i_0] = hex_data[(i_0 << 2) + 3];
    }

    for (i_0 = 0; i_0 < m; i_0++) {
      b_hex_data[i_0 + loop_ub] = hex_data[(i_0 << 2) + 2];
    }

    for (i_0 = 0; i_0 < loop_ub_0; i_0++) {
      b_hex_data[(i_0 + loop_ub) + m] = hex_data[(i_0 << 2) + 1];
    }

    for (i_0 = 0; i_0 < loop_ub_1; i_0++) {
      b_hex_data[((i_0 + loop_ub) + m) + loop_ub_0] = hex_data[i_0 << 2];
    }

    b_tmp = rt_roundd_snf(ARDroneHover_hex2dec(b_hex_data, hex_size_2));
    if (b_tmp < 4.294967296E+9) {
      if (b_tmp >= 0.0) {
        x = (uint32_T)b_tmp;
      } else {
        x = 0U;
      }
    } else {
      x = MAX_uint32_T;
    }

    memcpy((void *)&rtb_u, (void *)&x, (uint32_T)((size_t)1 * sizeof(real32_T)));

    /* '<S5>:1:44' */
    /* '<S5>:1:64' */
    ARDroneHover_dec2hex(&data[44], hex_data, hex_size);

    /* '<S5>:1:65' */
    /* '<S5>:1:69' */
    loop_ub = hex_size[1];
    m = hex_size[1];
    loop_ub_0 = hex_size[1];
    loop_ub_1 = hex_size[1];
    hex_size_1[0] = 1;
    hex_size_1[1] = ((hex_size[1] + hex_size[1]) + hex_size[1]) + hex_size[1];
    for (i_0 = 0; i_0 < loop_ub; i_0++) {
      b_hex_data[i_0] = hex_data[(i_0 << 2) + 3];
    }

    for (i_0 = 0; i_0 < m; i_0++) {
      b_hex_data[i_0 + loop_ub] = hex_data[(i_0 << 2) + 2];
    }

    for (i_0 = 0; i_0 < loop_ub_0; i_0++) {
      b_hex_data[(i_0 + loop_ub) + m] = hex_data[(i_0 << 2) + 1];
    }

    for (i_0 = 0; i_0 < loop_ub_1; i_0++) {
      b_hex_data[((i_0 + loop_ub) + m) + loop_ub_0] = hex_data[i_0 << 2];
    }

    b_tmp = rt_roundd_snf(ARDroneHover_hex2dec(b_hex_data, hex_size_1));
    if (b_tmp < 4.294967296E+9) {
      if (b_tmp >= 0.0) {
        x = (uint32_T)b_tmp;
      } else {
        x = 0U;
      }
    } else {
      x = MAX_uint32_T;
    }

    memcpy((void *)&rtb_v, (void *)&x, (uint32_T)((size_t)1 * sizeof(real32_T)));

    /* '<S5>:1:45' */
    /* '<S5>:1:64' */
    ARDroneHover_dec2hex(&data[48], hex_data, hex_size);

    /* '<S5>:1:65' */
    /* '<S5>:1:69' */
    loop_ub = hex_size[1];
    m = hex_size[1];
    loop_ub_0 = hex_size[1];
    loop_ub_1 = hex_size[1];
    hex_size_0[0] = 1;
    hex_size_0[1] = ((hex_size[1] + hex_size[1]) + hex_size[1]) + hex_size[1];
    for (i_0 = 0; i_0 < loop_ub; i_0++) {
      b_hex_data[i_0] = hex_data[(i_0 << 2) + 3];
    }

    for (i_0 = 0; i_0 < m; i_0++) {
      b_hex_data[i_0 + loop_ub] = hex_data[(i_0 << 2) + 2];
    }

    for (i_0 = 0; i_0 < loop_ub_0; i_0++) {
      b_hex_data[(i_0 + loop_ub) + m] = hex_data[(i_0 << 2) + 1];
    }

    for (i_0 = 0; i_0 < loop_ub_1; i_0++) {
      b_hex_data[((i_0 + loop_ub) + m) + loop_ub_0] = hex_data[i_0 << 2];
    }

    b_tmp = rt_roundd_snf(ARDroneHover_hex2dec(b_hex_data, hex_size_0));
    if (b_tmp < 4.294967296E+9) {
      if (b_tmp >= 0.0) {
        x = (uint32_T)b_tmp;
      } else {
        x = 0U;
      }
    } else {
      x = MAX_uint32_T;
    }

    memcpy((void *)&rtb_w, (void *)&x, (uint32_T)((size_t)1 * sizeof(real32_T)));
    if ((rtb_status[31] == 1) && (bytesLeft < 0.2)) {
      /* '<S5>:1:49' */
      /* '<S5>:1:50' */
      bytesLeft = ARDroneHover_DW.hPrev;
    } else {
      if (rtb_status[31] == 1) {
        /* '<S5>:1:51' */
        /* '<S5>:1:52' */
        ARDroneHover_DW.hPrev = bytesLeft;
      }
    }

    rtb_yawAngle /= 1000.0F;
    rtb_u /= 1000.0F;
    rtb_v /= 1000.0F;
    rtb_w /= 1000.0F;

    /* DataTypeConversion: '<S1>/Type Conversion1' incorporates:
     *  MATLAB Function: '<S1>/ARDrone data decoding'
     */
    ARDroneHover_B.TypeConversion1 = b_res / 1000.0F;

    /* DataTypeConversion: '<S1>/Type Conversion2' incorporates:
     *  MATLAB Function: '<S1>/ARDrone data decoding'
     */
    ARDroneHover_B.TypeConversion2 = res / 1000.0F;

    /* ManualSwitch: '<Root>/Manual Switch2' incorporates:
     *  Constant: '<Root>/commands disabled'
     *  Constant: '<Root>/commands enabled'
     */
    if (ARDroneHover_P.ManualSwitch2_CurrentSetting == 1) {
      bytesToRead = ARDroneHover_P.commandsdisabled_Value;
    } else {
      bytesToRead = ARDroneHover_P.commandsenabled_Value;
    }

    /* End of ManualSwitch: '<Root>/Manual Switch2' */

    /* MATLAB Function: '<S1>/This block sets the heading angle to zero when the  commands from the Simulink controller are enabled. ' incorporates:
     *  DataTypeConversion: '<S1>/Type Conversion3'
     *  UnitDelay: '<S1>/Unit Delay to avoid algebraic loop'
     */
    /* MATLAB Function 'ARDrone Wi-Fi  Block/This block sets the heading angle to zero when the  commands from the Simulink controller are enabled. ': '<S8>:1' */
    /* '<S8>:1:6' */
    ARDroneHover_B.yawOut = rtb_yawAngle;
    if ((ARDroneHover_DW.UnitDelaytoavoidalgebraicloop_DSTATE == 1.0) &&
        (bytesToRead == 1.0)) {
      /* '<S8>:1:19' */
      /* '<S8>:1:20' */
      ARDroneHover_B.yawOut = rtb_yawAngle - ARDroneHover_DW.yaw0;

      /* '<S8>:1:21' */
      ARDroneHover_DW.mode = 1.0;
    } else {
      if ((ARDroneHover_DW.UnitDelaytoavoidalgebraicloop_DSTATE == 1.0) &&
          (ARDroneHover_DW.mode == 0.0)) {
        /* '<S8>:1:22' */
        /* '<S8>:1:23' */
        ARDroneHover_DW.yaw0 = rtb_yawAngle;
      }
    }

    /* '<S8>:1:27' */
    b_tmp = ARDroneHover_B.yawOut;
    if ((!rtIsInf(ARDroneHover_B.yawOut)) && (!rtIsNaN(ARDroneHover_B.yawOut)))
    {
      if (ARDroneHover_B.yawOut == 0.0) {
        ARDroneHover_B.yawOut = 0.0;
      } else {
        ARDroneHover_B.yawOut = fmod(ARDroneHover_B.yawOut, 360.0);
        if (ARDroneHover_B.yawOut == 0.0) {
          ARDroneHover_B.yawOut = 0.0;
        } else {
          if (b_tmp < 0.0) {
            ARDroneHover_B.yawOut += 360.0;
          }
        }
      }
    } else {
      ARDroneHover_B.yawOut = (rtNaN);
    }

    if (ARDroneHover_B.yawOut > 180.0) {
      /* '<S8>:1:28' */
      /* '<S8>:1:29' */
      ARDroneHover_B.yawOut += -360.0;
    }

    /* End of MATLAB Function: '<S1>/This block sets the heading angle to zero when the  commands from the Simulink controller are enabled. ' */
    /* DataTypeConversion: '<S1>/Type Conversion4' incorporates:
     *  MATLAB Function: '<S1>/ARDrone data decoding'
     */
    ARDroneHover_B.TypeConversion4 = bytesLeft;

    /* Constant: '<S17>/Constant1' */
    ARDroneHover_B.Constant1[0] = ARDroneHover_P.Constant1_Value[0];
    ARDroneHover_B.Constant1[1] = ARDroneHover_P.Constant1_Value[1];
  }

  /* Integrator: '<S17>/Integrator' */
  if (ARDroneHover_DW.Integrator_IWORK != 0) {
    ARDroneHover_X.Integrator_CSTATE[0] = ARDroneHover_B.Constant1[0];
    ARDroneHover_X.Integrator_CSTATE[1] = ARDroneHover_B.Constant1[1];
  }

  ARDroneHover_B.Integrator[0] = ARDroneHover_X.Integrator_CSTATE[0];
  ARDroneHover_B.Integrator[1] = ARDroneHover_X.Integrator_CSTATE[1];

  /* End of Integrator: '<S17>/Integrator' */
  if (rtmIsMajorTimeStep(ARDroneHover_M)) {
  }

  /* Gain: '<Root>/deg 2 rad' */
  ARDroneHover_B.deg2rad[0] = ARDroneHover_P.deg2rad_Gain *
    ARDroneHover_B.TypeConversion1;
  ARDroneHover_B.deg2rad[1] = ARDroneHover_P.deg2rad_Gain *
    ARDroneHover_B.TypeConversion2;
  ARDroneHover_B.deg2rad[2] = ARDroneHover_P.deg2rad_Gain *
    ARDroneHover_B.yawOut;
  if (rtmIsMajorTimeStep(ARDroneHover_M)) {
    /* DataTypeConversion: '<S1>/Type Conversion5' */
    ARDroneHover_B.TypeConversion5 = rtb_u;

    /* DataTypeConversion: '<S1>/Type Conversion6' */
    ARDroneHover_B.TypeConversion6 = rtb_v;

    /* DataTypeConversion: '<S1>/Type Conversion7' */
    ARDroneHover_B.TypeConversion7 = rtb_w;

    /* SignalConversion: '<S4>/TmpSignal ConversionAtTo WorkspaceInport1' */
    ARDroneHover_B.TmpSignalConversionAtToWorkspaceInport1[0] =
      ARDroneHover_B.deg2rad[0];
    ARDroneHover_B.TmpSignalConversionAtToWorkspaceInport1[1] =
      ARDroneHover_B.deg2rad[1];
    ARDroneHover_B.TmpSignalConversionAtToWorkspaceInport1[2] =
      ARDroneHover_B.deg2rad[2];
    ARDroneHover_B.TmpSignalConversionAtToWorkspaceInport1[3] =
      ARDroneHover_B.TypeConversion5;
    ARDroneHover_B.TmpSignalConversionAtToWorkspaceInport1[4] =
      ARDroneHover_B.TypeConversion6;
    ARDroneHover_B.TmpSignalConversionAtToWorkspaceInport1[5] =
      ARDroneHover_B.TypeConversion7;
    ARDroneHover_B.TmpSignalConversionAtToWorkspaceInport1[6] =
      ARDroneHover_B.Integrator[0];
    ARDroneHover_B.TmpSignalConversionAtToWorkspaceInport1[7] =
      ARDroneHover_B.Integrator[1];
    ARDroneHover_B.TmpSignalConversionAtToWorkspaceInport1[8] =
      ARDroneHover_B.TypeConversion4;
  }

  /* Gain: '<S4>/deg 2 rad1' */
  ARDroneHover_B.deg2rad1 = ARDroneHover_P.deg2rad1_Gain *
    ARDroneHover_B.deg2rad[2];
  if (rtmIsMajorTimeStep(ARDroneHover_M)) {
    /* Saturate: '<S1>/Saturation 1' incorporates:
     *  Constant: '<Root>/Constant'
     */
    if (ARDroneHover_P.Constant_Value > ARDroneHover_P.Saturation1_UpperSat) {
      rtb_Saturation1 = ARDroneHover_P.Saturation1_UpperSat;
    } else if (ARDroneHover_P.Constant_Value <
               ARDroneHover_P.Saturation1_LowerSat) {
      rtb_Saturation1 = ARDroneHover_P.Saturation1_LowerSat;
    } else {
      rtb_Saturation1 = ARDroneHover_P.Constant_Value;
    }

    /* End of Saturate: '<S1>/Saturation 1' */

    /* Saturate: '<S1>/Saturation 2' incorporates:
     *  Constant: '<Root>/Constant'
     */
    if (ARDroneHover_P.Constant_Value > ARDroneHover_P.Saturation2_UpperSat) {
      rtb_Saturation2 = ARDroneHover_P.Saturation2_UpperSat;
    } else if (ARDroneHover_P.Constant_Value <
               ARDroneHover_P.Saturation2_LowerSat) {
      rtb_Saturation2 = ARDroneHover_P.Saturation2_LowerSat;
    } else {
      rtb_Saturation2 = ARDroneHover_P.Constant_Value;
    }

    /* End of Saturate: '<S1>/Saturation 2' */

    /* Saturate: '<S1>/Saturation 3' incorporates:
     *  Constant: '<Root>/Constant'
     */
    if (ARDroneHover_P.Constant_Value > ARDroneHover_P.Saturation3_UpperSat) {
      rtb_Saturation3 = ARDroneHover_P.Saturation3_UpperSat;
    } else if (ARDroneHover_P.Constant_Value <
               ARDroneHover_P.Saturation3_LowerSat) {
      rtb_Saturation3 = ARDroneHover_P.Saturation3_LowerSat;
    } else {
      rtb_Saturation3 = ARDroneHover_P.Constant_Value;
    }

    /* End of Saturate: '<S1>/Saturation 3' */
  }

  /* Step: '<Root>/Step1' incorporates:
   *  Step: '<Root>/Step'
   */
  b_tmp = ARDroneHover_M->Timing.t[0];
  if (b_tmp < ARDroneHover_P.Step1_Time) {
    bytesLeft = ARDroneHover_P.Step1_Y0;
  } else {
    bytesLeft = ARDroneHover_P.Step1_YFinal;
  }

  /* End of Step: '<Root>/Step1' */

  /* Step: '<Root>/Step' */
  if (b_tmp < ARDroneHover_P.Step_Time) {
    b_tmp = ARDroneHover_P.Step_Y0;
  } else {
    b_tmp = ARDroneHover_P.Step_YFinal;
  }

  /* Gain: '<S13>/proportional control gain' incorporates:
   *  Sum: '<Root>/Sum'
   *  Sum: '<S13>/Sum3'
   */
  bytesLeft = ((bytesLeft + b_tmp) - ARDroneHover_B.TypeConversion4) *
    ARDroneHover_P.proportionalcontrolgain_Gain;

  /* Saturate: '<S1>/Saturation 4' */
  if (bytesLeft > ARDroneHover_P.Saturation4_UpperSat) {
    ARDroneHover_B.Saturation4 = ARDroneHover_P.Saturation4_UpperSat;
  } else if (bytesLeft < ARDroneHover_P.Saturation4_LowerSat) {
    ARDroneHover_B.Saturation4 = ARDroneHover_P.Saturation4_LowerSat;
  } else {
    ARDroneHover_B.Saturation4 = bytesLeft;
  }

  /* End of Saturate: '<S1>/Saturation 4' */
  if (rtmIsMajorTimeStep(ARDroneHover_M)) {
    /* ManualSwitch: '<Root>/Manual Switch1' incorporates:
     *  Constant: '<Root>/land'
     *  Constant: '<Root>/take off'
     */
    if (ARDroneHover_P.ManualSwitch1_CurrentSetting == 1) {
      bytesLeft = ARDroneHover_P.land_Value;
    } else {
      bytesLeft = ARDroneHover_P.takeoff_Value;
    }

    /* End of ManualSwitch: '<Root>/Manual Switch1' */

    /* MATLAB Function: '<S7>/Drone state request' */
    /* MATLAB Function 'ARDrone Wi-Fi  Block/Subsystem1/Drone state request': '<S9>:1' */
    /* '<S9>:1:26' */
    /* '<S9>:1:32' */
    /* '<S9>:1:38' */
    /* '<S9>:1:42' */
    /* '<S9>:1:51' */
    /* '<S9>:1:54' */
    /* '<S9>:1:65' */
    /* '<S9>:1:72' */
    /* '<S9>:1:113' */
    /* '<S9>:1:16' */
    /* '<S9>:1:19' */
    /* '<S9>:1:22' */
    memset(&ARDroneHover_B.dataControl[0], 0, 150U * sizeof(uint8_T));

    /* '<S9>:1:26' */
    m = 0;
    guard1 = false;
    if (ARDroneHover_DW.SequenceNumber <= 1.0) {
      /* '<S9>:1:29' */
      guard1 = true;
    } else {
      if (!rtIsInf(ARDroneHover_DW.SequenceNumber)) {
        b_tmp = fmod(ARDroneHover_DW.SequenceNumber, 100.0);
        if (b_tmp == 0.0) {
          b_tmp = 0.0;
        }
      } else {
        b_tmp = (rtNaN);
      }

      if (b_tmp == 0.0) {
        /* '<S9>:1:29' */
        guard1 = true;
      }
    }

    if (guard1) {
      /* '<S9>:1:30' */
      ARDroneHover_DW.SequenceNumber++;

      /* '<S9>:1:31' */
      /* '<S9>:1:32' */
      ARDroneHover_getString(ARDroneHover_DW.SequenceNumber, strCmd_data,
        hex_size);
      m = 41 + hex_size[1];
      for (i_0 = 0; i_0 < 10; i_0++) {
        cmd_data[i_0] = c[i_0];
      }

      aux = hex_size[0] * hex_size[1];
      if (0 <= aux - 1) {
        memcpy(&cmd_data[10], &strCmd_data[0], aux * sizeof(char_T));
      }

      for (i_0 = 0; i_0 < 30; i_0++) {
        cmd_data[(i_0 + aux) + 10] = d[i_0];
      }

      cmd_data[40 + aux] = '\x0d';
    }

    /* '<S9>:1:36' */
    ARDroneHover_DW.SequenceNumber++;

    /* '<S9>:1:37' */
    ARDroneHover_getString(ARDroneHover_DW.SequenceNumber, strCmd_data, hex_size);

    /* '<S9>:1:38' */
    aux = m;

    /* MATLAB Function: '<S7>/Drone state request' */
    loop_ub = hex_size[1];
    m = (m + hex_size[1]) + 11;
    for (i_0 = 0; i_0 < 10; i_0++) {
      /* MATLAB Function: '<S7>/Drone state request' */
      cmd_data[aux + i_0] = e[i_0];
    }

    for (i_0 = 0; i_0 < loop_ub; i_0++) {
      /* MATLAB Function: '<S7>/Drone state request' */
      cmd_data[(aux + i_0) + 10] = strCmd_data[i_0];
    }

    /* MATLAB Function: '<S7>/Drone state request' */
    cmd_data[(aux + hex_size[1]) + 10] = '\x0d';

    /* ManualSwitch: '<Root>/Manual Switch' incorporates:
     *  Constant: '<Root>/_'
     *  Constant: '<Root>/stop'
     */
    if (ARDroneHover_P.ManualSwitch_CurrentSetting == 1) {
      b_tmp = ARDroneHover_P._Value;
    } else {
      b_tmp = ARDroneHover_P.stop_Value;
    }

    /* End of ManualSwitch: '<Root>/Manual Switch' */

    /* MATLAB Function: '<S7>/Drone state request' */
    if (b_tmp == 1.0) {
      /* '<S9>:1:41' */
      /* '<S9>:1:42' */
      m = hex_size[1] + 18;
      loop_ub = hex_size[0] * hex_size[1] - 1;
      for (i_0 = 0; i_0 < 7; i_0++) {
        cmd_data[i_0] = f[i_0];
      }

      if (0 <= loop_ub) {
        memcpy(&cmd_data[7], &strCmd_data[0], (loop_ub + 1) * sizeof(char_T));
      }

      for (i_0 = 0; i_0 < 10; i_0++) {
        cmd_data[(i_0 + loop_ub) + 8] = g[i_0];
      }

      cmd_data[18 + loop_ub] = '\x0d';
    } else if ((ARDroneHover_DW.SequenceNumber > 20.0) &&
               (ARDroneHover_DW.SequenceNumber < 22.0)) {
      /* '<S9>:1:46' */
      /* '<S9>:1:49' */
      ARDroneHover_DW.SequenceNumber = 22.0;

      /* '<S9>:1:50' */
      /* '<S9>:1:51' */
      ARDroneHover_getString(22.0, strCmd_data, hex_size);
      loop_ub = (m + hex_size[1]) + 10;
      if (0 <= m - 1) {
        memcpy(&cmd_data_0[0], &cmd_data[0], m * sizeof(char_T));
      }

      for (i_0 = 0; i_0 < 9; i_0++) {
        cmd_data_0[i_0 + m] = i[i_0];
      }

      aux = hex_size[0] * hex_size[1];
      for (i_0 = 0; i_0 < aux; i_0++) {
        cmd_data_0[(i_0 + m) + 9] = strCmd_data[i_0];
      }

      cmd_data_0[(m + aux) + 9] = '\x0d';
      m = loop_ub;
      if (0 <= loop_ub - 1) {
        memcpy(&cmd_data[0], &cmd_data_0[0], loop_ub * sizeof(char_T));
      }
    } else if ((ARDroneHover_DW.SequenceNumber >= 22.0) &&
               (ARDroneHover_DW.SequenceNumber < 25.0)) {
      /* '<S9>:1:53' */
      /* '<S9>:1:54' */
      aux = m;
      m = (m + hex_size[1]) + 41;
      loop_ub = hex_size[1] - 1;
      for (i_0 = 0; i_0 < 10; i_0++) {
        cmd_data[aux + i_0] = c[i_0];
      }

      for (i_0 = 0; i_0 <= loop_ub; i_0++) {
        cmd_data[(aux + i_0) + 10] = strCmd_data[i_0];
      }

      for (i_0 = 0; i_0 < 30; i_0++) {
        cmd_data[((aux + i_0) + loop_ub) + 11] = h[i_0];
      }

      cmd_data[(aux + loop_ub) + 41] = '\x0d';
    } else {
      if (ARDroneHover_DW.SequenceNumber >= 25.0) {
        /* '<S9>:1:57' */
        if (bytesLeft == 1.0) {
          /* '<S9>:1:59' */
          if (rtb_status[31] == 0) {
            /* '<S9>:1:61' */
            /* '<S9>:1:63' */
            ARDroneHover_DW.SequenceNumber++;

            /* '<S9>:1:64' */
            /* '<S9>:1:65' */
            ARDroneHover_getString(ARDroneHover_DW.SequenceNumber, strCmd_data,
              hex_size);
            loop_ub = (m + hex_size[1]) + 18;
            if (0 <= m - 1) {
              memcpy(&cmd_data_0[0], &cmd_data[0], m * sizeof(char_T));
            }

            for (i_0 = 0; i_0 < 7; i_0++) {
              cmd_data_0[i_0 + m] = f[i_0];
            }

            aux = hex_size[0] * hex_size[1];
            for (i_0 = 0; i_0 < aux; i_0++) {
              cmd_data_0[(i_0 + m) + 7] = strCmd_data[i_0];
            }

            for (i_0 = 0; i_0 < 10; i_0++) {
              cmd_data_0[((i_0 + m) + aux) + 7] = j[i_0];
            }

            cmd_data_0[(m + aux) + 17] = '\x0d';
            m = loop_ub;
            if (0 <= loop_ub - 1) {
              memcpy(&cmd_data[0], &cmd_data_0[0], loop_ub * sizeof(char_T));
            }
          } else {
            if ((rtb_status[31] == 1) && (bytesToRead == 1.0)) {
              /* '<S9>:1:67' */
              /* '<S9>:1:69' */
              ARDroneHover_DW.SequenceNumber++;

              /* '<S9>:1:70' */
              /* '<S9>:1:72' */
              ARDroneHover_getString(ARDroneHover_DW.SequenceNumber, strCmd_data,
                hex_size);
              loop_ub = (m + hex_size[1]) + 11;
              if (0 <= m - 1) {
                memcpy(&cmd_data_0[0], &cmd_data[0], m * sizeof(char_T));
              }

              for (i_0 = 0; i_0 < 8; i_0++) {
                cmd_data_0[i_0 + m] = l[i_0];
              }

              aux = hex_size[0] * hex_size[1];
              for (i_0 = 0; i_0 < aux; i_0++) {
                cmd_data_0[(i_0 + m) + 8] = strCmd_data[i_0];
              }

              i_0 = m + aux;
              cmd_data_0[i_0 + 8] = ',';
              cmd_data_0[i_0 + 9] = '1';
              cmd_data_0[i_0 + 10] = ',';
              if (0 <= loop_ub - 1) {
                memcpy(&cmd_data[0], &cmd_data_0[0], loop_ub * sizeof(char_T));
              }

              /* '<S9>:1:74' */
              /* '<S9>:1:75' */
              ARDroneHover_getString(fabs((real_T)ARDroneHover_float2IEEE754
                (rtb_Saturation1)), strCmd_data, hex_size);
              loop_ub_0 = hex_size[1];
              aux = hex_size[0] * hex_size[1] - 1;
              if (0 <= aux) {
                memcpy(&strAux_data[0], &strCmd_data[0], (aux + 1) * sizeof
                       (char_T));
              }

              if (rtb_Saturation1 < 0.0) {
                /* '<S9>:1:76' */
                /* '<S9>:1:77' */
                loop_ub_0 = 1 + hex_size[1];
                strAux_data[0] = '-';
                if (0 <= aux) {
                  memcpy(&strAux_data[1], &strCmd_data[0], (aux + 1) * sizeof
                         (char_T));
                }
              }

              /* '<S9>:1:79' */
              aux = loop_ub + loop_ub_0;
              m = aux + 1;
              for (i_0 = 0; i_0 < loop_ub_0; i_0++) {
                cmd_data[loop_ub + i_0] = strAux_data[i_0];
              }

              cmd_data[aux] = ',';

              /* '<S9>:1:81' */
              /* '<S9>:1:82' */
              ARDroneHover_getString(fabs((real_T)ARDroneHover_float2IEEE754
                (rtb_Saturation2)), strCmd_data, hex_size);
              loop_ub_0 = hex_size[1];
              loop_ub = hex_size[0] * hex_size[1] - 1;
              if (0 <= loop_ub) {
                memcpy(&strAux_data[0], &strCmd_data[0], (loop_ub + 1) * sizeof
                       (char_T));
              }

              if (rtb_Saturation2 < 0.0) {
                /* '<S9>:1:83' */
                /* '<S9>:1:84' */
                loop_ub_0 = 1 + hex_size[1];
                loop_ub = hex_size[0] * hex_size[1] - 1;
                strAux_data[0] = '-';
                if (0 <= loop_ub) {
                  memcpy(&strAux_data[1], &strCmd_data[0], (loop_ub + 1) *
                         sizeof(char_T));
                }
              }

              /* '<S9>:1:86' */
              aux = m;
              m = (m + loop_ub_0) + 1;
              for (i_0 = 0; i_0 < loop_ub_0; i_0++) {
                cmd_data[aux + i_0] = strAux_data[i_0];
              }

              cmd_data[aux + loop_ub_0] = ',';

              /* '<S9>:1:88' */
              aux = ARDroneHover_float2IEEE754(ARDroneHover_B.Saturation4);

              /* '<S9>:1:89' */
              ARDroneHover_getString(fabs((real_T)aux), strCmd_data, hex_size);
              loop_ub_0 = hex_size[1];
              loop_ub = hex_size[0] * hex_size[1] - 1;
              if (0 <= loop_ub) {
                memcpy(&strAux_data[0], &strCmd_data[0], (loop_ub + 1) * sizeof
                       (char_T));
              }

              if (ARDroneHover_B.Saturation4 < 0.0) {
                /* '<S9>:1:90' */
                /* '<S9>:1:91' */
                loop_ub_0 = 1 + hex_size[1];
                loop_ub = hex_size[0] * hex_size[1] - 1;
                strAux_data[0] = '-';
                if (0 <= loop_ub) {
                  memcpy(&strAux_data[1], &strCmd_data[0], (loop_ub + 1) *
                         sizeof(char_T));
                }
              }

              /* '<S9>:1:93' */
              aux = m;
              m = (m + loop_ub_0) + 1;
              for (i_0 = 0; i_0 < loop_ub_0; i_0++) {
                cmd_data[aux + i_0] = strAux_data[i_0];
              }

              cmd_data[aux + loop_ub_0] = ',';

              /* '<S9>:1:96' */
              /* '<S9>:1:97' */
              ARDroneHover_getString(fabs((real_T)ARDroneHover_float2IEEE754
                (rtb_Saturation3)), strCmd_data, hex_size);
              loop_ub_0 = hex_size[1];
              loop_ub = hex_size[0] * hex_size[1] - 1;
              if (0 <= loop_ub) {
                memcpy(&strAux_data[0], &strCmd_data[0], (loop_ub + 1) * sizeof
                       (char_T));
              }

              if (rtb_Saturation3 < 0.0) {
                /* '<S9>:1:98' */
                /* '<S9>:1:99' */
                /* '<S9>:1:100' */
                loop_ub_0 = 1 + hex_size[1];
                loop_ub = hex_size[0] * hex_size[1] - 1;
                strAux_data[0] = '-';
                if (0 <= loop_ub) {
                  memcpy(&strAux_data[1], &strCmd_data[0], (loop_ub + 1) *
                         sizeof(char_T));
                }
              }

              /* '<S9>:1:102' */
              aux = m;
              m = (m + loop_ub_0) + 1;
              for (i_0 = 0; i_0 < loop_ub_0; i_0++) {
                cmd_data[aux + i_0] = strAux_data[i_0];
              }

              cmd_data[aux + loop_ub_0] = '\x0d';
            }
          }
        } else {
          if ((bytesLeft == 0.0) && (rtb_status[31] == 1)) {
            /* '<S9>:1:108' */
            /* '<S9>:1:110' */
            /* '<S9>:1:111' */
            ARDroneHover_DW.SequenceNumber++;

            /* '<S9>:1:112' */
            /* '<S9>:1:113' */
            ARDroneHover_getString(ARDroneHover_DW.SequenceNumber, strCmd_data,
              hex_size);
            loop_ub = (m + hex_size[1]) + 18;
            if (0 <= m - 1) {
              memcpy(&cmd_data_0[0], &cmd_data[0], m * sizeof(char_T));
            }

            for (i_0 = 0; i_0 < 7; i_0++) {
              cmd_data_0[i_0 + m] = f[i_0];
            }

            aux = hex_size[0] * hex_size[1];
            for (i_0 = 0; i_0 < aux; i_0++) {
              cmd_data_0[(i_0 + m) + 7] = strCmd_data[i_0];
            }

            for (i_0 = 0; i_0 < 10; i_0++) {
              cmd_data_0[((i_0 + m) + aux) + 7] = k[i_0];
            }

            cmd_data_0[(m + aux) + 17] = '\x0d';
            m = loop_ub;
            if (0 <= loop_ub - 1) {
              memcpy(&cmd_data[0], &cmd_data_0[0], loop_ub * sizeof(char_T));
            }
          }
        }
      }
    }

    /* '<S9>:1:126' */
    for (i_0 = 0; i_0 < m; i_0++) {
      ARDroneHover_B.dataControl[i_0] = (uint8_T)cmd_data[i_0];
    }

    /* '<S9>:1:131' */
    ARDroneHover_B.isFlying = rtb_status[31];

    /* S-Function (sldrtpo): '<S7>/Packet Output' */
    /* S-Function Block: <S7>/Packet Output */

    /* no code required */

    /* RateTransition: '<S10>/Rate Transition' incorporates:
     *  Constant: '<S10>/Constant'
     */
    if (ARDroneHover_M->Timing.RateInteraction.TID1_2) {
      ARDroneHover_B.RateTransition[0] = ARDroneHover_P.Constant_Value_k[0];
      ARDroneHover_B.RateTransition[1] = ARDroneHover_P.Constant_Value_k[1];
    }

    /* End of RateTransition: '<S10>/Rate Transition' */
  }

  /* MATLAB Function: '<S17>/Velocity from vehicle body frame  to inertial NED  frame' */
  /* MATLAB Function 'Baseline Controller1/Position controller/Coordinate trnasformation  from inertial frame to body frame ': '<S16>:1' */
  /* '<S16>:1:3' */
  /* '<S16>:1:4' */
  /* MATLAB Function 'Position estimation Important:This block provides an  inaccurate extimation of position  based on  velocity information. /Position estimation/Velocity from vehicle body frame  to inertial NED  frame': '<S18>:1' */
  /* '<S18>:1:3' */
  /* '<S18>:1:4' */
  ARDroneHover_B.Vel_xy[0] = 0.0;
  bytesToRead = cos(ARDroneHover_B.deg2rad[2]);
  ARDroneHover_B.Vel_xy[0] += bytesToRead * ARDroneHover_B.TypeConversion5;
  rtb_Saturation1 = sin(ARDroneHover_B.deg2rad[2]);
  ARDroneHover_B.Vel_xy[0] += -rtb_Saturation1 * ARDroneHover_B.TypeConversion6;
  ARDroneHover_B.Vel_xy[1] = 0.0;
  ARDroneHover_B.Vel_xy[1] += rtb_Saturation1 * ARDroneHover_B.TypeConversion5;
  ARDroneHover_B.Vel_xy[1] += bytesToRead * ARDroneHover_B.TypeConversion6;

  /* Clock: '<Root>/Clock1' */
  ARDroneHover_B.Clock1 = ARDroneHover_M->Timing.t[0];
  if (rtmIsMajorTimeStep(ARDroneHover_M)) {
  }
}

/* Model update function for TID0 */
void ARDroneHover_update0(void)        /* Sample time: [0.0s, 0.0s] */
{
  /* Update for Integrator: '<S17>/Integrator' */
  ARDroneHover_DW.Integrator_IWORK = 0;
  if (rtmIsMajorTimeStep(ARDroneHover_M)) {
    /* Update for UnitDelay: '<S1>/Unit Delay to avoid algebraic loop' */
    ARDroneHover_DW.UnitDelaytoavoidalgebraicloop_DSTATE =
      ARDroneHover_B.isFlying;

    /* Update for S-Function (sldrtpo): '<S7>/Packet Output' */

    /* S-Function Block: <S7>/Packet Output */
    {
      uint8_T outdata[150U];
      RTWin_ANYTYPEPTR outdp;
      outdp.p_uint8_T = outdata;

      {
        int_T i1;
        const uint8_T *u0 = &ARDroneHover_B.dataControl[0];
        for (i1=0; i1 < 150; i1++) {
          {
            uint8_T pktout = u0[i1];
            *outdp.p_uint8_T++ = pktout;
          }
        }
      }

      RTBIO_DriverIO(1, STREAMOUTPUT, IOWRITE, 150U,
                     &ARDroneHover_P.PacketOutput_PacketID, (double*) outdata,
                     NULL);
    }
  }

  if (rtmIsMajorTimeStep(ARDroneHover_M)) {
    rt_ertODEUpdateContinuousStates(&ARDroneHover_M->solverInfo);
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++ARDroneHover_M->Timing.clockTick0)) {
    ++ARDroneHover_M->Timing.clockTickH0;
  }

  ARDroneHover_M->Timing.t[0] = rtsiGetSolverStopTime
    (&ARDroneHover_M->solverInfo);

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++ARDroneHover_M->Timing.clockTick1)) {
    ++ARDroneHover_M->Timing.clockTickH1;
  }

  ARDroneHover_M->Timing.t[1] = ARDroneHover_M->Timing.clockTick1 *
    ARDroneHover_M->Timing.stepSize1 + ARDroneHover_M->Timing.clockTickH1 *
    ARDroneHover_M->Timing.stepSize1 * 4294967296.0;
}

/* Derivatives for root system: '<Root>' */
void ARDroneHover_derivatives(void)
{
  XDot_ARDroneHover_T *_rtXdot;
  _rtXdot = ((XDot_ARDroneHover_T *) ARDroneHover_M->derivs);

  /* Derivatives for Integrator: '<S17>/Integrator' */
  _rtXdot->Integrator_CSTATE[0] = ARDroneHover_B.Vel_xy[0];
  _rtXdot->Integrator_CSTATE[1] = ARDroneHover_B.Vel_xy[1];
}

/* Model output function for TID2 */
void ARDroneHover_output2(void)        /* Sample time: [0.65s, 0.0s] */
{
  /* S-Function (sldrtpo): '<S10>/Packet Output1' */
  /* S-Function Block: <S10>/Packet Output1 */

  /* no code required */
}

/* Model update function for TID2 */
void ARDroneHover_update2(void)        /* Sample time: [0.65s, 0.0s] */
{
  /* Update for S-Function (sldrtpo): '<S10>/Packet Output1' */

  /* S-Function Block: <S10>/Packet Output1 */
  {
    uint8_T outdata[2U];
    RTWin_ANYTYPEPTR outdp;
    outdp.p_uint8_T = outdata;

    {
      uint8_T pktout = ARDroneHover_B.RateTransition[0];
      *outdp.p_uint8_T++ = pktout;
    }

    {
      uint8_T pktout = ARDroneHover_B.RateTransition[1];
      *outdp.p_uint8_T++ = pktout;
    }

    RTBIO_DriverIO(0, STREAMOUTPUT, IOWRITE, 2U,
                   &ARDroneHover_P.PacketOutput1_PacketID, (double*) outdata,
                   NULL);
  }

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick2"
   * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick2 and the high bits
   * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++ARDroneHover_M->Timing.clockTick2)) {
    ++ARDroneHover_M->Timing.clockTickH2;
  }

  ARDroneHover_M->Timing.t[2] = ARDroneHover_M->Timing.clockTick2 *
    ARDroneHover_M->Timing.stepSize2 + ARDroneHover_M->Timing.clockTickH2 *
    ARDroneHover_M->Timing.stepSize2 * 4294967296.0;
}

/* Model output wrapper function for compatibility with a static main program */
void ARDroneHover_output(int_T tid)
{
  switch (tid) {
   case 0 :
    ARDroneHover_output0();
    break;

   case 2 :
    ARDroneHover_output2();
    break;

   default :
    break;
  }
}

/* Model update wrapper function for compatibility with a static main program */
void ARDroneHover_update(int_T tid)
{
  switch (tid) {
   case 0 :
    ARDroneHover_update0();
    break;

   case 2 :
    ARDroneHover_update2();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void ARDroneHover_initialize(void)
{
  /* Start for Constant: '<S17>/Constant1' */
  ARDroneHover_B.Constant1[0] = ARDroneHover_P.Constant1_Value[0];
  ARDroneHover_B.Constant1[1] = ARDroneHover_P.Constant1_Value[1];

  /* Start for S-Function (sldrtpo): '<S7>/Packet Output' */

  /* S-Function Block: <S7>/Packet Output */
  /* no initial value should be set */

  /* Start for S-Function (sldrtpo): '<S10>/Packet Output1' */

  /* S-Function Block: <S10>/Packet Output1 */
  /* no initial value should be set */

  /* InitializeConditions for UnitDelay: '<S1>/Unit Delay to avoid algebraic loop' */
  ARDroneHover_DW.UnitDelaytoavoidalgebraicloop_DSTATE =
    ARDroneHover_P.UnitDelaytoavoidalgebraicloop_InitialCondition;

  /* InitializeConditions for Integrator: '<S17>/Integrator' */
  if (rtmIsFirstInitCond(ARDroneHover_M)) {
    ARDroneHover_X.Integrator_CSTATE[0] = 0.0;
    ARDroneHover_X.Integrator_CSTATE[1] = 0.0;
  }

  ARDroneHover_DW.Integrator_IWORK = 1;

  /* End of InitializeConditions for Integrator: '<S17>/Integrator' */

  /* SystemInitialize for MATLAB Function: '<S1>/Data synchronization ' */
  memset(&ARDroneHover_DW.buffer[0], 0, sizeof(uint8_T) << 10U);
  ARDroneHover_DW.countBuffer = 0.0;
  ARDroneHover_DW.count = 0.0;
  ARDroneHover_DW.countHeader = 0.0;

  /* SystemInitialize for MATLAB Function: '<S1>/ARDrone data decoding' */
  ARDroneHover_DW.hPrev = 0.0;

  /* SystemInitialize for MATLAB Function: '<S1>/Data synchronization ' */
  memset(&ARDroneHover_DW.frame[0], 0, 496U * sizeof(uint8_T));
  memset(&ARDroneHover_DW.lastFrame[0], 0, 496U * sizeof(uint8_T));

  /* SystemInitialize for MATLAB Function: '<S1>/ARDrone data decoding' */
  memset(&ARDroneHover_DW.dataPrev[0], 0, 496U * sizeof(uint8_T));

  /* SystemInitialize for MATLAB Function: '<S1>/This block sets the heading angle to zero when the  commands from the Simulink controller are enabled. ' */
  ARDroneHover_DW.yaw0 = 0.0;
  ARDroneHover_DW.mode = 0.0;

  /* SystemInitialize for MATLAB Function: '<S7>/Drone state request' */
  ARDroneHover_DW.SequenceNumber = 1.0;

  /* set "at time zero" to false */
  if (rtmIsFirstInitCond(ARDroneHover_M)) {
    rtmSetFirstInitCond(ARDroneHover_M, 0);
  }
}

/* Model terminate function */
void ARDroneHover_terminate(void)
{
  /* Terminate for S-Function (sldrtpo): '<S7>/Packet Output' */

  /* S-Function Block: <S7>/Packet Output */
  /* no initial value should be set */

  /* Terminate for S-Function (sldrtpo): '<S10>/Packet Output1' */

  /* S-Function Block: <S10>/Packet Output1 */
  /* no initial value should be set */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  if (tid == 1)
    tid = 0;
  ARDroneHover_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  ARDroneHover_update(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  ARDroneHover_initialize();
}

void MdlTerminate(void)
{
  ARDroneHover_terminate();
}

/* Registration function */
RT_MODEL_ARDroneHover_T *ARDroneHover(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)ARDroneHover_M, 0,
                sizeof(RT_MODEL_ARDroneHover_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&ARDroneHover_M->solverInfo,
                          &ARDroneHover_M->Timing.simTimeStep);
    rtsiSetTPtr(&ARDroneHover_M->solverInfo, &rtmGetTPtr(ARDroneHover_M));
    rtsiSetStepSizePtr(&ARDroneHover_M->solverInfo,
                       &ARDroneHover_M->Timing.stepSize0);
    rtsiSetdXPtr(&ARDroneHover_M->solverInfo, &ARDroneHover_M->derivs);
    rtsiSetContStatesPtr(&ARDroneHover_M->solverInfo, (real_T **)
                         &ARDroneHover_M->contStates);
    rtsiSetNumContStatesPtr(&ARDroneHover_M->solverInfo,
      &ARDroneHover_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&ARDroneHover_M->solverInfo,
      &ARDroneHover_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&ARDroneHover_M->solverInfo,
      &ARDroneHover_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&ARDroneHover_M->solverInfo,
      &ARDroneHover_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&ARDroneHover_M->solverInfo, (&rtmGetErrorStatus
      (ARDroneHover_M)));
    rtsiSetRTModelPtr(&ARDroneHover_M->solverInfo, ARDroneHover_M);
  }

  rtsiSetSimTimeStep(&ARDroneHover_M->solverInfo, MAJOR_TIME_STEP);
  ARDroneHover_M->intgData.f[0] = ARDroneHover_M->odeF[0];
  ARDroneHover_M->contStates = ((real_T *) &ARDroneHover_X);
  rtsiSetSolverData(&ARDroneHover_M->solverInfo, (void *)
                    &ARDroneHover_M->intgData);
  rtsiSetSolverName(&ARDroneHover_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = ARDroneHover_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    ARDroneHover_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    ARDroneHover_M->Timing.sampleTimes =
      (&ARDroneHover_M->Timing.sampleTimesArray[0]);
    ARDroneHover_M->Timing.offsetTimes =
      (&ARDroneHover_M->Timing.offsetTimesArray[0]);

    /* task periods */
    ARDroneHover_M->Timing.sampleTimes[0] = (0.0);
    ARDroneHover_M->Timing.sampleTimes[1] = (0.065);
    ARDroneHover_M->Timing.sampleTimes[2] = (0.65);

    /* task offsets */
    ARDroneHover_M->Timing.offsetTimes[0] = (0.0);
    ARDroneHover_M->Timing.offsetTimes[1] = (0.0);
    ARDroneHover_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(ARDroneHover_M, &ARDroneHover_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = ARDroneHover_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits = ARDroneHover_M->Timing.perTaskSampleHitsArray;
    ARDroneHover_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    ARDroneHover_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(ARDroneHover_M, -1);
  ARDroneHover_M->Timing.stepSize0 = 0.065;
  ARDroneHover_M->Timing.stepSize1 = 0.065;
  ARDroneHover_M->Timing.stepSize2 = 0.65;
  rtmSetFirstInitCond(ARDroneHover_M, 1);

  /* External mode info */
  ARDroneHover_M->Sizes.checksums[0] = (2346787871U);
  ARDroneHover_M->Sizes.checksums[1] = (4003601368U);
  ARDroneHover_M->Sizes.checksums[2] = (3409927909U);
  ARDroneHover_M->Sizes.checksums[3] = (1343324922U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[13];
    ARDroneHover_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = &rtAlwaysEnabled;
    systemRan[12] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(ARDroneHover_M->extModeInfo,
      &ARDroneHover_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(ARDroneHover_M->extModeInfo,
                        ARDroneHover_M->Sizes.checksums);
    rteiSetTPtr(ARDroneHover_M->extModeInfo, rtmGetTPtr(ARDroneHover_M));
  }

  ARDroneHover_M->solverInfoPtr = (&ARDroneHover_M->solverInfo);
  ARDroneHover_M->Timing.stepSize = (0.065);
  rtsiSetFixedStepSize(&ARDroneHover_M->solverInfo, 0.065);
  rtsiSetSolverMode(&ARDroneHover_M->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  ARDroneHover_M->blockIO = ((void *) &ARDroneHover_B);
  (void) memset(((void *) &ARDroneHover_B), 0,
                sizeof(B_ARDroneHover_T));

  {
    int32_T i;
    for (i = 0; i < 9; i++) {
      ARDroneHover_B.TmpSignalConversionAtToWorkspaceInport1[i] = 0.0;
    }

    ARDroneHover_B.TypeConversion = 0.0;
    ARDroneHover_B.TypeConversion1 = 0.0;
    ARDroneHover_B.TypeConversion2 = 0.0;
    ARDroneHover_B.TypeConversion4 = 0.0;
    ARDroneHover_B.Constant1[0] = 0.0;
    ARDroneHover_B.Constant1[1] = 0.0;
    ARDroneHover_B.Integrator[0] = 0.0;
    ARDroneHover_B.Integrator[1] = 0.0;
    ARDroneHover_B.deg2rad[0] = 0.0;
    ARDroneHover_B.deg2rad[1] = 0.0;
    ARDroneHover_B.deg2rad[2] = 0.0;
    ARDroneHover_B.TypeConversion5 = 0.0;
    ARDroneHover_B.TypeConversion6 = 0.0;
    ARDroneHover_B.TypeConversion7 = 0.0;
    ARDroneHover_B.deg2rad1 = 0.0;
    ARDroneHover_B.Saturation4 = 0.0;
    ARDroneHover_B.Clock1 = 0.0;
    ARDroneHover_B.Vel_xy[0] = 0.0;
    ARDroneHover_B.Vel_xy[1] = 0.0;
    ARDroneHover_B.yawOut = 0.0;
    ARDroneHover_B.isFlying = 0.0;
  }

  /* parameters */
  ARDroneHover_M->defaultParam = ((real_T *)&ARDroneHover_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &ARDroneHover_X;
    ARDroneHover_M->contStates = (x);
    (void) memset((void *)&ARDroneHover_X, 0,
                  sizeof(X_ARDroneHover_T));
  }

  /* states (dwork) */
  ARDroneHover_M->dwork = ((void *) &ARDroneHover_DW);
  (void) memset((void *)&ARDroneHover_DW, 0,
                sizeof(DW_ARDroneHover_T));
  ARDroneHover_DW.UnitDelaytoavoidalgebraicloop_DSTATE = 0.0;
  ARDroneHover_DW.yaw0 = 0.0;
  ARDroneHover_DW.mode = 0.0;
  ARDroneHover_DW.SequenceNumber = 0.0;
  ARDroneHover_DW.count = 0.0;
  ARDroneHover_DW.countHeader = 0.0;
  ARDroneHover_DW.countBuffer = 0.0;
  ARDroneHover_DW.hPrev = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    ARDroneHover_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  ARDroneHover_M->Sizes.numContStates = (2);/* Number of continuous states */
  ARDroneHover_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  ARDroneHover_M->Sizes.numY = (0);    /* Number of model outputs */
  ARDroneHover_M->Sizes.numU = (0);    /* Number of model inputs */
  ARDroneHover_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  ARDroneHover_M->Sizes.numSampTimes = (3);/* Number of sample times */
  ARDroneHover_M->Sizes.numBlocks = (69);/* Number of blocks */
  ARDroneHover_M->Sizes.numBlockIO = (21);/* Number of block outputs */
  ARDroneHover_M->Sizes.numBlockPrms = (43);/* Sum of parameter "widths" */
  return ARDroneHover_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
