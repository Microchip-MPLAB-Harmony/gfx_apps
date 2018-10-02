#include "gfx/hal/inc/gfx_processor_interface.h"

#if GFX_PROCESSOR_COUNT > 0
GFX_ProcessorIntf GFX_ProcessorInterfaces[GFX_PROCESSOR_COUNT] = {{0}};

GFX_Result GFX_InitializeProcessorList();

GFX_Result GFX_ProcessorIntfInitialize(void)
{   
    return GFX_InitializeProcessorList();
}

GFX_Result GFX_ProcessorIntfGet(GFX_Processor idx, GFX_ProcessorIntf* intf)
{
    if(idx >= GFX_PROCESSOR_COUNT || intf == NULL)
        return GFX_FAILURE;
        
    intf->infoGet = GFX_ProcessorInterfaces[idx].infoGet;
    intf->contextInitialize = GFX_ProcessorInterfaces[idx].contextInitialize;
        
    return GFX_SUCCESS;
}

GFX_ProcessorIntf* GFX_ProcessorIntfPtrGet(GFX_Driver idx)
{
    if(idx >= GFX_DRIVER_COUNT)
        return NULL;
        
    return &GFX_ProcessorInterfaces[idx];
}
#endif