/*******************************************************************************
 Module for Microchip Graphics Library

  Company:
    Microchip Technology Inc.

  File Name:
    libaria.h

  Summary:
    The header file joins all header files used in the graphics object library.

  Description:
    This header file includes all the header files required to use the
    Harmony Graphics Object Library. 
*******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2017 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
*******************************************************************************/
// DOM-IGNORE-END

#ifndef LIBARIA_H
// DOM-IGNORE-BEGIN
#define LIBARIA_H
// DOM-IGNORE-END


////////////////////////////// INCLUDES //////////////////////////////
#include "gfx/libaria/inc/libaria_common.h"

#include "gfx/libaria/inc/libaria_context.h"
#include "gfx/libaria/inc/libaria_input.h"
#include "gfx/libaria/inc/libaria_layer.h"
#include "gfx/libaria/inc/libaria_scheme.h"
#include "gfx/libaria/inc/libaria_screen.h"

//#include "gfx/libaria/inc/libaria_context.h"

//#include "gfx/libaria/libaria_config.h"

#if LA_ARC_WIDGET_ENABLED
#include "gfx/libaria/inc/libaria_widget_arc.h"
#endif

#if LA_BAR_GRAPH_WIDGET_ENABLED
#include "gfx/libaria/inc/libaria_widget_bar_graph.h"
#endif

#if LA_BUTTON_WIDGET_ENABLED
#include "gfx/libaria/inc/libaria_widget_button.h"
#endif

#if LA_CHECKBOX_WIDGET_ENABLED
#include "gfx/libaria/inc/libaria_widget_checkbox.h"
#endif

#if LA_CIRCLE_WIDGET_ENABLED
#include "gfx/libaria/inc/libaria_widget_circle.h"
#endif

#if LA_CIRCULAR_GAUGE_WIDGET_ENABLED 
#include "gfx/libaria/inc/libaria_widget_circular_gauge.h"
#endif

#if LA_CIRCULAR_SLIDER_WIDGET_ENABLED 
#include "gfx/libaria/inc/libaria_widget_circular_slider.h"
#endif

#if LA_DRAWSURFACE_WIDGET_ENABLED
#include "gfx/libaria/inc/libaria_widget_drawsurface.h"
#endif

#if LA_GRADIENT_WIDGET_ENABLED
#include "gfx/libaria/inc/libaria_widget_gradient.h"
#endif

#if LA_GROUPBOX_WIDGET_ENABLED
#include "gfx/libaria/inc/libaria_widget_groupbox.h"
#endif

#if LA_IMAGE_WIDGET_ENABLED
#include "gfx/libaria/inc/libaria_widget_image.h"
#endif

#if LA_IMAGEPLUS_WIDGET_ENABLED
#include "gfx/libaria/inc/libaria_widget_imageplus.h"
#endif

#if LA_IMAGESEQUENCE_WIDGET_ENABLED
#include "gfx/libaria/inc/libaria_widget_imagesequence.h"
#endif

#if LA_KEYPAD_WIDGET_ENABLED
#include "gfx/libaria/inc/libaria_widget_keypad.h"
#endif

#if LA_LABEL_WIDGET_ENABLED
#include "gfx/libaria/inc/libaria_widget_label.h"
#endif

#if LA_LINE_WIDGET_ENABLED
#include "gfx/libaria/inc/libaria_widget_line.h"
#endif

#if LA_LINE_GRAPH_WIDGET_ENABLED
#include "gfx/libaria/inc/libaria_widget_line_graph.h"
#endif

#if LA_LIST_WIDGET_ENABLED
#include "gfx/libaria/inc/libaria_widget_list.h"
#endif

#if LA_LISTWHEEL_WIDGET_ENABLED
#include "gfx/libaria/inc/libaria_widget_listwheel.h"
#endif

#if LA_PIE_CHART_WIDGET_ENABLED
#include "gfx/libaria/inc/libaria_widget_pie_chart.h"
#endif

#if LA_PROGRESSBAR_WIDGET_ENABLED
#include "gfx/libaria/inc/libaria_widget_progressbar.h"
#endif

#if LA_RADIOBUTTON_WIDGET_ENABLED
#include "gfx/libaria/inc/libaria_widget_radiobutton.h"
#endif

#if LA_RADIAL_MENU_WIDGET_ENABLED
#include "gfx/libaria/inc/libaria_widget_radial_menu.h"
#endif

#if LA_RECTANGLE_WIDGET_ENABLED
#include "gfx/libaria/inc/libaria_widget_rectangle.h"
#endif

#if LA_SCROLLBAR_WIDGET_ENABLED
#include "gfx/libaria/inc/libaria_widget_scrollbar.h"
#endif

#if LA_SLIDER_WIDGET_ENABLED
#include "gfx/libaria/inc/libaria_widget_slider.h"
#endif

#if LA_TEXTFIELD_WIDGET_ENABLED
#include "gfx/libaria/inc/libaria_widget_textfield.h"
#endif

#if LA_TOUCHTEST_WIDGET_ENABLED
#include "gfx/libaria/inc/libaria_widget_touchtest.h"
#endif

#if LA_WINDOW_WIDGET_ENABLED
#include "gfx/libaria/inc/libaria_widget_window.h"
#endif

// *****************************************************************************
/* Type:
    laResult laInitialize()

  Summary:
    Function to perform basic initialization of the Aria library state.

  Description:
    Function to perform basic initialization of the Aria library state.  Must
    be called before any other library operations are performed.

  Remarks:
    
  Returns;
    laResult - the result of the initialization operation
*/
LIB_EXPORT laResult laInitialize();

// *****************************************************************************
/* Type:
    void laShutdown()

  Summary:
    Function to shutdown the active Aria library state.

  Description:
    Function to shutdown the active Aria library state.

  Remarks:
*/
LIB_EXPORT void laShutdown();

// *****************************************************************************
/* Type:
    void laUpdate()

  Summary:
    Aria library update (tasks) function.

  Description:
    This function updates the active Aria library context state.  It performs
    event processing as well as servicing of the widget paint loop.  It should
    be called often.

  Parameters:
    uint32_t dt - a delta time, typically expressed in milliseconds, since the
                  last time laUpdate was called.  If this value is zero then
                  time-dependent features will not advance.
*/
LIB_EXPORT void laUpdate(uint32_t dt);
    
#endif // LIBARIA_H
