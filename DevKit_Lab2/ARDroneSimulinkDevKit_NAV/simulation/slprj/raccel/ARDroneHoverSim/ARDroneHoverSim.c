#include "__cf_ARDroneHoverSim.h"
#include "rt_logging_mmi.h"
#include "ARDroneHoverSim_capi.h"
#include <math.h>
#include "ARDroneHoverSim.h"
#include "ARDroneHoverSim_private.h"
#include "ARDroneHoverSim_dt.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; RTWExtModeInfo * gblRTWExtModeInfo = NULL ; extern boolean_T
gblExtModeStartPktReceived ; void raccelForceExtModeShutdown ( ) { if ( !
gblExtModeStartPktReceived ) { boolean_T stopRequested = false ;
rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 3 , & stopRequested ) ; }
rtExtModeShutdown ( 3 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 0 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 1 ; int_T gbl_raccel_NumST = 4 ; const char_T
* gbl_raccel_Version = "8.13 (R2017b) 24-Jul-2017" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#else
UNUSED_PARAMETER ( S ) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; const char * gblSlvrJacPatternFileName =
"slprj//raccel//ARDroneHoverSim//ARDroneHoverSim_Jpattern.mat" ; const int_T
gblNumRootInportBlks = 0 ; const int_T gblNumModelInputs = 0 ; extern
rtInportTUtable * gblInportTUtables ; extern const char * gblInportFileName ;
const int_T gblInportDataTypeIdx [ ] = { - 1 } ; const int_T gblInportDims [
] = { - 1 } ; const int_T gblInportComplex [ ] = { - 1 } ; const int_T
gblInportInterpoFlag [ ] = { - 1 } ; const int_T gblInportContinuous [ ] = {
- 1 } ;
#include "simstruc.h"
#include "fixedpoint.h"
B rtB ; X rtX ; DW rtDW ; static SimStruct model_S ; SimStruct * const rtS =
& model_S ;
#ifndef __RTW_UTFREE__  
extern void * utMalloc ( size_t ) ;
#endif
void * rt_TDelayCreateBuf ( int_T numBuffer , int_T bufSz , int_T elemSz ) {
return ( ( void * ) utMalloc ( numBuffer * bufSz * elemSz ) ) ; }
#ifndef __RTW_UTFREE__  
extern void * utMalloc ( size_t ) ; extern void utFree ( void * ) ;
#endif
boolean_T rt_TDelayUpdateTailOrGrowBuf ( int_T * bufSzPtr , int_T * tailPtr ,
int_T * headPtr , int_T * lastPtr , real_T tMinusDelay , real_T * * tBufPtr ,
real_T * * uBufPtr , real_T * * xBufPtr , boolean_T isfixedbuf , boolean_T
istransportdelay , int_T * maxNewBufSzPtr ) { int_T testIdx ; int_T tail = *
tailPtr ; int_T bufSz = * bufSzPtr ; real_T * tBuf = * tBufPtr ; real_T *
xBuf = ( NULL ) ; int_T numBuffer = 2 ; if ( istransportdelay ) { numBuffer =
3 ; xBuf = * xBufPtr ; } testIdx = ( tail < ( bufSz - 1 ) ) ? ( tail + 1 ) :
0 ; if ( ( tMinusDelay <= tBuf [ testIdx ] ) && ! isfixedbuf ) { int_T j ;
real_T * tempT ; real_T * tempU ; real_T * tempX = ( NULL ) ; real_T * uBuf =
* uBufPtr ; int_T newBufSz = bufSz + 1024 ; if ( newBufSz > * maxNewBufSzPtr
) { * maxNewBufSzPtr = newBufSz ; } tempU = ( real_T * ) utMalloc ( numBuffer
* newBufSz * sizeof ( real_T ) ) ; if ( tempU == ( NULL ) ) { return ( false
) ; } tempT = tempU + newBufSz ; if ( istransportdelay ) tempX = tempT +
newBufSz ; for ( j = tail ; j < bufSz ; j ++ ) { tempT [ j - tail ] = tBuf [
j ] ; tempU [ j - tail ] = uBuf [ j ] ; if ( istransportdelay ) tempX [ j -
tail ] = xBuf [ j ] ; } for ( j = 0 ; j < tail ; j ++ ) { tempT [ j + bufSz -
tail ] = tBuf [ j ] ; tempU [ j + bufSz - tail ] = uBuf [ j ] ; if (
istransportdelay ) tempX [ j + bufSz - tail ] = xBuf [ j ] ; } if ( * lastPtr
> tail ) { * lastPtr -= tail ; } else { * lastPtr += ( bufSz - tail ) ; } *
tailPtr = 0 ; * headPtr = bufSz ; utFree ( uBuf ) ; * bufSzPtr = newBufSz ; *
tBufPtr = tempT ; * uBufPtr = tempU ; if ( istransportdelay ) * xBufPtr =
tempX ; } else { * tailPtr = testIdx ; } return ( true ) ; } real_T
rt_TDelayInterpolate ( real_T tMinusDelay , real_T tStart , real_T * tBuf ,
real_T * uBuf , int_T bufSz , int_T * lastIdx , int_T oldestIdx , int_T
newIdx , real_T initOutput , boolean_T discrete , boolean_T
minorStepAndTAtLastMajorOutput ) { int_T i ; real_T yout , t1 , t2 , u1 , u2
; if ( ( newIdx == 0 ) && ( oldestIdx == 0 ) && ( tMinusDelay > tStart ) )
return initOutput ; if ( tMinusDelay <= tStart ) return initOutput ; if ( (
tMinusDelay <= tBuf [ oldestIdx ] ) ) { if ( discrete ) { return ( uBuf [
oldestIdx ] ) ; } else { int_T tempIdx = oldestIdx + 1 ; if ( oldestIdx ==
bufSz - 1 ) tempIdx = 0 ; t1 = tBuf [ oldestIdx ] ; t2 = tBuf [ tempIdx ] ;
u1 = uBuf [ oldestIdx ] ; u2 = uBuf [ tempIdx ] ; if ( t2 == t1 ) { if (
tMinusDelay >= t2 ) { yout = u2 ; } else { yout = u1 ; } } else { real_T f1 =
( t2 - tMinusDelay ) / ( t2 - t1 ) ; real_T f2 = 1.0 - f1 ; yout = f1 * u1 +
f2 * u2 ; } return yout ; } } if ( minorStepAndTAtLastMajorOutput ) { if (
newIdx != 0 ) { if ( * lastIdx == newIdx ) { ( * lastIdx ) -- ; } newIdx -- ;
} else { if ( * lastIdx == newIdx ) { * lastIdx = bufSz - 1 ; } newIdx =
bufSz - 1 ; } } i = * lastIdx ; if ( tBuf [ i ] < tMinusDelay ) { while (
tBuf [ i ] < tMinusDelay ) { if ( i == newIdx ) break ; i = ( i < ( bufSz - 1
) ) ? ( i + 1 ) : 0 ; } } else { while ( tBuf [ i ] >= tMinusDelay ) { i = (
i > 0 ) ? i - 1 : ( bufSz - 1 ) ; } i = ( i < ( bufSz - 1 ) ) ? ( i + 1 ) : 0
; } * lastIdx = i ; if ( discrete ) { double tempEps = ( DBL_EPSILON ) *
128.0 ; double localEps = tempEps * muDoubleScalarAbs ( tBuf [ i ] ) ; if (
tempEps > localEps ) { localEps = tempEps ; } localEps = localEps / 2.0 ; if
( tMinusDelay >= ( tBuf [ i ] - localEps ) ) { yout = uBuf [ i ] ; } else {
if ( i == 0 ) { yout = uBuf [ bufSz - 1 ] ; } else { yout = uBuf [ i - 1 ] ;
} } } else { if ( i == 0 ) { t1 = tBuf [ bufSz - 1 ] ; u1 = uBuf [ bufSz - 1
] ; } else { t1 = tBuf [ i - 1 ] ; u1 = uBuf [ i - 1 ] ; } t2 = tBuf [ i ] ;
u2 = uBuf [ i ] ; if ( t2 == t1 ) { if ( tMinusDelay >= t2 ) { yout = u2 ; }
else { yout = u1 ; } } else { real_T f1 = ( t2 - tMinusDelay ) / ( t2 - t1 )
; real_T f2 = 1.0 - f1 ; yout = f1 * u1 + f2 * u2 ; } } return ( yout ) ; }
#ifndef __RTW_UTFREE__  
extern void utFree ( void * ) ;
#endif
void rt_TDelayFreeBuf ( void * buf ) { utFree ( buf ) ; } void MdlInitialize
( void ) { rtX . c0wv2q33w2 [ 0 ] = rtP . StateSpace_InitialCondition ; rtX .
j1xq4yvlx2 [ 0 ] = rtP . StateSpace1_InitialCondition ; rtX . c0wv2q33w2 [ 1
] = rtP . StateSpace_InitialCondition ; rtX . j1xq4yvlx2 [ 1 ] = rtP .
StateSpace1_InitialCondition ; rtX . clfp10tphj = rtP .
StateSpace4_InitialCondition ; rtX . kjndn5kljk [ 0 ] = rtP .
StateSpace5_InitialCondition ; rtX . kjndn5kljk [ 1 ] = rtP .
StateSpace5_InitialCondition ; if ( ssIsFirstInitCond ( rtS ) ) { rtX .
lw2jyyhpz2 [ 0 ] = 0.0 ; rtX . lw2jyyhpz2 [ 1 ] = 0.0 ; } rtDW . aks53l4lnr =
1 ; rtDW . dzkln1ywkn = rtP . RTrans4_InitialCondition ; rtDW . cilee0gxli =
rtP . RTrans3_InitialCondition ; rtDW . omsjx15qkl = rtP .
RTrans2_InitialCondition ; rtDW . o0kw0astte = rtP . RTrans1_InitialCondition
; rtX . iautxvq3ek = rtP . StateSpace2_InitialCondition ; rtX . ltpfrlwiir =
rtP . StateSpace3_InitialCondition ; } void MdlStart ( void ) { { void * *
slioCatalogueAddr = rt_slioCatalogueAddr ( ) ; void * r2 = ( NULL ) ; void *
* pOSigstreamManagerAddr = ( NULL ) ; const char *
errorCreatingOSigstreamManager = ( NULL ) ; const char *
errorAddingR2SharedResource = ( NULL ) ; * slioCatalogueAddr =
rtwGetNewSlioCatalogue ( rt_GetMatSigLogSelectorFileName ( ) ) ;
errorAddingR2SharedResource = rtwAddR2SharedResource (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) , 1 ) ; if (
errorAddingR2SharedResource != ( NULL ) ) { rtwTerminateSlioCatalogue (
slioCatalogueAddr ) ; * slioCatalogueAddr = ( NULL ) ; ssSetErrorStatus ( rtS
, errorAddingR2SharedResource ) ; return ; } r2 = rtwGetR2SharedResource (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) ) ;
pOSigstreamManagerAddr = rt_GetOSigstreamManagerAddr ( ) ;
errorCreatingOSigstreamManager = rtwOSigstreamManagerCreateInstance (
rt_GetMatSigLogSelectorFileName ( ) , r2 , pOSigstreamManagerAddr ) ; if (
errorCreatingOSigstreamManager != ( NULL ) ) { * pOSigstreamManagerAddr = (
NULL ) ; ssSetErrorStatus ( rtS , errorCreatingOSigstreamManager ) ; return ;
} } rtB . f5dnmxffg4 [ 0 ] = rtP . Constant1_Value [ 0 ] ; rtB . f5dnmxffg4 [
1 ] = rtP . Constant1_Value [ 1 ] ; rtB . ct0lfakgvx = rtP .
RTrans4_InitialCondition ; rtB . mqxjcbkpjz = rtP . RTrans3_InitialCondition
; rtB . ny5cfobxq4 = rtP . RTrans2_InitialCondition ; rtB . d04rtlng0c = rtP
. RTrans1_InitialCondition ; { int_T j ; { real_T * pBuffer = ( real_T * )
rt_TDelayCreateBuf ( 2 , 4096 , sizeof ( real_T ) ) ; if ( pBuffer == ( NULL
) ) { ssSetErrorStatus ( rtS , "vtdelay memory allocation error" ) ; return ;
} rtDW . phswmmvrn3 . Tail [ 0 ] = 0 ; rtDW . phswmmvrn3 . Head [ 0 ] = 0 ;
rtDW . phswmmvrn3 . Last [ 0 ] = 0 ; rtDW . phswmmvrn3 . CircularBufSize [ 0
] = 4096 ; for ( j = 0 ; j < 4096 ; j ++ ) { pBuffer [ j ] = ( rtP .
totalcommunicationtimedelay_InitOutput [ 0 ] ) ; pBuffer [ 4096 + j ] =
ssGetT ( rtS ) ; } rtDW . ncnf0zgwn3 . TUbufferPtrs [ 0 ] = ( void * ) &
pBuffer [ 0 ] ; rtDW . ncnf0zgwn3 . TUbufferPtrs [ 4 ] = ( void * ) & pBuffer
[ 4096 ] ; } { real_T * pBuffer = ( real_T * ) rt_TDelayCreateBuf ( 2 , 4096
, sizeof ( real_T ) ) ; if ( pBuffer == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"vtdelay memory allocation error" ) ; return ; } rtDW . phswmmvrn3 . Tail [ 1
] = 0 ; rtDW . phswmmvrn3 . Head [ 1 ] = 0 ; rtDW . phswmmvrn3 . Last [ 1 ] =
0 ; rtDW . phswmmvrn3 . CircularBufSize [ 1 ] = 4096 ; for ( j = 0 ; j < 4096
; j ++ ) { pBuffer [ j ] = ( rtP . totalcommunicationtimedelay_InitOutput [ 1
] ) ; pBuffer [ 4096 + j ] = ssGetT ( rtS ) ; } rtDW . ncnf0zgwn3 .
TUbufferPtrs [ 1 ] = ( void * ) & pBuffer [ 0 ] ; rtDW . ncnf0zgwn3 .
TUbufferPtrs [ 5 ] = ( void * ) & pBuffer [ 4096 ] ; } { real_T * pBuffer = (
real_T * ) rt_TDelayCreateBuf ( 2 , 4096 , sizeof ( real_T ) ) ; if ( pBuffer
== ( NULL ) ) { ssSetErrorStatus ( rtS , "vtdelay memory allocation error" )
; return ; } rtDW . phswmmvrn3 . Tail [ 2 ] = 0 ; rtDW . phswmmvrn3 . Head [
2 ] = 0 ; rtDW . phswmmvrn3 . Last [ 2 ] = 0 ; rtDW . phswmmvrn3 .
CircularBufSize [ 2 ] = 4096 ; for ( j = 0 ; j < 4096 ; j ++ ) { pBuffer [ j
] = ( rtP . totalcommunicationtimedelay_InitOutput [ 2 ] ) ; pBuffer [ 4096 +
j ] = ssGetT ( rtS ) ; } rtDW . ncnf0zgwn3 . TUbufferPtrs [ 2 ] = ( void * )
& pBuffer [ 0 ] ; rtDW . ncnf0zgwn3 . TUbufferPtrs [ 6 ] = ( void * ) &
pBuffer [ 4096 ] ; } { real_T * pBuffer = ( real_T * ) rt_TDelayCreateBuf ( 2
, 4096 , sizeof ( real_T ) ) ; if ( pBuffer == ( NULL ) ) { ssSetErrorStatus
( rtS , "vtdelay memory allocation error" ) ; return ; } rtDW . phswmmvrn3 .
Tail [ 3 ] = 0 ; rtDW . phswmmvrn3 . Head [ 3 ] = 0 ; rtDW . phswmmvrn3 .
Last [ 3 ] = 0 ; rtDW . phswmmvrn3 . CircularBufSize [ 3 ] = 4096 ; for ( j =
0 ; j < 4096 ; j ++ ) { pBuffer [ j ] = ( rtP .
totalcommunicationtimedelay_InitOutput [ 3 ] ) ; pBuffer [ 4096 + j ] =
ssGetT ( rtS ) ; } rtDW . ncnf0zgwn3 . TUbufferPtrs [ 3 ] = ( void * ) &
pBuffer [ 0 ] ; rtDW . ncnf0zgwn3 . TUbufferPtrs [ 7 ] = ( void * ) & pBuffer
[ 4096 ] ; } } MdlInitialize ( ) ; { bool externalInputIsInDatasetFormat =
false ; void * pISigstreamManager = rt_GetISigstreamManager ( ) ;
rtwISigstreamManagerGetInputIsInDatasetFormat ( pISigstreamManager , &
externalInputIsInDatasetFormat ) ; if ( externalInputIsInDatasetFormat ) { }
} } void MdlOutputs ( int_T tid ) { boolean_T rEQ0 ; real_T q ; real_T
fvwn1zkclo ; real_T plktxbzzse ; real_T drd2hzurdg_idx_0 ; real_T
drd2hzurdg_idx_1 ; real_T ltsn4s1rxr_idx_1 ; if ( ssIsContinuousTask ( rtS ,
tid ) ) { rtB . cofx0wimtn = 0.0 ; rtB . cofx0wimtn += rtP . StateSpace_C [ 0
] * rtX . c0wv2q33w2 [ 0 ] ; rtB . cofx0wimtn += rtP . StateSpace_C [ 1 ] *
rtX . c0wv2q33w2 [ 1 ] ; rtB . afymbnqbja = rtP . deg2rad1_Gain * rtB .
cofx0wimtn ; rtB . hwfrmz5f3r = 0.0 ; rtB . hwfrmz5f3r += rtP . StateSpace1_C
[ 0 ] * rtX . j1xq4yvlx2 [ 0 ] ; rtB . hwfrmz5f3r += rtP . StateSpace1_C [ 1
] * rtX . j1xq4yvlx2 [ 1 ] ; rtB . e0dwz0nd0f = rtP . deg2rad_Gain * rtB .
hwfrmz5f3r ; plktxbzzse = rtP . StateSpace4_C * rtX . clfp10tphj ; if ( ( !
muDoubleScalarIsInf ( plktxbzzse ) ) && ( ! muDoubleScalarIsNaN ( plktxbzzse
) ) ) { if ( plktxbzzse == 0.0 ) { fvwn1zkclo = 0.0 ; } else { fvwn1zkclo =
muDoubleScalarRem ( plktxbzzse , 6.2831853071795862 ) ; rEQ0 = ( fvwn1zkclo
== 0.0 ) ; if ( ! rEQ0 ) { q = muDoubleScalarAbs ( plktxbzzse /
6.2831853071795862 ) ; rEQ0 = ( muDoubleScalarAbs ( q - muDoubleScalarFloor (
q + 0.5 ) ) <= 2.2204460492503131E-16 * q ) ; } if ( rEQ0 ) { fvwn1zkclo =
0.0 ; } else { if ( plktxbzzse < 0.0 ) { fvwn1zkclo += 6.2831853071795862 ; }
} } } else { fvwn1zkclo = ( rtNaN ) ; } if ( fvwn1zkclo > 3.1415926535897931
) { fvwn1zkclo += - 6.2831853071795862 ; } rtB . k2pexa1jcv = rtP .
deg2rad2_Gain * fvwn1zkclo ; } if ( ssIsSampleHit ( rtS , 1 , tid ) ) { } if
( ssIsContinuousTask ( rtS , tid ) ) { rtB . grcjjbltf4 = 0.0 ; rtB .
grcjjbltf4 += rtP . StateSpace5_C [ 0 ] * rtX . kjndn5kljk [ 0 ] ; rtB .
grcjjbltf4 += rtP . StateSpace5_C [ 1 ] * rtX . kjndn5kljk [ 1 ] ; } if (
ssIsSampleHit ( rtS , 1 , tid ) ) { } if ( ssIsContinuousTask ( rtS , tid ) )
{ if ( rtDW . aks53l4lnr != 0 ) { rtX . lw2jyyhpz2 [ 0 ] = rtB . f5dnmxffg4 [
0 ] ; rtX . lw2jyyhpz2 [ 1 ] = rtB . f5dnmxffg4 [ 1 ] ; } rtB . kqhgmm5uqn [
0 ] = rtX . lw2jyyhpz2 [ 0 ] ; rtB . kqhgmm5uqn [ 1 ] = rtX . lw2jyyhpz2 [ 1
] ; } if ( ssIsSampleHit ( rtS , 1 , tid ) ) { } if ( ssIsContinuousTask (
rtS , tid ) ) { rtB . lj3rhp5vml [ 0 ] = rtP . deg2rad_Gain_ac0spr3vlb * rtB
. afymbnqbja ; rtB . lj3rhp5vml [ 1 ] = rtP . deg2rad_Gain_ac0spr3vlb * rtB .
e0dwz0nd0f ; rtB . lj3rhp5vml [ 2 ] = rtP . deg2rad_Gain_ac0spr3vlb * rtB .
k2pexa1jcv ; rtB . lheu1wj2gf = rtP . deg2rad1_Gain_nt4gyxjmbp * rtB .
lj3rhp5vml [ 2 ] ; } if ( ssIsSampleHit ( rtS , 1 , tid ) ) { if (
ssIsSpecialSampleHit ( rtS , 2 , 1 , tid ) ) { rtB . ct0lfakgvx = rtDW .
dzkln1ywkn ; rtB . mqxjcbkpjz = rtDW . cilee0gxli ; } if ( rtB . ct0lfakgvx >
rtP . Saturation1_UpperSat ) { rtB . lo0eaoyvmd = rtP . Saturation1_UpperSat
; } else if ( rtB . ct0lfakgvx < rtP . Saturation1_LowerSat ) { rtB .
lo0eaoyvmd = rtP . Saturation1_LowerSat ; } else { rtB . lo0eaoyvmd = rtB .
ct0lfakgvx ; } if ( rtB . mqxjcbkpjz > rtP . Saturation2_UpperSat ) { rtB .
j3kljood4v = rtP . Saturation2_UpperSat ; } else if ( rtB . mqxjcbkpjz < rtP
. Saturation2_LowerSat ) { rtB . j3kljood4v = rtP . Saturation2_LowerSat ; }
else { rtB . j3kljood4v = rtB . mqxjcbkpjz ; } if ( ssIsSpecialSampleHit (
rtS , 2 , 1 , tid ) ) { rtB . ny5cfobxq4 = rtDW . omsjx15qkl ; rtB .
d04rtlng0c = rtDW . o0kw0astte ; } if ( rtB . ny5cfobxq4 > rtP .
Saturation3_UpperSat ) { rtB . cllqdyv02v = rtP . Saturation3_UpperSat ; }
else if ( rtB . ny5cfobxq4 < rtP . Saturation3_LowerSat ) { rtB . cllqdyv02v
= rtP . Saturation3_LowerSat ; } else { rtB . cllqdyv02v = rtB . ny5cfobxq4 ;
} if ( rtB . d04rtlng0c > rtP . Saturation4_UpperSat ) { rtB . mhwrae3jwj =
rtP . Saturation4_UpperSat ; } else if ( rtB . d04rtlng0c < rtP .
Saturation4_LowerSat ) { rtB . mhwrae3jwj = rtP . Saturation4_LowerSat ; }
else { rtB . mhwrae3jwj = rtB . d04rtlng0c ; } } if ( ssIsContinuousTask (
rtS , tid ) ) { rtB . oz1y4s2hbk = 0.0 ; rtB . oz1y4s2hbk += rtP .
StateSpace2_C * rtX . iautxvq3ek ; rtB . edlokp5332 = 0.0 ; rtB . edlokp5332
+= rtP . StateSpace3_C * rtX . ltpfrlwiir ; { real_T * * uBuffer = ( real_T *
* ) & rtDW . ncnf0zgwn3 . TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T
* * ) & rtDW . ncnf0zgwn3 . TUbufferPtrs [ 4 ] ; real_T simTime = ssGetT (
rtS ) ; real_T appliedDelay ; appliedDelay = rtP . timeDelay ; if (
appliedDelay > rtP . totalcommunicationtimedelay_MaxDelay ) { appliedDelay =
rtP . totalcommunicationtimedelay_MaxDelay ; } if ( appliedDelay < 0.0 ) {
appliedDelay = 0.0 ; } rtB . m32nvwcf2p [ 0 ] = rt_TDelayInterpolate (
simTime - appliedDelay , 0.0 , * tBuffer , * uBuffer , rtDW . phswmmvrn3 .
CircularBufSize [ 0 ] , & rtDW . phswmmvrn3 . Last [ 0 ] , rtDW . phswmmvrn3
. Tail [ 0 ] , rtDW . phswmmvrn3 . Head [ 0 ] , ( rtP .
totalcommunicationtimedelay_InitOutput [ 0 ] ) , 1 , ( boolean_T ) (
ssIsMinorTimeStep ( rtS ) && ( ssGetTimeOfLastOutput ( rtS ) == ssGetT ( rtS
) ) ) ) ; tBuffer ++ ; uBuffer ++ ; appliedDelay = rtP . timeDelay ; if (
appliedDelay > rtP . totalcommunicationtimedelay_MaxDelay ) { appliedDelay =
rtP . totalcommunicationtimedelay_MaxDelay ; } if ( appliedDelay < 0.0 ) {
appliedDelay = 0.0 ; } rtB . m32nvwcf2p [ 1 ] = rt_TDelayInterpolate (
simTime - appliedDelay , 0.0 , * tBuffer , * uBuffer , rtDW . phswmmvrn3 .
CircularBufSize [ 1 ] , & rtDW . phswmmvrn3 . Last [ 1 ] , rtDW . phswmmvrn3
. Tail [ 1 ] , rtDW . phswmmvrn3 . Head [ 1 ] , ( rtP .
totalcommunicationtimedelay_InitOutput [ 1 ] ) , 1 , ( boolean_T ) (
ssIsMinorTimeStep ( rtS ) && ( ssGetTimeOfLastOutput ( rtS ) == ssGetT ( rtS
) ) ) ) ; tBuffer ++ ; uBuffer ++ ; appliedDelay = rtP . timeDelay ; if (
appliedDelay > rtP . totalcommunicationtimedelay_MaxDelay ) { appliedDelay =
rtP . totalcommunicationtimedelay_MaxDelay ; } if ( appliedDelay < 0.0 ) {
appliedDelay = 0.0 ; } rtB . m32nvwcf2p [ 2 ] = rt_TDelayInterpolate (
simTime - appliedDelay , 0.0 , * tBuffer , * uBuffer , rtDW . phswmmvrn3 .
CircularBufSize [ 2 ] , & rtDW . phswmmvrn3 . Last [ 2 ] , rtDW . phswmmvrn3
. Tail [ 2 ] , rtDW . phswmmvrn3 . Head [ 2 ] , ( rtP .
totalcommunicationtimedelay_InitOutput [ 2 ] ) , 1 , ( boolean_T ) (
ssIsMinorTimeStep ( rtS ) && ( ssGetTimeOfLastOutput ( rtS ) == ssGetT ( rtS
) ) ) ) ; tBuffer ++ ; uBuffer ++ ; appliedDelay = rtP . timeDelay ; if (
appliedDelay > rtP . totalcommunicationtimedelay_MaxDelay ) { appliedDelay =
rtP . totalcommunicationtimedelay_MaxDelay ; } if ( appliedDelay < 0.0 ) {
appliedDelay = 0.0 ; } rtB . m32nvwcf2p [ 3 ] = rt_TDelayInterpolate (
simTime - appliedDelay , 0.0 , * tBuffer , * uBuffer , rtDW . phswmmvrn3 .
CircularBufSize [ 3 ] , & rtDW . phswmmvrn3 . Last [ 3 ] , rtDW . phswmmvrn3
. Tail [ 3 ] , rtDW . phswmmvrn3 . Head [ 3 ] , ( rtP .
totalcommunicationtimedelay_InitOutput [ 3 ] ) , 1 , ( boolean_T ) (
ssIsMinorTimeStep ( rtS ) && ( ssGetTimeOfLastOutput ( rtS ) == ssGetT ( rtS
) ) ) ) ; } } if ( ssIsSampleHit ( rtS , 1 , tid ) ) { if (
ssIsSpecialSampleHit ( rtS , 2 , 1 , tid ) ) { rtB . kwpff2ydjd = rtB .
edlokp5332 ; rtB . le5u5iq05u = rtB . kqhgmm5uqn [ 0 ] ; rtB . lcppzkdajf =
rtB . kqhgmm5uqn [ 1 ] ; } if ( ssIsSpecialSampleHit ( rtS , 2 , 1 , tid ) )
{ rtB . mtdunn0hxq = rtB . lj3rhp5vml [ 2 ] ; } } if ( ssIsSampleHit ( rtS ,
2 , tid ) ) { drd2hzurdg_idx_0 = rtP . InertialXrefm_Value - rtB . le5u5iq05u
; drd2hzurdg_idx_1 = rtP . InertialYrefm_Value - rtB . lcppzkdajf ; } if (
ssIsSampleHit ( rtS , 1 , tid ) && ssIsSpecialSampleHit ( rtS , 2 , 1 , tid )
) { rtB . ky1idomaqy = rtB . grcjjbltf4 ; } if ( ssIsSampleHit ( rtS , 2 ,
tid ) ) { ltsn4s1rxr_idx_1 = - muDoubleScalarSin ( rtB . mtdunn0hxq ) *
drd2hzurdg_idx_0 + muDoubleScalarCos ( rtB . mtdunn0hxq ) * drd2hzurdg_idx_1
; rtB . ic5el12kf2 = ( ( muDoubleScalarCos ( rtB . mtdunn0hxq ) *
drd2hzurdg_idx_0 + muDoubleScalarSin ( rtB . mtdunn0hxq ) * drd2hzurdg_idx_1
) * rtP . Gain2_Gain - rtB . kwpff2ydjd ) * rtP . Gain_Gain ; rtB .
karkyytmd2 = ( rtP . Headingrefrad_Value - rtB . mtdunn0hxq ) * rtP .
proportionalcontrolgainyaw_Gain ; } if ( ssIsSampleHit ( rtS , 1 , tid ) &&
ssIsSpecialSampleHit ( rtS , 2 , 1 , tid ) ) { rtB . ayqkbl03wb = rtB .
oz1y4s2hbk ; } if ( ssIsSampleHit ( rtS , 2 , tid ) ) { rtB . mq1at2ouk5 = (
rtP . Heightrefm_Value - rtB . ky1idomaqy ) * rtP .
proportionalcontrolgain_Gain ; rtB . mrnorbqaqm = ( rtP . Gain3_Gain *
ltsn4s1rxr_idx_1 - rtB . ayqkbl03wb ) * rtP . Gain1_Gain ; } if (
ssIsContinuousTask ( rtS , tid ) ) { rtB . gb1cjjlaov [ 0 ] = 0.0 ; rtB .
gb1cjjlaov [ 0 ] += muDoubleScalarCos ( rtB . lj3rhp5vml [ 2 ] ) * rtB .
edlokp5332 ; rtB . gb1cjjlaov [ 0 ] += - muDoubleScalarSin ( rtB . lj3rhp5vml
[ 2 ] ) * rtB . oz1y4s2hbk ; rtB . gb1cjjlaov [ 1 ] = 0.0 ; rtB . gb1cjjlaov
[ 1 ] += muDoubleScalarSin ( rtB . lj3rhp5vml [ 2 ] ) * rtB . edlokp5332 ;
rtB . gb1cjjlaov [ 1 ] += muDoubleScalarCos ( rtB . lj3rhp5vml [ 2 ] ) * rtB
. oz1y4s2hbk ; } UNUSED_PARAMETER ( tid ) ; } void MdlOutputsTID3 ( int_T tid
) { rtB . hbl52k43sz = rtP . Constant_Value ; rtB . f5dnmxffg4 [ 0 ] = rtP .
Constant1_Value [ 0 ] ; rtB . f5dnmxffg4 [ 1 ] = rtP . Constant1_Value [ 1 ]
; UNUSED_PARAMETER ( tid ) ; } void MdlUpdate ( int_T tid ) { if (
ssIsContinuousTask ( rtS , tid ) ) { rtDW . aks53l4lnr = 0 ; } if (
ssIsSampleHit ( rtS , 2 , tid ) ) { rtDW . dzkln1ywkn = rtB . mrnorbqaqm ;
rtDW . cilee0gxli = rtB . ic5el12kf2 ; rtDW . omsjx15qkl = rtB . karkyytmd2 ;
rtDW . o0kw0astte = rtB . mq1at2ouk5 ; } if ( ssIsContinuousTask ( rtS , tid
) ) { { real_T * * uBuffer = ( real_T * * ) & rtDW . ncnf0zgwn3 .
TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T * * ) & rtDW . ncnf0zgwn3
. TUbufferPtrs [ 4 ] ; real_T * * xBuffer = ( NULL ) ; real_T simTime =
ssGetT ( rtS ) ; rtDW . phswmmvrn3 . Head [ 0 ] = ( ( rtDW . phswmmvrn3 .
Head [ 0 ] < ( rtDW . phswmmvrn3 . CircularBufSize [ 0 ] - 1 ) ) ? ( rtDW .
phswmmvrn3 . Head [ 0 ] + 1 ) : 0 ) ; if ( rtDW . phswmmvrn3 . Head [ 0 ] ==
rtDW . phswmmvrn3 . Tail [ 0 ] ) { if ( ! rt_TDelayUpdateTailOrGrowBuf ( &
rtDW . phswmmvrn3 . CircularBufSize [ 0 ] , & rtDW . phswmmvrn3 . Tail [ 0 ]
, & rtDW . phswmmvrn3 . Head [ 0 ] , & rtDW . phswmmvrn3 . Last [ 0 ] ,
simTime - rtP . totalcommunicationtimedelay_MaxDelay , tBuffer , uBuffer ,
xBuffer , ( boolean_T ) 0 , ( boolean_T ) 0 , & rtDW . phswmmvrn3 .
MaxNewBufSize ) ) { ssSetErrorStatus ( rtS ,
"vtdelay memory allocation error" ) ; return ; } } ( * tBuffer ++ ) [ rtDW .
phswmmvrn3 . Head [ 0 ] ] = simTime ; ( * uBuffer ++ ) [ rtDW . phswmmvrn3 .
Head [ 0 ] ] = rtB . lo0eaoyvmd ; rtDW . phswmmvrn3 . Head [ 1 ] = ( ( rtDW .
phswmmvrn3 . Head [ 1 ] < ( rtDW . phswmmvrn3 . CircularBufSize [ 1 ] - 1 ) )
? ( rtDW . phswmmvrn3 . Head [ 1 ] + 1 ) : 0 ) ; if ( rtDW . phswmmvrn3 .
Head [ 1 ] == rtDW . phswmmvrn3 . Tail [ 1 ] ) { if ( !
rt_TDelayUpdateTailOrGrowBuf ( & rtDW . phswmmvrn3 . CircularBufSize [ 1 ] ,
& rtDW . phswmmvrn3 . Tail [ 1 ] , & rtDW . phswmmvrn3 . Head [ 1 ] , & rtDW
. phswmmvrn3 . Last [ 1 ] , simTime - rtP .
totalcommunicationtimedelay_MaxDelay , tBuffer , uBuffer , xBuffer , (
boolean_T ) 0 , ( boolean_T ) 0 , & rtDW . phswmmvrn3 . MaxNewBufSize ) ) {
ssSetErrorStatus ( rtS , "vtdelay memory allocation error" ) ; return ; } } (
* tBuffer ++ ) [ rtDW . phswmmvrn3 . Head [ 1 ] ] = simTime ; ( * uBuffer ++
) [ rtDW . phswmmvrn3 . Head [ 1 ] ] = rtB . j3kljood4v ; rtDW . phswmmvrn3 .
Head [ 2 ] = ( ( rtDW . phswmmvrn3 . Head [ 2 ] < ( rtDW . phswmmvrn3 .
CircularBufSize [ 2 ] - 1 ) ) ? ( rtDW . phswmmvrn3 . Head [ 2 ] + 1 ) : 0 )
; if ( rtDW . phswmmvrn3 . Head [ 2 ] == rtDW . phswmmvrn3 . Tail [ 2 ] ) {
if ( ! rt_TDelayUpdateTailOrGrowBuf ( & rtDW . phswmmvrn3 . CircularBufSize [
2 ] , & rtDW . phswmmvrn3 . Tail [ 2 ] , & rtDW . phswmmvrn3 . Head [ 2 ] , &
rtDW . phswmmvrn3 . Last [ 2 ] , simTime - rtP .
totalcommunicationtimedelay_MaxDelay , tBuffer , uBuffer , xBuffer , (
boolean_T ) 0 , ( boolean_T ) 0 , & rtDW . phswmmvrn3 . MaxNewBufSize ) ) {
ssSetErrorStatus ( rtS , "vtdelay memory allocation error" ) ; return ; } } (
* tBuffer ++ ) [ rtDW . phswmmvrn3 . Head [ 2 ] ] = simTime ; ( * uBuffer ++
) [ rtDW . phswmmvrn3 . Head [ 2 ] ] = rtB . cllqdyv02v ; rtDW . phswmmvrn3 .
Head [ 3 ] = ( ( rtDW . phswmmvrn3 . Head [ 3 ] < ( rtDW . phswmmvrn3 .
CircularBufSize [ 3 ] - 1 ) ) ? ( rtDW . phswmmvrn3 . Head [ 3 ] + 1 ) : 0 )
; if ( rtDW . phswmmvrn3 . Head [ 3 ] == rtDW . phswmmvrn3 . Tail [ 3 ] ) {
if ( ! rt_TDelayUpdateTailOrGrowBuf ( & rtDW . phswmmvrn3 . CircularBufSize [
3 ] , & rtDW . phswmmvrn3 . Tail [ 3 ] , & rtDW . phswmmvrn3 . Head [ 3 ] , &
rtDW . phswmmvrn3 . Last [ 3 ] , simTime - rtP .
totalcommunicationtimedelay_MaxDelay , tBuffer , uBuffer , xBuffer , (
boolean_T ) 0 , ( boolean_T ) 0 , & rtDW . phswmmvrn3 . MaxNewBufSize ) ) {
ssSetErrorStatus ( rtS , "vtdelay memory allocation error" ) ; return ; } } (
* tBuffer ) [ rtDW . phswmmvrn3 . Head [ 3 ] ] = simTime ; ( * uBuffer ) [
rtDW . phswmmvrn3 . Head [ 3 ] ] = rtB . mhwrae3jwj ; } } UNUSED_PARAMETER (
tid ) ; } void MdlUpdateTID3 ( int_T tid ) { UNUSED_PARAMETER ( tid ) ; }
void MdlDerivatives ( void ) { XDot * _rtXdot ; _rtXdot = ( ( XDot * )
ssGetdX ( rtS ) ) ; _rtXdot -> c0wv2q33w2 [ 0 ] = 0.0 ; _rtXdot -> j1xq4yvlx2
[ 0 ] = 0.0 ; _rtXdot -> c0wv2q33w2 [ 1 ] = 0.0 ; _rtXdot -> j1xq4yvlx2 [ 1 ]
= 0.0 ; _rtXdot -> c0wv2q33w2 [ 0 ] += rtP . StateSpace_A [ 0 ] * rtX .
c0wv2q33w2 [ 0 ] ; _rtXdot -> c0wv2q33w2 [ 0 ] += rtP . StateSpace_A [ 1 ] *
rtX . c0wv2q33w2 [ 1 ] ; _rtXdot -> c0wv2q33w2 [ 1 ] += rtP . StateSpace_A [
2 ] * rtX . c0wv2q33w2 [ 0 ] ; _rtXdot -> c0wv2q33w2 [ 0 ] += rtP .
StateSpace_B * rtB . m32nvwcf2p [ 0 ] ; _rtXdot -> j1xq4yvlx2 [ 0 ] += rtP .
StateSpace1_A [ 0 ] * rtX . j1xq4yvlx2 [ 0 ] ; _rtXdot -> j1xq4yvlx2 [ 0 ] +=
rtP . StateSpace1_A [ 1 ] * rtX . j1xq4yvlx2 [ 1 ] ; _rtXdot -> j1xq4yvlx2 [
1 ] += rtP . StateSpace1_A [ 2 ] * rtX . j1xq4yvlx2 [ 0 ] ; _rtXdot ->
j1xq4yvlx2 [ 0 ] += rtP . StateSpace1_B * rtB . m32nvwcf2p [ 1 ] ; _rtXdot ->
clfp10tphj = 0.0 ; _rtXdot -> clfp10tphj += rtP . StateSpace4_A * rtX .
clfp10tphj ; _rtXdot -> clfp10tphj += rtP . StateSpace4_B * rtB . m32nvwcf2p
[ 2 ] ; _rtXdot -> kjndn5kljk [ 0 ] = 0.0 ; _rtXdot -> lw2jyyhpz2 [ 0 ] = rtB
. gb1cjjlaov [ 0 ] ; _rtXdot -> kjndn5kljk [ 1 ] = 0.0 ; _rtXdot ->
lw2jyyhpz2 [ 1 ] = rtB . gb1cjjlaov [ 1 ] ; _rtXdot -> kjndn5kljk [ 0 ] +=
rtP . StateSpace5_A [ 0 ] * rtX . kjndn5kljk [ 0 ] ; _rtXdot -> kjndn5kljk [
0 ] += rtP . StateSpace5_A [ 1 ] * rtX . kjndn5kljk [ 1 ] ; _rtXdot ->
kjndn5kljk [ 1 ] += rtP . StateSpace5_A [ 2 ] * rtX . kjndn5kljk [ 0 ] ;
_rtXdot -> kjndn5kljk [ 0 ] += rtP . StateSpace5_B * rtB . m32nvwcf2p [ 3 ] ;
_rtXdot -> iautxvq3ek = 0.0 ; _rtXdot -> iautxvq3ek += rtP . StateSpace2_A *
rtX . iautxvq3ek ; _rtXdot -> iautxvq3ek += rtP . StateSpace2_B * rtB .
cofx0wimtn ; _rtXdot -> ltpfrlwiir = 0.0 ; _rtXdot -> ltpfrlwiir += rtP .
StateSpace3_A * rtX . ltpfrlwiir ; _rtXdot -> ltpfrlwiir += rtP .
StateSpace3_B * rtB . hwfrmz5f3r ; { } } void MdlProjection ( void ) { } void
MdlTerminate ( void ) { rt_TDelayFreeBuf ( rtDW . ncnf0zgwn3 . TUbufferPtrs [
0 ] ) ; rt_TDelayFreeBuf ( rtDW . ncnf0zgwn3 . TUbufferPtrs [ 1 ] ) ;
rt_TDelayFreeBuf ( rtDW . ncnf0zgwn3 . TUbufferPtrs [ 2 ] ) ;
rt_TDelayFreeBuf ( rtDW . ncnf0zgwn3 . TUbufferPtrs [ 3 ] ) ; if (
rt_slioCatalogue ( ) != ( NULL ) ) { void * * slioCatalogueAddr =
rt_slioCatalogueAddr ( ) ; rtwSaveDatasetsToMatFile (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) ,
rt_GetMatSigstreamLoggingFileName ( ) ) ; rtwTerminateSlioCatalogue (
slioCatalogueAddr ) ; * slioCatalogueAddr = NULL ; } } void
MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS , 11 ) ;
ssSetNumPeriodicContStates ( rtS , 0 ) ; ssSetNumY ( rtS , 0 ) ; ssSetNumU (
rtS , 0 ) ; ssSetDirectFeedThrough ( rtS , 0 ) ; ssSetNumSampleTimes ( rtS ,
3 ) ; ssSetNumBlocks ( rtS , 57 ) ; ssSetNumBlockIO ( rtS , 33 ) ;
ssSetNumBlockParams ( rtS , 69 ) ; } void MdlInitializeSampleTimes ( void ) {
ssSetSampleTime ( rtS , 0 , 0.0 ) ; ssSetSampleTime ( rtS , 1 , 0.005 ) ;
ssSetSampleTime ( rtS , 2 , 0.065 ) ; ssSetOffsetTime ( rtS , 0 , 0.0 ) ;
ssSetOffsetTime ( rtS , 1 , 0.0 ) ; ssSetOffsetTime ( rtS , 2 , 0.0 ) ; }
void raccel_set_checksum ( ) { ssSetChecksumVal ( rtS , 0 , 1862538803U ) ;
ssSetChecksumVal ( rtS , 1 , 1285932175U ) ; ssSetChecksumVal ( rtS , 2 ,
1195978743U ) ; ssSetChecksumVal ( rtS , 3 , 2431553248U ) ; }
#if defined(_MSC_VER)
#pragma optimize( "", off )
#endif
SimStruct * raccel_register_model ( void ) { static struct _ssMdlInfo mdlInfo
; ( void ) memset ( ( char * ) rtS , 0 , sizeof ( SimStruct ) ) ; ( void )
memset ( ( char * ) & mdlInfo , 0 , sizeof ( struct _ssMdlInfo ) ) ;
ssSetMdlInfoPtr ( rtS , & mdlInfo ) ; { static time_T mdlPeriod [
NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ; static time_T
mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [ NSAMPLE_TIMES ] ;
static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static boolean_T
mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T mdlPerTaskSampleHits
[ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T mdlTimeOfNextSampleHit [
NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i < NSAMPLE_TIMES ; i ++ ) {
mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ; mdlTaskTimes [ i ] = 0.0 ;
mdlTsMap [ i ] = i ; } } mdlSampleHits [ 0 ] = 1 ; ssSetSampleTimePtr ( rtS ,
& mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , & mdlOffset [ 0 ] ) ;
ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ; ssSetTPtr ( rtS , &
mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , & mdlSampleHits [ 0 ] ) ;
ssSetTNextWasAdjustedPtr ( rtS , & mdlTNextWasAdjustedPtr [ 0 ] ) ;
ssSetPerTaskSampleHitsPtr ( rtS , & mdlPerTaskSampleHits [ 0 ] ) ;
ssSetTimeOfNextSampleHitPtr ( rtS , & mdlTimeOfNextSampleHit [ 0 ] ) ; } {
static int_T mdlPerTaskSampleHits [ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; ( void
) memset ( ( void * ) & mdlPerTaskSampleHits [ 0 ] , 0 , 3 * 3 * sizeof (
int_T ) ) ; ssSetPerTaskSampleHitsPtr ( rtS , & mdlPerTaskSampleHits [ 0 ] )
; } ssSetSolverMode ( rtS , SOLVER_MODE_MULTITASKING ) ; { ssSetBlockIO ( rtS
, ( ( void * ) & rtB ) ) ; ( void ) memset ( ( ( void * ) & rtB ) , 0 ,
sizeof ( B ) ) ; } ssSetDefaultParam ( rtS , ( real_T * ) & rtP ) ; { real_T
* x = ( real_T * ) & rtX ; ssSetContStates ( rtS , x ) ; ( void ) memset ( (
void * ) x , 0 , sizeof ( X ) ) ; } { void * dwork = ( void * ) & rtDW ;
ssSetRootDWork ( rtS , dwork ) ; ( void ) memset ( dwork , 0 , sizeof ( DW )
) ; } { static DataTypeTransInfo dtInfo ; ( void ) memset ( ( char_T * ) &
dtInfo , 0 , sizeof ( dtInfo ) ) ; ssSetModelMappingInfo ( rtS , & dtInfo ) ;
dtInfo . numDataTypes = 15 ; dtInfo . dataTypeSizes = & rtDataTypeSizes [ 0 ]
; dtInfo . dataTypeNames = & rtDataTypeNames [ 0 ] ; dtInfo . BTransTable = &
rtBTransTable ; dtInfo . PTransTable = & rtPTransTable ; }
ARDroneHoverSim_InitializeDataMapInfo ( ) ; ssSetIsRapidAcceleratorActive (
rtS , true ) ; ssSetRootSS ( rtS , rtS ) ; ssSetVersion ( rtS ,
SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS , "ARDroneHoverSim" ) ;
ssSetPath ( rtS , "ARDroneHoverSim" ) ; ssSetTStart ( rtS , 0.0 ) ;
ssSetTFinal ( rtS , 100.0 ) ; ssSetStepSize ( rtS , 0.005 ) ;
ssSetFixedStepSize ( rtS , 0.005 ) ; { static RTWLogInfo rt_DataLoggingInfo ;
rt_DataLoggingInfo . loggingInterval = NULL ; ssSetRTWLogInfo ( rtS , &
rt_DataLoggingInfo ) ; } { { static int_T rt_LoggedStateWidths [ ] = { 2 , 2
, 1 , 2 , 2 , 1 , 1 } ; static int_T rt_LoggedStateNumDimensions [ ] = { 1 ,
1 , 1 , 1 , 1 , 1 , 1 } ; static int_T rt_LoggedStateDimensions [ ] = { 2 , 2
, 1 , 2 , 2 , 1 , 1 } ; static boolean_T rt_LoggedStateIsVarDims [ ] = { 0 ,
0 , 0 , 0 , 0 , 0 , 0 } ; static BuiltInDTypeId rt_LoggedStateDataTypeIds [ ]
= { SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE } ; static int_T rt_LoggedStateComplexSignals [ ] = { 0 , 0 , 0 , 0
, 0 , 0 , 0 } ; static const char_T * rt_LoggedStateLabels [ ] = { "CSTATE" ,
"CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" } ; static
const char_T * rt_LoggedStateBlockNames [ ] = {
"ARDroneHoverSim/ARDrone Simulation Block/State-Space" ,
"ARDroneHoverSim/ARDrone Simulation Block/State-Space1" ,
"ARDroneHoverSim/ARDrone Simulation Block/State-Space4" ,
"ARDroneHoverSim/ARDrone Simulation Block/State-Space5" ,
 "ARDroneHoverSim/Position estimation\nImportant:This block provides an \ninaccurate extimation of position \nbased on  velocity information. /Position estimation/Integrator"
, "ARDroneHoverSim/ARDrone Simulation Block/State-Space2" ,
"ARDroneHoverSim/ARDrone Simulation Block/State-Space3" } ; static const
char_T * rt_LoggedStateNames [ ] = { "" , "" , "" , "" , "" , "" , "" } ;
static boolean_T rt_LoggedStateCrossMdlRef [ ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0
} ; static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert [ ] = { { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } } ; static RTWLogSignalInfo
rt_LoggedStateSignalInfo = { 7 , rt_LoggedStateWidths ,
rt_LoggedStateNumDimensions , rt_LoggedStateDimensions ,
rt_LoggedStateIsVarDims , ( NULL ) , ( NULL ) , rt_LoggedStateDataTypeIds ,
rt_LoggedStateComplexSignals , ( NULL ) , ( NULL ) , { rt_LoggedStateLabels }
, ( NULL ) , ( NULL ) , ( NULL ) , { rt_LoggedStateBlockNames } , {
rt_LoggedStateNames } , rt_LoggedStateCrossMdlRef , rt_RTWLogDataTypeConvert
} ; static void * rt_LoggedStateSignalPtrs [ 7 ] ; rtliSetLogXSignalPtrs (
ssGetRTWLogInfo ( rtS ) , ( LogSignalPtrsType ) rt_LoggedStateSignalPtrs ) ;
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , & rt_LoggedStateSignalInfo
) ; rt_LoggedStateSignalPtrs [ 0 ] = ( void * ) & rtX . c0wv2q33w2 [ 0 ] ;
rt_LoggedStateSignalPtrs [ 1 ] = ( void * ) & rtX . j1xq4yvlx2 [ 0 ] ;
rt_LoggedStateSignalPtrs [ 2 ] = ( void * ) & rtX . clfp10tphj ;
rt_LoggedStateSignalPtrs [ 3 ] = ( void * ) & rtX . kjndn5kljk [ 0 ] ;
rt_LoggedStateSignalPtrs [ 4 ] = ( void * ) & rtX . lw2jyyhpz2 [ 0 ] ;
rt_LoggedStateSignalPtrs [ 5 ] = ( void * ) & rtX . iautxvq3ek ;
rt_LoggedStateSignalPtrs [ 6 ] = ( void * ) & rtX . ltpfrlwiir ; }
rtliSetLogT ( ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX (
ssGetRTWLogInfo ( rtS ) , "tmp_raccel_xout" ) ; rtliSetLogXFinal (
ssGetRTWLogInfo ( rtS ) , "xFinal" ) ; rtliSetLogVarNameModifier (
ssGetRTWLogInfo ( rtS ) , "none" ) ; rtliSetLogFormat ( ssGetRTWLogInfo ( rtS
) , 2 ) ; rtliSetLogMaxRows ( ssGetRTWLogInfo ( rtS ) , 0 ) ;
rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS ) , 1 ) ; rtliSetLogY (
ssGetRTWLogInfo ( rtS ) , "" ) ; rtliSetLogYSignalInfo ( ssGetRTWLogInfo (
rtS ) , ( NULL ) ) ; rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL
) ) ; } { static struct _ssStatesInfo2 statesInfo2 ; ssSetStatesInfo2 ( rtS ,
& statesInfo2 ) ; } { static ssPeriodicStatesInfo periodicStatesInfo ;
ssSetPeriodicStatesInfo ( rtS , & periodicStatesInfo ) ; } { static
ssSolverInfo slvrInfo ; static boolean_T contStatesDisabled [ 11 ] ;
ssSetSolverInfo ( rtS , & slvrInfo ) ; ssSetSolverName ( rtS , "ode1" ) ;
ssSetVariableStepSolver ( rtS , 0 ) ; ssSetSolverConsistencyChecking ( rtS ,
0 ) ; ssSetSolverAdaptiveZcDetection ( rtS , 0 ) ;
ssSetSolverRobustResetMethod ( rtS , 0 ) ; ssSetSolverStateProjection ( rtS ,
0 ) ; ssSetSolverMassMatrixType ( rtS , ( ssMatrixType ) 0 ) ;
ssSetSolverMassMatrixNzMax ( rtS , 0 ) ; ssSetModelOutputs ( rtS , MdlOutputs
) ; ssSetModelLogData ( rtS , rt_UpdateTXYLogVars ) ;
ssSetModelLogDataIfInInterval ( rtS , rt_UpdateTXXFYLogVars ) ;
ssSetModelUpdate ( rtS , MdlUpdate ) ; ssSetModelDerivatives ( rtS ,
MdlDerivatives ) ; ssSetTNextTid ( rtS , INT_MIN ) ; ssSetTNext ( rtS ,
rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ; ssSetNumNonsampledZCs ( rtS ,
0 ) ; ssSetContStateDisabled ( rtS , contStatesDisabled ) ; }
ssSetChecksumVal ( rtS , 0 , 1862538803U ) ; ssSetChecksumVal ( rtS , 1 ,
1285932175U ) ; ssSetChecksumVal ( rtS , 2 , 1195978743U ) ; ssSetChecksumVal
( rtS , 3 , 2431553248U ) ; { static const sysRanDType rtAlwaysEnabled =
SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo rt_ExtModeInfo ; static const
sysRanDType * systemRan [ 4 ] ; gblRTWExtModeInfo = & rt_ExtModeInfo ;
ssSetRTWExtModeInfo ( rtS , & rt_ExtModeInfo ) ;
rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo , systemRan ) ;
systemRan [ 0 ] = & rtAlwaysEnabled ; systemRan [ 1 ] = & rtAlwaysEnabled ;
systemRan [ 2 ] = & rtAlwaysEnabled ; systemRan [ 3 ] = & rtAlwaysEnabled ;
rteiSetModelMappingInfoPtr ( ssGetRTWExtModeInfo ( rtS ) , &
ssGetModelMappingInfo ( rtS ) ) ; rteiSetChecksumsPtr ( ssGetRTWExtModeInfo (
rtS ) , ssGetChecksums ( rtS ) ) ; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS )
, ssGetTPtr ( rtS ) ) ; } return rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
const int_T gblParameterTuningTid = 3 ; void MdlOutputsParameterSampleTime (
int_T tid ) { MdlOutputsTID3 ( tid ) ; }
