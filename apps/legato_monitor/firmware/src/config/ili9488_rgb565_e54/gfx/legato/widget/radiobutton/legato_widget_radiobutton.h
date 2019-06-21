/*******************************************************************************
 Module for Microchip Graphics Library - Legato User Interface Library

  Company:
    Microchip Technology Inc.

  File Name:
    legato_widget_radiobutton.h

  Summary:
    

  Description:
    This module implements radio button widget functions.
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
#ifndef LEGATO_RADIOBUTTON_H
#define LEGATO_RADIOBUTTON_H
//DOM-IGNORE-END

#include "gfx/legato/common/legato_common.h"

#if LE_RADIOBUTTON_WIDGET_ENABLED == 1

#include "gfx/legato/image/legato_image.h"
#include "gfx/legato/widget/legato_widget.h"
#include "gfx/legato/widget/radiobutton/legato_radiobutton_group.h"
#include "gfx/legato/string/legato_string.h"

typedef struct leRadioButtonWidget leRadioButtonWidget;
typedef struct leRadioButtonGroup leRadioButtonGroup;

// *****************************************************************************
/* Function Pointer:
    leRadioButtonWidget_SelectedEvent

  Summary:
    Radio button selected function callback type
*/
typedef void (*leRadioButtonWidget_SelectedEvent)(leRadioButtonWidget*);

// *****************************************************************************
/* Function Pointer:
    leRadioButtonWidget_DeselectedEvent

  Summary:
    Radio button deselected function callback type
*/
typedef void (*leRadioButtonWidget_DeselectedEvent)(leRadioButtonWidget*);

// *****************************************************************************
// *****************************************************************************
// Section: Data Types and Constants
// *****************************************************************************
// *****************************************************************************

// DOM-IGNORE-BEGIN
typedef struct leRadioButtonWidget leRadioButtonWidget;

#define LE_RADIOBUTTONWIDGET_VTABLE(THIS_TYPE) \
    LE_WIDGET_VTABLE(THIS_TYPE) \
    \
    leRadioButtonGroup* (*getGroup)(const THIS_TYPE* _this); \
    leBool              (*getSelected)(const THIS_TYPE* _this); \
    leResult            (*setSelected)(THIS_TYPE* _this); \
    void                (*select)(THIS_TYPE* _this); \
    void                (*deselect)(THIS_TYPE* _this); \
    leString*           (*getText)(const THIS_TYPE* _this); \
    leResult            (*setText)(THIS_TYPE* _this, const leString* str); \
    leImage*            (*getSelectedImage)(const THIS_TYPE* _this); \
    leResult            (*setSelectedImage)(THIS_TYPE* _this, const leImage* img); \
    leImage*            (*getUnselectedImage)(const THIS_TYPE* _this); \
    leResult            (*setUnselectedImage)(THIS_TYPE* _this, const leImage* img); \
    leRelativePosition  (*getImagePosition)(const THIS_TYPE* _this); \
    leResult            (*setImagePosition)(THIS_TYPE* _this, leRelativePosition pos); \
    uint32_t            (*getImageMargin)(const THIS_TYPE* _this); \
    leResult            (*setImageMargin)(THIS_TYPE* _this, uint32_t mg); \
    leRadioButtonWidget_SelectedEvent (*getSelectedEventCallback)(const THIS_TYPE* _this); \
    leResult            (*setSelectedEventCallback)(THIS_TYPE* _this, leRadioButtonWidget_SelectedEvent cb); \
    leRadioButtonWidget_DeselectedEvent (*getDeselectedEventCallback)(const THIS_TYPE* _this); \
    leResult            (*setDeselectedEventCallback)(THIS_TYPE* _this, leRadioButtonWidget_DeselectedEvent cb); \
    uint32_t            (*getCircleButtonSize)(const THIS_TYPE* _this); \
    leResult            (*setCircleButtonSize)(THIS_TYPE* _this, uint32_t sz); \
    
typedef struct leRadioButtonWidgetVTable
{
	LE_RADIOBUTTONWIDGET_VTABLE(leRadioButtonWidget)
} leRadioButtonWidgetVTable; 

