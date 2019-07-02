#include "gfx/legato/generated/le_gen_scheme.h"

leScheme defaultScheme;
leScheme ElevatedScheme;
leScheme HighStage1Scheme;
leScheme HighStage2Scheme;
leScheme HypertensiveScheme;
leScheme NormalScheme;

void legato_initialize_schemes(void)
{
    leScheme_Initialize(&defaultScheme, LE_COLOR_MODE_RGB_565);
    defaultScheme.base = 0xFFFF;
    defaultScheme.highlight = 0xC67A;
    defaultScheme.highlightLight = 0xFFFF;
    defaultScheme.shadow = 0x8410;
    defaultScheme.shadowDark = 0x4208;
    defaultScheme.foreground = 0x0000;
    defaultScheme.foregroundInactive = 0xD71C;
    defaultScheme.foregroundDisabled = 0x8410;
    defaultScheme.background = 0xFFFF;
    defaultScheme.backgroundInactive = 0xD71C;
    defaultScheme.backgroundDisabled = 0xC67A;
    defaultScheme.text = 0x0000;
    defaultScheme.textHighlight = 0x001F;
    defaultScheme.textHighlightText = 0xFFFF;
    defaultScheme.textInactive = 0xD71C;
    defaultScheme.textDisabled = 0x8C92;

    leScheme_Initialize(&ElevatedScheme, LE_COLOR_MODE_RGB_565);
    ElevatedScheme.base = 0xC67A;
    ElevatedScheme.highlight = 0xC67A;
    ElevatedScheme.highlightLight = 0xFFFF;
    ElevatedScheme.shadow = 0x8410;
    ElevatedScheme.shadowDark = 0x4208;
    ElevatedScheme.foreground = 0x0000;
    ElevatedScheme.foregroundInactive = 0xD71C;
    ElevatedScheme.foregroundDisabled = 0x8410;
    ElevatedScheme.background = 0xFFFF;
    ElevatedScheme.backgroundInactive = 0xD71C;
    ElevatedScheme.backgroundDisabled = 0xC67A;
    ElevatedScheme.text = 0xBDE0;
    ElevatedScheme.textHighlight = 0x001F;
    ElevatedScheme.textHighlightText = 0xFFFF;
    ElevatedScheme.textInactive = 0xD71C;
    ElevatedScheme.textDisabled = 0x8C92;

    leScheme_Initialize(&HighStage1Scheme, LE_COLOR_MODE_RGB_565);
    HighStage1Scheme.base = 0xC67A;
    HighStage1Scheme.highlight = 0xC67A;
    HighStage1Scheme.highlightLight = 0xFFFF;
    HighStage1Scheme.shadow = 0x8410;
    HighStage1Scheme.shadowDark = 0x4208;
    HighStage1Scheme.foreground = 0x0000;
    HighStage1Scheme.foregroundInactive = 0xD71C;
    HighStage1Scheme.foregroundDisabled = 0x8410;
    HighStage1Scheme.background = 0xFFFF;
    HighStage1Scheme.backgroundInactive = 0xD71C;
    HighStage1Scheme.backgroundDisabled = 0xC67A;
    HighStage1Scheme.text = 0xFC00;
    HighStage1Scheme.textHighlight = 0x001F;
    HighStage1Scheme.textHighlightText = 0xFFFF;
    HighStage1Scheme.textInactive = 0xD71C;
    HighStage1Scheme.textDisabled = 0x8C92;

    leScheme_Initialize(&HighStage2Scheme, LE_COLOR_MODE_RGB_565);
    HighStage2Scheme.base = 0xC67A;
    HighStage2Scheme.highlight = 0xC67A;
    HighStage2Scheme.highlightLight = 0xFFFF;
    HighStage2Scheme.shadow = 0x8410;
    HighStage2Scheme.shadowDark = 0x4208;
    HighStage2Scheme.foreground = 0x0000;
    HighStage2Scheme.foregroundInactive = 0xD71C;
    HighStage2Scheme.foregroundDisabled = 0x8410;
    HighStage2Scheme.background = 0xFFFF;
    HighStage2Scheme.backgroundInactive = 0xD71C;
    HighStage2Scheme.backgroundDisabled = 0xC67A;
    HighStage2Scheme.text = 0xBA00;
    HighStage2Scheme.textHighlight = 0x001F;
    HighStage2Scheme.textHighlightText = 0xFFFF;
    HighStage2Scheme.textInactive = 0xD71C;
    HighStage2Scheme.textDisabled = 0x8C92;

    leScheme_Initialize(&HypertensiveScheme, LE_COLOR_MODE_RGB_565);
    HypertensiveScheme.base = 0xC67A;
    HypertensiveScheme.highlight = 0xC67A;
    HypertensiveScheme.highlightLight = 0xFFFF;
    HypertensiveScheme.shadow = 0x8410;
    HypertensiveScheme.shadowDark = 0x4208;
    HypertensiveScheme.foreground = 0x0000;
    HypertensiveScheme.foregroundInactive = 0xD71C;
    HypertensiveScheme.foregroundDisabled = 0x8410;
    HypertensiveScheme.background = 0xFFFF;
    HypertensiveScheme.backgroundInactive = 0xD71C;
    HypertensiveScheme.backgroundDisabled = 0xC67A;
    HypertensiveScheme.text = 0xB800;
    HypertensiveScheme.textHighlight = 0x001F;
    HypertensiveScheme.textHighlightText = 0xFFFF;
    HypertensiveScheme.textInactive = 0xD71C;
    HypertensiveScheme.textDisabled = 0x8C92;

    leScheme_Initialize(&NormalScheme, LE_COLOR_MODE_RGB_565);
    NormalScheme.base = 0xC67A;
    NormalScheme.highlight = 0xC67A;
    NormalScheme.highlightLight = 0xFFFF;
    NormalScheme.shadow = 0x8410;
    NormalScheme.shadowDark = 0x4208;
    NormalScheme.foreground = 0x0000;
    NormalScheme.foregroundInactive = 0xD71C;
    NormalScheme.foregroundDisabled = 0x8410;
    NormalScheme.background = 0xFFFF;
    NormalScheme.backgroundInactive = 0xD71C;
    NormalScheme.backgroundDisabled = 0xC67A;
    NormalScheme.text = 0x0400;
    NormalScheme.textHighlight = 0x001F;
    NormalScheme.textHighlightText = 0xFFFF;
    NormalScheme.textInactive = 0xD71C;
    NormalScheme.textDisabled = 0x8C92;

}
