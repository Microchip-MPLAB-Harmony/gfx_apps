#ifndef LEGATO_STATE_H
#define LEGATO_STATE_H

// DOM-IGNORE-BEGIN

#include "gfx/legato/common/legato_common.h"

#include "gfx/legato/renderer/legato_driver.h"
#include "gfx/legato/core/legato_input.h"
#include "gfx/legato/core/legato_scheme.h"
#include "gfx/legato/string/legato_stringtable.h"
#include "gfx/legato/widget/legato_editwidget.h" 

// *****************************************************************************
/* Type:
    leLanguageChangedCallback_FnPtr

  Summary:
    Callback pointer for when the language change event occurs.

  Description:
    Callback pointer for when the language change event occurs.

  Remarks:

*/
typedef void (*leLanguageChangedCallback_FnPtr)(uint32_t);

typedef struct leState
{
    const leStringTable* stringTable; // the string table for the instance
    uint32_t languageID; // the currently active language
    
    uint32_t widgetIDs; // the next unique widget ID
    
    leScheme defaultScheme; // an internal default scheme that widgets use by
                            // default if the user doesn't set one
                            
    leWidget* focus; // the widget that currently has focus
    leEditWidget* edit; // the widget that is currently receiving edit events
    
    leLanguageChangedCallback_FnPtr languageChangedCB; // language changed callback

    leWidget rootWidget[LE_LAYER_COUNT];

    //leScreen screens[LE_MAX_SCREENS];
    //int32_t activeScreen;
    
#if LE_STREAMING_ENABLED == 1
    leStreamManager* activeStream; // active stream state
#endif
} leState;

/* internal use only */
LIB_EXPORT leState* leGetState();
// DOM-IGNORE-END

// *****************************************************************************
/* Type:
    leResult leInitialize()

  Summary:
    Function to perform basic initialization of the Legato library state.

  Description:
    Function to perform basic initialization of the Legato library state.  Must
    be called before any other library operations are performed.

  Remarks:
    
  Returns;
    leResult - the result of the initialization operation
*/
LIB_EXPORT leResult leInitialize(const leDisplayDriver* dispDriver);

// *****************************************************************************
/* Type:
    void leShutdown()

  Summary:
    Function to shutdown the active Legato library state.

  Description:
    Function to shutdown the active Legato library state.

  Remarks:
*/
LIB_EXPORT void leShutdown();

// *****************************************************************************
/* Type:
    void leUpdate(uint32_t dt)

  Summary:
    Legato library update (tasks) function.

  Description:
    This function updates the active Legato library context state.  It performs
    event processing as well as servicing of the widget paint loop.  It should
    be called often.

  Parameters:
    uint32_t dt - a delta time, typically expressed in milliseconds, since the
                  last time leUpdate was called.  If this value is zero then
                  time-dependent features will not advance.
*/
LIB_EXPORT leResult leUpdate(uint32_t dt);

// *****************************************************************************
/* Function:
    leColorMode leGetColorMode()
    
   Summary:
    Returns the color mode of the current context

   Returns:
    leColorMode
*/
LIB_EXPORT leColorMode leGetColorMode();
    
// *****************************************************************************
/* Function:
    LIB_EXPORT leRect leGetDisplayRect()

   Summary:
    Returns the display rectangle structure of the physical display

   Description:
    Returns the display rectangle - width height and upper left corner coordinates
    of the physical display

   Precondition:

   Parameters:
    
  Returns:
    leRect

  Remarks:    
    
*/
LIB_EXPORT leRect leGetDisplayRect();
    
// *****************************************************************************
/* Function:
    leStringTable* leGetStringTable()

   Summary:
    Get a pointer to the leStringTable structure that maintains the strings,
    associated fonts, etc

   Description:
    Get a pointer to the leStringTable structure that maintains the strings,
    associated fonts, etc

   Precondition:

   Parameters:
    
  Returns:
    leStringTable*

  Remarks:    
    
*/
LIB_EXPORT leStringTable* leGetStringTable();

// *****************************************************************************
/* Function:
    void leSetStringTable(leStringTable* table)

   Summary:
    Set the StringTable pointer to the specified new StringTableAsset structure  

   Description:
    Set the StringTable pointer to the specified new StringTableAsset structure 

   Precondition:

   Parameters:
    leStringTable*

  Returns:
    void

  Remarks:    
    
*/
LIB_EXPORT void leSetStringTable(const leStringTable* table);

// *****************************************************************************
/* Function:
    uint32_t leGetStringLanguage()

   Summary:
    Returns the language index of the current context  

   Description:
    Returns the language index of the current context

   Precondition:

   Parameters:
    
  Returns:
    uint32_t

  Remarks:    
    
*/
LIB_EXPORT uint32_t leGetStringLanguage();

