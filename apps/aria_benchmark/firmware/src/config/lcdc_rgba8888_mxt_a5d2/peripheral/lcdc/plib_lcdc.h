/*******************************************************************************
  LCDC PLIB

  Company:
    Microchip Technology Inc.

  File Name:
    plib_lcdc.h

  Summary:
    LCDC PLIB external functions declarations

  Description:
    This peripheral library implements a SUBSET of the register configurations
    for the LCDC. 
*******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2018 released Microchip Technology Inc.  All rights reserved.

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

// DOM-IGNORE-END

#ifndef _PLIB_LCDC_H    // Guards against multiple inclusion
#define _PLIB_LCDC_H

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

// *****************************************************************************
/* LCDC Signal Polarity

   Summary:
    Defines the polarity of the LCDC control signals

   Description:
    This defines the polarity of the LCDC control signals. A signal with positive
    polarity will be asserted high, while a signal with negative polarity will be
    asserted low.

   Remarks:
    None.
*/
typedef enum 
{
    LCDC_POLARITY_POSITIVE = 0,
    LCDC_POLARITY_NEGATIVE
} LCDC_SIGNAL_POLARITY;

// *****************************************************************************
/* LCDC Clock Source

   Summary:
    Defines the clock sources for the LCDC peripheral

   Description:

   Remarks:
    None.
*/
typedef enum 
{
    LCDC_CLOCK_SOURCE_SYSTEM = 0,
    LCDC_CLOCK_SOURCE_SYSTEM_2X
} LCDC_CLOCK_SOURCE;

// *****************************************************************************
/* PWM Clock Source

   Summary:
    Defines the clock sources for the LCDC PWM 

   Description:

   Remarks:
    None.
*/
typedef enum 
{
    LCDC_PWM_SOURCE_SLOW = 0,
    LCDC_PWM_SOURCE_SYSTEM
} LCDC_PWM_CLOCK_SOURCE;

// *****************************************************************************
/* LCDC Layer Types

   Summary:
    Defines the types for the LCDC hardware layers and overlays

   Description:

   Remarks:
    None.
*/
typedef enum 
{
    LCDC_LAYER_BASE = 0,
    LCDC_LAYER_OVR1 = 1,
    LCDC_LAYER_OVR2 = 2,
    LCDC_LAYER_HEO = 3,
    LCDC_LAYER_PP = 4
} LCDC_LAYER_ID;

// *****************************************************************************
/* LCDC Sync Edge

   Summary:
    Defines the HSYNC edge where VSYNC is synchronized

   Description:

   Remarks:
    None.
*/
typedef enum 
{
    LCDC_SYNC_EDGE_FIRST,
    LCDC_SYNC_EDGE_SECOND
} LCDC_VSYNC_SYNC_EDGE;

// *****************************************************************************
/* LCDC RGB Mode

   Summary:
    Defines the RGB color mode input types

   Description:

   Remarks:
    None.
*/
typedef enum 
{
    LCDC_INPUT_COLOR_MODE_RGB_444 = LCDC_BASECFG1_RGBMODE_12BPP_RGB_444_Val,
    LCDC_INPUT_COLOR_MODE_ARGB_4444 = LCDC_BASECFG1_RGBMODE_16BPP_ARGB_4444_Val,
    LCDC_INPUT_COLOR_MODE_RGBA_4444 = LCDC_BASECFG1_RGBMODE_16BPP_RGBA_4444_Val,
    LCDC_INPUT_COLOR_MODE_RGB_565 = LCDC_BASECFG1_RGBMODE_16BPP_RGB_565_Val,
    LCDC_INPUT_COLOR_MODE_TRGB_1555 = LCDC_BASECFG1_RGBMODE_16BPP_TRGB_1555_Val,
    LCDC_INPUT_COLOR_MODE_RGB_666 = LCDC_BASECFG1_RGBMODE_18BPP_RGB_666_Val,
    LCDC_INPUT_COLOR_MODE_RGB_666PACKED = LCDC_BASECFG1_RGBMODE_18BPP_RGB_666PACKED_Val,
    LCDC_INPUT_COLOR_MODE_TRGB_1666 = LCDC_BASECFG1_RGBMODE_19BPP_TRGB_1666_Val,
    LCDC_INPUT_COLOR_MODE_TRGB_PACKED = LCDC_BASECFG1_RGBMODE_19BPP_TRGB_PACKED_Val,
    LCDC_INPUT_COLOR_MODE_RGB_888 = LCDC_BASECFG1_RGBMODE_24BPP_RGB_888_Val,
    LCDC_INPUT_COLOR_MODE_RGB_888PACKED = LCDC_BASECFG1_RGBMODE_24BPP_RGB_888_PACKED_Val,
    LCDC_INPUT_COLOR_MODE_TRGB_1888 = LCDC_BASECFG1_RGBMODE_25BPP_TRGB_1888_Val,
    LCDC_INPUT_COLOR_MODE_ARGB_8888 = LCDC_BASECFG1_RGBMODE_32BPP_ARGB_8888_Val,
    LCDC_INPUT_COLOR_MODE_RGBA_8888 = LCDC_BASECFG1_RGBMODE_32BPP_RGBA_8888_Val,
    LCDC_INPUT_COLOR_MODE_LUT8, //Last mode
    LCDC_INPUT_COLOR_MODE_UNSUPPORTED,
} LCDC_INPUT_COLOR_MODE;

