/*******************************************************************************
  MPLAB Harmony Nano2D Generated HAL Wrapper

  File Name:
    libnano2D_hal.c

  Summary:
    Build-time generated implementation for the Nano2D Generated HAL Wrapper.

  Description:
    Build-time generated implementation for the Nano2D Generated HAL Wrapper.

    Created with MPLAB Harmony Version 2.03
*******************************************************************************/
// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2019 released Microchip Technology Inc.  All rights reserved.

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

#include "gfx/hal/inc/gfx_common.h"
#include "gfx/hal/inc/gfx_processor_interface.h"
#include "gfx/driver/processor/gfx2d/drv_gfx2d.h"

//#include <xc.h>
//#include <sys/attribs.h>
//#include <sys/kmem.h>

const char* driverName = "GFX 2D";

#define CMD_BUFFER_SIZE  8192
uint32_t __attribute__((coherent, aligned(32))) commandBuffer[CMD_BUFFER_SIZE];

// GPU command buffer seems to work better when placed in DDR
//#define CMD_BUFFER_DDR_ADDRESS 0xA9E00000


GFX2D_PIXEL_FORMAT p2dFormats[GFX_COLOR_MODE_COUNT] =
{
    -1, // GFX_COLOR_MODE_GS_8
    -1, // GFX_COLOR_MODE_RGB_332,
    GFX2D_RGB16, // GFX_COLOR_MODE_RGB_565
    -1, // GFX_COLOR_MODE_RGBA_5551
    -1, // GFX_COLOR_MODE_RGB_888
    GFX2D_ARGB32, // GFX_COLOR_MODE_RGBA_8888
    -1, // GFX_COLOR_MODE_ARGB_8888
    -1, // GFX_COLOR_MODE_YUV
    -1, // GFX_COLOR_MODE_INDEX_1
    -1, //GFX_COLOR_MODE_INDEX_4
    -1, // GFX_COLOR_MODE_INDEX_8
};

static GFX_Result drawLine(const GFX_Point* p1,
                           const GFX_Point* p2,
                           const GFX_DrawState* state)
{
    struct gpu_buffer    buffer;
    GFX_Rect lrect;
    GFX2D_TRANSFER_DIRECTION orientation = GFX2D_XY00;
    GFX_Context* context = GFX_ActiveContext();

    // return failure if line is not horizonal or vertical line
    if(p1->x != p2->x && p1->y != p2->y)
        return GFX_FAILURE;  

    switch(context->orientation)
    {
        case GFX_ORIENTATION_0:
        {
            orientation = GFX2D_XY00;
            break;
        }
        case GFX_ORIENTATION_90:
        {
            orientation = GFX2D_XY01;
            break;
        }
        case GFX_ORIENTATION_180:
        {
            orientation = GFX2D_XY10;
            break;
        }
        case GFX_ORIENTATION_270:
        {
            orientation = GFX2D_XY11;
            break;
        }
    }

    buffer.width = state->target->size.width;
    buffer.height = state->target->size.height;
    buffer.format = p2dFormats[state->target->mode];
    buffer.dir = orientation;
    buffer.addr = (uint32_t)state->target->pixels;
    
    lrect.x = p1->x; 
    lrect.y = p1->y;
    lrect.width = p2->x;
    lrect.height = p2->y;
    
    DRV_GFX2D_Fill(&buffer,
             (GFX2D_RECTANGLE*)&lrect,
             GFX_ColorConvert(state->colorMode, GFX_COLOR_MODE_ARGB_8888, state->color));
    
    return GFX_SUCCESS;
}

