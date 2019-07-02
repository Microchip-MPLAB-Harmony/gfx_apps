/*******************************************************************************
  ILI9488 Display Top-Level Driver Source File

  File Name:
    drv_gfx_ili9488.c

  Summary:
    Top level driver for ILI9488.

  Description:
    Build-time generated implementation for the ILI9488 Driver.

    Created with MPLAB Harmony Version 3.0
*******************************************************************************/
//DOM-IGNORE-BEGIN
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
//DOM-IGNORE-END


#include "definitions.h"

#include "drv_gfx_ili9488_cmd_defs.h"
#include "drv_gfx_ili9488_common.h"
#include "drv_gfx_ili9488.h"

// Number of layers
#define LAYER_COUNT     1

// Default max width/height of ILI9488 frame
#define DISPLAY_DEFAULT_WIDTH   320
#define DISPLAY_DEFAULT_HEIGHT  480

#define DISPLAY_WIDTH   320
#define DISPLAY_HEIGHT  480

#define BYTES_PER_PIXEL_BUFFER 2
#define PIXEL_BUFFER_COLOR_MODE LE_COLOR_MODE_RGB_565
#define SCREEN_WIDTH DISPLAY_WIDTH
#define SCREEN_HEIGHT DISPLAY_HEIGHT

ILI9488_DRV drv;

static uint32_t swapCount = 0;

/** initCmdParm

  Summary:
    Table of command/parameter(s) used to initialize the ILI9488.

  Description:
    This table contains command/parameter(s) values that are written to the
    ILI9488 during initialization.

  Remarks:
    Add project-specific initialization values for the ILI9488 here.
 */
ILI9488_CMD_PARAM initCmdParm[] =
{
    {ILI9488_CMD_INTERFACE_PIXEL_FORMAT_SET, 1, {ILI9488_COLOR_PIX_FMT_16BPP}},
    {ILI9488_CMD_SET_IMAGE_FUNCTION, 1, {0x01}},
    {ILI9488_CMD_INTERFACE_MODE_CONTROL, 1, {0x00}},
    {ILI9488_CMD_MEMORY_ACCESS_CONTROL, 1, {(
                                             ILI9488_MADCTL_RGB_BGR_ORDER_CTRL |
                                             ILI9488_MADCTL_COL_ADDR_ORDER |
                                            0)}},

    {ILI9488_CMD_SLEEP_OUT, 0, {0x00}},
    {ILI9488_CMD_DISPLAY_ON, 0, {0x00}},
};

/* ************************************************************************** */

/**
  Function:
    static void ILI9488_DelayMS(int ms)

  Summary:
    Delay helper function.

  Description:
    This is a helper function for delay using the system tick timer.

  Parameters:
    ms      - Delay in milliseconds

  Returns:
    None.

*/

static inline void ILI9488_DelayMS(int ms)
{
    SYS_TIME_HANDLE timer = SYS_TIME_HANDLE_INVALID;

    if (SYS_TIME_DelayMS(ms, &timer) != SYS_TIME_SUCCESS)
        return;
    while (SYS_TIME_DelayIsComplete(timer) == false);
}
/**
  Function:
    static int ILI9488_Reset(void)

  Summary:
    Toggles the hardware reset to the ILI9488.

  Description:
    This function toggles the GPIO pin for asserting reset to the ILI9488.

  Parameters:
    None

  Returns:
    None

*/
static int ILI9488_Reset(void)
{
    ILI9488_Reset_Deassert();
    ILI9488_DelayMS(10);
    ILI9488_Reset_Assert();
    ILI9488_DelayMS(10);
    ILI9488_Reset_Deassert();
    ILI9488_DelayMS(30);

    return 0;
}

