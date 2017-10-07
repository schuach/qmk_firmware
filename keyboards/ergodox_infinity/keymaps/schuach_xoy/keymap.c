#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "keymap_german.h"
#undef LEADER_TIMEOUT
#define LEADER_TIMEOUT 500

#define XOY  0   // default layer
#define QWERT 1 // qwertz
#define MOD3 2   // Neo Mod3
#define MOD4 3   // Neo Mod4
#define FN 4     // Function and Media Keys
#define MDIA 5     // Media and Mouse

// Dual role keys (LAYER_KC) and modified keys
#define MDIA_Z LT(MDIA, DE_Z)
#define CTL_F  CTL_T(DE_F)
#define ALT_SPC LALT(KC_SPC)
#define ALT_TAB LALT(KC_TAB)
#define SALT_TB S(LALT(KC_TAB))

#define ______ KC_TRNS

// macros
#define ND_CARET M(2) // non-dead caret
#define ND_BTCK M(3) // non-dead backtick

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

enum {
  TD_CPC = 0
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |Cp/Pst/C|   1  |   2  |   3  |   4  |   5  |  FN  |           | KRun |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   X  |   .  |   O  |   ,  |   Y  |  (   |           |  *)  |   V  |   G  |   C  |   L  |   J  |   ß    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |Esc/Ctrl|   H  |   A  |   E  |   I  |   U  |------|           |------|   D  |   T  |   R  |   N  |   S  |Ctl/F   |
 * |--------+------+------+------+------+------|  [   |           |  *]  |------+------+------+------+------+--------|
 * | Leader |   K  |   Q  |   Ä  |   Ü  |   Ö  |      |           |      |   B  |   P  |   W  |   M  |MDIA/Z|RSft/Rtn|
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Leader|   <  |   >  | lAlt | Del  |                                       | Bspc | Left | Down |  Up  |Right |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | lAlt | LGui |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Pgup |       | Home |        |      |
 *                                 | Mod4 | Lsft |------|       |------|  Mod3  | Spc  |
 *                                 |      |      | Pgdn |       | End  |        |      |
 *                                 `--------------------'       `----------------------'
 */
  [XOY] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        TD(TD_CPC),   DE_1,    DE_2,    DE_3,    DE_4,    DE_5,    OSL(FN),
        KC_TAB,       DE_X,    DE_DOT,  DE_O,    DE_COMM, DE_Y,    DE_LPRN,
        CTL_T(KC_ESC),DE_H,    DE_A,    DE_E,    DE_I,    DE_U,
        KC_LEAD,      DE_K,    DE_Q,    DE_AE,   DE_UE,   DE_OE,   DE_LBRC,
        KC_LEAD,      DE_LESS, DE_MORE, KC_LALT, KC_DEL,
        // left thumb
                                                    OSM(MOD_LALT), KC_LGUI,
                                                                   KC_PGUP,
                                            TT(MOD4),  KC_LSFT,    KC_PGDN,

        // right hand
        ALT_SPC, DE_6,    DE_7,    DE_8,    DE_9,    DE_0,    DE_MINS,
        DE_RPRN, DE_V,    DE_G,    DE_C,    DE_L,    DE_J,    DE_SS,
                 DE_D,    DE_T,    DE_R,    DE_N,    DE_S,    CTL_F,
        DE_RBRC, DE_B,    DE_P,    DE_W,    DE_M,    MDIA_Z,  SFT_T(KC_ENT),
                 KC_BSPC, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
        // right thumb
        OSM(MOD_RALT), CTL_T(KC_ESC),
        KC_HOME,
        KC_END,        OSL(MOD3),   KC_SPC

    ),
/* Keymap 1: QWERT
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Esc    |  1   |  2   |  3   |  4   |  5   | FN   |           |      |  6   |  7   |  8   |  9   |  0   |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |  Q   |  W   |  E   |  R   |  T   |      |           |      |  Z   |  U   |  I   |  O   |  P   |   Ü    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | CAPS   |  A   |  S   |  D   |  F   |  G   |------|           |------|  H   |  J   |  K   |  L   |  Ö   |   Ä    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Lshft  |  Y   |  X   |  C   |  V   |  B   |      |           |      |  N   |  M   |  ,   |  .   |  -   |Rsft/Ret|
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Lctl |  Gui |      |  Lalt|  Del |                                       | Bspc | Left | Down | Up   | Right|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Mod 4| Gui  |       | Ralt |Ctl/Es|
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | Pgup |       | Home |      |      |
 *                                 | Spc  | Shft |------|       |------| Mod 3| Spc  |
 *                                 |      |      | Pgdn |       | End  |      |      |
 *                                 `--------------------'       `--------------------'
 */
  [QWERT] = LAYOUT_ergodox(  // layer 1 : qwertz, should not be accessible from layer 0
        // left hand
        KC_ESC,       DE_1,    DE_2,    DE_3,    DE_4,    DE_5,    OSL(FN),
        KC_TAB,       DE_Q,    DE_W,    DE_E,    DE_R,    DE_T,    ______,
        KC_CAPS,      DE_A,    DE_S,    DE_D,    DE_F,    DE_G,
        KC_LSFT,      DE_Y,    DE_X,    DE_C,    DE_V,    DE_B,   ______,
        KC_LCTL,      KC_LGUI, KC_NO,   KC_LALT, KC_DEL,
        // left thumb
                                                        TT(MOD4),  KC_LGUI,
                                                                   KC_PGUP,
                                          KC_SPC,  SFT_T(KC_DEL),  KC_PGDN,

        // right hand
        ______,  DE_6,    DE_7,    DE_8,    DE_9,    DE_0,    DE_MINS,
        ______,  DE_Z,    DE_U,    DE_I,    DE_O,    DE_P,    DE_UE,
                 DE_H,    DE_J,    DE_K,    DE_L,    DE_OE,   CTL_T(DE_AE),
        ______,  DE_B,    DE_P,    DE_W,    DE_M,    DE_Z,    SFT_T(KC_ENT),
        KC_BSPC, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
        // right thumb
        KC_RALT, CTL_T(KC_ESC),
        KC_HOME,
        KC_END,  OSL(MOD3),   KC_SPC

    ),