static GFX_Result fillRect(const GFX_Rect* rect,
                           const GFX_DrawState* state)
{
    struct gpu_buffer    buffer;
    //GFX2D_RECTANGLE rect;
    GFX_Rect lrect;
    GFX2D_TRANSFER_DIRECTION orientation = GFX2D_XY00;
    GFX_Context* context = GFX_ActiveContext();

#if GFX_LAYER_CLIPPING_ENABLED || GFX_BOUNDS_CLIPPING_ENABLED
    GFX_Rect clipRect;
#endif

    lrect = *rect;
    
#if GFX_LAYER_CLIPPING_ENABLED
    // clip rect against target rect
    GFX_RectClip(&state->targetClipRect,
                 &lrect,
                 &clipRect);
                 
    lrect = clipRect;        
#endif
    
#if GFX_BOUNDS_CLIPPING_ENABLED
    if((state->clipEnable == GFX_TRUE) && 
        GFX_RectIntersects(&state->clipRect, &lrect) == GFX_FALSE)
        return GFX_FAILURE;
        
    // clip rect against global clipping rect
    if(state->clipEnable == GFX_TRUE)
    {
        GFX_RectClip(&state->clipRect,
                     &lrect,
                     &clipRect);
                     
        lrect = clipRect; 
    }
#endif   

    switch(context->orientation)
    {
        case GFX_ORIENTATION_0:
        {
            orientation = GFX2D_XY00;
            break;
        }
        case GFX_ORIENTATION_90:
        {
            orientation = GFX2D_XY01;
            break;
        }
        case GFX_ORIENTATION_180:
        {
            orientation = GFX2D_XY10;
            break;
        }
        case GFX_ORIENTATION_270:
        {
            orientation = GFX2D_XY11;
            break;
        }
    }

    buffer.width = state->target->size.width;
    buffer.height = state->target->size.height;
    buffer.format = p2dFormats[state->target->mode];
    buffer.dir = GFX2D_XY01;
    buffer.addr = (uint32_t)state->target->pixels;
    
    DRV_GFX2D_Fill(&buffer,
             (GFX2D_RECTANGLE*)&lrect,
             GFX_ColorConvert(state->colorMode, GFX_COLOR_MODE_ARGB_8888, state->color));
    
    return GFX_SUCCESS;
}

