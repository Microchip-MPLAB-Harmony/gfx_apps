#ifndef LEGATO_INIT_SCHEME_H
#define LEGATO_INIT_SCHEME_H

#include "gfx/legato/legato.h"

extern leScheme BlackBackground;
extern leScheme BlackTextScheme;
extern leScheme Button1Scheme;
extern leScheme Button2Scheme;
extern leScheme Button3Scheme;
extern leScheme Button4Scheme;
extern leScheme DarkGrayScheme;
extern leScheme InactiveBackgroundScheme;
extern leScheme LabelBannerScheme;
extern leScheme ListWheelScheme;
extern leScheme ListWheelScheme2;
extern leScheme OffWhiteTextScheme;
extern leScheme ProgressBarRemainScheme;
extern leScheme ProgressBarScheme;
extern leScheme SquareButtonScheme;
extern leScheme UnselectedItemTextScheme;
extern leScheme VeryDarkGrayScheme;
extern leScheme WhiteBackgroundScheme;
extern leScheme WhiteTextScheme;

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

void legato_initialize_schemes();

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LEGATO_INIT_SCHEME_H
