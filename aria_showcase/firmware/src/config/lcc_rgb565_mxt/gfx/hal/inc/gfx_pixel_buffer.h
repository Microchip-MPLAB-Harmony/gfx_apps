/*******************************************************************************
 Module for Microchip Graphics Library - Hardware Abstraction Layer

  Company:
    Microchip Technology Inc.

  File Name:
    gfx_pixel_buffer.h

  Summary:
    Defines a general purpose pixel buffer construct.

  Description:
    Pixel buffer generation and management functions.
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
#ifndef GFX_BUFFER_H
#define GFX_BUFFER_H
//DOM-IGNORE-END

#include "gfx/hal/inc/gfx_common.h"
#include "gfx/hal/inc/gfx_color.h"

// *****************************************************************************
// *****************************************************************************
// Section: Data Types and Constants
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Structure:
    GFX_PixelBuffer_t

  Summary:
    A pixel buffer is a wrapper around a basic data pointer.  A pixel buffer
    has a color mode, a pixel count, a rectangular dimension, a pixel count,
    and a lenght in bytes.

  Description:
    mode - the color mode of the pixel buffer
    size - the width and height dimension of the pixel buffer
    pixel_count - the total number of pixels in the buffer
    buffer_length - the total size of the buffer in bytes
    pixels - the pointer to the pixel data for the buffer

  Remarks:
    None.
*/
typedef struct GFX_PixelBuffer_t
{
    GFX_ColorMode mode;
    
    GFX_Size size;
    int32_t pixel_count;
    
    uint32_t buffer_length;
    GFX_Buffer pixels;
} GFX_PixelBuffer;

// *****************************************************************************
// *****************************************************************************
// Section: Routines
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    GFX_Result GFX_PixelBufferCreate(const int32_t width,
                                     const int32_t height,
                                     const GFX_ColorMode mode,
                                     const void* const address,
                                     GFX_PixelBuffer* buffer)

  Summary:
    Initializes a pixel buffer struct.  Does not actually allocate any memory.

  Parameters:
    const int32_t - the width of the buffer
    const int32_t - the height of the buffer
    const GFX_ColorMode - the color mode of the buffer
    const void* - the data addres of the buffer (may be NULL)
    GFX_PixelBuffer* - pointer of the pixel buffer buffer to initialize
    
  Returns:
    GFX_Result
    
  Remarks:
    
*/
LIB_EXPORT GFX_Result GFX_PixelBufferCreate(const int32_t width,
                                            const int32_t height,
                                            const GFX_ColorMode mode,
                                            const void* const address,
                                            GFX_PixelBuffer* buffer);

// *****************************************************************************
/* Function:
    GFX_Result GFX_PixelBufferDestroy(GFX_PixelBuffer* const buffer,
                                      GFX_MemoryIntf* mem_intf)

  Summary:
    Destroys a pixel buffer construct.  If the buffer's pixels pointer is not
    zero this function will attempt to free it using the provided 
    GFX_MemoryIntf memory interface.

  Parameters:
    GFX_PixelBuffer* - the buffer to destroy
    GFX_MemoryIntf* - the memory interface to reference for free()
    
  Returns:
    GFX_Result
    
  Remarks:
    
*/                                            
LIB_EXPORT GFX_Result GFX_PixelBufferDestroy(GFX_PixelBuffer* const buffer,
                                             GFX_MemoryIntf* mem_intf);

// *****************************************************************************
/* Function:
    GFX_Result GFX_PixelBufferCopy(const GFX_PixelBuffer* const buffer,
                                   GFX_MemoryIntf* mem_intf,
                                   GFX_PixelBuffer* result)

  Summary:
    Creates a copy of the input buffer.  If the input buffer's pixel data is
    not null then the data will be duplicated for the result buffer.

  Parameters:
    const GFX_PixelBuffer* const buffer - the source buffer
    GFX_MemoryIntf* - the memory interface to use for memory operations
    GFX_PixelBuffer* - the result buffer
    
  Returns:
    GFX_Result    
    
  Remarks:
    
*/                                             
LIB_EXPORT GFX_Result GFX_PixelBufferCopy(const GFX_PixelBuffer* const buffer,
                                          GFX_MemoryIntf* mem_intf,
                                          GFX_PixelBuffer* result);

