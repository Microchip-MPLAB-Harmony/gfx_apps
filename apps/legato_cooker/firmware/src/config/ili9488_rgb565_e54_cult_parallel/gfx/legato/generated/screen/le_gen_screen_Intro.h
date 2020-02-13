#ifndef LE_GEN_SCREEN_INTRO_H
#define LE_GEN_SCREEN_INTRO_H

#include "gfx/legato/generated/le_gen_init.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// widget list for this screen
// layer 0
extern leWidget* PanelWidget6;
extern leImageWidget* ImageWidget5;
extern leImageWidget* ImageWidget7;


// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_Intro(); // called when Legato is initialized
leResult screenShow_Intro(); // called when screen is shown
void screenHide_Intro(); // called when screen is hidden
void screenDestroy_Intro(); // called when Legato is destroyed
void screenUpdate_Intro(); // called when Legato is updating

leWidget* screenGetRoot_Intro(uint32_t lyrIdx); // gets a root widget for this screen

// event handlers
void Intro_OnShow(void);

void Intro_OnHide(void);

void Intro_OnUpdate(void);


//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_INTRO_H
