#ifndef LE_GEN_SCREEN_SCREEN2_H
#define LE_GEN_SCREEN_SCREEN2_H

#include "gfx/legato/legato.h"

#include "gfx/legato/generated/le_gen_scheme.h"
#include "gfx/legato/generated/le_gen_assets.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// screen member widget declarations
extern leWidget* Screen2_PanelWidget0;
extern leImageWidget* Screen2_ImageWidget1;
extern leLabelWidget* Screen2_LabelWidget0;
extern leLabelWidget* Screen2_LabelWidget1;
extern leLabelWidget* Screen2_LabelWidget2;
extern leLabelWidget* Screen2_LabelWidget3;
extern leLabelWidget* Screen2_LabelWidget4;
extern leLabelWidget* Screen2_LabelWidget5;
extern leButtonWidget* Screen2_ButtonWidget0;

// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_Screen2(); // called when Legato is initialized
leResult screenShow_Screen2(); // called when screen is shown
void screenHide_Screen2(); // called when screen is hidden
void screenDestroy_Screen2(); // called when Legato is destroyed
void screenUpdate_Screen2(); // called when Legato is updating

leWidget* screenGetRoot_Screen2(uint32_t lyrIdx); // gets a root widget for this screen

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_SCREEN2_H
