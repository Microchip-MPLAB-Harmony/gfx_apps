/********************************************************************************
  GFX GLCD Driver Functions for Static Single Instance Driver

  Company:
    Microchip Technology Inc.

  File Name:
    drv_gfx_glcd.c

  Summary:
    Source code for the GFX GLCD driver static implementation.

  Description:
    This file contains the source code for the static implementation of the
    GFX GLCD driver.
*******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2017 released Microchip Technology Inc.  All rights reserved.

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

#include <stdint.h>
#include <stdbool.h>
#include "peripheral/evic/plib_evic.h"
#include "gfx/driver/controller/glcd/plib_glcd.h"
#include "gfx/driver/controller/glcd/drv_gfx_glcd.h"
#include "definitions.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data
// *****************************************************************************
// *****************************************************************************

#define BUFFER_PER_LAYER    2

#define DISPLAY_WIDTH  480
#define DISPLAY_HEIGHT 272
#define GFX_GLCD_LAYERS 3
#define GFX_GLCD_BACKGROUND_COLOR 0xFFFFFF00
#define GFX_GLCD_CONFIG_CONTROL 0x80000000
#define GFX_GLCD_CONFIG_CLK_DIVIDER 16

/*** GLCD Layer 0 Configuration ***/
#define  GFX_GLCD_LAYER0_BASEADDR                      0xA827D800
#define  GFX_GLCD_LAYER0_DBL_BASEADDR                  0xA81FE000
/*** GLCD Layer 1 Configuration ***/
#define  GFX_GLCD_LAYER1_BASEADDR                      0xA817E800
#define  GFX_GLCD_LAYER1_DBL_BASEADDR                  0xA80FF000
/*** GLCD Layer 2 Configuration ***/
#define  GFX_GLCD_LAYER2_BASEADDR                      0xA807F800
#define  GFX_GLCD_LAYER2_DBL_BASEADDR                  0xA8000000

#define LCDC_DEFAULT_GFX_COLOR_MODE GFX_COLOR_MODE_RGBA_8888
#define FRAMEBUFFER_PTR_TYPE    uint32_t*
#define FRAMEBUFFER_PIXEL_TYPE    uint32_t

const char* DRIVER_NAME = "GLCD";
static uint32_t supported_color_format = (GFX_COLOR_MASK_GS_8 |
                                          GFX_COLOR_MASK_RGB_565 | 
                                          GFX_COLOR_MASK_RGBA_8888);

uint32_t state;

volatile int32_t waitForAlphaSetting[GFX_GLCD_LAYERS] = {0};

//Layer Parameters
//--------------------------------------------------------------------------
typedef struct __display_layer {
    FRAMEBUFFER_PTR_TYPE  baseaddr[BUFFER_PER_LAYER];
    int        draw;
    int        frame;
    uint32_t   resx;
    uint32_t   resy;
    uint32_t   buscfg;
    uint32_t   format;
    uint32_t   stride;
    uint32_t   startx;
    uint32_t   starty;
    uint32_t   sizex;
    uint32_t   sizey;
    uint32_t   alpha;
    uint32_t   dblend;
    uint32_t   sblend;
    uint32_t   colorspace;
    uint16_t   color;
} DISPLAY_LAYER;
static DISPLAY_LAYER drvLayer[GFX_GLCD_LAYERS];


/**** Hardware Abstraction Interfaces ****/
enum
{
    INIT = 0,
    RUN
};

static int DRV_GFX_GLCD_Start();

GFX_Context* cntxt;

volatile GFX_Bool waitingForVSync;

// function that returns the information for this driver
GFX_Result driverGLCDInfoGet(GFX_DriverInfo* info)
{
    if(info == NULL)
    return GFX_FAILURE;

    // populate info struct
    strcpy(info->name, DRIVER_NAME);
    info->color_formats = supported_color_format;
    info->layer_count = GFX_GLCD_LAYERS;

    return GFX_SUCCESS;
}

static GFX_Result glcdUpdate()
{
    GFX_Context* context = GFX_ActiveContext();

    if(context == NULL)
        return GFX_FAILURE;

    if(state == INIT)
    {
        if(DRV_GFX_GLCD_Start() != 0)
            return GFX_FAILURE;

        state = RUN;
    }

    return GFX_SUCCESS;
}

static void glcdDestroy(GFX_Context* context)
{
    // driver specific shutdown tasks
    if(context->driver_data != GFX_NULL)
    {
        context->memory.free(context->driver_data);
        context->driver_data = GFX_NULL;
    }

    // general default shutdown
    defDestroy(context);
}

