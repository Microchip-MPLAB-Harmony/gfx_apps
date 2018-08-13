#include "gfx/libaria/inc/libaria_widget_bar_graph.h"

#if LA_BAR_GRAPH_WIDGET_ENABLED

#include "gfx/libaria/inc/libaria_context.h"
#include "gfx/libaria/inc/libaria_string.h"
#include "gfx/libaria/inc/libaria_utils.h"
#include "gfx/libaria/inc/libaria_widget.h"

#define DEFAULT_WIDTH           101
#define DEFAULT_HEIGHT          101

#define DEFAULT_TICK_LENGTH     5
#define DEFAULT_TICK_INTERVAL   10
#define DEFAULT_SUBTICK_INTERVAL   5
#define DEFAULT_MAX_VALUE       100
#define DEFAULT_MIN_VALUE       0

void _laBarGraphWidget_Constructor(laBarGraphWidget* graph)
{
    _laWidget_Constructor((laWidget*)graph);

    graph->widget.type = LA_WIDGET_ARC;
    
    graph->widget.destructor = (laWidget_Destructor_FnPtr)&_laBarGraphWidget_Destructor;

    // override base class methods
    graph->widget.paint = (laWidget_Paint_FnPtr)&_laBarGraphWidget_Paint;

    graph->widget.rect.width = DEFAULT_WIDTH;
    graph->widget.rect.height = DEFAULT_HEIGHT;

    graph->widget.borderType = LA_WIDGET_BORDER_NONE;
    graph->widget.backgroundType = LA_WIDGET_BACKGROUND_NONE;
    
    graph->tickLength = DEFAULT_TICK_LENGTH;
    graph->fillGraphArea = LA_TRUE;
    graph->stacked = LA_FALSE;
    graph->maxValue = DEFAULT_MAX_VALUE;
    graph->minValue = DEFAULT_MIN_VALUE;
    graph->tickInterval = DEFAULT_TICK_INTERVAL;
    graph->subtickInterval = DEFAULT_SUBTICK_INTERVAL;
    
    graph->valueGridlinesVisible = LA_TRUE;
    graph->valueAxisLabelsVisible = LA_TRUE;
    graph->valueAxisTicksVisible = LA_TRUE;
    graph->valueAxisSubticksVisible = LA_TRUE;
    graph->valueAxisTicksPosition = BAR_GRAPH_TICK_CENTER;
    graph->valueAxisSubticksPosition = BAR_GRAPH_TICK_CENTER;
    
    graph->categAxisLabelsVisible = LA_TRUE;
    graph->categAxisTicksVisible = LA_TRUE;
    graph->categAxisTicksPosition = BAR_GRAPH_TICK_CENTER;
    
    laArray_Create(&graph->dataSeries);
    laArray_Create(&graph->categories);
}

void _laBarGraphWidget_Destructor(laBarGraphWidget* graph)
{
    laBarGraphWidget_DestroyAll(graph);
    
    _laWidget_Destructor((laWidget*)graph);
}

laBarGraphWidget* laBarGraphWidget_New()
{
    laBarGraphWidget* graph = NULL;

    if(laContext_GetActive() == NULL)
        return NULL;

    graph = laContext_GetActive()->memIntf.heap.calloc(1, sizeof(laBarGraphWidget));

    if(graph == NULL)
        return NULL;
    
    _laBarGraphWidget_Constructor(graph);

    return graph;
}

uint32_t laBarGraphWidget_GetTickLength(laBarGraphWidget* graph)
{
    if(graph == NULL)
        return LA_FAILURE;
        
    return graph->tickLength;
}

laResult laBarGraphWidget_SetTickLength(laBarGraphWidget* graph, uint32_t length)
{
    if(graph == NULL)
        return LA_FAILURE;
        
    if(graph->tickLength == length)
        return LA_SUCCESS;
        
    graph->tickLength = length;
    
    laWidget_Invalidate((laWidget*)graph);
        
    return LA_SUCCESS;
}

laBool laBarGraphWidget_GetStacked(laBarGraphWidget* graph)
{
    if(graph == NULL)
        return LA_FAILURE;
        
    return graph->stacked;
}

laResult laBarGraphWidget_SetStacked(laBarGraphWidget* graph, laBool stacked)
{
    if(graph == NULL)
        return LA_FAILURE;
        
    if(graph->stacked == stacked)
        return LA_SUCCESS;
        
    graph->stacked = stacked;
    
    laWidget_Invalidate((laWidget*)graph);
        
    return LA_SUCCESS;
}

