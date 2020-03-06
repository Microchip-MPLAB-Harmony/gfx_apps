// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2020 Microchip Technology Inc. and its subsidiaries.
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

#include "gfx/libaria/libaria_events.h"
#include "app.h"

// RPMDrawSurfaceWidget - DrawNotificationEvent
laBool RPMDrawSurfaceWidget_DrawNotificationEvent(laDrawSurfaceWidget* sfc, GFX_Rect* rect)
{
    // Custom Action
    #define IMAGE_WIDTH 250
    #define IMAGE_HEIGHT 250
    #define SCREEN_WIDTH 800
    #define SCREEN_HEIGHT 480
    #define POINTER_LENGTH 104
    
    extern const uint8_t needle_data[250000];
    
    GFX_Rect oldRect, newRect;
    uint32_t * writeBuffer;
    
    GFX_Point ptSource, ptDest, ptDest2;
    GFX_Color color = 0;
    int16_t sin256, cos256;
    GFX_Point ptPointerTip;
    GFX_Context* context = GFX_ActiveContext();
    
    GFX_Point ptCenter = {.x = 125, .y = 125};
    
    GFX_Rect sourceRect = {.x = 0, 
                           .y = 0,
                           .height = IMAGE_HEIGHT,
                           .width = IMAGE_WIDTH};
    
    GFX_Rect centerRect = {.x = 104, 
                           .y = 104,
                           .height = 40,
                           .width = 40};
    
    static int oldAngle = 0;
    int newAngle = APP_GetValueAngle();
    
    GFX_Set(GFXF_LAYER_ACTIVE, context->layer.active->id);
    GFX_Get(GFXF_LAYER_BUFFER_ADDRESS,
            context->layer.active->buffer_write_idx,
            (GFX_Buffer *) &writeBuffer);
    
    GFX_PolarToXY(POINTER_LENGTH , oldAngle, &ptPointerTip);
    ptPointerTip.x += ptCenter.x;
    ptPointerTip.y = ptCenter.y - ptPointerTip.y;
    oldRect = GFX_RectFromPoints(&ptPointerTip, &ptCenter);
    oldRect = GFX_RectCombine(&oldRect, &centerRect);
    
    GFX_PolarToXY(POINTER_LENGTH, newAngle, &ptPointerTip);
    ptPointerTip.x += ptCenter.x;
    ptPointerTip.y = ptCenter.y - ptPointerTip.y;
    newRect = GFX_RectFromPoints(&ptPointerTip, &ptCenter);
    newRect = GFX_RectCombine(&newRect, &centerRect);
    
    oldAngle = newAngle;
    
    sin256 =  GFX_SineCosineGet(-newAngle, GFX_TRIG_SINE_TYPE);
    cos256 =  GFX_SineCosineGet(-newAngle, GFX_TRIG_COSINE_TYPE);
    
    GFX_Set(GFXF_DRAW_CLIP_RECT, rect);
    GFX_Set(GFXF_DRAW_CLIP_ENABLE, GFX_TRUE);
    
    //Clear the old rect
    if (GFX_RectCompare(&oldRect, &newRect) == 0)
    {
        GFX_Set(GFXF_DRAW_COLOR, 0x0);
        GFX_Set(GFXF_DRAW_MODE, GFX_DRAW_FILL);
        laUtils_RectToLayerSpace((laWidget *) sfc, &oldRect);
        GFX_DrawRect(oldRect.x, oldRect.y, oldRect.width, oldRect.height);
    
    }
    
    //Scan thru the pixels to right, bottom and find the source pixel in original image
    for (ptDest.y = newRect.y;
         ptDest.y < newRect.y + newRect.height;
         ptDest.y++)
    {
        for (ptDest.x = newRect.x;
             ptDest.x < newRect.x + newRect.width;
             ptDest.x++)
        {
            ptSource.x = ((ptDest.x - ptCenter.x) * cos256 + 
                          (ptDest.y - ptCenter.y) * sin256) / 256 + 
                          ptCenter.x;
            ptSource.y = (-(ptDest.x - ptCenter.x) * sin256 + 
                           (ptDest.y - ptCenter.y)* cos256) / 256 +
                          ptCenter.y;
    
            if (GFX_RectContainsPoint(&sourceRect, &ptSource))
            {
                color = getImagePixelGaussianBlur3x3((uint32_t *) needle_data,
                                             IMAGE_WIDTH,
                                             IMAGE_HEIGHT,
                                             ptSource);
            }
    
            GFX_Set(GFXF_DRAW_COLOR, color);
    
            ptDest2 = ptDest;
    
            laUtils_PointToLayerSpace((laWidget *) sfc, &ptDest2);
            writeBuffer[SCREEN_WIDTH * ptDest2.y + ptDest2.x] = color;
            //GFX_DrawPixel(ptDest2.x, ptDest2.y);
        }
    }
    
    return LA_TRUE;
}

