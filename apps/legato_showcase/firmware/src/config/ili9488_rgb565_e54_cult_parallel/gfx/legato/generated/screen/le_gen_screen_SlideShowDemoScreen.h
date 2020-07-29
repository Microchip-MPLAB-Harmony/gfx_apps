#ifndef LE_GEN_SCREEN_SLIDESHOWDEMOSCREEN_H
#define LE_GEN_SCREEN_SLIDESHOWDEMOSCREEN_H

#include "gfx/legato/legato.h"

#include "gfx/legato/generated/le_gen_scheme.h"
#include "gfx/legato/generated/le_gen_assets.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// screen member widget declarations
extern leGradientWidget* SlideShowDemoScreen_GradientWidget6;
extern leImageSequenceWidget* SlideShowDemoScreen_ImageSequenceWidget1;
extern leButtonWidget* SlideShowDemoScreen_SlideshowHelpButton;
extern leButtonWidget* SlideShowDemoScreen_SlideShowHomeButton;
extern leLabelWidget* SlideShowDemoScreen_LabelWidget10;
extern leButtonWidget* SlideShowDemoScreen_SlideShowPrevButton;
extern leButtonWidget* SlideShowDemoScreen_SlideshowNextButton;
extern leButtonWidget* SlideShowDemoScreen_SlideShowFFButton;
extern leButtonWidget* SlideShowDemoScreen_SlideShowPlayButton;
extern leImageWidget* SlideShowDemoScreen_SSStatusImageWidget;

// event handlers
// !!THESE MUST BE IMPLEMENTED IN THE APPLICATION CODE!!
void event_SlideShowDemoScreen_SlideshowHelpButton_OnReleased(leButtonWidget* btn);
void event_SlideShowDemoScreen_SlideShowHomeButton_OnReleased(leButtonWidget* btn);
void event_SlideShowDemoScreen_SlideShowPrevButton_OnReleased(leButtonWidget* btn);
void event_SlideShowDemoScreen_SlideshowNextButton_OnReleased(leButtonWidget* btn);
void event_SlideShowDemoScreen_SlideShowFFButton_OnPressed(leButtonWidget* btn);
void event_SlideShowDemoScreen_SlideShowFFButton_OnReleased(leButtonWidget* btn);
void event_SlideShowDemoScreen_SlideShowPlayButton_OnPressed(leButtonWidget* btn);
void event_SlideShowDemoScreen_SlideShowPlayButton_OnReleased(leButtonWidget* btn);

// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_SlideShowDemoScreen(); // called when Legato is initialized
leResult screenShow_SlideShowDemoScreen(); // called when screen is shown
void screenHide_SlideShowDemoScreen(); // called when screen is hidden
void screenDestroy_SlideShowDemoScreen(); // called when Legato is destroyed
void screenUpdate_SlideShowDemoScreen(); // called when Legato is updating

leWidget* screenGetRoot_SlideShowDemoScreen(uint32_t lyrIdx); // gets a root widget for this screen

// Screen Events:
void SlideShowDemoScreen_OnShow(); // called when this screen is shown
void SlideShowDemoScreen_OnHide(); // called when this screen is hidden
void SlideShowDemoScreen_OnUpdate(); // called when this screen is updated

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_SLIDESHOWDEMOSCREEN_H
