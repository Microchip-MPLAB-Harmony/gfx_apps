/*******************************************************************************
  2D Graphics Engine GFX2D PLIB

  Company
    Microchip Technology Inc.

  File Name
    plib_gfx2d.h

  Summary
    GFX2D PLIB Header File.

  Description
    This file defines the interface to the GFX2D peripheral library. This
    library provides access to and control of the associated peripheral
    instance.

  Remarks:
    None.

*******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2019 Microchip Technology Inc. and its subsidiaries.
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

#ifndef _PLIB_PLIB_GFX2D_H    // Guards against multiple inclusion
#define _PLIB_PLIB_GFX2D_H

#include "device.h"
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Data Types
// *****************************************************************************
// *****************************************************************************

typedef void (*PLIB_GFX2D_IRQ_CALLBACK) (uintptr_t context);

// *****************************************************************************
/* GFX2D IRQ Callback Object

   Summary:
    Struct for GFX2D IRQ handler

   Description:
    This structure defines the GFX2D IRQ handler object, used to store the IRQ
    callback function registered from the GFX2D driver

   Remarks:
    None.
*/
typedef struct
{
    PLIB_GFX2D_IRQ_CALLBACK callback_fn;
    uintptr_t context;
}PLIB_GFX2D_IRQ_CALLBACK_OBJECT;


// *****************************************************************************
/* GFX2D Instruction Status

   Summary:
    GFX2D Instruction Status data type.

   Description:
    This data type defines the GFX2D Instruction Status.

   Remarks:
    None.
*/

typedef enum
{
    /* No Error */
    GFX2D_ERROR_NONE,

    /* GPU returned Nack */
    GFX2D_ERROR_NACK,

} GFX2D_STATUS;

// *****************************************************************************
/* GFX2D State.

   Summary:
    GFX2D PLib Task State.

   Description:
    This data type defines the GFX2D PLib Task State.

   Remarks:
    None.

*/

typedef enum {

    /* GFX2D PLib Task Error State */
    GFX2D_STATE_ERROR = -1,

    /* GFX2D PLib Task Idle State */
    GFX2D_STATE_IDLE,

    /* GFX2D PLib Task Instruction Done State */
    GFX2D_STATE_TRANSFER_DONE,

} GFX2D_STATE;


// *****************************************************************************
/* GFX2D PLib Instance Object

   Summary:
    GFX2D PLib Object structure.

   Description:
    This data structure defines the GFX2D PLib Instance Object.

   Remarks:
    None.
*/

typedef struct
{
    uint16_t address;

    /* State */
    GFX2D_STATE state;

    /* Transfer status */
    GFX2D_STATUS error;

    /* Transfer Event Callback */
    PLIB_GFX2D_IRQ_CALLBACK callback;

    /* Transfer context */
    uintptr_t context;

} GFX2D_OBJ;


// *****************************************************************************
/* GFX2D Clock Gating Disable Core

   Summary:
    Defines the clock gating for the graphics engine

   Description:
    This defines .

   Remarks:
    None.
*/
typedef enum 
{
    GFX2D_CLOCK_GATING_ACTIVATED = 0,
    GFX2D_CLOCK_GATING_DISABLED
} GFX2D_CLOCK_GATING;


/* GFX2D Memory Tile Access

   Summary:
    Defines the memory access for the graphics engine.

   Description:
    This defines .

   Remarks:
    None.
*/
typedef enum 
{
    GFX2D_MEMORY_TILE_ACCESS = 0,
    GFX2D_MEMORY_LINEAR_ACCESS
} GFX2D_MEMORY_ACCESS;


/* GFX2D Performance Filter Configuration

   Summary:
    Defines the performance filter configuration for the graphics engine.

   Description:
    This defines .

   Remarks:
    None.
*/
typedef enum 
{
    GFX2D_FILTER_DISABLED = 0,
    GFX2D_FILTER_QOS0,
    GFX2D_FILTER_QOS1,
    GFX2D_FILTER_QOS2,
    GFX2D_FILTER_QOS3
} GFX2D_PERFORMANCE_FILTER_CONFIG;

/* GFX2D Performance Metrics Counter Selection

   Summary:
    Defines the performance metrics selection for the graphics engine.

   Description:
    This defines .

   Remarks:
    None.
*/
typedef enum 
{
    GFX2D_METRICS_DISABLED = 0,
    GFX2D_METRICS_INCREMENT_ON_READ,
    GFX2D_METRICS_INCREMENT_ON_WRITE,
    GFX2D_METRICS_INCREMENT_ON_CLOCK_CYCLES
} GFX2D_PERFORMANCE_METRICS_SELECTION;

      
/* GFX2D Surface

   Summary:
    Defines the surfaces of the graphics engine.

   Description:
    This defines .

   Remarks:
    None.
*/
typedef enum 
{
    GFX2D_SURFACE_ZERO = 0,
    GFX2D_SURFACE_ONE,
    GFX2D_SURFACE_TWO,
    GFX2D_SURFACE_THREE
} GFX2D_SURFACE;


/* GFX2D Color Lookup Table

   Summary:
    Defines the color lookup tables of the graphics engine.

   Description:
    This defines .

   Remarks:
    None.
*/
typedef enum 
{
    GFX2D_COLOR_LOOKUP_TABLE_ZERO = 0,
    GFX2D_COLOR_LOOKUP_TABLE_ONE,
} GFX2D_COLOR_LOOKUP_TABLE;

