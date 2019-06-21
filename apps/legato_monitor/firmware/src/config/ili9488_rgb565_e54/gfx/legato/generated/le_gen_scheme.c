#include "gfx/legato/generated/le_gen_scheme.h"

leScheme BoldLabelScheme;
leScheme defaultScheme;
leScheme PanelScheme;

void legato_initialize_schemes(void)
{
    leScheme_Initialize(&BoldLabelScheme, LE_COLOR_MODE_RGB_565);
    BoldLabelScheme.base = 0xC67A;
    BoldLabelScheme.highlight = 0xC67A;
    BoldLabelScheme.highlightLight = 0xFFFF;
    BoldLabelScheme.shadow = 0x8410;
    BoldLabelScheme.shadowDark = 0x4208;
    BoldLabelScheme.foreground = 0x0000;
    BoldLabelScheme.foregroundInactive = 0xD71C;
    BoldLabelScheme.foregroundDisabled = 0x8410;
    BoldLabelScheme.background = 0xFFFF;
    BoldLabelScheme.backgroundInactive = 0xD71C;
    BoldLabelScheme.backgroundDisabled = 0xC67A;
    BoldLabelScheme.text = 0xFFFF;
    BoldLabelScheme.textHighlight = 0x001F;
    BoldLabelScheme.textHighlightText = 0xFFFF;
    BoldLabelScheme.textInactive = 0xD71C;
    BoldLabelScheme.textDisabled = 0x8C92;

    leScheme_Initialize(&defaultScheme, LE_COLOR_MODE_RGB_565);
    defaultScheme.base = 0xFFFF;
    defaultScheme.highlight = 0xFFFF;
    defaultScheme.highlightLight = 0xFFFF;
    defaultScheme.shadow = 0x8410;
    defaultScheme.shadowDark = 0x4208;
    defaultScheme.foreground = 0x0000;
    defaultScheme.foregroundInactive = 0xD71C;
    defaultScheme.foregroundDisabled = 0x8410;
    defaultScheme.background = 0xFFFF;
    defaultScheme.backgroundInactive = 0xFFFF;
    defaultScheme.backgroundDisabled = 0xFFFF;
    defaultScheme.text = 0x0000;
    defaultScheme.textHighlight = 0x001F;
    defaultScheme.textHighlightText = 0xFFFF;
    defaultScheme.textInactive = 0xD71C;
    defaultScheme.textDisabled = 0x8C92;

    leScheme_Initialize(&PanelScheme, LE_COLOR_MODE_RGB_565);
    PanelScheme.base = 0x7BF4;
    PanelScheme.highlight = 0xC67A;
    PanelScheme.highlightLight = 0xFFFF;
    PanelScheme.shadow = 0x8410;
    PanelScheme.shadowDark = 0x4208;
    PanelScheme.foreground = 0x0000;
    PanelScheme.foregroundInactive = 0xD71C;
    PanelScheme.foregroundDisabled = 0x8410;
    PanelScheme.background = 0xFFFF;
    PanelScheme.backgroundInactive = 0xD71C;
    PanelScheme.backgroundDisabled = 0xC67A;
    PanelScheme.text = 0x0000;
    PanelScheme.textHighlight = 0x001F;
    PanelScheme.textHighlightText = 0xFFFF;
    PanelScheme.textInactive = 0xD71C;
    PanelScheme.textDisabled = 0x8C92;

}
