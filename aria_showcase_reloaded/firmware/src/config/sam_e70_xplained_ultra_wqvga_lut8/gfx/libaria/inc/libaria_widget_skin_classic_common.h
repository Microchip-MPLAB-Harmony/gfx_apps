/*******************************************************************************
 Module for Microchip Graphics Library - Aria User Interface Library

  Company:
    Microchip Technology Inc.

  File Name:
    libaria_widget_skin_classic_common.c

  Summary:
    Common functions for the classic widget skin.

  Description:   
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

#ifndef LIBARIA_WIDGET_SKIN_CLASSIC_COMMON_H
#define LIBARIA_WIDGET_SKIN_CLASSIC_COMMON_H
//DOM-IGNORE-END

#include "gfx/libaria/inc/libaria_widget.h"

#include "gfx/libaria/inc/libaria_context.h"
#include "gfx/libaria/inc/libaria_draw.h"

void laWidget_SkinClassic_FillRect(const GFX_Rect* rect,
                                   GFX_Color clr,
                                   const GFX_Rect* dmgRect);

void laWidget_SkinClassic_DrawBackground(laWidget* wgt, GFX_Color clr);
void laWidget_SkinClassic_DrawRoundCornerBackground(laWidget* wgt, GFX_Color clr);

void laWidget_SkinClassic_DrawStandardBackground(laWidget* wgt);

void laWidget_SkinClassic_DrawLineBorderLeft(const GFX_Rect* rect,
                                             GFX_Color clr,
                                             const GFX_Rect* dmgRect);
                                             
void laWidget_SkinClassic_DrawLineBorderTop(const GFX_Rect* rect,
                                            GFX_Color clr,
                                            const GFX_Rect* dmgRect);
                                            
void laWidget_SkinClassic_DrawLineBorderRight(const GFX_Rect* rect,
                                              GFX_Color clr,
                                              const GFX_Rect* dmgRect);
                                              
void laWidget_SkinClassic_DrawLineBorderBottom(const GFX_Rect* rect,
                                               GFX_Color clr,
                                               const GFX_Rect* dmgRect);
                                               
void laWidget_SkinClassic_DrawLineBorder(const GFX_Rect* rect,
                                         GFX_Color clr,
                                         const GFX_Rect* dmgRect);                                           

void laWidget_SkinClassic_DrawBevelBorderLeft(const GFX_Rect* rect,
                                              GFX_Color outer,
                                              GFX_Color inner,
                                              const GFX_Rect* dmgRect);

void laWidget_SkinClassic_DrawBevelBorderTop(const GFX_Rect* rect,
                                             GFX_Color outer,
                                             GFX_Color inner,
                                             const GFX_Rect* dmgRect);

void laWidget_SkinClassic_DrawBevelBorderRight(const GFX_Rect* rect,
                                               GFX_Color outer,
                                               GFX_Color inner,
                                               const GFX_Rect* dmgRect);

void laWidget_SkinClassic_DrawBevelBorderBottom(const GFX_Rect* rect,
                                                GFX_Color outer,
                                                GFX_Color inner,
                                                const GFX_Rect* dmgRect);
                                                
void laWidget_SkinClassic_Draw2x2BeveledBorder(const GFX_Rect* rect,
                                               GFX_Color leftUpOuter,
                                               GFX_Color leftUpInner,
                                               GFX_Color bottomRightOuter,
                                               GFX_Color bototmRightInner,
                                               const GFX_Rect* dmgRect);                                                

void laWidget_SkinClassic_Draw1x2BeveledBorder(const GFX_Rect* rect,
                                              GFX_Color leftUp,
                                              GFX_Color bottomRightOuter,
                                              GFX_Color bototmRightInner,
                                              const GFX_Rect* dmgRect);                                             

void laWidget_SkinClassic_DrawBlit(laWidget* wgt,
                                   GFX_PixelBuffer* buffer);
                                                
void laWidget_SkinClassic_DrawStandardLineBorder(laWidget* wgt);

void laWidget_SkinClassic_DrawStandardRoundCornerLineBorder(laWidget* wgt);
                                                
void laWidget_SkinClassic_DrawStandardRaisedBorder(laWidget* wgt);    

void laWidget_SkinClassic_DrawStandardLoweredBorder(laWidget* wgt);

void laWidget_SkinClassic_DrawStandardHybridBorder(laWidget* wgt);                             

void laWidget_SkinClassic_InvalidateBorderAreas(laWidget*);



#endif /* LIBARIA_WIDGET_SKIN_CLASSIC_COMMON_H */