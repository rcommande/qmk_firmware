#include "s65_x.h"
#include "action_layer.h"

#define _BL 0
#define _AL 1
#define _FL 2
#define _UL 3

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* 0: Main layer, swapped alt and GUI for Mac
   * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   * │ ESC │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │  0  │  -  │  =  │▒▒▒▒▒│BKSPC│DEL  │
   * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   * │ TAB │  Q  │  W  │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │  [  │  ]  │  \  │█████│END  │
   * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   * │CAPSL│  A  │  S  │  D  │  F  │  G  │  H  │  J  │  K  │  L  │  ;  │  '  │▒▒▒▒▒│ENTER│█████│PG_UP│
   * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   * │LSHFT│▒▒▒▒▒│  Z  │  X  │  C  │  V  │  B  │  N  │  M  │  ,  │  .  │  /  │▒▒▒▒▒│RSHFT│ UP  │PG_DN│
   * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   * │LCTRL│L_ALT│L_GUI│█████│█████│█████│ SPC │█████│█████│█████│R_ALT│ FN0 │ APP │LEFT │DOWN │RIGHT│
   * └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
   */

  /* 0: ANSI qwerty */
  [_BL] = ANSI_KEYMAP(
        F(3),   KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_DEL, \
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_END, \
        F(2),   KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,       KC_ENT,     KC_PGUP, \
        KC_LSFT,     KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,    KC_RSFT, KC_UP, KC_PGDN, \
        KC_LCTL, KC_LALT, KC_LGUI,            KC_SPC,            KC_RALT, MO(_FL), KC_RCTL, KC_LEFT, KC_DOWN, KC_RIGHT),


  /* 1: Locking arrow keys to WASD for when you need dedicated arrow keys
   *  ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *  │     │     │     │     │     │     │     │     │     │     │     │     │     │▒▒▒▒▒│▒▒▒▒▒│     │
   *  ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *  │     │     │ Up  │     │     │     │     │     │     │     │     │     │     │     │▒▒▒▒▒│     │
   *  ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *  │     │Left │Down │Right│     │     │     │     │     │     │     │     │▒▒▒▒▒│     │▒▒▒▒▒│     │
   *  ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *  │     │▒▒▒▒▒│     │     │     │     │     │     │     │     │     │     │▒▒▒▒▒│     │     │     │
   *  ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *  │     │     │     │█████│█████│█████│     │█████│█████│█████│     │     │     │     │     │     │
   *  └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
   */

  [_AL] = ANSI_KEYMAP(
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  \
      KC_TRNS, KC_TRNS, KC_UP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
      KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
      KC_TRNS, KC_TRNS, KC_TRNS,               KC_TRNS,                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

  /* 2: Fn layer
   *  ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *  │GRAVE│ F1  │ F2  │ F3  │ F4  │ F5  │ F6  │ F7  │ F8  │ F9  │ F10 │ F11 │ F12 │▒▒▒▒▒│▒▒▒▒▒│     │
   *  ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *  │     │ _AL │ Up  │     │     │     │     │     │PGUP │PGDWN│PRTSC│SCLCK│PAUSE│     │▒▒▒▒▒│     │
   *  ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *  │     │Left │Down │Right│     │     │Left │Down │ Up  │Right│     │     │▒▒▒▒▒│     │▒▒▒▒▒│     │
   *  ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *  │     │▒▒▒▒▒│_UL  │     │     │     │     │     │     │Home │ End │     │▒▒▒▒▒│     │Vol+ │     │
   *  ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *  │     │     │     │█████│█████│█████│     │█████│█████│█████│     │     │     │Mute │Vol- │Play │
   *  └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
   */

  [_FL] = ANSI_KEYMAP(
      KC_GRAVE, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS, KC_TRNS, \
      KC_TRNS, F(1), KC_UP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP, KC_PGDN, KC_PSCR, KC_SLCK, KC_PAUS, KC_TRNS, KC_TRNS, \
      KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_TRNS, KC_TRNS, KC_TRNS, \
      KC_TRNS, KC_TRNS, F(3), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_END, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLU, KC_TRNS, \
      KC_TRNS, KC_TRNS, KC_TRNS,               KC_TRNS,                KC_TRNS, KC_TRNS, KC_TRNS, KC_MUTE, KC_VOLD, KC_MPLY),

  /* 3: Locking layer for controlling the underglow
   *  ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *  │     │     │     │     │     │     │     │     │     │     │     │     │     │▒▒▒▒▒│▒▒▒▒▒│     │
   *  ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *  │     │     │     │     │     │     │     │     │     │     │     │     │     │     │▒▒▒▒▒│     │
   *  ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *  │     │ On  │Mode │     │     │     │     │     │     │     │     │     │▒▒▒▒▒│     │▒▒▒▒▒│     │
   *  ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *  │     │▒▒▒▒▒│     │Hue+ │Hue- │Sat+ │Sat- │Val+ │Val- │     │     │     │▒▒▒▒▒│     │▒▒▒▒▒│     │
   *  ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *  │     │     │     │█████│█████│█████│     │█████│█████│█████│     │     │     │     │     │     │
   *  └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
   */

  [_UL] = ANSI_KEYMAP(
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  \
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
      KC_TRNS, F(4), F(5), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
      KC_TRNS, KC_TRNS, F(6), F(7), F(8), F(9), F(10), F(11), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
      KC_TRNS, KC_TRNS, KC_TRNS,               KC_TRNS,                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
};

enum function_id {
  RGBLED_TOGGLE,
  RGBLED_STEP_MODE,
  RGBLED_INCREASE_HUE,
  RGBLED_DECREASE_HUE,
  RGBLED_INCREASE_SAT,
  RGBLED_DECREASE_SAT,
  RGBLED_INCREASE_VAL,
  RGBLED_DECREASE_VAL,
  SHIFT_ESC,
};

const uint16_t PROGMEM fn_actions[] = {
  [0]  = ACTION_LAYER_MOMENTARY(_FL),       // Momentary Fn overlay
  [1]  = ACTION_LAYER_TOGGLE(_AL),          // Toggle Arrow Layer overlay
  [2]  = ACTION_LAYER_TAP_KEY(_FL, KC_CAPS),// Tap to toggle caps lock and hold to activate function layer
  [3]  = ACTION_LAYER_TOGGLE(_UL),          // Toggle Underglow Layer overlay
  [4]  = ACTION_FUNCTION(RGBLED_TOGGLE),    // Turn on/off underglow
  [5]  = ACTION_FUNCTION(RGBLED_STEP_MODE), // Change underglow mode
  [6]  = ACTION_FUNCTION(RGBLED_INCREASE_HUE),
  [7]  = ACTION_FUNCTION(RGBLED_DECREASE_HUE),
  [8]  = ACTION_FUNCTION(RGBLED_INCREASE_SAT),
  [9]  = ACTION_FUNCTION(RGBLED_DECREASE_SAT),
  [10] = ACTION_FUNCTION(RGBLED_INCREASE_VAL),
  [11] = ACTION_FUNCTION(RGBLED_DECREASE_VAL),
  [12] = ACTION_FUNCTION(SHIFT_ESC),
};

void matrix_scan_user(void) {

  // Would like to do something like this, that would be cool
  // Turn off all the LEDs on except for the ones mapped on the UL layer, for example
  /* uint32_t layer = layer_state; */
  /* if (layer & (1<<1)) { */
  /*   gh60_wasd_leds_on(); */
  /* } else { */
  /*   gh60_wasd_leds_off(); */
  /* } */
  /*  */
  /* if (layer & (1<<2)) { */
  /*   gh60_esc_led_on(); */
  /* } else { */
  /*   gh60_esc_led_off(); */
  /* } */
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        register_code(KC_RSFT);
      } else {
        unregister_code(KC_RSFT);
      }
      break;
  }
  return MACRO_NONE;
};

