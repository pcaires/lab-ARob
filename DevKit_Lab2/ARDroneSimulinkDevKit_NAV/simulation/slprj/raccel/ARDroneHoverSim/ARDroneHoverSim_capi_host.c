#include "ARDroneHoverSim_capi_host.h"
static ARDroneHoverSim_host_DataMapInfo_T root;
static int initialized = 0;
rtwCAPI_ModelMappingInfo *getRootMappingInfo()
{
    if (initialized == 0) {
        initialized = 1;
        ARDroneHoverSim_host_InitializeDataMapInfo(&(root), "ARDroneHoverSim");
    }
    return &root.mmi;
}

rtwCAPI_ModelMappingInfo *mexFunction() {return(getRootMappingInfo());}
