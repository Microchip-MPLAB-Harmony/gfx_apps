#ifndef LE_GEN_SCREEN_TOUCHTESTDEMOSCREEN_H
#define LE_GEN_SCREEN_TOUCHTESTDEMOSCREEN_H

#include "gfx/legato/legato.h"

#include "gfx/legato/generated/le_gen_scheme.h"
#include "gfx/legato/generated/le_gen_assets.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// screen member widget declarations
extern leGradientWidget* TouchTestDemoScreen_GradientWidget2;
extern leTouchTestWidget* TouchTestDemoScreen_TouchTestWidget1;
extern leLabelWidget* TouchTestDemoScreen_LabelWidget6;
extern leImageWidget* TouchTestDemoScreen_ImageWidget5;
extern leButtonWidget* TouchTestDemoScreen_TouchTestHelpButton;
extern leButtonWidget* TouchTestDemoScreen_TouchTestHomeButton;
extern leLabelWidget* TouchTestDemoScreen_LabelWidget7;
extern leButtonWidget* TouchTestDemoScreen_TouchTestNextButton;

// event handlers
// !!THESE MUST BE IMPLEMENTED IN THE APPLICATION CODE!!
void event_TouchTestDemoScreen_TouchTestHelpButton_OnReleased(leButtonWidget* btn);
void event_TouchTestDemoScreen_TouchTestHomeButton_OnReleased(leButtonWidget* btn);
void event_TouchTestDemoScreen_TouchTestNextButton_OnReleased(leButtonWidget* btn);

// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_TouchTestDemoScreen(); // called when Legato is initialized
leResult screenShow_TouchTestDemoScreen(); // called when screen is shown
void screenHide_TouchTestDemoScreen(); // called when screen is hidden
void screenDestroy_TouchTestDemoScreen(); // called when Legato is destroyed
void screenUpdate_TouchTestDemoScreen(); // called when Legato is updating

leWidget* screenGetRoot_TouchTestDemoScreen(uint32_t lyrIdx); // gets a root widget for this screen

// Screen Events:
void TouchTestDemoScreen_OnShow(); // called when this screen is shown
void TouchTestDemoScreen_OnUpdate(); // called when this screen is updated

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_TOUCHTESTDEMOSCREEN_H
