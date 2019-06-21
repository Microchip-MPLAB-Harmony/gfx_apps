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

#include "gfx/legato/widget/textfield/legato_widget_textfield.h"

#if LE_TEXTFIELD_WIDGET_ENABLED

#include "gfx/legato/common/legato_error.h"
#include "gfx/legato/common/legato_utils.h"
#include "gfx/legato/core/legato_state.h"
#include "gfx/legato/memory/legato_memory.h"
#include "gfx/legato/string/legato_string.h"
#include "gfx/legato/widget/legato_widget.h"

#define DEFAULT_WIDTH           100
#define DEFAULT_HEIGHT          25

#define DEFAULT_CURSOR_TIME     1000

static leTextFieldWidgetVTable textFieldWidgetVTable;

void _leTextFieldWidget_GetTextRect(const leTextFieldWidget* _this,
                                    leRect* textRect,
                                    leRect* drawRect);
                                    
void _leTextFieldWidget_GetCursorRect(const leTextFieldWidget* _this,
                                      leRect* cursorRect);

static void _invalidateText(const leTextFieldWidget* _this)
{
    leRect textRect, drawRect;
    
    _leTextFieldWidget_GetTextRect(_this, &textRect, &drawRect);
    
    _this->fn->_damageArea(_this, &drawRect);
}

static void _invalidateCursor(const leTextFieldWidget* _this)
{
    leRect cursorRect;
    
    _leTextFieldWidget_GetCursorRect(_this, &cursorRect);
    
    _this->fn->_damageArea(_this, &cursorRect);
}

static void _setCursorFromPoint(leTextFieldWidget* _this,
                                const lePoint* pnt)
{
    leRect textRect;
    
    _this->text.fn->getRect(&_this->text, 0, &textRect);
    
    leUtils_ArrangeRectangleRelative(&textRect,
                                     leRect_Zero,
                                     _this->editWidget.widget.rect,
                                     _this->editWidget.widget.halign,
                                     LE_VALIGN_MIDDLE,
                                     0,
                                     _this->editWidget.widget.margin.left,
                                     _this->editWidget.widget.margin.top,
                                     _this->editWidget.widget.margin.right,
                                     _this->editWidget.widget.margin.bottom,
                                     0);
    
    leUtils_RectToScreenSpace((leWidget*)_this, &textRect);
    
    //leTextFieldWidget_SetCursorPosition(_this, leString_GetCharIndexAtPoint(&_this->text, pnt->x - _this->editWidget.widget.rect.x));
}

void leEditWidget_Constructor(leEditWidget* editWgt);

void leTextFieldWidget_Constructor(leTextFieldWidget* _this)
{
    LE_ASSERT_THIS();
    
    leEditWidget_Constructor((leEditWidget*)_this);

    _this->editWidget.widget.fn = (void*)&textFieldWidgetVTable;
    _this->editWidget.fn = (void*)&textFieldWidgetVTable;
    _this->fn = &textFieldWidgetVTable;
    
    _this->editWidget.widget.type = LE_WIDGET_TEXTFIELD;

    // override base class methods
    /*_this->editWidget.widget.update = (leWidget_Update_FnPtr)&_leTextFieldWidget_Update;
    _this->editWidget.widget.paint = (leWidget_Paint_FnPtr)&_leTextFieldWidget_Paint;
    _this->editWidget.widget.focusGained = (leWidget_Focus_FnPtr)&_leTextFieldWidget_FocusGained;
    _this->editWidget.widget.focusLost = (leWidget_Focus_FnPtr)&_leTextFieldWidget_FocusLost;
    _this->editWidget.widget.touchDown = (leWidget_TouchDownEvent_FnPtr)&_leTextFieldWidget_TouchDownEvent;
    _this->editWidget.widget.touchUp = (leWidget_TouchUpEvent_FnPtr)&_leTextFieldWidget_TouchUpEvent;
    _this->editWidget.widget.touchMoved = (leWidget_TouchMovedEvent_FnPtr)&_leTextFieldWidget_TouchMovedEvent;*/

    // override edit class methods
    /*_this->editWidget.startEdit = (leEditWidget_StartEdit_FnPtr)&startEdit;
    _this->editWidget.endEdit = (leEditWidget_EndEdit_FnPtr)&endEdit;
    _this->editWidget.clear = (leEditWidget_Clear_FnPtr)&clear;
    _this->editWidget.accept = (leEditWidget_Accept_FnPtr)&accept;
    _this->editWidget.append = (leEditWidget_Append_FnPtr)&append;
    _this->editWidget.set = (leEditWidget_Set_FnPtr)&set;
    _this->editWidget.backspace = (leEditWidget_Backspace_FnPtr)&backspace;*/

    _this->editWidget.widget.rect.width = DEFAULT_WIDTH;
    _this->editWidget.widget.rect.height = DEFAULT_HEIGHT;
    
    _this->editWidget.widget.borderType = LE_WIDGET_BORDER_BEVEL;

    leDynamicString_Constructor(&_this->text);
    _this->hintText = NULL;
    
    _this->editWidget.widget.halign = LE_HALIGN_LEFT;
    _this->cursorEnable = LE_TRUE;
    _this->cursorDelay = DEFAULT_CURSOR_TIME;
    _this->clearOnFirstEdit = LE_TRUE;
}