uint32_t laBarGraphWidget_GetMaxValue(laBarGraphWidget* graph, laBarGraphValueAxis axis)
{
    if(graph == NULL)
        return LA_FAILURE;
        
    return graph->maxValue;
}

laResult laBarGraphWidget_SetMaxValue(laBarGraphWidget* graph, laBarGraphValueAxis axis, int32_t value)
{
    if(graph == NULL)
        return LA_FAILURE;

    if (value <= graph->minValue)
        return LA_FAILURE;
    
    if(graph->maxValue == value)
        return LA_SUCCESS;
        
    graph->maxValue = value;
    
    laWidget_Invalidate((laWidget*)graph);
        
    return LA_SUCCESS;
}

uint32_t laBarGraphWidget_GetMinValue(laBarGraphWidget* graph, laBarGraphValueAxis axis)
{
    if(graph == NULL)
        return LA_FAILURE;
        
    return graph->minValue;
}

laResult laBarGraphWidget_SetMinValue(laBarGraphWidget* graph, laBarGraphValueAxis axis, int32_t value)
{
    if(graph == NULL)
        return LA_FAILURE;
    
    if (value >= graph->maxValue)
        return LA_FAILURE;

    if(graph->minValue == value)
        return LA_SUCCESS;
        
    graph->minValue = value;
    
    laWidget_Invalidate((laWidget*)graph);
        
    return LA_SUCCESS;
}

laBool laBarGraphWidget_GetValueAxisLabelsVisible(laBarGraphWidget* graph, laBarGraphValueAxis axis)
{
    if(graph == NULL)
        return LA_FAILURE;
        
    return graph->valueAxisLabelsVisible;
}

laResult laBarGraphWidget_SetValueAxisLabelsVisible(laBarGraphWidget* graph, laBarGraphValueAxis axis, laBool visible)
{
    if(graph == NULL)
        return LA_FAILURE;
        
    if(graph->valueAxisLabelsVisible == visible)
        return LA_SUCCESS;
        
    graph->valueAxisLabelsVisible = visible;
    
    laWidget_Invalidate((laWidget*)graph);
        
    return LA_SUCCESS;
}

laBool laBarGraphWidget_GetFillGraphArea(laBarGraphWidget* graph)
{
    if(graph == NULL)
        return LA_FAILURE;
        
    return graph->fillGraphArea;
}

laResult laBarGraphWidget_SetFillGraphArea(laBarGraphWidget* graph, laBool fill)
{
    if(graph == NULL)
        return LA_FAILURE;
        
    if(graph->fillGraphArea == fill)
        return LA_SUCCESS;
        
    graph->fillGraphArea = fill;
    
    laWidget_Invalidate((laWidget*)graph);
        
    return LA_SUCCESS;
}

laBool laBarGraphWidget_GetGridlinesVisible(laBarGraphWidget* graph, laBarGraphValueAxis axis)
{
    if(graph == NULL)
        return LA_FAILURE;
        
    return graph->valueGridlinesVisible;
}

laResult laBarGraphWidget_SetGridlinesVisible(laBarGraphWidget* graph, laBarGraphValueAxis axis, laBool visible)
{
    if(graph == NULL)
        return LA_FAILURE;
        
    if(graph->valueGridlinesVisible == visible)
        return LA_SUCCESS;
        
    graph->valueGridlinesVisible = visible;
    
    laWidget_Invalidate((laWidget*)graph);
        
    return LA_SUCCESS;
}

laBool laBarGraphWidget_GetValueAxisTicksVisible(laBarGraphWidget* graph, laBarGraphValueAxis axis)
{
    if(graph == NULL)
        return LA_FAILURE;
        
    return graph->valueAxisTicksVisible;
}

laResult laBarGraphWidget_SetValueAxisTicksVisible(laBarGraphWidget* graph, laBarGraphValueAxis axis, laBool visible)
{
    if(graph == NULL)
        return LA_FAILURE;
        
    if(graph->valueAxisTicksVisible == visible)
        return LA_SUCCESS;
        
    graph->valueAxisTicksVisible = visible;
    
    laWidget_Invalidate((laWidget*)graph);
        
    return LA_SUCCESS;
}

