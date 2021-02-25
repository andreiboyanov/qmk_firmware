#include QMK_KEYBOARD_H

enum layers {
    _QWERTY = 0,
    _NUM,
    _SYM,
    _NAV
};

#define NUM_ESC LT(_NUM, KC_ESC)
#define NAV_ENT LT(_NAV, KC_ENT)
#define SYM_TAB LT(_SYM, KC_TAB)
#define SYM_SPC LT(_SYM, KC_SPC)
#define NAV_SPC LT(_NAV, KC_SPC)
#define NAV_TAB LT(_NAV, KC_TAB)
#define NUM_BSP LT(_NUM, KC_BSPC)

#define LGUI_A  MT(MOD_LGUI, KC_A)
#define LALT_S  MT(MOD_LALT, KC_S)
#define LCTL_D  MT(MOD_LCTL, KC_D)
#define LSFT_F  MT(MOD_LSFT, KC_F)
#define RSFT_J  MT(MOD_RSFT, KC_J)
#define RCTL_K  MT(MOD_RCTL, KC_K)
#define RALT_L  MT(MOD_RALT, KC_L)
#define RGUI_SC MT(MOD_RGUI, KC_SCLN)

// #define LGUI_ MT(MOD_LGUI, KC_)
#define LALT_F4 MT(MOD_LALT, KC_F4)
#define LCTL_F5 MT(MOD_LCTL, KC_F5)
#define LSFT_F6 MT(MOD_LSFT, KC_F6)
#define RSFT_4  MT(MOD_RSFT, KC_4)
#define RCTL_5  MT(MOD_RCTL, KC_5)
#define RALT_6  MT(MOD_RALT, KC_6)
#define RGUI_IN MT(MOD_RGUI, KC_INS)

#define LGUI_CL MT(MOD_LGUI, KC_COLN)
#define LALT_DL MT(MOD_LALT, KC_DLR)
#define LCTL_PR MT(MOD_LCTL, KC_PERC)
#define LSFT_CR MT(MOD_LSFT, KC_CIRC)
#define RSFT_LB MT(MOD_RSFT, KC_LBRC)
#define RCTL_RB MT(MOD_RCTL, KC_RBRC)
#define RALT_MI MT(MOD_RALT, KC_MINS)
#define RGUI_PL MT(MOD_RGUI, KC_PLUS)

#define RSFT_LF MT(MOD_RSFT, KC_LEFT)
#define RCTL_DN MT(MOD_RCTL, KC_DOWN)
#define RALT_RG MT(MOD_RALT, KC_RGHT)
#define RGUI_IN MT(MOD_RGUI, KC_INS)

#define _ KC_TRANSPARENT
#define X KC_NO

enum custom_keycodes {
    SCRATCHPAD = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
      _, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    SCRATCHPAD,
      _, LGUI_A,  LALT_S,  LCTL_D,  LSFT_F,  KC_G,               KC_H,    RSFT_J,  RCTL_K,  RALT_L,  RGUI_SC, _,
      KC_SPC, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, X, X,   X, X, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _,
             KC_TAB, KC_DEL, NUM_ESC, SYM_SPC, NAV_ENT,  NAV_TAB, SYM_SPC, NUM_BSP, KC_DEL,  KC_RALT
    ),
    [_NUM] = LAYOUT(
      _, XXXXXXX, KC_F7,   KC_F8,   KC_F9,   KC_F10,              KC_0,    KC_7,    KC_8,    KC_9,    KC_PSCR, _,
      _, KC_LGUI, LALT_F4, LCTL_F5, LSFT_F6, KC_F11,              KC_0,    RSFT_4,  RCTL_5,  RALT_6,  RGUI_IN, _,
      _, XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F12, X, X,  X, X, KC_0,    KC_1,    KC_2,    KC_3,    KC_DEL,  _,
              _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______
    ),
    [_SYM] = LAYOUT(
      _, XXXXXXX, KC_AMPR, KC_ASTR, KC_PIPE, KC_COLN,              KC_DQUO,    KC_LPRN, KC_RPRN, KC_EQL,  KC_ASTR, _,
      _, KC_LGUI, KC_DLR,  KC_PERC, KC_CIRC, KC_TILD,              KC_QUOT,    RSFT_LB, RCTL_RB, RALT_MI, RGUI_PL, _,
      _, XXXXXXX, KC_EXLM, KC_AT,   KC_HASH, KC_QUES, X, X,  X, X, KC_GRV,     KC_LCBR, KC_RCBR, KC_UNDS, KC_BSLS, _,
               _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______
    ),
    [_NAV] = LAYOUT(
      _, _______, _______, _______, _______, _______,              KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_PSCR, _,
      _, _______, _______, _______, _______, _______,              KC_PGDN, RSFT_LF, RCTL_DN, RALT_RG, RGUI_IN, _,
      _, _______, _______, _______, _______, _______, X, X,  X, X, KC_QUES, KC_LT,   KC_GT,   KC_COLN, KC_DEL,  _,
               _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SCRATCHPAD:
        if (record->event.pressed) {
            SEND_STRING(SS_LGUI("-"));
        }
        break;
    }
    return true;
}

// layer_state_t layer_state_set_user(layer_state_t state) {
    // return update_tri_layer_state(state, _NUM, _SYM, _NAV);
// }

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}

static void render_kyria_logo(void) {
    static const char PROGMEM kyria_logo[] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
        0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
    };
    oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
}

static void render_qmk_logo(void) {
  static const char PROGMEM qmk_logo[] = {
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};

  oled_write_P(qmk_logo, false);
}

static void render_status(void) {
    // QMK Logo and version information
    render_qmk_logo();
    oled_write_P(PSTR("Kyria rev1.0\n\n"), false);

    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case _NUM:
            oled_write_P(PSTR("Numeric\n"), false);
            break;
        case _SYM:
            oled_write_P(PSTR("Symbols\n"), false);
            break;
        case _NAV:
            oled_write_P(PSTR("Navigation\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undefined\n"), false);
    }

    // Host Keyboard LED Status
    uint8_t led_usb_state = host_keyboard_leds();
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK) ? PSTR("NUMLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK) ? PSTR("CAPLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_kyria_logo();
    }
}
#endif

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 1) {
        // Page up/Page down
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
}
#endif
