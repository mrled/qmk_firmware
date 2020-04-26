/* Happy Birthday, Eli. Hope you enjoy it.
 */

#include QMK_KEYBOARD_H

enum custom_keycodes {
  CKC_BESTELI = SAFE_RANGE,
  CKC_MATRIX,
  CKC_DOGTTERFLY,
  CKC_FRICK,
  CKC_CHROMESS,
  CKC_MACSS,
  CKC_WINSS,
  CKC_SWEARS,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_MUTE, TO(2), CKC_CHROMESS,
        CKC_MACSS, TT(1), CKC_WINSS,
        KC_MEDIA_PREV_TRACK, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK
    ),
    [1] = LAYOUT(
        CKC_FRICK, CKC_BESTELI, CKC_SWEARS,
        CKC_MATRIX, TO(1),  CKC_DOGTTERFLY,
        KC_E, KC_L, KC_I
    ),
    [2] = LAYOUT(
        KC_PGUP, TO(0), KC_HOME,
        KC_PGDN, KC_UP, KC_END,
        KC_LEFT, KC_DOWN, KC_RIGHT
    )
};

void encoder_update_user_volume(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 1) {
        if (clockwise) {
            tap_code(KC_BRIGHTNESS_UP);
        } else {
            tap_code(KC_BRIGHTNESS_DOWN);
        }
    }
}

void encoder_update_user_mouse(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_MS_LEFT);
        } else {
            tap_code(KC_MS_RIGHT);
        }
    }
    else if (index == 1) {
        if (clockwise) {
            tap_code(KC_MS_UP);
        } else {
            tap_code(KC_MS_DOWN);
        }
    }
}

void encoder_update_user(uint8_t index, bool clockwise) {
    encoder_update_user_volume(index, clockwise);
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CKC_FRICK:
            if (record->event.pressed) SEND_STRING("What the frick? ");
            return false;
        case CKC_BESTELI:
            if (record->event.pressed) SEND_STRING("ELI WINS THE INTERNET. ");
            return false;
        case CKC_CHROMESS:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                tap_code(KC_F5);
                unregister_code(KC_LGUI);
            }
            return false;
        case CKC_MACSS:
            if (record->event.pressed) {
                register_code(KC_LSHIFT);
                register_code(KC_LGUI);
                tap_code(KC_3);
                unregister_code(KC_LGUI);
                unregister_code(KC_LSHIFT);
            }
            return false;
        case CKC_WINSS:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                tap_code(KC_PSCR);
                unregister_code(KC_LGUI);
            }
            return false;
        case CKC_SWEARS:
            if (record->event.pressed) SEND_STRING("!)@(*#$!(@*#$*");
            return false;
        case CKC_MATRIX:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                tap_code(KC_SPC);
                unregister_code(KC_LGUI);
                _delay_ms(500);
                SEND_STRING("terminal.app");
                _delay_ms(750);
                tap_code(KC_ENT);
                _delay_ms(2000);
                SEND_STRING("curl http://bruxy.regnet.cz/linux/matrix/matrix.sh | bash");
                tap_code(KC_ENT);
            }
            return false;
        case CKC_DOGTTERFLY:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                tap_code(KC_SPC);
                unregister_code(KC_LGUI);
                _delay_ms(500);
                SEND_STRING("https://www.youtube.com/watch?v=LaEuyKs4-Kg");
                tap_code(KC_ENT);
            }
            return false;
        default:
            return true; // Process all other keycodes normally
    }
}

