#ifndef LE_GEN_SCREEN_SCREEN1_H
#define LE_GEN_SCREEN_SCREEN1_H

#include "gfx/legato/legato.h"

#include "gfx/legato/generated/le_gen_scheme.h"
#include "gfx/legato/generated/le_gen_assets.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// screen member widget declarations
extern leWidget* Screen1_PanelBackground;
extern leImageWidget* Screen1_ImageWidget0;
extern leWidget* Screen1_PositionWidget;
extern leButtonWidget* Screen1_ButtonWidget_RunLeft;
extern leButtonWidget* Screen1_ButtonWidget_RunRight;
extern leButtonWidget* Screen1_ButtonWidget_Jump;
extern leButtonWidget* Screen1_ButtonWidget_ScreenChange;
extern leImageSequenceWidget* Screen1_ImageSequenceWidget_DizzieLeft;
extern leImageSequenceWidget* Screen1_ImageSequenceWidget_DizzieRight;
extern leImageSequenceWidget* Screen1_ImageSequenceWidget_HurtLeft;
extern leImageSequenceWidget* Screen1_ImageSequenceWidget_IdleLeft;
extern leImageSequenceWidget* Screen1_ImageSequenceWidget_IdleRight;
extern leImageSequenceWidget* Screen1_ImageSequenceWidget_HurtRight;
extern leImageSequenceWidget* Screen1_ImageSequenceWidget_RunLeft;
extern leImageSequenceWidget* Screen1_ImageSequenceWidget_RunRight;
extern leImageSequenceWidget* Screen1_ImageSequenceWidget_JumpLeft;
extern leImageSequenceWidget* Screen1_ImageSequenceWidget_JumpRight;

// event handlers
// !!THESE MUST BE IMPLEMENTED IN THE APPLICATION CODE!!
void event_Screen1_ButtonWidget_RunLeft_OnPressed(leButtonWidget* btn);
void event_Screen1_ButtonWidget_RunLeft_OnReleased(leButtonWidget* btn);
void event_Screen1_ButtonWidget_RunRight_OnPressed(leButtonWidget* btn);
void event_Screen1_ButtonWidget_RunRight_OnReleased(leButtonWidget* btn);
void event_Screen1_ButtonWidget_Jump_OnPressed(leButtonWidget* btn);
void event_Screen1_ButtonWidget_Jump_OnReleased(leButtonWidget* btn);

// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_Screen1(); // called when Legato is initialized
leResult screenShow_Screen1(); // called when screen is shown
void screenHide_Screen1(); // called when screen is hidden
void screenDestroy_Screen1(); // called when Legato is destroyed
void screenUpdate_Screen1(); // called when Legato is updating

leWidget* screenGetRoot_Screen1(uint32_t lyrIdx); // gets a root widget for this screen

// Screen Events:
void Screen1_OnShow(); // called when this screen is shown
void Screen1_OnHide(); // called when this screen is hidden
void Screen1_OnUpdate(); // called when this screen is updated

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_SCREEN1_H