// *****************************************************************************
/* Function:
    GFX_Buffer GFX_PixelBufferOffsetGet(const GFX_PixelBuffer* const buffer,
                                        const GFX_Point* const pnt)

  Summary:
    Gets the offset address of the pixel that resides at the provided
    point in the given buffer.

  Parameters:
    const GFX_PixelBuffer* - the source buffer
    const GFX_Point* - the point for which the offset should be calculated
    
  Returns:
    GFX_Buffer - the pointer to the offset point in the source buffer
*/                                          
LIB_EXPORT GFX_Buffer GFX_PixelBufferOffsetGet(const GFX_PixelBuffer* const buffer,
                                               const GFX_Point* const pnt);

// *****************************************************************************
/* Function:
    GFX_Buffer GFX_PixelBufferOffsetGet_Unsafe(const GFX_PixelBuffer* const buffer,
                                               const GFX_Point* const pnt)

  Summary:
    Gets the offset address of the pixel that resides at the provided
    point in the given buffer.  Similar to GFX_PixelBufferOffsetGet but performs
    no bounds checking.

  Parameters:
    const GFX_PixelBuffer* - the source buffer
    const GFX_Point* - the point for which the offset should be calculated
    
  Returns:
    GFX_Buffer - the pointer to the offset point in the source buffer
*/                                               
LIB_EXPORT GFX_Buffer GFX_PixelBufferOffsetGet_Unsafe(const GFX_PixelBuffer* const buffer,
                                                      const GFX_Point* const pnt);                                                  

// *****************************************************************************
/* Function:
    GFX_Color GFX_PixelBufferGet(const GFX_PixelBuffer* const buffer,
                                 const GFX_Point* const pnt)

  Summary:
    Gets the value of the pixel that resides at the provided point in
    the given buffer.

  Parameters:
    const GFX_PixelBuffer* - the source buffer
    const GFX_Point* - the point for which the offset should be calculated
    
  Returns:
    GFX_Color - the value of the pixel at the point in the source buffer
*/                                                      
LIB_EXPORT GFX_Color GFX_PixelBufferGet(const GFX_PixelBuffer* const buffer,
                                        const GFX_Point* const pnt);

// *****************************************************************************
/* Function:
    GFX_Color GFX_PixelBufferGet_Unsafe(const GFX_PixelBuffer* const buffer,
                                               const GFX_Point* const pnt)

  Summary:
    Gets the value of the pixel that resides at the provided point in
    the given buffer.  Like GFX_PixelBufferGet but performs no bounds checking.

  Parameters:
    const GFX_PixelBuffer* - the source buffer
    const GFX_Point* - the point for which the offset should be calculated
    
  Returns:
    GFX_Color - the value of the pixel at the point in the source buffer
*/                                             
LIB_EXPORT GFX_Color GFX_PixelBufferGet_Unsafe(const GFX_PixelBuffer* const buffer,
                                               const GFX_Point* const pnt);
                                               
// *****************************************************************************
/* Function:
    GFX_Color GFX_PixelBufferGetIndex(const GFX_PixelBuffer* const buffer,
                                      const int32_t idx)

  Summary:
    Interprets the pixel buffer as a table of indices and looks up a specific
    index at position 'idx'.  Indices may be 1bpp, 4bpp, or 8bpp in size and
    are indicated by the color mode of the pixel buffer.

  Parameters:
    const GFX_PixelBuffer* const - the input buffer
    const int32_t - the index to retrieve
    
  Returns:
    GFX_Color - the resultant value that was retrieved
*/                                        
LIB_EXPORT GFX_Color GFX_PixelBufferGetIndex(const GFX_PixelBuffer* const buffer,
                                             const int32_t idx);

// *****************************************************************************
/* Function:
    GFX_Result GFX_PixelBufferAreaGet(const GFX_PixelBuffer* const buffer,
                                      const GFX_Rect* const rect,
                                      GFX_MemoryIntf* mem_intf,
                                      GFX_PixelBuffer* out)

  Summary:
    Extracts a rectanglar section of pixels from a pixel buffer.

  Parameters:
    const GFX_PixelBuffer* const buffer - the source buffer
    const GFX_Rect* rect - the area to extract
    GFX_MemoryIntf* - the memory interface to use for memory operations
    GFX_PixelBuffer* - the resultant pixel buffer
    
  Returns:
    GFX_Result
*/
LIB_EXPORT GFX_Result GFX_PixelBufferAreaGet(const GFX_PixelBuffer* const buffer,
                                             const GFX_Rect* const rect,
                                             GFX_MemoryIntf* mem_intf,
                                             GFX_PixelBuffer* out);
                                             