// DOM-IGNORE-END

// *****************************************************************************
/* Enumeration:
    leRadioButtonWidget

  Summary:
    Implementation of a radio button widget struct

  Description:
    A radio button is similar to a checkbox widget in that it has an on and
    off state.  It is further capable of being added to a radio button group.
    This group provides a mutually exclusive selection capability so that
    only one radio button may be selected at any one time.

  Remarks:
    None.
*/
typedef struct leRadioButtonWidget
{
    leWidget widget; // widget base class
    
    leRadioButtonWidgetVTable* fn;

    leBool selected; // indicates if the radio button is selected

    const leString* text; // radio button text

    const leImage* selectedImage; // button custom selected image
    const leImage* unselectedImage; // buton custom unselected image
    
    leRelativePosition imagePosition; // image icon relative position
    
    uint32_t imageMargin; // image margin
    uint32_t circleButtonSize; // size of radio circle button in pixels

    leRadioButtonWidget_SelectedEvent selectedEvent; // button selected event callback
    leRadioButtonWidget_DeselectedEvent deselectedEvent; // button deselected event callback

    leRadioButtonGroup* group; // radio button group
} leRadioButtonWidget;


// *****************************************************************************
// *****************************************************************************
// Section: Routines
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    leRadioButtonWidget* leRadioButtonWidget_New()

  Summary:
    Allocates memory for a new widget of this type.  The application is
    responsible for the managment of this memory until the widget is added to
    a widget tree.

  Description:
    

  Parameters:
    
  Returns:
    leRadioButtonWidget*
    
  Remarks:
    
*/
LIB_EXPORT leRadioButtonWidget* leRadioButtonWidget_New();

LIB_EXPORT void leRadioButtonWidget_Constructor(leRadioButtonWidget* btn);

#if 0
// *****************************************************************************
/* Function:
    leRadioButtonGroup* leRadioButtonWidget_GetGroup(leRadioButtonWidget* btn)

  Summary:
    Returns the pointer to the currently set radio button group.

  Description:
    

  Parameters:
    leRadioButtonWidget* btn - the widget
    
  Returns:
    leRadioButtonGroup* - the currently assigned radio button group
    
  Remarks:
    
*/
LIB_EXPORT leRadioButtonGroup* leRadioButtonWidget_GetGroup(leRadioButtonWidget* btn);

// *****************************************************************************
/* Function:
    leBool leRadioButtonWidget_GetSelected(leRadioButtonWidget* btn)

  Summary:
    Returns true if this radio button is currently selected

  Description:
    

  Parameters:
    leRadioButtonWidget* btn - the widget
    
  Returns:
    leBool - true if this button is currently selected
    
  Remarks:
    
*/
LIB_EXPORT leBool leRadioButtonWidget_GetSelected(leRadioButtonWidget* btn);

// *****************************************************************************
/* Function:
    leResult leRadioButtonWidget_SetSelected(leRadioButtonWidget* btn)

  Summary:
    Sets this button as selected.

  Description:
    If this button belongs to a radio button group then this function will
    potentially unselect another button and become selected.

  Parameters:
    leRadioButtonWidget* btn - the widget
    
  Returns:
    leResult - the operation result
    
  Remarks:
    
*/
LIB_EXPORT leResult leRadioButtonWidget_SetSelected(leRadioButtonWidget* btn);

// *****************************************************************************
/* Function:
    leResult leRadioButtonWidget_GetText(leRadioButtonWidget* btn, 
                                         leString* str)

  Summary:
    Gets the text value for the button.

  Description:
    This function allocates memory and initializes the input string pointer.  The
    caller is responsible for managing the memory once this function returns.

  Parameters:
    leRadioButtonWidget* btn - the widget
    leString* str - a pointer to an leString object
    
  Returns:
    leResult - the operation result
    
  Remarks:
    
*/
LIB_EXPORT leResult leRadioButtonWidget_GetText(leRadioButtonWidget* btn, 
                                                leString* str);

