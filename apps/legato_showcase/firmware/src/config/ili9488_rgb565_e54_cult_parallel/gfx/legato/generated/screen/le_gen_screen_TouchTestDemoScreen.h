#ifndef LE_GEN_SCREEN_TOUCHTESTDEMOSCREEN_H
#define LE_GEN_SCREEN_TOUCHTESTDEMOSCREEN_H

#include "gfx/legato/generated/le_gen_init.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// widget list for this screen
// layer 0
extern leGradientWidget* GradientWidget2;
extern leTouchTestWidget* TouchTestWidget1;
extern leLabelWidget* LabelWidget6;
extern leImageWidget* ImageWidget5;
extern leButtonWidget* TouchTestHelpButton;
extern leButtonWidget* TouchTestHomeButton;
extern leLabelWidget* LabelWidget7;
extern leButtonWidget* TouchTestNextButton;


// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_TouchTestDemoScreen(); // called when Legato is initialized
leResult screenShow_TouchTestDemoScreen(); // called when screen is shown
void screenHide_TouchTestDemoScreen(); // called when screen is hidden
void screenDestroy_TouchTestDemoScreen(); // called when Legato is destroyed
void screenUpdate_TouchTestDemoScreen(); // called when Legato is updating

leWidget* screenGetRoot_TouchTestDemoScreen(uint32_t lyrIdx); // gets a root widget for this screen

// event handlers
void TouchTestDemoScreen_OnShow(void);

void TouchTestDemoScreen_OnUpdate(void);

void TouchTestHelpButton_OnReleased(leButtonWidget* btn)
;

void TouchTestHomeButton_OnReleased(leButtonWidget* btn)
;

void TouchTestNextButton_OnReleased(leButtonWidget* btn)
;


//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_TOUCHTESTDEMOSCREEN_H
