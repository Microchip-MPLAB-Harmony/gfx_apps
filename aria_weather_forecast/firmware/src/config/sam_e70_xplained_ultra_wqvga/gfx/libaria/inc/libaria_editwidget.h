/*******************************************************************************
 Module for Microchip Graphics Library - Aria User Interface Library

  Company:
    Microchip Technology Inc.

  File Name:
    libaria_editwidget.h

  Summary:
    

  Description:
    This module implements the routines to enable edit of library widgets.
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

#ifndef LIBARIA_EDITWIDGET_H
#define LIBARIA_EDITWIDGET_H
//DOM-IGNORE-END

#include "gfx/libaria/inc/libaria_common.h"
#include "gfx/libaria/inc/libaria_widget.h"

typedef struct laEditWidget_t laEditWidget;
typedef struct laString_t laString;

typedef laResult (*laEditWidget_StartEdit_FnPtr)(laEditWidget*);
typedef void (*laEditWidget_EndEdit_FnPtr)(laEditWidget*);
typedef void (*laEditWidget_Clear_FnPtr)(laEditWidget*);
typedef void (*laEditWidget_Accept_FnPtr)(laEditWidget*);
typedef void (*laEditWidget_Set_FnPtr)(laEditWidget*, laString);
typedef void (*laEditWidget_Append_FnPtr)(laEditWidget*, laString);
typedef void (*laEditWidget_Backspace_FnPtr)(laEditWidget*);

/* Structure:
        laEditWidget_t

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
typedef struct laEditWidget_t
{
    laWidget widget;
    
    laEditWidget_StartEdit_FnPtr startEdit;
    laEditWidget_EndEdit_FnPtr endEdit;
    
    laEditWidget_Clear_FnPtr clear;
    laEditWidget_Accept_FnPtr accept;
    laEditWidget_Set_FnPtr set;
    laEditWidget_Append_FnPtr append;
    laEditWidget_Backspace_FnPtr backspace;
} laEditWidget;

// DOM-IGNORE-BEGIN
void _laEditWidget_Constructor(laEditWidget* edit);
void _laEditWidget_Destructor(laEditWidget* edit);
// DOM-IGNORE-END

laResult laEditWidget_StartEdit();
void laEditWidget_EndEdit();

void laEditWidget_Clear();
void laEditWidget_Accept();
void laEditWidget_Set(laString str);
void laEditWidget_Append(laString str);
void laEditWidget_Backspace();

#endif // LIBARIA_EDITWIDGET_H