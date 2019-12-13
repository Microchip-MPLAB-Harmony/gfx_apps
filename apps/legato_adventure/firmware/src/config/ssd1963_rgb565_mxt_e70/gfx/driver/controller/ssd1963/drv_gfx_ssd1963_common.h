/*******************************************************************************
 Module for Microchip Graphics Library - Hardware Abstraction Layer

  Company:
    Microchip Technology Inc.

  File Name:
    drv_gfx_ssd1963_common.h

  Summary:
    Contains SSD1963 driver type definitions and interface prototypes.

  Description:
    Contains SSD1963 driver type definitions and interface prototypes.
*******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2017 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
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

#ifndef DRV_GFX_SSD1963_COMMON_H    /* Guard against multiple inclusion */
#define DRV_GFX_SSD1963_COMMON_H

/** SSD1963_CMD_PARAM

  Summary:
    Structure contains command and parameter information.

*/
typedef struct 
{
    /* Command */
    uint8_t cmd;
    
    /* Number of command parameters */
    uint8_t parmCount;
    
    /* Command parameters, max of 4 */
    uint8_t parms[4];
} SSD1963_CMD_PARAM;

/** SSD1963_DRV_STATE

  Summary:
    Enum of SSD1963 driver states.
    
*/
typedef enum
{
    INIT = 0,
    RUN
} SSD1963_DRV_STATE;

/** SSD1963_DRV

  Summary:
    Structure contains driver-specific data and ops pointers.
    
*/
typedef struct SSD1963_DRV 
{
    /* Driver state */
    SSD1963_DRV_STATE state;
    
    /* Port-specific private data */
    void *port_priv;
} SSD1963_DRV;

/* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif // DRV_GFX_SSD1963_COMMON_H

/* *****************************************************************************
 End of File
 */
