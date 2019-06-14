/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app_utils.c

  Summary:
    This file contains the source code for the MPLAB Harmony application.

  Description:
    This file contains the source code for the MPLAB Harmony application.  It
    implements the logic of the application's state machine and it may call
    API routines of other MPLAB Harmony modules in the system, such as drivers,
    system services, and middleware.  However, it does not call any of the
    system interfaces (such as the "Initialize" and "Tasks" functions) of any of
    the modules in the system or make any assumptions about when those functions
    are called.  That is the responsibility of the configuration-specific system
    files.
 *******************************************************************************/

#include "app.h"

uint32_t getImagePixelGaussianBlur3x3(uint32_t * image,
                                        uint32_t width,
                                        uint32_t height,
                                        GFX_Point pt)
{
    uint32_t r = 0, g = 0, b = 0, a = 0;
    uint32_t color = 0;
    unsigned int x, y;
    uint32_t kernel[3][3] = {{1, 2, 1},
                             {2, 4, 2},
                             {1, 2, 1}};
    
    if (pt.x > 0 && 
        pt.y > 0 && 
        pt.x < width - 1&&
        pt.y < height - 1)
    {
        for (y = 0; y < 3 ; y++)
        {
            for (x = 0; x < 3; x++)
            {
                color = image[width * (pt.y - 1 + y) + (pt.x - 1 + x)];
                r += ((color >> 24) & 0xff) * kernel[x][y];
                g += ((color >> 16) & 0xff) * kernel[x][y];
                b += ((color >> 8) & 0xff) * kernel[x][y];
                a += (color & 0xff) * kernel[x][y];
            }
        }
        
        //Divide each channel by total weight (16) and combine to 32-bit color
        color = (((r >> 4) & 0xff)<< 24) |
                (((g >> 4) & 0xff) << 16) |
                (((b >> 4) & 0xff) << 8) |
                ((a >> 4) & 0xff);
    }
    else
    {
        color = image[width * pt.y + pt.x];
    }
    
    return color;
}


/* *****************************************************************************
 End of File
 */
