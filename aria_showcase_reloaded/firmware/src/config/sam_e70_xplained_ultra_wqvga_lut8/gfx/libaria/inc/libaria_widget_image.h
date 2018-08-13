/*******************************************************************************
 Module for Microchip Graphics Library - Aria User Interface Library

  Company:
    Microchip Technology Inc.

  File Name:
    libaria_widget_image.h

  Summary:
    

  Description:
    This module implements image widget functions.
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

#ifndef LIBARIA_IMAGE_H
#define LIBARIA_IMAGE_H
//DOM-IGNORE-END

#include "gfx/libaria/inc/libaria_common.h"

#if LA_IMAGE_WIDGET_ENABLED

#include "gfx/libaria/inc/libaria_widget.h"

typedef struct laImageWidget_t laImageWidget;

// *****************************************************************************
// *****************************************************************************
// Section: Data Types and Constants
// *****************************************************************************
// *****************************************************************************
typedef void (*laImageWidget_DrawEventCallback)(laImageWidget* );
// *****************************************************************************
/* Enumeration:
    laImageWidget_t

  Summary:
    Image widget struct definition

  Description:
    An image widget displays an image asset.

  Remarks:
    None.
*/    
typedef struct laImageWidget_t
{
    laWidget widget; // widget base class

    laHAlignment halign; // image horizontal alignment
    laVAlignment valign; // image vertical alignment

    GFXU_ImageAsset* image; // pointer to image asset
    
    GFXU_ExternalAssetReader* reader; // asset reader
    
    laImageWidget_DrawEventCallback ImageDrawStart;
    laImageWidget_DrawEventCallback ImageDrawEnd;
    
} laImageWidget;

void _laImageWidget_Constructor(laImageWidget* img);
void _laImageWidget_Destructor(laImageWidget* img);

void _laImageWidget_Paint(laImageWidget* img);

// *****************************************************************************
// *****************************************************************************
// Section: Routines
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    laImageWidget* laImageWidget_New()

  Summary:
    Allocates memory for and initializes a new widget of this type.  The
    application is responsible for the managment of this memory until the
    widget is added to a widget tree.

  Description:
    

  Parameters:
    void
    
  Returns:
    laImageWidget* - the widget
    
  Remarks:
    
*/
LIB_EXPORT laImageWidget* laImageWidget_New();

// *****************************************************************************
/* Function:
    laHAlignment laImageWidget_GetHAlignment(laImageWidget* img)

  Summary:
    Gets the image horizontal alignment value.

  Description:
    

  Parameters:
    laImageWidget* img - the widget
    
  Returns:
    laHAlignment - the horizontal alignment value
    
  Remarks:
    
*/
LIB_EXPORT laHAlignment laImageWidget_GetHAlignment(laImageWidget* img);

// *****************************************************************************
/* Function:
    laResult laImageWidget_SetHAlignment(laImageWidget* img,
                                     laHAlignment align)

  Summary:
    Sets the image horizontal alignment value.

  Description:
    

  Parameters:
    laImageWidget* img - the widget
    laHAlignment align - the horizontal alignment value
    
  Returns:
    laResult - the operation result
    
  Remarks:
    
*/
LIB_EXPORT laResult laImageWidget_SetHAlignment(laImageWidget* img,
                                                laHAlignment align);

// *****************************************************************************
/* Function:
    laVAlignment laImageWidget_GetVAlignment(laImageWidget* img)

  Summary:
    Gets the image vertical alignment value.

  Description:
    

  Parameters:
    laImageWidget* img - the widget
    
  Returns:
    laVAlignment - the vertical alignment setting
    
  Remarks:
    
*/
LIB_EXPORT laVAlignment laImageWidget_GetVAlignment(laImageWidget* img);

// *****************************************************************************
/* Function:
    laResult laImageWidget_SetVAlignment(laImageWidget* img,
                                         laVAlignment align)

  Summary:
    Sets the image vertical alignment value.

  Description:
    

  Parameters:
    laImageWidget* img - the widget
    laVAlignment - the vertical alignment setting
    
  Returns:
    laResult - the operation result
    
  Remarks:
    
*/
LIB_EXPORT laResult laImageWidget_SetVAlignment(laImageWidget* img,
                                                laVAlignment align);                                                    

// *****************************************************************************
/* Function:
    GFXU_ImageAsset* laImageWidget_GetImage(laImageWidget* img)

  Summary:
    Gets the image asset pointer for the widget.

  Description:
    

  Parameters:
    laImageWidget* img - the widget
    
  Returns:
    GFXU_ImageAsset* - the image asset pointer
    
  Remarks:
    
*/
LIB_EXPORT GFXU_ImageAsset* laImageWidget_GetImage(laImageWidget* img);
// *****************************************************************************
/* Function:
    laResult laImageWidget_SetImage(laImageWidget* img,
                                    GFXU_ImageAsset* imgAst)

  Summary:
    Sets the image asset pointer for the widget.

  Description:
    

  Parameters:
    llaImageWidget* img - the widget
    GFXU_ImageAsset* imgAst - the image asset pointer
    
  Returns:
    laResult - the operation result
    
  Remarks:
    
*/
LIB_EXPORT laResult laImageWidget_SetImage(laImageWidget* img,
                                           GFXU_ImageAsset* imgAst);

// internal use only
void _laImageWidget_GetImageRect(laImageWidget* img,
                                 GFX_Rect* imgRect,
                                 GFX_Rect* imgSrcRect);
                                  


void laImageWidget_SetCallBackStart(laImageWidget* image, laImageWidget_DrawEventCallback cb);
void laImageWidget_SetCallBackEnd(laImageWidget* image, laImageWidget_DrawEventCallback cb);


#endif // LA_IMAGE_WIDGET_ENABLED
#endif /* LIBARIA_IMAGE_H */