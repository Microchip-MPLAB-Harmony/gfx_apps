#ifndef LE_GEN_SCREEN_FPSIMAGES_H
#define LE_GEN_SCREEN_FPSIMAGES_H

#include "gfx/legato/generated/le_gen_init.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// widget list for this screen
// layer 0
extern leWidget* ImageBackground;
extern leImageWidget* ImageRenderArea;
extern leWidget* ImageSideContainer;
extern leLabelWidget* ImageUpdateLabel;
extern leLabelWidget* ImageRefreshLabel;
extern leLabelWidget* ImageRefreshValue;
extern leLabelWidget* ImageContainerTitle;
extern leButtonWidget* ImageNextButton;
extern leButtonWidget* ImageSizeDownButton;
extern leButtonWidget* ImageSizeUpButton;
extern leLabelWidget* ImageSizeLabel;
extern leLabelWidget* ImageSizeValue;
extern leLabelWidget* ImageTypeLabel;
extern leLabelWidget* ImageTypeValue;
extern leButtonWidget* ImageTypePrevButton;
extern leButtonWidget* ImageTypeNextButton;
extern leButtonWidget* ImageUpdateValue;


// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_FPSImages(); // called when Legato is initialized
leResult screenShow_FPSImages(); // called when screen is shown
void screenHide_FPSImages(); // called when screen is hidden
void screenDestroy_FPSImages(); // called when Legato is destroyed
void screenUpdate_FPSImages(); // called when Legato is updating

leWidget* screenGetRoot_FPSImages(uint32_t lyrIdx); // gets a root widget for this screen

// event handlers
void FPSImages_OnShow(void);
void FPSImages_OnHide(void);
void FPSImages_OnUpdate(void);
void ImageNextButton_OnPressed(leButtonWidget* btn);
void ImageSizeDownButton_OnPressed(leButtonWidget* btn);
void ImageSizeUpButton_OnPressed(leButtonWidget* btn);
void ImageTypePrevButton_OnPressed(leButtonWidget* btn);
void ImageTypeNextButton_OnPressed(leButtonWidget* btn);

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_FPSIMAGES_H
