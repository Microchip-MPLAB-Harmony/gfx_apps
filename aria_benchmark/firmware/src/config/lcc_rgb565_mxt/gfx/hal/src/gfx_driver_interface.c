#include "gfx/hal/inc/gfx_driver_interface.h"

GFX_DriverIntf GFX_DriverInterfaces[GFX_DRIVER_COUNT] = {{0}};

GFX_Result GFX_InitializeDriverList();

GFX_Result GFX_DriverIntfInitialize(void)
{   
    return GFX_InitializeDriverList();
}

GFX_Result GFX_DriverIntfGet(GFX_Driver idx, GFX_DriverIntf* intf)
{
    if(idx >= GFX_DRIVER_COUNT || intf == NULL)
        return GFX_FAILURE;
        
    intf->infoGet = GFX_DriverInterfaces[idx].infoGet;
    intf->contextInitialize = GFX_DriverInterfaces[idx].contextInitialize;
        
    return GFX_SUCCESS;
}

GFX_DriverIntf* GFX_DriverIntfPtrGet(GFX_Driver idx)
{
    if(idx >= GFX_DRIVER_COUNT)
        return NULL;
        
    return &GFX_DriverInterfaces[idx];
}