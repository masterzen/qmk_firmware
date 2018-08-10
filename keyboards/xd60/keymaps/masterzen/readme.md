# Masterzen's Keymap for XIUDI's 60% XD60 PCB

This is a layout with a 2u shift and a block of arrow keys, as shown here:
http://www.keyboard-layout-editor.com/#/gists/cbf8e043e1bb03e98ae5f2e22616c1fb

## Additional Notes

The map supports both a linux and OSX base layer. It also switches the RGB underglow when in a custom layer and comes back correctly to the choosen mode.

The map has LCTRL as Caps Lock, and uses the multiple backlight pins feature to control the caps lock led as it was part of the backlight (which is possible because xd60 doesn't support hardware PWM on backlight pin).

## Build

To build my keymap, simply run `make xd60:masterzen`.
