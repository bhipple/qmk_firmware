#include QMK_KEYBOARD_H

enum my_keycodes {
    M_UNUSED = SAFE_RANGE,
    M_AUTOMERGE,
    M_DISPLAY_MD,
    M_BRKT_L_C,
    M_BRKT_R_C,
    M_CLEAR,
    M_COLON_CLOSE,
    M_COLON_DIFFGET,
    M_COLON_DIFFPUT,
    M_COLON_Q,
    M_COLON_QA,
    M_COLON_S_P,
    M_COLON_TABCLOSE,
    M_COLON_TABNEW,
    M_COLON_V_S_P,
    M_COLON_W,
    M_EMACS_DOWN,
    M_EMACS_LEFT,
    M_EMACS_RIGHT,
    M_EMACS_SWITCH_BUF,
    M_EMACS_UP,
    M_EOL_BRACE,
    M_EOL_SEMICOLON,
    M_gt,
    M_gT,
    M_PASTE,
    M_SPC_B_B,
    M_SPC_G_S,
    M_SPC_J_J,
    M_SPC_P_F,
    M_SPC_P_P,
    M_SPC_R_T,
    M_SPC_SLASH,
    M_SPC_STAR,
    M_TMUX_CREATE,
    M_TMUX_DELETE,
    M_TMUX_DOWN,
    M_TMUX_FILE,
    M_TMUX_GIT,
    M_TMUX_LAYOUT_H,
    M_TMUX_LEFT,
    M_TMUX_LIST_WINDOWS,
    M_TMUX_NEXT,
    M_TMUX_PASTE,
    M_TMUX_PREV,
    M_TMUX_RERUN,
    M_TMUX_RIGHT,
    M_TMUX_SCROLL,
    M_TMUX_SEARCH,
    M_TMUX_SPLIT,
    M_TMUX_SWAP_PANES,
    M_TMUX_VSPLIT,
    M_TMUX_WINDOW_1,
    M_TMUX_WINDOW_2,
    M_TMUX_WINDOW_3,
    M_TMUX_WINDOW_4,
    M_TMUX_WINDOW_5,
    M_TMUX_WINDOW_6,
    M_TMUX_WINDOW_7,
    M_TMUX_WINDOW_8,
    M_TMUX_WINDOW_9,
    M_TMUX_WINDOW_LEFT,
    M_TMUX_WINDOW_RIGHT,
    M_TMUX_ZOOM,
};

