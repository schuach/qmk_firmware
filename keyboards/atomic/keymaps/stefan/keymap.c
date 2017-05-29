// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// this is the style you want to emulate.

#include "atomic.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.


// macros
#define N2_CARET M(1)
#define N2_BTCK M(2)


#define _AW 0   // AdNWzjßf
#define _N2 1  // neo2 hardcoded
#define _QW 2  // qwertz-layer (neo2 softcoded)
#define _N3 3  // neo2 Ebene 3 hardcoded
#define _N4 4  // neo2 Ebene 4 hardcoded
#define _NI 5  // neo2 inverted
#define _SP 6  // space-toggled layer
#define _SYS 7 // system keys

// KC-Defs für Neo 2 softcoded
#define N2_MOD3 KC_CAPS
#define N2_MOD4 KC_NUBS
#define N2_RMD4 KC_RALT // right Mod4 for locking the layer
#define KC_SZ   KC_LBRC

// Standard layer
#define N2_MINS KC_SLSH   // -
#define N2_GRAV S(KC_EQL) // è dead
#define N2_AKUT KC_EQL    // é dead
#define N2_SZ	KC_MINS   // ß
#define N2_Y	KC_Z      // y
#define N2_Z	KC_Y      // z
#define N2_UE   KC_LBRC   // ü
#define N2_OE	KC_SCLN   // ö
#define N2_AE	KC_QUOT   // ä

// Shift-layer
#define N2_RING S(KC_GRV)       // °
#define N2_PARG KC_HASH         // §
#define N2_FLDQ RALT(KC_Z)      // »
#define N2_FRDQ RALT(KC_X)      // »
#define N2_EURO RALT(KC_E)      // €
#define N2_GLDQ RALT(KC_V)      // „
#define N2_GRDQ RALT(KC_B)      // “
#define N2_ERDQ RALT(KC_N)      // ”
#define N2_CEDI RALT(KC_EQL)    // ¸
#define N2_CSZ  RALT(S(KC_S))   // ẞ großes ß
#define N2_DASH RALT(KC_SLSH)   // – Halbgeviertstrich
#define N2_TILD RALT(KC_RBRC)   // ~ non-dead
#define N2_MDOT RALT(KC_COMM)   // · Malpunkt

// Mod3
#define N2_SPS1 RALT(KC_1)
#define N2_SPS2 RALT(KC_2)
#define N2_SPS3 RALT(KC_3)
#define N2_FLSQ RALT(S(KC_Z))
#define N2_FRSQ RALT(S(KC_X))
#define N2_CENT RALT(KC_C)
#define N2_YEN  RALT(S(KC_Y))
#define N2_GLSQ RALT(S(KC_V))
#define N2_GRSQ RALT(S(KC_B))
#define N2_ERSQ RALT(S(KC_N))
#define N2_UL   S(KC_SLSH)
/*
#define
#define
#define
#define
#define
*/
#define N2_COLN S(KC_DOT)
#define N2_AT   RALT(KC_Q)
#define N2_BSLS RALT(KC_MINS)
#define N2_SLSH KC_AMPR
#define N2_MINS KC_SLSH
#define N2_HASH KC_BSLS

// Klammern 1
#define N2_LPRN KC_ASTR
#define N2_RPRN KC_LPRN
#define N2_LCBR RALT(KC_7)
#define N2_RCBR RALT(KC_0)
#define N2_LBRC RALT(KC_8)
#define N2_RBRC RALT(KC_9)
#define N2_GT   KC_NUBS    // <
#define N2_LT   S(KC_NUBS) // >