#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))
void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  switch (id) {
    case RGBLED_TOGGLE:
      //led operations
      if (record->event.pressed) {
        rgblight_toggle();
      }
      break;
    case RGBLED_INCREASE_HUE:
      if (record->event.pressed) {
        rgblight_increase_hue();
      }
      break;
    case RGBLED_DECREASE_HUE:
      if (record->event.pressed) {
        rgblight_decrease_hue();
      }
      break;
    case RGBLED_INCREASE_SAT:
      if (record->event.pressed) {
        rgblight_increase_sat();
      }
      break;
    case RGBLED_DECREASE_SAT:
      if (record->event.pressed) {
        rgblight_decrease_sat();
      }
      break;
    case RGBLED_INCREASE_VAL:
      if (record->event.pressed) {
        rgblight_increase_val();
      }
      break;
    case RGBLED_DECREASE_VAL:
      if (record->event.pressed) {
        rgblight_decrease_val();
      }
      break;
    case RGBLED_STEP_MODE:
      if (record->event.pressed) {
        rgblight_step();
      }
      break;
      static uint8_t shift_esc_shift_mask;
      // Shift + ESC = ~
    case SHIFT_ESC:
      shift_esc_shift_mask = get_mods()&MODS_CTRL_MASK;
      if (record->event.pressed) {
        if (shift_esc_shift_mask) {
          add_key(KC_GRV);
          send_keyboard_report();
        } else {
          add_key(KC_ESC);
          send_keyboard_report();
        }
      } else {
        if (shift_esc_shift_mask) {
          del_key(KC_GRV);
          send_keyboard_report();
        } else {
          del_key(KC_ESC);
          send_keyboard_report();
        }
      }
      break;
  }
};
