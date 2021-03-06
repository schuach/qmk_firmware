#include "atomic.h"
#include "keymap_german.h"

// Fillers to make layering more clear
#define _______ KC_TRNS
#define ___T___ KC_TRNS
#define XXXXXXX KC_NO

// Layer shorthand
#define QW 0
#define FN 1
#define SYS 2

// Custom definitions
#define SPC_FN LT(FN, KC_SPC)
#define RALT_HOM MT(MOD_RALT, KC_HOME)
#define C(kc) LCTL(kc)

/* ROW 1 OPTIONS
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 *                                                                                                                      .- 2u ------------.
 *                                                                                                                      | KEY    . XXXXXX |
 *                                                                                                                      '-----------------'
 */
 
/* ROW 2 OPTIONS
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 * .- 2u ------------.                                                                                                  .- 2u ------------.
 * | KEY    . XXXXXX |                                                                                                  | KEY    . XXXXXX |
 * '-----------------'                                                                                                  '-----------------'
 */
 
/* ROW 3 OPTIONS
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 * .- 2u ------------.                                                                                         .- 2u ------------.
 * | KEY    . XXXXXX |                                                                                         |   X             |
 * '-----------------'                                                                                         '-----------------'
 *                                                                                                                      .- 2u ------------.
 *                                                                                                                      |   X             |
 *                                                                                                                      '-----------------'
 */
 
/* ROW 4 OPTIONS
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 *                                                                                                    .- 2u ------------.
 *                                                                                                    | KEY    . XXXXXX |
 *                                                                                                    '-----------------'
 * .- 2u ------------.                                                                                         .- 2u ------------.
 * | KEY    . XXXXXX |                                                                                         | KEY    . XXXXXX |
 * '-----------------'                                                                                         '-----------------'
 *                                                                                                                      .- 2u ------------.
 *                                                                                                                      | KEY    . XXXXXX |
 *                                                                                                                      '-----------------'
 */

/* ROW 5 OPTIONS
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 * .- 1.25u --+ 1.25u ------- 1.25u +--- 1.25u --- 2u -------------- 1.25u ---- 1.25u ------ 1.25u +---- 1.25u .
 * |   X      | X        |        X |      X    |   X             |   X      | X        |        X |      X    |
 * '-----------------------------------------------------------------------------------------------------------'
 *                                                                .- 2u ------------.
 *                                                                |   X             |
 *                                                                '-----------------'
 *                                  .--------------------- 6.25u ----------------------------.
 *                                  |                        X                               |
 *                                  '--------------------------------------------------------'
 *                       .----------------------- 6.25u ---------------------------- 1.25u ---- 1.25u ---- 1.25u ------ 1.25u +-- 1.25u --.
 *                       |                          X                             |     X    |   X      | X        |        X |      X    |
 *                       '----------------------------------------------------------------------------------------------------------------'
 */
