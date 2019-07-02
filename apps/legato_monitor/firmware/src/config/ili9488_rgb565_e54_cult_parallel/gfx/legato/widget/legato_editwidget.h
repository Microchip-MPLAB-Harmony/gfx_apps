/*******************************************************************************
 Module for Microchip Graphics Library - Legato User Interface Library

  Company:
    Microchip Technology Inc.

  File Name:
    legato_editwidget.h

  Summary:
    

  Description:
    This module implements the routines to enable edit of library widgets.
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

#ifndef LEGATO_EDITWIDGET_H
#define LEGATO_EDITWIDGET_H
//DOM-IGNORE-END

#include "gfx/legato/common/legato_common.h"
#include "gfx/legato/widget/legato_widget.h"
#include "gfx/legato/string/legato_string.h"

// DOM-IGNORE-BEGIN
typedef struct leEditWidget leEditWidget;

#define LE_EDITWIDGET_VTABLE(THIS_TYPE) \
    LE_WIDGET_VTABLE(THIS_TYPE) \
    \
    leResult (*editStart)(THIS_TYPE* _this); \
    void     (*editEnd)(THIS_TYPE* _this); \
    void     (*editClear)(THIS_TYPE* _this); \
    void     (*editAccept)(THIS_TYPE* _this); \
    void     (*editSet)(THIS_TYPE* _this, const leString* str); \
    void     (*editAppend)(THIS_TYPE* _this, const leString* str); \
    void     (*editBackspace)(THIS_TYPE* _this); \
    
typedef struct leEditWidgetVTable
{
	LE_EDITWIDGET_VTABLE(leEditWidget)
} leEditWidgetVTable; 

// DOM-IGNORE-END

/* Structure:
        leEditWidget

    Summary:
        Specifies the edit widget structure to manage all properties and events
        associated with edit widgets

    Description:
        Edit widgets are a subset of normal widgets that are capable of receiving
        edit events from the UI kernel.  Specialized widgets are capable of
        broadcasting edit events and the active edit event will react to them.

    Remarks:
        None.
        
*/
typedef struct leEditWidget
{
    leWidget widget;
    
    leEditWidgetVTable* fn;
    
} leEditWidget;

// DOM-IGNORE-BEGIN
leResult _leEditWidget_StartEdit();
void _leEditWidget_EndEdit();

void _leEditWidget_Clear();
void _leEditWidget_Accept();
void _leEditWidget_Set(const leString* str);
void _leEditWidget_Append(const leString* str);
void _leEditWidget_Backspace();
// DOM-IGNORE-END

#endif // LEGATO_EDITWIDGET_H