// *****************************************************************************
/* Function:
    void leSetStringLanguage(uint32_t id)

   Summary:
    Sets the current language index 

   Description:
    Sets the current language index

   Precondition:

   Parameters:
    uint32_t

  Returns:
    void

  Remarks:    
    
*/
LIB_EXPORT void leSetStringLanguage(uint32_t id);

// *****************************************************************************
/* Function:
    leScheme* leGetDefaultScheme()

   Summary:
    Returns the pointer to the current default scheme  

   Description:
    Returns the pointer to the current default scheme

   Precondition:

   Parameters:
    
  Returns:
    leScheme*

  Remarks:    
    
*/
LIB_EXPORT leScheme* leGetDefaultScheme();

// *****************************************************************************
/* Function:
    leWidget* leGetFocusWidget()

   Summary:
    Return a pointer to the widget in focus 

   Description:
    The focus widget is the widget that is currently receiving all input events.
    This can happen when the user initiates a touch down event on the widget
    and is currently dragging their finger on the display.  The widget will
    receive all touch moved events until a touch up event is received.

   Precondition:

   Parameters:
    
  Returns:
    leWidget*

  Remarks:    
    
*/
LIB_EXPORT leWidget* leGetFocusWidget();

// *****************************************************************************
/* Function:
    leResult leSetFocusWidget(leWidget* widget)

   Summary:
    Set into focus the widget specified as the argument 

   Description:
    Set into focus the widget specified as the argument

   Precondition:

   Parameters:
    leWidget*

  Returns:
    leResult

  Remarks:    
    
*/
LIB_EXPORT leResult leSetFocusWidget(leWidget* widget);

// *****************************************************************************
/* Function:
    leEditWidget* leGetEditWidget()

   Summary:
    Gets the widget that is currently recieving all widget edit events.

   Description:
    Edit widgets are widgets that inherit the 'edit widget' API function list.
    These widgets are capable of receiving edit events from other widgets
    that are edit event broadcasters.  A broadcaster could be a 'key pad' and
    a receiver could be a 'text edit' box.

   Precondition:

   Parameters:
    void

  Returns:
    leEditWidget*

  Remarks:    
    
*/
LIB_EXPORT leEditWidget* leGetEditWidget();

// *****************************************************************************
/* Function:
    leResult leSetEditWidget(leEditWidget* widget)

   Summary:
    Sets the currently active edit widget.  

   Precondition:

   Parameters:
    leEditWidget* - a widget that inherits the edit widget API and has its
                   'editable' flag set to true.

  Returns:
    leResult

  Remarks:    
    
*/
LIB_EXPORT leResult leSetEditWidget(leEditWidget* widget);
    
// *****************************************************************************
/* Function:
    leResult leSetLanguageChangedCallback(leLanguageChangedCallback_FnPtr cb)

   Summary:
    Set the callback function pointer when the language change event occurs  

   Description:
    Set the callback function pointer when the language change event occurs

   Precondition:

   Parameters:
    leLanguageChangedCallback_FnPtr

  Returns:
    leResult

  Remarks:    
    
*/
LIB_EXPORT leResult leSetLanguageChangedCallback(leLanguageChangedCallback_FnPtr cb);
 
// *****************************************************************************
/* Function:
    void leRedrawAll()

   Summary:
    Forces the library to redraw the currently active scene in its entirety.  

   Precondition:

   Parameters:
    
  Returns:
    void

  Remarks:    
    
*/
LIB_EXPORT void leRedrawAll();

/*  Function:
        leBool leIsDrawing()
 
    Summary:
        Indicates if any layers of the active screen are currently drawing a
        frame.
        
    Description:
        Indicates if the library currently drawing a frame.  Because frame updates
        can asynchronous to making changes to the UI state it is best to only make 
        updates to the state of a widget only when the layer is not drawing.
        
    Returns:
        leResult    

*/



LIB_EXPORT leBool leIsDrawing();

LIB_EXPORT leResult leAddRootWidget(leWidget* wgt,
                                    uint32_t layer);

LIB_EXPORT leResult leRemoveRootWidget(leWidget* wgt,
                                       uint32_t layer);

LIB_EXPORT leBool leWidgetIsInScene(const leWidget* wgt);


leResult leEdit_StartEdit();
void leEdit_EndEdit();
void leEdit_Clear();
void leEdit_Accept();
void leEdit_Set(leString* str);
void leEdit_Append(leString* str);
void leEdit_Backspace();

#if LE_STREAMING_ENABLED == 1
leStreamManager* leGetActiveStream();
leResult leRunActiveStream();
void leAbortActiveStream();
#endif

#endif /* LEGATO_STATE_H */