// *****************************************************************************
/* Function:
    leResult leRadioButtonWidget_SetText(leRadioButtonWidget* btn,
                                         leString str)

  Summary:
    Sets the text value for the button.

  Description:
    This function copies the contents of the input string into its internal
    string buffer.  The input string can then be freed or altered without 
    affecting the label's internal string value.

  Parameters:
    leRadioButtonWidget* btn - the widget
    leString str - an leString object
    
  Returns:
    leResult - the operation result
    
  Remarks:
    
*/                                             
LIB_EXPORT leResult leRadioButtonWidget_SetText(leRadioButtonWidget* btn,
                                                leString str);

// *****************************************************************************
/* Function:
    leHAlignment leRadioButtonWidget_GetHAlignment(leRadioButtonWidget* btn)

  Summary:
    Gets the horizontal alignment setting for a button

  Description:
    

  Parameters:
    leRadioButtonWidget* btn - the widget
        
  Returns:
    leHAlignment - the horizontal alignment value
    
  Remarks:
    
*/    
LIB_EXPORT leHAlignment leRadioButtonWidget_GetHAlignment(leRadioButtonWidget* btn);

// *****************************************************************************
/* Function:
    leResult leRadioButtonWidget_SetHAlignment(leRadioButtonWidget* btn,
                                               leHAlignment align)

  Summary:
    Sets the horizontal alignment value for a button

  Description:
    

  Parameters:
    leRadioButtonWidget* btn - the widget
    leHAlignment align - the desired alignment value
    
  Returns:
    leResult - the operation result
    
  Remarks:
    
*/    
LIB_EXPORT leResult leRadioButtonWidget_SetHAlignment(leRadioButtonWidget* btn,
                                                      leHAlignment align);

// *****************************************************************************
/* Function:
    leVAlignment leRadioButtonWidget_GetVAlignment(leRadioButtonWidget* btn)

  Summary:
    Sets the vertical alignment for a button

  Description:
    

  Parameters:
    leRadioButtonWidget* btn - the widget
        
  Returns:
    leVAlignment align - the desired vertical alignment setting
    
  Remarks:
    
*/    
LIB_EXPORT leVAlignment leRadioButtonWidget_GetVAlignment(leRadioButtonWidget* btn);

// *****************************************************************************
/* Function:
    leResult leRadioButtonWidget_SetVAlignment(leRadioButtonWidget* btn,
                                               leVAlignment align)

  Summary:
    Sets the vertical alignment for a button

  Description:
    

  Parameters:
    leRadioButtonWidget* btn - the widget
    leVAlignment align - the desired vertical alignment setting
    
  Returns:
    leResult - the operation result
        
  Remarks:
    
*/    
LIB_EXPORT leResult leRadioButtonWidget_SetVAlignment(leRadioButtonWidget* btn,
                                                      leVAlignment align);                                                    
// *****************************************************************************
/* Function:
    GFXU_ImageAsset* leRadioButtonWidget_GetSelectedImage(leRadioButtonWidget* btn)

  Summary:
    Gets the selected image asset pointer for a button

  Description:
    

  Parameters:
    leRadioButtonWidget* btn - the widget
        
  Returns:
    GFXU_ImageAsset* - the selected asset pointer
    
  Remarks:
    
*/    
LIB_EXPORT GFXU_ImageAsset* leRadioButtonWidget_GetSelectedImage(leRadioButtonWidget* btn);

// *****************************************************************************
/* Function:
    leResult leRadioButtonWidget_SetSelectedImage(leRadioButtonWidget* btn,
                                                  GFXU_ImageAsset* img)

  Summary:
    Sets the image to be used as a selected icon

  Description:
    

  Parameters:
    leRadioButtonWidget* btn - the widget
    GFXU_ImageAsset* img - the desired image asset pointer or NULL
    
  Returns:
    leResult - the operation result
    
  Remarks:
    
*/    
LIB_EXPORT leResult leRadioButtonWidget_SetSelectedImage(leRadioButtonWidget* btn,
                                                         GFXU_ImageAsset* img);

