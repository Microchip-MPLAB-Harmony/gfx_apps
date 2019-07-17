#ifndef LE_GEN_SCREEN_ALPHABLENDINGDEMOSCREEN_H
#define LE_GEN_SCREEN_ALPHABLENDINGDEMOSCREEN_H

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
extern leButtonWidget* AlphaHelpButton;
extern leButtonWidget* AlphaHomeButton;
extern leLabelWidget* LabelWidget9;
extern leButtonWidget* AlphaNextButton;
extern leButtonWidget* SliderUpButtonWidget;
extern leButtonWidget* SliderDownButtonWidget;


// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_AlphaBlendingDemoScreen(); // called when Legato is initialized
leResult screenShow_AlphaBlendingDemoScreen(); // called when screen is shown
void screenHide_AlphaBlendingDemoScreen(); // called when screen is hidden
void screenDestroy_AlphaBlendingDemoScreen(); // called when Legato is destroyed
void screenUpdate_AlphaBlendingDemoScreen(); // called when Legato is updating

leWidget* screenGetRoot_AlphaBlendingDemoScreen(uint32_t lyrIdx); // gets a root widget for this screen

// event handlers
void AlphaBlendingDemoScreen_OnShow(void);
void AlphaBlendingDemoScreen_OnHide(void);
void AlphaBlendingDemoScreen_OnUpdate(void);
void SliderWidget1_OnValueChanged(leSliderWidget* sld);
void AlphaHelpButton_OnReleased(leButtonWidget* btn);
void AlphaHomeButton_OnReleased(leButtonWidget* btn);
void AlphaNextButton_OnReleased(leButtonWidget* btn);
void SliderUpButtonWidget_OnReleased(leButtonWidget* btn);
void SliderDownButtonWidget_OnReleased(leButtonWidget* btn);

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_ALPHABLENDINGDEMOSCREEN_H
