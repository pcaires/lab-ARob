#include "__cf_ARDroneHoverSim.h"
#ifndef RTW_HEADER_ARDroneHoverSim_acc_h_
#define RTW_HEADER_ARDroneHoverSim_acc_h_
#include <stddef.h>
#include <float.h>
#ifndef ARDroneHoverSim_acc_COMMON_INCLUDES_
#define ARDroneHoverSim_acc_COMMON_INCLUDES_
#include <stdlib.h>
#define S_FUNCTION_NAME simulink_only_sfcn 
#define S_FUNCTION_LEVEL 2
#define RTW_GENERATED_S_FUNCTION
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#endif
#include "ARDroneHoverSim_acc_types.h"
#include "multiword_types.h"
#include "mwmathutil.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
typedef struct { real_T B_3_0_0 ; real_T B_3_2_0 ; real_T B_3_3_0 ; real_T
B_3_4_0 ; real_T B_3_5_0 ; real_T B_3_6_0 ; real_T B_3_8_0 ; real_T B_3_10_0
; real_T B_3_12_0 [ 2 ] ; real_T B_3_13_0 [ 2 ] ; real_T B_3_16_0 [ 3 ] ;
real_T B_3_17_0 ; real_T B_3_19_0 ; real_T B_3_20_0 ; real_T B_3_21_0 ;
real_T B_3_22_0 ; real_T B_3_23_0 ; real_T B_3_24_0 ; real_T B_3_25_0 ;
real_T B_3_26_0 ; real_T B_3_27_0 ; real_T B_3_28_0 ; real_T B_3_29_0 ;
real_T B_3_30_0 [ 4 ] ; real_T B_3_31_0 ; real_T B_3_32_0 ; real_T B_3_33_0 ;
real_T B_3_36_0 [ 2 ] ; real_T B_3_37_0 ; real_T B_3_41_0 ; real_T B_3_44_0 ;
real_T B_3_45_0 ; real_T B_3_48_0 ; real_T B_3_49_0 ; real_T B_3_52_0 ;
real_T B_2_0_1 [ 2 ] ; real_T B_1_0_1 [ 2 ] ; real_T B_0_0_1 ; }
B_ARDroneHoverSim_T ; typedef struct { real_T RTrans4_Buffer0 ; real_T
RTrans3_Buffer0 ; real_T RTrans2_Buffer0 ; real_T RTrans1_Buffer0 ; struct {
real_T modelTStart ; } totalcommunicationtimedelay_RWORK ; void *
Euleranglesdeg_PWORK ; void * Heightm_PWORK ; void *
InertialpotitionalongXem_PWORK ; void * InertialpotitionalongYem_PWORK ; void
* headingdeg_PWORK ; struct { void * TUbufferPtrs [ 8 ] ; }
totalcommunicationtimedelay_PWORK ; int32_T
VelocityfromvehiclebodyframetoinertialNEDframe_sysIdxToRun ; int32_T
Coordinatetrnasformationfrominertialframetobodyframe_sysIdxToRun ; int32_T
normalizeanglebetweenpiandpiradians_sysIdxToRun ; int_T Integrator_IWORK ;
struct { int_T Tail [ 4 ] ; int_T Head [ 4 ] ; int_T Last [ 4 ] ; int_T
CircularBufSize [ 4 ] ; int_T MaxNewBufSize ; }
totalcommunicationtimedelay_IWORK ; char_T
pad_totalcommunicationtimedelay_IWORK [ 4 ] ; } DW_ARDroneHoverSim_T ;
typedef struct { real_T StateSpace_CSTATE [ 2 ] ; real_T StateSpace1_CSTATE [
2 ] ; real_T StateSpace4_CSTATE ; real_T StateSpace5_CSTATE [ 2 ] ; real_T
Integrator_CSTATE [ 2 ] ; real_T StateSpace2_CSTATE ; real_T
StateSpace3_CSTATE ; } X_ARDroneHoverSim_T ; typedef struct { real_T
StateSpace_CSTATE [ 2 ] ; real_T StateSpace1_CSTATE [ 2 ] ; real_T
StateSpace4_CSTATE ; real_T StateSpace5_CSTATE [ 2 ] ; real_T
Integrator_CSTATE [ 2 ] ; real_T StateSpace2_CSTATE ; real_T
StateSpace3_CSTATE ; } XDot_ARDroneHoverSim_T ; typedef struct { boolean_T
StateSpace_CSTATE [ 2 ] ; boolean_T StateSpace1_CSTATE [ 2 ] ; boolean_T
StateSpace4_CSTATE ; boolean_T StateSpace5_CSTATE [ 2 ] ; boolean_T
Integrator_CSTATE [ 2 ] ; boolean_T StateSpace2_CSTATE ; boolean_T
StateSpace3_CSTATE ; } XDis_ARDroneHoverSim_T ; struct P_ARDroneHoverSim_T_ {
real_T P_0 ; real_T P_1 [ 3 ] ; real_T P_2 ; real_T P_3 [ 2 ] ; real_T P_4 ;
real_T P_5 ; real_T P_6 [ 3 ] ; real_T P_7 ; real_T P_8 [ 2 ] ; real_T P_9 ;
real_T P_10 ; real_T P_11 ; real_T P_12 ; real_T P_13 ; real_T P_14 ; real_T
P_15 ; real_T P_16 [ 3 ] ; real_T P_17 ; real_T P_18 [ 2 ] ; real_T P_19 ;
real_T P_20 [ 2 ] ; real_T P_21 ; real_T P_22 ; real_T P_23 ; real_T P_24 ;
real_T P_25 ; real_T P_26 ; real_T P_27 ; real_T P_28 ; real_T P_29 ; real_T
P_30 ; real_T P_31 ; real_T P_32 ; real_T P_33 ; real_T P_34 ; real_T P_35 ;
real_T P_36 ; real_T P_37 ; real_T P_38 ; real_T P_39 ; real_T P_40 ; real_T
P_41 ; real_T P_42 ; real_T P_43 ; real_T P_44 ; real_T P_45 [ 4 ] ; real_T
P_46 ; real_T P_47 ; real_T P_48 ; real_T P_49 ; real_T P_50 ; real_T P_51 ;
real_T P_52 ; real_T P_53 ; real_T P_54 ; real_T P_55 ; } ; extern
P_ARDroneHoverSim_T ARDroneHoverSim_rtDefaultP ;
#endif
