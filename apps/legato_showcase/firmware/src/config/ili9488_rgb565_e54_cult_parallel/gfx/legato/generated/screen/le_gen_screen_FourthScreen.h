#ifndef LE_GEN_SCREEN_FOURTHSCREEN_H
#define LE_GEN_SCREEN_FOURTHSCREEN_H

#include "gfx/legato/generated/le_gen_init.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// widget list for this screen
// layer 0
extern leGradientWidget* GradientWidget5;
extern leWidget* PanelWidget1;
extern leSliderWidget* SliderWidget1;
extern leLabelWidget* SliderValueLabelWidget;
extern leWidget* PanelWidget2;
extern leImageWidget* ImageWidget1;
extern leImageWidget* ImageWidget2;
extern leButtonWidget* ButtonWidget4;
extern leButtonWidget* ButtonWidget8;
extern leLabelWidget* LabelWidget9;
extern leButtonWidget* ButtonWidget33;
extern leButtonWidget* SliderUpButtonWidget;
extern leButtonWidget* SliderDownButtonWidget;


// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_FourthScreen(); // called when Legato is initialized
leResult screenShow_FourthScreen(); // called when screen is shown
void screenHide_FourthScreen(); // called when screen is hidden
void screenDestroy_FourthScreen(); // called when Legato is destroyed
void screenUpdate_FourthScreen(); // called when Legato is updating

leWidget* screenGetRoot_FourthScreen(uint32_t lyrIdx); // gets a root widget for this screen

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_FOURTHSCREEN_H
