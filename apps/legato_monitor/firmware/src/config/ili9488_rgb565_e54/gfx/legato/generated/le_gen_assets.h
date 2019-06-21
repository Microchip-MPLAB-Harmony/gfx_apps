/*******************************************************************************
 Module for Microchip Legato Graphics Library

  Company:
    Microchip Technology Inc.

  File Name:
    generated/le_gen_assets.h

  Summary:
    Header file containing a list of asset specifications for use with the
    MPLAB Harmony Graphics Stack.

  Description:
    Header file containing a list of asset specifications for use with the
    MPLAB Harmony Graphics Stack.
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

#ifndef LE_GEN_ASSETS_H
#define LE_GEN_ASSETS_H

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

#include "gfx/legato/legato.h"

/*****************************************************************************
* MPLAB Harmony Graphics Asset Location IDs
*****************************************************************************/
/*****************************************************************************
* MPLAB Harmony Graphics Image Assets
*****************************************************************************/
/*********************************
 * Legato Image Asset
 * Name:   _1200px_Heart_coraz_n
 * Size:   31x31 pixels
 * Format: Raw
 * Mode: INDEX_8
 ***********************************/
extern leImage _1200px_Heart_coraz_n;

/*********************************
 * Legato Image Asset
 * Name:   Battery
 * Size:   64x24 pixels
 * Format: Raw
 * Mode: INDEX_1
 ***********************************/
extern leImage Battery;

/*********************************
 * Legato Image Asset
 * Name:   Microchip_logo
 * Size:   100x20 pixels
 * Format: Raw
 * Mode: INDEX_8
 ***********************************/
extern leImage Microchip_logo;

/*********************************
 * Legato Image Asset
 * Name:   BannerLeft
 * Size:   105x397 pixels
 * Format: Raw
 * Mode: INDEX_4
 ***********************************/
extern leImage BannerLeft;

/*****************************************************************************
* MPLAB Harmony Graphics Palette Assets
*****************************************************************************/
/*********************************
 * Legato Palette Asset
 * Mode:   RGB_565
 * Size:   2
 ***********************************/
extern lePalette leGenPalette1;

/*********************************
 * Legato Palette Asset
 * Mode:   RGB_565
 * Size:   20
 ***********************************/
extern lePalette leGenPalette0;

/*********************************
 * Legato Palette Asset
 * Mode:   RGB_565
 * Size:   3
 ***********************************/
extern lePalette leGenPalette3;

/*********************************
 * Legato Palette Asset
 * Mode:   RGB_565
 * Size:   161
 ***********************************/
extern lePalette leGenPalette2;

/*****************************************************************************
* MPLAB Harmony Graphics Font Assets
*****************************************************************************/
/*********************************
 * Legato Font Asset
 * Name:         Arial48
 * Height:       38
 * Baseline:     36
 * Style:        Plain
 * Glyph Count:  5
 * Range Count:  5
 * Glyph Ranges: 0x41
                 0x44
                 0x49
                 0x53
                 0x59
***********************************/
extern leFont Arial48;

/*********************************
 * Legato Font Asset
 * Name:         Arial30
 * Height:       23
 * Baseline:     22
 * Style:        Plain
 * Glyph Count:  5
 * Range Count:  5
 * Glyph Ranges: 0x45
                 0x4C
                 0x50
                 0x53
                 0x55
***********************************/
extern leFont Arial30;

/*********************************
 * Legato Font Asset
 * Name:         Arial14
 * Height:       14
 * Baseline:     10
 * Style:        Plain
 * Glyph Count:  18
 * Range Count:  12
 * Glyph Ranges: 0x20
                 0x2C
                 0x2F-0x32
                 0x36
                 0x39
                 0x48
                 0x4D
                 0x61
                 0x63
                 0x67-0x69
                 0x6D-0x6E
                 0x72
***********************************/
extern leFont Arial14;

/*********************************
 * Legato Font Asset
 * Name:         Calibri98
 * Height:       65
 * Baseline:     63
 * Style:        Plain
 * Glyph Count:  2
 * Range Count:  2
 * Glyph Ranges: 0x34
                 0x38
***********************************/
extern leFont Calibri98;

/*********************************
 * Legato Font Asset
 * Name:         Calibri
 * Height:       49
 * Baseline:     47
 * Style:        Plain
 * Glyph Count:  10
 * Range Count:  1
 * Glyph Ranges: 0x30-0x39
***********************************/
extern leFont Calibri;

/*********************************
 * Legato Font Asset
 * Name:         CourierNew
 * Height:       63
 * Baseline:     61
 * Style:        Plain
 * Glyph Count:  11
 * Range Count:  2
 * Glyph Ranges: 0x20
                 0x30-0x39
***********************************/
extern leFont CourierNew;

/*****************************************************************************
 * Legato String Table
 * Encoding        ASCII
 * Language Count: 1
 * String Count:   11
*****************************************************************************/

// language IDs
#define language_default    0

// string IDs
#define string_Date    0
#define string_Dia    1
#define string_DiaDefaultValue    2
#define string_PULSE    3
#define string_PulseDefaultValue    4
#define string_PulseValueNums    5
#define string_Sys    6
#define string_SysDefaultValue    7
#define string_SysDiaValueNums    8
#define string_mmhg    9
#define string_permin    10

extern const leStringTable stringTable;
//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* LE_GEN_ASSETS_H */
