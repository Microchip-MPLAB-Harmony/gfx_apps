#include "gfx/libaria/inc/libaria_event.h"

#include "gfx/libaria/inc/libaria_context.h"
#include "gfx/libaria/inc/libaria_input.h"

static laEventResult processEvent(laEvent* evt);

uint32_t laEvent_GetCount()
{
    laContext* context = laContext_GetActive();
    
    if(context == NULL)
        return 0;

    return context->event.events.size;
}

/*laResult laEvent_GetEvent(uint32_t index, laEvent* evt)
{
    laContext* context = laContext_GetActive();
    
    if(context == NULL || index >= context->event.events.size)
        return LA_FAILURE;

    laList_GetAtIndex(

    *evt = *context->event.events.elements[index];

    return LA_SUCCESS;
}*/

laResult laEvent_SetFilter(laEvent_FilterEvent cb)
{
    laContext* context = laContext_GetActive();
    
    if(context == NULL)
        return LA_FAILURE;

    context->event.filter = cb;

    return LA_SUCCESS;
}

laResult laEvent_AddEvent(laEvent* evt)
{
    laContext* context = laContext_GetActive();

    if(context == NULL || evt == NULL)
        return LA_FAILURE;

    laList_PushBack(&context->event.events, evt);

    return LA_SUCCESS;
}

laResult laEvent_ClearList()
{
    laContext* context = laContext_GetActive();

    if(context == NULL)
        return LA_FAILURE;

    laList_Destroy(&context->event.events);

    return LA_SUCCESS;
}

laResult laEvent_ProcessEvents()
{
    laContext* context = laContext_GetActive();
    laEvent* evt;
    laListNode* node;
    laEventResult res;

    if(context == NULL)
        return LA_FAILURE;

    if(context->event.events.size == 0)
        return LA_SUCCESS;
        
    node = context->event.events.head;
    
    if(context->event.events.size > 1)
    {
        node = node;
    }
    
    while(node != NULL)
    {
        //evt = context->event.events.values[i];
        evt = (laEvent*)node->val;

        if(context->event.filter != NULL &&
           context->event.filter(evt) == LA_FALSE)
           continue;

        node = node->next;

        res = processEvent(evt);
        
        if(res == LA_EVENT_HANDLED)
        {
            laList_Remove(&context->event.events, evt);
            
            context->memIntf.heap.free(evt);
        }
        else if(res == LA_EVENT_RESET_QUEUE)
        {
            laList_Destroy(&context->event.events);
            
            node = NULL;
        }
    }

    return LA_SUCCESS;
}

static laEventResult processEvent(laEvent* evt)
{
    switch(evt->id)
    {
        case LA_EVENT_SCREEN_CHANGE:
        {
            return _laContext_HandleScreenChangeEvent(evt);
            
            break;
        }
        case LA_EVENT_TOUCH_DOWN:
        case LA_EVENT_TOUCH_UP:
        case LA_EVENT_TOUCH_MOVED:
        {
            return _laInput_HandleInputEvent(evt);
        }
        default:
            break;
    }
    
    return LA_EVENT_HANDLED;
}