/*******************************************************************************
 Module for Microchip Graphics Library - Legato User Interface Library

  Company:
    Microchip Technology Inc.

  File Name:
    legato_widget_button.h

  Summary:


  Description:
    This module implements button widget functions.
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
#ifndef LEGATO_CHECKBOX_H
#define LEGATO_CHECKBOX_H
//DOM-IGNORE-END

#include "gfx/legato/common/legato_common.h"

#if LE_CHECKBOX_WIDGET_ENABLED == 1

#include "gfx/legato/image/legato_image.h"
#include "gfx/legato/widget/legato_widget.h"
#include "gfx/legato/string/legato_string.h"

typedef struct leCheckBoxWidget leCheckBoxWidget;

// *****************************************************************************
/* Function Pointer:
    leCheckBoxWidget_CheckedEvent

  Summary:
    Checkbox checked event function callback type
*/
typedef void (*leCheckBoxWidget_CheckedEvent)(leCheckBoxWidget*);

// *****************************************************************************
/* Function Pointer:
    leCheckBoxWidget_UncheckedEvent

  Summary:
    Checkbox unchecked event function callback type
*/
typedef void (*leCheckBoxWidget_UncheckedEvent)(leCheckBoxWidget*);

// *****************************************************************************
// *****************************************************************************
// Section: Data Types and Constants
// *****************************************************************************
// *****************************************************************************

// DOM-IGNORE-BEGIN
typedef struct leCheckBoxWidget leCheckBoxWidget;

#define LE_CHECKBOXWIDGET_VTABLE(THIS_TYPE) \
    LE_WIDGET_VTABLE(THIS_TYPE) \
    \
    leBool           (*getChecked)(const THIS_TYPE* _this); \
    leResult         (*setChecked)(THIS_TYPE* _this, leBool toggleable); \
    leImage*         (*getCheckedImage)(const THIS_TYPE* _this); \
    leResult         (*setCheckedImage)(THIS_TYPE* _this, leImage* img); \
    leImage*         (*getUncheckedImage)(const THIS_TYPE* _this); \
    leResult         (*setUncheckedImage)(THIS_TYPE* _this, leImage* img); \
    leRelativePosition  (*getImagePosition)(const THIS_TYPE* _this); \
    leResult         (*setImagePosition)(THIS_TYPE* _this, leRelativePosition pos); \
    uint32_t         (*getImageMargin)(const THIS_TYPE* _this); \
    leResult         (*setImageMargin)(THIS_TYPE* _this, uint32_t mg); \
    leString*        (*getString)(const THIS_TYPE* _this); \
    leResult         (*setString)(THIS_TYPE* _this, const leString* str); \
    leCheckBoxWidget_CheckedEvent   (*getCheckedEventCallback)(const THIS_TYPE* _this); \
    leResult         (*setCheckedEventCallback)(THIS_TYPE* _this, leCheckBoxWidget_CheckedEvent cb); \
    leCheckBoxWidget_UncheckedEvent (*getUncheckedEventCallback)(const THIS_TYPE* _this); \
    leResult         (*setUncheckedEventCallback)(THIS_TYPE* _this, leCheckBoxWidget_UncheckedEvent cb); \
    
    
typedef struct leCheckBoxWidgetVTable
{
	LE_CHECKBOXWIDGET_VTABLE(leCheckBoxWidget)
} leCheckBoxWidgetVTable; 

// DOM-IGNORE-END

// *****************************************************************************
/* Structure:
    leCheckBoxWidget

  Summary:
    Implementation of a checkbox widget.

  Description:
    A check box widget contains an interactive two-state box indicating on or
    off.  The check box may also contain descriptive text.  Custom images for
    the check box may be used in place of the default box graphic.

  Remarks:
    None.
*/
typedef struct leCheckBoxWidget
{
    leWidget widget; // base class properties
    
    leCheckBoxWidgetVTable* fn;

    leBool checked; // the state of the box

    const leString* string; // the text of the box

    const leImage* checkedImage; // pointer to a custom image to use for the
                                 // checked image
    const leImage* uncheckedImage; // pointer to a custom image to use for the
                                   // unchecked image

    leRelativePosition imagePosition; // postition of the image relative to the text
                                      // of the box
    uint32_t imageMargin; // the distance between the image and the text

    leCheckBoxWidget_CheckedEvent checkedEvent; // callback for checked events
    leCheckBoxWidget_CheckedEvent uncheckedEvent; // callback for unchecked events
} leCheckBoxWidget;

// *****************************************************************************
// *****************************************************************************
// Section: Routines
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    leCheckBoxWidget* leCheckBoxWidget_New()

  Summary:
    Allocates memory for and initializes a new widget of this type.  The
    application is responsible for the managment of this memory until the
    widget is added to a widget tree.

  Description:


  Parameters:
    void

  Returns:
    leCheckBoxWidget*

  Remarks:

*/
LIB_EXPORT leCheckBoxWidget* leCheckBoxWidget_New();

LIB_EXPORT void leCheckBoxWidget_Constructor(leCheckBoxWidget* wgt);

