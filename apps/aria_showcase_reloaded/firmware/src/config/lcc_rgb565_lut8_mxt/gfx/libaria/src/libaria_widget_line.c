#include "gfx/libaria/inc/libaria_widget_line.h"

#if LA_LINE_WIDGET_ENABLED

#include "gfx/libaria/inc/libaria_context.h"
#include "gfx/libaria/inc/libaria_string.h"
#include "gfx/libaria/inc/libaria_utils.h"
#include "gfx/libaria/inc/libaria_widget.h"

#define DEFAULT_WIDTH           100
#define DEFAULT_HEIGHT          100

void _laLineWidget_Constructor(laLineWidget* line)
{
    _laWidget_Constructor((laWidget*)line);
    
    line->widget.destructor = (laWidget_Destructor_FnPtr)&_laLineWidget_Destructor;

    line->widget.type = LA_WIDGET_LINE;

    // override base class methods
    line->widget.paint = (laWidget_Paint_FnPtr)&_laLineWidget_Paint;

    line->widget.rect.width = DEFAULT_WIDTH;
    line->widget.rect.height = DEFAULT_HEIGHT;

    line->widget.borderType = LA_WIDGET_BORDER_NONE;
    line->widget.backgroundType = LA_WIDGET_BACKGROUND_NONE;

    line->x1 = 0;
    line->y1 = 0;
    line->x2 = DEFAULT_WIDTH - 1;
    line->y2 = DEFAULT_HEIGHT - 1;
}

void _laLineWidget_Destructor(laLineWidget* line)
{
    _laWidget_Destructor((laWidget*)line);
}

laLineWidget* laLineWidget_New()
{
    laLineWidget* line = NULL;

    if(laContext_GetActive() == NULL)
        return NULL;

    line = laContext_GetActive()->memIntf.heap.calloc(1, sizeof(laLineWidget));

    if(line == NULL)
        return NULL;
    
    _laLineWidget_Constructor(line);

    return line;
}

laResult laLineWidget_GetStartPoint(laLineWidget* line, int32_t* x, int32_t* y)
{
    if(line == NULL || x == NULL || y == NULL)
        return LA_FAILURE;
        
    *x = line->x1;
    *y = line->y1;
        
    return LA_SUCCESS;
}

laResult laLineWidget_SetStartPoint(laLineWidget* line, int32_t x, int32_t y)
{
    if(line == NULL)
        return LA_FAILURE;
        
    if(line->x1 == x && line->y1 == y)
        return LA_SUCCESS;
        
    line->x1 = x;
    line->y1 = y;
    
    laWidget_Invalidate((laWidget*)line);
        
    return LA_SUCCESS;
}

laResult laLineWidget_GetEndPoint(laLineWidget* line, int32_t* x, int32_t* y)
{
    if(line == NULL || x == NULL || y == NULL)
        return LA_FAILURE;
        
    *x = line->x2;
    *y = line->y2;
        
    return LA_SUCCESS;
}

laResult laLineWidget_SetEndPoint(laLineWidget* line, int32_t x, int32_t y)
{
    if(line == NULL)
        return LA_FAILURE;
        
    if(line->x2 == x && line->y2 == y)
        return LA_SUCCESS;
        
    line->x2 = x;
    line->y2 = y;
    
    laWidget_Invalidate((laWidget*)line);
        
    return LA_SUCCESS;
}

#endif // LA_LINE_WIDGET_ENABLED