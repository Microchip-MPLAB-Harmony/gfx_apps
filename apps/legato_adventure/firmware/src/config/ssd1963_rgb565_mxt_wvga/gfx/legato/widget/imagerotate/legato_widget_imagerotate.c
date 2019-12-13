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

#include "gfx/legato/widget/imagerotate/legato_widget_imagerotate.h"

#if LE_IMAGEROTATE_WIDGET_ENABLED

#include "gfx/legato/common/legato_error.h"
#include "gfx/legato/common/legato_math.h"
#include "gfx/legato/common/legato_utils.h"
#include "gfx/legato/memory/legato_memory.h"
#include "gfx/legato/string/legato_string.h"
#include "gfx/legato/widget/legato_widget.h"

#define DEFAULT_WIDTH           100
#define DEFAULT_HEIGHT          100

static leImageRotateWidgetVTable imageRotateWidgetVTable;

static void calculateImageRect(leImageRotateWidget* img)
{
    lePoint point[4];
    int32_t minX = 99999;
    int32_t maxX = -99999;
    int32_t minY = 99999;
    int32_t maxY = -99999;

    uint32_t i;

    if(img->image == NULL)
    {
        img->imageRect = leRect_Zero;

        return;
    }

    point[0].x = 0;
    point[0].y = 0;

    point[1].x = img->image->buffer.size.width;
    point[1].y = 0;

    point[2].x = 0;
    point[2].y = img->image->buffer.size.height;

    point[3].x = point[1].x;
    point[3].y = point[2].y;

    point[0] = leRotatePoint(point[0], img->origin, img->angle);
    point[1] = leRotatePoint(point[1], img->origin, img->angle);
    point[2] = leRotatePoint(point[2], img->origin, img->angle);
    point[3] = leRotatePoint(point[3], img->origin, img->angle);

    for(i = 0; i < 4; i++)
    {
        if(point[i].x < minX)
        {
            minX = point[i].x;
        }

        if(point[i].x > maxX)
        {
            maxX = point[i].x;
        }

        if(point[i].y < minY)
        {
            minY = point[i].y;
        }

        if(point[i].y > maxY)
        {
            maxY = point[i].y;
        }
    }

    img->imageRect.x = minX;
    img->imageRect.y = minY;
    img->imageRect.width = maxX - minX;
    img->imageRect.height = maxY - minY;
}

void leImageRotateWidget_Constructor(leImageRotateWidget* _this)
{
    leWidget_Constructor((leWidget*)_this);
    
    _this->widget.fn = (void*)&imageRotateWidgetVTable;
    _this->fn = &imageRotateWidgetVTable;
    
    _this->widget.type = LE_WIDGET_IMAGEROTATE;

    _this->widget.rect.width = DEFAULT_WIDTH;
    _this->widget.rect.height = DEFAULT_HEIGHT;

    _this->widget.borderType = LE_WIDGET_BORDER_NONE;
    _this->widget.backgroundType = LE_WIDGET_BACKGROUND_FILL;

    _this->image = NULL;

    _this->origin = lePoint_Zero;
    _this->angle = 0;

    _this->filter = LE_IMAGEFILTER_NEAREST_NEIGHBOR;
}

void _leWidget_Destructor(leWidget* _this);

void _leImageRotateWidget_Destructor(leImageRotateWidget* _this)
{
    _leWidget_Destructor((leWidget*)_this);
}

leImageRotateWidget* leImageRotateWidget_New()
{
    leImageRotateWidget* img = NULL;

    img = LE_MALLOC(sizeof(leImageRotateWidget));

    if(img == NULL)
        return NULL;
    
    leImageRotateWidget_Constructor(img);

    return img;
}

static leImage* getImage(const leImageRotateWidget* _this)
{
    LE_ASSERT_THIS();

    return (leImage*)_this->image;
}

static leResult setImage(leImageRotateWidget* _this,
                         const leImage* imgAst)
{
    LE_ASSERT_THIS();

    _this->image = imgAst;

    calculateImageRect(_this);

    _this->fn->invalidate(_this);
    
    return LE_SUCCESS;
}

static lePoint getOrigin(const leImageRotateWidget* _this)
{
    LE_ASSERT_THIS();

    return _this->origin;
}

static leResult setOriginX(leImageRotateWidget* _this,
                           int32_t x)
{
    LE_ASSERT_THIS();

    if(_this->origin.x == x)
    {
        return LE_SUCCESS;
    }

    _this->origin.x = x;

    _this->fn->invalidate(_this);

    return LE_SUCCESS;
}

static leResult setOriginY(leImageRotateWidget* _this,
                           int32_t y)
{
    LE_ASSERT_THIS();

    if(_this->origin.y == y)
    {
        return LE_SUCCESS;
    }

    _this->origin.y = y;

    _this->fn->invalidate(_this);

    return LE_SUCCESS;
}

static int32_t getAngle(const leImageRotateWidget* _this)
{
    LE_ASSERT_THIS();

    return _this->angle;
}

static leResult setAngle(leImageRotateWidget* _this,
                         int32_t angle)
{
    LE_ASSERT_THIS();

    if(_this->angle == angle)
        return LE_SUCCESS;

    _this->angle = angle;

    calculateImageRect(_this);

    _this->fn->invalidate(_this);

    return LE_SUCCESS;
}

static leImageFilterMode getFilter(const leImageRotateWidget* _this)
{
    LE_ASSERT_THIS();
        
    return _this->filter;
}

static leResult setFilter(leImageRotateWidget* _this,
                          leImageFilterMode filter)
{
    LE_ASSERT_THIS();
        
    if(_this->filter == filter)
        return LE_SUCCESS;
        
    _this->filter = filter;
    
    _this->fn->invalidate(_this);
        
    return LE_SUCCESS;
}

void _leWidget_FillVTable(leWidgetVTable* tbl);
void _leImageRotateWidget_Paint(leImageRotateWidget* _this);

void _leImageRotateWidget_GenerateVTable()
{
    _leWidget_FillVTable((void*)&imageRotateWidgetVTable);
    
    /* overrides from base class */
    imageRotateWidgetVTable._destructor = _leImageRotateWidget_Destructor;
    imageRotateWidgetVTable._paint = _leImageRotateWidget_Paint;

    /* member functions */
    imageRotateWidgetVTable.getImage = getImage;
    imageRotateWidgetVTable.setImage = setImage;
    imageRotateWidgetVTable.getOrigin = getOrigin;
    imageRotateWidgetVTable.setOriginX = setOriginX;
    imageRotateWidgetVTable.setOriginY = setOriginY;
    imageRotateWidgetVTable.getAngle = getAngle;
    imageRotateWidgetVTable.setAngle = setAngle;
    imageRotateWidgetVTable.getFilter = getFilter;
    imageRotateWidgetVTable.setFilter = setFilter;
}

void _leImageRotateWidget_FillVTable(leImageRotateWidgetVTable* tbl)
{
    *tbl = imageRotateWidgetVTable;
}


#endif // LE_IMAGEPLUS_WIDGET_ENABLED