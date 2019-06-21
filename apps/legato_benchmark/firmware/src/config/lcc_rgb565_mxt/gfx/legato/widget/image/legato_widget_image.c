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

#include "gfx/legato/widget/image/legato_widget_image.h"

#if LE_IMAGE_WIDGET_ENABLED

#include <string.h>

#include "gfx/legato/image/legato_image.h"
#include "gfx/legato/string/legato_string.h"
#include "gfx/legato/common/legato_utils.h"
#include "gfx/legato/memory/legato_memory.h"
#include "gfx/legato/renderer/legato_renderer.h"
#include "gfx/legato/widget/legato_widget.h"

static leImageWidgetVTable imageWidgetVTable;

#define DEFAULT_WIDTH           100
#define DEFAULT_HEIGHT          100

void _leImageWidget_GetImageRect(const leImageWidget* img,
                                 leRect* imgRect,
                                 leRect* imgSrcRect);

static void invalidateImageRect(const leImageWidget* _this)
{
    leRect rect, imgRect, clipRect;
    
    _leImageWidget_GetImageRect(_this, &imgRect, &clipRect);
    
    rect = _this->fn->localRect(_this);
    
    leRectClip(&rect, &imgRect, &clipRect);
    
    leUtils_RectToScreenSpace((leWidget*)_this, &clipRect);
    
    _this->fn->_damageArea(_this, &clipRect);
}

/* base class constructor and destructor */
void _leWidget_Destructor(leWidget* _this);

void _leImageWidget_Constructor(leImageWidget* _this)
{
    leWidget_Constructor((leWidget*)_this);
    
    _this->widget.fn = (void*)&imageWidgetVTable;
    _this->fn = &imageWidgetVTable;
    
    _this->widget.type = LE_WIDGET_IMAGE;

    _this->widget.rect.width = DEFAULT_WIDTH;
    _this->widget.rect.height = DEFAULT_HEIGHT;

    _this->widget.borderType = LE_WIDGET_BORDER_NONE;
    _this->widget.backgroundType = LE_WIDGET_BACKGROUND_NONE;

    _this->image = NULL;
    
#if LE_IMAGE_WIDGET_DEBUG_CB == 1
    leImageWidget_DrawEventCallback debugDrawStart;
    leImageWidget_DrawEventCallback debugDrawEnd;
#endif
}

void _leImageWidget_Destructor(leImageWidget* _this)
{    
    _leWidget_Destructor((leWidget*)_this);
}

leImageWidget* leImageWidget_New()
{
    leImageWidget* img = NULL;

    img = LE_MALLOC(sizeof(leImageWidget));

    if(img == NULL)
        return NULL;
    
    _leImageWidget_Constructor(img);

    return img;
}

leResult leImageWidget_PNew(leImageWidget* img)
{
    if(img == NULL)
        return LE_FAILURE;
        
    memset(img, 0, sizeof(leImageWidget));
    
    _leImageWidget_Constructor(img);

    return LE_SUCCESS;
}

static void invalidateContents(const leImageWidget* _this)
{
    if(_this->image != NULL)
    {
        invalidateImageRect(_this);
    }
}

leImage* _leImageWidget_GetImage(const leImageWidget* _this)
{
    return (leImage*)_this->image;
}

leResult _leImageWidget_SetImage(leImageWidget* _this,
                                 leImage* imgAst)
{
    if(_this->image == imgAst)
        return LE_SUCCESS;
        
    if(_this->image != NULL)
        invalidateImageRect(_this);

    _this->image = imgAst;

    if(_this->image != NULL)
        invalidateImageRect(_this);
    
    return LE_SUCCESS;
}

#if LE_IMAGE_WIDGET_DEBUG_CB == 1
void leImageWidget_SetDebugStartCallBack(leImageWidget* _this,
                                         leImageWidget_DrawEventCallback cb)
{
    _this->debugDrawStart = cb;
}

void leImageWidget_SetDebugCallBackEnd(leImageWidget* _this,
                                       leImageWidget_DrawEventCallback cb)
{
    _this->debugDrawEnd = cb;
}
#endif

void _leWidget_FillVTable(leWidgetVTable* tbl);
void _leImageWidget_Paint(leImageWidget* _this);

void _leImageWidget_GenerateVTable()
{
    _leWidget_FillVTable((void*)&imageWidgetVTable);
    
    /* overrides from base class */
    imageWidgetVTable._destructor = _leImageWidget_Destructor;
    imageWidgetVTable._paint = _leImageWidget_Paint;
    imageWidgetVTable.invalidateContents = invalidateContents;
    
    /* member functions */
    imageWidgetVTable.getImage = _leImageWidget_GetImage;
    imageWidgetVTable.setImage = _leImageWidget_SetImage;
    
#if LE_IMAGE_WIDGET_DEBUG_CB == 1
    imageWidgetVTable.setDebugDrawStartCallback = leImageWidget_SetDebugStartCallBack;
    imageWidgetVTable.setDebugDrawEndCallback = leImageWidget_SetDebugCallBackEnd;
#endif
}

void _leImageWidget_FillVTable(leImageWidgetVTable* tbl)
{
    *tbl = imageWidgetVTable;
}

#endif // LE_IMAGE_WIDGET_ENABLED