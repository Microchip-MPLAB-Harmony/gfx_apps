/********************************************************************************
  GFX GFX2D Driver Functions

  Company:
    Microchip Technology Inc.

  File Name:
    drv_glcd.c

  Summary:
    Source code for the GFX GFX2D driver static implementation.

  Description:
    This file contains the source code for the static implementation of the
    GFX GFX2D driver.
*******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2019 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute Software
only when embedded on a Microchip microcontroller or digital  signal  controller
that is integrated into your product or third party  product  (pursuant  to  the
sublicense terms in the accompanying license agreement).

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

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "gfx/driver/processor/gfx2d/drv_gfx2d.h"
#include "definitions.h"
#include "system/time/sys_time.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data
// *****************************************************************************
// *****************************************************************************

#define DISPLAY_WIDTH  480
#define DISPLAY_HEIGHT 272
uint32_t  __attribute__ ((aligned (64))) blitbuffer[DISPLAY_WIDTH * DISPLAY_HEIGHT] ;
uint32_t  __attribute__ ((aligned (64))) maskbuffer[DISPLAY_WIDTH * DISPLAY_HEIGHT] ;


/* Indicate end of execute instruction */
volatile uint8_t gpu_end = 0;

void _IntHandler(uintptr_t context)
{
    gpu_end = 1;
}

/**** End Hardware Abstraction Interfaces ****/


void DRV_GFX2D_Initialize()
{
    // call the plib initialization routines
    PLIB_GFX2D_Initialize();
    PLIB_GFX2D_Enable();
    PLIB_GFX2D_IRQ_CallbackRegister(_IntHandler, 0);
}

void  DRV_GFX2D_Fill(
    GFX2D_BUFFER *dest,
    GFX2D_RECTANGLE *dest_rect,
    gpu_color_t color)
{
    PLIB_GFX2D_Fill(dest, dest_rect, color);

    /* Wait for instruction to complete */
    while ( PLIB_GFX2D_GetGlobalStatusBusy() == true ) ;
    //while (gpu_end == 0) {
    //};
}

void  DRV_GFX2D_Copy(
    GFX2D_BUFFER *dest,
    GFX2D_RECTANGLE *dest_rect,
    GFX2D_BUFFER *src,
    GFX2D_RECTANGLE *src_rect)
{
    PLIB_GFX2D_Copy(dest, dest_rect, src, src_rect);

    /* Wait for instruction to complete */
    while ( PLIB_GFX2D_GetGlobalStatusBusy() == true ) ;
    //while (gpu_end == 0) {
    //};
}

void  DRV_GFX2D_Blend(
    GFX2D_BUFFER *dest,
    GFX2D_RECTANGLE *dest_rect,
    GFX2D_BUFFER *src1,
    GFX2D_RECTANGLE *src1_rect,
    GFX2D_BUFFER *src2,
    GFX2D_RECTANGLE *src2_rect,
    GFX2D_BLEND blend)
{
    PLIB_GFX2D_Blend(dest, dest_rect, src1, src1_rect, src2, src2_rect, blend);

    /* Wait for instruction to complete */
    while ( PLIB_GFX2D_GetGlobalStatusBusy() == true ) ;
    //while (gpu_end == 0) {
    //};
}

void  DRV_GFX2D_Rop(
   GFX2D_BUFFER *dest, 
   GFX2D_RECTANGLE *dest_rect, 
   GFX2D_BUFFER *src1,      
   GFX2D_RECTANGLE *src1_rect, 
   GFX2D_BUFFER *src2, 
   GFX2D_RECTANGLE *src2_rect,
   GFX2D_BUFFER *pmask, 
   GFX2D_ROP rop)
{
    PLIB_GFX2D_Rop(dest, dest_rect, src1, src1_rect, src2, src2_rect, pmask, rop);

    /* Wait for instruction to complete */
    while ( PLIB_GFX2D_GetGlobalStatusBusy() == true ) ;
    //while (gpu_end == 0) {
    //};
}
/*******************************************************************************
 End of File
*/