#if 0
// *****************************************************************************
/* Function:
    leBool leCheckBoxWidget_GetChecked(leCheckBoxWidget* cbox)

  Summary:
    Gets the checked state of the check box

  Description:


  Parameters:
    leCheckBoxWidget* cbox - the widget

  Returns:
    leBool - the checked flag value

  Remarks:

*/
LIB_EXPORT leBool leCheckBoxWidget_GetChecked(leCheckBoxWidget* cbox);

// *****************************************************************************
/* Function:
    leResult leCheckBoxWidget_SetChecked(leCheckBoxWidget* cbox,
                                         leBool checked)

  Summary:
    Sets the checked state of the check box

  Description:


  Parameters:
    leCheckBoxWidget* cbox - the widget
    leBool checked - the desired checked value

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leCheckBoxWidget_SetChecked(leCheckBoxWidget* cbox,
                                                leBool checked);

// *****************************************************************************
/* Function:
    leHAlignment leCheckBoxWidget_GetHAlignment(leCheckBoxWidget* cbox)

  Summary:
    Gets the horizontal alignment of the check box

  Description:


  Parameters:
    leCheckBoxWidget* cbox - the widget

  Returns:
    leHAlignment - the current halign value

  Remarks:

*/
LIB_EXPORT leHAlignment leCheckBoxWidget_GetHAlignment(leCheckBoxWidget* cbox);

// *****************************************************************************
/* Function:
    leResult leCheckBoxWidget_SetHAlignment(leCheckBoxWidget* cbox,
                                            leHAlignment align)

  Summary:
    Sets the horizontal alignment of the check box.

  Description:


  Parameters:
    leCheckBoxWidget* cbox - the widget
    leHAlignment align - the desired halign value

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leCheckBoxWidget_SetHAlignment(leCheckBoxWidget* cbox,
                                                   leHAlignment align);

// *****************************************************************************
/* Function:
    leVAlignment leCheckBoxWidget_GetVAlignment(leCheckBoxWidget* cbox)

  Summary:
    Gets the vertical alignment of the check box

  Description:


  Parameters:
    leCheckBoxWidget* cbox - the widget

  Returns:
    leVAlignment

  Remarks:

*/
LIB_EXPORT leVAlignment leCheckBoxWidget_GetVAlignment(leCheckBoxWidget* cbox);

// *****************************************************************************
/* Function:
    leResult leCheckBoxWidget_SetVAlignment(leCheckBoxWidget* cbox,
                                            leVAlignment align)

  Summary:
    Sets the vertical alignment of the check box

  Description:


  Parameters:
    leCheckBoxWidget* cbox - the widget
    leVAlignment align - the valign value

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leCheckBoxWidget_SetVAlignment(leCheckBoxWidget* cbox,
                                                   leVAlignment align);

// *****************************************************************************
/* Function:
    leImage* leCheckBoxWidget_GetCheckedImage(leCheckBoxWidget* btn)

  Summary:
    Gets the checked image of the check box

  Description:


  Parameters:
    leCheckBoxWidget* cbox - the widget

  Returns:
    leImage* - the current checked image asset pointer

  Remarks:

*/
LIB_EXPORT leImage* leCheckBoxWidget_GetCheckedImage(leCheckBoxWidget* btn);

// *****************************************************************************
/* Function:
    leResult leCheckBoxWidget_SetCheckedImage(leCheckBoxWidget* btn,
                                              leImage* img)

  Summary:
    Sets the checked image of the check box

  Description:


  Parameters:
    leCheckBoxWidget* cbox - the widget
    leImage* img - the desired checked image asset pointer

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leCheckBoxWidget_SetCheckedImage(leCheckBoxWidget* btn,
                                                     leImage* img);

// *****************************************************************************
/* Function:
    leImage* leCheckBoxWidget_GetUncheckedImage(leCheckBoxWidget* btn)

  Summary:
    Gets the unchecked image of the check box

  Description:


  Parameters:
    leCheckBoxWidget* cbox - the widget

  Returns:
    leImage* - the current unchecked image asset pointer

  Remarks:

*/
LIB_EXPORT leImage* leCheckBoxWidget_GetUncheckedImage(leCheckBoxWidget* btn);

// *****************************************************************************
/* Function:
    leResult leCheckBoxWidget_SetUncheckedImage(leCheckBoxWidget* btn,
                                                leImage* img)

  Summary:
    Sets the unchecked image of the check box

  Description:


  Parameters:
    leCheckBoxWidget* cbox - the widget
    leImage* img - the desired unchecked image asset pointer

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leCheckBoxWidget_SetUncheckedImage(leCheckBoxWidget* btn,
                                                       leImage* img);

// *****************************************************************************
/* Function:
    leRelativePosition leCheckBoxWidget_GetImagePosition(leCheckBoxWidget* btn)

  Summary:
    Gets the image position of the check box

  Description:


  Parameters:
    leCheckBoxWidget* cbox - the widget

  Returns:
    leRelativePosition - the current image position value

  Remarks:

*/
LIB_EXPORT leRelativePosition leCheckBoxWidget_GetImagePosition(leCheckBoxWidget* btn);

