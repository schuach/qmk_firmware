#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "keymap_german.h"
#undef LEADER_TIMEOUT
#define LEADER_TIMEOUT 750

#define XOY  0   // default layer
#define QWERT 1 // qwertz
#define MOD3 2   // Neo Mod3
#define MOD4 3   // Neo Mod4
#define FN 4     // Function and Media Keys
#define MDIA 5     // Media and Mouse

// Dual role keys (LAYER_KC) and modified keys
#define MDIA_Z LT(MDIA, DE_Z)
#define MDIA_MNS LT(MDIA, DE_MINS)
#define CTL_F  CTL_T(DE_F)
#define ALT_SPC LALT(KC_SPC)
#define ALT_TAB LALT(KC_TAB)
#define SALT_TB S(LALT(KC_TAB))
#define TRM_QKE KC_F12
#define KRUNNER LALT(KC_SPC)

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
  TD_CPC = 0,
  TD_OPRN,
  TD_CPRN,
  TD_OBRC,
  TD_CBRC,
  TD_QUOT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |Cp/Pst/C|   1  |   2  |   3  |   4  |   5  |KRunnr|           | F12  |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   X  |   .  |   O  |   ,  |   Y  |  (/{ |           |  )/} |   V  |   G  |   C  |   L  |   J  |   ß    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |Esc/Ctrl|   H  |   A  |   E  |   I  |   U  |------|           |------|   D  |   T  |   R  |   N  |   S  |Ctl/F   |
 * |--------+------+------+------+------+------|  [/< |           |  ]/> |------+------+------+------+------+--------|
 * | LGui   |   K  |   Q  |   Ä  |   Ü  |   Ö  |      |           |      |   B  |   P  |   W  |   M  |MDIA/Z| Enter  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Prnt |   <  |   >  |  "/' | Del  |                                       | Bspc | Left | Down |  Up  |Right |
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
        TD(TD_CPC),   DE_1,    DE_2,    DE_3,    DE_4,    DE_5,    KRUNNER,
        KC_TAB,       DE_X,    DE_DOT,  DE_O,    DE_COMM, DE_Y,    TD(TD_OPRN),
        CTL_T(KC_ESC),DE_H,    DE_A,    DE_E,    DE_I,    DE_U,
        KC_LGUI,      DE_K,    DE_Q,    DE_AE,   DE_UE,   DE_OE,   TD(TD_OBRC),
        KC_PSCR,      DE_LESS, DE_MORE, TD(TD_QUOT), KC_DEL,
        // left thumb
                                                    OSM(MOD_LALT), KC_LGUI,
                                                                   KC_PGUP,
                                            TT(MOD4),  KC_LSFT,    KC_PGDN,

        // right hand
        KC_F12,      DE_6,    DE_7,    DE_8,    DE_9,    DE_0,    DE_MINS,
        TD(TD_CPRN), DE_V,    DE_G,    DE_C,    DE_L,    DE_J,    DE_SS,
                     DE_D,    DE_T,    DE_R,    DE_N,    DE_S,    CTL_F,
        TD(TD_CBRC), DE_B,    DE_P,    DE_W,    DE_M,    MDIA_Z,  KC_ENT,
                     KC_BSPC, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
        // right thumb
        OSM(MOD_RALT), CTL_T(KC_ESC),
        KC_HOME,
        KC_END,        OSL(MOD3),   LT(FN,KC_SPC)

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
 * | Lshft  |  Y   |  X   |  C   |  V   |  B   |      |           |      |  N   |  M   |  ,   |  .   |Mdia/-|Rsft/Ret|
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
        ______,  DE_N,    DE_M,    DE_DOT,  DE_COMM, MDIA_MNS,SFT_T(KC_ENT),
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
 * |        | Pgup | Bspc | Up   | Del  | Pgdn |      |           |      |      |  7   |  8   |  9   |  +   |   -    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | Home | Left | Down | Right| End  |------|           |------|      |  4   |  5   |  6   |  ,   |   .    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | Esc  | Tab  | Ins  | Ret  | Undo |      |           |      |   :  |  1   |  2   |  3   |  ;   |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |  0   |      |      |      |      |
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
        ______,  ______,  DE_7 ,   DE_8 ,   DE_9 ,   KC_PPLS, KC_PMNS,
                 ______,  DE_4 ,   DE_5 ,   DE_6 ,   KC_COMM, KC_DOT,
        ______,  DE_COLN, DE_1 ,   DE_2 ,   DE_3 ,   DE_SCLN, KC_PENT,
                          DE_0 ,   ______,  ______,  ______,  ______,
        ______,  ______,
        ______,
        ______,  KC_SPC,  DE_0
 ),
