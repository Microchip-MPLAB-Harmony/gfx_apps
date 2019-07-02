/*******************************************************************************
 Module for Microchip Graphics Library - Legato User Interface Library

  Company:
    Microchip Technology Inc.

  File Name:
    legato_widget_button.h

  Summary:
    Defines a button widget
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
#ifndef LEGATO_BUTTON_H
#define LEGATO_BUTTON_H
//DOM-IGNORE-END

#include "gfx/legato/common/legato_common.h"

#if LE_BUTTON_WIDGET_ENABLED == 1

#include "gfx/legato/widget/legato_widget.h"

#include "gfx/legato/image/legato_image.h"
#include "gfx/legato/string/legato_string.h"

// *****************************************************************************
// *****************************************************************************
// Section: Data Types and Constants
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Enumeration:
    leButtonState

  Summary:
    Controls the button pressed state
*/

typedef enum leButtonState
{
    LE_BUTTON_STATE_UP,
    LE_BUTTON_STATE_DOWN,
    LE_BUTTON_STATE_TOGGLED
} leButtonState;

typedef struct leButtonWidget leButtonWidget;

// *****************************************************************************
/* Function Pointer:
    leButtonWidget_PressedEvent

  Summary:
    Button pressed event function callback type
*/
typedef void (*leButtonWidget_PressedEvent)(leButtonWidget*);

// *****************************************************************************
/* Function Pointer:
    leButtonWidget_ReleasedEvent

  Summary:
    Button released event function callback type
*/
typedef void (*leButtonWidget_ReleasedEvent)(leButtonWidget*);


// DOM-IGNORE-BEGIN
typedef struct leButtonWidget leButtonWidget;

#define LE_BUTTONWIDGET_VTABLE(THIS_TYPE) \
    LE_WIDGET_VTABLE(THIS_TYPE) \
    \
    leBool                       (*getToggleable)(const THIS_TYPE* _this); \
    leResult                     (*setToggleable)(THIS_TYPE* _this, leBool toggleable); \
    leBool                       (*getPressed)(const THIS_TYPE* _this); \
    leResult                     (*setPressed)(THIS_TYPE* _this, leBool pressed); \
    leString*                    (*getString)(const THIS_TYPE* _this); \
    leResult                     (*setString)(THIS_TYPE* _this, const leString* str); \
    leImage*                     (*getPressedImage)(const THIS_TYPE* _this); \
    leResult                     (*setPressedImage)(THIS_TYPE* _this, leImage* img); \
    leImage*                     (*getReleasedImage)(const THIS_TYPE* _this); \
    leResult                     (*setReleasedImage)(THIS_TYPE* _this, leImage* img); \
    leRelativePosition           (*getImagePosition)(const THIS_TYPE* _this); \
    leResult                     (*setImagePosition)(THIS_TYPE* _this, leRelativePosition pos); \
    uint32_t                     (*getImageMargin)(const THIS_TYPE* _this); \
    leResult                     (*setImageMargin)(THIS_TYPE* _this, uint32_t mg); \
    int32_t                      (*getPressedOffset)(const THIS_TYPE* _this); \
    leResult                     (*setPressedOffset)(THIS_TYPE* _this, int32_t offs); \
    leButtonWidget_PressedEvent  (*getPressedEventCallback)(const THIS_TYPE* _this); \
    leResult                     (*setPressedEventCallback)(THIS_TYPE* _this, leButtonWidget_PressedEvent cb); \
    leButtonWidget_ReleasedEvent (*getReleasedEventCallback)(const THIS_TYPE* _this); \
    leResult                     (*setReleasedEventCallback)(THIS_TYPE* _this, leButtonWidget_ReleasedEvent cb); \
    
    
typedef struct leButtonWidgetVTable
{
	LE_BUTTONWIDGET_VTABLE(leButtonWidget)
} leButtonWidgetVTable; 

// DOM-IGNORE-END

