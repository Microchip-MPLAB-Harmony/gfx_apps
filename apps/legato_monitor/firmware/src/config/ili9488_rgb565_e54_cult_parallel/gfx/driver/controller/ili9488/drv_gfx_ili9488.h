/*******************************************************************************
  MPLAB Harmony Generated Driver Header File

  File Name:
    drv_gfx_ili9488.h

  Summary:
    Build-time generated header file for ILI9488 driver.
	
  Description:
    Build-time generated header file for top-level ILI9488 driver.
 * 
    Created with MPLAB Harmony Version 2.03
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

#ifndef DRV_GFX_ILI9488_H
#define DRV_GFX_ILI9488_H

#include "gfx/legato/renderer/legato_driver.h"

#ifdef __cplusplus
    extern "C" {
#endif
 

//DOM-IGNORE-END

leResult DRV_ILI9488_Initialize(void);

leColorMode DRV_ILI9488_GetColorMode(void);
uint32_t DRV_ILI9488_GetBufferCount(void);
uint32_t DRV_ILI9488_GetDisplayWidth(void);
uint32_t DRV_ILI9488_GetDisplayHeight(void);
void DRV_ILI9488_Update(void);
uint32_t DRV_ILI9488_GetLayerCount();
uint32_t DRV_ILI9488_GetActiveLayer();
leResult DRV_ILI9488_SetActiveLayer(uint32_t idx);
leResult DRV_ILI9488_BlitBuffer(int32_t x, int32_t y, lePixelBuffer* buf);
void DRV_ILI9488_Swap(void);
uint32_t DRV_ILI9488_GetSwapCount(void);


static const leDisplayDriver ili9488DisplayDriver =
{
    DRV_ILI9488_GetColorMode,
    DRV_ILI9488_GetBufferCount,
    DRV_ILI9488_GetDisplayWidth,
    DRV_ILI9488_GetDisplayHeight,
    DRV_ILI9488_Update,
    DRV_ILI9488_GetLayerCount,
    DRV_ILI9488_GetActiveLayer,
    DRV_ILI9488_SetActiveLayer,
    DRV_ILI9488_BlitBuffer,
    DRV_ILI9488_Swap,
    DRV_ILI9488_GetSwapCount
};

#ifdef __cplusplus
    }
#endif
    
#endif // DRV_GFX_ILI9488_H