// *****************************************************************************
/* LCDC Output Mode

   Summary:
    Defines the controller output mode types

   Description:

   Remarks:
    None.
*/
typedef enum 
{
    LCDC_OUTPUT_COLOR_MODE_12BPP = LCDC_LCDCFG5_MODE_OUTPUT_12BPP_Val,
    LCDC_OUTPUT_COLOR_MODE_16BPP = LCDC_LCDCFG5_MODE_OUTPUT_16BPP_Val,
    LCDC_OUTPUT_COLOR_MODE_18BPP = LCDC_LCDCFG5_MODE_OUTPUT_18BPP_Val,
    LCDC_OUTPUT_COLOR_MODE_24BPP = LCDC_LCDCFG5_MODE_OUTPUT_24BPP_Val,
} LCDC_OUTPUT_COLOR_MODE;

// *****************************************************************************
/* Function:
    void LCDC_SetPixelClockPolarity(LCDC_SIGNAL_POLARITY polarity)

   Summary:
    Sets the pixel clock signal polarity

   Description:
    None

   Precondition:
    None.

   Parameters:
    polarity - the polarity of the pixel clock

   Returns:
    None

   Remarks:
    None
*/
void LCDC_SetPixelClockPolarity(LCDC_SIGNAL_POLARITY polarity);

// *****************************************************************************
/* Function:
    void LCDC_SetClockSourceSelection(LCDC_CLOCK_SOURCE source)

   Summary:
    Sets the LCDC clock source

   Description:
    None

   Precondition:
    None.

   Parameters:
    source - the source clock

   Returns:
    None

   Remarks:
    None
*/
void LCDC_SetClockSourceSelection(LCDC_CLOCK_SOURCE source);

// *****************************************************************************
/* Function:
    void LCDC_SetPWMClockSourceSelection(LCDC_PWM_CLOCK_SOURCE source)

   Summary:
    Sets the LCDC PWM clock source

   Description:
    None

   Precondition:
    None.

   Parameters:
    source - the source clock

   Returns:
    None

   Remarks:
    None
*/
void LCDC_SetPWMClockSourceSelection(LCDC_PWM_CLOCK_SOURCE source);

// *****************************************************************************
/* Function:
    void LCDC_SetLayerClockGatingDisable(LCDC_LAYER_ID layer, bool disable)

   Summary:
    Disables/Enables the clock gating on the LCDC layers

   Description:
    None

   Precondition:
    None.

   Parameters:
    layer - the layer to enable clock gating on
    disable - disables the clock gating if true, enables if false

   Returns:
    None

   Remarks:
    None
*/
void LCDC_SetLayerClockGatingDisable(LCDC_LAYER_ID layer, bool disable);

// *****************************************************************************
/* Function:
    void LCDC_SetClockDivider(uint8_t value)

   Summary:
    Sets the clock divider for the pixel clock

   Description:
    The pixel clock period formula is LCDPCLK = source clock / value
    when source clock is the system clock when CLKSET is '0', and 2x 
    system_clock when CLKSEL is '1'

   Precondition:
    None.

   Parameters:
    value - the 8-bit divider value, must be greater than 2

   Returns:
    None

   Remarks:
    None
*/
void LCDC_SetClockDivider(uint8_t value);

// *****************************************************************************
/* Function:
    void LCDC_SetHSYNCPulseWidth(uint16_t value)

   Summary:
    Sets HSYNC pulse length, given in pixel clock cycles

   Description:
    None

   Precondition:
    None.

   Parameters:
    value - the 16-bit pulse width, must be greater than 1

   Returns:
    None

   Remarks:
    None
*/
void LCDC_SetHSYNCPulseWidth(uint16_t value);