/* GFX2D Pixel formats

   Summary:
    Defines the pixel formats of the  graphics engine.

   Description:
    This defines .

   Remarks:
    None.
*/
typedef enum 
{
    GFX2D_A4IDX4 = 0,
    GFX2D_A8,
    GFX2D_IDX8,
    GFX2D_A8IDX8,
    GFX2D_RGB12,
    GFX2D_ARGB16,
    GFX2D_RBG15,
    GFX2D_TRGB16,
    GFX2D_RGBT16,
    GFX2D_RGB16,
    GFX2D_RGB24,
    GFX2D_ARGB32
} GFX2D_PIXEL_FORMAT;


/* GFX2D Pixel formats

   Summary:
    Defines the pixel formats of the  graphics engine.

   Description:
    This defines .

   Remarks:
    None.
*/
typedef enum 
{
    GFX2D_XY00 = 0,
    GFX2D_XY01,
    GFX2D_XY10,
    GFX2D_XY11
} GFX2D_TRANSFER_DIRECTION;

// *****************************************************************************
/**
 * \berif GFX2D buffer format
 */
 //typedef enum gpu_buffer_format {
 //   GFX2D_A8       = 1,  /*!< 8 bits per pixel alpha, with user-defined constant color */
 //   GFX2D_RGB12    = 4,  /*!< 12 bits per pixel, 4 bits per color channel */
 //   GFX2D_ARGB16   = 5,  /*!< 16 bits per pixel with 4-bit width alpha value, and 4 bits per color channel */
 //   GFX2D_RGB15    = 6,  /*!< 15 bits per pixel, 5 bits per color channel */
 //   GFX2D_TRGB16   = 7,  /*!< 16 bits per pixel, 5 bits for the red and blue channels and 6 bits for the green channel */
 //   GFX2D_RGBT16   = 8,  /*!< 16 bits per pixel, with 1 bit for transparency and 5 bits for color channels */
 //   GFX2D_RGB16    = 9,  /*!< 16 bits per pixel, 5 bits for the red and blue channels and 6 bits for the green channel */
 //   GFX2D_ARGB8888 = 10, /*!< 32 bits per pixel, 8 bits for alpha and color channels */
 //   GFX2D_RGBA8888 = 11, /*!< 32 bits per pixel, 8 bits for alpha and color channels */
 //   GFX2D_BUFFER_FORMAT_SIZE
//} GFX2D_BUFFER_FORMAT;

/* GPU BUffer format's pixel size in bytes */
#define GFX2D_BUFFER_FORMAT_PIXEL_SIZE {1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 4, 4};

/**
 * \berif GFX2D Buffer
 */
typedef struct gpu_buffer {
    uint32_t               width;  /*!< Buffer width in pixel */
    uint32_t               height; /*!< Buffer height in pixel */
    GFX2D_PIXEL_FORMAT     format;    /*!< Buffer pixel format */
    uint32_t               addr;   /*!< Buffer memory address */
    GFX2D_TRANSFER_DIRECTION dir;
} GFX2D_BUFFER;

typedef struct gpu_rectangle {
    uint32_t x;      /*!< X position in pixel, start from 0 */
    uint32_t y;      /*!< Y position in pixel, start from 0 */
    uint32_t width;  /*!< Width in pixel */
    uint32_t height; /*!< Height in pixel */
} GFX2D_RECTANGLE;

/**
 * \berif GFX2D color
 * A(31-24), R(23-16), G(15-8), B(7-0)
 */
typedef uint32_t gpu_color_t;
#define GFX2D_COLOR(a, r, g, b) (((a) << 24) | ((r) << 16) | ((g) << 8) | (b))

/**
 * \berif GFX2D Blend functions
 */
typedef enum gpu_blend {
    GFX2D_BLEND_SRC_OVER, /* S + (1-Sa)*D */
    GFX2D_BLEND_DST_OVER, /* (1-Da) * S + D */
    GFX2D_BLEND_SRC_IN,   /* Da * S */
    GFX2D_BLEND_DST_IN,   /* Sa * D */
    GFX2D_BLEND_ADDITIVE, /* S + D */
    GFX2D_BLEND_SUBTRACT  /* D * (1 - S) */
} GFX2D_BLEND;


// *****************************************************************************
// *****************************************************************************
// Section: Interface Routines
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    void PLIB_GFX2D_IRQ_CallbackRegister(PLIB_GFX2D_IRQ_CALLBACK callback, uintptr_t context);

   Summary:
    Registers a callback function for the GFX2 IRQ handler

   Description:
    None

   Precondition:
    None.

   Parameters:
    callback - the callback function
    context - the handler context

   Returns:
    None

   Remarks:
    None
*/
void PLIB_GFX2D_IRQ_CallbackRegister(PLIB_GFX2D_IRQ_CALLBACK callback, uintptr_t context);

void PLIB_GFX2D_Initialize( void );

void PLIB_GFX2D_Enable( void );

void PLIB_GFX2D_Disable( void );

GFX2D_STATUS PLIB_GFX2D_Fill(struct gpu_buffer *dst, struct gpu_rectangle *rect, gpu_color_t color);

GFX2D_STATUS PLIB_GFX2D_Copy(struct gpu_buffer *dst, struct gpu_rectangle *dst_rect, struct gpu_buffer *src,
                        struct gpu_rectangle *src_rect);

GFX2D_STATUS PLIB_GFX2D_Blend(struct gpu_buffer *dst, struct gpu_rectangle *dst_rect, struct gpu_buffer *fg,
                         struct gpu_rectangle *fg_rect, struct gpu_buffer *bg, struct gpu_rectangle *bg_rect,
                         enum gpu_blend blend);

bool PLIB_GFX2D_IsBusy(void);

GFX2D_STATUS PLIB_GFX2D_StatusGet(void);


// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif
// DOM-IGNORE-END

#endif /* PLIB_PLIB_GFX2D_H */
