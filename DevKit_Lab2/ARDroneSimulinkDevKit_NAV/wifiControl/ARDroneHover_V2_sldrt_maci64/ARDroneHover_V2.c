/*
 * ARDroneHover_V2.c
 *
 * Code generation for model "ARDroneHover_V2".
 *
 * Model version              : $Id: UAV_PIL.mdl 965 2013-03-21 01:08:53Z escobar $
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C source code generated on : Thu Apr  5 08:19:12 2018
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Mac OS X)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ARDroneHover_V2.h"
#include "ARDroneHover_V2_private.h"
#include "ARDroneHover_V2_dt.h"

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
  0.005, 0.0,
  0.05, 0.0,
};

/* list of Simulink Desktop Real-Time boards */
const int SLDRTBoardCount = 2;
SLDRTBOARD SLDRTBoards[2] = {
  { "Standard_Devices/UDP_Protocol", 5554U, 2, SLDRTBoardOptions0 },

  { "Standard_Devices/UDP_Protocol", 5556U, 2, SLDRTBoardOptions1 },
};

/* Block signals (auto storage) */
B_ARDroneHover_V2_T ARDroneHover_V2_B;

/* Continuous states */
X_ARDroneHover_V2_T ARDroneHover_V2_X;

/* Block states (auto storage) */
DW_ARDroneHover_V2_T ARDroneHover_V2_DW;

/* Real-time model */
RT_MODEL_ARDroneHover_V2_T ARDroneHover_V2_M_;
RT_MODEL_ARDroneHover_V2_T *const ARDroneHover_V2_M = &ARDroneHover_V2_M_;

/* Forward declaration for local functions */
static void ARDroneHover_V2_dec2hex(const uint8_T d[4], char_T s_data[], int32_T
  s_size[2]);
static real_T ARDroneHover_V2_hex2dec(const char_T s_data[], const int32_T
  s_size[2]);
static void ARDroneHover_V2_getString(real_T a, char_T strOut_data[], int32_T
  strOut_size[2]);