// *****************************************************************************
/* Function:
    void LCDC_SetVSYNCPulseWidth(uint16_t value)

   Summary:
    Sets VSYNC pulse length, given in pixel clock cycles

   Description:
    None

   Precondition:
    None.

   Parameters:
    value - the 16-bit pulse width, must be greater than 1

   Returns:
    None

   Remarks:
    None
*/
void LCDC_SetVSYNCPulseWidth(uint16_t value);

// *****************************************************************************
/* Function:
    void LCDC_SetVerticalFrontPorchWidth(uint16_t value)

   Summary:
    Sets VSYNC front porch width, give in number of lines

   Description:
    This field indicates the number of lines at the end of the frame

   Precondition:
    None.

   Parameters:
    value - the 16-bit porch width, must be greater than 1

   Returns:
    None

   Remarks:
    None
*/
void LCDC_SetVerticalFrontPorchWidth(uint16_t value);

// *****************************************************************************
/* Function:
    void LCDC_SetVerticalBackPorchWidth(uint16_t value)

   Summary:
    Sets VSYNC back porch width, give in number of lines

   Description:
    This field indicates the number of lines at the beginning of the frame

   Precondition:
    None.

   Parameters:
    value - the 16-bit porch width, must be greater than 1

   Returns:
    None

   Remarks:
    None
*/
void LCDC_SetVerticalBackPorchWidth(uint16_t value);

// *****************************************************************************
/* Function:
    void LCDC_SetHorizontalFrontPorchWidth(uint16_t value)

   Summary:
    Sets HSYNC front porch width, give in number of pixel clocks

   Description:
    Number of pixel clock cycles inserted at the end of the active line

   Precondition:
    None.

   Parameters:
    value - the 16-bit porch width, must be greater than 1

   Returns:
    None

   Remarks:
    None
*/
void LCDC_SetHorizontalFrontPorchWidth(uint16_t value);

// *****************************************************************************
/* Function:
    void LCDC_SetHorizontalBackPorchWidth(uint16_t value)

   Summary:
    Sets HSYNC front porch width, give in number of pixel clocks

   Description:
    Number of pixel clock cycles inserted at the beginning of the line

   Precondition:
    None.

   Parameters:
    value - the 16-bit porch width, must be greater than 1

   Returns:
    None

   Remarks:
    None
*/
void LCDC_SetHorizontalBackPorchWidth(uint16_t value);

// *****************************************************************************
/* Function:
    void LCDC_SetNumActiveRows(uint16_t value)

   Summary:
    Sets the number of active lines (height) in the frame

   Description:
    None

   Precondition:
    None.

   Parameters:
    value - the height of the frame in pixels

   Returns:
    None

   Remarks:
    None
*/
void LCDC_SetNumActiveRows(uint16_t value);

// *****************************************************************************
/* Function:
    void LCDC_SetNumPixelsPerLine(uint16_t value)

   Summary:
    Sets the number of pixels in a line (width) in the frame

   Description:
    None

   Precondition:
    None.

   Parameters:
    value - the width of the frame in pixels

   Returns:
    None

   Remarks:
    None
*/
void LCDC_SetNumPixelsPerLine(uint16_t value);

// *****************************************************************************
/* Function:
    void LCDC_SetHSYNCPolarity(LCDC_SIGNAL_POLARITY polarity)

   Summary:
    Sets the polarity of the HSYNC pulse

   Description:
    None

   Precondition:
    None.

   Parameters:
    polarity - positive polarity is active high, negative is active low

   Returns:
    None

   Remarks:
    None
*/
void LCDC_SetHSYNCPolarity(LCDC_SIGNAL_POLARITY polarity);

// *****************************************************************************
/* Function:
    void LCDC_SetVSYNCPolarity(LCDC_SIGNAL_POLARITY polarity)

   Summary:
    Sets the polarity of the VSYNC pulse

   Description:
    None

   Precondition:
    None.

   Parameters:
    polarity - positive polarity is active high, negative is active low

   Returns:
    None

   Remarks:
    None
*/
void LCDC_SetVSYNCPolarity(LCDC_SIGNAL_POLARITY polarity);

// *****************************************************************************
/* Function:
    LCDC_SetVSYNCPulseStart(LCDC_VSYNC_SYNC_EDGE edge)

   Summary:
    Sets the HSYNC pulse edge where the VSYNC pulse first active edge is 
    synchronized

   Description:
    None

   Precondition:
    None.

   Parameters:
    edge - first or second HSYNC edge

   Returns:
    None

   Remarks:
    None
*/
void LCDC_SetVSYNCPulseStart(LCDC_VSYNC_SYNC_EDGE edge);

