/*******************************************************************************
  GFX GFX2D Driver Interface Declarations for Static Single Instance Driver

  Company:
    Microchip Technology Inc.

  File Name:
    drv_gfx2d.h

  Summary:
    GFX GFX2D driver interface declarations for the static single instance driver.

  Description:
    The GFX2D device driver provides a simple interface to manage the GFX2D
    module on Microchip microcontrollers. This file defines the interface
    Declarations for the GFX2D driver.

  Remarks:
    Static interfaces incorporate the driver instance number within the names
    of the routines, eliminating the need for an object ID or object handle.

    Static single-open interfaces also eliminate the need for the open handle.
*******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2019 released Microchip Technology Inc.  All rights reserved.

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

#ifndef _DRV_GFX_GFX2D_H
#define _DRV_GFX_GFX2D_H


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
#include "peripheral/gfx2d/plib_gfx2d.h"

#ifdef __cplusplus
    extern "C" {
#endif

// *****************************************************************************
/* Function:
    void DRV_GFX2D_Initialize ()

  Summary:
    Initializes the GFX2D driver.

  Description:
    This routine initializes the GFX2D driver.

  Precondition:
    None.

  Parameters:
    None.

  Returns:

  Remarks:
    This routine must be called before any other GFX2D routine is called.
    This routine should only be called once during system initialization.
*/
void DRV_GFX2D_Initialize();


// *****************************************************************************
/* Function:
    void  DRV_GFX2D_Fill()

   Summary:
    Fill a (partial) buffer with a specified color

   Description:
    Draws and fills a rectangle with a specific color onto destination buffer.

    An optional blend mode can be specified that defines the blending of the
    color onto the destination.

   Precondition:

   Parameters:
    destination   - Pointer to a n2d_buffer_t structure that describes the buffer to be filled
    rectangle     - Pointer to a rectangle that specifies the area to be filled. If rectangle is NULL,
                    the entire buffer will be filled with the specified color
    color         - The color value to use for filling the buffer
    blend         - The blending mode to be applied to each pixel. If no blending is required, set this
                    value to N2D_BLEND_NONE (0)

  Returns:
    Returns the status as defined by n2d_error_t

  Remarks:
    This function will wait until the hardware is complete, i.e. it is synchronous
*/
void  DRV_GFX2D_Fill(
    GFX2D_BUFFER *destination,
    GFX2D_RECTANGLE *rectangle,
    gpu_color_t color);

// *****************************************************************************
/* Function:
    void DRV_GFX2D_Copy()

   Summary:
    Copy a source buffer to the the destination buffer

   Description:
    The specified region of the source buffer is copied to the specified region
    of the destination buffer. If the regions are different in size, simple low-quality
    scaling will automatically be performed.

    An optional blend mode can be specified that defines the blending of the
    source onto the destination.

   Precondition:

   Parameters:
    destination           - Pointer to a n2d_buffer_t structure that describes the destination of the
                            blit
    destination_rectangle - Optional pointer to the rectangle that defines the region inside the
                            destination buffer. If this rectangle is not specified, the entire destination
                            buffer is used as the destination region
    source                - Pointer to a n2d_buffer_t structure that describes the source of the blit
    source_rectangle      - Optional pointer to the rectangle that defines the region inside the source buffer.
                            If this rectangle is not specified, the entire source buffer is used as the source
                            region

  Returns:
    Returns the status as defined by GFX_STATUS

  Remarks:
    This function will wait until the hardware is complete, i.e. it is synchronous.
  */
void DRV_GFX2D_Copy(
    GFX2D_BUFFER *destination,
    GFX2D_RECTANGLE *destination_rectangle,
    GFX2D_BUFFER *source,
    GFX2D_RECTANGLE *source_rectangle);

// *****************************************************************************
// *****************************************************************************
// Section: Functions
// *****************************************************************************
// *****************************************************************************

GFX_Result driverGfx2DInfoGet(GFX_DriverInfo* info);
GFX_Result driverGfx2DContextInitialize(GFX_Context* context);

#ifdef __cplusplus
    }
#endif
    
#endif // #ifndef _DRV_GFX_GFX2D_H
/*******************************************************************************
 End of File
*/