/* 
 * .- 1.25u --+ 1.25u ------- 1.25u +--------------------- 6.25u -------------------------------------------------------------------------.
 * |   X      | X        |        X |                        X                               |        |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY - MIT ENHANCED / GRID COMPATIBLE
 * .---------------------------------------------------------------------------------------------------------------------- 2u ------------.
 * | ESC    | 1      | 2      | 3      | 4      | 5      | 6      | 7      | 8      | 9      | 0      | ß      | '      | XXXXXX . BACKSP |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | TAB    | Q      | W      | E      | R      | T      | Z      | U      | I      | O      | P      | Ü      | +      | INS    | DEL    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+- 2u ------------+--------|
 * | NUM    | A      | S      | D      | F      | G      | H      | J      | K      | L      | Ö      | Ä      | XXXXXX . ENTER  | PG UP  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+- 2u ---------------------+--------|
 * | LSHIFT | Y      | X      | C      | V      | B      | N      | M      | ,      | .      | -      | XXXXXX . RSHIFT | UP     | PG DN  |
 * .- 1.25u --+ 1.25u ------- 1.25u +--------------------- 6.25u -------------------------------------------------------------------------.
 * | LCTL     | LGUI     | LALT     |         SPACE                                          |RALT/HOM| END    | LEFT   | DOWN   | RIGHT  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [QW] = { /* QWERTZ */
  { KC_ESC,       DE_1,    DE_2,    DE_3,    DE_4,    DE_5,    DE_6,    DE_7,    DE_8,    DE_9,    DE_0,    DE_SS,   DE_ACUT, KC_BSPC, KC_BSPC  },
  { KC_TAB,       DE_Q,    DE_W,    DE_E,    DE_R,    DE_T,    DE_Z,    DE_U,    DE_I,    DE_O,    DE_P,    DE_UE,   DE_PLUS, KC_INS,  KC_DEL   },
  { KC_ESC,       DE_A,    DE_S,    DE_D,    DE_F,    DE_G,    DE_H,    DE_J,    DE_K,    DE_L,    DE_OE,   DE_AE,   KC_ENT,  KC_ENT,  KC_PGUP  },
  { KC_LSFT,      DE_Y,    DE_X,    DE_C,    DE_V,    DE_B,    DE_N,    DE_M,    DE_COMM, DE_DOT,  DE_MINS, KC_RSFT, KC_RSFT, KC_UP,   KC_PGDN  },
  {CTL_T(KC_ENT), KC_LGUI, XXXXXXX, KC_LALT, XXXXXXX, XXXXXXX, SPC_FN,  SPC_FN,  XXXXXXX, XXXXXXX, RALT_HOM,KC_END,  KC_LEFT, KC_DOWN, KC_RGHT  },
 },


/* FUNCTION
 * .---------------------------------------------------------------------------------------------------------------------- 2u ------------.
 * |        | F1     | F2     | F3     | F4     | F5     | F6     | F7     | F8     | F9     | F10    | F11    | F12    | XXXXXX .        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * |        |        |        | C-F3   |        | C-F5   |        | C-F7   | C-F8   |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+- 2u ------------+--------|
 * |        |        |        |        |        |        |        | [      | ]      | {      | }      |        | XXXXXX .        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+- 2u ---------------------+--------|
 * |        | |      |        |        | <      | >      |        | (      | )      |        |        | XXXXXX .        |        |        |
 * .- 1.25u --+ 1.25u ------- 1.25u +--------------------- 6.25u -------------------------------------------------------------------------.
 * |          |          |          |                                                        |        |        |        |        |       |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [FN] = { /* Function Layer */
  { _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  ___T___, ___T___  },
  { _______, _______, _______, C(KC_F3),_______, C(KC_F5),_______, C(KC_F7),C(KC_F8),_______, _______, _______, _______, _______, MO(SYS)  },
  { _______, _______, _______, _______, _______, _______, _______, DE_LBRC, DE_RBRC, DE_LCBR, DE_RCBR, _______, ___T___, ___T___, _______  },
  { _______, DE_PIPE, _______, _______, DE_LESS, DE_MORE, _______, DE_LPRN, DE_RPRN, _______, _______, _______, _______, _______, _______  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  },
 },
 /* SYSTEM
 * .---------------------------------------------------------------------------------------------------------------------- 2u ------------.
 * |        |        |        |        |        |        |        |        |        |        |        |        |        | XXXXXX .        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * |        |        |        |        | RESET  |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+- 2u ------------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        | XXXXXX .        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+- 2u ---------------------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        | XXXXXX .        |        |        |
 * .- 1.25u --+ 1.25u ------- 1.25u +--------------------- 6.25u -------------------------------------------------------------------------.
 * |          |          |          |                                                        |        |        |        |        |       |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */
 
 [SYS] = { /* System Keys */
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, ___T___, ___T___  },
  { _______, _______, _______, _______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, ___T___, ___T___, _______  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  },
 },

};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};