// *****************************************************************************
/* Function:
    LCDC_SetVSYNCPulseEnd(LCDC_VSYNC_SYNC_EDGE edge)

   Summary:
    Sets the HSYNC pulse edge where the VSYNC pulse second active edge is
    synchronized

   Description:
    None

   Precondition:
    None.

   Parameters:
    edge - first or second HSYNC edge

   Returns:
    None

   Remarks:
    None
*/
void LCDC_SetVSYNCPulseEnd(LCDC_VSYNC_SYNC_EDGE edge);

// *****************************************************************************
/* Function:
    void LCDC_SetDisplaySignalPolarity(LCDC_SIGNAL_POLARITY polarity)

   Summary:
    Sets the polarity of the DISP signal

   Description:
    None

   Precondition:
    None.

   Parameters:
    polarity - positive polarity is active high, negative is active low

   Returns:
    None

   Remarks:
    None
*/
void LCDC_SetDisplaySignalPolarity(LCDC_SIGNAL_POLARITY polarity);

// *****************************************************************************
/* Function:
    void LCDC_SetDitheringEnable(bool enable)

   Summary:
    Enables/disables the LCDC dithering logical unit

   Description:
    None

   Precondition:
    None.

   Parameters:
    enable - if true, dithering is enabled. Disabled if false

   Returns:
    None

   Remarks:
    None
*/
void LCDC_SetDitheringEnable(bool enable);

// *****************************************************************************
/* Function:
    void LCDC_SetDisplaySignalSynchronization(bool synchronous)

   Summary:
    Sets the sync of the DISP signal with the HYSNC pulse

   Description:
    None

   Precondition:
    None.

   Parameters:
    synchronous - if true, DISP signal is sync w/ the 2nd active edge of HSYNC

   Returns:
    None

   Remarks:
    None
*/
void LCDC_SetDisplaySignalSynchronization(bool synchronous);

// *****************************************************************************
/* Function:
    void LCDC_SetOutputMode(LCDC_OUTPUT_COLOR_MODE mode)

   Summary:
    Sets the output mode of the LCDC

   Description:
    None

   Precondition:
    None.

   Parameters:
    mode - the output mode

   Returns:
    None

   Remarks:
    None
*/
void LCDC_SetOutputMode(LCDC_OUTPUT_COLOR_MODE mode);

// *****************************************************************************
/* Function:
    void LCDC_SetPostPocessingEnable(bool enable)

   Summary:
    Enables/disables post processing

   Description:
    None

   Precondition:
    None.

   Parameters:
    enable - if true, post processing is enabled. Disabled if false.

   Returns:
    None

   Remarks:
    None
*/
void LCDC_SetPostPocessingEnable(bool enable);

// *****************************************************************************
/* Function:
    void LCDC_SetVSYNCPulseSetupConfig(bool synchronous)

   Summary:
    Sets the VSYNC pulse sync with HSYNC pulse edge

   Description:
    None

   Precondition:
    None.

   Parameters:
    synchronous - if true, VSYNC is asserted sync with the HSYNC pulse edge
                  if false, VSYNC is asserted one pclk before the HSYNC pulse

   Returns:
    None

   Remarks:
    None
*/
void LCDC_SetVSYNCPulseSetupConfig(bool synchronous);

// *****************************************************************************
/* Function:
    void LCDC_SetVSYNCPulseHoldConfig(bool synchronous)

   Summary:
    Sets the VSYNC pulse sync with HSYNC pulse edge

   Description:
    None

   Precondition:
    None.

   Parameters:
    synchronous - if true, VSYNC is asserted sync with the HSYNC pulse edge
                  if false, VSYNC is held active one pclk after the HSYNC pulse

   Returns:
    None

   Remarks:
    None
*/
void LCDC_SetVSYNCPulseHoldConfig(bool synchronous);

// *****************************************************************************
/* Function:
    void LCDC_SetDisplayGuardTime(uint16_t frames)

   Summary:
    Number of frames inserted before and after DISP assertion

   Description:
    None

   Precondition:
    None.

   Parameters:
    frames - the number of frames

   Returns:
    None

   Remarks:
    None
*/
void LCDC_SetDisplayGuardTime(uint16_t frames);

// *****************************************************************************
/* Function:
    void LCDC_SetPWMPrescaler(uint8_t div)

   Summary:
    Sets the configuration of the counter prescaler module

   Description:
    None

   Precondition:
    None.

   Parameters:
    div - the prescaler value (2^div)

   Returns:
    None

   Remarks:
    None
*/
void LCDC_SetPWMPrescaler(uint8_t div);

