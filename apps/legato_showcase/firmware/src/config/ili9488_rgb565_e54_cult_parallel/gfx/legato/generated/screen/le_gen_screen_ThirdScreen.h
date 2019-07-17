#ifndef LE_GEN_SCREEN_THIRDSCREEN_H
#define LE_GEN_SCREEN_THIRDSCREEN_H

#include "gfx/legato/generated/le_gen_init.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// widget list for this screen
// layer 0
extern leGradientWidget* GradientWidget4;
extern leKeyPadWidget* KeyPadWidget1;
extern leTextFieldWidget* TextFieldWidget1;
extern leButtonWidget* ButtonWidget5;
extern leButtonWidget* ButtonWidget6;
extern leLabelWidget* LabelWidget8;
extern leButtonWidget* ButtonWidget32;


// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_ThirdScreen(); // called when Legato is initialized
leResult screenShow_ThirdScreen(); // called when screen is shown
void screenHide_ThirdScreen(); // called when screen is hidden
void screenDestroy_ThirdScreen(); // called when Legato is destroyed
void screenUpdate_ThirdScreen(); // called when Legato is updating

leWidget* screenGetRoot_ThirdScreen(uint32_t lyrIdx); // gets a root widget for this screen

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_THIRDSCREEN_H
