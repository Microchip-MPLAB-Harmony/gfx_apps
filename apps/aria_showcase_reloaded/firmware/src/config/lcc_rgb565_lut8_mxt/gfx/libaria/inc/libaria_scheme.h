/*******************************************************************************
 Module for Microchip Graphics Library - Aria User Interface Library

  Company:
    Microchip Technology Inc.

  File Name:
    libaria_scheme.h

  Summary:
    A scheme is a collection of colors that can be referenced by one or more
    widgets.  Widgets may use schemes in different ways.  While the color
    names strive to be intuitive they aren't always used in the manner in
    which they describe.
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

#ifndef LIBARIA_SCHEME_H
#define LIBARIA_SCHEME_H
//DOM-IGNORE-END

#include "gfx/libaria/inc/libaria_common.h"
#include "gfx/libaria/inc/libaria_draw.h"
#include "gfx/utils/gfx_utils.h"

#ifdef __cplusplus
    extern "C" {
#endif
      
// *****************************************************************************
// *****************************************************************************
// Section: Data Types and Constants
// *****************************************************************************
// *****************************************************************************

/*
  Enumeration:
    laScheme_t

  Summary:
    This structure specifies the style scheme components of an object.

  Description:
    A scheme is a collection of colors that can be referenced by widgets
    or other objects. While the color names strive to be intuitive they
    aren't always used in the manner in which they describe.

  Remarks:
   None.
 */
typedef struct laScheme_t
{
    GFX_Color base;
    GFX_Color highlight;
    GFX_Color highlightLight;
    GFX_Color shadow;
    GFX_Color shadowDark;
    GFX_Color foreground;
    GFX_Color foregroundInactive;
    GFX_Color foregroundDisabled;
    GFX_Color background;
    GFX_Color backgroundInactive;
    GFX_Color backgroundDisabled;
    GFX_Color text;
    GFX_Color textHighlight;
    GFX_Color textHighlightText;
    GFX_Color textInactive;
    GFX_Color textDisabled;
} laScheme;

// *****************************************************************************
// *****************************************************************************
// Section: Routines
// *****************************************************************************
// *****************************************************************************

/* Function:
     void laScheme_Initialize(laScheme* scheme, GFX_ColorMode mode)
 
   Summary:
     Initialize the scheme to the default values as per the specified color mode. 

   Description:
     Initialize the scheme to the default values as per the specified color mode.

   Parameters:
     laSceme* scheme - the scheme to modify
     GFX_ColorMode - the color mode to use
    
   Returns:
     void    

*/
LIB_EXPORT void laScheme_Initialize(laScheme* scheme, GFX_ColorMode mode);

#ifdef __cplusplus
    }
#endif
    
#endif // LIBARIA_SCHEME_H 