// *****************************************************************************
/* Function:
    void LCDC_SetPWMSignalPolarity(LCDC_SIGNAL_POLARITY polarity)

   Summary:
    Sets the polarity of the PWM signal

   Description:
    None

   Precondition:
    None.

   Parameters:
    polarity - the signal polarity

   Returns:
    None

   Remarks:
    None
*/
void LCDC_SetPWMSignalPolarity(LCDC_SIGNAL_POLARITY polarity);

// *****************************************************************************
/* Function:
    void LCDC_SetPWMCompareValue(uint32_t value)

   Summary:
    Sets the PWM compare value

   Description:
    None

   Precondition:
    None.

   Parameters:
    value - the compare value

   Returns:
    None

   Remarks:
    None
*/
void LCDC_SetPWMCompareValue(uint32_t value);

// *****************************************************************************
/* Function:
    void LCDC_SetPixelClockEnable(bool enable)

   Summary:
    Enables/disables the pixel clock

   Description:
    None

   Precondition:
    None.

   Parameters:
    enable - if true, pixel clock is enabled. Disabled if false.

   Returns:
    None

   Remarks:
    None
*/
void LCDC_SetPixelClockEnable(bool enable);

// *****************************************************************************
/* Function:
    void LCDC_SetSYNCEnable(bool enable)

   Summary:
    Enables/disables the VSYNC and HSYNC signals

   Description:
    None

   Precondition:
    None.

   Parameters:
    enable - if true, H/VSYNC signals are generated. if false, signals are disabled

   Returns:
    None

   Remarks:
    None
*/
void LCDC_SetSYNCEnable(bool enable);

// *****************************************************************************
/* Function:
    void LCDC_SetDISPSignalEnable(bool enable)

   Summary:
    Enables/disables the DISP signal

   Description:
    None

   Precondition:
    None.

   Parameters:
    enable - if true, DISP signal is generated. if false, DISP is disabled

   Returns:
    None

   Remarks:
    None
*/
void LCDC_SetDISPSignalEnable(bool enable);

// *****************************************************************************
/* Function:
    void LCDC_SetPWMEnable(bool enable)

   Summary:
    Enables/disables the PWM signal

   Description:
    None

   Precondition:
    None.

   Parameters:
    enable - if true, PWM signal is generated. if false, PWM is disabled

   Returns:
    None

   Remarks:
    None
*/
void LCDC_SetPWMEnable(bool enable);

// *****************************************************************************
/* Function:
    void LCDC_ClockReset(void)

   Summary:
    Resets the pixel clock module

   Description:
    None

   Precondition:
    None.

   Parameters:
    None

   Returns:
    None

   Remarks:
    None
*/
void LCDC_ClockReset( void );

// *****************************************************************************
/* Function:
    void LCDC_SYNCReset(void)

   Summary:
    Resets the timing engine

   Description:
    None

   Precondition:
    None.

   Parameters:
    None

   Returns:
    None

   Remarks:
    None
*/
void LCDC_SYNCReset( void );

// *****************************************************************************
/* Function:
    void LCDC_DISPSignalReset(void)

   Summary:
    Resets the DISP signal

   Description:
    None

   Precondition:
    None.

   Parameters:
    None

   Returns:
    None

   Remarks:
    None
*/
void LCDC_DISPSignalReset( void );

// *****************************************************************************
/* Function:
    void LCDC_PWMReset(void)

   Summary:
    Resets the PWM module

   Description:
    None

   Precondition:
    None.

   Parameters:
    None

   Returns:
    None

   Remarks:
    None
*/
void LCDC_PWMReset( void );

// *****************************************************************************
/* Function:
    bool LCDC_GetPixelClockStatusRunning(void)

   Summary:
    Gets the status of the pixel clock

   Description:
    None

   Precondition:
    None.

   Parameters:
    None

   Returns:
    true - pixel clock is running
    false - pixel clock is disabled

   Remarks:
    None
*/
bool LCDC_GetPixelClockStatusRunning( void );

// *****************************************************************************
/* Function:
    bool LCDC_GetTimingEngineStatusRunning(void)

   Summary:
    Gets the status of the timing engine

   Description:
    None

   Precondition:
    None.

   Parameters:
    None

   Returns:
    true - timing engine is running
    false - timing engine is disabled

   Remarks:
    None
*/
bool LCDC_GetTimingEngineStatusRunning( void );