// *****************************************************************************
/* Function:
    GFXU_ImageAsset* leRadioButtonWidget_GetUnselectedImage(leRadioButtonWidget* btn)

  Summary:
    Gets the image asset pointer currently used as the unselected icon

  Description:
    

  Parameters:
    leRadioButtonWidget* btn - the widget
        
  Returns:
    GFXU_ImageAsset* - the selected asset pointer
    
  Remarks:
    
*/    
LIB_EXPORT GFXU_ImageAsset* leRadioButtonWidget_GetUnselectedImage(leRadioButtonWidget* btn);

// *****************************************************************************
/* Function:
    leResult leRadioButtonWidget_SetUnselectedImage(leRadioButtonWidget* btn,
                                                    GFXU_ImageAsset* img)

  Summary:
    Sets the asset pointer for the radio button's unselected image icon

  Description:
    

  Parameters:
    leRadioButtonWidget* btn - the widget
    GFXU_ImageAsset* img - the desired image asset pointer or NULL
    
  Returns:
    leResult - the operation result
    
  Remarks:
    
*/    
LIB_EXPORT leResult leRadioButtonWidget_SetUnselectedImage(leRadioButtonWidget* btn,
                                                           GFXU_ImageAsset* img);

// *****************************************************************************
/* Function:
    leRelativePosition leRadioButtonWidget_GetImagePosition(leRadioButtonWidget* btn)

  Summary:
    Gets the current image position setting for the radio button

  Description:
    

  Parameters:
    leRadioButtonWidget* btn - the widget
        
  Returns:
    leRelativePosition - the current image relative position
    
  Remarks:
    
*/                                                           
LIB_EXPORT leRelativePosition leRadioButtonWidget_GetImagePosition(leRadioButtonWidget* btn);

// *****************************************************************************
/* Function:
    leResult leRadioButtonWidget_SetImagePosition(leRadioButtonWidget* btn,
                                                  leRelativePosition pos)

  Summary:
    Sets the image relative position setting for the radio button

  Description:
    

  Parameters:
    leRadioButtonWidget* btn - the widget
    leRelativePosition pos - the desired image position
    
  Returns:
    leResult - the operation result
    
  Remarks:
    
*/    
LIB_EXPORT leResult leRadioButtonWidget_SetImagePosition(leRadioButtonWidget* btn,
                                                         leRelativePosition pos);

// *****************************************************************************
/* Function:
    uint16_t leRadioButtonWidget_GetImageMargin(leRadioButtonWidget* btn)

  Summary:
    Gets the distance between the icon and the text

  Description:
    

  Parameters:
    leRadioButtonWidget* btn - the widget
        
  Returns:
    uint32_t - the distance value
    
  Remarks:
    
*/    
LIB_EXPORT uint32_t leRadioButtonWidget_GetImageMargin(leRadioButtonWidget* btn);

// *****************************************************************************
/* Function:
    leResult leRadioButtonWidget_SetImageMargin(leRadioButtonWidget* btn,
                                                uint32_t mg)

  Summary:
    Sets the distance between the icon and text

  Description:
    

  Parameters:
    leRadioButtonWidget* btn - the widget
    uint32_t mg - the distance value
    
  Returns:
    leResult - the operation result
    
  Remarks:
    
*/    
LIB_EXPORT leResult leRadioButtonWidget_SetImageMargin(leRadioButtonWidget* btn,
                                                       uint32_t mg);

// *****************************************************************************
/* Function:
    leRadioButtonWidget_SelectedEvent leRadioButtonWidget_GetSelectedEventCallback(leRadioButtonWidget* btn)

  Summary:
    Gets the current radio button selected event callback

  Description:
    

  Parameters:
    leRadioButtonWidget* btn - the widget
        
  Returns:
    leRadioButtonWidget_SelectedEvent - a valid callback pointer or NULL
    
  Remarks:
    
*/    
LIB_EXPORT leRadioButtonWidget_SelectedEvent leRadioButtonWidget_GetSelectedEventCallback(leRadioButtonWidget* btn);

