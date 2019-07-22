/*******************************************************************************
 Module for Microchip Graphics Library - Legato User Interface Library

  Company:
    Microchip Technology Inc.

  File Name:
    legato_driver.h

  Summary:
    Abstract display driver definition for the Legato graphics library.

  Description:
    Abstract display driver definition for the Legato graphics library.
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

#ifndef LEGATO_DRIVER_H
#define LEGATO_DRIVER_H

#include "gfx/legato/common/legato_pixelbuffer.h"

typedef struct leDisplayDriver
{
    leColorMode (*getColorMode)(void);
    
    uint32_t (*getBufferCount)(void);
    
    uint32_t (*getDisplayWidth)(void);
    
    uint32_t (*getDisplayHeight)(void);
    
    void (*update)(void);
    
    uint32_t (*getLayerCount)(void);
    
    uint32_t (*getActiveLayer)(void);
    
    leResult (*setActiveLayer)(uint32_t idx);
    
    leResult (*blitBuffer)(int32_t x,
                           int32_t y,
                           lePixelBuffer* buf);
                           
    void (*swap)(void);
    
    uint32_t (*getVSYNCCount)(void);
} leDisplayDriver;

#endif // LEGATO_H