/*******************************************************************************
  Module for Microchip Graphics Library - Aria User Interface Library

  Company:
    Microchip Technology Inc.

  File Name:
    libaria_common.h

  Summary:
    This file defines the common macros and definitions used by the gfx
    definition and implementation headers.

  Description:
    This file defines the common macros and definitions used by the gfx
    definition and the implementation header.

  Remarks:
    The directory in which this file resides should be added to the compiler's
    search path for header files.
 *******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2010-2014 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED AS-IS WITHOUT WARRANTY OF ANY KIND,
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

#ifndef LIBARIA_COMMON_H
#define LIBARIA_COMMON_H
//DOM-IGNORE-END

#include "gfx/libaria/inc/libaria_global.h"

#include "gfx/hal/gfx.h"
#include "gfx/utils/gfx_utils.h"

#include "gfx/libaria/libaria_config.h"

#ifndef WIN32
//#include "osal/osal.h" FIXME for H3
#else
#include "native_common.h"
#endif

#ifndef LA_DEFAULT_SCHEME_COLOR_MODE
#define LA_DEFAULT_SCHEME_COLOR_MODE GFX_COLOR_MODE_RGB_565
#endif

#ifdef __cplusplus
    extern "C" {
#endif

// *****************************************************************************
// *****************************************************************************
// Section: Data Types and Constants
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Enumeration:
    laResult

  Summary:
    libaria results (success and failure codes).

  Description:
    Various definitions for success and failure codes.

  Remarks:
    None.
*/
typedef enum laResult_t
{
    LA_FAILURE = -1,
    LA_SUCCESS = 0
} laResult;

// *****************************************************************************
/* Enumeration:
    laBool

  Summary:
    libaria bool values

  Description:
    libaria bool values

  Remarks:
    None.
*/
typedef enum laBool_t
{
    LA_FALSE = 0,
    LA_TRUE
} laBool;

// *****************************************************************************
/* Enumeration:
    laVAlignment

  Summary:
    libaria vertical alignment values

  Description:
    libaria vertical alignment values

  Remarks:
    None.
*/
typedef enum
{
    LA_VALIGN_TOP,
    LA_VALIGN_MIDDLE,
    LA_VALIGN_BOTTOM
} laVAlignment;

// *****************************************************************************
/* Enumeration:
    laHAlignment

  Summary:
    libaria horizontal alignment values

  Description:
    libaria horizontal alignment values

  Remarks:
    None.
*/
typedef enum
{
    LA_HALIGN_LEFT,
    LA_HALIGN_CENTER,
    LA_HALIGN_RIGHT
} laHAlignment;

// *****************************************************************************
/* Enumeration:
    laMargin

  Summary:
    libaria margin values

  Description:
    libaria margin values

  Remarks:
    None.
*/
typedef struct laMargin_t
{
    uint8_t left;
    uint8_t top;
    uint8_t right;
    uint8_t bottom;
} laMargin;

// *****************************************************************************
/* Enumeration:
    laRelativePosition

  Summary:
    libaria relative position values

  Description:
    libaria relative position values

  Remarks:
    None.
*/
typedef enum laRelativePosition
{
    LA_RELATIVE_POSITION_LEFTOF,
    LA_RELATIVE_POSITION_ABOVE,
    LA_RELATIVE_POSITION_RIGHTOF,
    LA_RELATIVE_POSITION_BELOW,
    LA_RELATIVE_POSITION_BEHIND
} laRelativePosition;

// *****************************************************************************
/* Enumeration:
    laPreemptionLevel

  Summary:
    libaria pre-emption level values

  Description:
    libaria pre-emption level values

  Remarks:
    None.
*/
typedef enum laPreemptionLevel
{
    LA_PREEMPTION_LEVEL_0, // draw cycle always completes
    LA_PREEMPTION_LEVEL_1, // preempts after each widget fully draws
    LA_PREEMPTION_LEVEL_2  // preempts after each widget draw step completes
} laPreemptionLevel;

// DOM-IGNORE-END

#ifdef __cplusplus
    }
#endif
     
#endif // LIBARIA_COMMON_H

/*******************************************************************************
 End of File
*/