static GLCD_LAYER_COLOR_MODE convertColorModeGfxToGLCD(GFX_ColorMode mode)
{
    switch(mode)
    {
        case GFX_COLOR_MODE_GS_8:
            return GLCD_LAYER_COLOR_MODE_LUT8;
            break;
        case GFX_COLOR_MODE_RGB_332:
            return GLCD_LAYER_COLOR_MODE_RGB332;
            break;
        case GFX_COLOR_MODE_RGB_565:
            return GLCD_LAYER_COLOR_MODE_RGB565;
            break;
        case GFX_COLOR_MODE_RGB_888:
            return GLCD_LAYER_COLOR_MODE_RGB888;
            break;
        case GFX_COLOR_MODE_RGBA_8888:
            return GLCD_LAYER_COLOR_MODE_RGBA8888;
            break;
        case GFX_COLOR_MODE_ARGB_8888:
            return GLCD_LAYER_COLOR_MODE_ARGB8888;
            break;
        case GFX_COLOR_MODE_INDEX_1:
            return GLCD_LAYER_COLOR_MODE_L1;
            break;
        case GFX_COLOR_MODE_INDEX_4:
            return GLCD_LAYER_COLOR_MODE_L4;
            break;
        case GFX_COLOR_MODE_INDEX_8:
            return GLCD_LAYER_COLOR_MODE_L8;
            break;
        default:
            return GLCD_LAYER_COLOR_MODE_RGBA8888;
            break;
                        
    }
}

static uint32_t getColorModeStrideSize(GLCD_LAYER_COLOR_MODE mode)
{
    switch(mode)
    {
        case GLCD_LAYER_COLOR_MODE_LUT8:
            return sizeof(uint8_t);
            break;
        case GLCD_LAYER_COLOR_MODE_RGB332:
            return sizeof(uint8_t);
            break;
        case GLCD_LAYER_COLOR_MODE_RGB565:
            return sizeof(uint16_t);
            break;
        case GLCD_LAYER_COLOR_MODE_RGB888:
            return sizeof(uint32_t);
            break;
        case GLCD_LAYER_COLOR_MODE_RGBA8888:
            return sizeof(uint32_t);
            break;
        case GLCD_LAYER_COLOR_MODE_ARGB8888:
            return sizeof(uint32_t);
            break;
        case GLCD_LAYER_COLOR_MODE_L1:
            return sizeof(uint8_t);
            break;
        case GLCD_LAYER_COLOR_MODE_L4:
            return sizeof(uint8_t);
            break;
        case GLCD_LAYER_COLOR_MODE_L8:
            return sizeof(uint8_t);
            break;
        default:
            return sizeof(uint32_t);
            break;
                        
    }
}


static GFX_Result colorModeSet(GFX_ColorMode mode)
{
    GFX_Layer* layer;
    GFX_Context* context = GFX_ActiveContext();
    GLCD_LAYER_COLOR_MODE glcdMode;
    uint32_t stride = 0;
    
    layer = context->layer.active;
    
   
    // use default implementation to initialize buffer struct
    defColorModeSet(mode);
    
    // ensure all buffers are marked as managed by the driver so application
    // can't delete or modify them
    
    //Translate
    //GFX->GLCD
    glcdMode = convertColorModeGfxToGLCD(mode);
    stride = getColorModeStrideSize(glcdMode);
    
    //Update the active layer's color mode and stride
    drvLayer[layer->id].colorspace = glcdMode;

    PLIB_GLCD_LayerColorModeSet(layer->id, drvLayer[layer->id].colorspace);
    PLIB_GLCD_LayerStrideSet(layer->id, drvLayer[layer->id].resx * stride);

    return GFX_SUCCESS;
}

static GFX_Result layerBufferCountSet(uint32_t count)
{
    GFX_Layer* layer;
    GFX_Context* context = GFX_ActiveContext();
    uint32_t i;
    
    layer = context->layer.active;
    
    if(count > BUFFER_PER_LAYER)
    {
    count = BUFFER_PER_LAYER;
    }
    
    // use default implementation to initialize buffer struct
    defLayerBufferCountSet(count);
    
    // ensure all buffers are marked as managed by the driver so application
    // can't delete or modify them
    for(i = 0; i < layer->buffer_count; i++)
    {
        GFX_PixelBufferCreate(layer->rect.display.width,
                  layer->rect.display.height,
                  context->colorMode,
                  drvLayer[layer->id].baseaddr[i],
                  &layer->buffers[i].pb);

        layer->buffers[i].state = GFX_BS_MANAGED;
    }
    
    // ensure GLCD buffers are in-sync with the library
    PLIB_GLCD_LayerBaseAddressSet(layer->id, (uint32_t)drvLayer[layer->id].baseaddr[layer->buffer_read_idx]);

    return GFX_SUCCESS;
}