// *****************************************************************************
/* Structure:
    leButtonWidget

  Summary:
    Implementation of a button widget.  A button is an interactive element
    that simulates a typical button with a pressed an released state.

  Description:


  Remarks:
    None.
*/
typedef struct leButtonWidget
{
    leWidget widget;  // base widget header
    
    leButtonWidgetVTable* fn;

    leButtonState state; // button state
    uint8_t toggleable; // indicates if the button is toggleable

    const leString* string; // the string that holds the button text

    const leImage* pressedImage; // button pressed icon image
    const leImage* releasedImage; // button released icon image

    leRelativePosition imagePosition; // icon position in relation to text
    uint32_t imageMargin; // distance between text and icon
    int32_t pressedOffset; // pressed text offset distance

    leButtonWidget_PressedEvent pressedEvent; // pressed event callback
    leButtonWidget_ReleasedEvent releasedEvent; // released event callback
} leButtonWidget;

// *****************************************************************************
// *****************************************************************************
// Section: Routines
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    leButtonWidget* leButtonWidget_New()

  Summary:
    Allocates memory for and initializes a new widget of this type.  The
    application is responsible for the managment of this memory until the
    widget is added to a widget tree.

  Description:
    Creates a new button widget instance.  Invokes the button constructor

  Returns:
    leButtonWidget* - pointer to a new button widget instance

  Remarks:
    Caller is responsible for managing the memory allocated by this function
    until the widget is added to a valid widget tree.
*/
LIB_EXPORT leButtonWidget* leButtonWidget_New();

LIB_EXPORT void leButtonWidget_Constructor(leButtonWidget* wgt);

#if 0
// *****************************************************************************
/* Function:
    leBool leButtonWidget_GetToggleable(leButtonWidget* btn)

  Summary:
    Gets the value of this button's toggle flag

  Description:

  Parameters:
    leButtonWidget* btn - the button to reference

  Returns:
    leBool - the value of the toggle flag

*/
LIB_EXPORT leBool leButtonWidget_GetToggleable(leButtonWidget* btn);

// *****************************************************************************
/* Function:
    leResult leButtonWidget_SetToggleable(leButtonWidget* btn,
                                      leBool toggleable)

  Summary:
    Enables the toggle mode for a button.  When pressed, toggle buttons will
    stay down until pressed again.

  Description:

  Parameters:
    leButtonWidget* btn - the button to modify
    leBool toggleable - the desired togglestate

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leButtonWidget_SetToggleable(leButtonWidget* btn,
                                                 leBool toggleable);

// *****************************************************************************
/* Function:
    leBool leButtonWidget_GetPressed(leButtonWidget* btn)

  Summary:
    Gets the pressed state of a button

  Description:

  Parameters:
    leButtonWidget* btn - the button to reference

  Returns:
    leBool - the button pressed state

  Remarks:

*/
LIB_EXPORT leBool leButtonWidget_GetPressed(leButtonWidget* btn);

// *****************************************************************************
/* Function:
    leResult leButtonWidget_SetPressed(leButtonWidget* btn, leBool pressed)

  Summary:
    Sets the pressed state for a button.

  Description:

  Parameters:
    leButtonWidget* btn - the button to modify
    leBool pressed - the pressed state

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leButtonWidget_SetPressed(leButtonWidget* btn,
                                              leBool pressed);

// *****************************************************************************
/* Function:
    leString* leButtonWidget_GetText(leButtonWidget* btn)

  Summary:
    Gets the current string pointer for a button.

  Description:

  Parameters:
    leButtonWidget* btn - the button to reference

  Returns:
    leString* str - the current pointer to the text string

  Remarks:

*/
LIB_EXPORT leString* leButtonWidget_GetText(leButtonWidget* btn);

// *****************************************************************************
/* Function:
    leResult leButtonWidget_SetText(leButtonWidget* btn, leString* str)

  Summary:
    Sets the text for a button.  

  Description:

  Parameters:
    leButtonWidget* btn - the button to modify
    leString str - the pointer to the string to set to the button

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leButtonWidget_SetText(leButtonWidget* btn, leString* str);

// *****************************************************************************
/* Function:
    int32_t leButtonWidget_GetTextLineSpace(leButtonWidget* btn)

  Summary:
    Returns the line spacing in pixels for the button text. If < 0, the
    ascent value of the string's font is used.

  Description:

  Parameters:
    leButtonWidget* btn - the button to reference

  Returns:
    int32_t - the line spacing in pixels

  Remarks:

*/
LIB_EXPORT int32_t leButtonWidget_GetTextLineSpace(leButtonWidget* btn);

