/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "muse.h"
#include "keymap_hungarian.h"

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _LAYER4
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  BACKLIT,
  LAYER_CLR,
  LAYER4,
};

#define LOWER OSL(_LOWER)
#define RAISE OSL(_RAISE)
#define LAYER4 TO(_LAYER4)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Z  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   É  |  Á   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |LShift|   Y  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  Up  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  Clr | Alt  | GUI  |Lower |    Space    |Raise |   -  | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
      KC_TAB,        HU_Q,          HU_W,          HU_E,    HU_R,    HU_T,    HU_Z,    HU_U,    HU_I,    HU_O,    HU_P,    KC_BSPC,
      KC_ESC,        HU_A,          HU_S,          HU_D,    HU_F,    HU_G,    HU_H,    HU_J,    HU_K,    HU_L,    HU_EACU, HU_AACU,
      OSM(MOD_LSFT), HU_Y,          HU_X,          HU_C,    HU_V,    HU_B,    HU_N,    HU_M,    HU_COMM, HU_DOT,  KC_UP,   KC_ENT ,
      OSM(MOD_LCTL), LAYER_CLR,     KC_LALT,       KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   HU_MINS, KC_LEFT, KC_DOWN, KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   '  |   "  |   +  |   !  |   %  |   /  |   =  |   (  |   )  | CapsL| Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |   \  |   |  |   ^  |   [  |  ]   |   `  |   *  |   $  |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   >  |   #  |   &  |   @  |  {   |   }  |   <  |   >  |   ;  | PgUp | P Scr|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Ins  | Home | PgDo | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    HU_TILD, HU_QUOT, HU_DQUO, HU_PLUS, HU_EXLM, HU_PERC, HU_SLSH, HU_EQL,   HU_LPRN,  HU_RPRN, KC_CAPS, KC_BSPC,
    KC_DEL,  HU_BSLS, HU_PIPE, HU_CIRC, HU_LBRC, HU_RBRC, HU_GRV,  HU_ASTR,  HU_DLR,   _______, _______, _______,
    _______, HU_RABK, HU_HASH, HU_AMPR, HU_AT,   HU_LCBR, HU_RCBR, HU_LABK,  HU_RABK,  HU_SCLN, KC_PGUP, KC_PSCR,
    _______, _______, _______, _______, _______, _______, _______, _______,  KC_INS,   KC_HOME, KC_PGDN, KC_END
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   0  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |Brite | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   ö  |   ü  |   ó  |   ú  |  í   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   ő  |   ű  |      | Vol+ | Mute |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      | Func |             |      | Play | Prev | Vol- | Next |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    HU_0,    HU_1,    HU_2,    HU_3,    HU_4,    HU_5,    HU_6,    HU_7,    HU_8,    HU_9,    BL_STEP, KC_BSPC,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   HU_ODIA, HU_UDIA, HU_OACU, HU_UACU, HU_IACU,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  HU_ODAC, HU_UDAC, _______, KC_VOLU, KC_MUTE,
    _______, _______, _______, _______, LAYER4,  _______, _______, _______, KC_MPLY, KC_MPRV, KC_VOLD, KC_MNXT
),