static GFX_Result layerBufferAddressSet(uint32_t idx, GFX_Buffer address)
{
    GFX_Layer* layer;
    GFX_Context* context = GFX_ActiveContext();
    
    if (address == NULL || idx >= BUFFER_PER_LAYER)
    {
        return GFX_FAILURE;
    }
    
    layer = context->layer.active;

    //No need to call default address set as this is driver managed
    //defLayerBufferAddressSet(idx, address);
    
    drvLayer[layer->id].baseaddr[idx] = address;

    PLIB_GLCD_LayerBaseAddressSet(layer->id, (uint32_t)drvLayer[layer->id].baseaddr[idx]);
    
    return GFX_SUCCESS;
}

static GFX_Result layerBufferAllocate(uint32_t idx)
{
    GFX_Layer* layer;
    GFX_Context* context = GFX_ActiveContext();
    uint32_t  i,j;
    uint32_t  color = 0;
    
    layer = context->layer.active;

    if (layer->id == 0)
    {
        color = GFX_GLCD_BACKGROUND_COLOR;
    }
    
    for(i = 0; i < layer->rect.display.height; i++)
    {
        for(j = 0; j < layer->rect.display.width; j++)
    {
            *(uint32_t*)(drvLayer[layer->id].baseaddr[idx] + i*layer->rect.display.width + j) = color;
    }
    }
    return GFX_SUCCESS;
}

static GFX_Result layerBufferFree(uint32_t idx)
{
    return GFX_UNSUPPORTED;
}

static GFX_Result layerPositionSet(int32_t x, int32_t y)
{
    uint32_t idx;
    
    idx = GFX_ActiveContext()->layer.active->id;

    defLayerPositionSet(x, y);    
    
    PLIB_GLCD_LayerStartXYSet(idx,
                              GFX_ActiveContext()->layer.active->rect.display.x,
                              GFX_ActiveContext()->layer.active->rect.display.y);

    return GFX_SUCCESS;
}

static GFX_Result layerSizeSet(int32_t width, int32_t height)
{
    uint32_t idx;
    
    idx = GFX_ActiveContext()->layer.active->id;

    defLayerSizeSet(width, height);
        
    PLIB_GLCD_LayerSizeXYSet(idx,
                             GFX_ActiveContext()->layer.active->rect.display.width,
                             GFX_ActiveContext()->layer.active->rect.display.height);

    return GFX_SUCCESS;    
}

static GFX_Result layerAlphaAmountSet(uint32_t alpha, GFX_Bool wait)
{
    uint32_t idx;
    
    idx = GFX_ActiveContext()->layer.active->id;

    if(wait == GFX_TRUE)
    {
        waitForAlphaSetting[idx] = alpha;
    }
    else
    {
        waitForAlphaSetting[idx] = -1;
        
        defLayerAlphaAmountSet(alpha, wait);

        PLIB_GLCD_LayerGlobalAlphaSet(idx, alpha);
    }
    
    return GFX_SUCCESS;
}
    
static uint32_t layerAlphaAmountGet(void)
{
    uint32_t idx;
    
    idx = GFX_ActiveContext()->layer.active->id;

    return PLIB_GLCD_LayerGlobalAlphaGet(idx);
}

void layerSwapped(GFX_Layer* layer)
{
    if (layer->buffer_count > BUFFER_PER_LAYER)
        return;

    PLIB_GLCD_LayerBaseAddressSet(layer->id, (uint32_t)drvLayer[layer->id].baseaddr[layer->buffer_read_idx]);
}

static GFX_Result layerEnabledSet(GFX_Bool val)
{
    GFX_ActiveContext()->layer.active->enabled = val;
    
    if(val == GFX_TRUE)
        PLIB_GLCD_LayerEnable(GFX_ActiveContext()->layer.active->id);
    else
        PLIB_GLCD_LayerDisable(GFX_ActiveContext()->layer.active->id);
    
    return GFX_SUCCESS;
}