// *****************************************************************************
/* Function:
    leResult leButtonWidget_SetTextLineSpace(leButtonWidget* btn, int32_t pixels)

  Summary:
    Sets the line space in pixels of the text in the button widget. A value < 0
    sets the spacing to the ascent value of the string's font.

  Description:

  Parameters:
    leButtonWidget* btn - the button to modify
    int32_t pixels - the line space, in pixels

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leButtonWidget_SetTextLineSpace(leButtonWidget* btn, int32_t pixels);

// *****************************************************************************
/* Function:
    leHAlignment leButtonWidget_GetHAlignment(leButtonWidget* btn)

  Summary:
    Gets the horizontal alignment setting for a button

  Description:

  Parameters:
    leButtonWidget* btn - the button to reference

  Returns:
    leHAlignment - the horizontal alignment value

  Remarks:

*/
LIB_EXPORT leHAlignment leButtonWidget_GetHAlignment(leButtonWidget* btn);

// *****************************************************************************
/* Function:
    leResult leButtonWidget_SetHAlignment(leButtonWidget* btn,
                                             leHAlignment align)

  Summary:
    Sets the horizontal alignment value for a button

  Description:

  Parameters:
    leButtonWidget* btn - the button to modify
    leHAlignment align - the desired alignment value

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leButtonWidget_SetHAlignment(leButtonWidget* btn,
                                                 leHAlignment align);

// *****************************************************************************
/* Function:
    leVAlignment leButtonWidget_GetVAlignment(leButtonWidget* btn)

  Summary:
    Gets the vertical alignment setting for a button

  Description:

  Parameters:
    leButtonWidget* btn - the button to reference

  Returns:
    leVAlignment - the vertical alignment setting for the button

  Remarks:

*/
LIB_EXPORT leVAlignment leButtonWidget_GetVAlignment(leButtonWidget* btn);

// *****************************************************************************
/* Function:
    leResult leButtonWidget_SetVAlignment(leButtonWidget* btn,
                                      leVAlignment align)

  Summary:
    Sets the vertical alignment for a button

  Description:

  Parameters:
    leButtonWidget* btn - the btn to modify
    leVAlignment align - the desired vertical alignment setting

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leButtonWidget_SetVAlignment(leButtonWidget* btn,
                                                 leVAlignment align);

// *****************************************************************************
/* Function:
    leImage* leButtonWidget_GetPressedImage(leButtonWidget* btn)

  Summary:
    Gets the pressed image asset pointer for a button

  Description:

  Parameters:
    leButtonWidget* btn - the button to reference

  Returns:
    leImage* - the pressed asset pointer

  Remarks:

*/
LIB_EXPORT leImage* leButtonWidget_GetPressedImage(leButtonWidget* btn);

// *****************************************************************************
/* Function:
    leResult leButtonWidget_SetPressedImage(leButtonWidget* btn,
                                        leImage* img)

  Summary:
    Sets the image to be used as a pressed icon

  Description:

  Parameters:
    leButtonWidget* btn - the widget
    leImage* img - pointer to an image asset

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leButtonWidget_SetPressedImage(leButtonWidget* btn,
                                                   leImage* img);

// *****************************************************************************
/* Function:
    leImage* leButtonWidget_GetReleasedImage(leButtonWidget* btn)

  Summary:
    Gets the currently used released icon

  Description:

  Parameters:
    leButtonWidget* btn - the button to reference

  Returns:
    leImage* - the released asset pointer

  Remarks:

*/
LIB_EXPORT leImage* leButtonWidget_GetReleasedImage(leButtonWidget* btn);

// *****************************************************************************
/* Function:
    leResult leButtonWidget_SetReleasedImage(leButtonWidget* btn,
                                             leImage* img)

  Summary:
    Sets the image to be used as the released icon

  Description:

  Parameters:
    leButtonWidget* btn - the widget
    leImage* img - the image asset to be used

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leButtonWidget_SetReleasedImage(leButtonWidget* btn,
                                                    leImage* img);

// *****************************************************************************
/* Function:
    leRelativePosition leButtonWidget_GetImagePosition(leButtonWidget* btn)

  Summary:
    Gets the position of the button icon

  Description:

  Parameters:
    leButtonWidget* btn - the button to reference

  Returns:
    leRelativePosition

  Remarks:

*/
LIB_EXPORT leRelativePosition leButtonWidget_GetImagePosition(leButtonWidget* btn);