uint32_t laBarGraphWidget_GetValueAxisTickInterval(laBarGraphWidget* graph, laBarGraphValueAxis axis)
{
    if(graph == NULL)
        return LA_FAILURE;
        
    return graph->tickInterval;
}

laResult laBarGraphWidget_SetValueAxisTickInterval(laBarGraphWidget* graph, laBarGraphValueAxis axis, uint32_t interval)
{
    if(graph == NULL)
        return LA_FAILURE;
        
    if(graph->tickInterval == interval)
        return LA_SUCCESS;
        
    graph->tickInterval = interval;
    
    laWidget_Invalidate((laWidget*)graph);
        
    return LA_SUCCESS;
}

uint32_t laBarGraphWidget_GetValueAxisSubtickInterval(laBarGraphWidget* graph, laBarGraphValueAxis axis)
{
    if(graph == NULL)
        return LA_FAILURE;
        
    return graph->subtickInterval;
}

laResult laBarGraphWidget_SetValueAxisSubtickInterval(laBarGraphWidget* graph, laBarGraphValueAxis axis, uint32_t interval)
{
    if(graph == NULL)
        return LA_FAILURE;
        
    if(graph->subtickInterval == interval)
        return LA_SUCCESS;
        
    graph->subtickInterval = interval;
    
    laWidget_Invalidate((laWidget*)graph);
        
    return LA_SUCCESS;
}

laBool laBarGraphWidget_GetValueAxisSubticksVisible(laBarGraphWidget* graph, laBarGraphValueAxis axis)
{
    if(graph == NULL)
        return LA_FAILURE;
        
    return graph->valueAxisSubticksVisible;
}

laResult laBarGraphWidget_SetValueAxisSubticksVisible(laBarGraphWidget* graph, laBarGraphValueAxis axis, laBool visible)
{
    if(graph == NULL)
        return LA_FAILURE;
        
    if(graph->valueAxisSubticksVisible == visible)
        return LA_SUCCESS;
        
    graph->valueAxisSubticksVisible = visible;
    
    laWidget_Invalidate((laWidget*)graph);
        
    return LA_SUCCESS;
}

laBool laBarGraphWidget_GetCategoryAxisTicksVisible(laBarGraphWidget* graph)
{
    if(graph == NULL)
        return LA_FAILURE;
        
    return graph->categAxisTicksVisible;
}

laResult laBarGraphWidget_SetCategoryAxisTicksVisible(laBarGraphWidget* graph, laBool visible)
{
    if(graph == NULL)
        return LA_FAILURE;
        
    if(graph->categAxisTicksVisible == visible)
        return LA_SUCCESS;
        
    graph->categAxisTicksVisible = visible;
    
    laWidget_Invalidate((laWidget*)graph);
        
    return LA_SUCCESS;
}

laResult laBarGraphWidget_AddCategory(laBarGraphWidget* graph, uint32_t * id)
{
    laBarGraphCategory * category;
    
    if (graph == NULL)
        return LA_FAILURE;
    
    category = laContext_GetActive()->memIntf.heap.malloc(sizeof(laBarGraphCategory));
    if (category == NULL)
        return LA_FAILURE;
    
    laString_Initialize(&category->text);
    
    laArray_PushBack(&graph->categories, category);
    
    if (id != NULL)
    {
        *id = graph->categories.size;
    }
    
    laWidget_Invalidate((laWidget*)graph);
    
    return LA_SUCCESS;
}

laResult laBarGraphWidget_GetCategoryText(laBarGraphWidget* graph, uint32_t categoryID, laString * str)
{
    laBarGraphCategory * category;
    
    if(graph == NULL)
        return LA_FAILURE;
    
    if (categoryID >= graph->categories.size)
        return LA_FAILURE;
    
    category = laArray_Get(&graph->categories, categoryID);
    if (category == NULL)
        return LA_FAILURE;
    
    return laString_Copy(str, &category->text);
}

laResult laBarGraphWidget_SetCategoryText(laBarGraphWidget* graph, int32_t categoryID, laString str)
{
    laBarGraphCategory * category;
    
    if(graph == NULL)
        return LA_FAILURE;
    
    if (categoryID >= (int32_t) graph->categories.size)
        return LA_FAILURE;
    
    if (categoryID < 0)
        categoryID = graph->categories.size - 1;
    
    category = laArray_Get(&graph->categories, categoryID);
    if (category == NULL)
        return LA_FAILURE;
    
    if(laString_Copy(&category->text, &str) == LA_FAILURE)
        return LA_FAILURE;
    
    laWidget_Invalidate((laWidget*)graph);
    
    return LA_SUCCESS;
}