static GFX_Result glcdInitialize(GFX_Context* context)
{
    uint32_t      xResolution;
    uint32_t      yResolution;
    uint32_t      rightMargin;
    uint32_t      lowerMargin;
    uint32_t      hsyncLength;
    uint32_t      vsyncLength;
    uint32_t      leftMargin;
    uint32_t      upperMargin;
    uint32_t      stride;
    uint32_t      layerCount;
    uint32_t      i,j;

    cntxt = context;

    // general default initialization
    if(defInitialize(context) == GFX_FAILURE)
            return GFX_FAILURE;

    // override default HAL functions with GLCD specific implementations
    context->hal.update = &glcdUpdate;
    context->hal.destroy = &glcdDestroy;
    context->hal.layerBufferCountSet = &layerBufferCountSet;
    context->hal.layerBufferAddressSet = &layerBufferAddressSet;
    context->hal.layerBufferAllocate = &layerBufferAllocate;
    context->hal.layerBufferFree = &layerBufferFree;
    context->hal.layerSwapped = &layerSwapped;
    context->hal.layerPositionSet = &layerPositionSet;
    context->hal.layerSizeSet = &layerSizeSet;
    context->hal.layerEnabledSet = &layerEnabledSet;

    context->hal.layerAlphaAmountSet = &layerAlphaAmountSet;
    context->hal.layerAlphaAmountGet = &layerAlphaAmountGet;

    context->hal.colorModeSet = &colorModeSet;

    /* set temporary information */
    xResolution     = context->display_info->rect.width;
    yResolution     = context->display_info->rect.height;
    rightMargin     = context->display_info->attributes.horz.front_porch;
    leftMargin      = context->display_info->attributes.horz.back_porch;
    hsyncLength     = context->display_info->attributes.horz.pulse_width;
    vsyncLength     = context->display_info->attributes.vert.pulse_width;
    upperMargin     = context->display_info->attributes.vert.back_porch;
    lowerMargin     = context->display_info->attributes.vert.front_porch;

    /* glcd initialization */
    PLIB_GLCD_Disable();
    PLIB_GLCD_BackgroundColorSet(GFX_GLCD_BACKGROUND_COLOR);
    PLIB_GLCD_VSyncInterruptDisable();
    PLIB_GLCD_HSyncInterruptDisable();
    PLIB_GLCD_RGBSequentialModeSet(1<<31);

    PLIB_GLCD_FrontPorchXYSet(xResolution + rightMargin, yResolution + lowerMargin);
    PLIB_GLCD_BlankingXYSet(xResolution + rightMargin + hsyncLength, yResolution + lowerMargin + vsyncLength);
    PLIB_GLCD_BackPorchXYSet(xResolution + rightMargin + hsyncLength + leftMargin, yResolution + lowerMargin + vsyncLength + upperMargin);

    PLIB_GLCD_ClockDividerSet(GFX_GLCD_CONFIG_CLK_DIVIDER);
    PLIB_GLCD_ResolutionXYSet(xResolution, yResolution);

    PLIB_GLCD_PaletteGammaRampDisable();

    PLIB_GLCD_Enable();

    drvLayer[0].baseaddr[0] = (FRAMEBUFFER_PTR_TYPE)GFX_GLCD_LAYER0_BASEADDR;
    drvLayer[0].baseaddr[1] = (FRAMEBUFFER_PTR_TYPE)GFX_GLCD_LAYER0_DBL_BASEADDR;
    drvLayer[1].baseaddr[0] = (FRAMEBUFFER_PTR_TYPE)GFX_GLCD_LAYER1_BASEADDR;
    drvLayer[1].baseaddr[1] = (FRAMEBUFFER_PTR_TYPE)GFX_GLCD_LAYER1_DBL_BASEADDR;
    drvLayer[2].baseaddr[0] = (FRAMEBUFFER_PTR_TYPE)GFX_GLCD_LAYER2_BASEADDR;
    drvLayer[2].baseaddr[1] = (FRAMEBUFFER_PTR_TYPE)GFX_GLCD_LAYER2_DBL_BASEADDR;

    for (layerCount = 0; layerCount < context->layer.count; layerCount++)
    {
        drvLayer[layerCount].resx       = context->layer.layers[layerCount].rect.display.width;
        drvLayer[layerCount].resy       = context->layer.layers[layerCount].rect.display.height;
        drvLayer[layerCount].startx     = context->layer.layers[layerCount].rect.display.x;
        drvLayer[layerCount].starty     = context->layer.layers[layerCount].rect.display.y;
        drvLayer[layerCount].sizex      = drvLayer[layerCount].resx;
        drvLayer[layerCount].sizey      = drvLayer[layerCount].resy;
        drvLayer[layerCount].alpha      = context->layer.layers[layerCount].alphaAmount;
        drvLayer[layerCount].dblend     = GLCD_LAYER_DEST_BLEND_INV_SRCGBL;
        drvLayer[layerCount].sblend     = GLCD_LAYER_SRC_BLEND_ALPHA_SRCGBL;
        drvLayer[layerCount].colorspace = convertColorModeGfxToGLCD(GFX_COLOR_MODE_RGBA_8888);

        //Clear frame buffer
        for(i = 0; i < context->layer.layers[layerCount].rect.display.height; i++)
        {
            for(j = 0; j < context->layer.layers[layerCount].rect.display.width; j++)
            {
			*(uint32_t*)(drvLayer[layerCount].baseaddr[0] + i*context->layer.layers[layerCount].rect.display.width + j) = 0;
			*(uint32_t*)(drvLayer[layerCount].baseaddr[1] + i*context->layer.layers[layerCount].rect.display.width + j) = 0;
            }
        }
        
        stride = getColorModeStrideSize(drvLayer[layerCount].colorspace);

        PLIB_GLCD_LayerBaseAddressSet(layerCount, (uint32_t)drvLayer[layerCount].baseaddr[0]);
        PLIB_GLCD_LayerStrideSet(layerCount, drvLayer[layerCount].resx * stride );
        PLIB_GLCD_LayerResXYSet(layerCount, drvLayer[layerCount].resx, drvLayer[layerCount].resy );
        PLIB_GLCD_LayerStartXYSet(layerCount, drvLayer[layerCount].startx, drvLayer[layerCount].starty );
        PLIB_GLCD_LayerSizeXYSet(layerCount, drvLayer[layerCount].sizex, drvLayer[layerCount].sizey);
        PLIB_GLCD_LayerGlobalAlphaSet(layerCount, drvLayer[layerCount].alpha);
        PLIB_GLCD_LayerDestBlendFuncSet(layerCount, drvLayer[layerCount].dblend );
        PLIB_GLCD_LayerSrcBlendFuncSet(layerCount, drvLayer[layerCount].sblend );
        PLIB_GLCD_LayerColorModeSet(layerCount, drvLayer[layerCount].colorspace );

        // all layers off by default
        context->layer.layers[layerCount].enabled = GFX_FALSE;
    }

    EVIC_SourceStatusClear(INT_SOURCE_GLCD);
    EVIC_SourceEnable(INT_SOURCE_GLCD);

    return GFX_SUCCESS;
}

