#ifndef LEGATO_INIT_SCHEME_H
#define LEGATO_INIT_SCHEME_H

#include "gfx/legato/legato.h"

extern const leScheme defaultScheme;
extern const leScheme NormalScheme;
extern const leScheme HighStage1Scheme;
extern const leScheme HighStage2Scheme;
extern const leScheme HypertensiveScheme;
extern const leScheme ElevatedScheme;

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
