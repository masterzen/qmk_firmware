
#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT_60_ansi_split_bs_rshift(
    KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, LT(2, KC_ESC),
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
    LCTL_T(KC_ESC), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, MO(1),
    KC_LALT, KC_NO, KC_LGUI,                                     LT(1, KC_SPC),                             KC_NO, KC_RGUI, KC_NO, KC_RALT
  ),
  [1] = LAYOUT_60_ansi_split_bs_rshift(
        KC_GRV,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, KC_INS, LT(2, KC_ESC),
        _______, _______, KC_UP, _______, _______, _______, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS, KC_UP, _______, _______,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, KC_PAST, KC_PSLS, KC_HOME, KC_PGUP, KC_LEFT, KC_RGHT, KC_PENT,
        _______, KC_MUTE, KC_VOLU, KC_VOLD, _______, _______, KC_PPLS, KC_PMNS, KC_END, KC_PGDN, KC_DOWN, _______, _______,
        _______, _______, _______,                                     _______,                            _______, _______, _______, _______
  ),
  [2] = LAYOUT_60_ansi_split_bs_rshift(
        RESET, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        BL_TOGG, BL_DEC, BL_INC, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, RGB_VAI, RGB_VAD, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,                                     _______,                            _______, _______, _______, _______
  ),

};
