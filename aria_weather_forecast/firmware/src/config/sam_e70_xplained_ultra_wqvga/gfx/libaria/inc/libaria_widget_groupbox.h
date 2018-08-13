/*******************************************************************************
 Module for Microchip Graphics Library - Aria User Interface Library

  Company:
    Microchip Technology Inc.

  File Name:
    libaria_widget_groupbox.h

  Summary:
    

  Description:
    This module implements group box widget functions.
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

#ifndef LIBARIA_GROUPBOX_H
#define LIBARIA_GROUPBOX_H
//DOM-IGNORE-END

#include "gfx/libaria/inc/libaria_common.h"

#if LA_GROUPBOX_WIDGET_ENABLED

#include "gfx/libaria/inc/libaria_widget.h"
#include "gfx/libaria/inc/libaria_string.h"

// *****************************************************************************
// *****************************************************************************
// Section: Data Types and Constants
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Enumeration:
    laGroupBoxWidget_t

  Summary:
    Group box struct definition.

  Description:
    A group box is a widget that is similar to a basic panel but provides
    a line border and title text.  Used for grouping and describing widgets
    of similar function.

  Remarks:
    None.
*/        
typedef struct laGroupBoxWidget_t
{
    laWidget widget; // widget base class

    laString text; // group box title text

    laHAlignment halign; // group box text alignment

    GFXU_ExternalAssetReader* reader; // asset reader
} laGroupBoxWidget;

void _laGroupBoxWidget_Constructor(laGroupBoxWidget* box);
void _laGroupBoxWidget_Destructor(laGroupBoxWidget* box);

void _laGroupBoxWidget_Paint(laGroupBoxWidget* box);

// *****************************************************************************
// *****************************************************************************
// Section: Routines
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    laGroupBoxWidget* laGroupBoxWidget_New()

  Summary:
    Allocates memory for and initializes a new widget of this type.  The
    application is responsible for the managment of this memory until the
    widget is added to a widget tree.

  Description:
    Allocates memory for and initializes a new widget of this type.  The
    application is responsible for the managment of this memory until the
    widget is added to a widget tree.

  Parameters:
    void
    
  Returns:
    laGroupBoxWidget*
    
  Remarks:
    
*/
LIB_EXPORT laGroupBoxWidget* laGroupBoxWidget_New();

// *****************************************************************************
/* Function:
    laResult laGroupBoxWidget_GetText(laGroupBoxWidget* lbl, laString* str)

  Summary:
    Gets the text value for the group box.

  Description:
    This function allocates memory and initializes the input string pointer.  The
    caller is responsible for managing the memory once this function returns.

  Parameters:
    laGroupBoxWidget* box - the widget
    laString* str - a pointer to an laString object
    
  Returns:
    laResult
    
  Remarks:
    
*/
LIB_EXPORT laResult laGroupBoxWidget_GetText(laGroupBoxWidget* box, laString* str);

// *****************************************************************************
/* Function:
    void laGroupBoxWidget_SetText(laGroupBoxWidget* box, laString str)

  Summary:
    Sets the text value for the group box.

  Description:
    This function copies the contents of the input string into its internal
    string buffer.  The input string can then be freed or altered without 
    affecting the label's internal string value.

  Parameters:
    laGroupBoxWidget* box - the widget
    laString str - an laString object
    
  Returns:
    void
    
  Remarks:
    
*/
LIB_EXPORT laResult laGroupBoxWidget_SetText(laGroupBoxWidget* box, laString str);

// *****************************************************************************
/* Function:
    laHAlignment laGroupBoxWidget_GetAlignment(laGroupBoxWidget* box)

  Summary:
    Gets the horizontal alignmnet for the group box title text

  Description:
    

  Parameters:
    laGroupBoxWidget* box - the widget
        
  Returns:
    laHAlignment - the current halign value
    
  Remarks:
    
*/
LIB_EXPORT laHAlignment laGroupBoxWidget_GetAlignment(laGroupBoxWidget* box);

// *****************************************************************************
/* Function:
    laResult laGroupBoxWidget_SetAlignment(laGroupBoxWidget* box,
                                           laHAlignment align)

  Summary:
    Sets the alignment for the group box title text

  Description:
    

  Parameters:
    laGroupBoxWidget* box - the widget
    laHAlignment - the desired halign value
    
  Returns:
    laResult - the operation result
    
  Remarks:
    
*/
LIB_EXPORT laResult laGroupBoxWidget_SetAlignment(laGroupBoxWidget* box,
                                                  laHAlignment align);

// internal use only
void _laGroupBoxWidget_GetTextRect(laGroupBoxWidget* box,
								   GFX_Rect* textRect,
								   GFX_Rect* drawRect);

#endif // LA_GROUPBOX_WIDGET_ENABLED
#endif /* LIBARIA_GROUPBOX_H */