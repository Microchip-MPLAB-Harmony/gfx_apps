#ifndef LE_GEN_SCREEN_SECONDSCREEN_H
#define LE_GEN_SCREEN_SECONDSCREEN_H

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
extern leButtonWidget* ButtonWidget2;
extern leButtonWidget* ButtonWidget3;
extern leLabelWidget* LabelWidget7;
extern leButtonWidget* ButtonWidget31;


// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_SecondScreen(); // called when Legato is initialized
leResult screenShow_SecondScreen(); // called when screen is shown
void screenHide_SecondScreen(); // called when screen is hidden
void screenDestroy_SecondScreen(); // called when Legato is destroyed
void screenUpdate_SecondScreen(); // called when Legato is updating

leWidget* screenGetRoot_SecondScreen(uint32_t lyrIdx); // gets a root widget for this screen

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_SECONDSCREEN_H
