#include "__cf_ARDroneHoverSim.h"
#include <math.h>
#include "ARDroneHoverSim_acc.h"
#include "ARDroneHoverSim_acc_private.h"
#include <stdio.h>
#include "slexec_vm_simstruct_bridge.h"
#include "slexec_vm_zc_functions.h"
#include "slexec_vm_lookup_functions.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "simstruc.h"
#include "fixedpoint.h"
#define CodeFormat S-Function
#define AccDefine1 Accelerator_S-Function
#include "simtarget/slAccSfcnBridge.h"
#ifndef __RTW_UTFREE__  
extern void * utMalloc ( size_t ) ; extern void utFree ( void * ) ;
#endif
boolean_T ARDroneHoverSim_acc_rt_TDelayUpdateTailOrGrowBuf ( int_T * bufSzPtr
, int_T * tailPtr , int_T * headPtr , int_T * lastPtr , real_T tMinusDelay ,
real_T * * tBufPtr , real_T * * uBufPtr , real_T * * xBufPtr , boolean_T
isfixedbuf , boolean_T istransportdelay , int_T * maxNewBufSzPtr ) { int_T
testIdx ; int_T tail = * tailPtr ; int_T bufSz = * bufSzPtr ; real_T * tBuf =
* tBufPtr ; real_T * xBuf = ( NULL ) ; int_T numBuffer = 2 ; if (
istransportdelay ) { numBuffer = 3 ; xBuf = * xBufPtr ; } testIdx = ( tail <
( bufSz - 1 ) ) ? ( tail + 1 ) : 0 ; if ( ( tMinusDelay <= tBuf [ testIdx ] )
&& ! isfixedbuf ) { int_T j ; real_T * tempT ; real_T * tempU ; real_T *
tempX = ( NULL ) ; real_T * uBuf = * uBufPtr ; int_T newBufSz = bufSz + 1024
; if ( newBufSz > * maxNewBufSzPtr ) { * maxNewBufSzPtr = newBufSz ; } tempU
= ( real_T * ) utMalloc ( numBuffer * newBufSz * sizeof ( real_T ) ) ; if (
tempU == ( NULL ) ) { return ( false ) ; } tempT = tempU + newBufSz ; if (
istransportdelay ) tempX = tempT + newBufSz ; for ( j = tail ; j < bufSz ; j
++ ) { tempT [ j - tail ] = tBuf [ j ] ; tempU [ j - tail ] = uBuf [ j ] ; if
( istransportdelay ) tempX [ j - tail ] = xBuf [ j ] ; } for ( j = 0 ; j <
tail ; j ++ ) { tempT [ j + bufSz - tail ] = tBuf [ j ] ; tempU [ j + bufSz -
tail ] = uBuf [ j ] ; if ( istransportdelay ) tempX [ j + bufSz - tail ] =
xBuf [ j ] ; } if ( * lastPtr > tail ) { * lastPtr -= tail ; } else { *
lastPtr += ( bufSz - tail ) ; } * tailPtr = 0 ; * headPtr = bufSz ; utFree (
uBuf ) ; * bufSzPtr = newBufSz ; * tBufPtr = tempT ; * uBufPtr = tempU ; if (
istransportdelay ) * xBufPtr = tempX ; } else { * tailPtr = testIdx ; }
return ( true ) ; } real_T ARDroneHoverSim_acc_rt_TDelayInterpolate ( real_T
tMinusDelay , real_T tStart , real_T * tBuf , real_T * uBuf , int_T bufSz ,
int_T * lastIdx , int_T oldestIdx , int_T newIdx , real_T initOutput ,
boolean_T discrete , boolean_T minorStepAndTAtLastMajorOutput ) { int_T i ;
real_T yout , t1 , t2 , u1 , u2 ; if ( ( newIdx == 0 ) && ( oldestIdx == 0 )
&& ( tMinusDelay > tStart ) ) return initOutput ; if ( tMinusDelay <= tStart
) return initOutput ; if ( ( tMinusDelay <= tBuf [ oldestIdx ] ) ) { if (
discrete ) { return ( uBuf [ oldestIdx ] ) ; } else { int_T tempIdx =
oldestIdx + 1 ; if ( oldestIdx == bufSz - 1 ) tempIdx = 0 ; t1 = tBuf [
oldestIdx ] ; t2 = tBuf [ tempIdx ] ; u1 = uBuf [ oldestIdx ] ; u2 = uBuf [
tempIdx ] ; if ( t2 == t1 ) { if ( tMinusDelay >= t2 ) { yout = u2 ; } else {
yout = u1 ; } } else { real_T f1 = ( t2 - tMinusDelay ) / ( t2 - t1 ) ;
real_T f2 = 1.0 - f1 ; yout = f1 * u1 + f2 * u2 ; } return yout ; } } if (
minorStepAndTAtLastMajorOutput ) { if ( newIdx != 0 ) { if ( * lastIdx ==
newIdx ) { ( * lastIdx ) -- ; } newIdx -- ; } else { if ( * lastIdx == newIdx
) { * lastIdx = bufSz - 1 ; } newIdx = bufSz - 1 ; } } i = * lastIdx ; if (
tBuf [ i ] < tMinusDelay ) { while ( tBuf [ i ] < tMinusDelay ) { if ( i ==
newIdx ) break ; i = ( i < ( bufSz - 1 ) ) ? ( i + 1 ) : 0 ; } } else { while
( tBuf [ i ] >= tMinusDelay ) { i = ( i > 0 ) ? i - 1 : ( bufSz - 1 ) ; } i =
( i < ( bufSz - 1 ) ) ? ( i + 1 ) : 0 ; } * lastIdx = i ; if ( discrete ) {
double tempEps = ( DBL_EPSILON ) * 128.0 ; double localEps = tempEps *
muDoubleScalarAbs ( tBuf [ i ] ) ; if ( tempEps > localEps ) { localEps =
tempEps ; } localEps = localEps / 2.0 ; if ( tMinusDelay >= ( tBuf [ i ] -
localEps ) ) { yout = uBuf [ i ] ; } else { if ( i == 0 ) { yout = uBuf [
bufSz - 1 ] ; } else { yout = uBuf [ i - 1 ] ; } } } else { if ( i == 0 ) {
t1 = tBuf [ bufSz - 1 ] ; u1 = uBuf [ bufSz - 1 ] ; } else { t1 = tBuf [ i -
1 ] ; u1 = uBuf [ i - 1 ] ; } t2 = tBuf [ i ] ; u2 = uBuf [ i ] ; if ( t2 ==
t1 ) { if ( tMinusDelay >= t2 ) { yout = u2 ; } else { yout = u1 ; } } else {
real_T f1 = ( t2 - tMinusDelay ) / ( t2 - t1 ) ; real_T f2 = 1.0 - f1 ; yout
= f1 * u1 + f2 * u2 ; } } return ( yout ) ; } void rt_ssGetBlockPath (
SimStruct * S , int_T sysIdx , int_T blkIdx , char_T * * path ) {
_ssGetBlockPath ( S , sysIdx , blkIdx , path ) ; } void rt_ssSet_slErrMsg (
SimStruct * S , void * diag ) { _ssSet_slErrMsg ( S , diag ) ; } void
rt_ssReportDiagnosticAsWarning ( SimStruct * S , void * diag ) {
_ssReportDiagnosticAsWarning ( S , diag ) ; } static void mdlOutputs (
SimStruct * S , int_T tid ) { int32_T isHit ; B_ARDroneHoverSim_T * _rtB ;
P_ARDroneHoverSim_T * _rtP ; X_ARDroneHoverSim_T * _rtX ;
DW_ARDroneHoverSim_T * _rtDW ; _rtDW = ( ( DW_ARDroneHoverSim_T * )
ssGetRootDWork ( S ) ) ; _rtX = ( ( X_ARDroneHoverSim_T * ) ssGetContStates (
S ) ) ; _rtP = ( ( P_ARDroneHoverSim_T * ) ssGetModelRtp ( S ) ) ; _rtB = ( (
B_ARDroneHoverSim_T * ) _ssGetModelBlockIO ( S ) ) ; isHit =
ssIsContinuousTask ( S , 0 ) ; if ( isHit != 0 ) { _rtB -> B_3_2_0 = 0.0 ;
_rtB -> B_3_2_0 += _rtP -> P_3 [ 0 ] * _rtX -> StateSpace_CSTATE [ 0 ] ; _rtB
-> B_3_2_0 += _rtP -> P_3 [ 1 ] * _rtX -> StateSpace_CSTATE [ 1 ] ; _rtB ->
B_3_3_0 = _rtP -> P_5 * _rtB -> B_3_2_0 ; _rtB -> B_3_4_0 = 0.0 ; _rtB ->
B_3_4_0 += _rtP -> P_8 [ 0 ] * _rtX -> StateSpace1_CSTATE [ 0 ] ; _rtB ->
B_3_4_0 += _rtP -> P_8 [ 1 ] * _rtX -> StateSpace1_CSTATE [ 1 ] ; _rtB ->
B_3_5_0 = _rtP -> P_10 * _rtB -> B_3_4_0 ; _rtB -> B_3_6_0 = 0.0 ; _rtB ->
B_3_6_0 += _rtP -> P_13 * _rtX -> StateSpace4_CSTATE ; ssCallAccelRunBlock (
S , 0 , 0 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_3_8_0 = _rtP -> P_15 * _rtB ->
B_0_0_1 ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) {
ssCallAccelRunBlock ( S , 3 , 9 , SS_CALL_MDL_OUTPUTS ) ; } isHit =
ssIsContinuousTask ( S , 0 ) ; if ( isHit != 0 ) { _rtB -> B_3_10_0 = 0.0 ;
_rtB -> B_3_10_0 += _rtP -> P_18 [ 0 ] * _rtX -> StateSpace5_CSTATE [ 0 ] ;
_rtB -> B_3_10_0 += _rtP -> P_18 [ 1 ] * _rtX -> StateSpace5_CSTATE [ 1 ] ; }
isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { ssCallAccelRunBlock
( S , 3 , 11 , SS_CALL_MDL_OUTPUTS ) ; } isHit = ssIsContinuousTask ( S , 0 )
; if ( isHit != 0 ) { if ( _rtDW -> Integrator_IWORK != 0 ) { _rtX ->
Integrator_CSTATE [ 0 ] = _rtB -> B_3_12_0 [ 0 ] ; _rtX -> Integrator_CSTATE
[ 1 ] = _rtB -> B_3_12_0 [ 1 ] ; } _rtB -> B_3_13_0 [ 0 ] = _rtX ->
Integrator_CSTATE [ 0 ] ; _rtB -> B_3_13_0 [ 1 ] = _rtX -> Integrator_CSTATE
[ 1 ] ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) {
ssCallAccelRunBlock ( S , 3 , 14 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 3 , 15 , SS_CALL_MDL_OUTPUTS ) ; } isHit =
ssIsContinuousTask ( S , 0 ) ; if ( isHit != 0 ) { _rtB -> B_3_16_0 [ 0 ] =
_rtP -> P_21 * _rtB -> B_3_3_0 ; _rtB -> B_3_16_0 [ 1 ] = _rtP -> P_21 * _rtB
-> B_3_5_0 ; _rtB -> B_3_16_0 [ 2 ] = _rtP -> P_21 * _rtB -> B_3_8_0 ; _rtB
-> B_3_17_0 = _rtP -> P_22 * _rtB -> B_3_16_0 [ 2 ] ; } isHit = ssIsSampleHit
( S , 1 , 0 ) ; if ( isHit != 0 ) { ssCallAccelRunBlock ( S , 3 , 18 ,
SS_CALL_MDL_OUTPUTS ) ; isHit = ssIsSpecialSampleHit ( S , 2 , 1 , 0 ) ; if (
isHit != 0 ) { _rtB -> B_3_19_0 = _rtDW -> RTrans4_Buffer0 ; } if ( _rtB ->
B_3_19_0 > _rtP -> P_24 ) { _rtB -> B_3_20_0 = _rtP -> P_24 ; } else if (
_rtB -> B_3_19_0 < _rtP -> P_25 ) { _rtB -> B_3_20_0 = _rtP -> P_25 ; } else
{ _rtB -> B_3_20_0 = _rtB -> B_3_19_0 ; } isHit = ssIsSpecialSampleHit ( S ,
2 , 1 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_3_21_0 = _rtDW -> RTrans3_Buffer0
; } if ( _rtB -> B_3_21_0 > _rtP -> P_27 ) { _rtB -> B_3_22_0 = _rtP -> P_27
; } else if ( _rtB -> B_3_21_0 < _rtP -> P_28 ) { _rtB -> B_3_22_0 = _rtP ->
P_28 ; } else { _rtB -> B_3_22_0 = _rtB -> B_3_21_0 ; } isHit =
ssIsSpecialSampleHit ( S , 2 , 1 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_3_23_0
= _rtDW -> RTrans2_Buffer0 ; } if ( _rtB -> B_3_23_0 > _rtP -> P_30 ) { _rtB
-> B_3_24_0 = _rtP -> P_30 ; } else if ( _rtB -> B_3_23_0 < _rtP -> P_31 ) {
_rtB -> B_3_24_0 = _rtP -> P_31 ; } else { _rtB -> B_3_24_0 = _rtB ->
B_3_23_0 ; } isHit = ssIsSpecialSampleHit ( S , 2 , 1 , 0 ) ; if ( isHit != 0
) { _rtB -> B_3_25_0 = _rtDW -> RTrans1_Buffer0 ; } if ( _rtB -> B_3_25_0 >
_rtP -> P_33 ) { _rtB -> B_3_26_0 = _rtP -> P_33 ; } else if ( _rtB ->
B_3_25_0 < _rtP -> P_34 ) { _rtB -> B_3_26_0 = _rtP -> P_34 ; } else { _rtB
-> B_3_26_0 = _rtB -> B_3_25_0 ; } } isHit = ssIsContinuousTask ( S , 0 ) ;
if ( isHit != 0 ) { _rtB -> B_3_27_0 = 0.0 ; _rtB -> B_3_27_0 += _rtP -> P_37
* _rtX -> StateSpace2_CSTATE ; _rtB -> B_3_28_0 = 0.0 ; _rtB -> B_3_28_0 +=
_rtP -> P_41 * _rtX -> StateSpace3_CSTATE ; { real_T * * uBuffer = ( real_T *
* ) & _rtDW -> totalcommunicationtimedelay_PWORK . TUbufferPtrs [ 0 ] ;
real_T * * tBuffer = ( real_T * * ) & _rtDW ->
totalcommunicationtimedelay_PWORK . TUbufferPtrs [ 4 ] ; real_T simTime =
ssGetT ( S ) ; real_T appliedDelay ; appliedDelay = _rtB -> B_3_29_0 ; if (
appliedDelay > _rtP -> P_44 ) { appliedDelay = _rtP -> P_44 ; } if (
appliedDelay < 0.0 ) { appliedDelay = 0.0 ; } _rtB -> B_3_30_0 [ 0 ] =
ARDroneHoverSim_acc_rt_TDelayInterpolate ( simTime - appliedDelay , 0.0 , *
tBuffer , * uBuffer , _rtDW -> totalcommunicationtimedelay_IWORK .
CircularBufSize [ 0 ] , & _rtDW -> totalcommunicationtimedelay_IWORK . Last [
0 ] , _rtDW -> totalcommunicationtimedelay_IWORK . Tail [ 0 ] , _rtDW ->
totalcommunicationtimedelay_IWORK . Head [ 0 ] , _rtP -> P_45 [ 0 ] , 1 , (
boolean_T ) ( ssIsMinorTimeStep ( S ) && ( ssGetTimeOfLastOutput ( S ) ==
ssGetT ( S ) ) ) ) ; tBuffer ++ ; uBuffer ++ ; appliedDelay = _rtB ->
B_3_29_0 ; if ( appliedDelay > _rtP -> P_44 ) { appliedDelay = _rtP -> P_44 ;
} if ( appliedDelay < 0.0 ) { appliedDelay = 0.0 ; } _rtB -> B_3_30_0 [ 1 ] =
ARDroneHoverSim_acc_rt_TDelayInterpolate ( simTime - appliedDelay , 0.0 , *
tBuffer , * uBuffer , _rtDW -> totalcommunicationtimedelay_IWORK .
CircularBufSize [ 1 ] , & _rtDW -> totalcommunicationtimedelay_IWORK . Last [
1 ] , _rtDW -> totalcommunicationtimedelay_IWORK . Tail [ 1 ] , _rtDW ->
totalcommunicationtimedelay_IWORK . Head [ 1 ] , _rtP -> P_45 [ 1 ] , 1 , (
boolean_T ) ( ssIsMinorTimeStep ( S ) && ( ssGetTimeOfLastOutput ( S ) ==
ssGetT ( S ) ) ) ) ; tBuffer ++ ; uBuffer ++ ; appliedDelay = _rtB ->
B_3_29_0 ; if ( appliedDelay > _rtP -> P_44 ) { appliedDelay = _rtP -> P_44 ;
} if ( appliedDelay < 0.0 ) { appliedDelay = 0.0 ; } _rtB -> B_3_30_0 [ 2 ] =
ARDroneHoverSim_acc_rt_TDelayInterpolate ( simTime - appliedDelay , 0.0 , *
tBuffer , * uBuffer , _rtDW -> totalcommunicationtimedelay_IWORK .
CircularBufSize [ 2 ] , & _rtDW -> totalcommunicationtimedelay_IWORK . Last [
2 ] , _rtDW -> totalcommunicationtimedelay_IWORK . Tail [ 2 ] , _rtDW ->
totalcommunicationtimedelay_IWORK . Head [ 2 ] , _rtP -> P_45 [ 2 ] , 1 , (
boolean_T ) ( ssIsMinorTimeStep ( S ) && ( ssGetTimeOfLastOutput ( S ) ==
ssGetT ( S ) ) ) ) ; tBuffer ++ ; uBuffer ++ ; appliedDelay = _rtB ->
B_3_29_0 ; if ( appliedDelay > _rtP -> P_44 ) { appliedDelay = _rtP -> P_44 ;
} if ( appliedDelay < 0.0 ) { appliedDelay = 0.0 ; } _rtB -> B_3_30_0 [ 3 ] =
ARDroneHoverSim_acc_rt_TDelayInterpolate ( simTime - appliedDelay , 0.0 , *
tBuffer , * uBuffer , _rtDW -> totalcommunicationtimedelay_IWORK .
CircularBufSize [ 3 ] , & _rtDW -> totalcommunicationtimedelay_IWORK . Last [
3 ] , _rtDW -> totalcommunicationtimedelay_IWORK . Tail [ 3 ] , _rtDW ->
totalcommunicationtimedelay_IWORK . Head [ 3 ] , _rtP -> P_45 [ 3 ] , 1 , (
boolean_T ) ( ssIsMinorTimeStep ( S ) && ( ssGetTimeOfLastOutput ( S ) ==
ssGetT ( S ) ) ) ) ; } } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit !=
0 ) { isHit = ssIsSpecialSampleHit ( S , 2 , 1 , 0 ) ; if ( isHit != 0 ) {
_rtB -> B_3_31_0 = _rtB -> B_3_28_0 ; } isHit = ssIsSpecialSampleHit ( S , 2
, 1 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_3_32_0 = _rtB -> B_3_13_0 [ 0 ] ; }
isHit = ssIsSpecialSampleHit ( S , 2 , 1 , 0 ) ; if ( isHit != 0 ) { _rtB ->
B_3_33_0 = _rtB -> B_3_13_0 [ 1 ] ; } } isHit = ssIsSampleHit ( S , 2 , 0 ) ;
if ( isHit != 0 ) { _rtB -> B_3_36_0 [ 0 ] = _rtP -> P_46 - _rtB -> B_3_32_0
; _rtB -> B_3_36_0 [ 1 ] = _rtP -> P_47 - _rtB -> B_3_33_0 ; } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { isHit =
ssIsSpecialSampleHit ( S , 2 , 1 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_3_37_0
= _rtB -> B_3_16_0 [ 2 ] ; } } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if (
isHit != 0 ) { ssCallAccelRunBlock ( S , 1 , 0 , SS_CALL_MDL_OUTPUTS ) ; _rtB
-> B_3_41_0 = ( _rtP -> P_48 * _rtB -> B_1_0_1 [ 0 ] - _rtB -> B_3_31_0 ) *
_rtP -> P_49 ; _rtB -> B_3_44_0 = ( _rtP -> P_50 - _rtB -> B_3_37_0 ) * _rtP
-> P_51 ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { isHit =
ssIsSpecialSampleHit ( S , 2 , 1 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_3_45_0
= _rtB -> B_3_10_0 ; } } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit !=
0 ) { _rtB -> B_3_48_0 = ( _rtP -> P_52 - _rtB -> B_3_45_0 ) * _rtP -> P_53 ;
} isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { isHit =
ssIsSpecialSampleHit ( S , 2 , 1 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_3_49_0
= _rtB -> B_3_27_0 ; } } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit !=
0 ) { _rtB -> B_3_52_0 = ( _rtP -> P_54 * _rtB -> B_1_0_1 [ 1 ] - _rtB ->
B_3_49_0 ) * _rtP -> P_55 ; } isHit = ssIsContinuousTask ( S , 0 ) ; if (
isHit != 0 ) { ssCallAccelRunBlock ( S , 2 , 0 , SS_CALL_MDL_OUTPUTS ) ; }
UNUSED_PARAMETER ( tid ) ; } static void mdlOutputsTID3 ( SimStruct * S ,
int_T tid ) { B_ARDroneHoverSim_T * _rtB ; P_ARDroneHoverSim_T * _rtP ; _rtP
= ( ( P_ARDroneHoverSim_T * ) ssGetModelRtp ( S ) ) ; _rtB = ( (
B_ARDroneHoverSim_T * ) _ssGetModelBlockIO ( S ) ) ; _rtB -> B_3_0_0 = _rtP
-> P_0 ; ssCallAccelRunBlock ( S , 3 , 1 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
B_3_12_0 [ 0 ] = _rtP -> P_20 [ 0 ] ; _rtB -> B_3_12_0 [ 1 ] = _rtP -> P_20 [
1 ] ; _rtB -> B_3_29_0 = _rtP -> P_43 ; UNUSED_PARAMETER ( tid ) ; }
#define MDL_UPDATE
static void mdlUpdate ( SimStruct * S , int_T tid ) { int32_T isHit ;
B_ARDroneHoverSim_T * _rtB ; P_ARDroneHoverSim_T * _rtP ;
DW_ARDroneHoverSim_T * _rtDW ; _rtDW = ( ( DW_ARDroneHoverSim_T * )
ssGetRootDWork ( S ) ) ; _rtP = ( ( P_ARDroneHoverSim_T * ) ssGetModelRtp ( S
) ) ; _rtB = ( ( B_ARDroneHoverSim_T * ) _ssGetModelBlockIO ( S ) ) ; isHit =
ssIsContinuousTask ( S , 0 ) ; if ( isHit != 0 ) { _rtDW -> Integrator_IWORK
= 0 ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { _rtDW ->
RTrans4_Buffer0 = _rtB -> B_3_52_0 ; _rtDW -> RTrans3_Buffer0 = _rtB ->
B_3_41_0 ; _rtDW -> RTrans2_Buffer0 = _rtB -> B_3_44_0 ; _rtDW ->
RTrans1_Buffer0 = _rtB -> B_3_48_0 ; } isHit = ssIsContinuousTask ( S , 0 ) ;
if ( isHit != 0 ) { { real_T * * uBuffer = ( real_T * * ) & _rtDW ->
totalcommunicationtimedelay_PWORK . TUbufferPtrs [ 0 ] ; real_T * * tBuffer =
( real_T * * ) & _rtDW -> totalcommunicationtimedelay_PWORK . TUbufferPtrs [
4 ] ; real_T * * xBuffer = ( NULL ) ; real_T simTime = ssGetT ( S ) ; _rtDW
-> totalcommunicationtimedelay_IWORK . Head [ 0 ] = ( ( _rtDW ->
totalcommunicationtimedelay_IWORK . Head [ 0 ] < ( _rtDW ->
totalcommunicationtimedelay_IWORK . CircularBufSize [ 0 ] - 1 ) ) ? ( _rtDW
-> totalcommunicationtimedelay_IWORK . Head [ 0 ] + 1 ) : 0 ) ; if ( _rtDW ->
totalcommunicationtimedelay_IWORK . Head [ 0 ] == _rtDW ->
totalcommunicationtimedelay_IWORK . Tail [ 0 ] ) { if ( !
ARDroneHoverSim_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
totalcommunicationtimedelay_IWORK . CircularBufSize [ 0 ] , & _rtDW ->
totalcommunicationtimedelay_IWORK . Tail [ 0 ] , & _rtDW ->
totalcommunicationtimedelay_IWORK . Head [ 0 ] , & _rtDW ->
totalcommunicationtimedelay_IWORK . Last [ 0 ] , simTime - _rtP -> P_44 ,
tBuffer , uBuffer , xBuffer , ( boolean_T ) 0 , ( boolean_T ) 0 , & _rtDW ->
totalcommunicationtimedelay_IWORK . MaxNewBufSize ) ) { ssSetErrorStatus ( S
, "vtdelay memory allocation error" ) ; return ; } } ( * tBuffer ++ ) [ _rtDW
-> totalcommunicationtimedelay_IWORK . Head [ 0 ] ] = simTime ; ( * uBuffer
++ ) [ _rtDW -> totalcommunicationtimedelay_IWORK . Head [ 0 ] ] = _rtB ->
B_3_20_0 ; _rtDW -> totalcommunicationtimedelay_IWORK . Head [ 1 ] = ( (
_rtDW -> totalcommunicationtimedelay_IWORK . Head [ 1 ] < ( _rtDW ->
totalcommunicationtimedelay_IWORK . CircularBufSize [ 1 ] - 1 ) ) ? ( _rtDW
-> totalcommunicationtimedelay_IWORK . Head [ 1 ] + 1 ) : 0 ) ; if ( _rtDW ->
totalcommunicationtimedelay_IWORK . Head [ 1 ] == _rtDW ->
totalcommunicationtimedelay_IWORK . Tail [ 1 ] ) { if ( !
ARDroneHoverSim_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
totalcommunicationtimedelay_IWORK . CircularBufSize [ 1 ] , & _rtDW ->
totalcommunicationtimedelay_IWORK . Tail [ 1 ] , & _rtDW ->
totalcommunicationtimedelay_IWORK . Head [ 1 ] , & _rtDW ->
totalcommunicationtimedelay_IWORK . Last [ 1 ] , simTime - _rtP -> P_44 ,
tBuffer , uBuffer , xBuffer , ( boolean_T ) 0 , ( boolean_T ) 0 , & _rtDW ->
totalcommunicationtimedelay_IWORK . MaxNewBufSize ) ) { ssSetErrorStatus ( S
, "vtdelay memory allocation error" ) ; return ; } } ( * tBuffer ++ ) [ _rtDW
-> totalcommunicationtimedelay_IWORK . Head [ 1 ] ] = simTime ; ( * uBuffer
++ ) [ _rtDW -> totalcommunicationtimedelay_IWORK . Head [ 1 ] ] = _rtB ->
B_3_22_0 ; _rtDW -> totalcommunicationtimedelay_IWORK . Head [ 2 ] = ( (
_rtDW -> totalcommunicationtimedelay_IWORK . Head [ 2 ] < ( _rtDW ->
totalcommunicationtimedelay_IWORK . CircularBufSize [ 2 ] - 1 ) ) ? ( _rtDW
-> totalcommunicationtimedelay_IWORK . Head [ 2 ] + 1 ) : 0 ) ; if ( _rtDW ->
totalcommunicationtimedelay_IWORK . Head [ 2 ] == _rtDW ->
totalcommunicationtimedelay_IWORK . Tail [ 2 ] ) { if ( !
ARDroneHoverSim_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
totalcommunicationtimedelay_IWORK . CircularBufSize [ 2 ] , & _rtDW ->
totalcommunicationtimedelay_IWORK . Tail [ 2 ] , & _rtDW ->
totalcommunicationtimedelay_IWORK . Head [ 2 ] , & _rtDW ->
totalcommunicationtimedelay_IWORK . Last [ 2 ] , simTime - _rtP -> P_44 ,
tBuffer , uBuffer , xBuffer , ( boolean_T ) 0 , ( boolean_T ) 0 , & _rtDW ->
totalcommunicationtimedelay_IWORK . MaxNewBufSize ) ) { ssSetErrorStatus ( S
, "vtdelay memory allocation error" ) ; return ; } } ( * tBuffer ++ ) [ _rtDW
-> totalcommunicationtimedelay_IWORK . Head [ 2 ] ] = simTime ; ( * uBuffer
++ ) [ _rtDW -> totalcommunicationtimedelay_IWORK . Head [ 2 ] ] = _rtB ->
B_3_24_0 ; _rtDW -> totalcommunicationtimedelay_IWORK . Head [ 3 ] = ( (
_rtDW -> totalcommunicationtimedelay_IWORK . Head [ 3 ] < ( _rtDW ->
totalcommunicationtimedelay_IWORK . CircularBufSize [ 3 ] - 1 ) ) ? ( _rtDW
-> totalcommunicationtimedelay_IWORK . Head [ 3 ] + 1 ) : 0 ) ; if ( _rtDW ->
totalcommunicationtimedelay_IWORK . Head [ 3 ] == _rtDW ->
totalcommunicationtimedelay_IWORK . Tail [ 3 ] ) { if ( !
ARDroneHoverSim_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
totalcommunicationtimedelay_IWORK . CircularBufSize [ 3 ] , & _rtDW ->
totalcommunicationtimedelay_IWORK . Tail [ 3 ] , & _rtDW ->
totalcommunicationtimedelay_IWORK . Head [ 3 ] , & _rtDW ->
totalcommunicationtimedelay_IWORK . Last [ 3 ] , simTime - _rtP -> P_44 ,
tBuffer , uBuffer , xBuffer , ( boolean_T ) 0 , ( boolean_T ) 0 , & _rtDW ->
totalcommunicationtimedelay_IWORK . MaxNewBufSize ) ) { ssSetErrorStatus ( S
, "vtdelay memory allocation error" ) ; return ; } } ( * tBuffer ) [ _rtDW ->
totalcommunicationtimedelay_IWORK . Head [ 3 ] ] = simTime ; ( * uBuffer ) [
_rtDW -> totalcommunicationtimedelay_IWORK . Head [ 3 ] ] = _rtB -> B_3_26_0
; } } UNUSED_PARAMETER ( tid ) ; }
#define MDL_UPDATE
static void mdlUpdateTID3 ( SimStruct * S , int_T tid ) { UNUSED_PARAMETER (
tid ) ; }
#define MDL_DERIVATIVES
static void mdlDerivatives ( SimStruct * S ) { B_ARDroneHoverSim_T * _rtB ;
P_ARDroneHoverSim_T * _rtP ; X_ARDroneHoverSim_T * _rtX ;
XDot_ARDroneHoverSim_T * _rtXdot ; DW_ARDroneHoverSim_T * _rtDW ; _rtDW = ( (
DW_ARDroneHoverSim_T * ) ssGetRootDWork ( S ) ) ; _rtXdot = ( (
XDot_ARDroneHoverSim_T * ) ssGetdX ( S ) ) ; _rtX = ( ( X_ARDroneHoverSim_T *
) ssGetContStates ( S ) ) ; _rtP = ( ( P_ARDroneHoverSim_T * ) ssGetModelRtp
( S ) ) ; _rtB = ( ( B_ARDroneHoverSim_T * ) _ssGetModelBlockIO ( S ) ) ;
_rtXdot -> StateSpace_CSTATE [ 0 ] = 0.0 ; _rtXdot -> StateSpace1_CSTATE [ 0
] = 0.0 ; _rtXdot -> StateSpace_CSTATE [ 1 ] = 0.0 ; _rtXdot ->
StateSpace1_CSTATE [ 1 ] = 0.0 ; _rtXdot -> StateSpace_CSTATE [ 0 ] += _rtP
-> P_1 [ 0 ] * _rtX -> StateSpace_CSTATE [ 0 ] ; _rtXdot -> StateSpace_CSTATE
[ 0 ] += _rtP -> P_1 [ 1 ] * _rtX -> StateSpace_CSTATE [ 1 ] ; _rtXdot ->
StateSpace_CSTATE [ 1 ] += _rtP -> P_1 [ 2 ] * _rtX -> StateSpace_CSTATE [ 0
] ; _rtXdot -> StateSpace_CSTATE [ 0 ] += _rtP -> P_2 * _rtB -> B_3_30_0 [ 0
] ; _rtXdot -> StateSpace1_CSTATE [ 0 ] += _rtP -> P_6 [ 0 ] * _rtX ->
StateSpace1_CSTATE [ 0 ] ; _rtXdot -> StateSpace1_CSTATE [ 0 ] += _rtP -> P_6
[ 1 ] * _rtX -> StateSpace1_CSTATE [ 1 ] ; _rtXdot -> StateSpace1_CSTATE [ 1
] += _rtP -> P_6 [ 2 ] * _rtX -> StateSpace1_CSTATE [ 0 ] ; _rtXdot ->
StateSpace1_CSTATE [ 0 ] += _rtP -> P_7 * _rtB -> B_3_30_0 [ 1 ] ; _rtXdot ->
StateSpace4_CSTATE = 0.0 ; _rtXdot -> StateSpace4_CSTATE += _rtP -> P_11 *
_rtX -> StateSpace4_CSTATE ; _rtXdot -> StateSpace4_CSTATE += _rtP -> P_12 *
_rtB -> B_3_30_0 [ 2 ] ; _rtXdot -> StateSpace5_CSTATE [ 0 ] = 0.0 ; _rtXdot
-> Integrator_CSTATE [ 0 ] = _rtB -> B_2_0_1 [ 0 ] ; _rtXdot ->
StateSpace5_CSTATE [ 1 ] = 0.0 ; _rtXdot -> Integrator_CSTATE [ 1 ] = _rtB ->
B_2_0_1 [ 1 ] ; _rtXdot -> StateSpace5_CSTATE [ 0 ] += _rtP -> P_16 [ 0 ] *
_rtX -> StateSpace5_CSTATE [ 0 ] ; _rtXdot -> StateSpace5_CSTATE [ 0 ] +=
_rtP -> P_16 [ 1 ] * _rtX -> StateSpace5_CSTATE [ 1 ] ; _rtXdot ->
StateSpace5_CSTATE [ 1 ] += _rtP -> P_16 [ 2 ] * _rtX -> StateSpace5_CSTATE [
0 ] ; _rtXdot -> StateSpace5_CSTATE [ 0 ] += _rtP -> P_17 * _rtB -> B_3_30_0
[ 3 ] ; _rtXdot -> StateSpace2_CSTATE = 0.0 ; _rtXdot -> StateSpace2_CSTATE
+= _rtP -> P_35 * _rtX -> StateSpace2_CSTATE ; _rtXdot -> StateSpace2_CSTATE
+= _rtP -> P_36 * _rtB -> B_3_2_0 ; _rtXdot -> StateSpace3_CSTATE = 0.0 ;
_rtXdot -> StateSpace3_CSTATE += _rtP -> P_39 * _rtX -> StateSpace3_CSTATE ;
_rtXdot -> StateSpace3_CSTATE += _rtP -> P_40 * _rtB -> B_3_4_0 ; { } }
static void mdlInitializeSizes ( SimStruct * S ) { ssSetChecksumVal ( S , 0 ,
3140041195U ) ; ssSetChecksumVal ( S , 1 , 1868316226U ) ; ssSetChecksumVal (
S , 2 , 1033058685U ) ; ssSetChecksumVal ( S , 3 , 1350087037U ) ; { mxArray
* slVerStructMat = NULL ; mxArray * slStrMat = mxCreateString ( "simulink" )
; char slVerChar [ 10 ] ; int status = mexCallMATLAB ( 1 , & slVerStructMat ,
1 , & slStrMat , "ver" ) ; if ( status == 0 ) { mxArray * slVerMat =
mxGetField ( slVerStructMat , 0 , "Version" ) ; if ( slVerMat == NULL ) {
status = 1 ; } else { status = mxGetString ( slVerMat , slVerChar , 10 ) ; }
} mxDestroyArray ( slStrMat ) ; mxDestroyArray ( slVerStructMat ) ; if ( (
status == 1 ) || ( strcmp ( slVerChar , "9.0" ) != 0 ) ) { return ; } }
ssSetOptions ( S , SS_OPTION_EXCEPTION_FREE_CODE ) ; if ( ssGetSizeofDWork (
S ) != sizeof ( DW_ARDroneHoverSim_T ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal DWork sizes do "
"not match for accelerator mex file." ) ; } if ( ssGetSizeofGlobalBlockIO ( S
) != sizeof ( B_ARDroneHoverSim_T ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal BlockIO sizes do "
"not match for accelerator mex file." ) ; } { int ssSizeofParams ;
ssGetSizeofParams ( S , & ssSizeofParams ) ; if ( ssSizeofParams != sizeof (
P_ARDroneHoverSim_T ) ) { static char msg [ 256 ] ; sprintf ( msg ,
"Unexpected error: Internal Parameters sizes do "
"not match for accelerator mex file." ) ; } } _ssSetModelRtp ( S , ( real_T *
) & ARDroneHoverSim_rtDefaultP ) ; rt_InitInfAndNaN ( sizeof ( real_T ) ) ; }
static void mdlInitializeSampleTimes ( SimStruct * S ) { { SimStruct * childS
; SysOutputFcn * callSysFcns ; childS = ssGetSFunction ( S , 0 ) ;
callSysFcns = ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ]
= ( SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 1 ) ; callSysFcns
= ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 2 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; } slAccRegPrmChangeFcn ( S , mdlOutputsTID3 ) ; }
static void mdlTerminate ( SimStruct * S ) { }
#include "simulink.c"
