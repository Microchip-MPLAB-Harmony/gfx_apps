/*******************************************************************************
 Module for Microchip Graphics Library - Legato User Interface Library

  Company:
    Microchip Technology Inc.

  File Name:
    legato_stringutils.h

  Summary:


  Description:
    This module implements various string utility functions.
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
//DOM-IGNORE-END

#ifndef LE_STRINGUTILS_H
#define LE_STRINGUTILS_H

#include "gfx/legato/string/legato_string.h"

uint32_t leStringUtils_FromCStr(const char* str,
                                leChar* buf,
                                uint32_t size);

uint32_t leStringUtils_ToCStr(const leChar* str,
                              uint32_t strSize,
                              char* buf,
                              uint32_t bufSize);

leResult leStringUtils_GetRect(const leChar* str,
                               uint32_t size,
                               const leFont* font,
                               leRect* rect);

leResult leStringUtils_GetRectCStr(const char* str,
                                   const leFont* font,
                                   leRect* rect);

uint32_t leStringUtils_GetLineCount(const leChar* str,
                                    uint32_t size);

uint32_t leStringUtils_GetLineCountCStr(const char* str);

leResult leStringUtils_GetLineIndices(const leChar* str,
                                      uint32_t size,
                                      uint32_t line,
                                      uint32_t* start,
                                      uint32_t* end);

leResult leStringUtils_GetLineIndicesCStr(const char* str,
                                          uint32_t line,
                                          uint32_t* start,
                                          uint32_t* end);

leResult leStringUtils_GetLineRect(const leChar* str,
                                   uint32_t size,
                                   const leFont* font,
                                   uint32_t line,
                                   leRect* rect);

leResult leStringUtils_GetLineRectCStr(const char* str,
                                       const leFont* font,
                                       uint32_t line,
                                       leRect* rect);

leResult leStringUtils_GetCharRect(const leChar* str,
                                   uint32_t size,
                                   const leFont* font,
                                   uint32_t charIdx,
                                   leRect* rect);

leResult leStringUtils_GetCharRectCStr(const char* str,
                                       const leFont* font,
                                       uint32_t charIdx,
                                       leRect* rect);

leResult leStringUtils_GetCharIndexAtPoint(const leChar* str,
                                           uint32_t size,
                                           const leFont* font,
                                           lePoint pt,
                                           uint32_t* charIdx);

leResult leStringUtils_GetCharIndexAtPointCStr(const char* str,
                                               const leFont* font,
                                               lePoint pt,
                                               uint32_t* charIdx);

leResult leDecodeCodePoint(uint32_t encoding,
                           uint8_t* data,
                           uint32_t max,
                           uint32_t* codePoint,
                           uint32_t* offset);

#endif /* LE_STRINGUTILS_H */
