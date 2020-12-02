/* The bhipple layout for the Dactyl Manuform 5x6 Keyboard */
// clang-format: off
#include QMK_KEYBOARD_H

#define Colemak 0
#define NumPad 1
#define Macros 2
#define LeftIdx 3
#define RightIdx 4
#define Emacs 5
#define Tmux 6
#define Qwerty 7

// See here for generic keycodes:
// https://docs.qmk.fm/#/keycodes
enum my_keycodes {
    // New definitions
    M_CLEAR = SAFE_RANGE,
    M_COLON_B_D,
    M_COLON_S_P,
    M_COLON_V_S_P,
    M_EMACS_DOWN,
    M_EMACS_LEFT,
    M_EMACS_QUIT,
    M_EMACS_RIGHT,
    M_EMACS_SWITCH_BUF,
    M_EMACS_UP,
    M_EMACS_WA,
    M_EOL_BRACE,
    M_EOL_SEMICOLON,
    M_PASTE,
    M_SPC_B_B,
    M_SPC_G_S,
    M_SPC_G_STAR,
    M_SPC_J_J,
    M_SPC_P_H,
    M_SPC_P_P,
    M_SPC_R_T,
    M_SPC_G_SLASH,
};

// Define Aliases
#define D_BLUETOOTH  KC_WWW_SEARCH
#define D_PROGRAM    LWIN(KC_P)
#define D_TERMINAL   LWIN(KC_ENTER)

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Only do things on key presses, not lift ups
    if(!record->event.pressed) {
        return true;
    }

    switch (keycode) {
        case M_EMACS_LEFT:
            SEND_STRING(SS_TAP(X_ESCAPE) "wh\n");
            break;
        case M_EMACS_RIGHT:
            SEND_STRING(SS_TAP(X_ESCAPE) "wl\n");
            break;
        case M_EMACS_DOWN:
            SEND_STRING(SS_TAP(X_ESCAPE) "wj\n");
            break;
        case M_EMACS_UP:
            SEND_STRING(SS_TAP(X_ESCAPE) "wk\n");
            break;
        case M_EMACS_QUIT:
            SEND_STRING(":q\n");
            break;
        case M_EMACS_SWITCH_BUF:
            SEND_STRING(SS_LCTRL("x") "b");
            break;
        case M_EMACS_WA:
            SEND_STRING(":wa\n");
            break;
        case M_COLON_B_D:
            SEND_STRING(":bd\n");
            break;
        case M_COLON_S_P:
            SEND_STRING(":sp\n");
            break;
        case M_COLON_V_S_P:
            SEND_STRING(":vsp\n");
            break;
        case M_CLEAR:
            SEND_STRING("clear\n");
            break;
        case M_EOL_SEMICOLON:
            SEND_STRING(SS_TAP(X_ESCAPE) "A;");
            break;
        case M_SPC_B_B:
            SEND_STRING(" bb");
            break;
        case M_SPC_G_S:
            SEND_STRING(" gs");
            break;
        case M_SPC_G_STAR:
            SEND_STRING(" g*");
            break;
        case M_SPC_P_H:
            SEND_STRING(" ph");
            break;
        case M_SPC_P_P:
            SEND_STRING(" pp");
            break;
        case M_SPC_J_J:
            SEND_STRING(" jj");
            break;
        case M_SPC_G_SLASH:
            SEND_STRING(" g/");
            break;
        default:
            break;
    }
    return true;
}

#include "generated.h"
