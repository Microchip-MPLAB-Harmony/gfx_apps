/*******************************************************************************
  MPLAB Harmony Generated Driver Header File

  File Name:
    drv_gfx_ssd1963.h

  Summary:
    Build-time generated header file for SSD1963 driver.

  Description:
    Build-time generated header file for top-level SSD1963 driver.
 * 
    Created with MPLAB Harmony Version 3.0
*******************************************************************************/
//DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2017 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED AS IS WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
*******************************************************************************/
// DOM-IGNORE-END

#ifndef DRV_GFX_SSD1963_H
#define DRV_GFX_SSD1963_H

#include "gfx/hal/inc/gfx_common.h"
#include "gfx/hal/inc/gfx_driver_interface.h"
#include "gfx/hal/inc/gfx_default_impl.h"

#ifdef __cplusplus
    extern "C" {
#endif
 

//DOM-IGNORE-END

GFX_Result driverSSD1963InfoGet(GFX_DriverInfo *info);
GFX_Result driverSSD1963ContextInitialize(GFX_Context *context);

#ifdef __cplusplus
    }
#endif
    
#endif // DRV_GFX_SSD1963_H