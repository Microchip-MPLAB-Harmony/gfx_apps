#include "system/input/sys_input_listener.h"

static void defaultKeyDownHandler(const const SYS_INP_KeyEvent* evt) { }
static void defaultKeyUpHandler(const SYS_INP_KeyEvent* const evt) { }

static void defaultMouseMoveHandler(const SYS_INP_MouseMoveEvent* const evt) { }
static void defaultMouseButtonHandler(const SYS_INP_MouseButtonEvent* const evt) { }

static void defaultTouchStateHandler(const SYS_INP_TouchStateEvent* const evt) { }
static void defaultTouchMoveHandler(const SYS_INP_TouchMoveEvent* const evt) { }

static void defaultFlickGestureHandler(const SYS_INP_FlickGestureEvent* const evt) { }
static void defaultPinchEventHandler(const SYS_INP_PinchGestureEvent* const evt) { }
static void defaultStretchEventHandler(const SYS_INP_StretchGestureEvent* const evt) { }
static void defaultRotateEventHandler(const SYS_INP_RotateGestureEvent* const evt) { }

// initialize an input listener structure
void SYS_INP_ListenerInit(SYS_INP_InputListener* l)
{
    if(l == NULL)
        return;
    
    l->handleKeyDown = &defaultKeyDownHandler;
    l->handleKeyUp = &defaultKeyUpHandler;
    
    l->handleMouseMove = &defaultMouseMoveHandler;
    l->handleMouseButtonDown = &defaultMouseButtonHandler;
    l->handleMouseButtonUp = &defaultMouseButtonHandler;
    
    l->handleTouchDown = &defaultTouchStateHandler;
    l->handleTouchUp = &defaultTouchStateHandler;
    l->handleTouchMove = &defaultTouchMoveHandler;
    
    l->handleFlickGesture = &defaultFlickGestureHandler;
    l->handlePinchGesture = &defaultPinchEventHandler;
    l->handleStretchGesture = &defaultStretchEventHandler;
    l->handleRotateGesture = &defaultRotateEventHandler;
}