static int ILI9488_Init(ILI9488_DRV *drv,
                        ILI9488_CMD_PARAM *initVals,
                        int numVals)
{
    int returnValue;
    uint8_t buf[5];
    unsigned int i;

    for (i = 0; i < numVals; i++, initVals++)
    {
        returnValue = ILI9488_Intf_WriteCmd(drv,
                                         initVals->cmd,
                                         initVals->parms,
                                         initVals->parmCount);
        if (0 != returnValue)
            return -1;
    }

    buf[0] = 0;
    buf[1] = 0;
    buf[2] = (((DISPLAY_WIDTH - 1)  & 0xFF00) >> 8);
    buf[3] = ((DISPLAY_WIDTH - 1)  & 0xFF);
    
    returnValue = ILI9488_Intf_WriteCmd(drv,
                                     ILI9488_CMD_COLUMN_ADDRESS_SET,
                                     buf,
                                     4);
    if (0 != returnValue)
        return -1;

    buf[0] = 0;
    buf[1] = 0;
    buf[2] = (((DISPLAY_HEIGHT - 1)  & 0xFF00) >> 8);
    buf[3] = ((DISPLAY_HEIGHT - 1)  & 0xFF);
    
    returnValue = ILI9488_Intf_WriteCmd(drv,
                                  ILI9488_CMD_PAGE_ADDRESS_SET,
                                  buf,
                                  4);
    if (0 != returnValue)
        return -1;

    return returnValue;
}

leResult DRV_ILI9488_Initialize(void)
{
    drv.bytesPerPixelBuffer = BYTES_PER_PIXEL_BUFFER;

    //Open interface to ILI9488 controller
    return ILI9488_Intf_Open(&drv);
}

leColorMode DRV_ILI9488_GetColorMode(void)
{
    return PIXEL_BUFFER_COLOR_MODE;
}

uint32_t DRV_ILI9488_GetBufferCount(void)
{
    return 1;
}

uint32_t DRV_ILI9488_GetDisplayWidth(void)
{
    return SCREEN_WIDTH;
}

uint32_t DRV_ILI9488_GetDisplayHeight(void)
{
    return SCREEN_HEIGHT;
}

void DRV_ILI9488_Update(void)
{
    if(drv.state == INIT)
    {
        // perform driver initialization here
        ILI9488_Reset();

        ILI9488_Init(&drv,
                     initCmdParm,
                     sizeof(initCmdParm)/sizeof(ILI9488_CMD_PARAM));

        ILI9488_Backlight_On();

        drv.state = RUN;
    }
}

uint32_t DRV_ILI9488_GetLayerCount()
{
    return 1;
}

uint32_t DRV_ILI9488_GetActiveLayer()
{
    return 0;
}

leResult DRV_ILI9488_SetActiveLayer(uint32_t idx)
{
    return LE_SUCCESS;
}

leResult DRV_ILI9488_BlitBuffer(int32_t x,
                                int32_t y,
                                lePixelBuffer* buf)
{
    int row, col, dataIdx;
    uint16_t* ptr;
    uint16_t clr;

    uint8_t data[SCREEN_WIDTH * BYTES_PER_PIXEL_BUFFER];
    
    drv.lineX_Start = x;
    drv.lineX_End = x + buf->size.width;
    
    for(row = 0; row < buf->size.height; row++)
    {
        drv.currentLine = y + row;
        
        ptr = lePixelBufferOffsetGet_Unsafe(buf, 0, row);

        dataIdx = 0;

        for(col = 0; col < buf->size.width; col++)
        {
            clr = ptr[col];

            data[dataIdx++] = (uint8_t) (clr >> 8);
            data[dataIdx++] = (uint8_t) (uint8_t) (clr & 0xff);
        }

        ILI9488_Intf_WritePixels(&drv,
                                 drv.lineX_Start,
                                 drv.currentLine,
                                 data, 
                                 buf->size.width);
    }

    return LE_SUCCESS;
}

void DRV_ILI9488_Swap(void)
{
    swapCount++;
}

uint32_t DRV_ILI9488_GetSwapCount(void)
{
    return swapCount;
}