// *****************************************************************************
/* Function:
    bool LCDC_GetDisplaySignalStatusActivated(void)

   Summary:
    Gets the status of the DISP signal

   Description:
    None

   Precondition:
    None.

   Parameters:
    None

   Returns:
    true - DISP signal is activated
    false - DISP signal is disabled

   Remarks:
    None
*/
bool LCDC_GetDisplaySignalStatusActivated( void );

// *****************************************************************************
/* Function:
    bool LCDC_GetPWMSignalStatusActivated(void)

   Summary:
    Gets the status of the PWM signal

   Description:
    None

   Precondition:
    None.

   Parameters:
    None

   Returns:
    true - PWM signal is activated
    false - PWM signal is disabled

   Remarks:
    None
*/
bool LCDC_GetPWMSignalStatusActivated( void );

// *****************************************************************************
/* Function:
    bool LCDC_GetSynchronizationStatusInProgress(void)

   Summary:
    Gets the status of clock domain synchronization

   Description:
    None

   Precondition:
    None.

   Parameters:
    None

   Returns:
    true - synchronization is in progress
    false - synchronization is terminated

   Remarks:
    None
*/
bool LCDC_GetSynchronizationStatusInProgress( void );

// *****************************************************************************
/* Function:
    void LCDC_SetSOFInterruptEnable(bool enable)

   Summary:
    Enables/disables the start of frame interrupt

   Description:
    None

   Precondition:
    None.

   Parameters:
    enable - if true, interrupt is enabled. Disabled if false

   Returns:
    None

   Remarks:
    None
*/
void LCDC_SetSOFInterruptEnable(bool enable);

// *****************************************************************************
/* Function:
    void LCDC_SetLCDDisableInterruptEnable(bool enable)

   Summary:
    Enables/disables the LCD disable interrupt

   Description:
    None

   Precondition:
    None.

   Parameters:
    enable - if true, interrupt is enabled. Disabled if false

   Returns:
    None

   Remarks:
    None
*/
void LCDC_SetLCDDisableInterruptEnable(bool enable);

// *****************************************************************************
/* Function:
    void LCDC_SetRGBModeInput(LCDC_LAYER_ID layer, LCDC_INPUT_COLOR_MODE mode)

   Summary:
    Sets the input color mode for the specified layer

   Description:
    None

   Precondition:
    None.

   Parameters:
    layer - the target layer
    mode - the input color mode

   Returns:
    None

   Remarks:
    None
*/
void LCDC_SetRGBModeInput(LCDC_LAYER_ID layer, LCDC_INPUT_COLOR_MODE mode);

// *****************************************************************************
/* Function:
    void LCDC_SetDMAHeadPointer(LCDC_LAYER_ID layer, uint32_t head)

   Summary:
    Sets the specified layer's Head Pointer to the DMA descriptor address

   Description:
    None

   Precondition:
    None.

   Parameters:
    layer - the target layer
    head - the DMA decriptor address

   Returns:
    None

   Remarks:
    None
*/
void LCDC_SetDMAHeadPointer(LCDC_LAYER_ID layer, uint32_t head);

// *****************************************************************************
/* Function:
    void LCDC_SetWindowPosition(LCDC_LAYER_ID layer, uint16_t xpos, uint16_t ypos)

   Summary:
    Sets the X, Y position of the specified layer

   Description:
    None

   Precondition:
    None.

   Parameters:
    layer - the target layer
    xpos - the X coordinate position
    ypos - the Y coordinate position

   Returns:
    None

   Remarks:
    Only OVR1, OVR2 and HEO layers are supported
*/
void LCDC_SetWindowPosition(LCDC_LAYER_ID layer, uint16_t xpos, uint16_t ypos);

// *****************************************************************************
/* Function:
    void LCDC_SetWindowSize(LCDC_LAYER_ID layer, uint16_t width, uint16_t height)

   Summary:
    Sets the size of the specified layer

   Description:
    None

   Precondition:
    None.

   Parameters:
    layer - the target layer
    width - the width of the layer (pixels)
    height - the height of the layer (pixels)

   Returns:
    None

   Remarks:
    Only OVR1, OVR2 and HEO layers are supported
*/
void LCDC_SetWindowSize(LCDC_LAYER_ID layer, uint16_t width, uint16_t height);

// *****************************************************************************
/* Function:
    void LCDC_SetUseDMAPathEnable(LCDC_LAYER_ID layer, bool enable)

   Summary:
    Enables/disables the DMA path for the specified layer

   Description:
    None

   Precondition:
    None.

   Parameters:
    layer - the target layer
    enable - if true, the DMA channel retrieves pixels from memory
             if false, the default layer color is used

   Returns:
    None

   Remarks:
*/
void LCDC_SetUseDMAPathEnable(LCDC_LAYER_ID layer, bool enable);

