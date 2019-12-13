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

#include "gfx/legato/widget/legato_editwidget.h"

#include "gfx/legato/core/legato_state.h"
#include "gfx/legato/string/legato_string.h"

//static leEditWidget* edit; // the widget that is currently receiving edit events

static leEditWidgetVTable editWidgetVTable;

/* base class constructor and destructor */
void _leWidget_Destructor(leWidget* _this);

void leEditWidget_Constructor(leEditWidget* _this)
{
    /* call base class constructor */
    leWidget_Constructor((leWidget*)_this);
    
    _this->widget.fn = (void*)&editWidgetVTable;
    _this->fn = &editWidgetVTable;
}

void _leEditWidget_Destructor(leEditWidget* _this)
{
    /* call base class destructor */
    _leWidget_Destructor((leWidget*)_this);
}

leResult _leEditWidget_EditStart(leEditWidget* _this)
{
    return LE_FAILURE;
}

void _leEditWidget_EditEnd(leEditWidget* _this)
{ }

void _leEditWidget_EditClear(leEditWidget* _this)
{ }

void _leEditWidget_EditAccept(leEditWidget* _this)
{ }

void _leEditWidget_EditSet(leEditWidget* _this,
                           const leString* str)
{ }

void _leEditWidget_EditAppend(leEditWidget* _this,
                              const leString* str)
{ }

void _leEditWidget_EditBackspace(leEditWidget* _this)
{ }

void _leWidget_FillVTable(leWidgetVTable* tbl);

void _leEditWidget_GenerateVTable()
{
    _leWidget_FillVTable((void*)&editWidgetVTable);
    
    editWidgetVTable._destructor = _leEditWidget_Destructor;
    editWidgetVTable.editStart = _leEditWidget_EditStart;
    editWidgetVTable.editEnd = _leEditWidget_EditEnd;
    editWidgetVTable.editClear = _leEditWidget_EditClear;
    editWidgetVTable.editAccept = _leEditWidget_EditAccept;
    editWidgetVTable.editSet = _leEditWidget_EditSet;
    editWidgetVTable.editAppend = _leEditWidget_EditAppend;
    editWidgetVTable.editBackspace = _leEditWidget_EditBackspace;
}

void _leEditWidget_FillVTable(leEditWidgetVTable* tbl)
{
    *tbl = editWidgetVTable;
}

void _leEditWidget_Clear()
{ 
    leEditWidget* edit = leGetEditWidget();
    
    if(edit == NULL)
        return;
        
    edit->fn->editClear(edit);
}

void _leEditWidget_Accept()
{
    leEditWidget* edit = leGetEditWidget();
    
    if(edit == NULL)
        return;
        
    edit->fn->editAccept(edit);
}

void _leEditWidget_Set(const leString* str)
{
    leEditWidget* edit = leGetEditWidget();
    
    if(edit == NULL)
        return;
        
    edit->fn->editSet(edit, str);
}

void _leEditWidget_Append(const leString* str)
{
    leEditWidget* edit = leGetEditWidget();
    
    if(edit == NULL)
        return;
        
    edit->fn->editAppend(edit, str);
}

void _leEditWidget_Backspace()
{
    leEditWidget* edit = leGetEditWidget();
    
    if(edit == NULL)
        return;
        
    edit->fn->editBackspace(edit);
}