// *****************************************************************************
/* Function:
    GFX_Result GFX_PixelBufferAreaGet_Unsafe(const GFX_PixelBuffer* const buffer,
                                                    const GFX_Rect* const rect,
                                                    GFX_MemoryIntf* mem_intf,
                                                    GFX_PixelBuffer* out)

  Summary:
    Extracts a rectanglar section of pixels from a pixel buffer.  Like 
    GFX_PixelBufferAreaGet but performs no clipping between the rectangles of the
    extract area and the source buffer.
    
  Parameters:
    const GFX_PixelBuffer* const buffer - the source buffer
    const GFX_Rect* rect - the area to extract
    GFX_MemoryIntf* - the memory interface to use for memory operations
    GFX_PixelBuffer* - the resultant pixel buffer
    
  Returns:
    GFX_Result
*/                                                 
LIB_EXPORT GFX_Result GFX_PixelBufferAreaGet_Unsafe(const GFX_PixelBuffer* const buffer,
                                                    const GFX_Rect* const rect,
                                                    GFX_MemoryIntf* mem_intf,
                                                    GFX_PixelBuffer* out);

#if GFX_DRAW_PIPELINE_ENABLED
// *****************************************************************************
/* Function:
    GFX_Result GFX_PixelBufferConvert(const GFX_PixelBuffer* const source,
                                      const GFX_ColorMode result_mode,
                                      GFX_MemoryIntf* mem_intf,
                                      GFX_PixelBuffer* result)

  Summary:
    Duplicates a pixel buffer and converts the copy to another color mode.

  Parameters:
    const GFX_PixelBuffer* const source - the source buffer
    const GFX_ColorMode result_mode - the desired color mode
    GFX_MemoryIntf* - the memory interface to use for memory operations
    GFX_PixelBuffer* - the resultant pixel buffer
    
  Returns:
    GFX_Result
*/                                        
LIB_EXPORT GFX_Result GFX_PixelBufferConvert(const GFX_PixelBuffer* const source,
                                             const GFX_ColorMode result_mode,
                                             GFX_MemoryIntf* mem_intf,
                                             GFX_PixelBuffer* result);
                                             
// *****************************************************************************
/* Function:
    GFX_Result GFX_PixelBufferClipRect(const GFX_PixelBuffer* const buffer,
                                       const GFX_Rect* const rect,
                                       GFX_Rect* result)

  Summary:
    Clips a rectangle against a pixel buffer.  The result is guaranteed to fit
    inside the buffer's area.

  Parameters:
    const GFX_PixelBuffer* const buffer - the source buffer
    const GFX_Rect* const - the rectangle to analyze
    GFX_Rect* result - the clipped rectangle
    
  Returns:
    GFX_Result
*/                                             
LIB_EXPORT GFX_Result GFX_PixelBufferClipRect(const GFX_PixelBuffer* const buffer,
                                              const GFX_Rect* const rect,
                                              GFX_Rect* result);   

// *****************************************************************************
/* Function:
    GFX_Result GFX_PixelBufferSet(const GFX_PixelBuffer* const buffer,
                                  const GFX_Point* const pnt,
                                  GFX_Color color)

  Summary:
    Sets a pixel in a pixel buffer at a point to a specified color.  Caller is
    responsible for ensuring that the input color is in the same color format
    as the pixel buffer.

  Parameters:
    const GFX_PixelBuffer* const buffer - the buffer to operate on
    const GFX_Point* const - the location of the pixel to set
    GFX_Color - the color to set the pixel to.  must be the same format as the
                buffer
    
  Returns:
    GFX_Result
*/                                                
LIB_EXPORT GFX_Result GFX_PixelBufferSet(const GFX_PixelBuffer* const buffer,
                                         const GFX_Point* const pnt,
                                         GFX_Color color);

// *****************************************************************************
/* Function:
    GFX_Result GFX_PixelBufferSet_Unsafe(const GFX_PixelBuffer* const buffer,
                                                const GFX_Point* const pnt,
                                                GFX_Color color)

  Summary:
    Sets a pixel in a pixel buffer at a point to a specified color.  Caller is
    responsible for ensuring that the input color is in the same color format
    as the pixel buffer.  Like GFX_PixelBufferSet but performs no bounds
    checking.

  Parameters:
    const GFX_PixelBuffer* const buffer - the buffer to operate on
    const GFX_Point* const - the location of the pixel to set
    GFX_Color - the color to set the pixel to.  must be the same format as the
                buffer
    
  Returns:
    GFX_Result
*/                                         
LIB_EXPORT GFX_Result GFX_PixelBufferSet_Unsafe(const GFX_PixelBuffer* const buffer,
                                                const GFX_Point* const pnt,
                                                GFX_Color color);                                         
                                            
