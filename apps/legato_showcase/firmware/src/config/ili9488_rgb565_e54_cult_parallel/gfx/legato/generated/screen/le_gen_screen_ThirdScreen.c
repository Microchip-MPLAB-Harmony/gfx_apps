#include "gfx/legato/generated/screen/le_gen_screen_ThirdScreen.h"

// widget list for layer 0
static leWidget* root0;

leGradientWidget* GradientWidget4;
leKeyPadWidget* KeyPadWidget1;
leTextFieldWidget* TextFieldWidget1;
leButtonWidget* ButtonWidget5;
leButtonWidget* ButtonWidget6;
leLabelWidget* LabelWidget8;
leButtonWidget* ButtonWidget32;

// string list for this screen
static leTableString tableString_Keypad_1;
static leTableString tableString_Keypad_2;
static leTableString tableString_Keypad_3;
static leTableString tableString_Keypad_4;
static leTableString tableString_Keypad_5;
static leTableString tableString_Keypad_6;
static leTableString tableString_Keypad_7;
static leTableString tableString_Keypad_8;
static leTableString tableString_Keypad_9;
static leTableString tableString_Keypad_0;
static leTableString tableString_Keypad_q;
static leTableString tableString_Keypad_w;
static leTableString tableString_Keypad_e;
static leTableString tableString_Keypad_r;
static leTableString tableString_Keypad_t;
static leTableString tableString_Keypad_y;
static leTableString tableString_Keypad_u;
static leTableString tableString_Keypad_i;
static leTableString tableString_Keypad_o;
static leTableString tableString_Keypad_p;
static leTableString tableString_Keypad_a;
static leTableString tableString_Keypad_s;
static leTableString tableString_Keypad_d;
static leTableString tableString_Keypad_f;
static leTableString tableString_Keypad_g;
static leTableString tableString_Keypad_h;
static leTableString tableString_Keypad_j;
static leTableString tableString_Keypad_k;
static leTableString tableString_Keypad_l;
static leTableString tableString_Backspace;
static leTableString tableString_Keypad_z;
static leTableString tableString_Keypad_x;
static leTableString tableString_Keypad_c;
static leTableString tableString_Keypad_v;
static leTableString tableString_Keypad_b;
static leTableString tableString_Keypad_n;
static leTableString tableString_Keypad_m;
static leTableString tableString_spacebar;
static leTableString tableString_spaceChar;
static leTableString tableString_clear;
static leTableString tableString_textField_Instruction;
static leTableString tableString_KeypadWidgetDemo;

// event handlers
static void KeyPadWidget1_OnKeyClick(leKeyPadWidget* pad, leButtonWidget* btn, uint32_t row, uint32_t col);
static void TextFieldWidget1_OnFocusChanged(leTextFieldWidget* txt, leBool focused);
static void ButtonWidget5_OnReleased(leButtonWidget* btn);
static void ButtonWidget6_OnReleased(leButtonWidget* btn);
static void ButtonWidget32_OnReleased(leButtonWidget* btn);

static leBool showing = LE_FALSE;

leResult screenInit_ThirdScreen()
{
    return LE_SUCCESS;
}

