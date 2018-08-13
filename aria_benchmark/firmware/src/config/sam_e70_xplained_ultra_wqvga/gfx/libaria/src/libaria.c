#include "gfx/libaria/libaria.h"
#include "gfx/libaria/inc/libaria_context.h"

int32_t _initialized = LA_FALSE;

laResult laInitialize()
{
    if(_initialized == LA_TRUE)
        return LA_FAILURE;

    laContext_SetActive(NULL);

    _initialized = LA_TRUE;

    return LA_SUCCESS;
}

void laShutdown()
{
    laContext* context;

    if(_initialized == LA_FALSE)
        return;

    context = laContext_GetActive();

    if(context != NULL)
    {
        laContext_Destroy(context);
        laContext_SetActive(NULL);
    }

    _initialized = LA_FALSE;
}

void laUpdate(uint32_t dt)
{
    laContext_Update(dt);
}