// Symbole
#define N2_EQL  S(KC_0)
#define N2_AMP  S(KC_6)
#define N2_AST  S(KC_RBRC)
#define N2_QM   S(KC_MINS)
#define N2_PIPE RALT(KC_NUBS)
#define N2_DQ   S(KC_2)
#define N2_SQ   S(KC_BSLS)
#define N2_SCLN S(KC_COMM)
#define N2_CLN  S(KC_DOT)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_AW] = { /* AdNWzjßf */
  {LT(_SYS,KC_GRV),KC_1,   KC_2,    KC_3,    KC_4,   KC_5,    KC_6,    KC_7,           KC_8,    KC_9,    KC_0,    N2_MINS,      N2_GRAV, KC_NO, KC_BSPC    },
  {KC_TAB,        KC_K,    KC_U,    N2_UE,   KC_DOT, N2_AE,   KC_V,    KC_G,           KC_C,    KC_L,    N2_SZ,   LT(_NI,N2_Z), N2_AKUT, KC_INS,  KC_DEL  },
  {CTL_T(KC_ESC), KC_H,    KC_I,    KC_E,    KC_A,   KC_O,    KC_D,    KC_T,           KC_R,    KC_N,    KC_S,    KC_F,         KC_ENT,  KC_NO,   KC_PGUP },
  {KC_LSFT,       KC_X,    N2_Y,    N2_OE,   KC_COMM,KC_Q,    KC_B,    KC_P,           KC_W,    KC_M,    KC_J,    SFT_T(KC_ENT),KC_LEAD, KC_UP,   KC_PGDN },
  {KC_LEAD,       MO(_NI), KC_LGUI, ALT_T(N2_SZ),F(1),SFT_T(KC_DEL), LT(_N3,KC_BSPC),LT(_SP,KC_SPC), KC_NO,   KC_NO,   KC_HOME, KC_END,  KC_LEFT, KC_DOWN, KC_RGHT }
},

  [_N2] = { /* Neo 2 hardcoded */
  {LT(_SYS,KC_GRV),KC_1,   KC_2,    KC_3,    KC_4,   KC_5,    KC_6,    KC_7,           KC_8,    KC_9,    KC_0,    N2_MINS,      N2_GRAV, KC_NO, KC_BSPC    },
  {KC_TAB,        KC_X,    KC_V,    KC_L,    KC_C,   KC_W,    KC_K,    KC_H,           KC_G,    KC_F,    KC_Q,    N2_SZ,      N2_AKUT, KC_INS,  KC_DEL  },
  {CTL_T(KC_ESC), KC_U,    KC_I,    KC_A,    KC_E,   KC_O,    KC_S,    KC_N,           KC_R,    KC_T,    KC_D,    N2_Y,         KC_ENT,  KC_NO,   KC_PGUP },
  {KC_LSFT,       N2_UE,   N2_OE,   N2_AE,   KC_P,   N2_Z,    KC_B,    KC_M,           KC_COMM, KC_DOT,  KC_J,    SFT_T(KC_ENT),KC_NO,   KC_UP,   KC_PGDN },
  {KC_HOME,      KC_END,KC_LGUI,ALT_T(N2_SZ),F(1),   LT(_N3,KC_DEL), LT(_NI,KC_BSPC), LT(_SP,KC_SPC), KC_NO,   KC_NO,   KC_HOME, KC_END,       KC_LEFT, KC_DOWN, KC_RGHT }
},
[_QW] = { /* Qwerty/Software-Neo2 */
  {LT(_SYS,KC_GRV),KC_1,   KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,           KC_8,    KC_9,    KC_0,    N2_MINS,      N2_GRAV, KC_NO,   KC_BSPC },
  {KC_TAB,        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,           KC_I,    KC_O,    KC_P,    KC_SZ,        N2_AKUT, KC_INS,  KC_DEL  },
  {CTL_T(KC_ESC), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,           KC_K,    KC_L,    KC_SCLN, KC_QUOT,      KC_ENT,  KC_NO,   KC_PGUP },
  {KC_RSFT,       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,           KC_COMM, KC_DOT,  KC_SLSH, SFT_T(KC_ENT),KC_NO,   KC_UP,   KC_PGDN },
  {KC_HOME,       KC_END,KC_LGUI,ALT_T(KC_SZ),N2_MOD4,N2_MOD3, KC_BSPC, LT(_SP,KC_SPC), KC_RALT,   KC_NO,   KC_HOME, KC_END,KC_LEFT, KC_DOWN, KC_RGHT }
},
[_N3] = { /* Neo Ebene 3 hardcoded */
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
  {KC_TRNS, KC_NO,   N2_UL,   N2_LBRC, N2_RBRC, N2_CARET,KC_EXLM, N2_GT,   N2_LT,   N2_EQL,  N2_AMP,  KC_TRNS, KC_NO,   KC_NO,   KC_DEL  },
  {KC_TRNS, N2_BSLS, N2_SLSH, N2_LCBR, N2_RCBR, N2_AST,  N2_QM,   N2_LPRN, N2_RPRN, N2_MINS, N2_COLN, N2_AT,   KC_TRNS, KC_TRNS, KC_TRNS },
  {KC_TRNS, N2_HASH, KC_DLR,  N2_PIPE, N2_TILD, N2_BTCK, N2_EURO, KC_PERC, N2_DQ,   N2_SQ,   N2_SCLN, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS, KC_TRNS, KC_TRNS }
},
[_N4] = { /* WIP Neo Ebene 4 hardcoded */
  {KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_TRNS, KC_TRNS },
  {KC_TRNS, KC_PGUP, KC_BSPC, KC_UP,   KC_DEL,  KC_PGDN, KC_NO,   KC_7,    KC_8,    KC_9,    KC_PPLS, N2_MINS, KC_NO,  KC_NO,   KC_MUTE },
  {KC_TRNS, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  N2_SZ,   KC_4,    KC_5,    KC_6,    KC_COMM, KC_DOT,  KC_ENT, KC_TRNS, KC_VOLU },
  {KC_TRNS, KC_ESC,  KC_TAB,  KC_INS,  KC_PENT, KC_UNDO, N2_CLN,  KC_1,    KC_2,    KC_3,    N2_SCLN, KC_TRNS, KC_NO,  KC_MS_UP,KC_VOLD },
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_0,    KC_MPLY, KC_VOLD, KC_MS_BTN1,KC_MS_BTN2,KC_MS_LEFT,KC_MS_DOWN,KC_MS_RIGHT  },
},
[_NI] = { /* Neo 2 hardcoded inverted */
  {KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
  {KC_TRNS,  N2_GRAV,   KC_NO,   KC_NO,   N2_PARG,   KC_NO,    KC_W,    KC_C,    KC_L,    KC_V,    KC_X,    KC_TAB,       KC_NO,   KC_NO,   KC_NO },
  {KC_TRNS,  N2_AKUT,   KC_NO,   KC_NO,   N2_EURO,   KC_NO,    KC_O,    KC_E,    KC_A,    KC_I,    KC_U,    CTL_T(KC_ESC),KC_NO,   KC_NO,   KC_NO },
  {KC_TRNS,  KC_NO,     KC_NO,   KC_NO,   KC_NO,     KC_NO,    N2_Z,    KC_P,    N2_AE,   N2_OE,   N2_UE,   SFT_T(KC_ENT),KC_NO,   KC_NO,   KC_NO },
  {KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,ALT_T(N2_SZ),KC_LGUI,  KC_END,  KC_HOME,      KC_NO,   KC_NO,   KC_NO }
},
[_SP] = { /* spacebar-layer */
  {KC_TRNS, KC_NO, KC_NO,LCTL(KC_F3), KC_NO, LCTL(KC_F5), KC_NO, LCTL(KC_F7), LCTL(KC_F8), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO },
  {KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_NO,   KC_NO,   KC_BSPC, KC_PGDN, KC_PGUP, KC_DEL,  KC_NO,  KC_NO,   KC_NO,   KC_NO },
  {KC_TRNS, KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_TRNS, KC_HOME, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_END, KC_NO,   KC_NO,   KC_NO },
  {KC_TRNS, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_WH_D, KC_WH_U, KC_BTN2,KC_NO,   KC_NO,   KC_NO },
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,KC_NO,   KC_NO,   KC_NO }
},