static void layerSwapPending(GFX_Layer* layer)
{
    uint32_t l;
    GFX_Context* context = GFX_ActiveContext();
    GFX_Layer* lyr;
    
    if(context->layerSwapSync)
    {
    for(l = 0; l < context->layer.count; l++)
    {
            lyr = &context->layer.layers[l];
            
            if(lyr->enabled == GFX_TRUE)
            {
                if(lyr->invalid == GFX_TRUE && lyr->swap == GFX_FALSE)
                    return;
            }
    }
    }

    waitingForVSync = GFX_TRUE;

    PLIB_GLCD_VSyncInterruptEnable(); // enable vsync interrupt

    // need to spin until vsync happens to ensure content does not get
    // drawn to the wrong frame buffer
    while(waitingForVSync == GFX_TRUE ||
          PLIB_GLCD_IsVerticalBlankingActive() == true)
    { }
}

// function that initialized the driver context
GFX_Result driverGLCDContextInitialize(GFX_Context* context)
{
    // set driver-specific data initialization function address
    context->hal.initialize = &glcdInitialize;

    // set driver-specific destroy function address
    context->hal.destroy = &glcdDestroy;
    
    // vsync support
    context->hal.layerSwapPending = &layerSwapPending; 
    
    return GFX_SUCCESS;
}

void GLCD_Interrupt_Handler(void)
{
    uint32_t i;
    GFX_Context* context = GFX_ActiveContext();
    
    // disable vsync interrupt
    PLIB_GLCD_VSyncInterruptDisable(); 

    // clear interrupt flag
    EVIC_SourceStatusClear(INT_SOURCE_GLCD);

    // swap all pending layers
    for(i = 0; i < context->layer.count; i++)
    {
        if(context->layer.layers[i].swap == GFX_TRUE)
            GFX_LayerSwap(&context->layer.layers[i]);
            
        if(waitForAlphaSetting[i] >= 0)
        {
            context->layer.layers[i].alphaAmount = waitForAlphaSetting[i];

            PLIB_GLCD_LayerGlobalAlphaSet(i, (uint8_t)waitForAlphaSetting[i]);
        }
    }
    
    waitingForVSync = GFX_FALSE;
}

/**** End Hardware Abstraction Interfaces ****/


static int DRV_GFX_GLCD_Start()
{
    return 0;
}

/*******************************************************************************
 End of File
*/
