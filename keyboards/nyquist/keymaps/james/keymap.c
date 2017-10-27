#include "nyquist.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _COLEMAK 1
#define _UPKEEP 2
#define _GAME 3
#define _LOWER 4
#define _RAISE 5
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  GAME,
  COLEMAK,
  UPKEEP,
  LOWER,
  RAISE,
  ADJUST,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------+   +-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+   +------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+------+   +------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+   +------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+   +------+------+------+------+------+------|
 * | Ctrl | PgDn | Alt  | GUI  |Lower |Space |   |Space |Raise | Adjust| alt | shift|RCtrl |
 * `-----------------------------------------+   +-----------------------------------------'
 */
[_QWERTY] = KEYMAP( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL, \
  KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT , \
  CTL_T(KC_HOME),   KC_PGDN,  ALT_T(KC_PGUP), GUI_T(KC_END), LOWER,   KC_SPC,  KC_SPC,  RAISE,  KC_LEFT,  MT(MOD_RALT, KC_DOWN), MT(MOD_RSFT, KC_UP), MT(MOD_RCTL, KC_RGHT) \
),

/* Gaming TODO update comments
 * ,-----------------------------------------+   +-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+   +------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+------+   +------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+   +------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+   +------+------+------+------+------+------|
 * | Ctrl | PgDn | Alt  | GUI  |Lower |Space |   |Space |Raise | Adjust| alt | shift|RCtrl |
 * `-----------------------------------------+   +-----------------------------------------'
 */
[_GAME] = KEYMAP( \
  _______,  _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______, \
  _______,  _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______, \
  _______,  _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______, \
  _______,  _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______, \
  KC_LCTL, LOWER, KC_LALT, KC_LALT, KC_SPC,  KC_SPC,  KC_SPC,  RAISE,  KC_LGUI,  MT(MOD_RALT, KC_DOWN), MT(MOD_RSFT, KC_UP), MT(MOD_RCTL, KC_RGHT) \
),

/* Colemak
 * ,-----------------------------------------+   +-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+   +------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   |   J  |   L  |   U  |   Y  |   ;  | Del  |
 * |------+------+------+------+------+------+   +------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------+   +------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+   +------+------+------+------+------+------|
 * | Ctrl |Adjust| Alt  | GUI  |Lower |Space |   |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------+   +-----------------------------------------'
 */
[_COLEMAK] = KEYMAP( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_DEL, \
  KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT , \
  CTL_T(KC_HOME),   KC_PGDN,  ALT_T(KC_PGUP), GUI_T(KC_END), LOWER,   KC_SPC,  KC_SPC,  RAISE,  MT(MOD_MEH, KC_LEFT),  MT(MOD_RALT, KC_DOWN), MT(MOD_RSFT, KC_UP), MT(MOD_RCTL, KC_RGHT) \
),

/* Maintenance/Upkeep layer
 * ,-----------------------------------------+   +----------------------------------------.
 * | Reset|RGB Tg|      |Qwerty|Colemk|Dvorak|   |     |      |      |      |      |      |
 * |------+------+------+------+------+------+   +-----+------+------+------+------+------|
 * |      |RGB Md|Hue Up|Sat Up|Val Up|      |   |     |      |      |      |      |      |
 * |------+------+------+------+------+------+   +-----+------+------+------+------+------|
 * |Qwerty|      |Hue Dn|Sat Dn|Val Dn|      |   |     |      |      |      |      |      |
 * |------+------+------+------+------+------+   +-----+------+------+------+------+------|
 * |      |      |      |      |      |      |   |     |      |      |      |      |      |
 * |------+------+------+------+------+------+   +-----+------+------+------+------+------|
 * |      |      |      |      |      |      |   |     |      |      |      |      |      |
 * `-----------------------------------------+   +----------------------------------------'
 */
[_UPKEEP] =  KEYMAP( \
  RESET,   RGB_TOG,   _______, QWERTY,  COLEMAK, GAME, _______, _______,  _______, _______, _______, _______, \
  _______, RGB_MOD,   RGB_HUI, RGB_SAI, RGB_VAI, _______, _______, _______,  _______, _______, _______, _______, \
  QWERTY,  _______,   RGB_HUD, RGB_SAD, RGB_VAD, _______, _______, _______,  _______, _______, _______, _______, \
  _______, _______,   _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, \
  _______, _______,   _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______ \
),

/* Lower (Math & Music): F-keys, Media keys, and numpad.
 * ,-----------------------------------------+  +-----------------------------------------.
 * |      | Prnt | Stop | Play | Next | Mute|  | Num  |   7  |   8  |   9  |   -  | Bksp |
 * |------+------+------+------+------+------+  +------+------+------+------+------+------|
 * |ROTab |X tab | L Tab|NewTab|RTab  | Vol+ |  |   %  |   4  |   5  |  6  |   +  | Del  |
 * |------+------+------+------+------+------+  +------+------+------+------+------+------|
 * | Del  |      |      |      |      | Vol- |  |   /  |   1  |  2   |  3   |   =  |  %   |
 * |------+------+------+------+------+------+  +------+------+------+------+------+------|
 * |      |      |      |      |      |      |  |   *  |   0  |  .   |   .  | Entr | Entr |
 * |------+------+------+------+------+------+  +------+------+------+------+------+------|
 * |      |      |      |      |      |      |  |      |      |      |      |      | RCTRL|
 * `-----------------------------------------+  +-----------------------------------------'
 */