/* Func
 * ,-----------------------------------------------------------------------------------.
 * |   0  |   0  |   0  |   0  | BTN1 |   0  | WH Up| BTN1 | UP   | BTN2 |  0   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   0  |Accel2|Accel1|Accel0|   0  | WH Do| Left | Down | Right|  0   |  0   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   0  |   0  |   0  |   0  |   0  |   0  | BTN3 | BTN4 | BTN5 |  0   |  0   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      | Clr  |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LAYER4] = LAYOUT_planck_grid(
    HU_0,    HU_0,    HU_0,         HU_0,         KC_MS_BTN1,   HU_0,    KC_MS_WH_UP,   KC_MS_BTN1, KC_MS_UP,   KC_MS_BTN2,  HU_0,    _______,
    _______, HU_0,    KC_MS_ACCEL2, KC_MS_ACCEL1, KC_MS_ACCEL0, HU_0,    KC_MS_WH_DOWN, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, HU_0,    HU_0,
    _______, HU_0,    HU_0,         HU_0,         HU_0,         HU_0,    HU_0,          KC_MS_BTN3, KC_MS_BTN4, KC_MS_BTN5,  HU_0,    HU_0,
    _______, _______, _______,      _______,      LAYER_CLR,    _______, _______,       _______,    _______,    _______,     _______, _______
),
};


bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        #ifdef KEYBOARD_planck_rev5
          writePinLow(E6);
        #endif
      } else {
        unregister_code(KC_RSFT);
        #ifdef KEYBOARD_planck_rev5
          writePinHigh(E6);
        #endif
      }
      return false;
      break;
    case LAYER_CLR:
      layer_clear();
      clear_keyboard();
      break;
  }
  return true;
}

#ifdef AUDIO_ENABLE

float tone_my_startup[][2] = SONG(ODE_TO_JOY);
float tone_my_goodbye[][2] = SONG(ROCK_A_BYE_BABY);

float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);

float tone_audio_on[][2]   = SONG(CLOSE_ENCOUNTERS_5_NOTE);
float tone_music_on[][2]   = SONG(DOE_A_DEER);
float music_scale[][2]     = SONG(MUSIC_SCALE_SOUND);

float tone_caps_on[][2]    = SONG(CAPS_LOCK_ON_SOUND);
float tone_caps_off[][2]   = SONG(CAPS_LOCK_OFF_SOUND);
float tone_numlk_on[][2]   = SONG(NUM_LOCK_ON_SOUND);
float tone_numlk_off[][2]  = SONG(NUM_LOCK_OFF_SOUND);
float tone_scroll_on[][2]  = SONG(SCROLL_LOCK_ON_SOUND);
float tone_scroll_off[][2] = SONG(SCROLL_LOCK_OFF_SOUND);

void led_set_user(uint8_t usb_led)
{
    static uint8_t old_usb_led = 0;

    _delay_ms(10); // gets rid of tick

    if (!is_playing_notes())
    {
        if ((usb_led & (1<<USB_LED_CAPS_LOCK)) && !(old_usb_led & (1<<USB_LED_CAPS_LOCK)))
        {
                // If CAPS LK LED is turning on...
                PLAY_SONG(tone_caps_on);
        }
        else if (!(usb_led & (1<<USB_LED_CAPS_LOCK)) && (old_usb_led & (1<<USB_LED_CAPS_LOCK)))
        {
                // If CAPS LK LED is turning off...
                PLAY_SONG(tone_caps_off);
        }
        else if ((usb_led & (1<<USB_LED_NUM_LOCK)) && !(old_usb_led & (1<<USB_LED_NUM_LOCK)))
        {
                // If NUM LK LED is turning on...
                PLAY_SONG(tone_numlk_on);
        }
        else if (!(usb_led & (1<<USB_LED_NUM_LOCK)) && (old_usb_led & (1<<USB_LED_NUM_LOCK)))
        {
                // If NUM LED is turning off...
                PLAY_SONG(tone_numlk_off);
        }
        else if ((usb_led & (1<<USB_LED_SCROLL_LOCK)) && !(old_usb_led & (1<<USB_LED_SCROLL_LOCK)))
        {
                // If SCROLL LK LED is turning on...
                PLAY_SONG(tone_scroll_on);
        }
        else if (!(usb_led & (1<<USB_LED_SCROLL_LOCK)) && (old_usb_led & (1<<USB_LED_SCROLL_LOCK)))
        {
                // If SCROLL LED is turning off...
                PLAY_SONG(tone_scroll_off);
        }
    }

    old_usb_led = usb_led;
}

#endif /* AUDIO_ENABLE */


enum combo_events {
  YX_CUT,
  XC_COPY,
  CV_PASTE
};

const uint16_t PROGMEM cut_combo[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM copy_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM paste_combo[] = {KC_C, KC_V, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [YX_CUT] = COMBO_ACTION(cut_combo),
  [XC_COPY] = COMBO_ACTION(copy_combo),
  [CV_PASTE] = COMBO_ACTION(paste_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case YX_CUT:
      if (pressed){
        tap_code16(LCTL(KC_X));
      }
      break;
    case XC_COPY:
      if (pressed) {
        tap_code16(LCTL(KC_C));
      }
      break;
    case CV_PASTE:
      if (pressed) {
        tap_code16(LCTL(KC_V));
      }
      break;
  }
}
