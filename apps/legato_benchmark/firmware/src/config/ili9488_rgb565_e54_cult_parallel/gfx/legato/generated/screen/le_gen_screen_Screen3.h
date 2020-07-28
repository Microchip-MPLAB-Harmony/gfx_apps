#ifndef LE_GEN_SCREEN_SCREEN3_H
#define LE_GEN_SCREEN_SCREEN3_H

#include "gfx/legato/legato.h"

#include "gfx/legato/generated/le_gen_scheme.h"
#include "gfx/legato/generated/le_gen_assets.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// screen member widget declarations
extern leWidget* Screen3_ImageBackground;
extern leImageWidget* Screen3_ImageRenderArea;
extern leWidget* Screen3_ImageSideContainer;
extern leButtonWidget* Screen3_ImageUpdateValue;
extern leButtonWidget* Screen3_ImageTypeNextButton;
extern leButtonWidget* Screen3_ImageTypePrevButton;
extern leLabelWidget* Screen3_ImageTypeValue;
extern leLabelWidget* Screen3_ImageTypeLabel;
extern leLabelWidget* Screen3_ImageSizeValue;
extern leLabelWidget* Screen3_ImageSizeLabel;
extern leButtonWidget* Screen3_ImageSizeUpButton;
extern leButtonWidget* Screen3_ImageSizeDownButton;
extern leButtonWidget* Screen3_ImageNextButton;
extern leLabelWidget* Screen3_ImageContainerTitle;
extern leLabelWidget* Screen3_ImageRefreshValue;
extern leLabelWidget* Screen3_ImageRefreshLabel;
extern leLabelWidget* Screen3_ImageUpdateLabel;

// event handlers
// !!THESE MUST BE IMPLEMENTED IN THE APPLICATION CODE!!
void event_Screen3_ImageTypeNextButton_OnPressed(leButtonWidget* btn);
void event_Screen3_ImageTypePrevButton_OnPressed(leButtonWidget* btn);
void event_Screen3_ImageSizeUpButton_OnPressed(leButtonWidget* btn);
void event_Screen3_ImageSizeDownButton_OnPressed(leButtonWidget* btn);

// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_Screen3(); // called when Legato is initialized
leResult screenShow_Screen3(); // called when screen is shown
void screenHide_Screen3(); // called when screen is hidden
void screenDestroy_Screen3(); // called when Legato is destroyed
void screenUpdate_Screen3(); // called when Legato is updating

leWidget* screenGetRoot_Screen3(uint32_t lyrIdx); // gets a root widget for this screen

// Screen Events:
void Screen3_OnShow(); // called when this screen is shown
void Screen3_OnHide(); // called when this screen is hidden
void Screen3_OnUpdate(); // called when this screen is updated

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_SCREEN3_H