laResult laBarGraphWidget_AddSeries(laBarGraphWidget* graph, uint32_t * seriesID)
{
    laBarGraphDataSeries * series;
    
    if (graph == NULL)
        return LA_FAILURE;
    
    series = laContext_GetActive()->memIntf.heap.malloc(sizeof(laBarGraphDataSeries));
    if (series == NULL)
        return LA_FAILURE;

    laArray_Create(&series->data);
    series->axis = BAR_GRAPH_AXIS_0;
    series->scheme = graph->widget.scheme;
    
    laArray_PushBack(&graph->dataSeries, series);
    
    if (seriesID != NULL)
    {
        *seriesID = graph->dataSeries.size;
    }
    
    laWidget_Invalidate((laWidget*)graph);
    
    return LA_SUCCESS;
}

laResult laBarGraphWidget_AddDataToSeries(laBarGraphWidget* graph, uint32_t seriesID, int32_t value, uint32_t * index)
{
    laBarGraphDataSeries * series;
    int32_t * data;
    
    if (graph == NULL)
        return LA_FAILURE;
    
    if (seriesID >= graph->dataSeries.size)
        return LA_FAILURE;
    
    series = laArray_Get(&graph->dataSeries, seriesID);
    if (series == NULL)
        return LA_FAILURE;
    
    data = laContext_GetActive()->memIntf.heap.malloc(sizeof(data));
    if (data == NULL)
        return LA_FAILURE;
    
    *data = value;
    
    laArray_PushBack(&series->data, (void *) data);

    if (index != NULL)
    {
       *index = series->data.size - 1;
    }
    
    laWidget_Invalidate((laWidget*)graph);
    
    return LA_SUCCESS;
}

laResult laBarGraphWidget_SetDataInSeries(laBarGraphWidget* graph, 
                                          uint32_t seriesID,
                                          uint32_t index,
                                          int32_t value)
{
    laBarGraphDataSeries * series;
    int32_t * data;
    
    if (graph == NULL)
        return LA_FAILURE;
    
    if (seriesID >= graph->dataSeries.size)
        return LA_FAILURE;
    
    series = laArray_Get(&graph->dataSeries, seriesID);
    if (series == NULL)
        return LA_FAILURE;

    if (index >= series->data.size)
        return LA_FAILURE;

    data = laArray_Get(&series->data, index);
    if (data == NULL)
        return LA_FAILURE;
    
    *data = value;
    
    laWidget_Invalidate((laWidget*)graph);
    
    return LA_SUCCESS;
}

laScheme * laBarGraphWidget_GetSeriesScheme(laBarGraphWidget* graph, uint32_t seriesID)
{
    laBarGraphDataSeries * series;
    
    if(graph == NULL)
        return NULL;
    
    if (seriesID >= graph->dataSeries.size)
        return NULL;
    
    series = laArray_Get(&graph->dataSeries, seriesID);
    if (series == NULL)
        return NULL;
    
    return series->scheme;
}

laResult laBarGraphWidget_SetSeriesScheme(laBarGraphWidget* graph, int32_t seriesID, laScheme * scheme)
{
    laBarGraphDataSeries * series;
    
    if(graph == NULL || scheme == NULL)
        return LA_FAILURE;
    
    if (seriesID >= (int32_t) graph->dataSeries.size)
        return LA_FAILURE;
    
    if (seriesID < 0)
        seriesID = graph->dataSeries.size - 1;
    
    series = laArray_Get(&graph->dataSeries, seriesID);
    if (series == NULL)
        return LA_FAILURE;
    
    series->scheme = scheme;
    
    laWidget_Invalidate((laWidget*)graph);
        
    return LA_SUCCESS;
}

