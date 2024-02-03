/* Copyright 2015-2021 Jack Humbert
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

enum preonic_layers {
  _QWERTY,
  _L1,
  _L2,
  _SETT
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  L1,
  L2,
  SETT,
  BACKLIT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   1  |   2  |   3  |   4  |   5  |      |      |   6  |   7  |   8  |   9  |   0  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   Q  |   W  |   E  |   R  |   T  | VolD | VolU |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |   _  |   -  |   H  |   J  |   K  |   L  | Bksp |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  | Home |  End |   N  |   M  | ,  < | .  > | /  ? |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  ALT |   OS |  Esc | LShft|  TAB |  SPC | Enter|  L1  |   L2 | Menu | SETT |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_5x12(
  KC_1,    KC_2,    KC_3,    KC_4,   KC_5,    KC_NO,    KC_NO,    KC_6,     KC_7,    KC_8,    KC_9,    KC_0,
  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,    KC_VOLD,  KC_VOLU,  KC_Y,     KC_U,    KC_I,    KC_O,    KC_P,
  KC_A,    KC_S,    KC_D,    KC_F,   KC_G,    KC_UNDS,  KC_MINS,  KC_H,     KC_J,    KC_K,    KC_L,    KC_BSPC,
  KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,    KC_HOME,  KC_END,   KC_N,     KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
  KC_LCTL, KC_LALT, KC_LGUI, KC_ESC, KC_LSFT, KC_TAB,   KC_ENTER, KC_SPC,   L1,      L2,      KC_APP,  SETT
),

/* L1
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      | RESET| DEBUG|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | `  ~ |   @  |   #  |   $  |   %  |      |      | [  { | ]  } | \  | | -  _ | =  + |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   ^  |   &  |   *  |      |      |      |      |  (   |   )  | ;  : | '  " | Del  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |   !  | ,  < | .  > | /  ? |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  ALT |   OS |  Esc | LShft|  TAB | Enter|  SPC |  L1  |  L2  | Menu | SETT |
 * `-----------------------------------------------------------------------------------'
 */
[_L1] = LAYOUT_ortho_5x12(
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   EE_CLR,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  KC_GRV,  KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_NO,    KC_NO,    KC_LBRC, KC_RBRC, KC_BSLS, KC_MINS, KC_EQL,
  KC_CIRC, KC_AMPR, KC_ASTR, KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_LPRN, KC_RPRN, KC_SCLN, KC_QUOT, KC_DEL,
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,   KC_EXLM, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_LCTL, KC_LALT, KC_LGUI, KC_ESC,  KC_LSFT, KC_TAB,   KC_ENTER, KC_SPC,  L1,      L2,      KC_APP,  SETT
),

/* L2
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | LEFT | DOWN |  UP  | RGHT |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |   0  |  , < |  . > |  / ? |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  ALT |   OS |  Esc | LShft|  TAB |Enter |  SPC |  L1  |   L2 | Menu | SETT |
 * `-----------------------------------------------------------------------------------'
 */
[_L2] = LAYOUT_ortho_5x12(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,   KC_F6,    KC_F7,    KC_F8,      KC_F9,   KC_F10,   KC_F11,  KC_F12,
  KC_F5,   KC_F6,   KC_F7,   KC_F8,  KC_NO,   KC_NO,    KC_NO,    KC_NO,      KC_NO,   KC_NO,    KC_NO,   KC_NO,
  KC_F9,   KC_F10,  KC_F11,  KC_F12, KC_NO,   KC_NO,    KC_NO,    KC_LEFT,    KC_DOWN, KC_UP,    KC_RGHT, KC_NO,
  EE_CLR,  KC_NO,   KC_NO,   KC_NO,  KC_NO,   KC_NO,    KC_NO,    KC_NO,      KC_PGDN, KC_PGUP,  KC_NO,   KC_NO,
  KC_LCTL, KC_LALT, KC_LGUI, KC_ESC, KC_LSFT, KC_TAB,   KC_ENTER, KC_SPC,     L1,      L2,       KC_APP,  SETT
),

/* Settings
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      | RESET| DEBUG|      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  OS  |  Alt |      | LShft|    Space    | Enter|      |      |      | SETT |
 * `-----------------------------------------------------------------------------------'
 */
[_SETT] = LAYOUT_ortho_5x12(
  KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,    EE_CLR,  KC_NO,    KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,
  RGB_TOG,  KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,    KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,
  RGB_MOD,  RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI,  KC_NO,   KC_NO,    KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,
  RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD,  KC_NO,   KC_NO,    KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,
  KC_LCTL,  KC_LALT, KC_LGUI, KC_ESC,  KC_LSFT,  KC_TAB,  KC_ENTER, KC_SPC,   L1,     L2,     KC_APP, SETT
)


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
          }
          return false;
          break;
        case L1:
          if (record->event.pressed) {
            layer_on(_L1);
          } else {
            layer_off(_L1);
          }
          return false;
          break;
        case L2:
          if (record->event.pressed) {
            layer_on(_L2);
          } else {
            layer_off(_L2);
          }
          return false;
          break;
          case SETT:
          if (record->event.pressed) {
            layer_on(_SETT);
          } else {
            layer_off(_SETT);
          }
          return false;
          break;
      }
    return true;
};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_L2)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      register_code(KC_PGDN);
      unregister_code(KC_PGDN);
    } else {
      register_code(KC_PGUP);
      unregister_code(KC_PGUP);
    }
  }
    return true;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if (active) {
                layer_on(_L2);
            } else {
                layer_off(_L2);
            }
            break;
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
    return true;
}


void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case L2:
    case L1:
      return false;
    default:
      return true;
  }
}
