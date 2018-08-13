#include "gfx/hal/inc/gfx_driver_interface.h"

GFX_Result driverLCCInfoGet(GFX_DriverInfo* info);
GFX_Result driverLCCContextInitialize(GFX_Context* context);

GFX_Result GFX_InitializeDriverList()
{
    GFX_DriverInterfaces[0].infoGet = &driverLCCInfoGet;
    GFX_DriverInterfaces[0].contextInitialize = &driverLCCContextInitialize;

    return GFX_SUCCESS;
}