void _leEditWidget_Destructor(leEditWidget* edit);

static void destructor(leTextFieldWidget* _this)
{
    _this->text.fn->destructor(&_this->text);
    _this->hintText = NULL;
    
    _leEditWidget_Destructor((leEditWidget*)_this);
}

leTextFieldWidget* leTextFieldWidget_New()
{
    leTextFieldWidget* txt = NULL;

    txt = LE_MALLOC(sizeof(leTextFieldWidget));

    leTextFieldWidget_Constructor(txt);

    return txt;
}

static void update(leTextFieldWidget* _this,
                   uint32_t dt)
{   
    LE_ASSERT_THIS();
    
    if(leGetEditWidget() == (leEditWidget*)_this)
    {
        _this->cursorTime += dt;
        
        if(_this->cursorTime > _this->cursorDelay)
        {
            _this->cursorVisible = !_this->cursorVisible;
            
            //printf("%u\n", _this->cursorTime);
            
            _this->cursorTime = 0;
            
            _invalidateCursor(_this);
        }
    }
}

static uint32_t getCursorDelay(const leTextFieldWidget* _this)
{
    LE_ASSERT_THIS();

    return _this->cursorDelay;
}

static leResult setCursorDelay(leTextFieldWidget* _this,
                               uint32_t dt)
{
    LE_ASSERT_THIS();
    
    if(_this->cursorDelay == dt)
        return LE_FAILURE;

    _this->cursorDelay = dt;

    if(_this->cursorEnable == LE_TRUE && _this->cursorVisible == LE_TRUE)
    {
        _invalidateCursor(_this);
    }
        
    return LE_SUCCESS;
}

static leBool getCursorEnabled(const leTextFieldWidget* _this)
{
    LE_ASSERT_THIS();

    return _this->cursorEnable;
}

static leResult setCursorEnabled(leTextFieldWidget* _this,
                                 leBool en)
{
    LE_ASSERT_THIS();
    
    if(_this->cursorEnable == en)
        return LE_FAILURE;

    _this->cursorEnable = en;

    if(_this->cursorEnable == LE_TRUE && _this->cursorVisible == LE_TRUE)
    {
        _invalidateCursor(_this);
    }
        
    return LE_SUCCESS;
}

static uint32_t getCursorPosition(const leTextFieldWidget* _this)
{
    LE_ASSERT_THIS();

    return _this->cursorPos;
}

static leResult setCursorPosition(leTextFieldWidget* _this,
                                  uint32_t pos)
{
    LE_ASSERT_THIS();
    
    if(_this->cursorPos == pos)
        return LE_FAILURE;

    _this->cursorPos = pos;

    if(_this->cursorVisible == LE_TRUE)
    {
        _invalidateCursor(_this);
    }
        
    return LE_SUCCESS;
}

const static leString* getText(const leTextFieldWidget* _this)
{
    LE_ASSERT_THIS();
    
    return (const leString*)&_this->text;
}

static leResult setText(leTextFieldWidget* _this,
                        const leString* str)
{
    LE_ASSERT_THIS();
    
    _invalidateText(_this);
    
    _this->text.fn->setFromString(&_this->text, str);
    _this->cursorPos = _this->text.length;
    
    _invalidateText(_this);
    
    return LE_SUCCESS;
}

static leString* getHintText(const leTextFieldWidget* _this)
{
    LE_ASSERT_THIS();
    
    return (leString*)_this->hintText;
}

static leResult setHintText(leTextFieldWidget* _this,
                            const leString* str)
{
    LE_ASSERT_THIS();
    
    _invalidateText(_this);
    
    _this->hintText = str;
    
    _invalidateText(_this);
    
    return LE_SUCCESS;
}

static leResult setClearHintOnEdit(leTextFieldWidget* _this,
                                   leBool clear)
{
    LE_ASSERT_THIS();
    
    if(_this->clearOnFirstEdit == clear)
        return LE_FAILURE;

    _this->clearOnFirstEdit = clear;

    return LE_SUCCESS;
}

