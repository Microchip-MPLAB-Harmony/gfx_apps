#ifndef LE_GEN_SCREEN_MAINMENUHELP_H
#define LE_GEN_SCREEN_MAINMENUHELP_H

#include "gfx/legato/generated/le_gen_init.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// widget list for this screen
// layer 0
extern leWidget* PanelWidget0;
extern leButtonWidget* MainMenuHelpCloseButton;
extern leImageWidget* ImageWidget6;
extern leLabelWidget* LabelWidget12;
extern leLabelWidget* LabelWidget13;
extern leLabelWidget* LabelWidget14;
extern leLabelWidget* LabelWidget15;
extern leLabelWidget* LabelWidget16;
extern leLabelWidget* LabelWidget17;
extern leLabelWidget* LabelWidget18;
extern leLabelWidget* LabelWidget19;
extern leLabelWidget* LabelWidget20;
extern leImageWidget* ImageWidget7;
extern leImageWidget* ImageWidget8;
extern leImageWidget* ImageWidget9;
extern leImageWidget* ImageWidget10;
extern leImageWidget* ImageWidget11;
extern leImageWidget* ImageWidget12;
extern leImageWidget* ImageWidget13;


// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_MainMenuHelp(); // called when Legato is initialized
leResult screenShow_MainMenuHelp(); // called when screen is shown
void screenHide_MainMenuHelp(); // called when screen is hidden
void screenDestroy_MainMenuHelp(); // called when Legato is destroyed
void screenUpdate_MainMenuHelp(); // called when Legato is updating

leWidget* screenGetRoot_MainMenuHelp(uint32_t lyrIdx); // gets a root widget for this screen

// event handlers
void MainMenuHelp_OnShow(void);
void MainMenuHelp_OnUpdate(void);
void MainMenuHelpCloseButton_OnReleased(leButtonWidget* btn);

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_MAINMENUHELP_H