bool generated_keycode_process(uint16_t keycode) {
    switch (keycode) {
        case M_AUTOMERGE:
            SEND_STRING("[automerge]");
            break;
        case M_DISPLAY_MD:
            SEND_STRING("display(Markdown(f'# '))");
            break;
        case M_BRKT_L_C:
            SEND_STRING("[c");
            break;
        case M_BRKT_R_C:
            SEND_STRING("]c");
            break;
        case M_CLEAR:
            SEND_STRING("clear\n");
            break;
        case M_COLON_CLOSE:
            SEND_STRING(":close\n");
            break;
        case M_COLON_DIFFGET:
            SEND_STRING(":diffget\n");
            break;
        case M_COLON_DIFFPUT:
            SEND_STRING(":diffput\n");
            break;
        case M_COLON_Q:
            SEND_STRING(":q\n");
            break;
        case M_COLON_QA:
            SEND_STRING(":qa\n");
            break;
        case M_COLON_S_P:
            SEND_STRING(":sp\n");
            break;
        case M_COLON_TABCLOSE:
            SEND_STRING(":tabclose\n");
            break;
        case M_COLON_TABNEW:
            SEND_STRING(":tabnew\n");
            break;
        case M_COLON_V_S_P:
            SEND_STRING(":vsp\n");
            break;
        case M_COLON_W:
            SEND_STRING(":w\n");
            break;
        case M_EMACS_DOWN:
            SEND_STRING(SS_TAP(X_ESCAPE) " wj\n");
            break;
        case M_EMACS_LEFT:
            SEND_STRING(SS_TAP(X_ESCAPE) " wh\n");
            break;
        case M_EMACS_RIGHT:
            SEND_STRING(SS_TAP(X_ESCAPE) " wl\n");
            break;
        case M_EMACS_SWITCH_BUF:
            SEND_STRING(SS_LCTL("x") "b");
            break;
        case M_EMACS_UP:
            SEND_STRING(SS_TAP(X_ESCAPE) " wk\n");
            break;
        case M_EOL_BRACE:
            SEND_STRING(SS_TAP(X_ESCAPE) "A{");
            break;
        case M_EOL_SEMICOLON:
            SEND_STRING(SS_TAP(X_ESCAPE) "A;");
            break;
        case M_gt:
            SEND_STRING("gt");
            break;
        case M_gT:
            SEND_STRING("gT");
            break;
        case M_PASTE:
            SEND_STRING(SS_LSFT(SS_TAP(X_INSERT)));
            break;
        case M_SPC_B_B:
            SEND_STRING(" bb");
            break;
        case M_SPC_G_S:
            SEND_STRING(" gs");
            break;
        case M_SPC_J_J:
            SEND_STRING(" jj");
            break;
        case M_SPC_P_F:
            SEND_STRING(" pf");
            break;
        case M_SPC_P_P:
            SEND_STRING(" pp");
            break;
        case M_SPC_R_T:
            SEND_STRING(" rt");
            break;
        case M_SPC_SLASH:
            SEND_STRING(" /");
            break;
        case M_SPC_STAR:
            SEND_STRING(" *");
            break;
        case M_TMUX_CREATE:
            SEND_STRING(SS_LCTL("b") "c");
            break;
        case M_TMUX_DELETE:
            SEND_STRING(SS_LCTL("b") "x");
            break;
        case M_TMUX_DOWN:
            SEND_STRING(SS_LCTL("j"));
            break;
        case M_TMUX_FILE:
            SEND_STRING(SS_LCTL("bf"));
            break;
        case M_TMUX_GIT:
            SEND_STRING(SS_LCTL("bg"));
            break;
        case M_TMUX_LAYOUT_H:
            SEND_STRING(SS_LCTL("b") ":selectl even-horizontal\n");
            break;
        case M_TMUX_LEFT:
            SEND_STRING(SS_LCTL("h"));
            break;
        case M_TMUX_LIST_WINDOWS:
            SEND_STRING(SS_LCTL("b") "w");
            break;
        case M_TMUX_NEXT:
            SEND_STRING(SS_LCTL("b") "n");
            break;
        case M_TMUX_PASTE:
            SEND_STRING(SS_LCTL("b") "]");
            break;
        case M_TMUX_PREV:
            SEND_STRING(SS_LCTL("b") "p");
            break;
        case M_TMUX_RERUN:
            SEND_STRING("!!");
            break;
        case M_TMUX_RIGHT:
            SEND_STRING(SS_LCTL("l"));
            break;
        case M_TMUX_SCROLL:
            SEND_STRING(SS_LCTL("b") "[");
            break;
        case M_TMUX_SEARCH:
            SEND_STRING(SS_LCTL("b") "/");
            break;
        case M_TMUX_SPLIT:
            SEND_STRING(SS_LCTL("b") SS_LSFT("'"));
            break;
        case M_TMUX_SWAP_PANES:
            SEND_STRING(SS_LCTL("b") "o");
            break;
        case M_TMUX_VSPLIT:
            SEND_STRING(SS_LCTL("b") "%");
            break;
        case M_TMUX_WINDOW_1:
            SEND_STRING(SS_LCTL("b") "1");
            break;
        case M_TMUX_WINDOW_2:
            SEND_STRING(SS_LCTL("b") "2");
            break;
        case M_TMUX_WINDOW_3:
            SEND_STRING(SS_LCTL("b") "3");
            break;
        case M_TMUX_WINDOW_4:
            SEND_STRING(SS_LCTL("b") "4");
            break;
        case M_TMUX_WINDOW_5:
            SEND_STRING(SS_LCTL("b") "5");
            break;
        case M_TMUX_WINDOW_6:
            SEND_STRING(SS_LCTL("b") "6");
            break;
        case M_TMUX_WINDOW_7:
            SEND_STRING(SS_LCTL("b") "7");
            break;
        case M_TMUX_WINDOW_8:
            SEND_STRING(SS_LCTL("b") "8");
            break;
        case M_TMUX_WINDOW_9:
            SEND_STRING(SS_LCTL("b") "9");
            break;
        case M_TMUX_WINDOW_LEFT:
            SEND_STRING(SS_LCTL("b") "h");
            break;
        case M_TMUX_WINDOW_RIGHT:
            SEND_STRING(SS_LCTL("b") "l");
            break;
        case M_TMUX_ZOOM:
            SEND_STRING(SS_LCTL("b") "z");
            break;
        default:
            break;
    }

    return true;
}