[_LOWER] = KEYMAP( \
  _______, KC_PSCR, KC_MSTP, KC_MPLY,  KC_MNXT, KC_MUTE, KC_NLCK, KC_P7,   KC_P8,   KC_P9,  KC_PMNS, KC_BSPC, \
  LCTL(LSFT(KC_T)), LCTL(KC_W), LCTL(LSFT(KC_TAB)), LCTL(KC_T),  LCTL(KC_TAB), KC_VOLU, KC_PERC, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_DEL, \
  KC_DEL,  LCTL(KC_F), LGUI(LSFT(KC_P4)), LGUI(KC_D),  LGUI(LSFT(KC_P6)), KC_VOLD, KC_PSLS, KC_P1,   KC_P2,   KC_P3,   KC_PEQL, KC_PERC, \
  _______, _______, _______, _______,  _______, _______, KC_PAST, KC_P0,   KC_P0,   KC_PDOT,  KC_PENT, _______, \
  _______, _______, _______, _______,  _______, _______, _______,  _______, _______, _______,  _______, KC_RCTRL \
),


// WIP Ideas. maybe I won't do VIM style
/* Raise (Navigation and symbols Layer). TODO: Macros for left hand nav
 * ,-----------------------------------------+   +----------------------------------------.
 * |      |      |      |  M3  |      |      |   |     |      |      |      |      |      |
 * |------+------+------+------+------+------+   +-----+------+------+------+------+------|
 * |      |      |      |  \   |  |   |      |   |  _  |   -  |  +  |   =  |   \  |      |
 * |------+------+------+------+------+------+   +-----+------+------+------+------+------|
 * |      | HOME | PGDN | PGUP | END |  [   |    |  ]  |   ◀  |   ▼  |   ▲  |   ▶  | Alt  |
 * |------+------+------+------+------+------+   +-----+------+------+------+------+------|
 * |      |      |      |      |      |      |   |     |      |      |      |      |      |
 * |------+------+------+------+------+------+   +-----+------+------+------+------+------|
 * |      |      |      |      |      |      |   |     |      |      |      |      |      |
 * `-----------------------------------------+   +----------------------------------------'
 */
[_RAISE] = KEYMAP( \
  _______,  _______,  _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,   _______,   _______, \
  _______,  _______,  KC_BSLASH,  KC_PIPE,    _______,    _______,    KC_UNDS,    KC_MINS,    KC_PLUS,    KC_EQL,    KC_BSLS,    _______, \
  _______,  KC_HOME,  KC_PGDN,    KC_PGUP,    KC_END,     KC_LBRC,    KC_RBRC,    KC_LEFT,    KC_DOWN,    KC_UP,     KC_RIGHT,   KC_RCTRL, \
  _______,  _______,  _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,   _______,   _______, \
  _______,  _______,  _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,   _______,   _______ \
),

/* Adjust (Lower + Raise) TODO Implement comments
 * ,-----------------------------------------+   +-----------------------------------------.
 * |Qwerty|Colemk|UPkeep|GAME  |      |      |   |      |      |      |      |      |
 * |------+------+------+------+------+------+   +------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |      |   |      |  MvL | PgUp | MvR  |      |      |
 * |------+------+------+------+------+------+   +------+------+------+------+------+------|
 * | Del  |  F5  |  F6  |  F7  |  F8  |      |   |      | Home | PgDn |  End |      | Rctrl|
 * |------+------+------+------+------+------+   +------+------+------+------+------+------|
 * |      |  F9  |  F10 |  F11 |  F12 |      |   |      |      |      |      |      |      |
 * |------+------+------+------+------+------+   +------+------+------+------+------+------|
 * |      |      |      |      |      |      |   |      |      |      |      |      |      |
 * `-----------------------------------------+   +-----------------------------------------'
 */
[_ADJUST] =  KEYMAP( \
  QWERTY,   COLEMAK,   UPKEEP, GAME,  _______, _______, _______,   _______,  _______,   _______,  _______,  _______, \
  _______, KC_F1,     KC_F2,   KC_F3,   KC_F4, RGB_HUI, _______, LGUI(LSFT(KC_P4)),  KC_PGUP, LGUI(LSFT(KC_P6)), _______, _______, \
  KC_DEL,  KC_F5,     KC_F6,   KC_F7,   KC_F8, _______, _______, KC_HOME,  KC_PGDN, KC_END,  _______, KC_RCTRL, \
  _______, KC_F9,     KC_F10,  KC_F11,  KC_F12, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
)


};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_upkeep[][2]     = SONG(UPKEEP_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
float tone_game[][2]    = SONG(GAME_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_qwerty, false, 0);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_colemak, false, 0);
        #endif
        persistent_default_layer_set(1UL<<_COLEMAK);
      }
      return false;
      break;
    case UPKEEP:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_upkeep, false, 0);
        #endif
        persistent_default_layer_set(1UL<<_UPKEEP);
      }
      return false;
      break;
    case GAME:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_game, false, 0);
        #endif
        persistent_default_layer_set(1UL<<_GAME);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
