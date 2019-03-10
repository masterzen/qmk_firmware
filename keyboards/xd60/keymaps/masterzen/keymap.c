#include QMK_KEYBOARD_H
#include "action_layer.h"

enum layers
{
  BASE, // qwerty linux
  OSX,  // qwerty osx

  _FL, // function key layer
  _CL, // setup layer
};

enum keycodes
{
  // default layout switcher
  LAY_LIN = SAFE_RANGE,
  LAY_OSX
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* (Base Layer) Default Layer
   * ,-----------------------------------------------------------.
   * |Esc| 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =| Backsp |
   * |-----------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |
   * |-----------------------------------------------------------|
   * | CTRL |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '| Return |
   * |-----------------------------------------------------------|
   * |Shift  |  Z|  X|  C|  V|  B|  N|  M|  ,|  .| / |Shf|Up |FN |
   * |-----------------------------------------------------------|
   * |Ctrl|Gui |Alt |      Space           |Fn|AltG| LT| DN | RT |
   * `-----------------------------------------------------------'
   */

    // 0: Base Layer
    [BASE] = LAYOUT_all(
        KC_GRAVE, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_GRV,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
        CTL_T(KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_NO, LT(_FL,KC_ENT),
        KC_LSFT, KC_NO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, MT(MOD_RSFT,KC_SLSH), KC_RSFT, KC_UP, MO(_FL),
        KC_LCTL, KC_LGUI, KC_LALT, LT(_FL,KC_SPC), KC_RALT, KC_RCTRL, KC_LEFT, KC_DOWN, KC_RIGHT),

    // 1: OSX Layer
    [OSX] = LAYOUT_all(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, MO(_FL),
        KC_LCTL, KC_LALT, KC_LGUI, _______, KC_LGUI, KC_RALT, _______, _______, _______),

    /* Function Layer
   * ,-----------------------------------------------------------.
   * |`  | F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12| DEL   |
   * |-----------------------------------------------------------|
   * |  |RGBM|RGBVI|RGBHI|RGBSI|  |MUTE|VUP|VDO|  |BLD|BLU|BLS|  |
   * |-----------------------------------------------------------|
   * |    |RGBTOG|RGBVD|RGBHD|RGBSD| |<- |v |^ |->|  |   | enter |
   * |-----------------------------------------------------------|
   * |     |   |   |   |   |   |   |   |VDO|VUP|MUT|   |PGUP |   |
   * |-----------------------------------------------------------|
   * |   |    |    |      Space          |CL |   |HOME |PGDN|END |
   * `-----------------------------------------------------------'
   */

    // 1: Function Layer
    [_FL] = LAYOUT_all(
        KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL, KC_DEL,
        _______, RGB_MOD, RGB_VAI, RGB_HUI, RGB_SAI, _______, KC_MUTE, KC_VOLU, KC_VOLD, _______, _______, BL_DEC, BL_INC, BL_STEP,
        _______, RGB_TOG, RGB_VAD, RGB_HUD, RGB_SAD, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, _______, _______, KC_NO, KC_ENT,
        _______, KC_NO, _______, _______, _______, _______, _______, _______, _______, KC_VOLD, KC_VOLU, KC_MUTE, _______, KC_PGUP, MO(_FL),
        _______, _______, _______, KC_SPC, _______, MO(_CL), KC_HOME, KC_PGDOWN, KC_END),

    // 2: Control Layer
    [_CL] = LAYOUT_all(
        KC_ESC, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, DEBUG,
        LAY_LIN, LAY_OSX, _______, _______, RESET, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        LAY_LIN, LAY_OSX, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_NO, KC_ENT,
        _______, KC_NO, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PGUP, MO(_FL),
        _______, _______, _______, KC_SPC, _______, MO(_CL), KC_HOME, KC_PGDOWN, KC_END),

};

void persistent_default_layer_set(uint16_t default_layer)
{
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

#ifdef RGBLIGHT_ENABLE
extern rgblight_config_t rgblight_config;
#endif

bool edit = false;
uint32_t mode;
uint16_t hue;
uint8_t sat;
uint8_t val;

void matrix_init_user(void)
{
  #ifdef RGBLIGHT_ENABLE
  mode = rgblight_config.mode;
  #endif
  #ifdef UNICODE_ENABLE
  set_unicode_input_mode(UC_LNX);
  #endif
  // DDRB |= (1 << PB2);
  // PORTB &= ~(1 << PB2);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  switch (keycode)
  {
  /* layout switcher */
  case LAY_LIN:
    if (record->event.pressed)
    {
      persistent_default_layer_set(1UL << BASE);
    }
#ifdef UNICODE_ENABLE
    set_unicode_input_mode(UC_LNX);
#endif
    return false;
    break;
  case LAY_OSX:
    if (record->event.pressed)
    {
      persistent_default_layer_set(1UL << OSX);
    }
#ifdef UNICODE_ENABLE
    set_unicode_input_mode(UC_OSX);
#endif
    return false;
    break;
  case RGB_MOD:
    // allows to set the rgb mode while in the FL layer which uses
    // its own mode
    if (record->event.pressed)
    {
#ifdef RGBLIGHT_ENABLE
      rgblight_mode(mode);
      rgblight_step();
      mode = rgblight_config.mode;
#endif
    }
    return false;
    break;
  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state)
{
#ifdef RGBLIGHT_ENABLE
  if (state == BASE && edit == true)
  {
    hue = rgblight_get_hue();
    sat = rgblight_get_sat();
    val = rgblight_get_val();
    edit = false;
  }

  switch (biton32(state))
  {
  case _FL:
    mode = rgblight_get_mode();
    rgblight_mode_noeeprom(1);
    rgblight_setrgb(0xD3, 0x7F, 0xED);
    edit = true;
    break;
  case _CL:
    rgblight_mode_noeeprom(1);
    rgblight_setrgb(0x00, 0x00, 0xff);
    break;
  default:
    rgblight_mode(mode);
    rgblight_sethsv(hue, sat, val);
    break;
  }
#endif
  return state;
}

void led_set_user(uint8_t usb_led) {
}

void led_set_kb(uint8_t usb_led) {
}
