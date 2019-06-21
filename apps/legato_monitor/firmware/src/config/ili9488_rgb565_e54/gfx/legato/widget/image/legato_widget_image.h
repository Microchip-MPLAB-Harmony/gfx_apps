/*******************************************************************************
 Module for Microchip Graphics Library - Legato User Interface Library

  Company:
    Microchip Technology Inc.

  File Name:
    legato_widget_image.h

  Summary:


  Description:
    This module implements image widget functions.
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

#ifndef LEGATO_IMAGE_H
#define LEGATO_IMAGE_H
//DOM-IGNORE-END

#include "gfx/legato/common/legato_common.h"

#if LE_IMAGE_WIDGET_ENABLED

#include "gfx/legato/widget/legato_widget.h"

typedef struct leImageWidget leImageWidget;
typedef struct leImage leImage;

// *****************************************************************************
// *****************************************************************************
// Section: Data Types and Constants
// *****************************************************************************
// *****************************************************************************
#if LE_IMAGE_WIDGET_DEBUG_CB == 1
typedef void (*leImageWidget_DrawEventCallback)(leImageWidget* );

#define DEBUG_START_VFN void (*setDebugDrawStartCallback(THIS_TYPE* _this, leImageWidget_DrawEventCallback cb);
#define DEBUG_END_VFN void (*setDebugDrawEndCallback(THIS_TYPE* _this, leImageWidget_DrawEventCallback cb);
#else
#define DEBUG_START_VFN
#define DEBUG_END_VFN
#endif


// DOM-IGNORE-BEGIN

#define LE_IMAGEWIDGET_VTABLE(THIS_TYPE) \
    LE_WIDGET_VTABLE(THIS_TYPE) \
    \
    leImage*  (*getImage)(const THIS_TYPE* _this); \
    leResult  (*setImage)(THIS_TYPE* _this, leImage* img); \
    DEBUG_START_VFN \
    DEBUG_END_VFN \
    
typedef struct leImageWidgetVTable
{
	LE_IMAGEWIDGET_VTABLE(leImageWidget)
} leImageWidgetVTable; 

// DOM-IGNORE-END

// *****************************************************************************
/* Enumeration:
    leImageWidget

  Summary:
    Image widget struct definition

  Description:
    An image widget displays an image asset.

  Remarks:
    None.
*/
typedef struct leImageWidget
{
    leWidget widget; // widget base class

    leImageWidgetVTable* fn;

    const leImage* image; // pointer to image asset
} leImageWidget;

// *****************************************************************************
// *****************************************************************************
// Section: Routines
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    leImageWidget* leImageWidget_New()

  Summary:
    Allocates memory for and initializes a new widget of this type.  The
    application is responsible for the managment of this memory until the
    widget is added to a widget tree.

  Description:


  Parameters:
    void

  Returns:
    leImageWidget* - the widget

  Remarks:

*/
LIB_EXPORT leImageWidget* leImageWidget_New();

LIB_EXPORT leResult leImageWidget_PNew(leImageWidget* img);

// *****************************************************************************
/* Function:
    leImage* leImageWidget_GetImage(leImageWidget* img)

  Summary:
    Gets the image asset pointer for the widget.

  Description:


  Parameters:
    leImageWidget* img - the widget

  Returns:
    leImage* - the image asset pointer

  Remarks:

*/
//LIB_EXPORT leImage* leImageWidget_GetImage(leImageWidget* img);
// *****************************************************************************
/* Function:
    leResult leImageWidget_SetImage(leImageWidget* img,
                                    leImage* imgAst)

  Summary:
    Sets the image asset pointer for the widget.

  Description:


  Parameters:
    lleImageWidget* img - the widget
    leImage* imgAst - the image asset pointer

  Returns:
    leResult - the operation result

  Remarks:

*/
/*LIB_EXPORT leResult leImageWidget_SetImage(leImageWidget* img,
                                           leImage* imgAst);
*/

#endif // LE_IMAGE_WIDGET_ENABLED
#endif /* LEGATO_IMAGE_H */