// *****************************************************************************
/* Function:
    void LCDC_SetDMAAddressRegister(LCDC_LAYER_ID layer, uint32_t addr)

   Summary:
    Sets the Frame Buffer base address

   Description:
    None

   Precondition:
    None.

   Parameters:
    layer - the target layer
    addr - the frame buffer base address

   Returns:
    None

   Remarks:
*/
void LCDC_SetDMAAddressRegister(LCDC_LAYER_ID layer, uint32_t addr);

// *****************************************************************************
/* Function:
    void LCDC_SetDMADescriptorNextAddress(LCDC_LAYER_ID layer, uint32_t next)

   Summary:
    Sets next DMA descriptor address

   Description:
    None

   Precondition:
    None.

   Parameters:
    layer - the target layer
    next - the next DMA descriptor address

   Returns:
    None

   Remarks:
*/
void LCDC_SetDMADescriptorNextAddress(LCDC_LAYER_ID layer, uint32_t next);

// *****************************************************************************
/* Function:
    void LCDC_SetTransferDescriptorFetchEnable(LCDC_LAYER_ID layer, bool enable)

   Summary:
    Enables/disables Transfer Descriptor Fetch

   Description:
    None

   Precondition:
    None.

   Parameters:
    layer - the target layer
    enable - if true, Transfer Descriptor Fetch is enabled. Disabled if false.

   Returns:
    None

   Remarks:
*/
void LCDC_SetTransferDescriptorFetchEnable(LCDC_LAYER_ID layer, bool enable);

// *****************************************************************************
/* Function:
    void LCDC_AddToQueueEnable(LCDC_LAYER_ID layer)

   Summary:
    Indicates that a valid descriptor has been written to memory

   Description:
    Indicates that a valid descriptor has been written to memory, its memory 
    location should be written to the DMA head pointer. The A2QSR status bit 
    is set to one, and it is reset by hardware as soon as the descriptor 
    pointed to by the DMA head pointer is added to the list.

   Precondition:
    None.

   Parameters:
    layer - the target layer

   Returns:
    None

   Remarks:
*/
void LCDC_AddToQueueEnable(LCDC_LAYER_ID layer);

// *****************************************************************************
/* Function:
    void LCDC_SetChannelEnable(LCDC_LAYER_ID layer, bool enable)

   Summary:
    Enables/disables the DMA channel

   Description:
    None

   Precondition:
    None.

   Parameters:
    layer - the target layer
    enable - if true, DMA channel is enabled. Disabled if false

   Returns:
    None

   Remarks:
*/
void LCDC_SetChannelEnable(LCDC_LAYER_ID layer, bool enable);

// *****************************************************************************
/* Function:
    void LCDC_UpdateOverlayAttributesEnable(LCDC_LAYER_ID layer)

   Summary:
    Updates the layer attributes

   Description:
    Updates windows attributes on the next start of frame.

   Precondition:
    None.

   Parameters:
    layer - the target layer

   Returns:
    None

   Remarks:
*/
void LCDC_UpdateOverlayAttributesEnable(LCDC_LAYER_ID layer);

// *****************************************************************************
/* Function:
    void LCDC_SetBlenderOverlayLayerEnable(LCDC_LAYER_ID layer, bool enable)

   Summary:
    Enables/disables the overlay blender

   Description:
    None

   Precondition:
    None.

   Parameters:
    layer - the target layer
    enable - if true, overlay pixel color is set tot he DMA channel pixel color
             if false, overlay pixel color is set to the default overlay pixel color

   Returns:
    None

   Remarks:
    Only OVR1, OVR2 and HEO layers are supported
*/
void LCDC_SetBlenderOverlayLayerEnable(LCDC_LAYER_ID layer, bool enable);

// *****************************************************************************
/* Function:
    void LCDC_SetBlenderDMALayerEnable(LCDC_LAYER_ID layer, bool enable)

   Summary:
    Enables/disables the blender DMA channel

   Description:
    None

   Precondition:
    None.

   Parameters:
    layer - the target layer
    enable - if true, default color is used on the layer
             if false, DMA channel retrieves pixels from memory

   Returns:
    None

   Remarks:
    Only OVR1, OVR2 and HEO layers are supported
*/
void LCDC_SetBlenderDMALayerEnable(LCDC_LAYER_ID layer, bool enable);