/* Keymap 4: Function Keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |Version |      |      |      |      |      |XXXXXX|           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |  F1  |  F2  |  F3  |  F4  |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  F5  |  F6  |  F7  |  F8  |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  F9  |  F10 |  F11 |  F12 |      |      |           |      | Prnt | Num  | Caps |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EPRM |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Animat|      |       |Toggle|Solid |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Bright|Bright|      |       | Hue+ |      |      |
 *                                 |ness- |ness+ |------|       |------|      |XXXXXX|
 *                                 |      |      |      |       | Hue- |      |      |
 *                                 `--------------------'       `--------------------'
 */
// Function Keys
[FN] = LAYOUT_ergodox(
       VRSN,   ______, ______, ______, ______, ______, ______,
       ______, KC_F1,  KC_F2,  KC_F3,  KC_F4,  ______, ______,
       ______, KC_F5,  KC_F6,  KC_F7,  KC_F8,  ______,
       ______, KC_F9,  KC_F10, KC_F11, KC_F12, ______, ______,
         EPRM, ______, ______, ______, ______,
                                              RGB_MOD, ______,
                                                       ______,
                                      RGB_VAD,RGB_VAI, ______,
    // right hand
       DF(XOY), ______, ______, ______, ______, ______, ______,
       DF(QWERT),______,______, ______, ______, ______, ______,
       ______,  ______, ______, ______, ______, ______,
       ______,  KC_PSCR,KC_NLCK,KC_CAPS,______, ______, ______,
                        ______, ______, ______, ______, ______,
       RGB_TOG, RGB_SLD,
       RGB_HUI,
       RGB_HUD, ______, ______
),