// SpeedDrawSurfaceWidget - DrawNotificationEvent
laBool SpeedDrawSurfaceWidget_DrawNotificationEvent(laDrawSurfaceWidget* sfc, GFX_Rect* rect)
{
    // Custom Action
    #define IMAGE_WIDTH 250
    #define IMAGE_HEIGHT 250
    #define SCREEN_WIDTH 800
    #define SCREEN_HEIGHT 480
    #define POINTER_LENGTH 104
    
    extern const uint8_t needle2_data[250000];
    
    GFX_Rect oldRect, newRect;
    uint32_t * writeBuffer;
    
    GFX_Point ptSource, ptDest, ptDest2;
    GFX_Color color = 0;
    int16_t sin256, cos256;
    GFX_Point ptPointerTip;
    GFX_Context* context = GFX_ActiveContext();
    
    GFX_Point ptCenter = {.x = 125, .y = 125};
    
    GFX_Rect sourceRect = {.x = 0, 
                           .y = 0,
                           .height = IMAGE_HEIGHT,
                           .width = IMAGE_WIDTH};
    
    GFX_Rect centerRect = {.x = 104, 
                           .y = 104,
                           .height = 40,
                           .width = 40};
    
    static int oldAngle = 0;
    int newAngle = APP_GetSpeedAngle();
    
    GFX_Set(GFXF_LAYER_ACTIVE, context->layer.active->id);
    GFX_Get(GFXF_LAYER_BUFFER_ADDRESS,
            context->layer.active->buffer_write_idx,
            (GFX_Buffer *) &writeBuffer);
    
    GFX_PolarToXY(POINTER_LENGTH , oldAngle, &ptPointerTip);
    ptPointerTip.x += ptCenter.x;
    ptPointerTip.y = ptCenter.y - ptPointerTip.y;
    oldRect = GFX_RectFromPoints(&ptPointerTip, &ptCenter);
    oldRect = GFX_RectCombine(&oldRect, &centerRect);
    
    GFX_PolarToXY(POINTER_LENGTH, newAngle, &ptPointerTip);
    ptPointerTip.x += ptCenter.x;
    ptPointerTip.y = ptCenter.y - ptPointerTip.y;
    newRect = GFX_RectFromPoints(&ptPointerTip, &ptCenter);
    newRect = GFX_RectCombine(&newRect, &centerRect);
    
    oldAngle = newAngle;
    
    sin256 =  GFX_SineCosineGet(-newAngle, GFX_TRIG_SINE_TYPE);
    cos256 =  GFX_SineCosineGet(-newAngle, GFX_TRIG_COSINE_TYPE);
    
    GFX_Set(GFXF_DRAW_CLIP_RECT, rect);
    GFX_Set(GFXF_DRAW_CLIP_ENABLE, GFX_TRUE);
    
    //Clear the old rect
    if (GFX_RectCompare(&oldRect, &newRect) == 0)
    {
        GFX_Set(GFXF_DRAW_COLOR, 0x0);
        GFX_Set(GFXF_DRAW_MODE, GFX_DRAW_FILL);
        laUtils_RectToLayerSpace((laWidget *) sfc, &oldRect);
        GFX_DrawRect(oldRect.x, oldRect.y, oldRect.width, oldRect.height);
    
    }
    
    //Scan thru the pixels to right, bottom and find the source pixel in original image
    for (ptDest.y = newRect.y;
         ptDest.y < newRect.y + newRect.height;
         ptDest.y++)
    {
        for (ptDest.x = newRect.x;
             ptDest.x < newRect.x + newRect.width;
             ptDest.x++)
        {
            ptSource.x = ((ptDest.x - ptCenter.x) * cos256 + 
                          (ptDest.y - ptCenter.y) * sin256) / 256 + 
                          ptCenter.x;
            ptSource.y = (-(ptDest.x - ptCenter.x) * sin256 + 
                           (ptDest.y - ptCenter.y)* cos256) / 256 +
                          ptCenter.y;
    
            if (GFX_RectContainsPoint(&sourceRect, &ptSource))
            {
                color = getImagePixelGaussianBlur3x3((uint32_t *) needle2_data,
                                             IMAGE_WIDTH,
                                             IMAGE_HEIGHT,
                                             ptSource);
            }
    
            GFX_Set(GFXF_DRAW_COLOR, color);
    
            ptDest2 = ptDest;
    
            laUtils_PointToLayerSpace((laWidget *) sfc, &ptDest2);
            writeBuffer[SCREEN_WIDTH * ptDest2.y + ptDest2.x] = color;
        }
    }
    
    return LA_TRUE;
}

// CenterButtonWidget - PressedEvent
void CenterButtonWidget_PressedEvent(laButtonWidget* btn)
{
    // Custom Action
    
}

// CenterButtonWidget - ReleasedEvent
void CenterButtonWidget_ReleasedEvent(laButtonWidget* btn)
{
    // Custom Action
    
}

// EngineOnButton - PressedEvent
void EngineOnButton_PressedEvent(laButtonWidget* btn)
{
    // Custom Action
    APP_Send_Event(APP_EVENT_ENGINE_ON);
}

// EngineOnButton - ReleasedEvent
void EngineOnButton_ReleasedEvent(laButtonWidget* btn)
{
    // Custom Action
    APP_Send_Event(APP_EVENT_ENGINE_OFF);
}





