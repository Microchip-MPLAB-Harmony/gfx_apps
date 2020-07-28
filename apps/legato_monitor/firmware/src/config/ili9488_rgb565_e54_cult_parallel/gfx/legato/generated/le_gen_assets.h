/*******************************************************************************
 Module for Microchip Legato Graphics Library

  Company:
    Microchip Technology Inc.

  File Name:
    le_gen_assets.h

  Summary:
    Header file containing a list of asset specifications for use with the
    Legato Graphics Stack.


  Description:
    Header file containing a list of asset specifications for use with the
    Legato Graphics Stack.

*******************************************************************************/


// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C)  Microchip Technology Inc. and its subsidiaries.
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

#ifndef LE_GEN_ASSETS_H
#define LE_GEN_ASSETS_H

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

#include "gfx/legato/legato.h"

extern const lePalette leGlobalPalette;

/*****************************************************************************
 * Legato Graphics Image Assets
 *****************************************************************************/
/*********************************
 * Legato Image Asset
 * Name:   Background
 * Size:   320x480 pixels
 * Type:   RGB Data
 * Format: RGB_565
 ***********************************/
extern leImage Background;

/*********************************
 * Legato Image Asset
 * Name:   heart
 * Size:   25x25 pixels
 * Type:   RGB Data
 * Format: RGB_565
 ***********************************/
extern leImage heart;

/*********************************
 * Legato Image Asset
 * Name:   Microchip_meatball
 * Size:   42x30 pixels
 * Type:   RGB Data
 * Format: RGB_565
 ***********************************/
extern leImage Microchip_meatball;

/*********************************
 * Legato Image Asset
 * Name:   MHGC_170x170
 * Size:   170x170 pixels
 * Type:   RGB Data
 * Format: RGB_565
 ***********************************/
extern leImage MHGC_170x170;

/*********************************
 * Legato Image Asset
 * Name:   Bar_320
 * Size:   320x65 pixels
 * Type:   RGB Data
 * Format: RGB_565
 ***********************************/
extern leImage Bar_320;

/*********************************
 * Legato Image Asset
 * Name:   MicrochipLogo
 * Size:   144x39 pixels
 * Type:   RGB Data
 * Format: RGB_565
 ***********************************/
extern leImage MicrochipLogo;

/*****************************************************************************
 * Legato Graphics Font Assets
 *****************************************************************************/
/*********************************
 * Legato Font Asset
 * Name:         NotoSans_Regular
 * Height:       21
 * Baseline:     13
 * Style:        Antialias
 * Glyph Count:  11
 * Range Count:  1
 * Glyph Ranges: 0x30-0x3A
***********************************/
extern leRasterFont NotoSans_Regular;

/*********************************
 * Legato Font Asset
 * Name:         NotoSans_Bold
 * Height:       21
 * Baseline:     55
 * Style:        Antialias
 * Glyph Count:  12
 * Range Count:  3
 * Glyph Ranges: 0x20
                 0x2D
                 0x30-0x39
***********************************/
extern leRasterFont NotoSans_Bold;

/*****************************************************************************
 * Legato String Table
 * Encoding        ASCII
 * Language Count: 1
 * String Count:   5
 *****************************************************************************/

// language IDs
#define language_default    0

// string IDs
#define stringID_ClockNums    0
#define stringID_ClearVal    1
#define stringID_DefaultTime    2
#define stringID_Nums    3
#define stringID_Default    4

extern const leStringTable stringTable;

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* LE_GEN_ASSETS_H */