static void handleFocusGainedEvent(leTextFieldWidget* _this)
{
    LE_ASSERT_THIS();
    
    leSetEditWidget((leEditWidget*)_this);
    
    if (_this->focusChangedEvent != NULL)
    {
        _this->focusChangedEvent(_this, LE_TRUE);
    }
}

static void handleFocusLostEvent(leTextFieldWidget* _this)
{
    LE_ASSERT_THIS();
    
    if (_this->focusChangedEvent != NULL)
    {
        _this->focusChangedEvent(_this, LE_FALSE);
    }
}

static leTextFieldWidget_TextChangedCallback getTextChangedEventCallback(const leTextFieldWidget* _this)
{
    LE_ASSERT_THIS();

    return _this->textChangedEvent;
}

static leResult setTextChangedEventCallback(leTextFieldWidget* _this,
                                            leTextFieldWidget_TextChangedCallback cb)
{   
    LE_ASSERT_THIS();
    
    if(_this->textChangedEvent == cb)
        return LE_FAILURE;

    _this->textChangedEvent = cb;

    return LE_SUCCESS;
}

static leTextFieldWidget_FocusChangedCallback getFocusChangedEventCallback(const leTextFieldWidget* _this)
{
    LE_ASSERT_THIS();

    return _this->focusChangedEvent;
}

static leResult setFocusChangedEventCallback(leTextFieldWidget* _this,
                                             leTextFieldWidget_FocusChangedCallback cb)
{
    LE_ASSERT_THIS();
    
    if(_this->focusChangedEvent == cb)
        return LE_FAILURE;

    _this->focusChangedEvent = cb;

    return LE_SUCCESS;
}

static leResult editStart(leTextFieldWidget* _this)
{
    LE_ASSERT_THIS();
    
    _this->cursorTime = 0;
    _this->cursorVisible = LE_TRUE;

    if (_this->clearOnFirstEdit == LE_TRUE)
    {
        _invalidateText(_this);
        
        //leString_Clear(&_this->text);
        _this->clearOnFirstEdit  = LE_FALSE;
    }
    else
    {
        _invalidateCursor(_this);
    }
    
    return LE_SUCCESS;
}

static void editEnd(leTextFieldWidget* _this)
{
    LE_ASSERT_THIS();
    
    _this->cursorTime = 0;
    _this->cursorVisible = LE_FALSE;
    
    _invalidateCursor(_this);
}

static void editClear(leTextFieldWidget* _this)
{
    LE_ASSERT_THIS();
    
    _invalidateText(_this);
    _invalidateCursor(_this);
    
    _this->text.fn->clear(&_this->text);

    if (_this->textChangedEvent != NULL)
    {
        _this->textChangedEvent(_this);
    }
}

static void editAccept(leTextFieldWidget* _this)
{   
    LE_ASSERT_THIS();
    
    //leGetState()->
    //leContext_SetEditWidget(NULL);
}

static void editAppend(leTextFieldWidget* _this,
                       const leString* str)
{
    LE_ASSERT_THIS();
    
    // initial string value is probably referencing string table
    // extract it to local cache and to make editable
    //if(_this->text.table_index != LE_STRING_NULLIDX)
    //    leString_ExtractFromTable(&_this->text, _this->text.table_index);

    //_invalidateText(_this);
    //_invalidateCursor(_this);
    
//    _this->text.fn->insert(&_this->text, &str, _this->cursorPos);
//    
//    _this->cursorPos += str.fn->length(&str);
//    
//    if(_this->cursorEnable == LE_TRUE)
//    {
//        _this->cursorTime = 0;
//        _this->cursorVisible = LE_TRUE;
//    }
//    
//    _invalidateText(_this);
//    _invalidateCursor(_this);
//
//    if (_this->textChangedEvent != NULL)
//    {
//        _this->textChangedEvent(_this);
//    }
}

static void editSet(leTextFieldWidget* _this,
                    const leString* str)
{
    LE_ASSERT_THIS();
    
    _invalidateText(_this);
    _invalidateCursor(_this);
    
    _this->text.fn->setFromString(&_this->text, str);
    
    _this->cursorPos = _this->text.length;
    
    if(_this->cursorEnable == LE_TRUE)
    {
        _this->cursorTime = 0;
        _this->cursorVisible = LE_TRUE;
    }

    _invalidateText(_this);
    _invalidateCursor(_this);

    if (_this->textChangedEvent != NULL)
    {
        _this->textChangedEvent(_this);
    }
}

