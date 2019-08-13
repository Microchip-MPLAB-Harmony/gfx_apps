#ifndef LEGATO_INIT_H
#define LEGATO_INIT_H

#include "gfx/legato/legato.h"

#include "gfx/legato/generated/le_gen_scheme.h"
#include "gfx/legato/generated/le_gen_assets.h"

#include "gfx/legato/generated/screen/le_gen_screen_SplashScreen.h"
#include "gfx/legato/generated/screen/le_gen_screen_FPSCounters.h"
#include "gfx/legato/generated/screen/le_gen_screen_FPSMotion.h"
#include "gfx/legato/generated/screen/le_gen_screen_FPSImages.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// screen IDs
#define screenID_SplashScreen    0
#define screenID_FPSCounters    1
#define screenID_FPSMotion    2
#define screenID_FPSImages    3

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
