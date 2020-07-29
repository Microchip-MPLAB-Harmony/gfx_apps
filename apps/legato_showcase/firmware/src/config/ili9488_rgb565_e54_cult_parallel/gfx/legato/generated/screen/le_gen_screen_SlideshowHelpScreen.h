#ifndef LE_GEN_SCREEN_SLIDESHOWHELPSCREEN_H
#define LE_GEN_SCREEN_SLIDESHOWHELPSCREEN_H

#include "gfx/legato/legato.h"

#include "gfx/legato/generated/le_gen_scheme.h"
#include "gfx/legato/generated/le_gen_assets.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// screen member widget declarations
extern leWidget* SlideshowHelpScreen_PanelWidget8;
extern leButtonWidget* SlideshowHelpScreen_SlideShowHelpCloseButton;
extern leImageWidget* SlideshowHelpScreen_ImageWidget18;
extern leLabelWidget* SlideshowHelpScreen_LabelWidget27;
extern leLabelWidget* SlideshowHelpScreen_LabelWidget31;
extern leLabelWidget* SlideshowHelpScreen_LabelWidget36;
extern leLabelWidget* SlideshowHelpScreen_LabelWidget37;
extern leLabelWidget* SlideshowHelpScreen_LabelWidget38;
extern leLabelWidget* SlideshowHelpScreen_LabelWidget39;
extern leImageWidget* SlideshowHelpScreen_ImageWidget21;
extern leImageWidget* SlideshowHelpScreen_ImageWidget24;
extern leImageWidget* SlideshowHelpScreen_ImageWidget25;
extern leImageWidget* SlideshowHelpScreen_ImageWidget26;

// event handlers
// !!THESE MUST BE IMPLEMENTED IN THE APPLICATION CODE!!
void event_SlideshowHelpScreen_SlideShowHelpCloseButton_OnReleased(leButtonWidget* btn);

// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_SlideshowHelpScreen(); // called when Legato is initialized
leResult screenShow_SlideshowHelpScreen(); // called when screen is shown
void screenHide_SlideshowHelpScreen(); // called when screen is hidden
void screenDestroy_SlideshowHelpScreen(); // called when Legato is destroyed
void screenUpdate_SlideshowHelpScreen(); // called when Legato is updating

leWidget* screenGetRoot_SlideshowHelpScreen(uint32_t lyrIdx); // gets a root widget for this screen

// Screen Events:
void SlideshowHelpScreen_OnShow(); // called when this screen is shown
void SlideshowHelpScreen_OnUpdate(); // called when this screen is updated

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_SLIDESHOWHELPSCREEN_H
