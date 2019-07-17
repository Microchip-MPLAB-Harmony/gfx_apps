#ifndef LE_GEN_SCREEN_FIRSTSCREEN_H
#define LE_GEN_SCREEN_FIRSTSCREEN_H

#include "gfx/legato/generated/le_gen_init.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// widget list for this screen
// layer 0
extern leGradientWidget* GradientWidget3;
extern leButtonWidget* ButtonWidget1;
extern leButtonWidget* ButtonWidget7;
extern leRectangleWidget* RectangleWidget2;
extern leLabelWidget* LabelWidget3;
extern leListWheelWidget* ListWheel2;
extern leListWheelWidget* ListWheel4;
extern leListWheelWidget* ListWheel5;
extern leListWheelWidget* ListWheel1;
extern leLabelWidget* LabelWidget4;
extern leLabelWidget* LabelWidget5;
extern leButtonWidget* ButtonWidget30;


// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_FirstScreen(); // called when Legato is initialized
leResult screenShow_FirstScreen(); // called when screen is shown
void screenHide_FirstScreen(); // called when screen is hidden
void screenDestroy_FirstScreen(); // called when Legato is destroyed
void screenUpdate_FirstScreen(); // called when Legato is updating

leWidget* screenGetRoot_FirstScreen(uint32_t lyrIdx); // gets a root widget for this screen

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_FIRSTSCREEN_H