enum layers{
  Colemak, NumPad, Macros, Idx, Editor, Tmux, Qwerty
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {



[Colemak] = LAYOUT_voyager(KC_GRAVE, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINUS, KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y, KC_QUOT, KC_BACKSLASH, OSL(Macros), MT(MOD_LCTL, KC_A), MT(MOD_LALT, KC_R), MT(MOD_LGUI, KC_S), LT(Idx, KC_T), KC_G, KC_K, LT(Idx, KC_N), MT(MOD_RGUI, KC_E), MT(MOD_RALT, KC_I), MT(MOD_RCTL, KC_O), KC_SCLN, KC_LEFT_SHIFT, LT(NumPad, KC_Z), LT(Tmux, KC_X), LT(Editor, KC_C), KC_D, KC_V, KC_M, KC_H, LT(Editor, KC_COMM), LT(Tmux, KC_DOT), LT(NumPad, KC_SLSH), KC_RIGHT_SHIFT, KC_INT2, KC_SPACE, KC_NO, KC_NO),

[NumPad] = LAYOUT_voyager(KC_ESCAPE, KC_1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, _______, _______, _______, KC_LT, KC_GT, _______, _______, KC_7, KC_8, KC_9, KC_ASTERISK, KC_F12, KC_MINUS, KC_PLUS, KC_EQUAL, KC_LBRC, KC_RBRC, _______, _______, KC_4, KC_5, KC_6, KC_PLUS, _______, _______, _______, _______, KC_LEFT_CURLY_BRACE, KC_RIGHT_CURLY_BRACE, _______, KC_0, KC_1, KC_2, KC_3, _______, _______, KC_INT2, KC_SPACE, KC_NO, KC_NO),

[Macros] = LAYOUT_voyager(_______, KC_F11, KC_F12, KC_F13, KC_F14, KC_F15, KC_F16, KC_F17, KC_F18, KC_F19, KC_F20, KC_RIGHT_CTRL, _______, TO(Qwerty), TO(Colemak), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, M_PASTE, KC_ESCAPE, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, _______, M_EOL_SEMICOLON, _______, _______, _______, _______, _______, _______, D_BLUETOOTH_CON, KC_KB_MUTE, KC_KB_VOLUME_DOWN, KC_KB_VOLUME_UP, D_BLUETOOTH_DISC, QK_BOOTLOADER, KC_INT2, KC_SPACE, KC_NO, KC_NO),

[Idx] = LAYOUT_voyager(_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, D_PROGRAM, _______, _______, D_TERMINAL, _______, _______, _______, _______, _______, M_AUTOMERGE, _______, KC_ENTER, KC_BACKSPACE, _______, _______, KC_SPACE, KC_ENTER, KC_ESCAPE, _______, _______, _______, _______, _______, M_CLEAR, M_DISPLAY_MD, _______, _______, _______, _______, _______, _______, _______, KC_INT2, KC_SPACE, KC_NO, KC_NO),

[Editor] = LAYOUT_voyager(_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, M_COLON_Q, M_COLON_W, _______, M_SPC_P_P, M_COLON_DIFFPUT, M_BRKT_R_C, KC_F1, KC_F2, KC_F3, KC_F4, _______, _______, M_COLON_DIFFGET, M_SPC_R_T, _______, _______, M_SPC_STAR, M_BRKT_L_C, M_gT, M_gt, M_EMACS_RIGHT, _______, _______, _______, _______, _______, M_COLON_TABNEW, M_COLON_CLOSE, M_COLON_V_S_P, _______, M_SPC_P_F, _______, _______, M_SPC_SLASH, _______, KC_INT2, KC_SPACE, KC_NO, KC_NO),

[Tmux] = LAYOUT_voyager(_______, M_TMUX_WINDOW_1, M_TMUX_WINDOW_2, M_TMUX_WINDOW_3, M_TMUX_WINDOW_4, M_TMUX_WINDOW_5, M_TMUX_WINDOW_6, M_TMUX_WINDOW_7, M_TMUX_WINDOW_8, M_TMUX_WINDOW_9, _______, _______, _______, _______, M_TMUX_LIST_WINDOWS, M_TMUX_FILE, M_TMUX_LAYOUT_H, _______, _______, M_TMUX_WINDOW_LEFT, M_TMUX_WINDOW_RIGHT, _______, M_TMUX_SWAP_PANES, _______, _______, _______, M_TMUX_RERUN, M_TMUX_SPLIT, M_TMUX_SCROLL, M_CLEAR, M_TMUX_LEFT, M_TMUX_PREV, M_TMUX_NEXT, M_TMUX_RIGHT, _______, _______, _______, M_TMUX_ZOOM, _______, M_TMUX_CREATE, M_TMUX_DELETE, M_TMUX_VSPLIT, _______, _______, _______, _______, M_TMUX_SEARCH, _______, KC_INT2, KC_SPACE, KC_NO, KC_NO),

[Qwerty] = LAYOUT_voyager(KC_ESCAPE, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINUS, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BACKSLASH, OSL(Macros), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_LEFT_SHIFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, TO(Colemak), KC_INT2, KC_SPACE, KC_NO, KC_NO),

};

