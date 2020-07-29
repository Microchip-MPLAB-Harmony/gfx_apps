#include "gfx/legato/generated/screen/le_gen_screen_KeypadDemoScreen.h"

// screen member widget declarations
leWidget* root0;

leGradientWidget* KeypadDemoScreen_BackgroundGradient2;
leKeyPadWidget* KeypadDemoScreen_KeyPadWidget1;
leTextFieldWidget* KeypadDemoScreen_TextFieldWidget1;
leButtonWidget* KeypadDemoScreen_KeypadHelpButton;
leButtonWidget* KeypadDemoScreen_KeypadHomeButton;
leLabelWidget* KeypadDemoScreen_LabelWidget8;
leButtonWidget* KeypadDemoScreen_KeypadNextButton;

static leBool initialized = LE_FALSE;
static leBool showing = LE_FALSE;

leResult screenInit_KeypadDemoScreen()
{
    if(initialized == LE_TRUE)
        return LE_FAILURE;

    initialized = LE_TRUE;

    return LE_SUCCESS;
}

leResult screenShow_KeypadDemoScreen()
{
    if(showing == LE_TRUE)
        return LE_FAILURE;

    // layer 0
    root0 = leWidget_New();
    root0->fn->setSize(root0, 480, 320);
    root0->fn->setBackgroundType(root0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->setMargins(root0, 0, 0, 0, 0);
    root0->flags |= LE_WIDGET_IGNOREEVENTS;
    root0->flags |= LE_WIDGET_IGNOREPICK;

    KeypadDemoScreen_BackgroundGradient2 = leGradientWidget_New();
    KeypadDemoScreen_BackgroundGradient2->fn->setPosition(KeypadDemoScreen_BackgroundGradient2, 0, 0);
    KeypadDemoScreen_BackgroundGradient2->fn->setSize(KeypadDemoScreen_BackgroundGradient2, 480, 320);
    KeypadDemoScreen_BackgroundGradient2->fn->setScheme(KeypadDemoScreen_BackgroundGradient2, &BackgroundGradientScheme);
    KeypadDemoScreen_BackgroundGradient2->fn->setDirection(KeypadDemoScreen_BackgroundGradient2, LE_DIRECTION_DOWN);
    root0->fn->addChild(root0, (leWidget*)KeypadDemoScreen_BackgroundGradient2);

    KeypadDemoScreen_KeyPadWidget1 = leKeyPadWidget_New(4, 10);
    KeypadDemoScreen_KeyPadWidget1->fn->setPosition(KeypadDemoScreen_KeyPadWidget1, 15, 81);
    KeypadDemoScreen_KeyPadWidget1->fn->setSize(KeypadDemoScreen_KeyPadWidget1, 450, 130);
    KeypadDemoScreen_KeyPadWidget1->fn->setVisible(KeypadDemoScreen_KeyPadWidget1, LE_FALSE);
    KeypadDemoScreen_KeyPadWidget1->fn->setBackgroundType(KeypadDemoScreen_KeyPadWidget1, LE_WIDGET_BACKGROUND_NONE);
    leButtonWidget* cell_0_0 = KeypadDemoScreen_KeyPadWidget1->fn->getCellButton(KeypadDemoScreen_KeyPadWidget1, 0, 0);
    KeypadDemoScreen_KeyPadWidget1->fn->setKeyAction(KeypadDemoScreen_KeyPadWidget1, 0, 0, LE_KEYPAD_CELL_ACTION_APPEND);
    KeypadDemoScreen_KeyPadWidget1->fn->setKeyValue(KeypadDemoScreen_KeyPadWidget1, 0, 0, (leString*)&string_Keypad_1);
    cell_0_0->fn->setString(cell_0_0, (leString*)&string_Keypad_1);
    leButtonWidget* cell_0_1 = KeypadDemoScreen_KeyPadWidget1->fn->getCellButton(KeypadDemoScreen_KeyPadWidget1, 0, 1);
    KeypadDemoScreen_KeyPadWidget1->fn->setKeyAction(KeypadDemoScreen_KeyPadWidget1, 0, 1, LE_KEYPAD_CELL_ACTION_APPEND);
    KeypadDemoScreen_KeyPadWidget1->fn->setKeyValue(KeypadDemoScreen_KeyPadWidget1, 0, 1, (leString*)&string_Keypad_2);
    cell_0_1->fn->setString(cell_0_1, (leString*)&string_Keypad_2);
    leButtonWidget* cell_0_2 = KeypadDemoScreen_KeyPadWidget1->fn->getCellButton(KeypadDemoScreen_KeyPadWidget1, 0, 2);
    KeypadDemoScreen_KeyPadWidget1->fn->setKeyAction(KeypadDemoScreen_KeyPadWidget1, 0, 2, LE_KEYPAD_CELL_ACTION_APPEND);
    KeypadDemoScreen_KeyPadWidget1->fn->setKeyValue(KeypadDemoScreen_KeyPadWidget1, 0, 2, (leString*)&string_Keypad_3);
    cell_0_2->fn->setString(cell_0_2, (leString*)&string_Keypad_3);
    leButtonWidget* cell_0_3 = KeypadDemoScreen_KeyPadWidget1->fn->getCellButton(KeypadDemoScreen_KeyPadWidget1, 0, 3);
    KeypadDemoScreen_KeyPadWidget1->fn->setKeyAction(KeypadDemoScreen_KeyPadWidget1, 0, 3, LE_KEYPAD_CELL_ACTION_APPEND);
    KeypadDemoScreen_KeyPadWidget1->fn->setKeyValue(KeypadDemoScreen_KeyPadWidget1, 0, 3, (leString*)&string_Keypad_4);
    cell_0_3->fn->setString(cell_0_3, (leString*)&string_Keypad_4);
    leButtonWidget* cell_0_4 = KeypadDemoScreen_KeyPadWidget1->fn->getCellButton(KeypadDemoScreen_KeyPadWidget1, 0, 4);
    KeypadDemoScreen_KeyPadWidget1->fn->setKeyAction(KeypadDemoScreen_KeyPadWidget1, 0, 4, LE_KEYPAD_CELL_ACTION_APPEND);
    KeypadDemoScreen_KeyPadWidget1->fn->setKeyValue(KeypadDemoScreen_KeyPadWidget1, 0, 4, (leString*)&string_Keypad_5);
    cell_0_4->fn->setString(cell_0_4, (leString*)&string_Keypad_5);
    leButtonWidget* cell_0_5 = KeypadDemoScreen_KeyPadWidget1->fn->getCellButton(KeypadDemoScreen_KeyPadWidget1, 0, 5);
    KeypadDemoScreen_KeyPadWidget1->fn->setKeyAction(KeypadDemoScreen_KeyPadWidget1, 0, 5, LE_KEYPAD_CELL_ACTION_APPEND);
    KeypadDemoScreen_KeyPadWidget1->fn->setKeyValue(KeypadDemoScreen_KeyPadWidget1, 0, 5, (leString*)&string_Keypad_6);
    cell_0_5->fn->setString(cell_0_5, (leString*)&string_Keypad_6);
    leButtonWidget* cell_0_6 = KeypadDemoScreen_KeyPadWidget1->fn->getCellButton(KeypadDemoScreen_KeyPadWidget1, 0, 6);
    KeypadDemoScreen_KeyPadWidget1->fn->setKeyAction(KeypadDemoScreen_KeyPadWidget1, 0, 6, LE_KEYPAD_CELL_ACTION_APPEND);
    KeypadDemoScreen_KeyPadWidget1->fn->setKeyValue(KeypadDemoScreen_KeyPadWidget1, 0, 6, (leString*)&string_Keypad_7);
    cell_0_6->fn->setString(cell_0_6, (leString*)&string_Keypad_7);
    leButtonWidget* cell_0_7 = KeypadDemoScreen_KeyPadWidget1->fn->getCellButton(KeypadDemoScreen_KeyPadWidget1, 0, 7);
    KeypadDemoScreen_KeyPadWidget1->fn->setKeyAction(KeypadDemoScreen_KeyPadWidget1, 0, 7, LE_KEYPAD_CELL_ACTION_APPEND);
    KeypadDemoScreen_KeyPadWidget1->fn->setKeyValue(KeypadDemoScreen_KeyPadWidget1, 0, 7, (leString*)&string_Keypad_8);
    cell_0_7->fn->setString(cell_0_7, (leString*)&string_Keypad_8);
    leButtonWidget* cell_0_8 = KeypadDemoScreen_KeyPadWidget1->fn->getCellButton(KeypadDemoScreen_KeyPadWidget1, 0, 8);
    KeypadDemoScreen_KeyPadWidget1->fn->setKeyAction(KeypadDemoScreen_KeyPadWidget1, 0, 8, LE_KEYPAD_CELL_ACTION_APPEND);
    KeypadDemoScreen_KeyPadWidget1->fn->setKeyValue(KeypadDemoScreen_KeyPadWidget1, 0, 8, (leString*)&string_Keypad_9);
    cell_0_8->fn->setString(cell_0_8, (leString*)&string_Keypad_9);
    leButtonWidget* cell_0_9 = KeypadDemoScreen_KeyPadWidget1->fn->getCellButton(KeypadDemoScreen_KeyPadWidget1, 0, 9);
    KeypadDemoScreen_KeyPadWidget1->fn->setKeyAction(KeypadDemoScreen_KeyPadWidget1, 0, 9, LE_KEYPAD_CELL_ACTION_APPEND);
    KeypadDemoScreen_KeyPadWidget1->fn->setKeyValue(KeypadDemoScreen_KeyPadWidget1, 0, 9, (leString*)&string_Keypad_0);
    cell_0_9->fn->setString(cell_0_9, (leString*)&string_Keypad_0);
    leButtonWidget* cell_1_0 = KeypadDemoScreen_KeyPadWidget1->fn->getCellButton(KeypadDemoScreen_KeyPadWidget1, 1, 0);
    KeypadDemoScreen_KeyPadWidget1->fn->setKeyAction(KeypadDemoScreen_KeyPadWidget1, 1, 0, LE_KEYPAD_CELL_ACTION_APPEND);
    KeypadDemoScreen_KeyPadWidget1->fn->setKeyValue(KeypadDemoScreen_KeyPadWidget1, 1, 0, (leString*)&string_Keypad_q);
    cell_1_0->fn->setString(cell_1_0, (leString*)&string_Keypad_q);
    leButtonWidget* cell_1_1 = KeypadDemoScreen_KeyPadWidget1->fn->getCellButton(KeypadDemoScreen_KeyPadWidget1, 1, 1);
    KeypadDemoScreen_KeyPadWidget1->fn->setKeyAction(KeypadDemoScreen_KeyPadWidget1, 1, 1, LE_KEYPAD_CELL_ACTION_APPEND);
    KeypadDemoScreen_KeyPadWidget1->fn->setKeyValue(KeypadDemoScreen_KeyPadWidget1, 1, 1, (leString*)&string_Keypad_w);
    cell_1_1->fn->setString(cell_1_1, (leString*)&string_Keypad_w);
    leButtonWidget* cell_1_2 = KeypadDemoScreen_KeyPadWidget1->fn->getCellButton(KeypadDemoScreen_KeyPadWidget1, 1, 2);
    KeypadDemoScreen_KeyPadWidget1->fn->setKeyAction(KeypadDemoScreen_KeyPadWidget1, 1, 2, LE_KEYPAD_CELL_ACTION_APPEND);
    KeypadDemoScreen_KeyPadWidget1->fn->setKeyValue(KeypadDemoScreen_KeyPadWidget1, 1, 2, (leString*)&string_Keypad_e);
    cell_1_2->fn->setString(cell_1_2, (leString*)&string_Keypad_e);
    leButtonWidget* cell_1_3 = KeypadDemoScreen_KeyPadWidget1->fn->getCellButton(KeypadDemoScreen_KeyPadWidget1, 1, 3);
    KeypadDemoScreen_KeyPadWidget1->fn->setKeyAction(KeypadDemoScreen_KeyPadWidget1, 1, 3, LE_KEYPAD_CELL_ACTION_APPEND);
    KeypadDemoScreen_KeyPadWidget1->fn->setKeyValue(KeypadDemoScreen_KeyPadWidget1, 1, 3, (leString*)&string_Keypad_r);
    cell_1_3->fn->setString(cell_1_3, (leString*)&string_Keypad_r);
    leButtonWidget* cell_1_4 = KeypadDemoScreen_KeyPadWidget1->fn->getCellButton(KeypadDemoScreen_KeyPadWidget1, 1, 4);
    KeypadDemoScreen_KeyPadWidget1->fn->setKeyAction(KeypadDemoScreen_KeyPadWidget1, 1, 4, LE_KEYPAD_CELL_ACTION_APPEND);
    KeypadDemoScreen_KeyPadWidget1->fn->setKeyValue(KeypadDemoScreen_KeyPadWidget1, 1, 4, (leString*)&string_Keypad_t);
    cell_1_4->fn->setString(cell_1_4, (leString*)&string_Keypad_t);
    leButtonWidget* cell_1_5 = KeypadDemoScreen_KeyPadWidget1->fn->getCellButton(KeypadDemoScreen_KeyPadWidget1, 1, 5);
    KeypadDemoScreen_KeyPadWidget1->fn->setKeyAction(KeypadDemoScreen_KeyPadWidget1, 1, 5, LE_KEYPAD_CELL_ACTION_APPEND);
    KeypadDemoScreen_KeyPadWidget1->fn->setKeyValue(KeypadDemoScreen_KeyPadWidget1, 1, 5, (leString*)&string_Keypad_y);
    cell_1_5->fn->setString(cell_1_5, (leString*)&string_Keypad_y);
    leButtonWidget* cell_1_6 = KeypadDemoScreen_KeyPadWidget1->fn->getCellButton(KeypadDemoScreen_KeyPadWidget1, 1, 6);
    KeypadDemoScreen_KeyPadWidget1->fn->setKeyAction(KeypadDemoScreen_KeyPadWidget1, 1, 6, LE_KEYPAD_CELL_ACTION_APPEND);
    KeypadDemoScreen_KeyPadWidget1->fn->setKeyValue(KeypadDemoScreen_KeyPadWidget1, 1, 6, (leString*)&string_Keypad_u);
    cell_1_6->fn->setString(cell_1_6, (leString*)&string_Keypad_u);
    leButtonWidget* cell_1_7 = KeypadDemoScreen_KeyPadWidget1->fn->getCellButton(KeypadDemoScreen_KeyPadWidget1, 1, 7);
    KeypadDemoScreen_KeyPadWidget1->fn->setKeyAction(KeypadDemoScreen_KeyPadWidget1, 1, 7, LE_KEYPAD_CELL_ACTION_APPEND);
    KeypadDemoScreen_KeyPadWidget1->fn->setKeyValue(KeypadDemoScreen_KeyPadWidget1, 1, 7, (leString*)&string_Keypad_i);
    cell_1_7->fn->setString(cell_1_7, (leString*)&string_Keypad_i);
    leButtonWidget* cell_1_8 = KeypadDemoScreen_KeyPadWidget1->fn->getCellButton(KeypadDemoScreen_KeyPadWidget1, 1, 8);
    KeypadDemoScreen_KeyPadWidget1->fn->setKeyAction(KeypadDemoScreen_KeyPadWidget1, 1, 8, LE_KEYPAD_CELL_ACTION_APPEND);
    KeypadDemoScreen_KeyPadWidget1->fn->setKeyValue(KeypadDemoScreen_KeyPadWidget1, 1, 8, (leString*)&string_Keypad_o);
    cell_1_8->fn->setString(cell_1_8, (leString*)&string_Keypad_o);
    leButtonWidget* cell_1_9 = KeypadDemoScreen_KeyPadWidget1->fn->getCellButton(KeypadDemoScreen_KeyPadWidget1, 1, 9);
    KeypadDemoScreen_KeyPadWidget1->fn->setKeyAction(KeypadDemoScreen_KeyPadWidget1, 1, 9, LE_KEYPAD_CELL_ACTION_APPEND);
    KeypadDemoScreen_KeyPadWidget1->fn->setKeyValue(KeypadDemoScreen_KeyPadWidget1, 1, 9, (leString*)&string_Keypad_p);
    cell_1_9->fn->setString(cell_1_9, (leString*)&string_Keypad_p);
    leButtonWidget* cell_2_0 = KeypadDemoScreen_KeyPadWidget1->fn->getCellButton(KeypadDemoScreen_KeyPadWidget1, 2, 0);
    KeypadDemoScreen_KeyPadWidget1->fn->setKeyAction(KeypadDemoScreen_KeyPadWidget1, 2, 0, LE_KEYPAD_CELL_ACTION_APPEND);
    KeypadDemoScreen_KeyPadWidget1->fn->setKeyValue(KeypadDemoScreen_KeyPadWidget1, 2, 0, (leString*)&string_Keypad_a);
    cell_2_0->fn->setString(cell_2_0, (leString*)&string_Keypad_a);
    leButtonWidget* cell_2_1 = KeypadDemoScreen_KeyPadWidget1->fn->getCellButton(KeypadDemoScreen_KeyPadWidget1, 2, 1);
    KeypadDemoScreen_KeyPadWidget1->fn->setKeyAction(KeypadDemoScreen_KeyPadWidget1, 2, 1, LE_KEYPAD_CELL_ACTION_APPEND);
    KeypadDemoScreen_KeyPadWidget1->fn->setKeyValue(KeypadDemoScreen_KeyPadWidget1, 2, 1, (leString*)&string_Keypad_s);
    cell_2_1->fn->setString(cell_2_1, (leString*)&string_Keypad_s);
    leButtonWidget* cell_2_2 = KeypadDemoScreen_KeyPadWidget1->fn->getCellButton(KeypadDemoScreen_KeyPadWidget1, 2, 2);
    KeypadDemoScreen_KeyPadWidget1->fn->setKeyAction(KeypadDemoScreen_KeyPadWidget1, 2, 2, LE_KEYPAD_CELL_ACTION_APPEND);
    KeypadDemoScreen_KeyPadWidget1->fn->setKeyValue(KeypadDemoScreen_KeyPadWidget1, 2, 2, (leString*)&string_Keypad_d);
    cell_2_2->fn->setString(cell_2_2, (leString*)&string_Keypad_d);
    leButtonWidget* cell_2_3 = KeypadDemoScreen_KeyPadWidget1->fn->getCellButton(KeypadDemoScreen_KeyPadWidget1, 2, 3);
    KeypadDemoScreen_KeyPadWidget1->fn->setKeyAction(KeypadDemoScreen_KeyPadWidget1, 2, 3, LE_KEYPAD_CELL_ACTION_APPEND);
    KeypadDemoScreen_KeyPadWidget1->fn->setKeyValue(KeypadDemoScreen_KeyPadWidget1, 2, 3, (leString*)&string_Keypad_f);
    cell_2_3->fn->setString(cell_2_3, (leString*)&string_Keypad_f);
    leButtonWidget* cell_2_4 = KeypadDemoScreen_KeyPadWidget1->fn->getCellButton(KeypadDemoScreen_KeyPadWidget1, 2, 4);
    KeypadDemoScreen_KeyPadWidget1->fn->setKeyAction(KeypadDemoScreen_KeyPadWidget1, 2, 4, LE_KEYPAD_CELL_ACTION_APPEND);
    KeypadDemoScreen_KeyPadWidget1->fn->setKeyValue(KeypadDemoScreen_KeyPadWidget1, 2, 4, (leString*)&string_Keypad_g);
    cell_2_4->fn->setString(cell_2_4, (leString*)&string_Keypad_g);
    leButtonWidget* cell_2_5 = KeypadDemoScreen_KeyPadWidget1->fn->getCellButton(KeypadDemoScreen_KeyPadWidget1, 2, 5);
    KeypadDemoScreen_KeyPadWidget1->fn->setKeyAction(KeypadDemoScreen_KeyPadWidget1, 2, 5, LE_KEYPAD_CELL_ACTION_APPEND);
    KeypadDemoScreen_KeyPadWidget1->fn->setKeyValue(KeypadDemoScreen_KeyPadWidget1, 2, 5, (leString*)&string_Keypad_h);
    cell_2_5->fn->setString(cell_2_5, (leString*)&string_Keypad_h);
    leButtonWidget* cell_2_6 = KeypadDemoScreen_KeyPadWidget1->fn->getCellButton(KeypadDemoScreen_KeyPadWidget1, 2, 6);
    KeypadDemoScreen_KeyPadWidget1->fn->setKeyAction(KeypadDemoScreen_KeyPadWidget1, 2, 6, LE_KEYPAD_CELL_ACTION_APPEND);
    KeypadDemoScreen_KeyPadWidget1->fn->setKeyValue(KeypadDemoScreen_KeyPadWidget1, 2, 6, (leString*)&string_Keypad_j);
    cell_2_6->fn->setString(cell_2_6, (leString*)&string_Keypad_j);
    leButtonWidget* cell_2_7 = KeypadDemoScreen_KeyPadWidget1->fn->getCellButton(KeypadDemoScreen_KeyPadWidget1, 2, 7);
    KeypadDemoScreen_KeyPadWidget1->fn->setKeyAction(KeypadDemoScreen_KeyPadWidget1, 2, 7, LE_KEYPAD_CELL_ACTION_APPEND);
    KeypadDemoScreen_KeyPadWidget1->fn->setKeyValue(KeypadDemoScreen_KeyPadWidget1, 2, 7, (leString*)&string_Keypad_k);
    cell_2_7->fn->setString(cell_2_7, (leString*)&string_Keypad_k);
    leButtonWidget* cell_2_8 = KeypadDemoScreen_KeyPadWidget1->fn->getCellButton(KeypadDemoScreen_KeyPadWidget1, 2, 8);
    KeypadDemoScreen_KeyPadWidget1->fn->setKeyAction(KeypadDemoScreen_KeyPadWidget1, 2, 8, LE_KEYPAD_CELL_ACTION_APPEND);
    KeypadDemoScreen_KeyPadWidget1->fn->setKeyValue(KeypadDemoScreen_KeyPadWidget1, 2, 8, (leString*)&string_Keypad_l);
    cell_2_8->fn->setString(cell_2_8, (leString*)&string_Keypad_l);
    leButtonWidget* cell_2_9 = KeypadDemoScreen_KeyPadWidget1->fn->getCellButton(KeypadDemoScreen_KeyPadWidget1, 2, 9);
    KeypadDemoScreen_KeyPadWidget1->fn->setKeyAction(KeypadDemoScreen_KeyPadWidget1, 2, 9, LE_KEYPAD_CELL_ACTION_BACKSPACE);
    cell_2_9->fn->setString(cell_2_9, (leString*)&string_Backspace);
    leButtonWidget* cell_3_0 = KeypadDemoScreen_KeyPadWidget1->fn->getCellButton(KeypadDemoScreen_KeyPadWidget1, 3, 0);
    KeypadDemoScreen_KeyPadWidget1->fn->setKeyAction(KeypadDemoScreen_KeyPadWidget1, 3, 0, LE_KEYPAD_CELL_ACTION_APPEND);
    KeypadDemoScreen_KeyPadWidget1->fn->setKeyValue(KeypadDemoScreen_KeyPadWidget1, 3, 0, (leString*)&string_Keypad_z);
    cell_3_0->fn->setString(cell_3_0, (leString*)&string_Keypad_z);
    leButtonWidget* cell_3_1 = KeypadDemoScreen_KeyPadWidget1->fn->getCellButton(KeypadDemoScreen_KeyPadWidget1, 3, 1);
    KeypadDemoScreen_KeyPadWidget1->fn->setKeyAction(KeypadDemoScreen_KeyPadWidget1, 3, 1, LE_KEYPAD_CELL_ACTION_APPEND);
    KeypadDemoScreen_KeyPadWidget1->fn->setKeyValue(KeypadDemoScreen_KeyPadWidget1, 3, 1, (leString*)&string_Keypad_x);
    cell_3_1->fn->setString(cell_3_1, (leString*)&string_Keypad_x);
    leButtonWidget* cell_3_2 = KeypadDemoScreen_KeyPadWidget1->fn->getCellButton(KeypadDemoScreen_KeyPadWidget1, 3, 2);
    KeypadDemoScreen_KeyPadWidget1->fn->setKeyAction(KeypadDemoScreen_KeyPadWidget1, 3, 2, LE_KEYPAD_CELL_ACTION_APPEND);
    KeypadDemoScreen_KeyPadWidget1->fn->setKeyValue(KeypadDemoScreen_KeyPadWidget1, 3, 2, (leString*)&string_Keypad_c);
    cell_3_2->fn->setString(cell_3_2, (leString*)&string_Keypad_c);
    leButtonWidget* cell_3_3 = KeypadDemoScreen_KeyPadWidget1->fn->getCellButton(KeypadDemoScreen_KeyPadWidget1, 3, 3);
    KeypadDemoScreen_KeyPadWidget1->fn->setKeyAction(KeypadDemoScreen_KeyPadWidget1, 3, 3, LE_KEYPAD_CELL_ACTION_APPEND);
    KeypadDemoScreen_KeyPadWidget1->fn->setKeyValue(KeypadDemoScreen_KeyPadWidget1, 3, 3, (leString*)&string_Keypad_v);
    cell_3_3->fn->setString(cell_3_3, (leString*)&string_Keypad_v);
    leButtonWidget* cell_3_4 = KeypadDemoScreen_KeyPadWidget1->fn->getCellButton(KeypadDemoScreen_KeyPadWidget1, 3, 4);
    KeypadDemoScreen_KeyPadWidget1->fn->setKeyAction(KeypadDemoScreen_KeyPadWidget1, 3, 4, LE_KEYPAD_CELL_ACTION_APPEND);
    KeypadDemoScreen_KeyPadWidget1->fn->setKeyValue(KeypadDemoScreen_KeyPadWidget1, 3, 4, (leString*)&string_Keypad_b);
    cell_3_4->fn->setString(cell_3_4, (leString*)&string_Keypad_b);
    leButtonWidget* cell_3_5 = KeypadDemoScreen_KeyPadWidget1->fn->getCellButton(KeypadDemoScreen_KeyPadWidget1, 3, 5);
    KeypadDemoScreen_KeyPadWidget1->fn->setKeyAction(KeypadDemoScreen_KeyPadWidget1, 3, 5, LE_KEYPAD_CELL_ACTION_APPEND);
    KeypadDemoScreen_KeyPadWidget1->fn->setKeyValue(KeypadDemoScreen_KeyPadWidget1, 3, 5, (leString*)&string_Keypad_n);
    cell_3_5->fn->setString(cell_3_5, (leString*)&string_Keypad_n);
    leButtonWidget* cell_3_6 = KeypadDemoScreen_KeyPadWidget1->fn->getCellButton(KeypadDemoScreen_KeyPadWidget1, 3, 6);
    KeypadDemoScreen_KeyPadWidget1->fn->setKeyAction(KeypadDemoScreen_KeyPadWidget1, 3, 6, LE_KEYPAD_CELL_ACTION_APPEND);
    KeypadDemoScreen_KeyPadWidget1->fn->setKeyValue(KeypadDemoScreen_KeyPadWidget1, 3, 6, (leString*)&string_Keypad_m);
    cell_3_6->fn->setString(cell_3_6, (leString*)&string_Keypad_m);
    leButtonWidget* cell_3_7 = KeypadDemoScreen_KeyPadWidget1->fn->getCellButton(KeypadDemoScreen_KeyPadWidget1, 3, 7);
    KeypadDemoScreen_KeyPadWidget1->fn->setKeyAction(KeypadDemoScreen_KeyPadWidget1, 3, 7, LE_KEYPAD_CELL_ACTION_APPEND);
    KeypadDemoScreen_KeyPadWidget1->fn->setKeyValue(KeypadDemoScreen_KeyPadWidget1, 3, 7, (leString*)&string_spaceChar);
    cell_3_7->fn->setString(cell_3_7, (leString*)&string_spacebar);
    leButtonWidget* cell_3_8 = KeypadDemoScreen_KeyPadWidget1->fn->getCellButton(KeypadDemoScreen_KeyPadWidget1, 3, 8);
    KeypadDemoScreen_KeyPadWidget1->fn->setKeyVisible(KeypadDemoScreen_KeyPadWidget1, 3, 8, LE_FALSE);
    cell_3_8->fn->setString(cell_3_8, (leString*)&string_AM);
    leButtonWidget* cell_3_9 = KeypadDemoScreen_KeyPadWidget1->fn->getCellButton(KeypadDemoScreen_KeyPadWidget1, 3, 9);
    KeypadDemoScreen_KeyPadWidget1->fn->setKeyAction(KeypadDemoScreen_KeyPadWidget1, 3, 9, LE_KEYPAD_CELL_ACTION_CLEAR);
    cell_3_9->fn->setString(cell_3_9, (leString*)&string_clear);
    root0->fn->addChild(root0, (leWidget*)KeypadDemoScreen_KeyPadWidget1);

    KeypadDemoScreen_TextFieldWidget1 = leTextFieldWidget_New();
    KeypadDemoScreen_TextFieldWidget1->fn->setPosition(KeypadDemoScreen_TextFieldWidget1, 15, 38);
    KeypadDemoScreen_TextFieldWidget1->fn->setSize(KeypadDemoScreen_TextFieldWidget1, 450, 40);
    KeypadDemoScreen_TextFieldWidget1->fn->setHAlignment(KeypadDemoScreen_TextFieldWidget1, LE_HALIGN_LEFT);
    KeypadDemoScreen_TextFieldWidget1->fn->setString(KeypadDemoScreen_TextFieldWidget1, (leString*)&string_textField_Instruction);
    KeypadDemoScreen_TextFieldWidget1->fn->setHintString(KeypadDemoScreen_TextFieldWidget1, (leString*)&string_textField_Instruction);
    KeypadDemoScreen_TextFieldWidget1->fn->setFont(KeypadDemoScreen_TextFieldWidget1, (leFont*)&NotoSans_Bold18);
    KeypadDemoScreen_TextFieldWidget1->fn->setFocusChangedEventCallback(KeypadDemoScreen_TextFieldWidget1, event_KeypadDemoScreen_TextFieldWidget1_OnFocusChanged);
    root0->fn->addChild(root0, (leWidget*)KeypadDemoScreen_TextFieldWidget1);

    KeypadDemoScreen_KeypadHelpButton = leButtonWidget_New();
    KeypadDemoScreen_KeypadHelpButton->fn->setPosition(KeypadDemoScreen_KeypadHelpButton, 0, 260);
    KeypadDemoScreen_KeypadHelpButton->fn->setSize(KeypadDemoScreen_KeypadHelpButton, 60, 60);
    KeypadDemoScreen_KeypadHelpButton->fn->setAlphaAmount(KeypadDemoScreen_KeypadHelpButton, 220);
    KeypadDemoScreen_KeypadHelpButton->fn->setBackgroundType(KeypadDemoScreen_KeypadHelpButton, LE_WIDGET_BACKGROUND_NONE);
    KeypadDemoScreen_KeypadHelpButton->fn->setBorderType(KeypadDemoScreen_KeypadHelpButton, LE_WIDGET_BORDER_NONE);
    KeypadDemoScreen_KeypadHelpButton->fn->setPressedImage(KeypadDemoScreen_KeypadHelpButton, (leImage*)&GFX_Help_60);
    KeypadDemoScreen_KeypadHelpButton->fn->setReleasedImage(KeypadDemoScreen_KeypadHelpButton, (leImage*)&GFX_Help_60);
    KeypadDemoScreen_KeypadHelpButton->fn->setReleasedEventCallback(KeypadDemoScreen_KeypadHelpButton, event_KeypadDemoScreen_KeypadHelpButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)KeypadDemoScreen_KeypadHelpButton);

    KeypadDemoScreen_KeypadHomeButton = leButtonWidget_New();
    KeypadDemoScreen_KeypadHomeButton->fn->setPosition(KeypadDemoScreen_KeypadHomeButton, 421, 260);
    KeypadDemoScreen_KeypadHomeButton->fn->setSize(KeypadDemoScreen_KeypadHomeButton, 60, 60);
    KeypadDemoScreen_KeypadHomeButton->fn->setAlphaAmount(KeypadDemoScreen_KeypadHomeButton, 220);
    KeypadDemoScreen_KeypadHomeButton->fn->setBackgroundType(KeypadDemoScreen_KeypadHomeButton, LE_WIDGET_BACKGROUND_NONE);
    KeypadDemoScreen_KeypadHomeButton->fn->setBorderType(KeypadDemoScreen_KeypadHomeButton, LE_WIDGET_BORDER_NONE);
    KeypadDemoScreen_KeypadHomeButton->fn->setPressedImage(KeypadDemoScreen_KeypadHomeButton, (leImage*)&GFX_Home_60x60);
    KeypadDemoScreen_KeypadHomeButton->fn->setReleasedImage(KeypadDemoScreen_KeypadHomeButton, (leImage*)&GFX_Home_60x60);
    KeypadDemoScreen_KeypadHomeButton->fn->setReleasedEventCallback(KeypadDemoScreen_KeypadHomeButton, event_KeypadDemoScreen_KeypadHomeButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)KeypadDemoScreen_KeypadHomeButton);

    KeypadDemoScreen_LabelWidget8 = leLabelWidget_New();
    KeypadDemoScreen_LabelWidget8->fn->setPosition(KeypadDemoScreen_LabelWidget8, 10, 5);
    KeypadDemoScreen_LabelWidget8->fn->setSize(KeypadDemoScreen_LabelWidget8, 281, 25);
    KeypadDemoScreen_LabelWidget8->fn->setScheme(KeypadDemoScreen_LabelWidget8, &whiteScheme);
    KeypadDemoScreen_LabelWidget8->fn->setBackgroundType(KeypadDemoScreen_LabelWidget8, LE_WIDGET_BACKGROUND_NONE);
    KeypadDemoScreen_LabelWidget8->fn->setString(KeypadDemoScreen_LabelWidget8, (leString*)&string_KeypadWidgetDemo);
    root0->fn->addChild(root0, (leWidget*)KeypadDemoScreen_LabelWidget8);

    KeypadDemoScreen_KeypadNextButton = leButtonWidget_New();
    KeypadDemoScreen_KeypadNextButton->fn->setPosition(KeypadDemoScreen_KeypadNextButton, 359, 260);
    KeypadDemoScreen_KeypadNextButton->fn->setSize(KeypadDemoScreen_KeypadNextButton, 60, 60);
    KeypadDemoScreen_KeypadNextButton->fn->setBackgroundType(KeypadDemoScreen_KeypadNextButton, LE_WIDGET_BACKGROUND_NONE);
    KeypadDemoScreen_KeypadNextButton->fn->setBorderType(KeypadDemoScreen_KeypadNextButton, LE_WIDGET_BORDER_NONE);
    KeypadDemoScreen_KeypadNextButton->fn->setPressedImage(KeypadDemoScreen_KeypadNextButton, (leImage*)&GFX_NextScreen_60x60);
    KeypadDemoScreen_KeypadNextButton->fn->setReleasedImage(KeypadDemoScreen_KeypadNextButton, (leImage*)&GFX_NextScreen_60x60);
    KeypadDemoScreen_KeypadNextButton->fn->setReleasedEventCallback(KeypadDemoScreen_KeypadNextButton, event_KeypadDemoScreen_KeypadNextButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)KeypadDemoScreen_KeypadNextButton);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGB_565);

    KeypadDemoScreen_OnShow(); // raise event

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_KeypadDemoScreen()
{
    KeypadDemoScreen_OnUpdate(); // raise event
}

void screenHide_KeypadDemoScreen()
{
    KeypadDemoScreen_OnHide(); // raise event


    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    KeypadDemoScreen_BackgroundGradient2 = NULL;
    KeypadDemoScreen_KeyPadWidget1 = NULL;
    KeypadDemoScreen_TextFieldWidget1 = NULL;
    KeypadDemoScreen_KeypadHelpButton = NULL;
    KeypadDemoScreen_KeypadHomeButton = NULL;
    KeypadDemoScreen_LabelWidget8 = NULL;
    KeypadDemoScreen_KeypadNextButton = NULL;


    showing = LE_FALSE;
}

void screenDestroy_KeypadDemoScreen()
{
    if(initialized == LE_FALSE)
        return;

    initialized = LE_FALSE;
}

leWidget* screenGetRoot_KeypadDemoScreen(uint32_t lyrIdx)
{
    if(lyrIdx >= LE_LAYER_COUNT)
        return NULL;

    switch(lyrIdx)
    {
        case 0:
        {
            return root0;
        }
        default:
        {
            return NULL;
        }
    }
}

