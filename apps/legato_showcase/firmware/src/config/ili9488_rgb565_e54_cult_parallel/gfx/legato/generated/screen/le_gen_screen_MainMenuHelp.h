#ifndef LE_GEN_SCREEN_MAINMENUHELP_H
#define LE_GEN_SCREEN_MAINMENUHELP_H

#include "gfx/legato/legato.h"

#include "gfx/legato/generated/le_gen_scheme.h"
#include "gfx/legato/generated/le_gen_assets.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// screen member widget declarations
extern leWidget* MainMenuHelp_PanelWidget0;
extern leButtonWidget* MainMenuHelp_MainMenuHelpCloseButton;
extern leImageWidget* MainMenuHelp_ImageWidget6;
extern leLabelWidget* MainMenuHelp_LabelWidget12;
extern leLabelWidget* MainMenuHelp_LabelWidget13;
extern leLabelWidget* MainMenuHelp_LabelWidget14;
extern leLabelWidget* MainMenuHelp_LabelWidget15;
extern leLabelWidget* MainMenuHelp_LabelWidget16;
extern leLabelWidget* MainMenuHelp_LabelWidget17;
extern leLabelWidget* MainMenuHelp_LabelWidget18;
extern leLabelWidget* MainMenuHelp_LabelWidget19;
extern leLabelWidget* MainMenuHelp_LabelWidget20;
extern leImageWidget* MainMenuHelp_ImageWidget7;
extern leImageWidget* MainMenuHelp_ImageWidget8;
extern leImageWidget* MainMenuHelp_ImageWidget9;
extern leImageWidget* MainMenuHelp_ImageWidget10;
extern leImageWidget* MainMenuHelp_ImageWidget11;
extern leImageWidget* MainMenuHelp_ImageWidget12;
extern leImageWidget* MainMenuHelp_ImageWidget13;

// event handlers
// !!THESE MUST BE IMPLEMENTED IN THE APPLICATION CODE!!
void event_MainMenuHelp_MainMenuHelpCloseButton_OnReleased(leButtonWidget* btn);

// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_MainMenuHelp(); // called when Legato is initialized
leResult screenShow_MainMenuHelp(); // called when screen is shown
void screenHide_MainMenuHelp(); // called when screen is hidden
void screenDestroy_MainMenuHelp(); // called when Legato is destroyed
void screenUpdate_MainMenuHelp(); // called when Legato is updating

leWidget* screenGetRoot_MainMenuHelp(uint32_t lyrIdx); // gets a root widget for this screen

// Screen Events:
void MainMenuHelp_OnShow(); // called when this screen is shown
void MainMenuHelp_OnUpdate(); // called when this screen is updated

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_MAINMENUHELP_H