leResult screenShow_ThirdScreen()
{
    if(showing == LE_TRUE)
        return LE_FAILURE;

    // initialize static strings
    leTableString_Constructor(&tableString_Keypad_1, string_Keypad_1);
    leTableString_Constructor(&tableString_Keypad_2, string_Keypad_2);
    leTableString_Constructor(&tableString_Keypad_3, string_Keypad_3);
    leTableString_Constructor(&tableString_Keypad_4, string_Keypad_4);
    leTableString_Constructor(&tableString_Keypad_5, string_Keypad_5);
    leTableString_Constructor(&tableString_Keypad_6, string_Keypad_6);
    leTableString_Constructor(&tableString_Keypad_7, string_Keypad_7);
    leTableString_Constructor(&tableString_Keypad_8, string_Keypad_8);
    leTableString_Constructor(&tableString_Keypad_9, string_Keypad_9);
    leTableString_Constructor(&tableString_Keypad_0, string_Keypad_0);
    leTableString_Constructor(&tableString_Keypad_q, string_Keypad_q);
    leTableString_Constructor(&tableString_Keypad_w, string_Keypad_w);
    leTableString_Constructor(&tableString_Keypad_e, string_Keypad_e);
    leTableString_Constructor(&tableString_Keypad_r, string_Keypad_r);
    leTableString_Constructor(&tableString_Keypad_t, string_Keypad_t);
    leTableString_Constructor(&tableString_Keypad_y, string_Keypad_y);
    leTableString_Constructor(&tableString_Keypad_u, string_Keypad_u);
    leTableString_Constructor(&tableString_Keypad_i, string_Keypad_i);
    leTableString_Constructor(&tableString_Keypad_o, string_Keypad_o);
    leTableString_Constructor(&tableString_Keypad_p, string_Keypad_p);
    leTableString_Constructor(&tableString_Keypad_a, string_Keypad_a);
    leTableString_Constructor(&tableString_Keypad_s, string_Keypad_s);
    leTableString_Constructor(&tableString_Keypad_d, string_Keypad_d);
    leTableString_Constructor(&tableString_Keypad_f, string_Keypad_f);
    leTableString_Constructor(&tableString_Keypad_g, string_Keypad_g);
    leTableString_Constructor(&tableString_Keypad_h, string_Keypad_h);
    leTableString_Constructor(&tableString_Keypad_j, string_Keypad_j);
    leTableString_Constructor(&tableString_Keypad_k, string_Keypad_k);
    leTableString_Constructor(&tableString_Keypad_l, string_Keypad_l);
    leTableString_Constructor(&tableString_Backspace, string_Backspace);
    leTableString_Constructor(&tableString_Keypad_z, string_Keypad_z);
    leTableString_Constructor(&tableString_Keypad_x, string_Keypad_x);
    leTableString_Constructor(&tableString_Keypad_c, string_Keypad_c);
    leTableString_Constructor(&tableString_Keypad_v, string_Keypad_v);
    leTableString_Constructor(&tableString_Keypad_b, string_Keypad_b);
    leTableString_Constructor(&tableString_Keypad_n, string_Keypad_n);
    leTableString_Constructor(&tableString_Keypad_m, string_Keypad_m);
    leTableString_Constructor(&tableString_spacebar, string_spacebar);
    leTableString_Constructor(&tableString_spaceChar, string_spaceChar);
    leTableString_Constructor(&tableString_clear, string_clear);
    leTableString_Constructor(&tableString_textField_Instruction, string_textField_Instruction);
    leTableString_Constructor(&tableString_KeypadWidgetDemo, string_KeypadWidgetDemo);

    // layer 0
    root0 = leWidget_New();
    root0->fn->setPosition(root0, 0, 0);
    root0->fn->setSize(root0, 480, 320);
    root0->fn->setBackgroundType(root0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->setMargins(root0, 0, 0, 0, 0);

    GradientWidget4 = leGradientWidget_New();
    GradientWidget4->fn->setPosition(GradientWidget4, 0, 0);
    GradientWidget4->fn->setSize(GradientWidget4, 480, 320);
    GradientWidget4->fn->setScheme(GradientWidget4, &BackgroundGradientScheme);
    GradientWidget4->fn->setDirection(GradientWidget4, LE_DIRECTION_DOWN);
    root0->fn->addChild(root0, (leWidget*)GradientWidget4);

    KeyPadWidget1 = leKeyPadWidget_New(4, 10);
    KeyPadWidget1->fn->setPosition(KeyPadWidget1, 15, 81);
    KeyPadWidget1->fn->setSize(KeyPadWidget1, 450, 130);
    KeyPadWidget1->fn->setVisible(KeyPadWidget1, LE_FALSE);
    KeyPadWidget1->fn->setKeyAction(KeyPadWidget1, 0, 0, LE_KEYPAD_CELL_ACTION_APPEND);
    KeyPadWidget1->fn->setKeyValue(KeyPadWidget1, 0, 0, (leString*)&tableString_Keypad_1);
    leButtonWidget* KeyPadWidget1_cell_0_0 = KeyPadWidget1->fn->getCellButton(KeyPadWidget1, 0, 0);
    KeyPadWidget1_cell_0_0->fn->setString(KeyPadWidget1_cell_0_0, (leString*)&tableString_Keypad_1);
    KeyPadWidget1->fn->setKeyAction(KeyPadWidget1, 0, 1, LE_KEYPAD_CELL_ACTION_APPEND);
    KeyPadWidget1->fn->setKeyValue(KeyPadWidget1, 0, 1, (leString*)&tableString_Keypad_2);
    leButtonWidget* KeyPadWidget1_cell_0_1 = KeyPadWidget1->fn->getCellButton(KeyPadWidget1, 0, 1);
    KeyPadWidget1_cell_0_1->fn->setString(KeyPadWidget1_cell_0_1, (leString*)&tableString_Keypad_2);
    KeyPadWidget1->fn->setKeyAction(KeyPadWidget1, 0, 2, LE_KEYPAD_CELL_ACTION_APPEND);
    KeyPadWidget1->fn->setKeyValue(KeyPadWidget1, 0, 2, (leString*)&tableString_Keypad_3);
    leButtonWidget* KeyPadWidget1_cell_0_2 = KeyPadWidget1->fn->getCellButton(KeyPadWidget1, 0, 2);
    KeyPadWidget1_cell_0_2->fn->setString(KeyPadWidget1_cell_0_2, (leString*)&tableString_Keypad_3);
    KeyPadWidget1->fn->setKeyAction(KeyPadWidget1, 0, 3, LE_KEYPAD_CELL_ACTION_APPEND);
    KeyPadWidget1->fn->setKeyValue(KeyPadWidget1, 0, 3, (leString*)&tableString_Keypad_4);
    leButtonWidget* KeyPadWidget1_cell_0_3 = KeyPadWidget1->fn->getCellButton(KeyPadWidget1, 0, 3);
    KeyPadWidget1_cell_0_3->fn->setString(KeyPadWidget1_cell_0_3, (leString*)&tableString_Keypad_4);
    KeyPadWidget1->fn->setKeyAction(KeyPadWidget1, 0, 4, LE_KEYPAD_CELL_ACTION_APPEND);
    KeyPadWidget1->fn->setKeyValue(KeyPadWidget1, 0, 4, (leString*)&tableString_Keypad_5);
    leButtonWidget* KeyPadWidget1_cell_0_4 = KeyPadWidget1->fn->getCellButton(KeyPadWidget1, 0, 4);
    KeyPadWidget1_cell_0_4->fn->setString(KeyPadWidget1_cell_0_4, (leString*)&tableString_Keypad_5);
    KeyPadWidget1->fn->setKeyAction(KeyPadWidget1, 0, 5, LE_KEYPAD_CELL_ACTION_APPEND);
    KeyPadWidget1->fn->setKeyValue(KeyPadWidget1, 0, 5, (leString*)&tableString_Keypad_6);
    leButtonWidget* KeyPadWidget1_cell_0_5 = KeyPadWidget1->fn->getCellButton(KeyPadWidget1, 0, 5);
    KeyPadWidget1_cell_0_5->fn->setString(KeyPadWidget1_cell_0_5, (leString*)&tableString_Keypad_6);
    KeyPadWidget1->fn->setKeyAction(KeyPadWidget1, 0, 6, LE_KEYPAD_CELL_ACTION_APPEND);
    KeyPadWidget1->fn->setKeyValue(KeyPadWidget1, 0, 6, (leString*)&tableString_Keypad_7);
    leButtonWidget* KeyPadWidget1_cell_0_6 = KeyPadWidget1->fn->getCellButton(KeyPadWidget1, 0, 6);
    KeyPadWidget1_cell_0_6->fn->setString(KeyPadWidget1_cell_0_6, (leString*)&tableString_Keypad_7);
    KeyPadWidget1->fn->setKeyAction(KeyPadWidget1, 0, 7, LE_KEYPAD_CELL_ACTION_APPEND);
    KeyPadWidget1->fn->setKeyValue(KeyPadWidget1, 0, 7, (leString*)&tableString_Keypad_8);
    leButtonWidget* KeyPadWidget1_cell_0_7 = KeyPadWidget1->fn->getCellButton(KeyPadWidget1, 0, 7);
    KeyPadWidget1_cell_0_7->fn->setString(KeyPadWidget1_cell_0_7, (leString*)&tableString_Keypad_8);
    KeyPadWidget1->fn->setKeyAction(KeyPadWidget1, 0, 8, LE_KEYPAD_CELL_ACTION_APPEND);
    KeyPadWidget1->fn->setKeyValue(KeyPadWidget1, 0, 8, (leString*)&tableString_Keypad_9);
    leButtonWidget* KeyPadWidget1_cell_0_8 = KeyPadWidget1->fn->getCellButton(KeyPadWidget1, 0, 8);
    KeyPadWidget1_cell_0_8->fn->setString(KeyPadWidget1_cell_0_8, (leString*)&tableString_Keypad_9);
    KeyPadWidget1->fn->setKeyAction(KeyPadWidget1, 0, 9, LE_KEYPAD_CELL_ACTION_APPEND);
    KeyPadWidget1->fn->setKeyValue(KeyPadWidget1, 0, 9, (leString*)&tableString_Keypad_0);
    leButtonWidget* KeyPadWidget1_cell_0_9 = KeyPadWidget1->fn->getCellButton(KeyPadWidget1, 0, 9);
    KeyPadWidget1_cell_0_9->fn->setString(KeyPadWidget1_cell_0_9, (leString*)&tableString_Keypad_0);
    KeyPadWidget1->fn->setKeyAction(KeyPadWidget1, 1, 0, LE_KEYPAD_CELL_ACTION_APPEND);
    KeyPadWidget1->fn->setKeyValue(KeyPadWidget1, 1, 0, (leString*)&tableString_Keypad_q);
    leButtonWidget* KeyPadWidget1_cell_1_0 = KeyPadWidget1->fn->getCellButton(KeyPadWidget1, 1, 0);
    KeyPadWidget1_cell_1_0->fn->setString(KeyPadWidget1_cell_1_0, (leString*)&tableString_Keypad_q);
    KeyPadWidget1->fn->setKeyAction(KeyPadWidget1, 1, 1, LE_KEYPAD_CELL_ACTION_APPEND);
    KeyPadWidget1->fn->setKeyValue(KeyPadWidget1, 1, 1, (leString*)&tableString_Keypad_w);
    leButtonWidget* KeyPadWidget1_cell_1_1 = KeyPadWidget1->fn->getCellButton(KeyPadWidget1, 1, 1);
    KeyPadWidget1_cell_1_1->fn->setString(KeyPadWidget1_cell_1_1, (leString*)&tableString_Keypad_w);
    KeyPadWidget1->fn->setKeyAction(KeyPadWidget1, 1, 2, LE_KEYPAD_CELL_ACTION_APPEND);
    KeyPadWidget1->fn->setKeyValue(KeyPadWidget1, 1, 2, (leString*)&tableString_Keypad_e);
    leButtonWidget* KeyPadWidget1_cell_1_2 = KeyPadWidget1->fn->getCellButton(KeyPadWidget1, 1, 2);
    KeyPadWidget1_cell_1_2->fn->setString(KeyPadWidget1_cell_1_2, (leString*)&tableString_Keypad_e);
    KeyPadWidget1->fn->setKeyAction(KeyPadWidget1, 1, 3, LE_KEYPAD_CELL_ACTION_APPEND);
    KeyPadWidget1->fn->setKeyValue(KeyPadWidget1, 1, 3, (leString*)&tableString_Keypad_r);
    leButtonWidget* KeyPadWidget1_cell_1_3 = KeyPadWidget1->fn->getCellButton(KeyPadWidget1, 1, 3);
    KeyPadWidget1_cell_1_3->fn->setString(KeyPadWidget1_cell_1_3, (leString*)&tableString_Keypad_r);
    KeyPadWidget1->fn->setKeyAction(KeyPadWidget1, 1, 4, LE_KEYPAD_CELL_ACTION_APPEND);
    KeyPadWidget1->fn->setKeyValue(KeyPadWidget1, 1, 4, (leString*)&tableString_Keypad_t);
    leButtonWidget* KeyPadWidget1_cell_1_4 = KeyPadWidget1->fn->getCellButton(KeyPadWidget1, 1, 4);
    KeyPadWidget1_cell_1_4->fn->setString(KeyPadWidget1_cell_1_4, (leString*)&tableString_Keypad_t);
    KeyPadWidget1->fn->setKeyAction(KeyPadWidget1, 1, 5, LE_KEYPAD_CELL_ACTION_APPEND);
    KeyPadWidget1->fn->setKeyValue(KeyPadWidget1, 1, 5, (leString*)&tableString_Keypad_y);
    leButtonWidget* KeyPadWidget1_cell_1_5 = KeyPadWidget1->fn->getCellButton(KeyPadWidget1, 1, 5);
    KeyPadWidget1_cell_1_5->fn->setString(KeyPadWidget1_cell_1_5, (leString*)&tableString_Keypad_y);
    KeyPadWidget1->fn->setKeyAction(KeyPadWidget1, 1, 6, LE_KEYPAD_CELL_ACTION_APPEND);
    KeyPadWidget1->fn->setKeyValue(KeyPadWidget1, 1, 6, (leString*)&tableString_Keypad_u);
    leButtonWidget* KeyPadWidget1_cell_1_6 = KeyPadWidget1->fn->getCellButton(KeyPadWidget1, 1, 6);
    KeyPadWidget1_cell_1_6->fn->setString(KeyPadWidget1_cell_1_6, (leString*)&tableString_Keypad_u);
    KeyPadWidget1->fn->setKeyAction(KeyPadWidget1, 1, 7, LE_KEYPAD_CELL_ACTION_APPEND);
    KeyPadWidget1->fn->setKeyValue(KeyPadWidget1, 1, 7, (leString*)&tableString_Keypad_i);
    leButtonWidget* KeyPadWidget1_cell_1_7 = KeyPadWidget1->fn->getCellButton(KeyPadWidget1, 1, 7);
    KeyPadWidget1_cell_1_7->fn->setString(KeyPadWidget1_cell_1_7, (leString*)&tableString_Keypad_i);
    KeyPadWidget1->fn->setKeyAction(KeyPadWidget1, 1, 8, LE_KEYPAD_CELL_ACTION_APPEND);
    KeyPadWidget1->fn->setKeyValue(KeyPadWidget1, 1, 8, (leString*)&tableString_Keypad_o);
    leButtonWidget* KeyPadWidget1_cell_1_8 = KeyPadWidget1->fn->getCellButton(KeyPadWidget1, 1, 8);
    KeyPadWidget1_cell_1_8->fn->setString(KeyPadWidget1_cell_1_8, (leString*)&tableString_Keypad_o);
    KeyPadWidget1->fn->setKeyAction(KeyPadWidget1, 1, 9, LE_KEYPAD_CELL_ACTION_APPEND);
    KeyPadWidget1->fn->setKeyValue(KeyPadWidget1, 1, 9, (leString*)&tableString_Keypad_p);
    leButtonWidget* KeyPadWidget1_cell_1_9 = KeyPadWidget1->fn->getCellButton(KeyPadWidget1, 1, 9);
    KeyPadWidget1_cell_1_9->fn->setString(KeyPadWidget1_cell_1_9, (leString*)&tableString_Keypad_p);
    KeyPadWidget1->fn->setKeyAction(KeyPadWidget1, 2, 0, LE_KEYPAD_CELL_ACTION_APPEND);
    KeyPadWidget1->fn->setKeyValue(KeyPadWidget1, 2, 0, (leString*)&tableString_Keypad_a);
    leButtonWidget* KeyPadWidget1_cell_2_0 = KeyPadWidget1->fn->getCellButton(KeyPadWidget1, 2, 0);
    KeyPadWidget1_cell_2_0->fn->setString(KeyPadWidget1_cell_2_0, (leString*)&tableString_Keypad_a);
    KeyPadWidget1->fn->setKeyAction(KeyPadWidget1, 2, 1, LE_KEYPAD_CELL_ACTION_APPEND);
    KeyPadWidget1->fn->setKeyValue(KeyPadWidget1, 2, 1, (leString*)&tableString_Keypad_s);
    leButtonWidget* KeyPadWidget1_cell_2_1 = KeyPadWidget1->fn->getCellButton(KeyPadWidget1, 2, 1);
    KeyPadWidget1_cell_2_1->fn->setString(KeyPadWidget1_cell_2_1, (leString*)&tableString_Keypad_s);
    KeyPadWidget1->fn->setKeyAction(KeyPadWidget1, 2, 2, LE_KEYPAD_CELL_ACTION_APPEND);
    KeyPadWidget1->fn->setKeyValue(KeyPadWidget1, 2, 2, (leString*)&tableString_Keypad_d);
    leButtonWidget* KeyPadWidget1_cell_2_2 = KeyPadWidget1->fn->getCellButton(KeyPadWidget1, 2, 2);
    KeyPadWidget1_cell_2_2->fn->setString(KeyPadWidget1_cell_2_2, (leString*)&tableString_Keypad_d);
    KeyPadWidget1->fn->setKeyAction(KeyPadWidget1, 2, 3, LE_KEYPAD_CELL_ACTION_APPEND);
    KeyPadWidget1->fn->setKeyValue(KeyPadWidget1, 2, 3, (leString*)&tableString_Keypad_f);
    leButtonWidget* KeyPadWidget1_cell_2_3 = KeyPadWidget1->fn->getCellButton(KeyPadWidget1, 2, 3);
    KeyPadWidget1_cell_2_3->fn->setString(KeyPadWidget1_cell_2_3, (leString*)&tableString_Keypad_f);
    KeyPadWidget1->fn->setKeyAction(KeyPadWidget1, 2, 4, LE_KEYPAD_CELL_ACTION_APPEND);
    KeyPadWidget1->fn->setKeyValue(KeyPadWidget1, 2, 4, (leString*)&tableString_Keypad_g);
    leButtonWidget* KeyPadWidget1_cell_2_4 = KeyPadWidget1->fn->getCellButton(KeyPadWidget1, 2, 4);
    KeyPadWidget1_cell_2_4->fn->setString(KeyPadWidget1_cell_2_4, (leString*)&tableString_Keypad_g);
    KeyPadWidget1->fn->setKeyAction(KeyPadWidget1, 2, 5, LE_KEYPAD_CELL_ACTION_APPEND);
    KeyPadWidget1->fn->setKeyValue(KeyPadWidget1, 2, 5, (leString*)&tableString_Keypad_h);
    leButtonWidget* KeyPadWidget1_cell_2_5 = KeyPadWidget1->fn->getCellButton(KeyPadWidget1, 2, 5);
    KeyPadWidget1_cell_2_5->fn->setString(KeyPadWidget1_cell_2_5, (leString*)&tableString_Keypad_h);
    KeyPadWidget1->fn->setKeyAction(KeyPadWidget1, 2, 6, LE_KEYPAD_CELL_ACTION_APPEND);
    KeyPadWidget1->fn->setKeyValue(KeyPadWidget1, 2, 6, (leString*)&tableString_Keypad_j);
    leButtonWidget* KeyPadWidget1_cell_2_6 = KeyPadWidget1->fn->getCellButton(KeyPadWidget1, 2, 6);
    KeyPadWidget1_cell_2_6->fn->setString(KeyPadWidget1_cell_2_6, (leString*)&tableString_Keypad_j);
    KeyPadWidget1->fn->setKeyAction(KeyPadWidget1, 2, 7, LE_KEYPAD_CELL_ACTION_APPEND);
    KeyPadWidget1->fn->setKeyValue(KeyPadWidget1, 2, 7, (leString*)&tableString_Keypad_k);
    leButtonWidget* KeyPadWidget1_cell_2_7 = KeyPadWidget1->fn->getCellButton(KeyPadWidget1, 2, 7);
    KeyPadWidget1_cell_2_7->fn->setString(KeyPadWidget1_cell_2_7, (leString*)&tableString_Keypad_k);
    KeyPadWidget1->fn->setKeyAction(KeyPadWidget1, 2, 8, LE_KEYPAD_CELL_ACTION_APPEND);
    KeyPadWidget1->fn->setKeyValue(KeyPadWidget1, 2, 8, (leString*)&tableString_Keypad_l);
    leButtonWidget* KeyPadWidget1_cell_2_8 = KeyPadWidget1->fn->getCellButton(KeyPadWidget1, 2, 8);
    KeyPadWidget1_cell_2_8->fn->setString(KeyPadWidget1_cell_2_8, (leString*)&tableString_Keypad_l);
    KeyPadWidget1->fn->setKeyAction(KeyPadWidget1, 2, 9, LE_KEYPAD_CELL_ACTION_BACKSPACE);
    leButtonWidget* KeyPadWidget1_cell_2_9 = KeyPadWidget1->fn->getCellButton(KeyPadWidget1, 2, 9);
    KeyPadWidget1_cell_2_9->fn->setString(KeyPadWidget1_cell_2_9, (leString*)&tableString_Backspace);
    KeyPadWidget1->fn->setKeyAction(KeyPadWidget1, 3, 0, LE_KEYPAD_CELL_ACTION_APPEND);
    KeyPadWidget1->fn->setKeyValue(KeyPadWidget1, 3, 0, (leString*)&tableString_Keypad_z);
    leButtonWidget* KeyPadWidget1_cell_3_0 = KeyPadWidget1->fn->getCellButton(KeyPadWidget1, 3, 0);
    KeyPadWidget1_cell_3_0->fn->setString(KeyPadWidget1_cell_3_0, (leString*)&tableString_Keypad_z);
    KeyPadWidget1->fn->setKeyAction(KeyPadWidget1, 3, 1, LE_KEYPAD_CELL_ACTION_APPEND);
    KeyPadWidget1->fn->setKeyValue(KeyPadWidget1, 3, 1, (leString*)&tableString_Keypad_x);
    leButtonWidget* KeyPadWidget1_cell_3_1 = KeyPadWidget1->fn->getCellButton(KeyPadWidget1, 3, 1);
    KeyPadWidget1_cell_3_1->fn->setString(KeyPadWidget1_cell_3_1, (leString*)&tableString_Keypad_x);
    KeyPadWidget1->fn->setKeyAction(KeyPadWidget1, 3, 2, LE_KEYPAD_CELL_ACTION_APPEND);
    KeyPadWidget1->fn->setKeyValue(KeyPadWidget1, 3, 2, (leString*)&tableString_Keypad_c);
    leButtonWidget* KeyPadWidget1_cell_3_2 = KeyPadWidget1->fn->getCellButton(KeyPadWidget1, 3, 2);
    KeyPadWidget1_cell_3_2->fn->setString(KeyPadWidget1_cell_3_2, (leString*)&tableString_Keypad_c);
    KeyPadWidget1->fn->setKeyAction(KeyPadWidget1, 3, 3, LE_KEYPAD_CELL_ACTION_APPEND);
    KeyPadWidget1->fn->setKeyValue(KeyPadWidget1, 3, 3, (leString*)&tableString_Keypad_v);
    leButtonWidget* KeyPadWidget1_cell_3_3 = KeyPadWidget1->fn->getCellButton(KeyPadWidget1, 3, 3);
    KeyPadWidget1_cell_3_3->fn->setString(KeyPadWidget1_cell_3_3, (leString*)&tableString_Keypad_v);
    KeyPadWidget1->fn->setKeyAction(KeyPadWidget1, 3, 4, LE_KEYPAD_CELL_ACTION_APPEND);
    KeyPadWidget1->fn->setKeyValue(KeyPadWidget1, 3, 4, (leString*)&tableString_Keypad_b);
    leButtonWidget* KeyPadWidget1_cell_3_4 = KeyPadWidget1->fn->getCellButton(KeyPadWidget1, 3, 4);
    KeyPadWidget1_cell_3_4->fn->setString(KeyPadWidget1_cell_3_4, (leString*)&tableString_Keypad_b);
    KeyPadWidget1->fn->setKeyAction(KeyPadWidget1, 3, 5, LE_KEYPAD_CELL_ACTION_APPEND);
    KeyPadWidget1->fn->setKeyValue(KeyPadWidget1, 3, 5, (leString*)&tableString_Keypad_n);
    leButtonWidget* KeyPadWidget1_cell_3_5 = KeyPadWidget1->fn->getCellButton(KeyPadWidget1, 3, 5);
    KeyPadWidget1_cell_3_5->fn->setString(KeyPadWidget1_cell_3_5, (leString*)&tableString_Keypad_n);
    KeyPadWidget1->fn->setKeyAction(KeyPadWidget1, 3, 6, LE_KEYPAD_CELL_ACTION_APPEND);
    KeyPadWidget1->fn->setKeyValue(KeyPadWidget1, 3, 6, (leString*)&tableString_Keypad_m);
    leButtonWidget* KeyPadWidget1_cell_3_6 = KeyPadWidget1->fn->getCellButton(KeyPadWidget1, 3, 6);
    KeyPadWidget1_cell_3_6->fn->setString(KeyPadWidget1_cell_3_6, (leString*)&tableString_Keypad_m);
    KeyPadWidget1->fn->setKeyAction(KeyPadWidget1, 3, 7, LE_KEYPAD_CELL_ACTION_APPEND);
    KeyPadWidget1->fn->setKeyValue(KeyPadWidget1, 3, 7, (leString*)&tableString_spaceChar);
    leButtonWidget* KeyPadWidget1_cell_3_7 = KeyPadWidget1->fn->getCellButton(KeyPadWidget1, 3, 7);
    KeyPadWidget1_cell_3_7->fn->setString(KeyPadWidget1_cell_3_7, (leString*)&tableString_spacebar);
    KeyPadWidget1->fn->setKeyAction(KeyPadWidget1, 3, 8, LE_KEYPAD_CELL_ACTION_APPEND);
    leButtonWidget* KeyPadWidget1_cell_3_8 = KeyPadWidget1->fn->getCellButton(KeyPadWidget1, 3, 8);
    KeyPadWidget1_cell_3_8->fn->setVisible(KeyPadWidget1_cell_3_8, LE_FALSE);
    KeyPadWidget1->fn->setKeyAction(KeyPadWidget1, 3, 9, LE_KEYPAD_CELL_ACTION_CLEAR);
    leButtonWidget* KeyPadWidget1_cell_3_9 = KeyPadWidget1->fn->getCellButton(KeyPadWidget1, 3, 9);
    KeyPadWidget1_cell_3_9->fn->setString(KeyPadWidget1_cell_3_9, (leString*)&tableString_clear);
    KeyPadWidget1->fn->setKeyClickEventCallback(KeyPadWidget1, KeyPadWidget1_OnKeyClick);
    root0->fn->addChild(root0, (leWidget*)KeyPadWidget1);

    TextFieldWidget1 = leTextFieldWidget_New();
    TextFieldWidget1->fn->setPosition(TextFieldWidget1, 15, 38);
    TextFieldWidget1->fn->setSize(TextFieldWidget1, 450, 40);
    TextFieldWidget1->fn->setString(TextFieldWidget1, (leString*)&tableString_textField_Instruction);
    TextFieldWidget1->fn->setFocusChangedEventCallback(TextFieldWidget1, TextFieldWidget1_OnFocusChanged);
    root0->fn->addChild(root0, (leWidget*)TextFieldWidget1);

    ButtonWidget5 = leButtonWidget_New();
    ButtonWidget5->fn->setPosition(ButtonWidget5, 0, 260);
    ButtonWidget5->fn->setSize(ButtonWidget5, 60, 60);
    ButtonWidget5->fn->setAlphaAmount(ButtonWidget5, 220);
    ButtonWidget5->fn->setBackgroundType(ButtonWidget5, LE_WIDGET_BACKGROUND_NONE);
    ButtonWidget5->fn->setBorderType(ButtonWidget5, LE_WIDGET_BORDER_NONE);
    ButtonWidget5->fn->setPressedImage(ButtonWidget5, &GFX_Help_60);
    ButtonWidget5->fn->setReleasedImage(ButtonWidget5, &GFX_Help_60);
    ButtonWidget5->fn->setReleasedEventCallback(ButtonWidget5, ButtonWidget5_OnReleased);
    root0->fn->addChild(root0, (leWidget*)ButtonWidget5);

    ButtonWidget6 = leButtonWidget_New();
    ButtonWidget6->fn->setPosition(ButtonWidget6, 421, 260);
    ButtonWidget6->fn->setSize(ButtonWidget6, 60, 60);
    ButtonWidget6->fn->setAlphaAmount(ButtonWidget6, 220);
    ButtonWidget6->fn->setBackgroundType(ButtonWidget6, LE_WIDGET_BACKGROUND_NONE);
    ButtonWidget6->fn->setBorderType(ButtonWidget6, LE_WIDGET_BORDER_NONE);
    ButtonWidget6->fn->setPressedImage(ButtonWidget6, &GFX_Home_60x60);
    ButtonWidget6->fn->setReleasedImage(ButtonWidget6, &GFX_Home_60x60);
    ButtonWidget6->fn->setReleasedEventCallback(ButtonWidget6, ButtonWidget6_OnReleased);
    root0->fn->addChild(root0, (leWidget*)ButtonWidget6);

    LabelWidget8 = leLabelWidget_New();
    LabelWidget8->fn->setPosition(LabelWidget8, 10, 5);
    LabelWidget8->fn->setSize(LabelWidget8, 281, 25);
    LabelWidget8->fn->setScheme(LabelWidget8, &BlackBackground);
    LabelWidget8->fn->setBackgroundType(LabelWidget8, LE_WIDGET_BACKGROUND_NONE);
    LabelWidget8->fn->setString(LabelWidget8, (leString*)&tableString_KeypadWidgetDemo);
    root0->fn->addChild(root0, (leWidget*)LabelWidget8);

    ButtonWidget32 = leButtonWidget_New();
    ButtonWidget32->fn->setPosition(ButtonWidget32, 359, 260);
    ButtonWidget32->fn->setSize(ButtonWidget32, 60, 60);
    ButtonWidget32->fn->setBackgroundType(ButtonWidget32, LE_WIDGET_BACKGROUND_NONE);
    ButtonWidget32->fn->setBorderType(ButtonWidget32, LE_WIDGET_BORDER_NONE);
    ButtonWidget32->fn->setPressedImage(ButtonWidget32, &GFX_NextScreen_60x60);
    ButtonWidget32->fn->setReleasedImage(ButtonWidget32, &GFX_NextScreen_60x60);
    ButtonWidget32->fn->setReleasedEventCallback(ButtonWidget32, ButtonWidget32_OnReleased);
    root0->fn->addChild(root0, (leWidget*)ButtonWidget32);

    leAddRootWidget(root0, 0);

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_ThirdScreen()
{
}

void screenHide_ThirdScreen()
{
    leRemoveRootWidget(root0, 0);

    leWidget_Delete(root0);

    root0 = NULL;

    GradientWidget4 = NULL;
    KeyPadWidget1 = NULL;
    TextFieldWidget1 = NULL;
    ButtonWidget5 = NULL;
    ButtonWidget6 = NULL;
    LabelWidget8 = NULL;
    ButtonWidget32 = NULL;

    tableString_Keypad_1.fn->destructor(&tableString_Keypad_1);
    tableString_Keypad_2.fn->destructor(&tableString_Keypad_2);
    tableString_Keypad_3.fn->destructor(&tableString_Keypad_3);
    tableString_Keypad_4.fn->destructor(&tableString_Keypad_4);
    tableString_Keypad_5.fn->destructor(&tableString_Keypad_5);
    tableString_Keypad_6.fn->destructor(&tableString_Keypad_6);
    tableString_Keypad_7.fn->destructor(&tableString_Keypad_7);
    tableString_Keypad_8.fn->destructor(&tableString_Keypad_8);
    tableString_Keypad_9.fn->destructor(&tableString_Keypad_9);
    tableString_Keypad_0.fn->destructor(&tableString_Keypad_0);
    tableString_Keypad_q.fn->destructor(&tableString_Keypad_q);
    tableString_Keypad_w.fn->destructor(&tableString_Keypad_w);
    tableString_Keypad_e.fn->destructor(&tableString_Keypad_e);
    tableString_Keypad_r.fn->destructor(&tableString_Keypad_r);
    tableString_Keypad_t.fn->destructor(&tableString_Keypad_t);
    tableString_Keypad_y.fn->destructor(&tableString_Keypad_y);
    tableString_Keypad_u.fn->destructor(&tableString_Keypad_u);
    tableString_Keypad_i.fn->destructor(&tableString_Keypad_i);
    tableString_Keypad_o.fn->destructor(&tableString_Keypad_o);
    tableString_Keypad_p.fn->destructor(&tableString_Keypad_p);
    tableString_Keypad_a.fn->destructor(&tableString_Keypad_a);
    tableString_Keypad_s.fn->destructor(&tableString_Keypad_s);
    tableString_Keypad_d.fn->destructor(&tableString_Keypad_d);
    tableString_Keypad_f.fn->destructor(&tableString_Keypad_f);
    tableString_Keypad_g.fn->destructor(&tableString_Keypad_g);
    tableString_Keypad_h.fn->destructor(&tableString_Keypad_h);
    tableString_Keypad_j.fn->destructor(&tableString_Keypad_j);
    tableString_Keypad_k.fn->destructor(&tableString_Keypad_k);
    tableString_Keypad_l.fn->destructor(&tableString_Keypad_l);
    tableString_Backspace.fn->destructor(&tableString_Backspace);
    tableString_Keypad_z.fn->destructor(&tableString_Keypad_z);
    tableString_Keypad_x.fn->destructor(&tableString_Keypad_x);
    tableString_Keypad_c.fn->destructor(&tableString_Keypad_c);
    tableString_Keypad_v.fn->destructor(&tableString_Keypad_v);
    tableString_Keypad_b.fn->destructor(&tableString_Keypad_b);
    tableString_Keypad_n.fn->destructor(&tableString_Keypad_n);
    tableString_Keypad_m.fn->destructor(&tableString_Keypad_m);
    tableString_spacebar.fn->destructor(&tableString_spacebar);
    tableString_spaceChar.fn->destructor(&tableString_spaceChar);
    tableString_clear.fn->destructor(&tableString_clear);
    tableString_textField_Instruction.fn->destructor(&tableString_textField_Instruction);
    tableString_KeypadWidgetDemo.fn->destructor(&tableString_KeypadWidgetDemo);
    showing = LE_FALSE;
}

void screenDestroy_ThirdScreen()
{

}

leWidget* screenGetRoot_ThirdScreen(uint32_t lyrIdx)
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

// event handlers
void KeyPadWidget1_OnKeyClick(leKeyPadWidget* pad, leButtonWidget* btn, uint32_t row, uint32_t col)
{
}

void TextFieldWidget1_OnFocusChanged(leTextFieldWidget* txt, leBool focused)
{
}

void ButtonWidget5_OnReleased(leButtonWidget* btn)
{
}

void ButtonWidget6_OnReleased(leButtonWidget* btn)
{
}

void ButtonWidget32_OnReleased(leButtonWidget* btn)
{
}


