#include "__cf_ARDroneHoverSim.h"
#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "ARDroneHoverSim_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)    
#else
#include "builtin_typeid_types.h"
#include "ARDroneHoverSim.h"
#include "ARDroneHoverSim_capi.h"
#include "ARDroneHoverSim_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST                  
#define TARGET_STRING(s)               (NULL)                    
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , TARGET_STRING (
"ARDroneHoverSim/deg 2 rad" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } ,
{ 1 , 0 , TARGET_STRING ( "ARDroneHoverSim/RTrans1" ) , TARGET_STRING ( "" )
, 0 , 0 , 1 , 0 , 1 } , { 2 , 0 , TARGET_STRING ( "ARDroneHoverSim/RTrans2" )
, TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 1 } , { 3 , 0 , TARGET_STRING (
"ARDroneHoverSim/RTrans3" ) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 1 } , {
4 , 0 , TARGET_STRING ( "ARDroneHoverSim/RTrans4" ) , TARGET_STRING ( "" ) ,
0 , 0 , 1 , 0 , 1 } , { 5 , 0 , TARGET_STRING (
"ARDroneHoverSim/ARDrone Simulation Block/Constant" ) , TARGET_STRING ( "" )
, 0 , 0 , 1 , 0 , 2 } , { 6 , 0 , TARGET_STRING (
"ARDroneHoverSim/ARDrone Simulation Block/deg 2 rad" ) , TARGET_STRING ( "" )
, 0 , 0 , 1 , 0 , 0 } , { 7 , 0 , TARGET_STRING (
"ARDroneHoverSim/ARDrone Simulation Block/deg 2 rad1" ) , TARGET_STRING ( ""
) , 0 , 0 , 1 , 0 , 0 } , { 8 , 0 , TARGET_STRING (
"ARDroneHoverSim/ARDrone Simulation Block/deg 2 rad2" ) , TARGET_STRING ( ""
) , 0 , 0 , 1 , 0 , 0 } , { 9 , 0 , TARGET_STRING (
"ARDroneHoverSim/ARDrone Simulation Block/Saturation 1" ) , TARGET_STRING (
"" ) , 0 , 0 , 1 , 0 , 1 } , { 10 , 0 , TARGET_STRING (
"ARDroneHoverSim/ARDrone Simulation Block/Saturation 2" ) , TARGET_STRING (
"" ) , 0 , 0 , 1 , 0 , 1 } , { 11 , 0 , TARGET_STRING (
"ARDroneHoverSim/ARDrone Simulation Block/Saturation 3" ) , TARGET_STRING (
"" ) , 0 , 0 , 1 , 0 , 1 } , { 12 , 0 , TARGET_STRING (
"ARDroneHoverSim/ARDrone Simulation Block/Saturation 4" ) , TARGET_STRING (
"" ) , 0 , 0 , 1 , 0 , 1 } , { 13 , 0 , TARGET_STRING (
"ARDroneHoverSim/ARDrone Simulation Block/State-Space" ) , TARGET_STRING ( ""
) , 0 , 0 , 1 , 0 , 0 } , { 14 , 0 , TARGET_STRING (
"ARDroneHoverSim/ARDrone Simulation Block/State-Space1" ) , TARGET_STRING (
"" ) , 0 , 0 , 1 , 0 , 0 } , { 15 , 0 , TARGET_STRING (
"ARDroneHoverSim/ARDrone Simulation Block/State-Space2" ) , TARGET_STRING (
"" ) , 0 , 0 , 1 , 0 , 0 } , { 16 , 0 , TARGET_STRING (
"ARDroneHoverSim/ARDrone Simulation Block/State-Space3" ) , TARGET_STRING (
"" ) , 0 , 0 , 1 , 0 , 0 } , { 17 , 0 , TARGET_STRING (
"ARDroneHoverSim/ARDrone Simulation Block/State-Space5" ) , TARGET_STRING (
"" ) , 0 , 0 , 1 , 0 , 0 } , { 18 , 0 , TARGET_STRING (
"ARDroneHoverSim/ARDrone Simulation Block/total communication time delay" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 0 } , { 19 , 0 , TARGET_STRING (
"ARDroneHoverSim/Visualization of Drone states/deg 2 rad1" ) , TARGET_STRING
( "" ) , 0 , 0 , 1 , 0 , 0 } , { 20 , 0 , TARGET_STRING (
"ARDroneHoverSim/Baseline Controller/Forward velocity controller /Gain" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 3 } , { 21 , 0 , TARGET_STRING (
 "ARDroneHoverSim/Baseline Controller/Heading controller/proportional control gain - yaw"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 3 } , { 22 , 0 , TARGET_STRING (
 "ARDroneHoverSim/Baseline Controller/Height controller /proportional control gain"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 3 } , { 23 , 0 , TARGET_STRING (
"ARDroneHoverSim/Baseline Controller/Lateral velocity controller/Gain1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 3 } , { 24 , 3 , TARGET_STRING (
 "ARDroneHoverSim/Position estimation Important:This block provides an  inaccurate extimation of position  based on  velocity information. /Position estimation/Velocity from vehicle body frame  to inertial NED  frame"
) , TARGET_STRING ( "" ) , 0 , 0 , 3 , 0 , 0 } , { 25 , 0 , TARGET_STRING (
 "ARDroneHoverSim/Position estimation Important:This block provides an  inaccurate extimation of position  based on  velocity information. /Position estimation/Constant1"
) , TARGET_STRING ( "" ) , 0 , 0 , 3 , 0 , 2 } , { 26 , 0 , TARGET_STRING (
 "ARDroneHoverSim/Position estimation Important:This block provides an  inaccurate extimation of position  based on  velocity information. /Position estimation/Integrator"
) , TARGET_STRING ( "" ) , 0 , 0 , 3 , 0 , 0 } , { 0 , 0 , ( NULL ) , ( NULL
) , 0 , 0 , 0 , 0 , 0 } } ; static const rtwCAPI_BlockParameters
rtBlockParameters [ ] = { { 27 , TARGET_STRING (
"ARDroneHoverSim/Heading ref (rad)" ) , TARGET_STRING ( "Value" ) , 0 , 1 , 0
} , { 28 , TARGET_STRING ( "ARDroneHoverSim/Height ref (m)" ) , TARGET_STRING
( "Value" ) , 0 , 1 , 0 } , { 29 , TARGET_STRING (
"ARDroneHoverSim/Inertial X ref (m)" ) , TARGET_STRING ( "Value" ) , 0 , 1 ,
0 } , { 30 , TARGET_STRING ( "ARDroneHoverSim/Inertial Y ref (m)" ) ,
TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 31 , TARGET_STRING (
"ARDroneHoverSim/deg 2 rad" ) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 32
, TARGET_STRING ( "ARDroneHoverSim/RTrans1" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 1 , 0 } , { 33 , TARGET_STRING (
"ARDroneHoverSim/RTrans2" ) , TARGET_STRING ( "InitialCondition" ) , 0 , 1 ,
0 } , { 34 , TARGET_STRING ( "ARDroneHoverSim/RTrans3" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 1 , 0 } , { 35 , TARGET_STRING (
"ARDroneHoverSim/RTrans4" ) , TARGET_STRING ( "InitialCondition" ) , 0 , 1 ,
0 } , { 36 , TARGET_STRING (
"ARDroneHoverSim/ARDrone Simulation Block/Constant" ) , TARGET_STRING (
"Value" ) , 0 , 1 , 0 } , { 37 , TARGET_STRING (
"ARDroneHoverSim/ARDrone Simulation Block/deg 2 rad" ) , TARGET_STRING (
"Gain" ) , 0 , 1 , 0 } , { 38 , TARGET_STRING (
"ARDroneHoverSim/ARDrone Simulation Block/deg 2 rad1" ) , TARGET_STRING (
"Gain" ) , 0 , 1 , 0 } , { 39 , TARGET_STRING (
"ARDroneHoverSim/ARDrone Simulation Block/deg 2 rad2" ) , TARGET_STRING (
"Gain" ) , 0 , 1 , 0 } , { 40 , TARGET_STRING (
"ARDroneHoverSim/ARDrone Simulation Block/Saturation 1" ) , TARGET_STRING (
"UpperLimit" ) , 0 , 1 , 0 } , { 41 , TARGET_STRING (
"ARDroneHoverSim/ARDrone Simulation Block/Saturation 1" ) , TARGET_STRING (
"LowerLimit" ) , 0 , 1 , 0 } , { 42 , TARGET_STRING (
"ARDroneHoverSim/ARDrone Simulation Block/Saturation 2" ) , TARGET_STRING (
"UpperLimit" ) , 0 , 1 , 0 } , { 43 , TARGET_STRING (
"ARDroneHoverSim/ARDrone Simulation Block/Saturation 2" ) , TARGET_STRING (
"LowerLimit" ) , 0 , 1 , 0 } , { 44 , TARGET_STRING (
"ARDroneHoverSim/ARDrone Simulation Block/Saturation 3" ) , TARGET_STRING (
"UpperLimit" ) , 0 , 1 , 0 } , { 45 , TARGET_STRING (
"ARDroneHoverSim/ARDrone Simulation Block/Saturation 3" ) , TARGET_STRING (
"LowerLimit" ) , 0 , 1 , 0 } , { 46 , TARGET_STRING (
"ARDroneHoverSim/ARDrone Simulation Block/Saturation 4" ) , TARGET_STRING (
"UpperLimit" ) , 0 , 1 , 0 } , { 47 , TARGET_STRING (
"ARDroneHoverSim/ARDrone Simulation Block/Saturation 4" ) , TARGET_STRING (
"LowerLimit" ) , 0 , 1 , 0 } , { 48 , TARGET_STRING (
"ARDroneHoverSim/ARDrone Simulation Block/State-Space" ) , TARGET_STRING (
"A" ) , 0 , 0 , 0 } , { 49 , TARGET_STRING (
"ARDroneHoverSim/ARDrone Simulation Block/State-Space" ) , TARGET_STRING (
"B" ) , 0 , 1 , 0 } , { 50 , TARGET_STRING (
"ARDroneHoverSim/ARDrone Simulation Block/State-Space" ) , TARGET_STRING (
"C" ) , 0 , 3 , 0 } , { 51 , TARGET_STRING (
"ARDroneHoverSim/ARDrone Simulation Block/State-Space" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 1 , 0 } , { 52 , TARGET_STRING (
"ARDroneHoverSim/ARDrone Simulation Block/State-Space1" ) , TARGET_STRING (
"A" ) , 0 , 0 , 0 } , { 53 , TARGET_STRING (
"ARDroneHoverSim/ARDrone Simulation Block/State-Space1" ) , TARGET_STRING (
"B" ) , 0 , 1 , 0 } , { 54 , TARGET_STRING (
"ARDroneHoverSim/ARDrone Simulation Block/State-Space1" ) , TARGET_STRING (
"C" ) , 0 , 3 , 0 } , { 55 , TARGET_STRING (
"ARDroneHoverSim/ARDrone Simulation Block/State-Space1" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 1 , 0 } , { 56 , TARGET_STRING (
"ARDroneHoverSim/ARDrone Simulation Block/State-Space2" ) , TARGET_STRING (
"A" ) , 0 , 1 , 0 } , { 57 , TARGET_STRING (
"ARDroneHoverSim/ARDrone Simulation Block/State-Space2" ) , TARGET_STRING (
"B" ) , 0 , 1 , 0 } , { 58 , TARGET_STRING (
"ARDroneHoverSim/ARDrone Simulation Block/State-Space2" ) , TARGET_STRING (
"C" ) , 0 , 1 , 0 } , { 59 , TARGET_STRING (
"ARDroneHoverSim/ARDrone Simulation Block/State-Space2" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 1 , 0 } , { 60 , TARGET_STRING (
"ARDroneHoverSim/ARDrone Simulation Block/State-Space3" ) , TARGET_STRING (
"A" ) , 0 , 1 , 0 } , { 61 , TARGET_STRING (
"ARDroneHoverSim/ARDrone Simulation Block/State-Space3" ) , TARGET_STRING (
"B" ) , 0 , 1 , 0 } , { 62 , TARGET_STRING (
"ARDroneHoverSim/ARDrone Simulation Block/State-Space3" ) , TARGET_STRING (
"C" ) , 0 , 1 , 0 } , { 63 , TARGET_STRING (
"ARDroneHoverSim/ARDrone Simulation Block/State-Space3" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 1 , 0 } , { 64 , TARGET_STRING (
"ARDroneHoverSim/ARDrone Simulation Block/State-Space4" ) , TARGET_STRING (
"A" ) , 0 , 1 , 0 } , { 65 , TARGET_STRING (
"ARDroneHoverSim/ARDrone Simulation Block/State-Space4" ) , TARGET_STRING (
"B" ) , 0 , 1 , 0 } , { 66 , TARGET_STRING (
"ARDroneHoverSim/ARDrone Simulation Block/State-Space4" ) , TARGET_STRING (
"C" ) , 0 , 1 , 0 } , { 67 , TARGET_STRING (
"ARDroneHoverSim/ARDrone Simulation Block/State-Space4" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 1 , 0 } , { 68 , TARGET_STRING (
"ARDroneHoverSim/ARDrone Simulation Block/State-Space5" ) , TARGET_STRING (
"A" ) , 0 , 0 , 0 } , { 69 , TARGET_STRING (
"ARDroneHoverSim/ARDrone Simulation Block/State-Space5" ) , TARGET_STRING (
"B" ) , 0 , 1 , 0 } , { 70 , TARGET_STRING (
"ARDroneHoverSim/ARDrone Simulation Block/State-Space5" ) , TARGET_STRING (
"C" ) , 0 , 3 , 0 } , { 71 , TARGET_STRING (
"ARDroneHoverSim/ARDrone Simulation Block/State-Space5" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 1 , 0 } , { 72 , TARGET_STRING (
"ARDroneHoverSim/ARDrone Simulation Block/total communication time delay" ) ,
TARGET_STRING ( "MaximumDelay" ) , 0 , 1 , 0 } , { 73 , TARGET_STRING (
"ARDroneHoverSim/ARDrone Simulation Block/total communication time delay" ) ,
TARGET_STRING ( "InitialOutput" ) , 0 , 4 , 0 } , { 74 , TARGET_STRING (
"ARDroneHoverSim/Visualization of Drone states/deg 2 rad1" ) , TARGET_STRING
( "Gain" ) , 0 , 1 , 0 } , { 75 , TARGET_STRING (
"ARDroneHoverSim/Baseline Controller/Forward velocity controller /Gain" ) ,
TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 76 , TARGET_STRING (
 "ARDroneHoverSim/Baseline Controller/Heading controller/proportional control gain - yaw"
) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 77 , TARGET_STRING (
 "ARDroneHoverSim/Baseline Controller/Height controller /proportional control gain"
) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 78 , TARGET_STRING (
"ARDroneHoverSim/Baseline Controller/Lateral velocity controller/Gain1" ) ,
TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 79 , TARGET_STRING (
"ARDroneHoverSim/Baseline Controller/Position controller/Gain2" ) ,
TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 80 , TARGET_STRING (
"ARDroneHoverSim/Baseline Controller/Position controller/Gain3" ) ,
TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 81 , TARGET_STRING (
 "ARDroneHoverSim/Position estimation Important:This block provides an  inaccurate extimation of position  based on  velocity information. /Position estimation/Constant1"
) , TARGET_STRING ( "Value" ) , 0 , 5 , 0 } , { 0 , ( NULL ) , ( NULL ) , 0 ,
0 , 0 } } ; static const rtwCAPI_ModelParameters rtModelParameters [ ] = { {
82 , TARGET_STRING ( "timeDelay" ) , 0 , 1 , 0 } , { 0 , ( NULL ) , 0 , 0 , 0
} } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . lj3rhp5vml [ 0 ] , & rtB .
d04rtlng0c , & rtB . ny5cfobxq4 , & rtB . mqxjcbkpjz , & rtB . ct0lfakgvx , &
rtB . hbl52k43sz , & rtB . e0dwz0nd0f , & rtB . afymbnqbja , & rtB .
k2pexa1jcv , & rtB . lo0eaoyvmd , & rtB . j3kljood4v , & rtB . cllqdyv02v , &
rtB . mhwrae3jwj , & rtB . cofx0wimtn , & rtB . hwfrmz5f3r , & rtB .
oz1y4s2hbk , & rtB . edlokp5332 , & rtB . grcjjbltf4 , & rtB . m32nvwcf2p [ 0
] , & rtB . lheu1wj2gf , & rtB . ic5el12kf2 , & rtB . karkyytmd2 , & rtB .
mq1at2ouk5 , & rtB . mrnorbqaqm , & rtB . gb1cjjlaov [ 0 ] , & rtB .
f5dnmxffg4 [ 0 ] , & rtB . kqhgmm5uqn [ 0 ] , & rtP . Headingrefrad_Value , &
rtP . Heightrefm_Value , & rtP . InertialXrefm_Value , & rtP .
InertialYrefm_Value , & rtP . deg2rad_Gain_ac0spr3vlb , & rtP .
RTrans1_InitialCondition , & rtP . RTrans2_InitialCondition , & rtP .
RTrans3_InitialCondition , & rtP . RTrans4_InitialCondition , & rtP .
Constant_Value , & rtP . deg2rad_Gain , & rtP . deg2rad1_Gain , & rtP .
deg2rad2_Gain , & rtP . Saturation1_UpperSat , & rtP . Saturation1_LowerSat ,
& rtP . Saturation2_UpperSat , & rtP . Saturation2_LowerSat , & rtP .
Saturation3_UpperSat , & rtP . Saturation3_LowerSat , & rtP .
Saturation4_UpperSat , & rtP . Saturation4_LowerSat , & rtP . StateSpace_A [
0 ] , & rtP . StateSpace_B , & rtP . StateSpace_C [ 0 ] , & rtP .
StateSpace_InitialCondition , & rtP . StateSpace1_A [ 0 ] , & rtP .
StateSpace1_B , & rtP . StateSpace1_C [ 0 ] , & rtP .
StateSpace1_InitialCondition , & rtP . StateSpace2_A , & rtP . StateSpace2_B
, & rtP . StateSpace2_C , & rtP . StateSpace2_InitialCondition , & rtP .
StateSpace3_A , & rtP . StateSpace3_B , & rtP . StateSpace3_C , & rtP .
StateSpace3_InitialCondition , & rtP . StateSpace4_A , & rtP . StateSpace4_B
, & rtP . StateSpace4_C , & rtP . StateSpace4_InitialCondition , & rtP .
StateSpace5_A [ 0 ] , & rtP . StateSpace5_B , & rtP . StateSpace5_C [ 0 ] , &
rtP . StateSpace5_InitialCondition , & rtP .
totalcommunicationtimedelay_MaxDelay , & rtP .
totalcommunicationtimedelay_InitOutput [ 0 ] , & rtP .
deg2rad1_Gain_nt4gyxjmbp , & rtP . Gain_Gain , & rtP .
proportionalcontrolgainyaw_Gain , & rtP . proportionalcontrolgain_Gain , &
rtP . Gain1_Gain , & rtP . Gain2_Gain , & rtP . Gain3_Gain , & rtP .
Constant1_Value [ 0 ] , & rtP . timeDelay , } ; static int32_T *
rtVarDimsAddrMap [ ] = { ( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , SS_DOUBLE , 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_VECTOR , 0 , 2 , 0 } , { rtwCAPI_SCALAR , 2 , 2 , 0 } , {
rtwCAPI_VECTOR , 4 , 2 , 0 } , { rtwCAPI_VECTOR , 6 , 2 , 0 } , {
rtwCAPI_VECTOR , 8 , 2 , 0 } , { rtwCAPI_VECTOR , 10 , 2 , 0 } } ; static
const uint_T rtDimensionArray [ ] = { 3 , 1 , 1 , 1 , 4 , 1 , 2 , 1 , 1 , 4 ,
1 , 2 } ; static const real_T rtcapiStoredFloats [ ] = { 0.0 , 0.005 , 0.065
} ; static const rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) ,
rtwCAPI_FIX_RESERVED , 0 , 0 , 0 } , } ; static const rtwCAPI_SampleTimeMap
rtSampleTimeMap [ ] = { { ( const void * ) & rtcapiStoredFloats [ 0 ] , (
const void * ) & rtcapiStoredFloats [ 0 ] , 0 , 0 } , { ( const void * ) &
rtcapiStoredFloats [ 1 ] , ( const void * ) & rtcapiStoredFloats [ 0 ] , 1 ,
0 } , { ( NULL ) , ( NULL ) , 3 , 0 } , { ( const void * ) &
rtcapiStoredFloats [ 2 ] , ( const void * ) & rtcapiStoredFloats [ 0 ] , 2 ,
0 } } ; static rtwCAPI_ModelMappingStaticInfo mmiStatic = { { rtBlockSignals
, 27 , ( NULL ) , 0 , ( NULL ) , 0 } , { rtBlockParameters , 55 ,
rtModelParameters , 1 } , { ( NULL ) , 0 } , { rtDataTypeMap , rtDimensionMap
, rtFixPtMap , rtElementMap , rtSampleTimeMap , rtDimensionArray } , "float"
, { 1862538803U , 1285932175U , 1195978743U , 2431553248U } , ( NULL ) , 0 ,
0 } ; const rtwCAPI_ModelMappingStaticInfo * ARDroneHoverSim_GetCAPIStaticMap
( void ) { return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void ARDroneHoverSim_InitializeDataMapInfo ( void ) { rtwCAPI_SetVersion ( (
* rt_dataMapInfoPtr ) . mmi , 1 ) ; rtwCAPI_SetStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ; rtwCAPI_SetLoggingStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ; rtwCAPI_SetDataAddressMap ( ( *
rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ; rtwCAPI_SetVarDimsAddressMap (
( * rt_dataMapInfoPtr ) . mmi , rtVarDimsAddrMap ) ;
rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi , 0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void ARDroneHoverSim_host_InitializeDataMapInfo (
ARDroneHoverSim_host_DataMapInfo_T * dataMap , const char * path ) {
rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ; rtwCAPI_SetStaticMap ( dataMap ->
mmi , & mmiStatic ) ; rtwCAPI_SetDataAddressMap ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , NULL ) ; rtwCAPI_SetPath (
dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