/*
static GFX_Result drawBlit(const GFX_PixelBuffer* source,
                           const GFX_Rect* srcRect,
                           const GFX_Point* drawPoint,
                           const GFX_DrawState* state)
{
    n2d_buffer_t src_buffer, dest_buffer;
    GFX_Rect dest_rect;
    n2d_orientation_t orientation = N2D_0;
    GFX_Context* context = GFX_ActiveContext();
    n2d_blend_t blend = N2D_BLEND_NONE;

    // the source address must reside in KSEG1 (cache coherent) memory
    // and the source buffer must be raw pixels as the the GPU doesn't
    // understand palettized blits
    // if this fails then fall back to software mode
    if(IS_KVA1(source->pixels) == GFX_FALSE ||
       GFX_COLOR_MODE_IS_INDEX(source->mode) == GFX_TRUE ||
       GFX_COLOR_MODE_IS_INDEX(state->target->mode) == GFX_TRUE ||
       n2dFormats[source->mode] == -1 ||
       n2dFormats[state->colorMode] == -1)
        return cpuDrawBlit(source, srcRect, drawPoint, state);
    
    switch(context->orientation)
    {
        case GFX_ORIENTATION_0:
            orientation = N2D_0;
            break;

        case GFX_ORIENTATION_90:
        {
            orientation = N2D_90;
            break;
        }
        case GFX_ORIENTATION_180:
        {
            orientation = N2D_180;
            break;
        }
        case GFX_ORIENTATION_270:
        {
            orientation = N2D_270;
            break;
        }
    }

    // craft source buffer descriptor
    src_buffer.width = source->size.width;
    src_buffer.height = source->size.height;
    src_buffer.stride = source->size.width * GFX_ColorInfo[source->mode].size;
    src_buffer.format = n2dFormats[source->mode];
    src_buffer.orientation = orientation;
    src_buffer.handle = NULL;
    src_buffer.memory = source->pixels;
    src_buffer.gpu = KVA_TO_PA(source->pixels);
       
    // craft dest buffer descriptor
    dest_buffer.width = state->target->size.width;
    dest_buffer.height = state->target->size.height;
    dest_buffer.stride = state->target->size.width * GFX_ColorInfo[state->colorMode].size;
    dest_buffer.format = n2dFormats[state->target->mode];
    dest_buffer.orientation = orientation;
    dest_buffer.handle = NULL;
    dest_buffer.memory = state->target->pixels;
    dest_buffer.gpu = KVA_TO_PA(state->target->pixels);
    
    dest_rect.x = drawPoint->x;
    dest_rect.y = drawPoint->y;
    dest_rect.width = srcRect->width;
    dest_rect.height = srcRect->height;
    
    if(state->maskEnable == GFX_TRUE)
    {
        n2d_color_t color = (n2d_color_t)GFX_ColorConvert(state->colorMode, GFX_COLOR_MODE_ARGB_8888, state->maskValue);
        
        n2d_draw_state(N2D_TRANSPARENCY_SOURCE,
                       color,
                       0xA,
                       0xC);        
    }    

    if ((state->alphaEnable == GFX_TRUE) && 
        ((state->blendMode & GFX_BLEND_CHANNEL) == 0))
    {
        n2d_set_global_alpha(N2D_GLOBAL_ALPHA_ON, N2D_GLOBAL_ALPHA_OFF, state->globalAlphaValue, 0xff);
        blend = N2D_BLEND_SRC_OVER;
    }

    n2d_blit(&dest_buffer,
             (n2d_rectangle_t*)&dest_rect,
             &src_buffer,
             (n2d_rectangle_t*)srcRect,
             blend);

    if(state->maskEnable == GFX_TRUE)
    {
        n2d_draw_state(N2D_TRANSPARENCY_NONE, 0, 0xC, 0xC);
    }

    if ((state->alphaEnable == GFX_TRUE) && 
        ((state->blendMode & GFX_BLEND_CHANNEL) == 0))
    {
        n2d_set_global_alpha(N2D_GLOBAL_ALPHA_OFF, N2D_GLOBAL_ALPHA_OFF, 0xff, 0xff);
        blend = N2D_BLEND_NONE;
    }
    
    return GFX_SUCCESS;
}

static GFX_Result drawStretchBlit(const GFX_PixelBuffer* source,
                                  const GFX_Rect* srcRect,
                                  const GFX_Rect* destRect,
                                  const GFX_DrawState* state)
{
    n2d_buffer_t src_buffer, dest_buffer;
    n2d_orientation_t orientation = N2D_0;
    GFX_Context* context = GFX_ActiveContext();
    n2d_blend_t blend = N2D_BLEND_NONE;

    // the source address must reside in KSEG1 (cache coherent) memory
    // and the source buffer must be raw pixels as the the GPU doesn't
    // understand palettized blits
    // if this fails then fall back to software mode
    if(IS_KVA1(source->pixels) == GFX_FALSE ||
       GFX_COLOR_MODE_IS_INDEX(source->mode) == GFX_TRUE ||
       GFX_COLOR_MODE_IS_INDEX(state->target->mode) == GFX_TRUE ||
       n2dFormats[source->mode] == -1 ||
       n2dFormats[state->colorMode] == -1)
        return cpuDrawStretchBlit_NearestNeighbor(source, srcRect, destRect, state);
    
    switch(context->orientation)
    {
        case GFX_ORIENTATION_0:
            orientation = N2D_0;
            break;

        case GFX_ORIENTATION_90:
        {
            orientation = N2D_90;
            break;
        }
        case GFX_ORIENTATION_180:
        {
            orientation = N2D_180;
            break;
        }
        case GFX_ORIENTATION_270:
        {
            orientation = N2D_270;
            break;
        }
    }

    // craft source buffer descriptor
    src_buffer.width = source->size.width;
    src_buffer.height = source->size.height;
    src_buffer.stride = source->size.width * GFX_ColorInfo[source->mode].size;
    src_buffer.format = n2dFormats[source->mode];
    src_buffer.orientation = orientation;
    src_buffer.handle = NULL;
    src_buffer.memory = source->pixels;
    src_buffer.gpu = KVA_TO_PA(source->pixels);
       
    // craft dest buffer descriptor
    dest_buffer.width = state->target->size.width;
    dest_buffer.height = state->target->size.height;
    dest_buffer.stride = state->target->size.width * GFX_ColorInfo[state->colorMode].size;
    dest_buffer.format = n2dFormats[state->target->mode];
    dest_buffer.orientation = orientation;
    dest_buffer.handle = NULL;
    dest_buffer.memory = state->target->pixels;
    dest_buffer.gpu = KVA_TO_PA(state->target->pixels);
    
    if(state->maskEnable == GFX_TRUE)
    {
        n2d_color_t color = (n2d_color_t)GFX_ColorConvert(state->colorMode, GFX_COLOR_MODE_ARGB_8888, state->maskValue);
        
        n2d_draw_state(N2D_TRANSPARENCY_SOURCE,
                       color,
                       0xA,
                       0xC);        
    }    

    if ((state->alphaEnable == GFX_TRUE) && 
        ((state->blendMode & GFX_BLEND_CHANNEL) == 0))
    {
        n2d_set_global_alpha(N2D_GLOBAL_ALPHA_ON, N2D_GLOBAL_ALPHA_OFF, state->globalAlphaValue, 0xff);
        blend = N2D_BLEND_SRC_OVER;
    }

    n2d_blit(&dest_buffer,
             (n2d_rectangle_t*)destRect,
             &src_buffer,
             (n2d_rectangle_t*)srcRect,
             blend);

    if(state->maskEnable == GFX_TRUE)
    {
        n2d_draw_state(N2D_TRANSPARENCY_NONE, 0, 0xC, 0xC);
    }

    if ((state->alphaEnable == GFX_TRUE) && 
        ((state->blendMode & GFX_BLEND_CHANNEL) == 0))
    {
        n2d_set_global_alpha(N2D_GLOBAL_ALPHA_OFF, N2D_GLOBAL_ALPHA_OFF, 0xff, 0xff);
        blend = N2D_BLEND_NONE;
    }
    
    return GFX_SUCCESS;
}
*/

