#ifndef LE_GEN_SCREEN_MAINMENU_H
#define LE_GEN_SCREEN_MAINMENU_H

#include "gfx/legato/legato.h"

#include "gfx/legato/generated/le_gen_scheme.h"
#include "gfx/legato/generated/le_gen_assets.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// screen member widget declarations
extern leGradientWidget* MainMenu_GradientWidget1;
extern leButtonWidget* MainMenu_ListwheelDemoMenuButton;
extern leButtonWidget* MainMenu_AlphaBlendingDemoMenuButton;
extern leButtonWidget* MainMenu_SlideShowDemoMenuButton;
extern leButtonWidget* MainMenu_TouchTestDemoMenuDemo;
extern leButtonWidget* MainMenu_KeypadDemoMenuButton;
extern leButtonWidget* MainMenu_MainMenuHelpButton;
extern leLabelWidget* MainMenu_LabelWidget1;
extern leLabelWidget* MainMenu_LabelWidget2;
extern leImageWidget* MainMenu_ImageWidget3;
extern leImageWidget* MainMenu_ImageWidget4;
extern leButtonWidget* MainMenu_MainMenuSettingsButton;
extern leButtonWidget* MainMenu_MainMenuNextButton;

// event handlers
// !!THESE MUST BE IMPLEMENTED IN THE APPLICATION CODE!!
void event_MainMenu_ListwheelDemoMenuButton_OnReleased(leButtonWidget* btn);
void event_MainMenu_AlphaBlendingDemoMenuButton_OnReleased(leButtonWidget* btn);
void event_MainMenu_SlideShowDemoMenuButton_OnReleased(leButtonWidget* btn);
void event_MainMenu_TouchTestDemoMenuDemo_OnReleased(leButtonWidget* btn);
void event_MainMenu_KeypadDemoMenuButton_OnReleased(leButtonWidget* btn);
void event_MainMenu_MainMenuHelpButton_OnReleased(leButtonWidget* btn);
void event_MainMenu_MainMenuSettingsButton_OnReleased(leButtonWidget* btn);
void event_MainMenu_MainMenuNextButton_OnReleased(leButtonWidget* btn);

// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_MainMenu(); // called when Legato is initialized
leResult screenShow_MainMenu(); // called when screen is shown
void screenHide_MainMenu(); // called when screen is hidden
void screenDestroy_MainMenu(); // called when Legato is destroyed
void screenUpdate_MainMenu(); // called when Legato is updating

leWidget* screenGetRoot_MainMenu(uint32_t lyrIdx); // gets a root widget for this screen

// Screen Events:
void MainMenu_OnShow(); // called when this screen is shown
void MainMenu_OnUpdate(); // called when this screen is updated

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_MAINMENU_H