[_SYS] = { /* system keys */
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET },
  {KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   RESET,   KC_NO,   KC_NO,   KC_NO  },
  {KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,   KC_NO,   KC_NO  },  
  {KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   DF(_QW), DF(_N2), KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO  },
  {KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   LALT(LCTL(KC_DEL)) }
},
};

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(_N4)

};


const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
    switch(id) {
      case 0:
        return MACRODOWN(TYPE(KC_T), END);
      break;
    } 
    return MACRO_NONE;

};

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_P) {
      register_code(KC_LCTL);
      register_code(KC_V);
      unregister_code(KC_V);
      unregister_code(KC_LCTL);
    }
    SEQ_ONE_KEY(N2_Y) {
      register_code(KC_LCTL);
      register_code(KC_C);
      unregister_code(KC_C);
      unregister_code(KC_LCTL);
    }

    SEQ_TWO_KEYS(KC_D, KC_D) {
      register_code(KC_HOME);
      unregister_code(KC_HOME);
      register_code(KC_LSFT);
      register_code(KC_END);
      unregister_code(KC_END);
      unregister_code(KC_LSFT);
      register_code(KC_LCTL);
      register_code(KC_X);
      unregister_code(KC_X);
      unregister_code(KC_LCTL);
    }
    SEQ_THREE_KEYS(KC_A, KC_S, KC_D) {
      register_code(KC_LGUI);
      register_code(KC_S);
      unregister_code(KC_S);
      unregister_code(KC_LGUI);
    }
  }
}
