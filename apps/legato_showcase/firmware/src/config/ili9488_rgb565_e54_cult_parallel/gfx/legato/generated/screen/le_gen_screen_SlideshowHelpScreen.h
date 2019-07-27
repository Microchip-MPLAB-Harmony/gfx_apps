#ifndef LE_GEN_SCREEN_SLIDESHOWHELPSCREEN_H
#define LE_GEN_SCREEN_SLIDESHOWHELPSCREEN_H

#include "gfx/legato/generated/le_gen_init.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// widget list for this screen
// layer 0
extern leWidget* PanelWidget8;
extern leButtonWidget* SlideShowHelpCloseButton;
extern leImageWidget* ImageWidget18;
extern leLabelWidget* LabelWidget27;
extern leLabelWidget* LabelWidget31;
extern leLabelWidget* LabelWidget36;
extern leLabelWidget* LabelWidget37;
extern leLabelWidget* LabelWidget38;
extern leLabelWidget* LabelWidget39;
extern leImageWidget* ImageWidget21;
extern leImageWidget* ImageWidget24;
extern leImageWidget* ImageWidget25;
extern leImageWidget* ImageWidget26;


// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_SlideshowHelpScreen(); // called when Legato is initialized
leResult screenShow_SlideshowHelpScreen(); // called when screen is shown
void screenHide_SlideshowHelpScreen(); // called when screen is hidden
void screenDestroy_SlideshowHelpScreen(); // called when Legato is destroyed
void screenUpdate_SlideshowHelpScreen(); // called when Legato is updating

leWidget* screenGetRoot_SlideshowHelpScreen(uint32_t lyrIdx); // gets a root widget for this screen

// event handlers
void SlideshowHelpScreen_OnShow(void);

void SlideshowHelpScreen_OnUpdate(void);

void SlideShowHelpCloseButton_OnReleased(leButtonWidget* btn)
;


//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_SLIDESHOWHELPSCREEN_H