laResult laBarGraphWidget_DestroyAll(laBarGraphWidget* graph)
{
    laBarGraphCategory * category;
    laBarGraphDataSeries * series;
    uint32_t i;
    
    if (graph == NULL)
        return LA_FAILURE;
    
    // Free category string data
    for (i = 0; i < graph->categories.size; i++)
    {
        category = laArray_Get(&graph->categories, i);
        laString_Destroy(&category->text);
    }

    //Free the category array and contents
    laArray_Destroy(&graph->categories);
    
    // Free category string data
    for (i = 0; i < graph->dataSeries.size; i++)
    {
        series = laArray_Get(&graph->dataSeries, i);
        if (series != NULL)
        {
            //Destroy the data list and containers
            laArray_Destroy(&series->data);
             //Destroy the pointer list
            laArray_Destroy(&series->data);
        }
    }
    
    laArray_Destroy(&graph->dataSeries);
    
    laWidget_Invalidate((laWidget*)graph);
    
    return LA_SUCCESS;
}

laResult laBarGraphWidget_SetStringTable(laBarGraphWidget* graph, 
                                         GFXU_StringTableAsset * stringTable)
{
    if(graph == NULL)
        return LA_FAILURE;
        
    if(graph->stringTable == stringTable)
        return LA_SUCCESS;
        
    graph->stringTable = stringTable;
    
    laWidget_Invalidate((laWidget*) graph);
        
    return LA_SUCCESS;
}

laResult laBarGraphWidget_SetTicksLabelsStringID(laBarGraphWidget* graph, 
                                                 uint32_t stringID)
{
    if(graph == NULL)
        return LA_FAILURE;
        
    if(graph->ticksLabelsStringID == stringID)
        return LA_SUCCESS;
        
    graph->ticksLabelsStringID = stringID;
    
    laWidget_Invalidate((laWidget*) graph);
        
    return LA_SUCCESS;
}

laBool laBarGraphWidget_GetCategoryAxisLabelsVisible(laBarGraphWidget* graph)
{
    if(graph == NULL)
        return LA_FAILURE;
        
    return graph->categAxisLabelsVisible;
}

laResult laBarGraphWidget_SetCategoryAxisLabelsVisible(laBarGraphWidget* graph, laBool visible)
{
    if(graph == NULL)
        return LA_FAILURE;
        
    if(graph->categAxisLabelsVisible == visible)
        return LA_SUCCESS;
        
    graph->categAxisLabelsVisible = visible;
    
    laWidget_Invalidate((laWidget*)graph);
        
    return LA_SUCCESS;
}

laBarGraphTickPosition laBarGraphWidget_GetValueAxisTicksPosition(laBarGraphWidget* graph, laBarGraphValueAxis axis)
{
    if(graph == NULL)
        return LA_FAILURE;
        
    return graph->valueAxisTicksPosition;
}
laResult laBarGraphWidget_SetValueAxisTicksPosition(laBarGraphWidget* graph, laBarGraphValueAxis axis, laBarGraphTickPosition position)
{
    if(graph == NULL)
        return LA_FAILURE;
        
    if(graph->valueAxisTicksPosition == position)
        return LA_SUCCESS;
        
    graph->valueAxisTicksPosition = position;
    
    laWidget_Invalidate((laWidget*)graph);
        
    return LA_SUCCESS; 
}

laBarGraphTickPosition laBarGraphWidget_GetValueAxisSubticksPosition(laBarGraphWidget* graph, laBarGraphValueAxis axis)
{
    if(graph == NULL)
        return LA_FAILURE;
        
    return graph->valueAxisSubticksPosition;
}

laResult laBarGraphWidget_SetValueAxisSubticksPosition(laBarGraphWidget* graph, laBarGraphValueAxis axis, laBarGraphTickPosition position)
{
    if(graph == NULL)
        return LA_FAILURE;
        
    if(graph->valueAxisSubticksPosition == position)
        return LA_SUCCESS;
        
    graph->valueAxisSubticksPosition = position;
    
    laWidget_Invalidate((laWidget*)graph);
        
    return LA_SUCCESS;     
}

laBarGraphTickPosition laBarGraphWidget_GetCategoryAxisTicksPosition(laBarGraphWidget* graph)

{
    if(graph == NULL)
        return LA_FAILURE;
        
    return graph->categAxisTicksPosition;
}

laResult laBarGraphWidget_SetCategoryAxisTicksPosition(laBarGraphWidget* graph, laBarGraphTickPosition position)
{
    if(graph == NULL)
        return LA_FAILURE;
        
    if(graph->categAxisTicksPosition == position)
        return LA_SUCCESS;
        
    graph->categAxisTicksPosition = position;
    
    laWidget_Invalidate((laWidget*)graph);
        
    return LA_SUCCESS;      
}




#endif // LA_BAR_GRAPH_WIDGET_ENABLED