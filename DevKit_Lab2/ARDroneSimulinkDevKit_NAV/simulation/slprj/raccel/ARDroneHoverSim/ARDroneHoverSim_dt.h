#include "__cf_ARDroneHoverSim.h"
#include "ext_types.h"
static uint_T rtDataTypeSizes [ ] = { sizeof ( real_T ) , sizeof ( real32_T )
, sizeof ( int8_T ) , sizeof ( uint8_T ) , sizeof ( int16_T ) , sizeof (
uint16_T ) , sizeof ( int32_T ) , sizeof ( uint32_T ) , sizeof ( boolean_T )
, sizeof ( fcn_call_T ) , sizeof ( int_T ) , sizeof ( pointer_T ) , sizeof (
action_T ) , 2 * sizeof ( uint32_T ) , sizeof ( struct_Ka1LQkcaTuqbPFRwNN4XNE
) } ; static const char_T * rtDataTypeNames [ ] = { "real_T" , "real32_T" ,
"int8_T" , "uint8_T" , "int16_T" , "uint16_T" , "int32_T" , "uint32_T" ,
"boolean_T" , "fcn_call_T" , "int_T" , "pointer_T" , "action_T" ,
"timer_uint32_pair_T" , "struct_Ka1LQkcaTuqbPFRwNN4XNE" } ; static
DataTypeTransition rtBTransitions [ ] = { { ( char_T * ) ( & rtB . hbl52k43sz
) , 0 , 0 , 41 } , { ( char_T * ) ( & rtDW . dzkln1ywkn ) , 0 , 0 , 5 } , { (
char_T * ) ( & rtDW . ncfoovoi12 . LoggedData ) , 11 , 0 , 13 } , { ( char_T
* ) ( & rtDW . aks53l4lnr ) , 10 , 0 , 5 } } ; static DataTypeTransitionTable
rtBTransTable = { 4U , rtBTransitions } ; static DataTypeTransition
rtPTransitions [ ] = { { ( char_T * ) ( & rtP . timeDelay ) , 0 , 0 , 69 } }
; static DataTypeTransitionTable rtPTransTable = { 1U , rtPTransitions } ;
