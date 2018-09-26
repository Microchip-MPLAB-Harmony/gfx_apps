#include "gfx/libaria/inc/libaria_widget_groupbox.h"

#if LA_GROUPBOX_WIDGET_ENABLED

#include "gfx/libaria/inc/libaria_context.h"
#include "gfx/libaria/inc/libaria_layer.h"
#include "gfx/libaria/inc/libaria_string.h"
#include "gfx/libaria/inc/libaria_utils.h"
#include "gfx/libaria/inc/libaria_widget.h"

#define DEFAULT_WIDTH           100
#define DEFAULT_HEIGHT          100

static void invalidateTextRect(laGroupBoxWidget* box)
{
    GFX_Rect textRect, drawRect;
    
    _laGroupBoxWidget_GetTextRect(box, &textRect, &drawRect);
    
    laLayer_AddDamageRect(laUtils_GetLayer((laWidget*)box),
		                  &drawRect,
					      LA_FALSE);
}

static void languageChanging(laGroupBoxWidget* box)
{
    if(laString_IsEmpty(&box->text) == LA_FALSE)
        invalidateTextRect(box);
}

void _laGroupBoxWidget_Constructor(laGroupBoxWidget* box)
{
    _laWidget_Constructor((laWidget*)box);
    
    box->widget.destructor = (laWidget_Destructor_FnPtr)&_laGroupBoxWidget_Destructor;

    box->widget.languageChangeEvent = (laWidget_LanguageChangingEvent_FnPtr)&languageChanging;

    box->widget.type = LA_WIDGET_GROUPBOX;

    // override base class methods
    box->widget.paint = (laWidget_Paint_FnPtr)&_laGroupBoxWidget_Paint;

    box->widget.rect.width = DEFAULT_WIDTH;
    box->widget.rect.height = DEFAULT_HEIGHT;

    box->widget.borderType = LA_WIDGET_BORDER_NONE;

    laString_Initialize(&box->text);
    
    box->halign = LA_HALIGN_LEFT;
}

void _laGroupBoxWidget_Destructor(laGroupBoxWidget* box)
{
    laString_Destroy(&box->text);

    _laWidget_Destructor((laWidget*)box);
}

/*void _laGroupBoxWidget_Update(laGroupBoxWidget* box)
{

}*/

laGroupBoxWidget* laGroupBoxWidget_New()
{
    laGroupBoxWidget* box = NULL;

    if(laContext_GetActive() == NULL)
        return NULL;

    box = laContext_GetActive()->memIntf.heap.calloc(1, sizeof(laGroupBoxWidget));

    _laGroupBoxWidget_Constructor(box);

    return box;
}

laHAlignment laGroupBoxWidget_GetAlignment(laGroupBoxWidget* box)
{
    if(box == NULL)
        return 0;

    return box->halign;
}

laResult laGroupBoxWidget_SetAlignment(laGroupBoxWidget* box,
                                       laHAlignment align)
{
    if(box == NULL)
        return LA_FAILURE;

    if(box->halign == align)
        return LA_SUCCESS;

    box->halign = align;

    laWidget_Invalidate((laWidget*)box);
    
    return LA_SUCCESS;
}

laResult laGroupBoxWidget_GetText(laGroupBoxWidget* box, laString* str)
{
    if(box == NULL)
        return LA_FAILURE;
    
    return laString_Copy(str, &box->text);
}

laResult laGroupBoxWidget_SetText(laGroupBoxWidget* box, laString str)
{
    if(box == NULL)
        return LA_FAILURE;
        
    if(laString_Compare(&box->text, &str) == 0)
        return LA_SUCCESS;
        
    if(laString_Copy(&box->text, &str) == LA_FAILURE)
        return LA_FAILURE;
    
    laWidget_Invalidate((laWidget*)box);
    
    return LA_SUCCESS;
}

#endif // LA_GROUPBOX_WIDGET_ENABLED