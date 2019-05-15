/*******************************************************************************
  GFX GLCD Driver Interface Declarations for Static Single Instance Driver

  Company:
    Microchip Technology Inc.

  File Name:
    drv_gfx_glcd_static.h

  Summary:
    GFX GLCD driver interface declarations for the static single instance driver.

  Description:
    The GLCD device driver provides a simple interface to manage the GLCD
    module on Microchip microcontrollers. This file defines the interface
    Declarations for the GLCD driver.

  Remarks:
    Static interfaces incorporate the driver instance number within the names
    of the routines, eliminating the need for an object ID or object handle.

    Static single-open interfaces also eliminate the need for the open handle.
*******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2015 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED AS IS  WITHOUT  WARRANTY  OF  ANY  KIND,
EITHER EXPRESS  OR  IMPLIED,  INCLUDING  WITHOUT  LIMITATION,  ANY  WARRANTY  OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A  PARTICULAR  PURPOSE.
IN NO EVENT SHALL MICROCHIP OR  ITS  LICENSORS  BE  LIABLE  OR  OBLIGATED  UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION,  BREACH  OF  WARRANTY,  OR
OTHER LEGAL  EQUITABLE  THEORY  ANY  DIRECT  OR  INDIRECT  DAMAGES  OR  EXPENSES
INCLUDING BUT NOT LIMITED TO ANY  INCIDENTAL,  SPECIAL,  INDIRECT,  PUNITIVE  OR
CONSEQUENTIAL DAMAGES, LOST  PROFITS  OR  LOST  DATA,  COST  OF  PROCUREMENT  OF
SUBSTITUTE  GOODS,  TECHNOLOGY,  SERVICES,  OR  ANY  CLAIMS  BY  THIRD   PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE  THEREOF),  OR  OTHER  SIMILAR  COSTS.
*******************************************************************************/
//DOM-IGNORE-END

#ifndef _DRV_GFX_GLCD_H
#define _DRV_GFX_GLCD_H


// *****************************************************************************
// *****************************************************************************
// Section: File includes
// *****************************************************************************
// *****************************************************************************
/* Note:  A file that maps the interface definitions above to appropriate static
          implementations (depending on build mode) is included at the bottom of
          this file.
*/

#include "gfx/hal/inc/gfx_common.h"
#include "gfx/hal/inc/gfx_driver_interface.h"
#include "gfx/hal/inc/gfx_default_impl.h"

