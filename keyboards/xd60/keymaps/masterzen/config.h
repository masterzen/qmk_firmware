#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "config_common.h"

// B2 is Caps Lock, but in my keymap this is CTRL
// and I want the caps lock led to be lit at the same
// level as the other backlight leds./
#define BACKLIGHT_LED_COUNT 2
#undef BACKLIGHT_PIN
#define BACKLIGHT_PINS { F5, B2 }

#endif