static void editBackspace(leTextFieldWidget* _this)
{
    LE_ASSERT_THIS();
    
    if(_this->cursorPos == 0)
        return;
        
    _invalidateText(_this);
    _invalidateCursor(_this);
    
    _this->text.fn->remove(&_this->text, _this->cursorPos - 1, 1);
        
    if(_this->cursorPos > _this->text.length)
    {
        _this->cursorPos = _this->text.length;
    }
    else
    {
        _this->cursorPos--;
    }
        
    if(_this->cursorEnable == LE_TRUE)
    {
        _this->cursorTime = 0;
        _this->cursorVisible = LE_TRUE;
    }

    _invalidateText(_this);
    _invalidateCursor(_this);

    if (_this->textChangedEvent != NULL)
    {
        _this->textChangedEvent(_this);
    }
}

static void handleTouchDownEvent(leTextFieldWidget* _this,
                                 leInput_TouchDownEvent* evt)
{
    lePoint pnt;
    
    LE_ASSERT_THIS();
    
    pnt.x = evt->x;
    pnt.y = evt->y;
    
    _setCursorFromPoint(_this, &pnt);
    
    evt->event.accepted = LE_TRUE;
}

static void handleTouchUpEvent(leTextFieldWidget* _this,
                               leInput_TouchUpEvent* evt)
{
    LE_ASSERT_THIS();
    
    evt->event.accepted = LE_TRUE;
}

static void handleTouchMovedEvent(leTextFieldWidget* _this,
                                  leInput_TouchMoveEvent* evt)
{
    LE_ASSERT_THIS();
    
    /*lePoint pnt;
    
    pnt.x = evt->x;
    pnt.y = evt->y;
    
    _setCursorFromPoint(_this, &pnt);*/
    
    evt->event.accepted = LE_TRUE;
}

void _leEditWidget_FillVTable(leEditWidgetVTable* tbl);
void _leTextFieldWidget_Paint(leTextFieldWidget* _this);

void _leTextFieldWidget_GenerateVTable()
{
    _leEditWidget_FillVTable((void*)&textFieldWidgetVTable);
    
    /* overrides from base class */
    textFieldWidgetVTable._destructor = destructor;
    textFieldWidgetVTable._paint = _leTextFieldWidget_Paint;
    textFieldWidgetVTable.update = update;
    textFieldWidgetVTable.touchDownEvent = handleTouchDownEvent;
    textFieldWidgetVTable.touchUpEvent = handleTouchUpEvent;
    textFieldWidgetVTable.touchMoveEvent = handleTouchMovedEvent;
    textFieldWidgetVTable.focusLostEvent = handleFocusLostEvent;
    textFieldWidgetVTable.focusGainedEvent = handleFocusGainedEvent;
    
    /* override from edit widget */
    textFieldWidgetVTable.editStart = editStart;
    textFieldWidgetVTable.editEnd = editEnd;
    textFieldWidgetVTable.editClear = editClear;
    textFieldWidgetVTable.editAccept = editAccept;
    textFieldWidgetVTable.editSet = editSet;
    textFieldWidgetVTable.editAppend = editAppend;
    textFieldWidgetVTable.editBackspace = editBackspace;
    
    /* member functions */
    textFieldWidgetVTable.getCursorDelay = getCursorDelay;
    textFieldWidgetVTable.setCursorDelay = setCursorDelay;
    textFieldWidgetVTable.getCursorEnabled = getCursorEnabled;
    textFieldWidgetVTable.setCursorEnabled = setCursorEnabled;
    textFieldWidgetVTable.getCursorPosition = getCursorPosition;
    textFieldWidgetVTable.setCursorPosition = setCursorPosition;
    textFieldWidgetVTable.getText = getText;
    textFieldWidgetVTable.setText = setText;
    textFieldWidgetVTable.getHintText = getHintText;
    textFieldWidgetVTable.setHintText = setHintText;
    textFieldWidgetVTable.setClearHintOnEdit = setClearHintOnEdit;
    textFieldWidgetVTable.getTextChangedEventCallback = getTextChangedEventCallback;
    textFieldWidgetVTable.setTextChangedEventCallback = setTextChangedEventCallback;
    textFieldWidgetVTable.getFocusChangedEventCallback = getFocusChangedEventCallback;
    textFieldWidgetVTable.setFocusChangedEventCallback = setFocusChangedEventCallback;
}

void _leTextFieldWidget_FillVTable(leTextFieldWidgetVTable* tbl)
{
    *tbl = textFieldWidgetVTable;
}

#endif // LE_TEXTFIELD_WIDGET_ENABLED