// *****************************************************************************
/* Function:
    void LCDC_SetBlenderLocalAlphaEnable(LCDC_LAYER_ID layer, bool enable)

   Summary:
    Enables/disables local alpha blending

   Description:
    None

   Precondition:
    None.

   Parameters:
    layer - the target layer
    enable - if true, local alpha blending is enabled. Disabled if false.

   Returns:
    None

   Remarks:
    Only OVR1, OVR2 and HEO layers are supported
*/
void LCDC_SetBlenderLocalAlphaEnable(LCDC_LAYER_ID layer, bool enable);

// *****************************************************************************
/* Function:
    void LCDC_SetBlenderIteratedColorEnable(LCDC_LAYER_ID layer, bool enable)

   Summary:
    Enables use of iterated pixel value for final adder stage operand

   Description:
    None

   Precondition:
    None.

   Parameters:
    layer - the target layer
    use - if true, final adder stage operand is set to iterated pixel value.
          0 if false.

   Returns:
    None

   Remarks:
    Only OVR1, OVR2 and HEO layers are supported
*/
void LCDC_SetBlenderIteratedColorEnable(LCDC_LAYER_ID layer, bool enable);

// *****************************************************************************
/* Function:
    void LCDC_UpdateAttribute(LCDC_LAYER_ID layer)

   Summary:
    Updates the specified layer's window attributes

   Description:
    None

   Precondition:
    None.

   Parameters:
    layer - the target layer

   Returns:
    None

   Remarks:
    None
*/
void LCDC_UpdateAttribute(LCDC_LAYER_ID layer);

// *****************************************************************************
/* Function:
    void LCDC_SetBlenderUseIteratedColor(LCDC_LAYER_ID layer, bool use)

   Summary:
    Enables use of iterated pixel value for pixel difference

   Description:
    None

   Precondition:
    None.

   Parameters:
    layer - the target layer
    use - if true, pixel difference is set to iterated value. 0 if false.

   Returns:
    None

   Remarks:
    Only OVR1, OVR2 and HEO layers are supported
*/
void LCDC_SetBlenderUseIteratedColor(LCDC_LAYER_ID layer, bool use);

// *****************************************************************************
/* Function:
    void LCDC_SetBlenderGlobalAlpha(LCDC_LAYER_ID layer, uint8_t alpha)

   Summary:
    Sets the global alpha blending coefficient

   Description:
    None

   Precondition:
    None.

   Parameters:
    layer - the target layer
    alpha - global alpha value

   Returns:
    None

   Remarks:
    Only OVR1, OVR2 and HEO layers are supported
*/
void LCDC_SetBlenderGlobalAlpha(LCDC_LAYER_ID layer, uint8_t alpha);

// *****************************************************************************
/* Function:
    void LCDC_SetBlenderGlobalAlphaEnable(LCDC_LAYER_ID layer, bool enable)

   Summary:
    Enables/disables global alpha blending

   Description:
    None

   Precondition:
    None.

   Parameters:
    layer - the target layer
    enable - if true, global alpha is enabled. Disabled if false.

   Returns:
    None

   Remarks:
    Only OVR1, OVR2 and HEO layers are supported. Global alpha is superseded by
    local alpha.
*/
void LCDC_SetBlenderGlobalAlphaEnable(LCDC_LAYER_ID layer, bool enable);

// *****************************************************************************
/* Function:
    void LCDC_WaitForSyncInProgress( void )

   Summary:
    Waits for synchronization to complete. Unblocks when complete.

   Description:
    None

   Precondition:
    None.

   Parameters:
    None

   Returns:
    None

   Remarks:
    None
*/
void LCDC_WaitForSyncInProgress( void );

// *****************************************************************************
/* Function:
    void LCDC_WaitForClockRunning( void )

   Summary:
    Waits for pixel clock to start running. Blocks until PCLK is running.

   Description:
    None

   Precondition:
    None.

   Parameters:
    None

   Returns:
    None

   Remarks:
    None
*/
void LCDC_WaitForClockRunning( void );

// *****************************************************************************
/* Function:
    void LCDC_WaitForSynchronization( void )

   Summary:
    Waits for timing engine to start running. Blocks until Timing engine is running.

   Description:
    None

   Precondition:
    None.

   Parameters:
    None

   Returns:
    None

   Remarks:
    None
*/
void LCDC_WaitForSynchronization( void );

// *****************************************************************************
/* Function:
    void LCDC_WaitForDISPSignal( void )

   Summary:
    Waits for DISP signal to be activated. Blocks until Timing engine is activated.

   Description:
    None

   Precondition:
    None.

   Parameters:
    None

   Returns:
    None

   Remarks:
    None
*/
void LCDC_WaitForDISPSignal( void );

#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif

#endif // _PLIB_LCDC_H
