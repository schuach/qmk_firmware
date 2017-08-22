#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "keymap_german.h"

#define XOY  0 // default layer
#define MOD3 1 // Neo Mod3
#define MOD4 1 // Neo Mod4

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Leader |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   X  |   .  |   O  |   ,  |   Y  |      |           |      |   V  |   G  |   C  |   L  |   J  |   ß    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |Esc/Ctrl|   H  |   A  |   E  |   I  |   U  |------|           |------|   D  |   T  |   R  |   N  |   S  |   F    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift |   K  |   Q  |   Ä  |   Ü  |   Ö  |      |           |      |   B  |   P  |   W  |   M  |   Z  |RSft/Rtn|
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | LGui |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Pgup |       | Home |        |      |
 *                                 | Mod4 | Lsft |------|       |------|  Mod3  | Spc  |
 *                                 |      |      | Pgdn |       | End  |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[XOY] = KEYMAP(  // layer 0 : default
        // left hand
        KC_LEAD,        KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   KC_XXX,
        KC_TAB,         DE_K,         DE_DOT, DE_O,   DE_COMM,DE_Y,   KC_XXX,
        CTL_T(KC_ESC),  DE_H,         DE_A,   DE_E,   DE_I,   DE_U,
        KC_LSFT,        CTL_T(DE_X),  DE_Q,   DE_AE,  DE_UE,  DE_OE,  KC_XXX,
        LT(SYMB,KC_GRV),KC_QUOT,      LALT(KC_LSFT),  KC_LEFT,KC_RGHT,
                                              ALT_T(KC_APP),  KC_LGUI,
                                                              KC_HOME,
                                               KC_SPC,KC_ENT ,KC_END,
        // right hand
        KC_RGHT,     KC_6,   KC_7,   KC_8,   KC_9,   KC_0,             KC_MINS,
        TG(SYMB),    DE_V,   DE_G,   DE_C,   DE_L,   DE_SS,            DE_Z,
        DE_D,        DE_T,   DE_R,   DE_N,   LT(MDIA, DE_S),           KC_XXX,
        MEH_T(KC_NO),KC_B,   KC_P,   KC_W,   KC_M,   CTL_T(KC_J),      KC_RSFT,
                             KC_UP,  KC_DOWN,KC_LBRC,KC_RBRC,          KC_FN1,
        KC_LALT,        CTL_T(KC_ESC),
        KC_PGUP,
        KC_PGDN,KC_TAB, KC_RSFT
    ),
/* Keymap 1: Mod3
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |  _   |  [   |  ]   |  ^   |      |           |      |   !  |   <  |  >   |  =   |  &   |        |
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
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[MOD3] = KEYMAP(
       // left hand
       KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,
       KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,
       KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,
       KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,
       KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,
                                                    KC_XXX,  KC_XXX,
                                                             KC_XXX,
                                           KC_XXX,  KC_XXX,  KC_XXX,

       // right hand
       KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,
       KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,
                KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,
       KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,
                         KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,
       KC_XXX,  KC_XXX,
       KC_XXX,
       KC_XXX,  KC_XXX,   KC_TRNS
),
/* Keymap 2: Mod4
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        | Pgup | Bspc | Up   | Del  | Pgdn |      |           |      |   /  |   7  |  8   |  9   |  9   |   +    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | Home | Left | Down | Right| End  |------|           |------|   *  |   4  |  5   |  6   |  ,   |   .    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | Esc  | Tab  | Ins  | Ret  | Undo |      |           |      |   :  | Pad1 | Pad2 | Pad3 |  ;   |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
//* SYMBOLS
[MOD4] = KEYMAP(
       // left hand
       KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,
       KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,
       KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,
       KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,
       KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,
                                                    KC_XXX,  KC_XXX,
                                                             KC_XXX,
                                           KC_XXX,  KC_XXX,  KC_XXX,

       // right hand
       KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,
       KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,
                KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,
       KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,
                         KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,
       KC_XXX,  KC_XXX,
       KC_XXX,
       KC_XXX,  KC_XXX,   KC_TRNS
),
/* Dummy
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |  |   |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// DUMMY
/* [Dummy] = KEYMAP( */
/*        // left hand */
/*        KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX, */
/*        KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX, */
/*        KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX, */
/*        KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX, */
/*        KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX, */
/*                                                     KC_XXX,  KC_XXX, */
/*                                                              KC_XXX, */
/*                                            KC_XXX,  KC_XXX,  KC_XXX, */

/*        // right hand */
/*        KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX, */
/*        KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX, */
/*                 KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX, */
/*        KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX, */
/*                          KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX,  KC_XXX, */
/*        KC_XXX,  KC_XXX, */
/*        KC_XXX, */
/*        KC_XXX,  KC_XXX,   KC_TRNS */
/* ), */

};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
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

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
