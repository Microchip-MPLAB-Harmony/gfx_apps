#include "gfx/libaria/inc/libaria_editwidget.h"
#include "gfx/libaria/inc/libaria_context.h"
#include "gfx/libaria/inc/libaria_string.h"

static laResult startEdit(laEditWidget* edit) { return LA_FAILURE; }
static void endEdit(laEditWidget* edit) { }

static void clear(laEditWidget* edit) { }
static void accept(laEditWidget* edit) { }
static void set(laEditWidget* edit, laString str) { }
static void append(laEditWidget* edit, laString str) { }
static void backspace(laEditWidget* edit) { }

void _laEditWidget_Constructor(laEditWidget* edit)
{
    _laWidget_Constructor((laWidget*)edit);
    
    edit->widget.editable = LA_TRUE;
    
    edit->startEdit = &startEdit;
    edit->endEdit = &endEdit;
    
    edit->clear = &clear;
    edit->accept = &accept;
    edit->append = &append;
    edit->set = &set;
    edit->backspace = &backspace;
}

void _laEditWidget_Destructor(laEditWidget* edit)
{
    if(edit == NULL)
        return;
        
    _laWidget_Destructor((laWidget*)edit);
}

laResult laEditWidget_StartEdit()
{
    laEditWidget* edit = laContext_GetEditWidget();
    
    if(edit == NULL)
        return LA_FAILURE;
        
    return edit->startEdit(edit);
}

void laEditWidget_EndEdit()
{ 
    laEditWidget* edit = laContext_GetEditWidget();
    
    if(edit == NULL)
        return;
        
    edit->endEdit(edit);
}

void laEditWidget_Clear()
{ 
    laEditWidget* edit = laContext_GetEditWidget();
    
    if(edit == NULL)
        return;
        
    edit->clear(edit);
}

void laEditWidget_Accept()
{
    laEditWidget* edit = laContext_GetEditWidget();
    
    if(edit == NULL)
        return;
        
    edit->accept(edit);
}

void laEditWidget_Set(laString str)
{
    laEditWidget* edit = laContext_GetEditWidget();
    
    if(edit == NULL)
        return;
        
    edit->set(edit, str);
}

void laEditWidget_Append(laString str)
{
    laEditWidget* edit = laContext_GetEditWidget();
    
    if(edit == NULL)
        return;
        
    edit->append(edit, str);
}

void laEditWidget_Backspace()
{
    laEditWidget* edit = laContext_GetEditWidget();
    
    if(edit == NULL)
        return;
        
    edit->backspace(edit);
}