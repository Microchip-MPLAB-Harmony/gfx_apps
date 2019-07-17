#ifndef LE_GEN_SCREEN_MAINMENU_H
#define LE_GEN_SCREEN_MAINMENU_H

#include "gfx/legato/generated/le_gen_init.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// widget list for this screen
// layer 0
extern leGradientWidget* GradientWidget1;
extern leButtonWidget* ListwheelDemoMenuButton;
extern leButtonWidget* AlphaBlendingDemoMenuButton;
extern leButtonWidget* SlideShowDemoMenuButton;
extern leButtonWidget* TouchTestDemoMenuDemo;
extern leButtonWidget* KeypadDemoMenuButton;
extern leButtonWidget* MainMenuHelpButton;
extern leLabelWidget* LabelWidget1;
extern leLabelWidget* LabelWidget2;
extern leImageWidget* ImageWidget3;
extern leImageWidget* ImageWidget4;
extern leButtonWidget* MainMenuSettingsButton;
extern leButtonWidget* MainMenuNextButton;


// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_MainMenu(); // called when Legato is initialized
leResult screenShow_MainMenu(); // called when screen is shown
void screenHide_MainMenu(); // called when screen is hidden
void screenDestroy_MainMenu(); // called when Legato is destroyed
void screenUpdate_MainMenu(); // called when Legato is updating

leWidget* screenGetRoot_MainMenu(uint32_t lyrIdx); // gets a root widget for this screen

// event handlers
void MainMenu_OnShow(void);
void MainMenu_OnUpdate(void);
void ListwheelDemoMenuButton_OnReleased(leButtonWidget* btn);
void AlphaBlendingDemoMenuButton_OnReleased(leButtonWidget* btn);
void SlideShowDemoMenuButton_OnReleased(leButtonWidget* btn);
void TouchTestDemoMenuDemo_OnReleased(leButtonWidget* btn);
void KeypadDemoMenuButton_OnReleased(leButtonWidget* btn);
void MainMenuHelpButton_OnReleased(leButtonWidget* btn);
void MainMenuSettingsButton_OnReleased(leButtonWidget* btn);
void MainMenuNextButton_OnReleased(leButtonWidget* btn);

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_MAINMENU_H
