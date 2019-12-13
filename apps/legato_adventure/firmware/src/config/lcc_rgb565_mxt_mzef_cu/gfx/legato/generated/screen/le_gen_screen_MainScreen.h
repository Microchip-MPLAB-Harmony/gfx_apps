#ifndef LE_GEN_SCREEN_MAINSCREEN_H
#define LE_GEN_SCREEN_MAINSCREEN_H

#include "gfx/legato/generated/le_gen_init.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// widget list for this screen
// layer 0
extern leWidget* PanelBackground;
extern leImageWidget* ImageWidget0;
extern leWidget* PositionWidget;
extern leImageSequenceWidget* ImageSequenceWidget_JumpRight;
extern leImageSequenceWidget* ImageSequenceWidget_JumpLeft;
extern leImageSequenceWidget* ImageSequenceWidget_RunRight;
extern leImageSequenceWidget* ImageSequenceWidget_RunLeft;
extern leImageSequenceWidget* ImageSequenceWidget_HurtRight;
extern leImageSequenceWidget* ImageSequenceWidget_IdleRight;
extern leImageSequenceWidget* ImageSequenceWidget_IdleLeft;
extern leImageSequenceWidget* ImageSequenceWidget_HurtLeft;
extern leImageSequenceWidget* ImageSequenceWidget_DizzieRight;
extern leImageSequenceWidget* ImageSequenceWidget_DizzieLeft;
extern leButtonWidget* ButtonWidget_RunLeft;
extern leButtonWidget* ButtonWidget_RunRight;
extern leButtonWidget* ButtonWidget_Jump;
extern leButtonWidget* ButtonWidget_ScreenChange;


// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_MainScreen(); // called when Legato is initialized
leResult screenShow_MainScreen(); // called when screen is shown
void screenHide_MainScreen(); // called when screen is hidden
void screenDestroy_MainScreen(); // called when Legato is destroyed
void screenUpdate_MainScreen(); // called when Legato is updating

leWidget* screenGetRoot_MainScreen(uint32_t lyrIdx); // gets a root widget for this screen

// event handlers
void MainScreen_OnShow(void);

void MainScreen_OnHide(void);

void MainScreen_OnUpdate(void);

void ButtonWidget_RunLeft_OnPressed(leButtonWidget* btn)
;

void ButtonWidget_RunLeft_OnReleased(leButtonWidget* btn)
;

void ButtonWidget_RunRight_OnPressed(leButtonWidget* btn)
;

void ButtonWidget_RunRight_OnReleased(leButtonWidget* btn)
;

void ButtonWidget_Jump_OnPressed(leButtonWidget* btn)
;


//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_MAINSCREEN_H