// *****************************************************************************
/* Function:
    GFX_Result GFX_PixelBufferAreaSet(const GFX_PixelBuffer* const source,
                                      const GFX_Rect* const source_rect,
                                      const GFX_PixelBuffer* const dest,
                                      const GFX_Point* const pnt,
                                      GFX_MemoryIntf* mem_intf)

  Summary:
    Copies an area of pixels from a source buffer to a destination buffer.
    If the source buffer format does not match the destination format the data
    will be converted to match during the copy operation.  

  Parameters:
    const GFX_PixelBuffer* const source - the source buffer                                              
    const GFX_Rect* const source_rect - the rectangle of the source buffer
                                        to use
    const GFX_PixelBuffer* const dest - the destination buffer to copy to
    const GFX_Point* const pnt - the location of the destination to copy to
    GFX_MemoryIntf* - the memory interface to use for memory operations
    
  Returns:
    GFX_Result
*/
LIB_EXPORT GFX_Result GFX_PixelBufferAreaSet(const GFX_PixelBuffer* const source,
                                             const GFX_Rect* const source_rect,
                                             const GFX_PixelBuffer* const dest,
                                             const GFX_Point* const pnt,
                                             GFX_MemoryIntf* mem_intf);

// *****************************************************************************
/* Function:
    GFX_Result GFX_PixelBufferAreaSet_Unsafe(const GFX_PixelBuffer* const source,
                                                    const GFX_Rect* const source_rect,
                                                    const GFX_PixelBuffer* const dest,
                                                    const GFX_Point* const pnt,
                                                    GFX_MemoryIntf* mem_intf)

  Summary:
    Copies an area of pixels from a source buffer to a destination buffer.
    If the source buffer format does not match the destination format the data
    will be converted to match during the copy operation.  Like
    GFX_PixelBufferAreaSet but performs no bounds checking.

  Parameters:
    const GFX_PixelBuffer* const source - the source buffer                                              
    const GFX_Rect* const source_rect - the rectangle of the source buffer
                                        to use
    const GFX_PixelBuffer* const dest - the destination buffer to copy to
    const GFX_Point* const pnt - the location of the destination to copy to
    GFX_MemoryIntf* - the memory interface to use for memory operations
    
  Returns:
    GFX_Result
*/                                             
LIB_EXPORT GFX_Result GFX_PixelBufferAreaSet_Unsafe(const GFX_PixelBuffer* const source,
                                                    const GFX_Rect* const source_rect,
                                                    const GFX_PixelBuffer* const dest,
                                                    const GFX_Point* const pnt,
                                                    GFX_MemoryIntf* mem_intf);

// *****************************************************************************
/* Function:
    GFX_Result GFX_PixelBufferAreaFill(const GFX_PixelBuffer* const buffer,
                                       const GFX_Rect* const rect,
                                       const GFX_Color color)

  Summary:
    Fills an area of a pixel buffer with a solid color.  Caller is responsible
    for ensuring that the color is the same color format as the destination
    buffer.

  Parameters:
    const GFX_PixelBuffer* const buffer - the buffer to manipulate
    const GFX_Rect* const rect - the rectangle of the buffer to fill
    const GFX_Color color - the color to use for the fill operation
    
  Returns:
    GFX_Result
*/                                                    
LIB_EXPORT GFX_Result GFX_PixelBufferAreaFill(const GFX_PixelBuffer* const buffer,
                                              const GFX_Rect* const rect,
                                              const GFX_Color color);

// *****************************************************************************
/* Function:
    GFX_Result GFX_PixelBufferAreaFill_Unsafe(const GFX_PixelBuffer* const buffer,
                                                     const GFX_Rect* const rect,
                                                     const GFX_Color color)

  Summary:
    Fills an area of a pixel buffer with a solid color.  Caller is responsible
    for ensuring that the color is the same color format as the destination
    buffer.  Like GFX_PixelBufferAreaFill but performs no bounds checking.

  Parameters:
    const GFX_PixelBuffer* const buffer - the buffer to manipulate
    const GFX_Rect* const rect - the rectangle of the buffer to fill
    const GFX_Color color - the color to use for the fill operation
    
  Returns:
    GFX_Result
*/                                              
LIB_EXPORT GFX_Result GFX_PixelBufferAreaFill_Unsafe(const GFX_PixelBuffer* const buffer,
                                                     const GFX_Rect* const rect,
                                                     const GFX_Color color) ;      

#endif // GFX_DRAW_PIPELINE_ENABLED

#endif /* GFX_BUFFER_H */