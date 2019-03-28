/*******************************************************************************
  MPLAB Harmony Graphics Composer Generated Implementation File

  File Name:
    libaria_events.c

  Summary:
    Build-time generated implementation from the MPLAB Harmony
    Graphics Composer.

  Description:
    Build-time generated implementation from the MPLAB Harmony
    Graphics Composer.

    Created with MPLAB Harmony Version 3.0
*******************************************************************************/
// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/
// DOM-IGNORE-END

#include "gfx/libaria/libaria_events.h"
//CUSTOM CODE - DO NOT MODIFY OR REMOVE!!
#include "gfx/libaria/inc/libaria_utils.h"
#include "gfx/hal/inc/gfx_common.h"
#include "gfx/hal/inc/gfx_math.h"

#include "app.h"
//END OF CUSTOM CODE

// TachoDrawSurface - DrawNotificationEvent
laBool TachoDrawSurface_DrawNotificationEvent(laDrawSurfaceWidget* sfc, GFX_Rect* rect)
{
//CUSTOM CODE - DO NOT MODIFY OR REMOVE!!
    static GFX_Point start = {.x = 240, .y = 136}, end = {.x = 240, .y = 50};
    static GFX_Point startExt[6];
    
    GFX_Point newEnd;
    int value = GET_ANGLE_FROM_VALUE(appData.value);
    
    GFX_Set(GFXF_DRAW_MODE, GFX_DRAW_LINE);
    GFX_Set(GFXF_DRAW_COLOR, 0x00000000);
    GFX_DrawLine(start.x, start.y, end.x, end.y);
    GFX_DrawLine(startExt[0].x, startExt[0].y, end.x, end.y);
    GFX_DrawLine(startExt[1].x, startExt[1].y, end.x, end.y);
    GFX_DrawLine(startExt[2].x, startExt[2].y, end.x, end.y);
    GFX_DrawLine(startExt[3].x, startExt[3].y, end.x, end.y);
    GFX_DrawLine(startExt[4].x, startExt[2].y, end.x, end.y);
    GFX_DrawLine(startExt[5].x, startExt[3].y, end.x, end.y); 
    GFX_PolarToXY(86, value, &newEnd);
    end.x = newEnd.x + sfc->widget.rect.x + sfc->widget.rect.width/2;
    end.y = sfc->widget.rect.y + sfc->widget.rect.height/2 - newEnd.y;
    GFX_Set(GFXF_DRAW_COLOR, 0xff0000ff);
    GFX_DrawLine(start.x, start.y, end.x, end.y);
    
    if (value > 90 && value < 180)
    {
        startExt[0].x = start.x + 3;
        startExt[0].y = start.y - 3;
        startExt[1].x = start.x + 2;
        startExt[1].y = start.y - 2;
        startExt[2].x = start.x + 1;
        startExt[2].y = start.y - 1;
        startExt[3].x = start.x - 1;
        startExt[3].y = start.y + 1;
        startExt[4].x = start.x - 2;
        startExt[4].y = start.y + 2;
        startExt[5].x = start.x - 3;
        startExt[5].y = start.y + 3;      
    }
    else
    {
        startExt[0].x = start.x + 3;
        startExt[0].y = start.y + 3;      
        startExt[1].x = start.x + 2;
        startExt[1].y = start.y + 2;
        startExt[2].x = start.x + 1;
        startExt[2].y = start.y + 1;
        startExt[3].x = start.x - 1;
        startExt[3].y = start.y - 1;
        startExt[4].x = start.x - 2;
        startExt[4].y = start.y - 2;
        startExt[5].x = start.x - 3;
        startExt[5].y = start.y - 3;      
    }

    GFX_DrawLine(startExt[1].x, startExt[1].y, end.x, end.y);
    GFX_DrawLine(startExt[2].x, startExt[2].y, end.x, end.y);
    GFX_DrawLine(startExt[3].x, startExt[3].y, end.x, end.y);    
    GFX_DrawLine(startExt[4].x, startExt[4].y, end.x, end.y);    
    GFX_Set(GFXF_DRAW_COLOR, 0xffffffff);
    GFX_DrawLine(startExt[0].x, startExt[0].y, end.x, end.y);
    GFX_DrawLine(startExt[5].x, startExt[5].y, end.x, end.y);
    
    return GFX_TRUE;
//END OF CUSTOM CODE  
}

// EngineOnButton - PressedEvent
void EngineOnButton_PressedEvent(laButtonWidget* btn)
{
    // Custom Action
    appData.event = APP_EVENT_ENGINE_ON;
}

// EngineOnButton - ReleasedEvent
void EngineOnButton_ReleasedEvent(laButtonWidget* btn)
{
    // Custom Action
    appData.event = APP_EVENT_ENGINE_OFF;
}





