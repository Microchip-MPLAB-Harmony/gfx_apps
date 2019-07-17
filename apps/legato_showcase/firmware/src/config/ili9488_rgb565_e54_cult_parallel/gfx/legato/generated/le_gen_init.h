#ifndef LEGATO_INIT_H
#define LEGATO_INIT_H

#include "gfx/legato/legato.h"

#include "gfx/legato/generated/le_gen_scheme.h"
#include "gfx/legato/generated/le_gen_assets.h"

#include "gfx/legato/generated/screen/le_gen_screen_SplashScreen.h"
#include "gfx/legato/generated/screen/le_gen_screen_MainMenu.h"
#include "gfx/legato/generated/screen/le_gen_screen_ListWheelDemoScreen.h"
#include "gfx/legato/generated/screen/le_gen_screen_TouchTestDemoScreen.h"
#include "gfx/legato/generated/screen/le_gen_screen_KeypadDemoScreen.h"
#include "gfx/legato/generated/screen/le_gen_screen_AlphaBlendingDemoScreen.h"
#include "gfx/legato/generated/screen/le_gen_screen_SlideShowDemoScreen.h"
#include "gfx/legato/generated/screen/le_gen_screen_SettingsScreen.h"
#include "gfx/legato/generated/screen/le_gen_screen_MainMenuHelp.h"
#include "gfx/legato/generated/screen/le_gen_screen_ListWheelHelpScreen.h"
#include "gfx/legato/generated/screen/le_gen_screen_TouchTestHelpScreen.h"
#include "gfx/legato/generated/screen/le_gen_screen_KeypadHelpScreen.h"
#include "gfx/legato/generated/screen/le_gen_screen_AlphaBlendingHelpScreen.h"
#include "gfx/legato/generated/screen/le_gen_screen_SlideshowHelpScreen.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// screen IDs
#define screenID_SplashScreen    0
#define screenID_MainMenu    1
#define screenID_ListWheelDemoScreen    2
#define screenID_TouchTestDemoScreen    3
#define screenID_KeypadDemoScreen    4
#define screenID_AlphaBlendingDemoScreen    5
#define screenID_SlideShowDemoScreen    6
#define screenID_SettingsScreen    7
#define screenID_MainMenuHelp    8
#define screenID_ListWheelHelpScreen    9
#define screenID_TouchTestHelpScreen    10
#define screenID_KeypadHelpScreen    11
#define screenID_AlphaBlendingHelpScreen    12
#define screenID_SlideshowHelpScreen    13

void legato_initialize(void);

// global screen control functions
uint32_t legato_getCurrentScreen(void);
void legato_showScreen(uint32_t id);
void legato_hideCurrentScreen();
void legato_updateCurrentScreen();

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LEGATO_INIT_H
