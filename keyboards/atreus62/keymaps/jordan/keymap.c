#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _DEFAULT 0
#define _NAV 1
#define _RESET 2

enum custom_keycodes {
    WTF = SAFE_RANGE
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch(keycode) {
            case WTF:
                SEND_STRING("What the fuck did you just fucking say about me, you little bitch? I'll have you know I graduated top of my class in the Navy Seals, and I've been involved in numerous secret raids on Al-Quaeda, and I have over 300 confirmed kills. I am trained in gorilla warfare and I'm the top sniper in the entire US armed forces. You are nothing to me but just another target. I will wipe you the fuck out with precision the likes of which has never been seen before on this Earth, mark my fucking words. You think you can get away with saying that shit to me over the Internet? Think again, fucker. As we speak I am contacting my secret network of spies across the USA and your IP is being traced right now so you better prepare for the storm, maggot. The storm that wipes out the pathetic little thing you call your life. You're fucking dead, kid. I can be anywhere, anytime, and I can kill you in over seven hundred ways, and that's just with my bare hands. Not only am I extensively trained in unarmed combat, but I have access to the entire arsenal of the United States Marine Corps and I will use it to its full extent to wipe your miserable ass off the face of the continent, you little shit. If only you could have known what unholy retribution your little \"clever\" comment was about to bring down upon you, maybe you would have held your fucking tongue. But you couldn't, you didn't, and now you're paying the price, you goddamn idiot. I will shit fury all over you and you will drown in it. You're fucking dead, kiddo.");
                return false;
        }
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DEFAULT] = LAYOUT( /* qwerty */
    KC_GRV,   KC_1,    KC_2,    KC_3,    KC_4,     KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS ,
    KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_EQL  ,
    KC_ESC,   KC_A,    KC_S,    KC_D,    KC_F,     KC_G,                        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT ,
    KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,                        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS ,
    KC_LALT,  KC_NO,   KC_NO,   KC_NO,   MO(_NAV), KC_LGUI, KC_BSPC,  KC_ENT,   KC_SPC,  KC_NO,   KC_NO,   KC_NO,   KC_LBRC, KC_RBRC
  ),

  [_NAV] = LAYOUT(
    TO(_DEFAULT),  KC_F1,   KC_F2,   KC_F3,   KC_F4,        KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11  ,
    KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,                     KC_F13,  KC_TRNS, KC_UP,   KC_TRNS, KC_LBRC, KC_RBRC ,
    KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,                     KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS ,
    KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,                     KC_TRNS, KC_TRNS, KC_TRNS, KC_UP,   KC_TRNS, KC_TRNS ,
    KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, TO(_RESET)
  ),

  [_RESET] = LAYOUT(
    TO(_DEFAULT),  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,                     KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , WTF     ,
    KC_NO  ,       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,                     KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO   ,
    KC_NO  ,       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,                     KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO   ,
    KC_NO  ,       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,                     KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO   ,
    KC_NO  ,       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,  KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , RESET
  )

  /*
  [_TRNS] = LAYOUT(
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS ,
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS ,
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS ,
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS ,
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),
  */
};



const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  // MACRODOWN only works in this function
  switch (id) {
  case 0:
    if (record->event.pressed) {
      register_code(KC_RSFT);
    }
    else {
      unregister_code(KC_RSFT);
    }
    break;
  }
  return MACRO_NONE;
};