// *****************************************************************************
/* Function:
    leResult leButtonWidget_SetImagePosition(leButtonWidget* btn,
                                             leRelativePosition pos)

  Summary:
    Sets the position of the button icon

  Description:

  Parameters:
    leButtonWidget* btn - the widget
    leRelativePosition pos - the desired image position

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leButtonWidget_SetImagePosition(leButtonWidget* btn,
                                                    leRelativePosition pos);

// *****************************************************************************
/* Function:
    uint32_t leButtonWidget_GetImageMargin(leButtonWidget* btn)

  Summary:
    Gets the distance between the icon and the text

  Description:

  Parameters:
    leButtonWidget* btn - the widget

  Returns:
    uint32_t - the distance value

  Remarks:

*/
LIB_EXPORT uint32_t leButtonWidget_GetImageMargin(leButtonWidget* btn);

// *****************************************************************************
/* Function:
    leResult leButtonWidget_SetImageMargin(leButtonWidget* btn,
                                           uint32_t mg)

  Summary:
    Sets the distance between the icon and text

  Description:

  Parameters:
    leButtonWidget* btn - the widget
    uint32_t - the distance value

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leButtonWidget_SetImageMargin(leButtonWidget* btn,
                                                  uint32_t mg);

// *****************************************************************************
/* Function:
    int32_t leButtonWidget_GetPressedOffset(leButtonWidget* btn)

  Summary:
    Gets the offset of the button internals when pressed

  Description:


  Parameters:
    leButtonWidget* btn - the widget

  Returns:
    int32_t - the distance value

  Remarks:

*/
LIB_EXPORT int32_t leButtonWidget_GetPressedOffset(leButtonWidget* btn);

// *****************************************************************************
/* Function:
    leResult leButtonWidget_SetPressedOffset(leButtonWidget* btn, int32_t offs)

  Summary:
    Sets the offset of the button internals when pressed

  Description:
    This value will be applied to all of the contents of the button
    when it is pressed.  This helps to visualize the button being
    pressed.

  Parameters:
    leButtonWidget* btn - the widget
    int32_t - the distance value

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leButtonWidget_SetPressedOffset(leButtonWidget* btn,
                                                    int32_t offs);

// *****************************************************************************
/* Function:
    leButtonWidget_PressedEvent leButtonWidget_GetPressedEventCallback(leButtonWidget* btn)

  Summary:
    Gets the callback associated with the button pressed event

  Description:

  Parameters:
    leButtonWidget* btn - the widget

  Returns:
    leButtonWidget_PressedEvent

  Remarks:

*/
LIB_EXPORT leButtonWidget_PressedEvent leButtonWidget_GetPressedEventCallback(leButtonWidget* btn);

// *****************************************************************************
/* Function:
    leResult leButtonWidget_SetPressedEventCallback(leButtonWidget* btn,
                                                    leButtonWidget_PressedEvent cb)

  Summary:
    Sets the pressed event callback for the button

  Description:

  Parameters:
    leButtonWidget* btn - the widget
    leButtonWidget_PressedEvent cb - a valid callback pointer or NULL

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leButtonWidget_SetPressedEventCallback(leButtonWidget* btn,
                                                           leButtonWidget_PressedEvent cb);
// *****************************************************************************
/* Function:
    leButtonWidget_ReleasedEvent leButtonWidget_GetReleasedEventCallback(leButtonWidget* btn)

  Summary:
    Gets the callback for the button released event

  Description:

  Parameters:
    leButtonWidget* btn - the widget

  Returns:
    leButtonWidget_ReleasedEvent

  Remarks:

*/
LIB_EXPORT leButtonWidget_ReleasedEvent leButtonWidget_GetReleasedEventCallback(leButtonWidget* btn);

// *****************************************************************************
/* Function:
    leResult leButtonWidget_SetReleasedEventCallback(leButtonWidget* btn,
                                                     leButtonWidget_ReleasedEvent cb)

  Summary:
    Sets the callback for the button released event

  Description:

  Parameters:
    leButtonWidget* btn - the widget
    leButtonWidget_ReleasedEvent cb - a valid callback pointer or NULL

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leButtonWidget_SetReleasedEventCallback(leButtonWidget* btn,
                                                            leButtonWidget_ReleasedEvent cb);
#endif

#endif /* LE_BUTTON_WIDGET_ENABLED */
#endif /* LEGATO_BUTTON_H */