// *****************************************************************************
/* Function:
    leResult leRadioButtonWidget_SetSelectedEventCallback(leRadioButtonWidget* btn,
                                                          leRadioButtonWidget_SelectedEvent cb)

  Summary:
    Sets the radio button selected event callback

  Description:
    This callback is called when the radio button becomes selected

  Parameters:
    leRadioButtonWidget* btn - the widget
    leRadioButtonWidget_SelectedEvent - a valid callback pointer or NULL
    
  Returns:
    leResult - the operation result
    
  Remarks:
    
*/    
LIB_EXPORT leResult leRadioButtonWidget_SetSelectedEventCallback(leRadioButtonWidget* btn,
                                                                leRadioButtonWidget_SelectedEvent cb);

// *****************************************************************************
/* Function:
    leRadioButtonWidget_DeselectedEvent leRadioButtonWidget_GetDeselectedEventCallback(leRadioButtonWidget* btn)

  Summary:
    Gets the current radio button deselected event callback

  Description:
    

  Parameters:
    leRadioButtonWidget* btn - the widget
        
  Returns:
    leRadioButtonWidget_DeselectedEvent - a valid callback pointer or NULL
    
  Remarks:
    
*/    
LIB_EXPORT leRadioButtonWidget_DeselectedEvent leRadioButtonWidget_GetDeselectedEventCallback(leRadioButtonWidget* btn);

// *****************************************************************************
/* Function:
    leResult leRadioButtonWidget_SetDeselectedEventCallback(leRadioButtonWidget* btn,
                                                            leRadioButtonWidget_DeselectedEvent cb)

  Summary:
    Sets the deselected callback pointer

  Description:
    This callback is called when this radio button is deselected

  Parameters:
    leRadioButtonWidget* btn - the widget
    leRadioButtonWidget_DeselectedEvent - a valid callback pointer or NULL
    
  Returns:
    leResult - the operation result
    
  Remarks:
    
*/    
LIB_EXPORT leResult leRadioButtonWidget_SetDeselectedEventCallback(leRadioButtonWidget* btn,
                                                                   leRadioButtonWidget_DeselectedEvent cb);

// *****************************************************************************
/* Function:
    LIB_EXPORT uint32_t leRadioButtonWidget_GetCircleButtonSize(leRadioButtonWidget* btn)

  Summary:
    Gets the diameter/size of the default circle button

  Description:
    
  Parameters:
    leRadioButtonWidget* btn - the widget
        
  Returns:
    uint32_t size - the size of the default circle button
    
  Remarks:
    
*/
LIB_EXPORT uint32_t leRadioButtonWidget_GetCircleButtonSize(leRadioButtonWidget* btn);

// *****************************************************************************
/* Function:
    leResult leRadioButtonWidget_SetCircleButtonSize(leRadioButtonWidget* btn,
                                                     uint32_t size)

  Summary:
    Sets the size of the default circle button

  Description:

  Parameters:
    leRadioButtonWidget* btn - the widget
    uint32_t size - the diameter of the circle, in pixels
    
  Returns:
    leResult - the operation result
    
  Remarks:
    
*/  
LIB_EXPORT leResult leRadioButtonWidget_SetCircleButtonSize(leRadioButtonWidget* btn,
                                                            uint32_t size);

// DOM-IGNORE-BEGIN
// internal use only
void _leRadioButtonWidget_Select(leRadioButtonWidget* btn);
void _leRadioButtonWidget_Deselect(leRadioButtonWidget* btn);

// internal use only
void _leRadioButtonWidget_GetImageRect(leRadioButtonWidget* btn,
									   leRect* imgRect,
									   leRect* imgSrcRect);

void _leRadioButtonWidget_GetTextRect(leRadioButtonWidget* btn,
								      leRect* textRect,
								      leRect* drawRect);
// DOM-IGNORE-END
#endif

#endif // LE_RADIOBUTTON_WIDGET_ENABLED
#endif /* LEGATO_RADIOBUTTON_H */