#ifdef __cplusplus
    extern "C" {
#endif
        
// *****************************************************************************
/* GLCD Layer Control Definitions

  Summary:
    Structure holding the layer control definitions

  Description:
    This structure contains the layer control definitions.

  Remarks:
*/

typedef enum {
        GLCD_LAYER_DISABLE   = 0,
        GLCD_LAYER_ENABLE    = 1 << 31,
} GLCD_LAYER_CONTROL;


// *****************************************************************************
// *****************************************************************************
// Section: Interface Headers for the Static Driver
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
     void  void  DRV_GFX_GLCD_BackgroundColorSet(uint32_t bgColor)

  Summary:
     Sets the background color to the specified RGBA value

     <p><b>Implementation:</b> Static</p>

  Description:
     Sets the background color to the specified RGBA value


  Precondition:
    DRV_GFX_GLCD_Open has been called.

  Parameters:
    bgColor                        - RGBA color

  Returns:
    * none

  Remarks:
*/
void  DRV_GFX_GLCD_BackgroundColorSet(uint32_t bgColor);

// *****************************************************************************
/* Function:
    void DRV_GFX_GLCD_LayerAlphaSet(uint8_t alpha)

  Summary:
    Sets the alpha value for the specified layer index.
    <p><b>Implementation:</b> Static</p>

  Description:
    This routine sets the alpha value of the layer ranging from 0 to 0xFF.

  Precondition:
    DRV_GFX_GLCD_Open has been called.

  Parameters:
    None.

  Returns:
    None.

  Remarks:

*/
void DRV_GFX_GLCD_LayerAlphaSet(uint8_t alpha);

// *****************************************************************************
/* Function:
    void DRV_GFX_GLCD_LayerDestBlendSet(GLCD_LAYER_DEST_BLEND_FUNC blend)

  Summary:
    Sets the destination blend value to be used for the specified layer index.
    <p><b>Implementation:</b> Static</p>

  Description:
    This routine sets the destination blend value to be used for the specified layer index.

  Precondition:
    DRV_GFX_GLCD_Open has been called.

  Parameters:
    None.

  Returns:
    None.

  Remarks:

*/
void DRV_GFX_GLCD_LayerDestBlendSet(GLCD_LAYER_DEST_BLEND_FUNC blend);

// *****************************************************************************
/* Function:
    void DRV_GFX_GLCD_LayerSrcBlendSet(GLCD_LAYER_SRC_BLEND_FUNC blend)

  Summary:
    Sets the source blend value to be used for the specified layer index.
    <p><b>Implementation:</b> Static</p>

  Description:
    This routine sets the source blend value to be used for the specified layer index.

  Precondition:
    DRV_GFX_GLCD_Open has been called.

  Parameters:
    None.

  Returns:
    None.

  Remarks:

*/
void DRV_GFX_GLCD_LayerSrcBlendSet(GLCD_LAYER_SRC_BLEND_FUNC blend);

// *****************************************************************************
/* Function:
    void DRV_GFX_GLCD_LayerColorSpaceSet(GLCD_LAYER_COLOR_MODE colorSpace)

  Summary:
    Sets the color space to be used for the specified layer index.
    <p><b>Implementation:</b> Static</p>

  Description:
    This routine sets the color space to be used for the specified layer index.

  Precondition:
    DRV_GFX_GLCD_Open has been called.

  Parameters:
    None.

  Returns:
    None.

  Remarks:

*/
void DRV_GFX_GLCD_LayerColorSpaceSet(GLCD_LAYER_COLOR_MODE colorSpace);

// *****************************************************************************
/* Function:
    void DRV_GFX_GLCD_LayerEnableSet(GFX_Bool enable)

  Summary:
    Enables or disables the specified layer index based on the given enable flag.
    <p><b>Implementation:</b> Static</p>

  Description:
    Enables or disables the specified layer index based on the given enable flag.

  Precondition:
    DRV_GFX_GLCD_Open has been called.

  Parameters:
    None.

  Returns:
    None.

  Remarks:
*/
void DRV_GFX_GLCD_LayerEnableSet(GFX_Bool enable);

// *****************************************************************************
/* Function:
    void DRV_GFX_GLCD_LayerModeSet(uint32_t layerMode)

  Summary:
    Sets the mode state for the specified layer index.
    <p><b>Implementation:</b> Static</p>

  Description:
    This routine sets the mode state of the layer to either show or not show the layer.

  Precondition:
    DRV_GFX_GLCD_Open has been called.

  Parameters:
    None.

  Returns:
    None.

  Remarks:
    Deprecated. Will not be available next release.

*/
void DRV_GFX_GLCD_LayerModeSet(uint32_t layerMode);

// *****************************************************************************
/* Function:
    void DRV_GFX_GLCD_LayerFrameBufferSet(uint32_t * frame)

  Summary:
    Sets the baseaddress of the layer to the specific memory location.
    <p><b>Implementation:</b> Static</p>

  Description:
    This routine sets the baseaddress of the layer to the specific memory location.

  Precondition:
    DRV_GFX_GLCD_Open has been called.

  Parameters:
    None.

  Returns:
    None.

  Remarks:

*/
void DRV_GFX_GLCD_LayerFrameBufferSet(uint32_t * frame);

// *****************************************************************************
/* Function:
     void  DRV_GFX_GLCD_CursorSetPosition(uint32_t x, uint32_t y, GFX_Bool enable)

  Summary:
     Sets the position and enable state of the cursor.

     <p><b>Implementation:</b> Static</p>

  Description:
     Sets the x, y position of the cursor and its enable state.

  Precondition:
    DRV_GFX_GLCD_Open has been called.

  Parameters:
    x                              - x coordinate of the start point.
    y                              - y coordinate of the end point.
    enable                         - enable cursor on or off

  Returns:
    * none

  Remarks:
*/
void  DRV_GFX_GLCD_CursorSetPosition(uint32_t x, uint32_t y, GFX_Bool enable);

// *****************************************************************************
/* Function:
     void  DRV_GFX_GLCD_CursorImageSet(uint32_t * cursorImage)

  Summary:
     Sets Cursor image to the image specified.
     <p><b>Implementation:</b> Static</p>

  Description:
     Sets Cursor image to the image specified.

  Precondition:
    DRV_GFX_GLCD_Open has been called.

  Parameters:
    uint32_t * cursorImage         - 32x32 palatte image

  Returns:
    * none

  Remarks:
*/
void  DRV_GFX_GLCD_CursorImageSet(uint32_t * cursorImage);


// *****************************************************************************
/* Function:
     void DRV_GFX_GLCD_CursorPaletteSet(uint32_t * cursorPalette)

  Summary:
     Sets the Cursor Pallette to the given cursor palette.
     <p><b>Implementation:</b> Static</p>

  Description:
     Sets Cursor image to the image specified.

  Precondition:
    DRV_GFX_GLCD_Open has been called.

  Parameters:
    uint32_t * cursorImage         - 32x32 palatte image

  Returns:
    * none

  Remarks:
*/
void DRV_GFX_GLCD_CursorPaletteSet(uint32_t * gammaPalette);


// *****************************************************************************
/* Function:
     void DRV_GFX_GLCD_GammaPaletteSet(uint32_t * cursorPalette)

  Summary:
     Setsthe global gamma/palette to the given cursor palette.
     <p><b>Implementation:</b> Static</p>

  Description:
     Sets the global gamma/platform image.

  Precondition:
    DRV_GFX_GLCD_Open has been called.

  Parameters:
    uint32_t * cursorImage         - 32x32 palatte image

  Returns:
    * none

  Remarks:
*/
void  DRV_GFX_GLCD_GammaPaletteSet(uint32_t * gammaPalette);


// *****************************************************************************
// *****************************************************************************
// Section: Functions
// *****************************************************************************
// *****************************************************************************

GFX_Result driverLCCInfoGet(GFX_DriverInfo* info);
GFX_Result driverLCCContextInitialize(GFX_Context* context);

#ifdef __cplusplus
    }
#endif
    
#endif // #ifndef _DRV_GFX_GLCD_H
/*******************************************************************************
 End of File
*/