// function that returns the information for this driver
GFX_Result procGFX2DInfoGet(GFX_ProcessorInfo* info)
{
	if(info == NULL)
        return GFX_FAILURE;

	// populate info struct
    strcpy(info->name, driverName);
    info->color_formats = GFX_COLOR_MASK_ARGB_8888;
    
    return GFX_SUCCESS;
}

// function that initialized the driver context
GFX_Result procGFX2DContextInitialize(GFX_Context* context)
{
    /* initialize gpu hardware and peripheral software */
    DRV_GFX2D_Initialize();

	// GPU Pipeline
        //context->hal.drawPipeline[GFX_PIPELINE_GPU].drawLine[GFX_DRAW_LINE][GFX_ANTIALIAS_OFF] = &drawLine;
        //context->hal.drawPipeline[GFX_PIPELINE_GPU].drawLine[GFX_DRAW_FILL][GFX_ANTIALIAS_OFF] = &drawLine;
	
	context->hal.drawPipeline[GFX_PIPELINE_GPU].drawRect[GFX_DRAW_FILL][GFX_ANTIALIAS_OFF] = &fillRect;
	
        //context->hal.drawPipeline[GFX_PIPELINE_GPU].drawBlit = &drawBlit;
		
    // according to nano2d documentation the stretch blit is a fast resize, override nearest neighbor version
    //context->hal.drawPipeline[GFX_PIPELINE_GPU].drawStretchBlit[GFX_RESIZE_NEARESTNEIGHBOR] = &drawStretchBlit;
		
	// GCU/GPU Pipeline
        //context->hal.drawPipeline[GFX_PIPELINE_GCUGPU].drawLine[GFX_DRAW_LINE][GFX_ANTIALIAS_OFF] = &drawLine;
        //context->hal.drawPipeline[GFX_PIPELINE_GCUGPU].drawLine[GFX_DRAW_FILL][GFX_ANTIALIAS_OFF] = &drawLine;
	
	context->hal.drawPipeline[GFX_PIPELINE_GCUGPU].drawRect[GFX_DRAW_FILL][GFX_ANTIALIAS_OFF] = &fillRect;
	
        //context->hal.drawPipeline[GFX_PIPELINE_GCUGPU].drawBlit = &drawBlit;
	
    // according to nano2d documentation the stretch blit is a fast resize, override nearest neighbor version
    //context->hal.drawPipeline[GFX_PIPELINE_GCUGPU].drawStretchBlit[GFX_RESIZE_NEARESTNEIGHBOR] = &drawStretchBlit;
	
	return GFX_SUCCESS;
}