// *****************************************************************************
/* Function:
    leResult leCheckBoxWidget_SetImagePosition(leCheckBoxWidget* btn,
                                               leRelativePosition pos)

  Summary:
    Sets the image position of the check box

  Description:


  Parameters:
    leCheckBoxWidget* cbox - the widget
    leRelativePosition pos - the desired image position value

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leCheckBoxWidget_SetImagePosition(leCheckBoxWidget* btn,
                                                      leRelativePosition pos);

// *****************************************************************************
/* Function:
    uint32_t leCheckBoxWidget_GetImageMargin(leCheckBoxWidget* btn)

  Summary:
    Gets the distance between the image and the text

  Description:


  Parameters:
    leCheckBoxWidget* cbox - the widget

  Returns:
    uint32_t - the current image margin value

  Remarks:

*/
LIB_EXPORT uint32_t leCheckBoxWidget_GetImageMargin(leCheckBoxWidget* btn);

// *****************************************************************************
/* Function:
    leResult leCheckBoxWidget_SetImageMargin(leCheckBoxWidget* btn, uint32_t mg)

  Summary:
    Sets the distance between the image and the text

  Description:


  Parameters:
    leCheckBoxWidget* cbox - the widget
    uint32_t mg - the desired image margin value

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leCheckBoxWidget_SetImageMargin(leCheckBoxWidget* btn,
                                                    uint32_t mg);

// *****************************************************************************
/* Function:
    leResult leCheckBoxWidget_GetText(leCheckBoxWidget* cbox, leString* str)

  Summary:
    Gets a copy of the checkbox text.  If the text has local data the data will
    be duplicated.  The caller is responsible for managing the memory
    as appropriate.

  Description:


  Parameters:
    leCheckBoxWidget* cbox - the widget
    str - pointer to an leString object

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leCheckBoxWidget_GetText(leCheckBoxWidget* cbox, leString* str);

// *****************************************************************************
/* Function:
    leResult leCheckBoxWidget_SetText(leCheckBoxWidget* cbox, leString str)

  Summary:
    Sets the checkbox text to the input string.  If the string has local data
    the data will be duplicated and copied to the checkboxes internal string.

  Description:


  Parameters:
    leCheckBoxWidget* cbox - the widget

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leCheckBoxWidget_SetText(leCheckBoxWidget* cbox,
                                             leString str);

// *****************************************************************************
/* Function:
    leCheckBoxWidget_CheckedEvent leCheckBoxWidget_GetCheckedEventCallback(leCheckBoxWidget* cbox)

  Summary:
    Gets the checked event callback

  Description:


  Parameters:
    leCheckBoxWidget* cbox - the widget

  Returns:
    leCheckBoxWidget_CheckedEvent - a valid callback pointer or NULL

  Remarks:

*/
LIB_EXPORT leCheckBoxWidget_CheckedEvent leCheckBoxWidget_GetCheckedEventCallback(leCheckBoxWidget* cbox);

// *****************************************************************************
/* Function:
    leResult leCheckBoxWidget_SetCheckedEventCallback(leCheckBoxWidget* cbox,
                                                      leCheckBoxWidget_CheckedEvent cb)

  Summary:
    Sets the checked event callback

  Description:


  Parameters:
    leCheckBoxWidget* cbox - the widget
    leCheckBoxWidget_CheckedEvent cb - a valid callback pointer or NULL

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leCheckBoxWidget_SetCheckedEventCallback(leCheckBoxWidget* cbox,
                                                             leCheckBoxWidget_CheckedEvent cb);

// *****************************************************************************
/* Function:
    leCheckBoxWidget_UncheckedEvent leCheckBoxWidget_GetUncheckedEventCallback(leCheckBoxWidget* cbox)

  Summary:
    Gets the unchecked event callback

  Description:


  Parameters:
    leCheckBoxWidget* cbox - the widget

  Returns:
    leCheckBoxWidget_UncheckedEvent - a valid callback pointer or NULL

  Remarks:

*/
LIB_EXPORT leCheckBoxWidget_UncheckedEvent leCheckBoxWidget_GetUncheckedEventCallback(leCheckBoxWidget* cbox);

// *****************************************************************************
/* Function:
    leResult leCheckBoxWidget_SetUncheckedEventCallback(leCheckBoxWidget* cbox,
                                                        leCheckBoxWidget_UncheckedEvent cb)

  Summary:
    Sets the unchecked event callback

  Description:


  Parameters:
    leCheckBoxWidget* cbox - the widget
    leCheckBoxWidget_UncheckedEvent cb - a valid callback pointer or NULL

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leCheckBoxWidget_SetUncheckedEventCallback(leCheckBoxWidget* cbox,
                                                               leCheckBoxWidget_UncheckedEvent cb);

#endif
#endif // LE_CHECKBOX_WIDGET_ENABLED
#endif /* LEGATO_BUTTON_H */
