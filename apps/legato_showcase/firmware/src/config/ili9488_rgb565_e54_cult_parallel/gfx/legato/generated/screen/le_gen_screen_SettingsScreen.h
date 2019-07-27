#ifndef LE_GEN_SCREEN_SETTINGSSCREEN_H
#define LE_GEN_SCREEN_SETTINGSSCREEN_H

#include "gfx/legato/generated/le_gen_init.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// widget list for this screen
// layer 0
extern leGradientWidget* GradientWidget7;
extern leButtonWidget* SettingsHomeButton;
extern leWidget* PanelWidget3;
extern leLabelWidget* LabelWidget11;
extern leRadioButtonWidget* RadioButtonChinese;
extern leRadioButtonWidget* RadioButtonEnglish;
extern leButtonWidget* ButtonWidgetChinese;
extern leButtonWidget* ButtonWidgetEnglish;


// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_SettingsScreen(); // called when Legato is initialized
leResult screenShow_SettingsScreen(); // called when screen is shown
void screenHide_SettingsScreen(); // called when screen is hidden
void screenDestroy_SettingsScreen(); // called when Legato is destroyed
void screenUpdate_SettingsScreen(); // called when Legato is updating

leWidget* screenGetRoot_SettingsScreen(uint32_t lyrIdx); // gets a root widget for this screen

// event handlers
void SettingsScreen_OnShow(void);

void SettingsScreen_OnUpdate(void);

void SettingsHomeButton_OnReleased(leButtonWidget* btn)
;

void ButtonWidgetChinese_OnReleased(leButtonWidget* btn)
;

void ButtonWidgetEnglish_OnReleased(leButtonWidget* btn)
;


//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_SETTINGSSCREEN_H