static int32_T ARDroneHover_V2_float2IEEE754(real_T fVal);
static void rate_monotonic_scheduler(void);
time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(ARDroneHover_V2_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(ARDroneHover_V2_M, 2);
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
  if (ARDroneHover_V2_M->Timing.TaskCounters.TID[1] == 0) {
    ARDroneHover_V2_M->Timing.RateInteraction.TID1_2 =
      (ARDroneHover_V2_M->Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    ARDroneHover_V2_M->Timing.perTaskSampleHits[5] =
      ARDroneHover_V2_M->Timing.RateInteraction.TID1_2;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (ARDroneHover_V2_M->Timing.TaskCounters.TID[2])++;
  if ((ARDroneHover_V2_M->Timing.TaskCounters.TID[2]) > 9) {/* Sample time: [0.05s, 0.0s] */
    ARDroneHover_V2_M->Timing.TaskCounters.TID[2] = 0;
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
  ARDroneHover_V2_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Function for MATLAB Function: '<S1>/ARDrone data decoding' */
static void ARDroneHover_V2_dec2hex(const uint8_T d[4], char_T s_data[], int32_T
  s_size[2])
{
  uint8_T di;
  uint8_T r;
  int32_T j;
  char_T b_s_data[8];
  int32_T firstcol;
  boolean_T p;
  char_T b_s_data_0[8];
  int32_T b_s_size_idx_1;
  boolean_T exitg1;
  boolean_T exitg2;
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

  b_s_size_idx_1 = 2;
  for (j = 0; j < 8; j++) {
    b_s_data[j] = s_data[j];
  }

  firstcol = 2;
  j = 1;
  exitg1 = false;
  while ((!exitg1) && (j <= 1)) {
    p = false;
    j = 0;
    exitg2 = false;
    while ((!exitg2) && (j <= 3)) {
      if (s_data[j] != '0') {
        p = true;
        exitg2 = true;
      } else {
        j++;
      }
    }

    if (p) {
      firstcol = 1;
      exitg1 = true;
    } else {
      j = 2;
    }
  }

  if (firstcol > 1) {
    for (firstcol = 0; firstcol + 1 < 5; firstcol++) {
      b_s_data[firstcol] = b_s_data[firstcol + 4];
    }

    b_s_data_0[0] = b_s_data[0];
    b_s_data_0[1] = b_s_data[1];
    b_s_data_0[2] = b_s_data[2];
    b_s_data_0[3] = b_s_data[3];
    b_s_size_idx_1 = 1;
    for (j = 0; j < 4; j++) {
      b_s_data[j] = b_s_data_0[j];
    }
  }

  s_size[0] = 4;
  s_size[1] = b_s_size_idx_1;
  b_s_size_idx_1 <<= 2;
  if (0 <= b_s_size_idx_1 - 1) {
    memcpy(&s_data[0], &b_s_data[0], b_s_size_idx_1 * sizeof(char_T));
  }
}

/* Function for MATLAB Function: '<S1>/ARDrone data decoding' */
static real_T ARDroneHover_V2_hex2dec(const char_T s_data[], const int32_T
  s_size[2])
{
  real_T x;
  real_T p16;
  int32_T j;
  int32_T b;
  int32_T b_j;
  x = 0.0;
  p16 = 1.0;
  b = (int32_T)(((-1.0 - (real_T)s_size[1]) + 1.0) / -1.0);
  for (b_j = 1; b_j - 1 < b; b_j++) {
    j = s_size[1] - b_j;
    if (s_data[s_size[0] * j] != ' ') {
      j = (uint8_T)s_data[s_size[0] * j];
      if ((j != 0) && (j != 48)) {
        if (!(j <= 57)) {
          if (j > 70) {
            j -= 39;
          } else {
            j -= 7;
          }
        }

        x += ((real_T)j - 48.0) * p16;
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
static void ARDroneHover_V2_getString(real_T a, char_T strOut_data[], int32_T
  strOut_size[2])
{
  int32_T d;
  uint8_T digit_data[11];
  int32_T k;
  real_T r;
  int32_T digit_size_idx_1;

  /* '<S9>:1:140' */
  d = 0;
  if ((a >= 10.0) && (a < 100.0)) {
    /* '<S9>:1:146' */
    /* '<S9>:1:147' */
    d = 1;
  }

  if ((a >= 100.0) && (a < 1000.0)) {
    /* '<S9>:1:150' */
    /* '<S9>:1:151' */
    d = 2;
  }

  if ((a >= 1000.0) && (a < 10000.0)) {
    /* '<S9>:1:154' */
    /* '<S9>:1:155' */
    d = 3;
  }

  if ((a >= 10000.0) && (a < 100000.0)) {
    /* '<S9>:1:158' */
    /* '<S9>:1:159' */
    d = 4;
  }

  if ((a >= 100000.0) && (a < 1.0E+6)) {
    /* '<S9>:1:162' */
    /* '<S9>:1:163' */
    d = 5;
  }

  if ((a >= 1.0E+6) && (a < 1.0E+7)) {
    /* '<S9>:1:166' */
    /* '<S9>:1:167' */
    d = 6;
  }

  if ((a >= 1.0E+7) && (a < 1.0E+8)) {
    /* '<S9>:1:170' */
    /* '<S9>:1:171' */
    d = 7;
  }

  if ((a >= 1.0E+8) && (a < 1.0E+9)) {
    /* '<S9>:1:174' */
    /* '<S9>:1:175' */
    d = 8;
  }

  if ((a >= 1.0E+9) && (a < 1.0E+10)) {
    /* '<S9>:1:178' */
    /* '<S9>:1:179' */
    d = 9;
  }

  if (a >= 1.0E+10) {
    /* '<S9>:1:182' */
    /* '<S9>:1:183' */
    d = 10;
  }

  /* '<S9>:1:188' */
  digit_size_idx_1 = d + 1;
  if (0 <= d) {
    memset(&digit_data[0], 0, (d + 1) * sizeof(uint8_T));
  }

  /* '<S9>:1:191' */
  for (k = 0; k <= d; k++) {
    /* '<S9>:1:191' */
    /* '<S9>:1:193' */
    if (!rtIsInf(a)) {
      if (a == 0.0) {
        r = 0.0;
      } else {
        r = fmod(a, rt_powd_snf(10.0, 1.0 + (real_T)k));
        if (r == 0.0) {
          r = 0.0;
        }
      }
    } else {
      r = (rtNaN);
    }

    /* '<S9>:1:196' */
    r = r / rt_powd_snf(10.0, (1.0 + (real_T)k) - 1.0) + 48.0;
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

    digit_data[d - k] = (uint8_T)(r < 0.0 ? (int32_T)(int8_T)-(int8_T)(uint8_T)
      -r : (int32_T)(int8_T)(uint8_T)r);
  }

  /* '<S9>:1:201' */
  strOut_size[0] = 1;
  strOut_size[1] = digit_size_idx_1;
  for (d = 0; d < digit_size_idx_1; d++) {
    strOut_data[d] = (int8_T)digit_data[d];
  }
}

/* Function for MATLAB Function: '<S7>/Drone state request' */
static int32_T ARDroneHover_V2_float2IEEE754(real_T fVal)
{
  int32_T iVal;
  char_T binData[32];
  char_T binData2[32];
  int32_T bit;
  real_T b_iVal;
  uint8_T y[4];
  real32_T x;
  int32_T b_k;

  /* '<S9>:1:211' */
  /* '<S9>:1:209' */
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

  /* '<S9>:1:211' */
  for (b_k = 0; b_k < 8; b_k++) {
    binData2[b_k] = binData[(b_k << 2) + 3];
    binData2[b_k + 8] = binData[(b_k << 2) + 2];
    binData2[b_k + 16] = binData[(b_k << 2) + 1];
    binData2[b_k + 24] = binData[b_k << 2];
  }

  /* '<S9>:1:212' */
  b_iVal = 0.0;

  /* '<S9>:1:213' */
  for (b_k = 0; b_k < 32; b_k++) {
    /* '<S9>:1:213' */
    if (binData2[31 - b_k] == '1') {
      /* '<S9>:1:215' */
      /* '<S9>:1:216' */
      bit = 1;
    } else {
      /* '<S9>:1:218' */
      bit = 0;
    }

    if (32 - b_k == 1) {
      /* '<S9>:1:221' */
      /* '<S9>:1:222' */
      b_iVal -= (real_T)bit * 2.147483648E+9;
    } else {
      /* '<S9>:1:224' */
      b_iVal += rt_powd_snf(2.0, 32.0 - (32.0 + -(real_T)b_k)) * (real_T)bit;
    }
  }

  /* '<S9>:1:229' */
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
void ARDroneHover_V2_output0(void)     /* Sample time: [0.0s, 0.0s] */
{
  real_T bytesToRead;
  real_T bytesLeft;
  int32_T m;
  real32_T heading_unwrapped;
  char_T hex_data[8];
  char_T b_hex_data[8];
  real32_T res;
  real32_T b_res;
  char_T cmd_data[149];
  char_T strCmd_data[11];
  int32_T aux;
  char_T strAux_data[12];
  real_T r;
  static const char_T c[10] = { 'A', 'T', '*', 'C', 'O', 'N', 'F', 'I', 'G', '='
  };

  static const char_T d[31] = { ',', '\"', 'g', 'e', 'n', 'e', 'r', 'a', 'l',
    ':', 'n', 'a', 'v', 'd', 'a', 't', 'a', '_', 'd', 'e', 'm', 'o', '\"', ',',
    '\"', 'F', 'A', 'L', 'S', 'E', '\"' };

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

  real32_T rtb_psi;
  real32_T rtb_vx;
  real32_T rtb_vy;
  real32_T rtb_vz;
  real32_T rtb_altitude_raw;
  real_T rtb_Saturation4;
  real_T rtb_ManualSwitch1;
  int8_T rtb_ardrone_state[32];
  int32_T i_0;
  char_T hex_data_0[8];
  int32_T loop_ub;
  uint8_T tmp_data[10000];
  int32_T loop_ub_0;
  int32_T loop_ub_1;
  char_T cmd_data_0[149];
  int32_T hex_size[2];
  int32_T hex_size_0[2];
  int32_T hex_size_1[2];
  int32_T hex_size_2[2];
  int32_T hex_size_3[2];
  int32_T hex_size_4[2];
  int32_T hex_size_5[2];
  int32_T hex_size_6[2];
  int32_T hex_size_7[2];
  int32_T hex_size_8[2];
  int32_T hex_size_9[2];
  int32_T hex_size_a[2];
  int32_T hex_size_b[2];
  int32_T hex_size_c[2];
  int32_T hex_size_d[2];
  int32_T hex_size_e[2];
  int32_T hex_size_f[2];
  int32_T hex_size_g[2];
  int32_T hex_size_h[2];
  int32_T hex_size_i[2];
  int32_T hex_size_j[2];
  int32_T hex_size_k[2];
  int32_T hex_size_l[2];
  int32_T hex_size_m[2];
  int32_T hex_size_n[2];
  int32_T hex_size_o[2];
  int32_T strAux_size_idx_1;
  uint32_T x;
  real_T rtb_Saturation4_tmp;
  real_T u0_tmp;
  boolean_T guard1 = false;
  boolean_T exitg1;
  if (rtmIsMajorTimeStep(ARDroneHover_V2_M)) {
    /* set solver stop time */
    if (!(ARDroneHover_V2_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&ARDroneHover_V2_M->solverInfo,
                            ((ARDroneHover_V2_M->Timing.clockTickH0 + 1) *
        ARDroneHover_V2_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&ARDroneHover_V2_M->solverInfo,
                            ((ARDroneHover_V2_M->Timing.clockTick0 + 1) *
        ARDroneHover_V2_M->Timing.stepSize0 +
        ARDroneHover_V2_M->Timing.clockTickH0 *
        ARDroneHover_V2_M->Timing.stepSize0 * 4294967296.0));
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(ARDroneHover_V2_M)) {
    ARDroneHover_V2_M->Timing.t[0] = rtsiGetT(&ARDroneHover_V2_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(ARDroneHover_V2_M)) {
    /* S-Function (sldrtpi): '<S1>/Packet Input' */
    /* S-Function Block: <S1>/Packet Input */
    {
      uint8_T indata[2190U];
      int status = RTBIO_DriverIO(0, STREAMINPUT, IOREAD, 2190U,
        &ARDroneHover_V2_P.PacketInput_PacketID, (double*) indata, NULL);
      ARDroneHover_V2_B.PacketInput_o2 = status & 0x1;/* Data Ready port */
      if (status & 0x1) {
        RTWin_ANYTYPEPTR indp;
        indp.p_uint8_T = indata;

        {
          int_T i1;
          uint8_T *y0 = &ARDroneHover_V2_B.PacketInput_o1[0];
          for (i1=0; i1 < 2190; i1++) {
            y0[i1] = *indp.p_uint8_T++;
          }
        }
      }
    }

    /* MATLAB Function: '<S1>/Data synchronization ' */
    /* MATLAB Function 'ARDrone Wi-Fi  Block/Data synchronization ': '<S6>:1' */
    /* '<S6>:1:52' */
    for (i_0 = 0; i_0 < 2190; i_0++) {
      ARDroneHover_V2_DW.buffer[(int32_T)(ARDroneHover_V2_DW.countBuffer +
        ((real_T)i_0 + 1.0)) - 1] = ARDroneHover_V2_B.PacketInput_o1[i_0];
    }

    /* '<S6>:1:54' */
    bytesToRead = ARDroneHover_V2_DW.countBuffer + 2190.0;

    /* '<S6>:1:59' */
    aux = 0;
    exitg1 = false;
    while ((!exitg1) && (aux <= (int32_T)(ARDroneHover_V2_DW.countBuffer +
             2190.0) - 1)) {
      /* '<S6>:1:59' */
      if ((ARDroneHover_V2_DW.countHeader == 4.0) && (ARDroneHover_V2_DW.count <
           2186.0)) {
        /* '<S6>:1:60' */
        /* '<S6>:1:61' */
        bytesLeft = 2186.0 - ARDroneHover_V2_DW.count;
        rtb_Saturation4_tmp = (1.0 + (real_T)aux) + (2186.0 -
          ARDroneHover_V2_DW.count);
        if (1.0 + (real_T)aux > rtb_Saturation4_tmp - 1.0) {
          m = 1;
          loop_ub = 0;
        } else {
          m = aux + 1;
          loop_ub = (int32_T)(rtb_Saturation4_tmp - 1.0);
        }

        /* '<S6>:1:62' */
        i_0 = (int32_T)(ARDroneHover_V2_DW.count + 1.0) - 1;
        loop_ub -= m;
        for (loop_ub_0 = 0; loop_ub_0 <= loop_ub; loop_ub_0++) {
          ARDroneHover_V2_DW.frame[i_0 + loop_ub_0] = ARDroneHover_V2_DW.buffer
            [(m + loop_ub_0) - 1];
        }

        /* '<S6>:1:63' */
        ARDroneHover_V2_DW.count = 2186.0;

        /* '<S6>:1:64' */
        ARDroneHover_V2_DW.countBuffer = (ARDroneHover_V2_DW.countBuffer +
          2190.0) - bytesLeft;
        r = (1.0 + (real_T)aux) + bytesLeft;
        if (r > bytesToRead) {
          aux = 0;
          m = 0;
        } else {
          aux = (int32_T)r - 1;
          m = (int32_T)bytesToRead;
        }

        /* '<S6>:1:65' */
        loop_ub = m - aux;
        for (i_0 = 0; i_0 < loop_ub; i_0++) {
          tmp_data[i_0] = ARDroneHover_V2_DW.buffer[aux + i_0];
        }

        if (0 <= loop_ub - 1) {
          memcpy(&ARDroneHover_V2_DW.buffer[0], &tmp_data[0], loop_ub * sizeof
                 (uint8_T));
        }

        exitg1 = true;
      } else if ((ARDroneHover_V2_DW.countHeader == 3.0) &&
                 (ARDroneHover_V2_DW.buffer[aux] == 85)) {
        /* '<S6>:1:70' */
        /* '<S6>:1:72' */
        ARDroneHover_V2_DW.countHeader = 4.0;
        r = (ARDroneHover_V2_DW.countBuffer + 2190.0) - (1.0 + (real_T)aux);
        if (r > 2186.0) {
          /* '<S6>:1:74' */
          /* '<S6>:1:75' */
          ARDroneHover_V2_DW.count = 2186.0;

          /* '<S6>:1:76' */
          for (i_0 = 0; i_0 < 2186; i_0++) {
            ARDroneHover_V2_DW.frame[(int16_T)i_0] = ARDroneHover_V2_DW.buffer
              [(int32_T)((1.0 + (real_T)aux) + (real_T)(int16_T)(1 + i_0)) - 1];
          }

          /* '<S6>:1:77' */
          ARDroneHover_V2_DW.countBuffer = ((ARDroneHover_V2_DW.countBuffer +
            2190.0) - (1.0 + (real_T)aux)) - 2186.0;
          if (((1.0 + (real_T)aux) + 2186.0) + 1.0 > bytesToRead) {
            aux = 0;
            m = 0;
          } else {
            aux = (int32_T)(((1.0 + (real_T)aux) + 2186.0) + 1.0) - 1;
            m = (int32_T)bytesToRead;
          }

          /* '<S6>:1:78' */
          loop_ub = m - aux;
          for (i_0 = 0; i_0 < loop_ub; i_0++) {
            tmp_data[i_0] = ARDroneHover_V2_DW.buffer[aux + i_0];
          }

          if (0 <= loop_ub - 1) {
            memcpy(&ARDroneHover_V2_DW.buffer[0], &tmp_data[0], loop_ub * sizeof
                   (uint8_T));
          }
        } else {
          /* '<S6>:1:81' */
          ARDroneHover_V2_DW.count = r;
          if (ARDroneHover_V2_DW.count > 0.0) {
            /* '<S6>:1:82' */
            if ((1.0 + (real_T)aux) + 1.0 > ARDroneHover_V2_DW.countBuffer +
                2190.0) {
              aux = 1;
              m = 0;
            } else {
              aux = (int32_T)((1.0 + (real_T)aux) + 1.0);
              m = (int32_T)(ARDroneHover_V2_DW.countBuffer + 2190.0);
            }

            /* '<S6>:1:83' */
            loop_ub = m - aux;
            for (i_0 = 0; i_0 <= loop_ub; i_0++) {
              ARDroneHover_V2_DW.frame[i_0] = ARDroneHover_V2_DW.buffer[(aux +
                i_0) - 1];
            }
          }

          /* '<S6>:1:85' */
          ARDroneHover_V2_DW.countBuffer = 0.0;
        }

        exitg1 = true;
      } else {
        if ((ARDroneHover_V2_DW.countHeader == 2.0) &&
            (ARDroneHover_V2_DW.buffer[aux] == 102)) {
          /* '<S6>:1:92' */
          /* '<S6>:1:93' */
          ARDroneHover_V2_DW.countHeader = 3.0;
        }

        if ((ARDroneHover_V2_DW.countHeader == 1.0) &&
            (ARDroneHover_V2_DW.buffer[aux] == 119)) {
          /* '<S6>:1:96' */
          /* '<S6>:1:97' */
          ARDroneHover_V2_DW.countHeader = 2.0;
        }

        if ((ARDroneHover_V2_DW.countHeader == 0.0) &&
            (ARDroneHover_V2_DW.buffer[aux] == 136)) {
          /* '<S6>:1:100' */
          /* '<S6>:1:101' */
          ARDroneHover_V2_DW.countHeader = 1.0;
        }

        aux++;
      }
    }

    if (ARDroneHover_V2_DW.count == 2186.0) {
      /* '<S6>:1:106' */
      /* '<S6>:1:107' */
      /* '<S6>:1:108' */
      /* '<S6>:1:109' */
      /* '<S6>:1:110' */
      for (i_0 = 0; i_0 < 2186; i_0++) {
        ARDroneHover_V2_DW.lastFrame[i_0] = ARDroneHover_V2_DW.frame[i_0];
        ARDroneHover_V2_DW.frame[i_0] = 0U;
      }

      /* '<S6>:1:111' */
      ARDroneHover_V2_DW.count = 0.0;

      /* '<S6>:1:112' */
      ARDroneHover_V2_DW.countHeader = 0.0;
    } else {
      /* '<S6>:1:115' */
      /* '<S6>:1:116' */
    }

    memcpy(&ARDroneHover_V2_B.frameOut[0], &ARDroneHover_V2_DW.lastFrame[0],
           2186U * sizeof(uint8_T));

    /* End of MATLAB Function: '<S1>/Data synchronization ' */

    /* MATLAB Function: '<S1>/ARDrone data decoding' */
    /* MATLAB Function 'ARDrone Wi-Fi  Block/ARDrone data decoding': '<S5>:1' */
    /* '<S5>:1:9' */
    /* '<S5>:1:16' */
    /* '<S5>:1:18' */
    /* '<S5>:1:20' */
    /* '<S5>:1:25' */
    /* '<S5>:1:98' */
    for (i_0 = 0; i_0 < 32; i_0++) {
      rtb_ardrone_state[i_0] = 0;
    }

    /* '<S5>:1:99' */
    ARDroneHover_V2_dec2hex(&ARDroneHover_V2_B.frameOut[0], hex_data, hex_size);

    /* '<S5>:1:101' */
    loop_ub = hex_size[1];
    m = hex_size[1];
    loop_ub_0 = hex_size[1];
    loop_ub_1 = hex_size[1];
    aux = ((hex_size[1] + hex_size[1]) + hex_size[1]) + hex_size[1];
    for (i_0 = 0; i_0 < loop_ub; i_0++) {
      b_hex_data[i_0] = hex_data[hex_size[0] * i_0 + 3];
    }

    for (i_0 = 0; i_0 < m; i_0++) {
      b_hex_data[i_0 + loop_ub] = hex_data[hex_size[0] * i_0 + 2];
    }

    for (i_0 = 0; i_0 < loop_ub_0; i_0++) {
      b_hex_data[(i_0 + loop_ub) + m] = hex_data[hex_size[0] * i_0 + 1];
    }

    for (i_0 = 0; i_0 < loop_ub_1; i_0++) {
      b_hex_data[((i_0 + loop_ub) + m) + loop_ub_0] = hex_data[hex_size[0] * i_0];
    }

    /* '<S5>:1:102' */
    for (m = 0; m < aux; m++) {
      /* '<S5>:1:102' */
      if (b_hex_data[m] == 'F') {
        /* '<S5>:1:103' */
        /* '<S5>:1:104' */
        rtb_ardrone_state[((1 + m) << 2) - 4] = 1;
        rtb_ardrone_state[((1 + m) << 2) - 3] = 1;
        rtb_ardrone_state[((1 + m) << 2) - 2] = 1;
        rtb_ardrone_state[((1 + m) << 2) - 1] = 1;
      } else if (b_hex_data[m] == 'E') {
        /* '<S5>:1:105' */
        /* '<S5>:1:106' */
        i_0 = ((1 + m) << 2) - 4;
        rtb_ardrone_state[i_0] = 1;
        rtb_ardrone_state[1 + i_0] = 1;
        rtb_ardrone_state[2 + i_0] = 1;
        rtb_ardrone_state[3 + i_0] = 0;
      } else if (b_hex_data[m] == 'D') {
        /* '<S5>:1:107' */
        /* '<S5>:1:108' */
        i_0 = ((1 + m) << 2) - 4;
        rtb_ardrone_state[i_0] = 1;
        rtb_ardrone_state[1 + i_0] = 1;
        rtb_ardrone_state[2 + i_0] = 0;
        rtb_ardrone_state[3 + i_0] = 1;
      } else if (b_hex_data[m] == 'C') {
        /* '<S5>:1:109' */
        /* '<S5>:1:110' */
        i_0 = ((1 + m) << 2) - 4;
        rtb_ardrone_state[i_0] = 1;
        rtb_ardrone_state[1 + i_0] = 1;
        rtb_ardrone_state[2 + i_0] = 0;
        rtb_ardrone_state[3 + i_0] = 0;
      } else if (b_hex_data[m] == 'B') {
        /* '<S5>:1:111' */
        /* '<S5>:1:112' */
        i_0 = ((1 + m) << 2) - 4;
        rtb_ardrone_state[i_0] = 1;
        rtb_ardrone_state[1 + i_0] = 0;
        rtb_ardrone_state[2 + i_0] = 1;
        rtb_ardrone_state[3 + i_0] = 1;
      } else if (b_hex_data[m] == 'A') {
        /* '<S5>:1:113' */
        /* '<S5>:1:114' */
        i_0 = ((1 + m) << 2) - 4;
        rtb_ardrone_state[i_0] = 1;
        rtb_ardrone_state[1 + i_0] = 0;
        rtb_ardrone_state[2 + i_0] = 1;
        rtb_ardrone_state[3 + i_0] = 0;
      } else if (b_hex_data[m] == '9') {
        /* '<S5>:1:115' */
        /* '<S5>:1:116' */
        i_0 = ((1 + m) << 2) - 4;
        rtb_ardrone_state[i_0] = 1;
        rtb_ardrone_state[1 + i_0] = 0;
        rtb_ardrone_state[2 + i_0] = 0;
        rtb_ardrone_state[3 + i_0] = 1;
      } else if (b_hex_data[m] == '8') {
        /* '<S5>:1:117' */
        /* '<S5>:1:118' */
        i_0 = ((1 + m) << 2) - 4;
        rtb_ardrone_state[i_0] = 1;
        rtb_ardrone_state[1 + i_0] = 0;
        rtb_ardrone_state[2 + i_0] = 0;
        rtb_ardrone_state[3 + i_0] = 0;
      } else if (b_hex_data[m] == '7') {
        /* '<S5>:1:119' */
        /* '<S5>:1:120' */
        i_0 = ((1 + m) << 2) - 4;
        rtb_ardrone_state[i_0] = 0;
        rtb_ardrone_state[1 + i_0] = 1;
        rtb_ardrone_state[2 + i_0] = 1;
        rtb_ardrone_state[3 + i_0] = 1;
      } else if (b_hex_data[m] == '6') {
        /* '<S5>:1:121' */
        /* '<S5>:1:122' */
        i_0 = ((1 + m) << 2) - 4;
        rtb_ardrone_state[i_0] = 0;
        rtb_ardrone_state[1 + i_0] = 1;
        rtb_ardrone_state[2 + i_0] = 1;
        rtb_ardrone_state[3 + i_0] = 0;
      } else if (b_hex_data[m] == '5') {
        /* '<S5>:1:123' */
        /* '<S5>:1:124' */
        i_0 = ((1 + m) << 2) - 4;
        rtb_ardrone_state[i_0] = 0;
        rtb_ardrone_state[1 + i_0] = 1;
        rtb_ardrone_state[2 + i_0] = 0;
        rtb_ardrone_state[3 + i_0] = 1;
      } else if (b_hex_data[m] == '4') {
        /* '<S5>:1:125' */
        /* '<S5>:1:126' */
        i_0 = ((1 + m) << 2) - 4;
        rtb_ardrone_state[i_0] = 0;
        rtb_ardrone_state[1 + i_0] = 1;
        rtb_ardrone_state[2 + i_0] = 0;
        rtb_ardrone_state[3 + i_0] = 0;
      } else if (b_hex_data[m] == '3') {
        /* '<S5>:1:127' */
        /* '<S5>:1:128' */
        i_0 = ((1 + m) << 2) - 4;
        rtb_ardrone_state[i_0] = 0;
        rtb_ardrone_state[1 + i_0] = 0;
        rtb_ardrone_state[2 + i_0] = 1;
        rtb_ardrone_state[3 + i_0] = 1;
      } else if (b_hex_data[m] == '2') {
        /* '<S5>:1:129' */
        /* '<S5>:1:130' */
        i_0 = ((1 + m) << 2) - 4;
        rtb_ardrone_state[i_0] = 0;
        rtb_ardrone_state[1 + i_0] = 0;
        rtb_ardrone_state[2 + i_0] = 1;
        rtb_ardrone_state[3 + i_0] = 0;
      } else if (b_hex_data[m] == '1') {
        /* '<S5>:1:131' */
        /* '<S5>:1:132' */
        i_0 = ((1 + m) << 2) - 4;
        rtb_ardrone_state[i_0] = 0;
        rtb_ardrone_state[1 + i_0] = 0;
        rtb_ardrone_state[2 + i_0] = 0;
        rtb_ardrone_state[3 + i_0] = 1;
      } else {
        if (b_hex_data[m] == '0') {
          /* '<S5>:1:133' */
          /* '<S5>:1:134' */
          rtb_ardrone_state[((1 + m) << 2) - 4] = 0;
          rtb_ardrone_state[((1 + m) << 2) - 3] = 0;
          rtb_ardrone_state[((1 + m) << 2) - 2] = 0;
          rtb_ardrone_state[((1 + m) << 2) - 1] = 0;
        }
      }
    }

    /* '<S5>:1:28' */
    /* '<S5>:1:77' */
    ARDroneHover_V2_dec2hex(&ARDroneHover_V2_B.frameOut[20], hex_data, hex_size);

    /* '<S5>:1:78' */
    /* '<S5>:1:80' */
    loop_ub = hex_size[1];
    m = hex_size[1];
    loop_ub_0 = hex_size[1];
    loop_ub_1 = hex_size[1];
    hex_size_o[0] = 1;
    hex_size_o[1] = ((hex_size[1] + hex_size[1]) + hex_size[1]) + hex_size[1];
    for (i_0 = 0; i_0 < loop_ub; i_0++) {
      b_hex_data[i_0] = hex_data[hex_size[0] * i_0 + 3];
    }

    for (i_0 = 0; i_0 < m; i_0++) {
      b_hex_data[i_0 + loop_ub] = hex_data[hex_size[0] * i_0 + 2];
    }

    for (i_0 = 0; i_0 < loop_ub_0; i_0++) {
      b_hex_data[(i_0 + loop_ub) + m] = hex_data[hex_size[0] * i_0 + 1];
    }

    for (i_0 = 0; i_0 < loop_ub_1; i_0++) {
      b_hex_data[((i_0 + loop_ub) + m) + loop_ub_0] = hex_data[hex_size[0] * i_0];
    }

    /* DataTypeConversion: '<S1>/Type Conversion' incorporates:
     *  MATLAB Function: '<S1>/ARDrone data decoding'
     */
    ARDroneHover_V2_B.TypeConversion = ARDroneHover_V2_hex2dec(b_hex_data,
      hex_size_o);

    /* MATLAB Function: '<S1>/ARDrone data decoding' */
    /* '<S5>:1:29' */
    /* '<S5>:1:77' */
    ARDroneHover_V2_dec2hex(&ARDroneHover_V2_B.frameOut[24], hex_data, hex_size);

    /* '<S5>:1:78' */
    /* '<S5>:1:84' */
    loop_ub = hex_size[1];
    m = hex_size[1];
    loop_ub_0 = hex_size[1];
    loop_ub_1 = hex_size[1];
    hex_size_n[0] = 1;
    hex_size_n[1] = ((hex_size[1] + hex_size[1]) + hex_size[1]) + hex_size[1];
    for (i_0 = 0; i_0 < loop_ub; i_0++) {
      b_hex_data[i_0] = hex_data[hex_size[0] * i_0 + 3];
    }

    for (i_0 = 0; i_0 < m; i_0++) {
      b_hex_data[i_0 + loop_ub] = hex_data[hex_size[0] * i_0 + 2];
    }

    for (i_0 = 0; i_0 < loop_ub_0; i_0++) {
      b_hex_data[(i_0 + loop_ub) + m] = hex_data[hex_size[0] * i_0 + 1];
    }

    for (i_0 = 0; i_0 < loop_ub_1; i_0++) {
      b_hex_data[((i_0 + loop_ub) + m) + loop_ub_0] = hex_data[hex_size[0] * i_0];
    }

    r = rt_roundd_snf(ARDroneHover_V2_hex2dec(b_hex_data, hex_size_n));
    if (r < 4.294967296E+9) {
      if (r >= 0.0) {
        x = (uint32_T)r;
      } else {
        x = 0U;
      }
    } else {
      x = MAX_uint32_T;
    }

    memcpy((void *)&res, (void *)&x, (uint32_T)((size_t)1 * sizeof(real32_T)));

    /* '<S5>:1:30' */
    /* '<S5>:1:77' */
    ARDroneHover_V2_dec2hex(&ARDroneHover_V2_B.frameOut[28], hex_data, hex_size);

    /* '<S5>:1:78' */
    /* '<S5>:1:84' */
    loop_ub = hex_size[1];
    m = hex_size[1];
    loop_ub_0 = hex_size[1];
    loop_ub_1 = hex_size[1];
    hex_size_m[0] = 1;
    hex_size_m[1] = ((hex_size[1] + hex_size[1]) + hex_size[1]) + hex_size[1];
    for (i_0 = 0; i_0 < loop_ub; i_0++) {
      b_hex_data[i_0] = hex_data[hex_size[0] * i_0 + 3];
    }

    for (i_0 = 0; i_0 < m; i_0++) {
      b_hex_data[i_0 + loop_ub] = hex_data[hex_size[0] * i_0 + 2];
    }

    for (i_0 = 0; i_0 < loop_ub_0; i_0++) {
      b_hex_data[(i_0 + loop_ub) + m] = hex_data[hex_size[0] * i_0 + 1];
    }

    for (i_0 = 0; i_0 < loop_ub_1; i_0++) {
      b_hex_data[((i_0 + loop_ub) + m) + loop_ub_0] = hex_data[hex_size[0] * i_0];
    }

    r = rt_roundd_snf(ARDroneHover_V2_hex2dec(b_hex_data, hex_size_m));
    if (r < 4.294967296E+9) {
      if (r >= 0.0) {
        x = (uint32_T)r;
      } else {
        x = 0U;
      }
    } else {
      x = MAX_uint32_T;
    }

    memcpy((void *)&b_res, (void *)&x, (uint32_T)((size_t)1 * sizeof(real32_T)));

    /* '<S5>:1:31' */
    /* '<S5>:1:77' */
    ARDroneHover_V2_dec2hex(&ARDroneHover_V2_B.frameOut[32], hex_data, hex_size);

    /* '<S5>:1:78' */
    /* '<S5>:1:84' */
    loop_ub = hex_size[1];
    m = hex_size[1];
    loop_ub_0 = hex_size[1];
    loop_ub_1 = hex_size[1];
    hex_size_l[0] = 1;
    hex_size_l[1] = ((hex_size[1] + hex_size[1]) + hex_size[1]) + hex_size[1];
    for (i_0 = 0; i_0 < loop_ub; i_0++) {
      b_hex_data[i_0] = hex_data[hex_size[0] * i_0 + 3];
    }

    for (i_0 = 0; i_0 < m; i_0++) {
      b_hex_data[i_0 + loop_ub] = hex_data[hex_size[0] * i_0 + 2];
    }

    for (i_0 = 0; i_0 < loop_ub_0; i_0++) {
      b_hex_data[(i_0 + loop_ub) + m] = hex_data[hex_size[0] * i_0 + 1];
    }

    for (i_0 = 0; i_0 < loop_ub_1; i_0++) {
      b_hex_data[((i_0 + loop_ub) + m) + loop_ub_0] = hex_data[hex_size[0] * i_0];
    }

    r = rt_roundd_snf(ARDroneHover_V2_hex2dec(b_hex_data, hex_size_l));
    if (r < 4.294967296E+9) {
      if (r >= 0.0) {
        x = (uint32_T)r;
      } else {
        x = 0U;
      }
    } else {
      x = MAX_uint32_T;
    }

    memcpy((void *)&rtb_psi, (void *)&x, (uint32_T)((size_t)1 * sizeof(real32_T)));

    /* '<S5>:1:32' */
    /* '<S5>:1:77' */
    ARDroneHover_V2_dec2hex(&ARDroneHover_V2_B.frameOut[36], hex_data, hex_size);

    /* '<S5>:1:78' */
    /* '<S5>:1:80' */
    loop_ub = hex_size[1];
    m = hex_size[1];
    loop_ub_0 = hex_size[1];
    loop_ub_1 = hex_size[1];
    hex_size_k[0] = 1;
    hex_size_k[1] = ((hex_size[1] + hex_size[1]) + hex_size[1]) + hex_size[1];
    for (i_0 = 0; i_0 < loop_ub; i_0++) {
      b_hex_data[i_0] = hex_data[hex_size[0] * i_0 + 3];
    }

    for (i_0 = 0; i_0 < m; i_0++) {
      b_hex_data[i_0 + loop_ub] = hex_data[hex_size[0] * i_0 + 2];
    }

    for (i_0 = 0; i_0 < loop_ub_0; i_0++) {
      b_hex_data[(i_0 + loop_ub) + m] = hex_data[hex_size[0] * i_0 + 1];
    }

    for (i_0 = 0; i_0 < loop_ub_1; i_0++) {
      b_hex_data[((i_0 + loop_ub) + m) + loop_ub_0] = hex_data[hex_size[0] * i_0];
    }

    /* '<S5>:1:33' */
    /* '<S5>:1:77' */
    ARDroneHover_V2_dec2hex(&ARDroneHover_V2_B.frameOut[40], hex_data, hex_size);

    /* '<S5>:1:78' */
    /* '<S5>:1:84' */
    loop_ub = hex_size[1];
    m = hex_size[1];
    loop_ub_0 = hex_size[1];
    loop_ub_1 = hex_size[1];
    hex_size_j[0] = 1;
    hex_size_j[1] = ((hex_size[1] + hex_size[1]) + hex_size[1]) + hex_size[1];
    for (i_0 = 0; i_0 < loop_ub; i_0++) {
      hex_data_0[i_0] = hex_data[hex_size[0] * i_0 + 3];
    }

    for (i_0 = 0; i_0 < m; i_0++) {
      hex_data_0[i_0 + loop_ub] = hex_data[hex_size[0] * i_0 + 2];
    }

    for (i_0 = 0; i_0 < loop_ub_0; i_0++) {
      hex_data_0[(i_0 + loop_ub) + m] = hex_data[hex_size[0] * i_0 + 1];
    }

    for (i_0 = 0; i_0 < loop_ub_1; i_0++) {
      hex_data_0[((i_0 + loop_ub) + m) + loop_ub_0] = hex_data[hex_size[0] * i_0];
    }

    r = rt_roundd_snf(ARDroneHover_V2_hex2dec(hex_data_0, hex_size_j));
    if (r < 4.294967296E+9) {
      if (r >= 0.0) {
        x = (uint32_T)r;
      } else {
        x = 0U;
      }
    } else {
      x = MAX_uint32_T;
    }

    memcpy((void *)&rtb_vx, (void *)&x, (uint32_T)((size_t)1 * sizeof(real32_T)));

    /* '<S5>:1:34' */
    /* '<S5>:1:77' */
    ARDroneHover_V2_dec2hex(&ARDroneHover_V2_B.frameOut[44], hex_data, hex_size);

    /* '<S5>:1:78' */
    /* '<S5>:1:84' */
    loop_ub = hex_size[1];
    m = hex_size[1];
    loop_ub_0 = hex_size[1];
    loop_ub_1 = hex_size[1];
    hex_size_i[0] = 1;
    hex_size_i[1] = ((hex_size[1] + hex_size[1]) + hex_size[1]) + hex_size[1];
    for (i_0 = 0; i_0 < loop_ub; i_0++) {
      hex_data_0[i_0] = hex_data[hex_size[0] * i_0 + 3];
    }

    for (i_0 = 0; i_0 < m; i_0++) {
      hex_data_0[i_0 + loop_ub] = hex_data[hex_size[0] * i_0 + 2];
    }

    for (i_0 = 0; i_0 < loop_ub_0; i_0++) {
      hex_data_0[(i_0 + loop_ub) + m] = hex_data[hex_size[0] * i_0 + 1];
    }

    for (i_0 = 0; i_0 < loop_ub_1; i_0++) {
      hex_data_0[((i_0 + loop_ub) + m) + loop_ub_0] = hex_data[hex_size[0] * i_0];
    }

    r = rt_roundd_snf(ARDroneHover_V2_hex2dec(hex_data_0, hex_size_i));
    if (r < 4.294967296E+9) {
      if (r >= 0.0) {
        x = (uint32_T)r;
      } else {
        x = 0U;
      }
    } else {
      x = MAX_uint32_T;
    }

    memcpy((void *)&rtb_vy, (void *)&x, (uint32_T)((size_t)1 * sizeof(real32_T)));

    /* '<S5>:1:35' */
    /* '<S5>:1:77' */
    ARDroneHover_V2_dec2hex(&ARDroneHover_V2_B.frameOut[48], hex_data, hex_size);

    /* '<S5>:1:78' */
    /* '<S5>:1:84' */
    loop_ub = hex_size[1];
    m = hex_size[1];
    loop_ub_0 = hex_size[1];
    loop_ub_1 = hex_size[1];
    hex_size_h[0] = 1;
    hex_size_h[1] = ((hex_size[1] + hex_size[1]) + hex_size[1]) + hex_size[1];
    for (i_0 = 0; i_0 < loop_ub; i_0++) {
      hex_data_0[i_0] = hex_data[hex_size[0] * i_0 + 3];
    }

    for (i_0 = 0; i_0 < m; i_0++) {
      hex_data_0[i_0 + loop_ub] = hex_data[hex_size[0] * i_0 + 2];
    }

    for (i_0 = 0; i_0 < loop_ub_0; i_0++) {
      hex_data_0[(i_0 + loop_ub) + m] = hex_data[hex_size[0] * i_0 + 1];
    }

    for (i_0 = 0; i_0 < loop_ub_1; i_0++) {
      hex_data_0[((i_0 + loop_ub) + m) + loop_ub_0] = hex_data[hex_size[0] * i_0];
    }

    r = rt_roundd_snf(ARDroneHover_V2_hex2dec(hex_data_0, hex_size_h));
    if (r < 4.294967296E+9) {
      if (r >= 0.0) {
        x = (uint32_T)r;
      } else {
        x = 0U;
      }
    } else {
      x = MAX_uint32_T;
    }

    memcpy((void *)&rtb_vz, (void *)&x, (uint32_T)((size_t)1 * sizeof(real32_T)));

    /* '<S5>:1:36' */
    /* '<S5>:1:77' */
    /* '<S5>:1:78' */
    /* '<S5>:1:80' */
    /* '<S5>:1:38' */
    /* '<S5>:1:77' */
    ARDroneHover_V2_dec2hex(&ARDroneHover_V2_B.frameOut[230], hex_data, hex_size);

    /* '<S5>:1:78' */
    /* '<S5>:1:84' */
    loop_ub = hex_size[1];
    m = hex_size[1];
    loop_ub_0 = hex_size[1];
    loop_ub_1 = hex_size[1];
    hex_size_g[0] = 1;
    hex_size_g[1] = ((hex_size[1] + hex_size[1]) + hex_size[1]) + hex_size[1];
    for (i_0 = 0; i_0 < loop_ub; i_0++) {
      hex_data_0[i_0] = hex_data[hex_size[0] * i_0 + 3];
    }

    for (i_0 = 0; i_0 < m; i_0++) {
      hex_data_0[i_0 + loop_ub] = hex_data[hex_size[0] * i_0 + 2];
    }

    for (i_0 = 0; i_0 < loop_ub_0; i_0++) {
      hex_data_0[(i_0 + loop_ub) + m] = hex_data[hex_size[0] * i_0 + 1];
    }

    for (i_0 = 0; i_0 < loop_ub_1; i_0++) {
      hex_data_0[((i_0 + loop_ub) + m) + loop_ub_0] = hex_data[hex_size[0] * i_0];
    }

    r = rt_roundd_snf(ARDroneHover_V2_hex2dec(hex_data_0, hex_size_g));
    if (r < 4.294967296E+9) {
      if (r >= 0.0) {
        x = (uint32_T)r;
      } else {
        x = 0U;
      }
    } else {
      x = MAX_uint32_T;
    }

    memcpy((void *)&rtb_altitude_raw, (void *)&x, (uint32_T)((size_t)1 * sizeof
            (real32_T)));

    /* '<S5>:1:39' */
    /* '<S5>:1:77' */
    ARDroneHover_V2_dec2hex(&ARDroneHover_V2_B.frameOut[234], hex_data, hex_size);

    /* '<S5>:1:78' */
    /* '<S5>:1:84' */
    loop_ub = hex_size[1];
    m = hex_size[1];
    loop_ub_0 = hex_size[1];
    loop_ub_1 = hex_size[1];
    hex_size_f[0] = 1;
    hex_size_f[1] = ((hex_size[1] + hex_size[1]) + hex_size[1]) + hex_size[1];
    for (i_0 = 0; i_0 < loop_ub; i_0++) {
      hex_data_0[i_0] = hex_data[hex_size[0] * i_0 + 3];
    }

    for (i_0 = 0; i_0 < m; i_0++) {
      hex_data_0[i_0 + loop_ub] = hex_data[hex_size[0] * i_0 + 2];
    }

    for (i_0 = 0; i_0 < loop_ub_0; i_0++) {
      hex_data_0[(i_0 + loop_ub) + m] = hex_data[hex_size[0] * i_0 + 1];
    }

    for (i_0 = 0; i_0 < loop_ub_1; i_0++) {
      hex_data_0[((i_0 + loop_ub) + m) + loop_ub_0] = hex_data[hex_size[0] * i_0];
    }

    r = rt_roundd_snf(ARDroneHover_V2_hex2dec(hex_data_0, hex_size_f));
    if (r < 4.294967296E+9) {
      if (r >= 0.0) {
        x = (uint32_T)r;
      } else {
        x = 0U;
      }
    } else {
      x = MAX_uint32_T;
    }

    memcpy((void *)&rtb_altitude_raw, (void *)&x, (uint32_T)((size_t)1 * sizeof
            (real32_T)));

    /* '<S5>:1:40' */
    /* '<S5>:1:77' */
    ARDroneHover_V2_dec2hex(&ARDroneHover_V2_B.frameOut[238], hex_data, hex_size);

    /* '<S5>:1:78' */
    /* '<S5>:1:84' */
    loop_ub = hex_size[1];
    m = hex_size[1];
    loop_ub_0 = hex_size[1];
    loop_ub_1 = hex_size[1];
    hex_size_e[0] = 1;
    hex_size_e[1] = ((hex_size[1] + hex_size[1]) + hex_size[1]) + hex_size[1];
    for (i_0 = 0; i_0 < loop_ub; i_0++) {
      hex_data_0[i_0] = hex_data[hex_size[0] * i_0 + 3];
    }

    for (i_0 = 0; i_0 < m; i_0++) {
      hex_data_0[i_0 + loop_ub] = hex_data[hex_size[0] * i_0 + 2];
    }

    for (i_0 = 0; i_0 < loop_ub_0; i_0++) {
      hex_data_0[(i_0 + loop_ub) + m] = hex_data[hex_size[0] * i_0 + 1];
    }

    for (i_0 = 0; i_0 < loop_ub_1; i_0++) {
      hex_data_0[((i_0 + loop_ub) + m) + loop_ub_0] = hex_data[hex_size[0] * i_0];
    }

    r = rt_roundd_snf(ARDroneHover_V2_hex2dec(hex_data_0, hex_size_e));
    if (r < 4.294967296E+9) {
      if (r >= 0.0) {
        x = (uint32_T)r;
      } else {
        x = 0U;
      }
    } else {
      x = MAX_uint32_T;
    }

    memcpy((void *)&rtb_altitude_raw, (void *)&x, (uint32_T)((size_t)1 * sizeof
            (real32_T)));

    /* '<S5>:1:41' */
    /* '<S5>:1:77' */
    ARDroneHover_V2_dec2hex(&ARDroneHover_V2_B.frameOut[242], hex_data, hex_size);

    /* '<S5>:1:78' */
    /* '<S5>:1:84' */
    loop_ub = hex_size[1];
    m = hex_size[1];
    loop_ub_0 = hex_size[1];
    loop_ub_1 = hex_size[1];
    hex_size_d[0] = 1;
    hex_size_d[1] = ((hex_size[1] + hex_size[1]) + hex_size[1]) + hex_size[1];
    for (i_0 = 0; i_0 < loop_ub; i_0++) {
      hex_data_0[i_0] = hex_data[hex_size[0] * i_0 + 3];
    }

    for (i_0 = 0; i_0 < m; i_0++) {
      hex_data_0[i_0 + loop_ub] = hex_data[hex_size[0] * i_0 + 2];
    }

    for (i_0 = 0; i_0 < loop_ub_0; i_0++) {
      hex_data_0[(i_0 + loop_ub) + m] = hex_data[hex_size[0] * i_0 + 1];
    }

    for (i_0 = 0; i_0 < loop_ub_1; i_0++) {
      hex_data_0[((i_0 + loop_ub) + m) + loop_ub_0] = hex_data[hex_size[0] * i_0];
    }

    r = rt_roundd_snf(ARDroneHover_V2_hex2dec(hex_data_0, hex_size_d));
    if (r < 4.294967296E+9) {
      if (r >= 0.0) {
        x = (uint32_T)r;
      } else {
        x = 0U;
      }
    } else {
      x = MAX_uint32_T;
    }

    memcpy((void *)&rtb_altitude_raw, (void *)&x, (uint32_T)((size_t)1 * sizeof
            (real32_T)));

    /* '<S5>:1:42' */
    /* '<S5>:1:77' */
    ARDroneHover_V2_dec2hex(&ARDroneHover_V2_B.frameOut[246], hex_data, hex_size);

    /* '<S5>:1:78' */
    /* '<S5>:1:84' */
    loop_ub = hex_size[1];
    m = hex_size[1];
    loop_ub_0 = hex_size[1];
    loop_ub_1 = hex_size[1];
    hex_size_c[0] = 1;
    hex_size_c[1] = ((hex_size[1] + hex_size[1]) + hex_size[1]) + hex_size[1];
    for (i_0 = 0; i_0 < loop_ub; i_0++) {
      hex_data_0[i_0] = hex_data[hex_size[0] * i_0 + 3];
    }

    for (i_0 = 0; i_0 < m; i_0++) {
      hex_data_0[i_0 + loop_ub] = hex_data[hex_size[0] * i_0 + 2];
    }

    for (i_0 = 0; i_0 < loop_ub_0; i_0++) {
      hex_data_0[(i_0 + loop_ub) + m] = hex_data[hex_size[0] * i_0 + 1];
    }

    for (i_0 = 0; i_0 < loop_ub_1; i_0++) {
      hex_data_0[((i_0 + loop_ub) + m) + loop_ub_0] = hex_data[hex_size[0] * i_0];
    }

    r = rt_roundd_snf(ARDroneHover_V2_hex2dec(hex_data_0, hex_size_c));
    if (r < 4.294967296E+9) {
      if (r >= 0.0) {
        x = (uint32_T)r;
      } else {
        x = 0U;
      }
    } else {
      x = MAX_uint32_T;
    }

    memcpy((void *)&rtb_altitude_raw, (void *)&x, (uint32_T)((size_t)1 * sizeof
            (real32_T)));

    /* '<S5>:1:43' */
    /* '<S5>:1:77' */
    ARDroneHover_V2_dec2hex(&ARDroneHover_V2_B.frameOut[250], hex_data, hex_size);

    /* '<S5>:1:78' */
    /* '<S5>:1:84' */
    loop_ub = hex_size[1];
    m = hex_size[1];
    loop_ub_0 = hex_size[1];
    loop_ub_1 = hex_size[1];
    hex_size_b[0] = 1;
    hex_size_b[1] = ((hex_size[1] + hex_size[1]) + hex_size[1]) + hex_size[1];
    for (i_0 = 0; i_0 < loop_ub; i_0++) {
      hex_data_0[i_0] = hex_data[hex_size[0] * i_0 + 3];
    }

    for (i_0 = 0; i_0 < m; i_0++) {
      hex_data_0[i_0 + loop_ub] = hex_data[hex_size[0] * i_0 + 2];
    }

    for (i_0 = 0; i_0 < loop_ub_0; i_0++) {
      hex_data_0[(i_0 + loop_ub) + m] = hex_data[hex_size[0] * i_0 + 1];
    }

    for (i_0 = 0; i_0 < loop_ub_1; i_0++) {
      hex_data_0[((i_0 + loop_ub) + m) + loop_ub_0] = hex_data[hex_size[0] * i_0];
    }

    r = rt_roundd_snf(ARDroneHover_V2_hex2dec(hex_data_0, hex_size_b));
    if (r < 4.294967296E+9) {
      if (r >= 0.0) {
        x = (uint32_T)r;
      } else {
        x = 0U;
      }
    } else {
      x = MAX_uint32_T;
    }

    memcpy((void *)&rtb_altitude_raw, (void *)&x, (uint32_T)((size_t)1 * sizeof
            (real32_T)));

    /* '<S5>:1:46' */
    /* '<S5>:1:77' */
    ARDroneHover_V2_dec2hex(&ARDroneHover_V2_B.frameOut[286], hex_data, hex_size);

    /* '<S5>:1:78' */
    /* '<S5>:1:84' */
    loop_ub = hex_size[1];
    m = hex_size[1];
    loop_ub_0 = hex_size[1];
    loop_ub_1 = hex_size[1];
    hex_size_a[0] = 1;
    hex_size_a[1] = ((hex_size[1] + hex_size[1]) + hex_size[1]) + hex_size[1];
    for (i_0 = 0; i_0 < loop_ub; i_0++) {
      hex_data_0[i_0] = hex_data[hex_size[0] * i_0 + 3];
    }

    for (i_0 = 0; i_0 < m; i_0++) {
      hex_data_0[i_0 + loop_ub] = hex_data[hex_size[0] * i_0 + 2];
    }

    for (i_0 = 0; i_0 < loop_ub_0; i_0++) {
      hex_data_0[(i_0 + loop_ub) + m] = hex_data[hex_size[0] * i_0 + 1];
    }

    for (i_0 = 0; i_0 < loop_ub_1; i_0++) {
      hex_data_0[((i_0 + loop_ub) + m) + loop_ub_0] = hex_data[hex_size[0] * i_0];
    }

    r = rt_roundd_snf(ARDroneHover_V2_hex2dec(hex_data_0, hex_size_a));
    if (r < 4.294967296E+9) {
      if (r >= 0.0) {
        x = (uint32_T)r;
      } else {
        x = 0U;
      }
    } else {
      x = MAX_uint32_T;
    }

    memcpy((void *)&rtb_altitude_raw, (void *)&x, (uint32_T)((size_t)1 * sizeof
            (real32_T)));

    /* '<S5>:1:47' */
    /* '<S5>:1:77' */
    ARDroneHover_V2_dec2hex(&ARDroneHover_V2_B.frameOut[290], hex_data, hex_size);

    /* '<S5>:1:78' */
    /* '<S5>:1:84' */
    loop_ub = hex_size[1];
    m = hex_size[1];
    loop_ub_0 = hex_size[1];
    loop_ub_1 = hex_size[1];
    hex_size_9[0] = 1;
    hex_size_9[1] = ((hex_size[1] + hex_size[1]) + hex_size[1]) + hex_size[1];
    for (i_0 = 0; i_0 < loop_ub; i_0++) {
      hex_data_0[i_0] = hex_data[hex_size[0] * i_0 + 3];
    }

    for (i_0 = 0; i_0 < m; i_0++) {
      hex_data_0[i_0 + loop_ub] = hex_data[hex_size[0] * i_0 + 2];
    }

    for (i_0 = 0; i_0 < loop_ub_0; i_0++) {
      hex_data_0[(i_0 + loop_ub) + m] = hex_data[hex_size[0] * i_0 + 1];
    }

    for (i_0 = 0; i_0 < loop_ub_1; i_0++) {
      hex_data_0[((i_0 + loop_ub) + m) + loop_ub_0] = hex_data[hex_size[0] * i_0];
    }

    r = rt_roundd_snf(ARDroneHover_V2_hex2dec(hex_data_0, hex_size_9));
    if (r < 4.294967296E+9) {
      if (r >= 0.0) {
        x = (uint32_T)r;
      } else {
        x = 0U;
      }
    } else {
      x = MAX_uint32_T;
    }

    memcpy((void *)&rtb_altitude_raw, (void *)&x, (uint32_T)((size_t)1 * sizeof
            (real32_T)));

    /* '<S5>:1:49' */
    /* '<S5>:1:77' */
    ARDroneHover_V2_dec2hex(&ARDroneHover_V2_B.frameOut[518], hex_data, hex_size);

    /* '<S5>:1:78' */
    /* '<S5>:1:84' */
    loop_ub = hex_size[1];
    m = hex_size[1];
    loop_ub_0 = hex_size[1];
    loop_ub_1 = hex_size[1];
    hex_size_8[0] = 1;
    hex_size_8[1] = ((hex_size[1] + hex_size[1]) + hex_size[1]) + hex_size[1];
    for (i_0 = 0; i_0 < loop_ub; i_0++) {
      hex_data_0[i_0] = hex_data[hex_size[0] * i_0 + 3];
    }

    for (i_0 = 0; i_0 < m; i_0++) {
      hex_data_0[i_0 + loop_ub] = hex_data[hex_size[0] * i_0 + 2];
    }

    for (i_0 = 0; i_0 < loop_ub_0; i_0++) {
      hex_data_0[(i_0 + loop_ub) + m] = hex_data[hex_size[0] * i_0 + 1];
    }

    for (i_0 = 0; i_0 < loop_ub_1; i_0++) {
      hex_data_0[((i_0 + loop_ub) + m) + loop_ub_0] = hex_data[hex_size[0] * i_0];
    }

    r = rt_roundd_snf(ARDroneHover_V2_hex2dec(hex_data_0, hex_size_8));
    if (r < 4.294967296E+9) {
      if (r >= 0.0) {
        x = (uint32_T)r;
      } else {
        x = 0U;
      }
    } else {
      x = MAX_uint32_T;
    }

    memcpy((void *)&rtb_altitude_raw, (void *)&x, (uint32_T)((size_t)1 * sizeof
            (real32_T)));

    /* '<S5>:1:50' */
    /* '<S5>:1:77' */
    ARDroneHover_V2_dec2hex(&ARDroneHover_V2_B.frameOut[522], hex_data, hex_size);

    /* '<S5>:1:78' */
    /* '<S5>:1:84' */
    loop_ub = hex_size[1];
    m = hex_size[1];
    loop_ub_0 = hex_size[1];
    loop_ub_1 = hex_size[1];
    hex_size_7[0] = 1;
    hex_size_7[1] = ((hex_size[1] + hex_size[1]) + hex_size[1]) + hex_size[1];
    for (i_0 = 0; i_0 < loop_ub; i_0++) {
      hex_data_0[i_0] = hex_data[hex_size[0] * i_0 + 3];
    }

    for (i_0 = 0; i_0 < m; i_0++) {
      hex_data_0[i_0 + loop_ub] = hex_data[hex_size[0] * i_0 + 2];
    }

    for (i_0 = 0; i_0 < loop_ub_0; i_0++) {
      hex_data_0[(i_0 + loop_ub) + m] = hex_data[hex_size[0] * i_0 + 1];
    }

    for (i_0 = 0; i_0 < loop_ub_1; i_0++) {
      hex_data_0[((i_0 + loop_ub) + m) + loop_ub_0] = hex_data[hex_size[0] * i_0];
    }

    r = rt_roundd_snf(ARDroneHover_V2_hex2dec(hex_data_0, hex_size_7));
    if (r < 4.294967296E+9) {
      if (r >= 0.0) {
        x = (uint32_T)r;
      } else {
        x = 0U;
      }
    } else {
      x = MAX_uint32_T;
    }

    memcpy((void *)&rtb_altitude_raw, (void *)&x, (uint32_T)((size_t)1 * sizeof
            (real32_T)));

    /* '<S5>:1:51' */
    /* '<S5>:1:77' */
    ARDroneHover_V2_dec2hex(&ARDroneHover_V2_B.frameOut[530], hex_data, hex_size);

    /* '<S5>:1:78' */
    /* '<S5>:1:84' */
    loop_ub = hex_size[1];
    m = hex_size[1];
    loop_ub_0 = hex_size[1];
    loop_ub_1 = hex_size[1];
    hex_size_6[0] = 1;
    hex_size_6[1] = ((hex_size[1] + hex_size[1]) + hex_size[1]) + hex_size[1];
    for (i_0 = 0; i_0 < loop_ub; i_0++) {
      hex_data_0[i_0] = hex_data[hex_size[0] * i_0 + 3];
    }

    for (i_0 = 0; i_0 < m; i_0++) {
      hex_data_0[i_0 + loop_ub] = hex_data[hex_size[0] * i_0 + 2];
    }

    for (i_0 = 0; i_0 < loop_ub_0; i_0++) {
      hex_data_0[(i_0 + loop_ub) + m] = hex_data[hex_size[0] * i_0 + 1];
    }

    for (i_0 = 0; i_0 < loop_ub_1; i_0++) {
      hex_data_0[((i_0 + loop_ub) + m) + loop_ub_0] = hex_data[hex_size[0] * i_0];
    }

    r = rt_roundd_snf(ARDroneHover_V2_hex2dec(hex_data_0, hex_size_6));
    if (r < 4.294967296E+9) {
      if (r >= 0.0) {
        x = (uint32_T)r;
      } else {
        x = 0U;
      }
    } else {
      x = MAX_uint32_T;
    }

    memcpy((void *)&rtb_altitude_raw, (void *)&x, (uint32_T)((size_t)1 * sizeof
            (real32_T)));

    /* '<S5>:1:53' */
    /* '<S5>:1:77' */
    ARDroneHover_V2_dec2hex(&ARDroneHover_V2_B.frameOut[1711], hex_data,
      hex_size);

    /* '<S5>:1:78' */
    /* '<S5>:1:84' */
    loop_ub = hex_size[1];
    m = hex_size[1];
    loop_ub_0 = hex_size[1];
    loop_ub_1 = hex_size[1];
    hex_size_5[0] = 1;
    hex_size_5[1] = ((hex_size[1] + hex_size[1]) + hex_size[1]) + hex_size[1];
    for (i_0 = 0; i_0 < loop_ub; i_0++) {
      hex_data_0[i_0] = hex_data[hex_size[0] * i_0 + 3];
    }

    for (i_0 = 0; i_0 < m; i_0++) {
      hex_data_0[i_0 + loop_ub] = hex_data[hex_size[0] * i_0 + 2];
    }

    for (i_0 = 0; i_0 < loop_ub_0; i_0++) {
      hex_data_0[(i_0 + loop_ub) + m] = hex_data[hex_size[0] * i_0 + 1];
    }

    for (i_0 = 0; i_0 < loop_ub_1; i_0++) {
      hex_data_0[((i_0 + loop_ub) + m) + loop_ub_0] = hex_data[hex_size[0] * i_0];
    }

    r = rt_roundd_snf(ARDroneHover_V2_hex2dec(hex_data_0, hex_size_5));
    if (r < 4.294967296E+9) {
      if (r >= 0.0) {
        x = (uint32_T)r;
      } else {
        x = 0U;
      }
    } else {
      x = MAX_uint32_T;
    }

    memcpy((void *)&heading_unwrapped, (void *)&x, (uint32_T)((size_t)1 * sizeof
            (real32_T)));

    /* '<S5>:1:54' */
    /* '<S5>:1:77' */
    ARDroneHover_V2_dec2hex(&ARDroneHover_V2_B.frameOut[1715], hex_data,
      hex_size);

    /* '<S5>:1:78' */
    /* '<S5>:1:84' */
    loop_ub = hex_size[1];
    m = hex_size[1];
    loop_ub_0 = hex_size[1];
    loop_ub_1 = hex_size[1];
    hex_size_4[0] = 1;
    hex_size_4[1] = ((hex_size[1] + hex_size[1]) + hex_size[1]) + hex_size[1];
    for (i_0 = 0; i_0 < loop_ub; i_0++) {
      hex_data_0[i_0] = hex_data[hex_size[0] * i_0 + 3];
    }

    for (i_0 = 0; i_0 < m; i_0++) {
      hex_data_0[i_0 + loop_ub] = hex_data[hex_size[0] * i_0 + 2];
    }

    for (i_0 = 0; i_0 < loop_ub_0; i_0++) {
      hex_data_0[(i_0 + loop_ub) + m] = hex_data[hex_size[0] * i_0 + 1];
    }

    for (i_0 = 0; i_0 < loop_ub_1; i_0++) {
      hex_data_0[((i_0 + loop_ub) + m) + loop_ub_0] = hex_data[hex_size[0] * i_0];
    }

    r = rt_roundd_snf(ARDroneHover_V2_hex2dec(hex_data_0, hex_size_4));
    if (r < 4.294967296E+9) {
      if (r >= 0.0) {
        x = (uint32_T)r;
      } else {
        x = 0U;
      }
    } else {
      x = MAX_uint32_T;
    }

    memcpy((void *)&heading_unwrapped, (void *)&x, (uint32_T)((size_t)1 * sizeof
            (real32_T)));

    /* '<S5>:1:55' */
    /* '<S5>:1:77' */
    ARDroneHover_V2_dec2hex(&ARDroneHover_V2_B.frameOut[1719], hex_data,
      hex_size);

    /* '<S5>:1:78' */
    /* '<S5>:1:84' */
    loop_ub = hex_size[1];
    m = hex_size[1];
    loop_ub_0 = hex_size[1];
    loop_ub_1 = hex_size[1];
    hex_size_3[0] = 1;
    hex_size_3[1] = ((hex_size[1] + hex_size[1]) + hex_size[1]) + hex_size[1];
    for (i_0 = 0; i_0 < loop_ub; i_0++) {
      hex_data_0[i_0] = hex_data[hex_size[0] * i_0 + 3];
    }

    for (i_0 = 0; i_0 < m; i_0++) {
      hex_data_0[i_0 + loop_ub] = hex_data[hex_size[0] * i_0 + 2];
    }

    for (i_0 = 0; i_0 < loop_ub_0; i_0++) {
      hex_data_0[(i_0 + loop_ub) + m] = hex_data[hex_size[0] * i_0 + 1];
    }

    for (i_0 = 0; i_0 < loop_ub_1; i_0++) {
      hex_data_0[((i_0 + loop_ub) + m) + loop_ub_0] = hex_data[hex_size[0] * i_0];
    }

    r = rt_roundd_snf(ARDroneHover_V2_hex2dec(hex_data_0, hex_size_3));
    if (r < 4.294967296E+9) {
      if (r >= 0.0) {
        x = (uint32_T)r;
      } else {
        x = 0U;
      }
    } else {
      x = MAX_uint32_T;
    }

    memcpy((void *)&heading_unwrapped, (void *)&x, (uint32_T)((size_t)1 * sizeof
            (real32_T)));

    /* '<S5>:1:57' */
    /* '<S5>:1:77' */
    ARDroneHover_V2_dec2hex(&ARDroneHover_V2_B.frameOut[1736], hex_data,
      hex_size);

    /* '<S5>:1:78' */
    /* '<S5>:1:84' */
    loop_ub = hex_size[1];
    m = hex_size[1];
    loop_ub_0 = hex_size[1];
    loop_ub_1 = hex_size[1];
    hex_size_2[0] = 1;
    hex_size_2[1] = ((hex_size[1] + hex_size[1]) + hex_size[1]) + hex_size[1];
    for (i_0 = 0; i_0 < loop_ub; i_0++) {
      hex_data_0[i_0] = hex_data[hex_size[0] * i_0 + 3];
    }

    for (i_0 = 0; i_0 < m; i_0++) {
      hex_data_0[i_0 + loop_ub] = hex_data[hex_size[0] * i_0 + 2];
    }

    for (i_0 = 0; i_0 < loop_ub_0; i_0++) {
      hex_data_0[(i_0 + loop_ub) + m] = hex_data[hex_size[0] * i_0 + 1];
    }

    for (i_0 = 0; i_0 < loop_ub_1; i_0++) {
      hex_data_0[((i_0 + loop_ub) + m) + loop_ub_0] = hex_data[hex_size[0] * i_0];
    }

    r = rt_roundd_snf(ARDroneHover_V2_hex2dec(hex_data_0, hex_size_2));
    if (r < 4.294967296E+9) {
      if (r >= 0.0) {
        x = (uint32_T)r;
      } else {
        x = 0U;
      }
    } else {
      x = MAX_uint32_T;
    }

    memcpy((void *)&heading_unwrapped, (void *)&x, (uint32_T)((size_t)1 * sizeof
            (real32_T)));

    /* '<S5>:1:59' */
    /* '<S5>:1:60' */
    /* '<S5>:1:61' */
    /* '<S5>:1:63' */
    /* '<S5>:1:77' */
    ARDroneHover_V2_dec2hex(&ARDroneHover_V2_B.frameOut[1820], hex_data,
      hex_size);

    /* '<S5>:1:78' */
    /* '<S5>:1:84' */
    loop_ub = hex_size[1];
    m = hex_size[1];
    loop_ub_0 = hex_size[1];
    loop_ub_1 = hex_size[1];
    hex_size_1[0] = 1;
    hex_size_1[1] = ((hex_size[1] + hex_size[1]) + hex_size[1]) + hex_size[1];
    for (i_0 = 0; i_0 < loop_ub; i_0++) {
      hex_data_0[i_0] = hex_data[hex_size[0] * i_0 + 3];
    }

    for (i_0 = 0; i_0 < m; i_0++) {
      hex_data_0[i_0 + loop_ub] = hex_data[hex_size[0] * i_0 + 2];
    }

    for (i_0 = 0; i_0 < loop_ub_0; i_0++) {
      hex_data_0[(i_0 + loop_ub) + m] = hex_data[hex_size[0] * i_0 + 1];
    }

    for (i_0 = 0; i_0 < loop_ub_1; i_0++) {
      hex_data_0[((i_0 + loop_ub) + m) + loop_ub_0] = hex_data[hex_size[0] * i_0];
    }

    r = rt_roundd_snf(ARDroneHover_V2_hex2dec(hex_data_0, hex_size_1));
    if (r < 4.294967296E+9) {
      if (r >= 0.0) {
        x = (uint32_T)r;
      } else {
        x = 0U;
      }
    } else {
      x = MAX_uint32_T;
    }

    memcpy((void *)&heading_unwrapped, (void *)&x, (uint32_T)((size_t)1 * sizeof
            (real32_T)));

    /* '<S5>:1:64' */
    /* '<S5>:1:77' */
    ARDroneHover_V2_dec2hex(&ARDroneHover_V2_B.frameOut[1824], hex_data,
      hex_size);

    /* '<S5>:1:78' */
    /* '<S5>:1:84' */
    loop_ub = hex_size[1];
    m = hex_size[1];
    loop_ub_0 = hex_size[1];
    loop_ub_1 = hex_size[1];
    hex_size_0[0] = 1;
    hex_size_0[1] = ((hex_size[1] + hex_size[1]) + hex_size[1]) + hex_size[1];
    for (i_0 = 0; i_0 < loop_ub; i_0++) {
      hex_data_0[i_0] = hex_data[hex_size[0] * i_0 + 3];
    }

    for (i_0 = 0; i_0 < m; i_0++) {
      hex_data_0[i_0 + loop_ub] = hex_data[hex_size[0] * i_0 + 2];
    }

    for (i_0 = 0; i_0 < loop_ub_0; i_0++) {
      hex_data_0[(i_0 + loop_ub) + m] = hex_data[hex_size[0] * i_0 + 1];
    }

    for (i_0 = 0; i_0 < loop_ub_1; i_0++) {
      hex_data_0[((i_0 + loop_ub) + m) + loop_ub_0] = hex_data[hex_size[0] * i_0];
    }

    r = rt_roundd_snf(ARDroneHover_V2_hex2dec(hex_data_0, hex_size_0));
    if (r < 4.294967296E+9) {
      if (r >= 0.0) {
        x = (uint32_T)r;
      } else {
        x = 0U;
      }
    } else {
      x = MAX_uint32_T;
    }

    memcpy((void *)&heading_unwrapped, (void *)&x, (uint32_T)((size_t)1 * sizeof
            (real32_T)));

    /* '<S5>:1:67' */
    /* '<S5>:1:77' */
    /* '<S5>:1:78' */
    /* '<S5>:1:80' */
    rtb_psi /= 1000.0F;
    rtb_vx /= 1000.0F;
    rtb_vy /= 1000.0F;
    rtb_vz /= 1000.0F;

    /* DataTypeConversion: '<S1>/Type Conversion1' incorporates:
     *  MATLAB Function: '<S1>/ARDrone data decoding'
     */
    ARDroneHover_V2_B.TypeConversion1 = b_res / 1000.0F;

    /* DataTypeConversion: '<S1>/Type Conversion2' incorporates:
     *  MATLAB Function: '<S1>/ARDrone data decoding'
     */
    ARDroneHover_V2_B.TypeConversion2 = res / 1000.0F;

    /* ManualSwitch: '<Root>/Manual Switch2' incorporates:
     *  Constant: '<Root>/commands disabled'
     *  Constant: '<Root>/commands enabled'
     */
    if (ARDroneHover_V2_P.ManualSwitch2_CurrentSetting == 1) {
      bytesToRead = ARDroneHover_V2_P.commandsdisabled_Value;
    } else {
      bytesToRead = ARDroneHover_V2_P.commandsenabled_Value;
    }

    /* End of ManualSwitch: '<Root>/Manual Switch2' */

    /* MATLAB Function: '<S1>/This block sets the heading angle to zero when the  commands from the Simulink controller are enabled. ' incorporates:
     *  DataTypeConversion: '<S1>/Type Conversion3'
     *  UnitDelay: '<S1>/Unit Delay to avoid algebraic loop'
     */
    /* MATLAB Function 'ARDrone Wi-Fi  Block/This block sets the heading angle to zero when the  commands from the Simulink controller are enabled. ': '<S8>:1' */
    /* '<S8>:1:6' */
    ARDroneHover_V2_B.yawOut = rtb_psi;
    if ((ARDroneHover_V2_DW.UnitDelaytoavoidalgebraicloop_DSTATE == 1.0) &&
        (bytesToRead == 1.0)) {
      /* '<S8>:1:19' */
      /* '<S8>:1:20' */
      ARDroneHover_V2_B.yawOut = rtb_psi - ARDroneHover_V2_DW.yaw0;

      /* '<S8>:1:21' */
      ARDroneHover_V2_DW.mode = 1.0;
    } else {
      if ((ARDroneHover_V2_DW.UnitDelaytoavoidalgebraicloop_DSTATE == 1.0) &&
          (ARDroneHover_V2_DW.mode == 0.0)) {
        /* '<S8>:1:22' */
        /* '<S8>:1:23' */
        ARDroneHover_V2_DW.yaw0 = rtb_psi;
      }
    }

    /* '<S8>:1:27' */
    rtb_Saturation4 = ARDroneHover_V2_B.yawOut;
    if ((!rtIsInf(ARDroneHover_V2_B.yawOut)) && (!rtIsNaN
         (ARDroneHover_V2_B.yawOut))) {
      if (ARDroneHover_V2_B.yawOut == 0.0) {
        ARDroneHover_V2_B.yawOut = 0.0;
      } else {
        ARDroneHover_V2_B.yawOut = fmod(ARDroneHover_V2_B.yawOut, 360.0);
        if (ARDroneHover_V2_B.yawOut == 0.0) {
          ARDroneHover_V2_B.yawOut = 0.0;
        } else {
          if (rtb_Saturation4 < 0.0) {
            ARDroneHover_V2_B.yawOut += 360.0;
          }
        }
      }
    } else {
      ARDroneHover_V2_B.yawOut = (rtNaN);
    }

    if (ARDroneHover_V2_B.yawOut > 180.0) {
      /* '<S8>:1:28' */
      /* '<S8>:1:29' */
      ARDroneHover_V2_B.yawOut += -360.0;
    }

    /* End of MATLAB Function: '<S1>/This block sets the heading angle to zero when the  commands from the Simulink controller are enabled. ' */
    /* DataTypeConversion: '<S1>/Type Conversion4' incorporates:
     *  MATLAB Function: '<S1>/ARDrone data decoding'
     */
    ARDroneHover_V2_B.TypeConversion4 = ARDroneHover_V2_hex2dec(b_hex_data,
      hex_size_k) / 1000.0;

    /* Constant: '<S17>/Constant1' */
    ARDroneHover_V2_B.Constant1[0] = ARDroneHover_V2_P.Constant1_Value[0];
    ARDroneHover_V2_B.Constant1[1] = ARDroneHover_V2_P.Constant1_Value[1];
  }

  /* Integrator: '<S17>/Integrator' */
  if (ARDroneHover_V2_DW.Integrator_IWORK != 0) {
    ARDroneHover_V2_X.Integrator_CSTATE[0] = ARDroneHover_V2_B.Constant1[0];
    ARDroneHover_V2_X.Integrator_CSTATE[1] = ARDroneHover_V2_B.Constant1[1];
  }

  ARDroneHover_V2_B.Integrator[0] = ARDroneHover_V2_X.Integrator_CSTATE[0];
  ARDroneHover_V2_B.Integrator[1] = ARDroneHover_V2_X.Integrator_CSTATE[1];

  /* End of Integrator: '<S17>/Integrator' */
  if (rtmIsMajorTimeStep(ARDroneHover_V2_M)) {
    /* Gain: '<Root>/deg 2 rad' */
    ARDroneHover_V2_B.deg2rad[0] = ARDroneHover_V2_P.deg2rad_Gain *
      ARDroneHover_V2_B.TypeConversion1;
    ARDroneHover_V2_B.deg2rad[1] = ARDroneHover_V2_P.deg2rad_Gain *
      ARDroneHover_V2_B.TypeConversion2;
    ARDroneHover_V2_B.deg2rad[2] = ARDroneHover_V2_P.deg2rad_Gain *
      ARDroneHover_V2_B.yawOut;

    /* DataTypeConversion: '<S1>/Type Conversion5' */
    ARDroneHover_V2_B.TypeConversion5 = rtb_vx;

    /* DataTypeConversion: '<S1>/Type Conversion6' */
    ARDroneHover_V2_B.TypeConversion6 = rtb_vy;

    /* DataTypeConversion: '<S1>/Type Conversion7' */
    ARDroneHover_V2_B.TypeConversion7 = rtb_vz;

    /* SignalConversion: '<S4>/TmpSignal ConversionAtTo WorkspaceInport1' */
    ARDroneHover_V2_B.TmpSignalConversionAtToWorkspaceInport1[0] =
      ARDroneHover_V2_B.deg2rad[0];
    ARDroneHover_V2_B.TmpSignalConversionAtToWorkspaceInport1[1] =
      ARDroneHover_V2_B.deg2rad[1];
    ARDroneHover_V2_B.TmpSignalConversionAtToWorkspaceInport1[2] =
      ARDroneHover_V2_B.deg2rad[2];
    ARDroneHover_V2_B.TmpSignalConversionAtToWorkspaceInport1[3] =
      ARDroneHover_V2_B.TypeConversion5;
    ARDroneHover_V2_B.TmpSignalConversionAtToWorkspaceInport1[4] =
      ARDroneHover_V2_B.TypeConversion6;
    ARDroneHover_V2_B.TmpSignalConversionAtToWorkspaceInport1[5] =
      ARDroneHover_V2_B.TypeConversion7;
    ARDroneHover_V2_B.TmpSignalConversionAtToWorkspaceInport1[6] =
      ARDroneHover_V2_B.Integrator[0];
    ARDroneHover_V2_B.TmpSignalConversionAtToWorkspaceInport1[7] =
      ARDroneHover_V2_B.Integrator[1];
    ARDroneHover_V2_B.TmpSignalConversionAtToWorkspaceInport1[8] =
      ARDroneHover_V2_B.TypeConversion4;

    /* Gain: '<S4>/deg 2 rad1' */
    ARDroneHover_V2_B.deg2rad1 = ARDroneHover_V2_P.deg2rad1_Gain *
      ARDroneHover_V2_B.deg2rad[2];

    /* DataTypeConversion: '<S1>/Type Conversion16' */
    ARDroneHover_V2_B.TypeConversion16 = rtb_altitude_raw;

    /* Constant: '<Root>/Inertial X ref (m)' */
    ARDroneHover_V2_B.InertialXrefm = ARDroneHover_V2_P.InertialXrefm_Value;

    /* Constant: '<Root>/Inertial Y ref (m)' */
    ARDroneHover_V2_B.InertialYrefm = ARDroneHover_V2_P.InertialYrefm_Value;
  }

  /* Sum: '<S15>/Sum4' incorporates:
   *  MATLAB Function: '<S15>/Coordinate trnasformation  from inertial frame to body frame '
   */
  /* MATLAB Function 'Baseline Controller/Position controller/Coordinate trnasformation  from inertial frame to body frame ': '<S16>:1' */
  /* '<S16>:1:3' */
  /* '<S16>:1:4' */
  bytesLeft = ARDroneHover_V2_B.InertialXrefm - ARDroneHover_V2_B.Integrator[0];
  rtb_Saturation4 = ARDroneHover_V2_B.InertialYrefm -
    ARDroneHover_V2_B.Integrator[1];

  /* MATLAB Function: '<S15>/Coordinate trnasformation  from inertial frame to body frame ' incorporates:
   *  MATLAB Function: '<S17>/Velocity from vehicle body frame  to inertial NED  frame'
   */
  rtb_Saturation4_tmp = cos(ARDroneHover_V2_B.deg2rad[2]);
  u0_tmp = sin(ARDroneHover_V2_B.deg2rad[2]);

  /* Gain: '<S14>/Gain1' incorporates:
   *  Gain: '<S15>/Gain3'
   *  MATLAB Function: '<S15>/Coordinate trnasformation  from inertial frame to body frame '
   *  Sum: '<S14>/Sum5'
   */
  rtb_ManualSwitch1 = ((-u0_tmp * bytesLeft + rtb_Saturation4_tmp *
                        rtb_Saturation4) * ARDroneHover_V2_P.Gain3_Gain -
                       ARDroneHover_V2_B.TypeConversion6) *
    ARDroneHover_V2_P.Gain1_Gain;

  /* Saturate: '<S1>/Saturation 1' */
  if (rtb_ManualSwitch1 > ARDroneHover_V2_P.Saturation1_UpperSat) {
    ARDroneHover_V2_B.Saturation1 = ARDroneHover_V2_P.Saturation1_UpperSat;
  } else if (rtb_ManualSwitch1 < ARDroneHover_V2_P.Saturation1_LowerSat) {
    ARDroneHover_V2_B.Saturation1 = ARDroneHover_V2_P.Saturation1_LowerSat;
  } else {
    ARDroneHover_V2_B.Saturation1 = rtb_ManualSwitch1;
  }

  /* End of Saturate: '<S1>/Saturation 1' */

  /* Gain: '<S11>/Gain' incorporates:
   *  Gain: '<S15>/Gain2'
   *  MATLAB Function: '<S15>/Coordinate trnasformation  from inertial frame to body frame '
   *  Sum: '<S11>/Sum2'
   */
  rtb_ManualSwitch1 = ((rtb_Saturation4_tmp * bytesLeft + u0_tmp *
                        rtb_Saturation4) * ARDroneHover_V2_P.Gain2_Gain -
                       ARDroneHover_V2_B.TypeConversion5) *
    ARDroneHover_V2_P.Gain_Gain;

  /* Saturate: '<S1>/Saturation 2' */
  if (rtb_ManualSwitch1 > ARDroneHover_V2_P.Saturation2_UpperSat) {
    ARDroneHover_V2_B.Saturation2 = ARDroneHover_V2_P.Saturation2_UpperSat;
  } else if (rtb_ManualSwitch1 < ARDroneHover_V2_P.Saturation2_LowerSat) {
    ARDroneHover_V2_B.Saturation2 = ARDroneHover_V2_P.Saturation2_LowerSat;
  } else {
    ARDroneHover_V2_B.Saturation2 = rtb_ManualSwitch1;
  }

  /* End of Saturate: '<S1>/Saturation 2' */
  if (rtmIsMajorTimeStep(ARDroneHover_V2_M)) {
    /* Gain: '<S12>/proportional control gain - yaw' incorporates:
     *  Constant: '<Root>/Heading ref (rad)'
     *  Sum: '<S12>/Sum1'
     */
    bytesLeft = (ARDroneHover_V2_P.Headingrefrad_Value -
                 ARDroneHover_V2_B.deg2rad[2]) *
      ARDroneHover_V2_P.proportionalcontrolgainyaw_Gain;

    /* Saturate: '<S1>/Saturation 3' */
    if (bytesLeft > ARDroneHover_V2_P.Saturation3_UpperSat) {
      bytesLeft = ARDroneHover_V2_P.Saturation3_UpperSat;
    } else {
      if (bytesLeft < ARDroneHover_V2_P.Saturation3_LowerSat) {
        bytesLeft = ARDroneHover_V2_P.Saturation3_LowerSat;
      }
    }

    /* End of Saturate: '<S1>/Saturation 3' */

    /* Gain: '<S13>/proportional control gain' incorporates:
     *  Constant: '<Root>/Height ref (m)'
     *  Sum: '<S13>/Sum3'
     */
    rtb_Saturation4 = (ARDroneHover_V2_P.Heightrefm_Value -
                       ARDroneHover_V2_B.TypeConversion4) *
      ARDroneHover_V2_P.proportionalcontrolgain_Gain;

    /* Saturate: '<S1>/Saturation 4' */
    if (rtb_Saturation4 > ARDroneHover_V2_P.Saturation4_UpperSat) {
      rtb_Saturation4 = ARDroneHover_V2_P.Saturation4_UpperSat;
    } else {
      if (rtb_Saturation4 < ARDroneHover_V2_P.Saturation4_LowerSat) {
        rtb_Saturation4 = ARDroneHover_V2_P.Saturation4_LowerSat;
      }
    }

    /* End of Saturate: '<S1>/Saturation 4' */

    /* ManualSwitch: '<Root>/Manual Switch1' incorporates:
     *  Constant: '<Root>/land'
     *  Constant: '<Root>/take off'
     */
    if (ARDroneHover_V2_P.ManualSwitch1_CurrentSetting == 1) {
      rtb_ManualSwitch1 = ARDroneHover_V2_P.land_Value;
    } else {
      rtb_ManualSwitch1 = ARDroneHover_V2_P.takeoff_Value;
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
    memset(&ARDroneHover_V2_B.dataControl[0], 0, 150U * sizeof(uint8_T));

    /* '<S9>:1:26' */
    loop_ub_0 = 0;
    guard1 = false;
    if (ARDroneHover_V2_DW.SequenceNumber <= 1.0) {
      /* '<S9>:1:29' */
      guard1 = true;
    } else {
      if (!rtIsInf(ARDroneHover_V2_DW.SequenceNumber)) {
        r = fmod(ARDroneHover_V2_DW.SequenceNumber, 100.0);
        if (r == 0.0) {
          r = 0.0;
        }
      } else {
        r = (rtNaN);
      }

      if (r == 0.0) {
        /* '<S9>:1:29' */
        guard1 = true;
      }
    }

    if (guard1) {
      /* '<S9>:1:30' */
      ARDroneHover_V2_DW.SequenceNumber++;

      /* '<S9>:1:31' */
      /* '<S9>:1:32' */
      ARDroneHover_V2_getString(ARDroneHover_V2_DW.SequenceNumber, strCmd_data,
        hex_size);
      loop_ub_0 = 42 + hex_size[1];
      for (i_0 = 0; i_0 < 10; i_0++) {
        cmd_data[i_0] = c[i_0];
      }

      loop_ub = hex_size[0] * hex_size[1];
      if (0 <= loop_ub - 1) {
        memcpy(&cmd_data[10], &strCmd_data[0], loop_ub * sizeof(char_T));
      }

      for (i_0 = 0; i_0 < 31; i_0++) {
        cmd_data[(i_0 + loop_ub) + 10] = d[i_0];
      }

      cmd_data[41 + loop_ub] = '\x0d';
    }

    /* '<S9>:1:36' */
    ARDroneHover_V2_DW.SequenceNumber++;

    /* '<S9>:1:37' */
    ARDroneHover_V2_getString(ARDroneHover_V2_DW.SequenceNumber, strCmd_data,
      hex_size);

    /* '<S9>:1:38' */
    aux = loop_ub_0 + 10;

    /* MATLAB Function: '<S7>/Drone state request' */
    m = hex_size[1];
    loop_ub_1 = aux + hex_size[1];
    loop_ub_0 = loop_ub_1 + 1;
    for (i_0 = 0; i_0 < 10; i_0++) {
      /* MATLAB Function: '<S7>/Drone state request' */
      cmd_data[(aux + i_0) - 10] = e[i_0];
    }

    for (i_0 = 0; i_0 < m; i_0++) {
      /* MATLAB Function: '<S7>/Drone state request' */
      cmd_data[aux + i_0] = strCmd_data[i_0];
    }

    /* MATLAB Function: '<S7>/Drone state request' */
    cmd_data[loop_ub_1] = '\x0d';

    /* ManualSwitch: '<Root>/Manual Switch' incorporates:
     *  Constant: '<Root>/_'
     *  Constant: '<Root>/stop'
     */
    if (ARDroneHover_V2_P.ManualSwitch_CurrentSetting == 1) {
      r = ARDroneHover_V2_P._Value;
    } else {
      r = ARDroneHover_V2_P.stop_Value;
    }

    /* End of ManualSwitch: '<Root>/Manual Switch' */

    /* MATLAB Function: '<S7>/Drone state request' */
    if (r == 1.0) {
      /* '<S9>:1:41' */
      /* '<S9>:1:42' */
      loop_ub_0 = hex_size[1] + 18;
      for (i_0 = 0; i_0 < 7; i_0++) {
        cmd_data[i_0] = f[i_0];
      }

      loop_ub = hex_size[0] * hex_size[1];
      if (0 <= loop_ub - 1) {
        memcpy(&cmd_data[7], &strCmd_data[0], loop_ub * sizeof(char_T));
      }

      for (i_0 = 0; i_0 < 10; i_0++) {
        cmd_data[(i_0 + hex_size[0] * hex_size[1]) + 7] = g[i_0];
      }

      cmd_data[17 + hex_size[0] * hex_size[1]] = '\x0d';
    } else if ((ARDroneHover_V2_DW.SequenceNumber > 20.0) &&
               (ARDroneHover_V2_DW.SequenceNumber < 22.0)) {
      /* '<S9>:1:46' */
      /* '<S9>:1:49' */
      ARDroneHover_V2_DW.SequenceNumber = 22.0;

      /* '<S9>:1:50' */
      /* '<S9>:1:51' */
      ARDroneHover_V2_getString(22.0, strCmd_data, hex_size);
      loop_ub_1 = loop_ub_0 + hex_size[1];
      m = loop_ub_1 + 10;
      if (0 <= loop_ub_0 - 1) {
        memcpy(&cmd_data_0[0], &cmd_data[0], loop_ub_0 * sizeof(char_T));
      }

      for (i_0 = 0; i_0 < 9; i_0++) {
        cmd_data_0[i_0 + loop_ub_0] = i[i_0];
      }

      loop_ub = hex_size[1];
      for (i_0 = 0; i_0 < loop_ub; i_0++) {
        cmd_data_0[(i_0 + loop_ub_0) + 9] = strCmd_data[hex_size[0] * i_0];
      }

      cmd_data_0[loop_ub_1 + 9] = '\x0d';
      loop_ub_0 = m;
      if (0 <= m - 1) {
        memcpy(&cmd_data[0], &cmd_data_0[0], m * sizeof(char_T));
      }
    } else if ((ARDroneHover_V2_DW.SequenceNumber >= 22.0) &&
               (ARDroneHover_V2_DW.SequenceNumber < 25.0)) {
      /* '<S9>:1:53' */
      /* '<S9>:1:54' */
      aux = loop_ub_0 + 10;
      m = hex_size[1];
      loop_ub_1 = aux + hex_size[1];
      loop_ub_0 = loop_ub_1 + 31;
      for (i_0 = 0; i_0 < 10; i_0++) {
        cmd_data[(aux + i_0) - 10] = c[i_0];
      }

      for (i_0 = 0; i_0 < m; i_0++) {
        cmd_data[aux + i_0] = strCmd_data[i_0];
      }

      for (i_0 = 0; i_0 < 30; i_0++) {
        cmd_data[(aux + i_0) + m] = h[i_0];
      }

      cmd_data[loop_ub_1 + 30] = '\x0d';
    } else {
      if (ARDroneHover_V2_DW.SequenceNumber >= 25.0) {
        /* '<S9>:1:57' */
        if (rtb_ManualSwitch1 == 1.0) {
          /* '<S9>:1:59' */
          if (rtb_ardrone_state[31] == 0) {
            /* '<S9>:1:61' */
            /* '<S9>:1:63' */
            ARDroneHover_V2_DW.SequenceNumber++;

            /* '<S9>:1:64' */
            /* '<S9>:1:65' */
            ARDroneHover_V2_getString(ARDroneHover_V2_DW.SequenceNumber,
              strCmd_data, hex_size);
            loop_ub_1 = loop_ub_0 + hex_size[1];
            m = loop_ub_1 + 18;
            if (0 <= loop_ub_0 - 1) {
              memcpy(&cmd_data_0[0], &cmd_data[0], loop_ub_0 * sizeof(char_T));
            }

            for (i_0 = 0; i_0 < 7; i_0++) {
              cmd_data_0[i_0 + loop_ub_0] = f[i_0];
            }

            loop_ub = hex_size[1];
            for (i_0 = 0; i_0 < loop_ub; i_0++) {
              cmd_data_0[(i_0 + loop_ub_0) + 7] = strCmd_data[hex_size[0] * i_0];
            }

            for (i_0 = 0; i_0 < 10; i_0++) {
              cmd_data_0[((i_0 + loop_ub_0) + hex_size[1]) + 7] = j[i_0];
            }

            cmd_data_0[loop_ub_1 + 17] = '\x0d';
            loop_ub_0 = m;
            if (0 <= m - 1) {
              memcpy(&cmd_data[0], &cmd_data_0[0], m * sizeof(char_T));
            }
          } else {
            if ((rtb_ardrone_state[31] == 1) && (bytesToRead == 1.0)) {
              /* '<S9>:1:67' */
              /* '<S9>:1:69' */
              ARDroneHover_V2_DW.SequenceNumber++;

              /* '<S9>:1:70' */
              /* '<S9>:1:72' */
              ARDroneHover_V2_getString(ARDroneHover_V2_DW.SequenceNumber,
                strCmd_data, hex_size);
              loop_ub_1 = loop_ub_0 + hex_size[1];
              m = loop_ub_1 + 11;
              if (0 <= loop_ub_0 - 1) {
                memcpy(&cmd_data_0[0], &cmd_data[0], loop_ub_0 * sizeof(char_T));
              }

              for (i_0 = 0; i_0 < 8; i_0++) {
                cmd_data_0[i_0 + loop_ub_0] = l[i_0];
              }

              loop_ub = hex_size[1];
              for (i_0 = 0; i_0 < loop_ub; i_0++) {
                cmd_data_0[(i_0 + loop_ub_0) + 8] = strCmd_data[hex_size[0] *
                  i_0];
              }

              cmd_data_0[loop_ub_1 + 8] = ',';
              cmd_data_0[loop_ub_1 + 9] = '1';
              cmd_data_0[loop_ub_1 + 10] = ',';
              if (0 <= m - 1) {
                memcpy(&cmd_data[0], &cmd_data_0[0], m * sizeof(char_T));
              }

              /* '<S9>:1:74' */
              aux = ARDroneHover_V2_float2IEEE754(ARDroneHover_V2_B.Saturation1);

              /* '<S9>:1:75' */
              ARDroneHover_V2_getString(fabs((real_T)aux), strCmd_data, hex_size);
              strAux_size_idx_1 = hex_size[1];
              loop_ub = hex_size[0] * hex_size[1];
              if (0 <= loop_ub - 1) {
                memcpy(&strAux_data[0], &strCmd_data[0], loop_ub * sizeof(char_T));
              }

              if (ARDroneHover_V2_B.Saturation1 < 0.0) {
                /* '<S9>:1:76' */
                /* '<S9>:1:77' */
                strAux_size_idx_1 = 1 + hex_size[1];
                strAux_data[0] = '-';
                if (0 <= loop_ub - 1) {
                  memcpy(&strAux_data[1], &strCmd_data[0], loop_ub * sizeof
                         (char_T));
                }
              }

              /* '<S9>:1:79' */
              loop_ub_1 = m + strAux_size_idx_1;
              loop_ub_0 = loop_ub_1 + 1;
              for (i_0 = 0; i_0 < strAux_size_idx_1; i_0++) {
                cmd_data[m + i_0] = strAux_data[i_0];
              }

              cmd_data[loop_ub_1] = ',';

              /* '<S9>:1:81' */
              aux = ARDroneHover_V2_float2IEEE754(ARDroneHover_V2_B.Saturation2);

              /* '<S9>:1:82' */
              ARDroneHover_V2_getString(fabs((real_T)aux), strCmd_data, hex_size);
              strAux_size_idx_1 = hex_size[1];
              loop_ub = hex_size[0] * hex_size[1];
              if (0 <= loop_ub - 1) {
                memcpy(&strAux_data[0], &strCmd_data[0], loop_ub * sizeof(char_T));
              }

              if (ARDroneHover_V2_B.Saturation2 < 0.0) {
                /* '<S9>:1:83' */
                /* '<S9>:1:84' */
                strAux_size_idx_1 = 1 + hex_size[1];
                strAux_data[0] = '-';
                loop_ub = hex_size[0] * hex_size[1];
                if (0 <= loop_ub - 1) {
                  memcpy(&strAux_data[1], &strCmd_data[0], loop_ub * sizeof
                         (char_T));
                }
              }

              /* '<S9>:1:86' */
              aux = loop_ub_0;
              loop_ub_0 = (loop_ub_0 + strAux_size_idx_1) + 1;
              for (i_0 = 0; i_0 < strAux_size_idx_1; i_0++) {
                cmd_data[aux + i_0] = strAux_data[i_0];
              }

              cmd_data[aux + strAux_size_idx_1] = ',';

              /* '<S9>:1:88' */
              /* '<S9>:1:89' */
              ARDroneHover_V2_getString(fabs((real_T)
                ARDroneHover_V2_float2IEEE754(rtb_Saturation4)), strCmd_data,
                hex_size);
              strAux_size_idx_1 = hex_size[1];
              loop_ub = hex_size[0] * hex_size[1];
              if (0 <= loop_ub - 1) {
                memcpy(&strAux_data[0], &strCmd_data[0], loop_ub * sizeof(char_T));
              }

              if (rtb_Saturation4 < 0.0) {
                /* '<S9>:1:90' */
                /* '<S9>:1:91' */
                strAux_size_idx_1 = 1 + hex_size[1];
                strAux_data[0] = '-';
                loop_ub = hex_size[0] * hex_size[1];
                if (0 <= loop_ub - 1) {
                  memcpy(&strAux_data[1], &strCmd_data[0], loop_ub * sizeof
                         (char_T));
                }
              }

              /* '<S9>:1:93' */
              aux = loop_ub_0;
              loop_ub_0 = (loop_ub_0 + strAux_size_idx_1) + 1;
              for (i_0 = 0; i_0 < strAux_size_idx_1; i_0++) {
                cmd_data[aux + i_0] = strAux_data[i_0];
              }

              cmd_data[aux + strAux_size_idx_1] = ',';

              /* '<S9>:1:96' */
              /* '<S9>:1:97' */
              ARDroneHover_V2_getString(fabs((real_T)
                ARDroneHover_V2_float2IEEE754(bytesLeft)), strCmd_data, hex_size);
              strAux_size_idx_1 = hex_size[1];
              loop_ub = hex_size[0] * hex_size[1];
              if (0 <= loop_ub - 1) {
                memcpy(&strAux_data[0], &strCmd_data[0], loop_ub * sizeof(char_T));
              }

              if (bytesLeft < 0.0) {
                /* '<S9>:1:98' */
                /* '<S9>:1:99' */
                /* '<S9>:1:100' */
                strAux_size_idx_1 = 1 + hex_size[1];
                strAux_data[0] = '-';
                loop_ub = hex_size[0] * hex_size[1];
                if (0 <= loop_ub - 1) {
                  memcpy(&strAux_data[1], &strCmd_data[0], loop_ub * sizeof
                         (char_T));
                }
              }

              /* '<S9>:1:102' */
              aux = loop_ub_0;
              loop_ub_0 = (loop_ub_0 + strAux_size_idx_1) + 1;
              for (i_0 = 0; i_0 < strAux_size_idx_1; i_0++) {
                cmd_data[aux + i_0] = strAux_data[i_0];
              }

              cmd_data[aux + strAux_size_idx_1] = '\x0d';
            }
          }
        } else {
          if ((rtb_ManualSwitch1 == 0.0) && (rtb_ardrone_state[31] == 1)) {
            /* '<S9>:1:108' */
            /* '<S9>:1:110' */
            /* '<S9>:1:111' */
            ARDroneHover_V2_DW.SequenceNumber++;

            /* '<S9>:1:112' */
            /* '<S9>:1:113' */
            ARDroneHover_V2_getString(ARDroneHover_V2_DW.SequenceNumber,
              strCmd_data, hex_size);
            loop_ub_1 = loop_ub_0 + hex_size[1];
            m = loop_ub_1 + 18;
            if (0 <= loop_ub_0 - 1) {
              memcpy(&cmd_data_0[0], &cmd_data[0], loop_ub_0 * sizeof(char_T));
            }

            for (i_0 = 0; i_0 < 7; i_0++) {
              cmd_data_0[i_0 + loop_ub_0] = f[i_0];
            }

            loop_ub = hex_size[1];
            for (i_0 = 0; i_0 < loop_ub; i_0++) {
              cmd_data_0[(i_0 + loop_ub_0) + 7] = strCmd_data[hex_size[0] * i_0];
            }

            for (i_0 = 0; i_0 < 10; i_0++) {
              cmd_data_0[((i_0 + loop_ub_0) + hex_size[1]) + 7] = k[i_0];
            }

            cmd_data_0[loop_ub_1 + 17] = '\x0d';
            loop_ub_0 = m;
            if (0 <= m - 1) {
              memcpy(&cmd_data[0], &cmd_data_0[0], m * sizeof(char_T));
            }
          }
        }
      }
    }

    /* '<S9>:1:128' */
    for (i_0 = 0; i_0 < loop_ub_0; i_0++) {
      ARDroneHover_V2_B.dataControl[i_0] = (uint8_T)cmd_data[i_0];
    }

    /* '<S9>:1:133' */
    ARDroneHover_V2_B.isFlying = rtb_ardrone_state[31];

    /* S-Function (sldrtpo): '<S7>/Packet Output' */
    /* S-Function Block: <S7>/Packet Output */

    /* no code required */

    /* RateTransition: '<S10>/Rate Transition' incorporates:
     *  Constant: '<S10>/Constant'
     */
    if (ARDroneHover_V2_M->Timing.RateInteraction.TID1_2) {
      ARDroneHover_V2_B.RateTransition[0] = ARDroneHover_V2_P.Constant_Value[0];
      ARDroneHover_V2_B.RateTransition[1] = ARDroneHover_V2_P.Constant_Value[1];
    }

    /* End of RateTransition: '<S10>/Rate Transition' */

    /* MATLAB Function: '<S17>/Velocity from vehicle body frame  to inertial NED  frame' incorporates:
     *  SignalConversion: '<S18>/TmpSignal ConversionAt SFunction Inport1'
     */
    /* MATLAB Function 'Position estimation Important:This block provides an  inaccurate extimation of position  based on  velocity information. /Position estimation/Velocity from vehicle body frame  to inertial NED  frame': '<S18>:1' */
    /* '<S18>:1:3' */
    /* '<S18>:1:4' */
    ARDroneHover_V2_B.Vel_xy[0] = 0.0;
    ARDroneHover_V2_B.Vel_xy[0] += rtb_Saturation4_tmp *
      ARDroneHover_V2_B.TypeConversion5;
    ARDroneHover_V2_B.Vel_xy[0] += -sin(ARDroneHover_V2_B.deg2rad[2]) *
      ARDroneHover_V2_B.TypeConversion6;
    ARDroneHover_V2_B.Vel_xy[1] = 0.0;
    ARDroneHover_V2_B.Vel_xy[1] += u0_tmp * ARDroneHover_V2_B.TypeConversion5;
    ARDroneHover_V2_B.Vel_xy[1] += rtb_Saturation4_tmp *
      ARDroneHover_V2_B.TypeConversion6;
  }

  /* Clock: '<S1>/Clock' */
  ARDroneHover_V2_B.Clock = ARDroneHover_V2_M->Timing.t[0];

  /* Clock: '<Root>/Clock1' */
  ARDroneHover_V2_B.Clock1 = ARDroneHover_V2_M->Timing.t[0];
  if (rtmIsMajorTimeStep(ARDroneHover_V2_M)) {
  }
}

/* Model update function for TID0 */
void ARDroneHover_V2_update0(void)     /* Sample time: [0.0s, 0.0s] */
{
  /* Update for Integrator: '<S17>/Integrator' */
  ARDroneHover_V2_DW.Integrator_IWORK = 0;
  if (rtmIsMajorTimeStep(ARDroneHover_V2_M)) {
    /* Update for UnitDelay: '<S1>/Unit Delay to avoid algebraic loop' */
    ARDroneHover_V2_DW.UnitDelaytoavoidalgebraicloop_DSTATE =
      ARDroneHover_V2_B.isFlying;

    /* Update for S-Function (sldrtpo): '<S7>/Packet Output' */

    /* S-Function Block: <S7>/Packet Output */
    {
      uint8_T outdata[150U];
      RTWin_ANYTYPEPTR outdp;
      outdp.p_uint8_T = outdata;

      {
        int_T i1;
        const uint8_T *u0 = &ARDroneHover_V2_B.dataControl[0];
        for (i1=0; i1 < 150; i1++) {
          {
            uint8_T pktout = u0[i1];
            *outdp.p_uint8_T++ = pktout;
          }
        }
      }

      RTBIO_DriverIO(1, STREAMOUTPUT, IOWRITE, 150U,
                     &ARDroneHover_V2_P.PacketOutput_PacketID, (double*) outdata,
                     NULL);
    }
  }

  if (rtmIsMajorTimeStep(ARDroneHover_V2_M)) {
    rt_ertODEUpdateContinuousStates(&ARDroneHover_V2_M->solverInfo);
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
  if (!(++ARDroneHover_V2_M->Timing.clockTick0)) {
    ++ARDroneHover_V2_M->Timing.clockTickH0;
  }

  ARDroneHover_V2_M->Timing.t[0] = rtsiGetSolverStopTime
    (&ARDroneHover_V2_M->solverInfo);

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++ARDroneHover_V2_M->Timing.clockTick1)) {
    ++ARDroneHover_V2_M->Timing.clockTickH1;
  }

  ARDroneHover_V2_M->Timing.t[1] = ARDroneHover_V2_M->Timing.clockTick1 *
    ARDroneHover_V2_M->Timing.stepSize1 + ARDroneHover_V2_M->Timing.clockTickH1 *
    ARDroneHover_V2_M->Timing.stepSize1 * 4294967296.0;
}

/* Derivatives for root system: '<Root>' */
void ARDroneHover_V2_derivatives(void)
{
  XDot_ARDroneHover_V2_T *_rtXdot;
  _rtXdot = ((XDot_ARDroneHover_V2_T *) ARDroneHover_V2_M->derivs);

  /* Derivatives for Integrator: '<S17>/Integrator' */
  _rtXdot->Integrator_CSTATE[0] = ARDroneHover_V2_B.Vel_xy[0];
  _rtXdot->Integrator_CSTATE[1] = ARDroneHover_V2_B.Vel_xy[1];
}

/* Model output function for TID2 */
void ARDroneHover_V2_output2(void)     /* Sample time: [0.05s, 0.0s] */
{
  /* S-Function (sldrtpo): '<S10>/Packet Output1' */
  /* S-Function Block: <S10>/Packet Output1 */

  /* no code required */
}

/* Model update function for TID2 */
void ARDroneHover_V2_update2(void)     /* Sample time: [0.05s, 0.0s] */
{
  /* Update for S-Function (sldrtpo): '<S10>/Packet Output1' */

  /* S-Function Block: <S10>/Packet Output1 */
  {
    uint8_T outdata[2U];
    RTWin_ANYTYPEPTR outdp;
    outdp.p_uint8_T = outdata;

    {
      uint8_T pktout = ARDroneHover_V2_B.RateTransition[0];
      *outdp.p_uint8_T++ = pktout;
    }

    {
      uint8_T pktout = ARDroneHover_V2_B.RateTransition[1];
      *outdp.p_uint8_T++ = pktout;
    }

    RTBIO_DriverIO(0, STREAMOUTPUT, IOWRITE, 2U,
                   &ARDroneHover_V2_P.PacketOutput1_PacketID, (double*) outdata,
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
  if (!(++ARDroneHover_V2_M->Timing.clockTick2)) {
    ++ARDroneHover_V2_M->Timing.clockTickH2;
  }

  ARDroneHover_V2_M->Timing.t[2] = ARDroneHover_V2_M->Timing.clockTick2 *
    ARDroneHover_V2_M->Timing.stepSize2 + ARDroneHover_V2_M->Timing.clockTickH2 *
    ARDroneHover_V2_M->Timing.stepSize2 * 4294967296.0;
}

/* Model output wrapper function for compatibility with a static main program */
void ARDroneHover_V2_output(int_T tid)
{
  switch (tid) {
   case 0 :
    ARDroneHover_V2_output0();
    break;

   case 2 :
    ARDroneHover_V2_output2();
    break;

   default :
    break;
  }
}

/* Model update wrapper function for compatibility with a static main program */
void ARDroneHover_V2_update(int_T tid)
{
  switch (tid) {
   case 0 :
    ARDroneHover_V2_update0();
    break;

   case 2 :
    ARDroneHover_V2_update2();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void ARDroneHover_V2_initialize(void)
{
  /* Start for Constant: '<S17>/Constant1' */
  ARDroneHover_V2_B.Constant1[0] = ARDroneHover_V2_P.Constant1_Value[0];
  ARDroneHover_V2_B.Constant1[1] = ARDroneHover_V2_P.Constant1_Value[1];

  /* Start for S-Function (sldrtpo): '<S7>/Packet Output' */

  /* S-Function Block: <S7>/Packet Output */
  /* no initial value should be set */

  /* Start for S-Function (sldrtpo): '<S10>/Packet Output1' */

  /* S-Function Block: <S10>/Packet Output1 */
  /* no initial value should be set */

  /* InitializeConditions for UnitDelay: '<S1>/Unit Delay to avoid algebraic loop' */
  ARDroneHover_V2_DW.UnitDelaytoavoidalgebraicloop_DSTATE =
    ARDroneHover_V2_P.UnitDelaytoavoidalgebraicloop_InitialCondition;

  /* InitializeConditions for Integrator: '<S17>/Integrator' */
  if (rtmIsFirstInitCond(ARDroneHover_V2_M)) {
    ARDroneHover_V2_X.Integrator_CSTATE[0] = 0.0;
    ARDroneHover_V2_X.Integrator_CSTATE[1] = 0.0;
  }

  ARDroneHover_V2_DW.Integrator_IWORK = 1;

  /* End of InitializeConditions for Integrator: '<S17>/Integrator' */

  /* SystemInitialize for MATLAB Function: '<S1>/Data synchronization ' */
  memset(&ARDroneHover_V2_DW.buffer[0], 0, 10000U * sizeof(uint8_T));
  ARDroneHover_V2_DW.countBuffer = 0.0;
  memset(&ARDroneHover_V2_DW.frame[0], 0, 2186U * sizeof(uint8_T));
  memset(&ARDroneHover_V2_DW.lastFrame[0], 0, 2186U * sizeof(uint8_T));
  ARDroneHover_V2_DW.count = 0.0;
  ARDroneHover_V2_DW.countHeader = 0.0;

  /* SystemInitialize for MATLAB Function: '<S1>/This block sets the heading angle to zero when the  commands from the Simulink controller are enabled. ' */
  ARDroneHover_V2_DW.yaw0 = 0.0;
  ARDroneHover_V2_DW.mode = 0.0;

  /* SystemInitialize for MATLAB Function: '<S7>/Drone state request' */
  ARDroneHover_V2_DW.SequenceNumber = 1.0;

  /* set "at time zero" to false */
  if (rtmIsFirstInitCond(ARDroneHover_V2_M)) {
    rtmSetFirstInitCond(ARDroneHover_V2_M, 0);
  }
}

/* Model terminate function */
void ARDroneHover_V2_terminate(void)
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
  ARDroneHover_V2_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  ARDroneHover_V2_update(tid);
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
  ARDroneHover_V2_initialize();
}

void MdlTerminate(void)
{
  ARDroneHover_V2_terminate();
}

/* Registration function */
RT_MODEL_ARDroneHover_V2_T *ARDroneHover_V2(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)ARDroneHover_V2_M, 0,
                sizeof(RT_MODEL_ARDroneHover_V2_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&ARDroneHover_V2_M->solverInfo,
                          &ARDroneHover_V2_M->Timing.simTimeStep);
    rtsiSetTPtr(&ARDroneHover_V2_M->solverInfo, &rtmGetTPtr(ARDroneHover_V2_M));
    rtsiSetStepSizePtr(&ARDroneHover_V2_M->solverInfo,
                       &ARDroneHover_V2_M->Timing.stepSize0);
    rtsiSetdXPtr(&ARDroneHover_V2_M->solverInfo, &ARDroneHover_V2_M->derivs);
    rtsiSetContStatesPtr(&ARDroneHover_V2_M->solverInfo, (real_T **)
                         &ARDroneHover_V2_M->contStates);
    rtsiSetNumContStatesPtr(&ARDroneHover_V2_M->solverInfo,
      &ARDroneHover_V2_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&ARDroneHover_V2_M->solverInfo,
      &ARDroneHover_V2_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&ARDroneHover_V2_M->solverInfo,
      &ARDroneHover_V2_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&ARDroneHover_V2_M->solverInfo,
      &ARDroneHover_V2_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&ARDroneHover_V2_M->solverInfo, (&rtmGetErrorStatus
      (ARDroneHover_V2_M)));
    rtsiSetRTModelPtr(&ARDroneHover_V2_M->solverInfo, ARDroneHover_V2_M);
  }

  rtsiSetSimTimeStep(&ARDroneHover_V2_M->solverInfo, MAJOR_TIME_STEP);
  ARDroneHover_V2_M->intgData.f[0] = ARDroneHover_V2_M->odeF[0];
  ARDroneHover_V2_M->contStates = ((real_T *) &ARDroneHover_V2_X);
  rtsiSetSolverData(&ARDroneHover_V2_M->solverInfo, (void *)
                    &ARDroneHover_V2_M->intgData);
  rtsiSetSolverName(&ARDroneHover_V2_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = ARDroneHover_V2_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    ARDroneHover_V2_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    ARDroneHover_V2_M->Timing.sampleTimes =
      (&ARDroneHover_V2_M->Timing.sampleTimesArray[0]);
    ARDroneHover_V2_M->Timing.offsetTimes =
      (&ARDroneHover_V2_M->Timing.offsetTimesArray[0]);

    /* task periods */
    ARDroneHover_V2_M->Timing.sampleTimes[0] = (0.0);
    ARDroneHover_V2_M->Timing.sampleTimes[1] = (0.005);
    ARDroneHover_V2_M->Timing.sampleTimes[2] = (0.05);

    /* task offsets */
    ARDroneHover_V2_M->Timing.offsetTimes[0] = (0.0);
    ARDroneHover_V2_M->Timing.offsetTimes[1] = (0.0);
    ARDroneHover_V2_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(ARDroneHover_V2_M, &ARDroneHover_V2_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = ARDroneHover_V2_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits =
      ARDroneHover_V2_M->Timing.perTaskSampleHitsArray;
    ARDroneHover_V2_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    ARDroneHover_V2_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(ARDroneHover_V2_M, 30.0);
  ARDroneHover_V2_M->Timing.stepSize0 = 0.005;
  ARDroneHover_V2_M->Timing.stepSize1 = 0.005;
  ARDroneHover_V2_M->Timing.stepSize2 = 0.05;
  rtmSetFirstInitCond(ARDroneHover_V2_M, 1);

  /* External mode info */
  ARDroneHover_V2_M->Sizes.checksums[0] = (2262729904U);
  ARDroneHover_V2_M->Sizes.checksums[1] = (3757365895U);
  ARDroneHover_V2_M->Sizes.checksums[2] = (1102622097U);
  ARDroneHover_V2_M->Sizes.checksums[3] = (3484763028U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[13];
    ARDroneHover_V2_M->extModeInfo = (&rt_ExtModeInfo);
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
    rteiSetModelMappingInfoPtr(ARDroneHover_V2_M->extModeInfo,
      &ARDroneHover_V2_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(ARDroneHover_V2_M->extModeInfo,
                        ARDroneHover_V2_M->Sizes.checksums);
    rteiSetTPtr(ARDroneHover_V2_M->extModeInfo, rtmGetTPtr(ARDroneHover_V2_M));
  }

  ARDroneHover_V2_M->solverInfoPtr = (&ARDroneHover_V2_M->solverInfo);
  ARDroneHover_V2_M->Timing.stepSize = (0.005);
  rtsiSetFixedStepSize(&ARDroneHover_V2_M->solverInfo, 0.005);
  rtsiSetSolverMode(&ARDroneHover_V2_M->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  ARDroneHover_V2_M->blockIO = ((void *) &ARDroneHover_V2_B);
  (void) memset(((void *) &ARDroneHover_V2_B), 0,
                sizeof(B_ARDroneHover_V2_T));

  {
    int32_T i;
    for (i = 0; i < 9; i++) {
      ARDroneHover_V2_B.TmpSignalConversionAtToWorkspaceInport1[i] = 0.0;
    }

    ARDroneHover_V2_B.TypeConversion = 0.0;
    ARDroneHover_V2_B.TypeConversion1 = 0.0;
    ARDroneHover_V2_B.TypeConversion2 = 0.0;
    ARDroneHover_V2_B.TypeConversion4 = 0.0;
    ARDroneHover_V2_B.Constant1[0] = 0.0;
    ARDroneHover_V2_B.Constant1[1] = 0.0;
    ARDroneHover_V2_B.Integrator[0] = 0.0;
    ARDroneHover_V2_B.Integrator[1] = 0.0;
    ARDroneHover_V2_B.deg2rad[0] = 0.0;
    ARDroneHover_V2_B.deg2rad[1] = 0.0;
    ARDroneHover_V2_B.deg2rad[2] = 0.0;
    ARDroneHover_V2_B.TypeConversion5 = 0.0;
    ARDroneHover_V2_B.TypeConversion6 = 0.0;
    ARDroneHover_V2_B.TypeConversion7 = 0.0;
    ARDroneHover_V2_B.deg2rad1 = 0.0;
    ARDroneHover_V2_B.TypeConversion16 = 0.0;
    ARDroneHover_V2_B.InertialXrefm = 0.0;
    ARDroneHover_V2_B.InertialYrefm = 0.0;
    ARDroneHover_V2_B.Saturation1 = 0.0;
    ARDroneHover_V2_B.Saturation2 = 0.0;
    ARDroneHover_V2_B.Clock = 0.0;
    ARDroneHover_V2_B.Clock1 = 0.0;
    ARDroneHover_V2_B.Vel_xy[0] = 0.0;
    ARDroneHover_V2_B.Vel_xy[1] = 0.0;
    ARDroneHover_V2_B.yawOut = 0.0;
    ARDroneHover_V2_B.isFlying = 0.0;
  }

  /* parameters */
  ARDroneHover_V2_M->defaultParam = ((real_T *)&ARDroneHover_V2_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &ARDroneHover_V2_X;
    ARDroneHover_V2_M->contStates = (x);
    (void) memset((void *)&ARDroneHover_V2_X, 0,
                  sizeof(X_ARDroneHover_V2_T));
  }

  /* states (dwork) */
  ARDroneHover_V2_M->dwork = ((void *) &ARDroneHover_V2_DW);
  (void) memset((void *)&ARDroneHover_V2_DW, 0,
                sizeof(DW_ARDroneHover_V2_T));
  ARDroneHover_V2_DW.UnitDelaytoavoidalgebraicloop_DSTATE = 0.0;
  ARDroneHover_V2_DW.yaw0 = 0.0;
  ARDroneHover_V2_DW.mode = 0.0;
  ARDroneHover_V2_DW.SequenceNumber = 0.0;
  ARDroneHover_V2_DW.count = 0.0;
  ARDroneHover_V2_DW.countHeader = 0.0;
  ARDroneHover_V2_DW.countBuffer = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    ARDroneHover_V2_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  ARDroneHover_V2_M->Sizes.numContStates = (2);/* Number of continuous states */
  ARDroneHover_V2_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  ARDroneHover_V2_M->Sizes.numY = (0); /* Number of model outputs */
  ARDroneHover_V2_M->Sizes.numU = (0); /* Number of model inputs */
  ARDroneHover_V2_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  ARDroneHover_V2_M->Sizes.numSampTimes = (3);/* Number of sample times */
  ARDroneHover_V2_M->Sizes.numBlocks = (80);/* Number of blocks */
  ARDroneHover_V2_M->Sizes.numBlockIO = (27);/* Number of block outputs */
  ARDroneHover_V2_M->Sizes.numBlockPrms = (43);/* Sum of parameter "widths" */
  return ARDroneHover_V2_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