/* Keymap 2: Mod 3
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      | '      |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |  _   |  [   |  ]   |  ^   |      |           |      |   !  |   <  |  >   |  =   |  &   | `      |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  \   |  /   |  {   |  }   |  *   |------|           |------|   ?  |   (  |  )   |  -   |  :   |   @    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  #   |  $   |  |   |  ~   |  `   |      |           |      |   €  |   %  |  "   |  '   |  ;   |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|XXXXXX|      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[MOD3] = LAYOUT_ergodox(
       // left hand
      ______,  ______,  ______,  ______,  ______,  ______,  ______,
      ______,  ______,  DE_UNDS, DE_LBRC, DE_RBRC, ND_CARET,______,
      ______,  DE_BSLS, DE_SLSH, DE_LCBR, DE_RCBR, DE_ASTR,
      ______,  DE_HASH, DE_DLR,  DE_PIPE, DE_TILD, ND_BTCK,  ______,
      ______,  ______,  ______,  ______,  ______,
                                                   ______,  ______,
                                                            ______,
                                          ______,  ______,  ______,

      // right hand
      ______,  ______,  ______,  ______,  ______,  ______,  DE_ACUT,
      ______,  DE_EXLM, DE_LESS, DE_MORE, DE_EQL,  DE_AMPR, DE_GRV,
               DE_QST,  DE_LPRN, DE_RPRN, DE_MINS, DE_COLN, DE_AT,
      ______,  DE_EURO, DE_PERC, DE_DQOT, DE_QUOT, DE_SCLN, ______,
      ______,  ______,  ______,  ______,  ______,
      ______,  ______,
      ______,
      ______,  ______,  ______
),
/* Keymap 3: Mod 4
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |  =   |  /   |  *   |  -   |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        | Pgup | Bspc | Up   | Del  | Pgdn |      |           |      |      | Pad7 | Pad8 | Pad9 |  +   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | Home | Left | Down | Right| End  |------|           |------|      | Pad4 | Pad5 | Pad6 |  ,   |   .    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | Esc  | Tab  | Ins  | Ret  | Undo |      |           |      |   :  | Pad1 | Pad2 | Pad3 |  ;   |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       | Pad0 |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |XXXXXX|      |------|       |------|Space | Pad0 |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MOD 4
  [MOD4] = LAYOUT_ergodox(
        // left hand
        ______,  ______,  ______,  ______,  ______,  ______,  ______,
        ______,  KC_PGUP, KC_BSPC, KC_UP,   KC_DEL,  KC_PGDN, ______,
        ______,  KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,
        ______,  KC_ESC,  KC_TAB,  KC_INS,  KC_PENT, KC_UNDO, ______,
        ______,  ______,  ______,  ______,  ______,
        ______,  ______,
        ______,
        ______,  ______,  ______,

        // right hand
        ______,  ______,  KC_PEQL, KC_PSLS, KC_PAST, KC_PMNS, ______,
        ______,  ______,  KC_P7,   KC_P8,   KC_P9,   KC_PPLS, ______,
                 ______,  KC_4,    KC_P5,   KC_P6,   KC_COMM, KC_DOT,
        ______,  DE_COLN, KC_P1,   KC_P2,   KC_P3,   DE_SCLN, KC_PENT,
                          KC_P0,   ______,  ______,  ______,  ______,
        ______,  ______,
        ______,
        ______,  KC_SPC,  KC_P0
 ),
/* Keymap 4: Function Keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |Version |  F1  |  F2  |  F3  |  F4  |  F5  |XXXXXX|           |      |  F6  |  F7  |  F8  |  F9  |  F10 |  F11   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |  F12   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      | XOY  | QWERT|      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EPRM |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Animat|      |       |Toggle|Solid |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Bright|Bright|      |       | Hue+ |      |      |
 *                                 |ness- |ness+ |------|       |------|      |      |
 *                                 |      |      |      |       | Hue- |      |      |
 *                                 `--------------------'       `--------------------'
 */
