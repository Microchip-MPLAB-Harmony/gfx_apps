#ifndef LE_GEN_SCREEN_SETTINGSSCREEN_H
#define LE_GEN_SCREEN_SETTINGSSCREEN_H

#include "gfx/legato/legato.h"

#include "gfx/legato/generated/le_gen_scheme.h"
#include "gfx/legato/generated/le_gen_assets.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// screen member widget declarations
extern leGradientWidget* SettingsScreen_GradientWidget7;
extern leButtonWidget* SettingsScreen_SettingsHomeButton;
extern leWidget* SettingsScreen_PanelWidget3;
extern leButtonWidget* SettingsScreen_ButtonWidgetEnglish;
extern leButtonWidget* SettingsScreen_ButtonWidgetChinese;
extern leRadioButtonWidget* SettingsScreen_RadioButtonEnglish;
extern leRadioButtonWidget* SettingsScreen_RadioButtonChinese;
extern leLabelWidget* SettingsScreen_LabelWidget11;

// event handlers
// !!THESE MUST BE IMPLEMENTED IN THE APPLICATION CODE!!
void event_SettingsScreen_SettingsHomeButton_OnReleased(leButtonWidget* btn);
void event_SettingsScreen_ButtonWidgetEnglish_OnReleased(leButtonWidget* btn);
void event_SettingsScreen_ButtonWidgetChinese_OnReleased(leButtonWidget* btn);

// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_SettingsScreen(); // called when Legato is initialized
leResult screenShow_SettingsScreen(); // called when screen is shown
void screenHide_SettingsScreen(); // called when screen is hidden
void screenDestroy_SettingsScreen(); // called when Legato is destroyed
void screenUpdate_SettingsScreen(); // called when Legato is updating

leWidget* screenGetRoot_SettingsScreen(uint32_t lyrIdx); // gets a root widget for this screen

// Screen Events:
void SettingsScreen_OnShow(); // called when this screen is shown
void SettingsScreen_OnUpdate(); // called when this screen is updated

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_SETTINGSSCREEN_H