/* Keymap 5: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           | XOY  |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      | WhlDn| MsUp | WhlUp|      |      |           | QWERT|      |      |      |      |      |        |
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
       DF(XOY),______, ______, ______, ______, ______, ______,
       DF(QWERT),______,______,______, ______, ______, ______,
               ______, ______, ______, ______, ______, KC_MPLY,
       ______, ______, ______, KC_MPRV,KC_MNXT,______, ______,
                        KC_VOLD,KC_VOLU,KC_MUTE,______, ______,
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
        register_code(KC_LSFT);
        register_code(KC_INS);
        unregister_code(KC_INS);
        unregister_code(KC_LSFT);
      }
      SEQ_ONE_KEY(DE_Y) {
        // copy
        register_code(KC_LCTL);
        register_code(KC_INS);
        unregister_code(KC_INS);
        unregister_code(KC_LCTL);
      }
      SEQ_ONE_KEY(DE_D) {
        // cut
        register_code(KC_LSFT);
        register_code(KC_DEL);
        unregister_code(KC_DEL);
        unregister_code(KC_LSFT);
      }
      SEQ_TWO_KEYS(DE_D, DE_D) {
        // cut whole line
        register_code(KC_HOME);
        unregister_code(KC_HOME);
        register_code(KC_LSFT);
        register_code(KC_END);
        unregister_code(KC_END);
        unregister_code(KC_LSFT);
        register_code(KC_LSFT);
        register_code(KC_DEL);
        unregister_code(KC_DEL);
        unregister_code(KC_LSFT);
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
        register_code(KC_INS);
        unregister_code(KC_INS);
        unregister_code(KC_LCTL);
      }
      SEQ_TWO_KEYS(DE_Y, DE_A) {
        // copy to the beginning of the line
        register_code(KC_LSFT);
        register_code(KC_HOME);
        unregister_code(KC_HOME);
        unregister_code(KC_LSFT);
        register_code(KC_LCTL);
        register_code(KC_INS);
        unregister_code(KC_INS);
        unregister_code(KC_LCTL);
      }
      SEQ_TWO_KEYS(DE_Y, DE_E) {
        // copy to the end of the line
        register_code(KC_LSFT);
        register_code(KC_END);
        unregister_code(KC_END);
        unregister_code(KC_LSFT);
        register_code(KC_LCTL);
        register_code(KC_INS);
        unregister_code(KC_INS);
        unregister_code(KC_LCTL);
      }
      SEQ_TWO_KEYS(DE_D, DE_A) {
        // cut to the beginning of the line
        register_code(KC_LSFT);
        register_code(KC_HOME);
        unregister_code(KC_HOME);
        unregister_code(KC_LSFT);
        register_code(KC_LSFT);
        register_code(KC_DEL);
        unregister_code(KC_DEL);
        unregister_code(KC_LSFT);
      }
      SEQ_TWO_KEYS(DE_D, DE_E) {
        // cut to the end of the line
        register_code(KC_LSFT);
        register_code(KC_END);
        unregister_code(KC_END);
        unregister_code(KC_LSFT);
        register_code(KC_LSFT);
        register_code(KC_DEL);
        unregister_code(KC_DEL);
        unregister_code(KC_LSFT);
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
};

void dance_open_prn_cbr (qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
  case 1:
    register_code(KC_LSFT);
    register_code(KC_8);
    unregister_code(KC_8);
    unregister_code(KC_LSFT);
    break;
  case 2:
    register_code(KC_RALT);
    register_code(KC_7);
    unregister_code(KC_7);
    unregister_code(KC_RALT);
  }
}
void dance_close_prn_cbr (qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
  case 1:
    register_code(KC_LSFT);
    register_code(KC_9);
    unregister_code(KC_9);
    unregister_code(KC_LSFT);
    break;
  case 2:
    register_code(KC_RALT);
    register_code(KC_0);
    unregister_code(KC_0);
    unregister_code(KC_RALT);
  }
}
void dance_open_brc_abrc (qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
  case 1:
    register_code(KC_RALT);
    register_code(KC_8);
    unregister_code(KC_8);
    unregister_code(KC_RALT);
    break;
  case 2:
    register_code(KC_NUBS);
    unregister_code(KC_NUBS);
  }
}
void dance_close_brc_abrc (qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
  case 1:
    register_code(KC_RALT);
    register_code(KC_9);
    unregister_code(KC_9);
    unregister_code(KC_RALT);
    break;
  case 2:
    register_code(KC_LSFT);
    register_code(KC_NUBS);
    unregister_code(KC_NUBS);
    unregister_code(KC_LSFT);
  }
}

qk_tap_dance_action_t tap_dance_actions[] = {
  // Tap once for copy, twice for paste, thrice for cut
  [TD_CPC] = ACTION_TAP_DANCE_FN(dance_copy_paste_cut),
  // tap once for an opening paren, twice for an opening curly brace
  [TD_OPRN] = ACTION_TAP_DANCE_FN(dance_open_prn_cbr),
  // tap once for an closing paren, twice for an closing curly brace
  [TD_CPRN] = ACTION_TAP_DANCE_FN(dance_close_prn_cbr),
  // tap once for an opening bracket, twice for an opening angle brace
  [TD_OBRC] = ACTION_TAP_DANCE_FN(dance_open_brc_abrc),
  // tap once for an closing bracket, twice for an closing angle brace
  [TD_CBRC] = ACTION_TAP_DANCE_FN(dance_close_brc_abrc),
  // tap once for double quote, twice for single quote
  [TD_QUOT] = ACTION_TAP_DANCE_DOUBLE(DE_DQOT, DE_QUOT)
};

