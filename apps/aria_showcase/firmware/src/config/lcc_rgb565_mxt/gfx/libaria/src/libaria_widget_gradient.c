#include "gfx/libaria/inc/libaria_widget_gradient.h"

#if LA_GRADIENT_WIDGET_ENABLED

#include "gfx/libaria/inc/libaria_context.h"
#include "gfx/libaria/inc/libaria_string.h"
#include "gfx/libaria/inc/libaria_utils.h"
#include "gfx/libaria/inc/libaria_widget.h"

#define DEFAULT_WIDTH           100
#define DEFAULT_HEIGHT          100

void _laGradientWidget_Constructor(laGradientWidget* grad)
{
    _laWidget_Constructor((laWidget*)grad);
    
    grad->widget.destructor = (laWidget_Destructor_FnPtr)&_laGradientWidget_Destructor;

    grad->widget.type = LA_WIDGET_GRADIENT;

    // override base class methods
    grad->widget.paint = (laWidget_Paint_FnPtr)&_laGradientWidget_Paint;

    grad->widget.rect.width = DEFAULT_WIDTH;
    grad->widget.rect.height = DEFAULT_HEIGHT;

    grad->widget.borderType = LA_WIDGET_BORDER_NONE;
    grad->widget.backgroundType = LA_WIDGET_BACKGROUND_FILL;

    grad->dir = LA_GRADIENT_DIRECTION_RIGHT;
}

void _laGradientWidget_Destructor(laGradientWidget* grad)
{
    _laWidget_Destructor((laWidget*)grad);
}

laGradientWidget* laGradientWidget_New()
{
    laGradientWidget* grad = NULL;

    if(laContext_GetActive() == NULL)
        return NULL;

    grad = laContext_GetActive()->memIntf.heap.calloc(1, sizeof(laGradientWidget));

    if(grad == NULL)
        return NULL;
    
    _laGradientWidget_Constructor(grad);

    return grad;
}

laGradientWidgetDirection laGradientWidget_GetDirection(laGradientWidget* grad)
{
    if(grad == NULL)
        return 0;
        
    return grad->dir;
}

laResult laGradientWidget_SetDirection(laGradientWidget* grad,
                                       laGradientWidgetDirection dir)
{
    if(grad == NULL)
        return LA_FAILURE;
        
    if(grad->dir == dir)
        return LA_SUCCESS;
        
    grad->dir = dir;
    
    laWidget_Invalidate((laWidget*)grad);
        
    return LA_SUCCESS;
}

#endif // LA_GRADIENT_WIDGET_ENABLED