// Function Keys
[FN] = LAYOUT_ergodox(
       VRSN,   KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  ______,
       ______, ______, ______, ______, ______, ______, ______,
       ______, ______, ______, ______, ______, ______,
       ______, ______, ______, ______, ______, ______, ______,
         EPRM, ______, ______, ______, ______,
                                              RGB_MOD, ______,
                                                       ______,
                                      RGB_VAD,RGB_VAI, ______,
    // right hand
       ______,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11,
       ______,  ______, ______, ______, ______, ______, KC_F12,
       ______,  DF(XOY),DF(QWERT), ______, ______, ______,
       ______,  ______, ______, ______, ______, ______, ______,
                        ______, ______, ______, ______, ______,
       RGB_TOG, RGB_SLD,
       RGB_HUI,
       RGB_HUD, ______, ______
),


/* Keymap 5: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      | WhlDn| MsUp | WhlUp|      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |WhlLft|MsLeft|MsDown|MsRght|WhlRgt|------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      | Mclk |      |      |      |           |      |      |      | Prev | Next |XXXXXX|        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 | Lclk | Rclk |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = LAYOUT_ergodox(
       ______, ______, ______, ______, ______, ______, ______,
       ______, ______, KC_WH_D,KC_MS_U,KC_WH_U,______, ______,
       ______, KC_WH_L,KC_MS_L,KC_MS_D,KC_MS_R,KC_WH_R,
       ______, ______, ______, KC_BTN3,______, ______, ______,
       ______, ______, ______, ______, ______,
                                               ______, ______,
                                                       ______,
                                     KC_BTN1, KC_BTN2, ______,
    // right hand
       ______,  ______, ______, ______, ______, ______, ______,
       ______,  ______, ______, ______, ______, ______, ______,
                ______, ______, ______, ______, ______, KC_MPLY,
       ______,  ______, ______, KC_MPRV,KC_MNXT,______, ______,
                        KC_VOLU,KC_VOLD,KC_MUTE,______, ______,
       ______, ______,
       ______,
       ______, ______, KC_WBAK
),


};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(MOD3)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
        case 1:
        if (record->event.pressed) { // For resetting EEPROM
          eeconfig_init();
        }
        break;
        case 2:
          // if-statement notwendig, weil sonst auch bei key-up das Makro aufgerufen wird.
          if (record->event.pressed) {
            return MACRO( T(GRV), T(SPC), END);
          }
          break;
        case 3:
          if (record->event.pressed) {
            return MACRO(D(LSFT), T(EQL), U(LSFT), T(SPC), END);
          }
          break;
      }
    return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

LEADER_EXTERNS();

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 2:
          ergodox_right_led_1_on();
          break;
        case 3:
          ergodox_right_led_2_on();
          break;
        case 4:
          ergodox_right_led_3_on();
          break;
        default:
            // none
            break;
    }

    LEADER_DICTIONARY() {
      leading = false;
      leader_end();

      SEQ_ONE_KEY(DE_P) {
        // paste
        register_code(KC_LCTL);
        register_code(DE_V);
        unregister_code(DE_V);
        unregister_code(KC_LCTL);
      }

      SEQ_ONE_KEY(DE_Y) {
        // copy
        register_code(KC_LCTL);
        register_code(DE_C);
        unregister_code(DE_C);
        unregister_code(KC_LCTL);
      }

      SEQ_TWO_KEYS(DE_D, DE_D) {
        // cut whole line
        register_code(KC_HOME);
        unregister_code(KC_HOME);
        register_code(KC_LSFT);
        register_code(KC_END);
        unregister_code(KC_END);
        unregister_code(KC_LSFT);
        register_code(KC_LCTL);
        register_code(DE_X);
        unregister_code(DE_X);
        unregister_code(KC_LCTL);
      }
      SEQ_TWO_KEYS(DE_Y, DE_Y) {
        // copy whole line
        register_code(KC_HOME);
        unregister_code(KC_HOME);
        register_code(KC_LSFT);
        register_code(KC_END);
        unregister_code(KC_END);
        unregister_code(KC_LSFT);
        register_code(KC_LCTL);
        register_code(DE_C);
        unregister_code(DE_C);
        unregister_code(KC_LCTL);
      }

    }

};

void dance_copy_paste_cut (qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
  case 1:
    register_code(KC_LCTL);
    register_code(KC_INS);
    unregister_code(KC_INS);
    unregister_code(KC_LCTL);
    break;
  case 2:
    register_code(KC_LSFT);
    register_code(KC_INS);
    unregister_code(KC_INS);
    unregister_code(KC_LSFT);
    break;
  case 3:
    register_code(KC_LSFT);
    register_code(KC_DEL);
    unregister_code(KC_DEL);
    unregister_code(KC_LSFT);
  }
}

qk_tap_dance_action_t tap_dance_actions[] = {
  // Tap once for A, twice for B
  [TD_CPC] = ACTION_TAP_DANCE_FN(dance_copy_paste_cut)
};

