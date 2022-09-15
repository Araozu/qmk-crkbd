/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include <stdio.h>

/* _DVO
 *
 * TAB w q b p k   x l c h f DEL
 *  '  a o e i ñ   j r t n s  ´
 *  +  - y g u .   , d m v z ESC
 *
 */

/* _NUM
 *
 * TAB 1 2 3 4 5   6 7 8 9 0 DEL
 * SFT «     »       ← ↓   → GUI
 * CTL                       ESC
 *
 */

/* _SYM
 *
 * TAB ! " # $ %   / ( ) & = DEL
 * SFT | ~ < > ¿   ¡ { } [ ] GUI
 * CTL                       ESC
 *
 */

// TODO: `


// Custom dvorak
#define _DVO 0
// Standard qwerty
#define _QWE 1
// Numbers layer
#define _NUM 2
// Symbols layer
#define _SYM 3
// Functions layer
#define _FUN 4


// Mod tap left
#define LWINMOD   LGUI_T(KC_SLSH)  // GUI
#define LALTMOD   LALT_T(KC_Y)     // ALT
#define LSFTMOD   LSFT_T(KC_G)     // SHIFT
#define LCTRMOD   LCTL_T(KC_U)     // CTRL
#define LALTGRMOD RALT_T(KC_DOT)   // RALT


// Mod tap right
#define RALTGRMOD RALT_T(KC_COMM) // RALT
#define RCTRMOD   LCTL_T(KC_D)    // CTRL
#define RSFTMOD   LSFT_T(KC_M)    // SHIFT
#define RALTMOD   LALT_T(KC_V)    // ALT
#define RWINMOD   LGUI_T(KC_Z)    // GUI


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /**
                      ▀██                                   ▀██
      ▄▄▄▄          ▄▄ ██  ▄▄▄▄ ▄▄▄   ▄▄▄   ▄▄▄ ▄▄   ▄▄▄▄    ██  ▄▄
    ▄█▄▄▄██       ▄▀  ▀██   ▀█▄  █  ▄█  ▀█▄  ██▀ ▀▀ ▀▀ ▄██   ██ ▄▀
    ██       ████ █▄   ██    ▀█▄█   ██   ██  ██     ▄█▀ ██   ██▀█▄
     ▀█▄▄▄▀       ▀█▄▄▀██▄    ▀█     ▀█▄▄█▀ ▄██▄    ▀█▄▄▀█▀ ▄██▄ ██▄

     */
  [_DVO] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_B,    KC_P,    KC_K,                         KC_X,    KC_L,    KC_C,    KC_H,    KC_F, KC_LBRC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_MINS,    KC_A,    KC_O,    KC_E,    KC_I, KC_SCLN,                         KC_J,    KC_R,    KC_T,    KC_N,    KC_S, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_RBRC, LWINMOD, LALTMOD, LSFTMOD, LCTRMOD,LALTGRMOD,                   RALTGRMOD, RCTRMOD, RSFTMOD, RALTMOD, RWINMOD,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                C(KC_TAB),LT(_NUM, KC_TAB),  KC_SPC,    KC_BSPC,LT(_SYM, KC_ENT),A(KC_TAB)
                                      //`--------------------------'  `--------------------------'
  ),


  /*                                       ▄
      ▄▄▄ ▄  ▄▄▄ ▄▄▄ ▄▄▄   ▄▄▄▄  ▄▄▄ ▄▄  ▄██▄   ▄▄▄▄ ▄▄▄
    ▄▀   ██   ██  ██  █  ▄█▄▄▄██  ██▀ ▀▀  ██     ▀█▄  █
    █▄   ██    ███ ███   ██       ██      ██      ▀█▄█
    ▀█▄▄▀██     █   █     ▀█▄▄▄▀ ▄██▄     ▀█▄▀     ▀█
         ██                                     ▄▄ █
        ▀▀▀▀                                     ▀▀
   */
  [_QWE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_LGUI,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT,MO(_NUM),  KC_SPC,     KC_ENT,MO(_SYM), KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),


  /*
    ▄▄ ▄▄▄   ▄▄▄ ▄▄▄  ▄▄ ▄▄ ▄▄
     ██  ██   ██  ██   ██ ██ ██
     ██  ██   ██  ██   ██ ██ ██
    ▄██▄ ██▄  ▀█▄▄▀█▄ ▄██ ██ ██▄
   */
  [_NUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, KC_HOME, KC_PGDN, KC_PGUP,  KC_END,  KC_INS,                       KC_DEL, KC_LEFT, KC_DOWN,  KC_UP, KC_RIGHT, KC_LGUI,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, G(KC_1), G(KC_2), G(KC_3), G(KC_4), G(KC_5),                      XXXXXXX,KC_MEDIA_PREV_TRACK,KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_MEDIA_NEXT_TRACK,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT, _______,  KC_SPC,     KC_ENT,MO(_FUN), KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),


  /*
     ▄▄▄▄   ▄▄▄▄ ▄▄▄ ▄▄ ▄▄ ▄▄
    ██▄ ▀    ▀█▄  █   ██ ██ ██
    ▄ ▀█▄▄    ▀█▄█    ██ ██ ██
    █▀▄▄█▀     ▀█    ▄██ ██ ██▄
            ▄▄ █
             ▀▀
   */
  [_SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, KC_EXLM,  KC_AT,RALT(KC_3), KC_DLR, KC_PERC,                      KC_AMPR, KC_ASTR, KC_LPRN, KC_CIRC, KC_RPRN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_LSFT,RALT(KC_1),RALT(KC_4),KC_NUBS,S(KC_NUBS),KC_EQL,                XXXXXXX,RALT(KC_QUOT),RALT(KC_BSLS),RALT(KC_LBRC),RALT(KC_RBRC),KC_LGUI,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT,MO(_FUN),  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),


  /*
      ▄▀█▄
    ▄██▄   ▄▄▄ ▄▄▄  ▄▄ ▄▄▄
     ██     ██  ██   ██  ██
     ██     ██  ██   ██  ██
    ▄██▄    ▀█▄▄▀█▄ ▄██▄ ██▄
   */
  [_FUN] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,  KC_F11, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_F12, KC_LGUI,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,DF(_QWE),                     DF(_DVO), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  )
};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}
#endif // OLED_ENABLE
