#ifndef LE_GEN_SCREEN_SLIDESHOWDEMOSCREEN_H
#define LE_GEN_SCREEN_SLIDESHOWDEMOSCREEN_H

#include "gfx/legato/generated/le_gen_init.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// widget list for this screen
// layer 0
extern leGradientWidget* GradientWidget6;
extern leImageSequenceWidget* ImageSequenceWidget1;
extern leButtonWidget* SlideshowHelpButton;
extern leButtonWidget* SlideShowHomeButton;
extern leLabelWidget* LabelWidget10;
extern leButtonWidget* SlideShowPrevButton;
extern leButtonWidget* SlideshowNextButton;
extern leButtonWidget* SlideShowFFButton;
extern leButtonWidget* SlideShowPlayButton;
extern leImageWidget* SSStatusImageWidget;


// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_SlideShowDemoScreen(); // called when Legato is initialized
leResult screenShow_SlideShowDemoScreen(); // called when screen is shown
void screenHide_SlideShowDemoScreen(); // called when screen is hidden
void screenDestroy_SlideShowDemoScreen(); // called when Legato is destroyed
void screenUpdate_SlideShowDemoScreen(); // called when Legato is updating

leWidget* screenGetRoot_SlideShowDemoScreen(uint32_t lyrIdx); // gets a root widget for this screen

// event handlers
void SlideShowDemoScreen_OnShow(void);
void SlideShowDemoScreen_OnHide(void);
void SlideShowDemoScreen_OnUpdate(void);
void SlideshowHelpButton_OnReleased(leButtonWidget* btn);
void SlideShowHomeButton_OnReleased(leButtonWidget* btn);
void SlideShowPrevButton_OnReleased(leButtonWidget* btn);
void SlideshowNextButton_OnReleased(leButtonWidget* btn);
void SlideShowFFButton_OnPressed(leButtonWidget* btn);
void SlideShowFFButton_OnReleased(leButtonWidget* btn);
void SlideShowPlayButton_OnPressed(leButtonWidget* btn);
void SlideShowPlayButton_OnReleased(leButtonWidget* btn);

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_SLIDESHOWDEMOSCREEN_H
