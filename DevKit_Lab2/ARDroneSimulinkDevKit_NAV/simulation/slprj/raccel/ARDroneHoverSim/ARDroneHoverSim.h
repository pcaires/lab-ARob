#include "__cf_ARDroneHoverSim.h"
#ifndef RTW_HEADER_ARDroneHoverSim_h_
#define RTW_HEADER_ARDroneHoverSim_h_
#include <stddef.h>
#include <float.h>
#include <string.h>
#include "rtw_modelmap.h"
#ifndef ARDroneHoverSim_COMMON_INCLUDES_
#define ARDroneHoverSim_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "sigstream_rtw.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "ARDroneHoverSim_types.h"
#include "multiword_types.h"
#include "mwmathutil.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"
#include "rtGetInf.h"
#define MODEL_NAME ARDroneHoverSim
#define NSAMPLE_TIMES (4) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (33) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (11)   
#elif NCSTATES != 11
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { real_T hbl52k43sz ; real_T cofx0wimtn ; real_T afymbnqbja ;
real_T hwfrmz5f3r ; real_T e0dwz0nd0f ; real_T k2pexa1jcv ; real_T grcjjbltf4
; real_T f5dnmxffg4 [ 2 ] ; real_T kqhgmm5uqn [ 2 ] ; real_T lj3rhp5vml [ 3 ]
; real_T lheu1wj2gf ; real_T ct0lfakgvx ; real_T lo0eaoyvmd ; real_T
mqxjcbkpjz ; real_T j3kljood4v ; real_T ny5cfobxq4 ; real_T cllqdyv02v ;
real_T d04rtlng0c ; real_T mhwrae3jwj ; real_T oz1y4s2hbk ; real_T edlokp5332
; real_T m32nvwcf2p [ 4 ] ; real_T kwpff2ydjd ; real_T le5u5iq05u ; real_T
lcppzkdajf ; real_T mtdunn0hxq ; real_T ic5el12kf2 ; real_T karkyytmd2 ;
real_T ky1idomaqy ; real_T mq1at2ouk5 ; real_T ayqkbl03wb ; real_T mrnorbqaqm
; real_T gb1cjjlaov [ 2 ] ; } B ; typedef struct { real_T dzkln1ywkn ; real_T
cilee0gxli ; real_T omsjx15qkl ; real_T o0kw0astte ; struct { real_T
modelTStart ; } fusksw1re2 ; struct { void * LoggedData ; } ncfoovoi12 ;
struct { void * LoggedData ; } bsp21xrd1m ; struct { void * LoggedData ; }
pcayyc2dsa ; struct { void * LoggedData ; } f4msh5lxk5 ; struct { void *
LoggedData ; } gki5ebwyhe ; struct { void * TUbufferPtrs [ 8 ] ; } ncnf0zgwn3
; int_T aks53l4lnr ; struct { int_T Tail [ 4 ] ; int_T Head [ 4 ] ; int_T
Last [ 4 ] ; int_T CircularBufSize [ 4 ] ; int_T MaxNewBufSize ; } phswmmvrn3
; } DW ; typedef struct { real_T c0wv2q33w2 [ 2 ] ; real_T j1xq4yvlx2 [ 2 ] ;
real_T clfp10tphj ; real_T kjndn5kljk [ 2 ] ; real_T lw2jyyhpz2 [ 2 ] ;
real_T iautxvq3ek ; real_T ltpfrlwiir ; } X ; typedef struct { real_T
c0wv2q33w2 [ 2 ] ; real_T j1xq4yvlx2 [ 2 ] ; real_T clfp10tphj ; real_T
kjndn5kljk [ 2 ] ; real_T lw2jyyhpz2 [ 2 ] ; real_T iautxvq3ek ; real_T
ltpfrlwiir ; } XDot ; typedef struct { boolean_T c0wv2q33w2 [ 2 ] ; boolean_T
j1xq4yvlx2 [ 2 ] ; boolean_T clfp10tphj ; boolean_T kjndn5kljk [ 2 ] ;
boolean_T lw2jyyhpz2 [ 2 ] ; boolean_T iautxvq3ek ; boolean_T ltpfrlwiir ; }
XDis ; typedef struct { rtwCAPI_ModelMappingInfo mmi ; } DataMapInfo ; struct
P_ { real_T timeDelay ; real_T Constant_Value ; real_T StateSpace_A [ 3 ] ;
real_T StateSpace_B ; real_T StateSpace_C [ 2 ] ; real_T
StateSpace_InitialCondition ; real_T deg2rad1_Gain ; real_T StateSpace1_A [ 3
] ; real_T StateSpace1_B ; real_T StateSpace1_C [ 2 ] ; real_T
StateSpace1_InitialCondition ; real_T deg2rad_Gain ; real_T StateSpace4_A ;
real_T StateSpace4_B ; real_T StateSpace4_C ; real_T
StateSpace4_InitialCondition ; real_T deg2rad2_Gain ; real_T StateSpace5_A [
3 ] ; real_T StateSpace5_B ; real_T StateSpace5_C [ 2 ] ; real_T
StateSpace5_InitialCondition ; real_T Constant1_Value [ 2 ] ; real_T
deg2rad_Gain_ac0spr3vlb ; real_T deg2rad1_Gain_nt4gyxjmbp ; real_T
RTrans4_InitialCondition ; real_T Saturation1_UpperSat ; real_T
Saturation1_LowerSat ; real_T RTrans3_InitialCondition ; real_T
Saturation2_UpperSat ; real_T Saturation2_LowerSat ; real_T
RTrans2_InitialCondition ; real_T Saturation3_UpperSat ; real_T
Saturation3_LowerSat ; real_T RTrans1_InitialCondition ; real_T
Saturation4_UpperSat ; real_T Saturation4_LowerSat ; real_T StateSpace2_A ;
real_T StateSpace2_B ; real_T StateSpace2_C ; real_T
StateSpace2_InitialCondition ; real_T StateSpace3_A ; real_T StateSpace3_B ;
real_T StateSpace3_C ; real_T StateSpace3_InitialCondition ; real_T
totalcommunicationtimedelay_MaxDelay ; real_T
totalcommunicationtimedelay_InitOutput [ 4 ] ; real_T InertialXrefm_Value ;
real_T InertialYrefm_Value ; real_T Gain2_Gain ; real_T Gain_Gain ; real_T
Headingrefrad_Value ; real_T proportionalcontrolgainyaw_Gain ; real_T
Heightrefm_Value ; real_T proportionalcontrolgain_Gain ; real_T Gain3_Gain ;
real_T Gain1_Gain ; } ; extern const char * RT_MEMORY_ALLOCATION_ERROR ;
extern B rtB ; extern X rtX ; extern DW rtDW ; extern P rtP ; extern const
rtwCAPI_ModelMappingStaticInfo * ARDroneHoverSim_GetCAPIStaticMap ( void ) ;
extern SimStruct * const rtS ; extern const int_T gblNumToFiles ; extern
const int_T gblNumFrFiles ; extern const int_T gblNumFrWksBlocks ; extern
rtInportTUtable * gblInportTUtables ; extern const char * gblInportFileName ;
extern const int_T gblNumRootInportBlks ; extern const int_T
gblNumModelInputs ; extern const int_T gblInportDataTypeIdx [ ] ; extern
const int_T gblInportDims [ ] ; extern const int_T gblInportComplex [ ] ;
extern const int_T gblInportInterpoFlag [ ] ; extern const int_T
gblInportContinuous [ ] ; extern const int_T gblParameterTuningTid ; extern
size_t gblCurrentSFcnIdx ; extern DataMapInfo * rt_dataMapInfoPtr ; extern
rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr ; void MdlOutputs ( int_T tid )
; void MdlOutputsParameterSampleTime ( int_T tid ) ; void MdlUpdate ( int_T
tid ) ; void MdlTerminate ( void ) ; void MdlInitializeSizes ( void ) ; void
MdlInitializeSampleTimes ( void ) ; SimStruct * raccel_register_model ( void
) ;
#endif
