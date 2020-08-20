/*
Copyright 2018 <Pierre Constantineau>

3-Clause BSD License

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/
#include "keymap.h"

#define CTRLTAB XXXXXXX

#if KEYBOARD_SIDE == MASTER
std::array<std::array<Key, MATRIX_COLS>, MATRIX_ROWS> matrix = {KEYMAP(
    KC_1,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,  KC_Y, 
    KC_2,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,  KC_H,
    KC_3,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,  KC_N,
    KC_4,  KC_5,    KC_6,    KC_7,    KC_8,    KC_9,  KC_0 
)};
void setupKeymap() {
   // no layers for master keymap
   // this is a keymap that's used for testing that each key is responding properly to key presses
   // flash this keymap to both left and right to test whether each half works properly.
   // once tested, you can flash the left and right to their respective halves.
}
#endif

#if KEYBOARD_SIDE == LEFT
/* Qwerty
 * ,-----------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  | 
 * |------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |
 * |------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |
 * |------+------+------+------+------+------+------.
 * |      |      |      |      | Alt  | Gui  | Spc  |
 * `-----------------------------------------+------'
 */
std::array<std::array<Key, MATRIX_COLS>, MATRIX_ROWS> matrix = {KEYMAP(
    KC_ESC  , KC_Q    , KC_W    , KC_E    , KC_R    , KC_T    , _______ , \
    CTRLTAB , KC_A    , KC_S    , KC_D    , KC_F    , KC_G    , _______ , \
    KC_LSFT , KC_Z    , KC_X    , KC_C    , KC_V    , KC_B    , _______ , \
    _______ , _______ , _______ , _______ , KC_LALT , KC_LGUI , KC_SPC \
)};

void setupKeymap() {

    uint32_t qwerty_hold[MATRIX_ROWS][MATRIX_COLS] = KEYMAP( \
        _______ , _______ , _______ , _______ , _______ , _______ , _______ , \
        KC_LCTL , _______ , _______ , _______ , _______ , _______ , _______ , \
        _______ , _______ , _______ , _______ , _______ , _______ , _______ , \
        _______ , _______ , _______ , _______ , _______ , _______ , _______ \
    );

    uint32_t qwerty_tap[MATRIX_ROWS][MATRIX_COLS] = KEYMAP( \
        _______ , _______ , _______ , _______ , _______ , _______ , _______ , \
        KC_TAB  , _______ , _______ , _______ , _______ , _______ , _______ , \
        _______ , _______ , _______ , _______ , _______ , _______ , _______ , \
        _______ , _______ , _______ , _______ , _______ , _______ , _______ \
    );

    /* Layer 1 (Raise)
    * ,-----------------------------------------.
    * | `    |   1  |   2  |   3  |   4  |   5  | 
    * |------+------+------+------+------+------|
    * | Ctrl |      |      |      |      |      |
    * |------+------+------+------+------+------|
    * | Shift|      |      |      |      |      |
    * |------+------+------+------+------+------+------.
    * |      |      |      |      | Alt  | Gui  | Spc  |
    * `-----------------------------------------+------'
    */
    uint32_t layer1[MATRIX_ROWS][MATRIX_COLS] = KEYMAP( \
        KC_GRAVE, KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , _______ , \
        CTRLTAB , _______ , _______ , _______ , _______ , _______ , _______ , \
        KC_LSFT , _______ , _______ , _______ , _______ , _______ , _______ , \
        _______ , _______ , _______ , _______ , KC_LALT , KC_LGUI , KC_SPC \
    );

    /* Layer 2 (lower)
    * ,-----------------------------------------.
    * |  ~   |   !  |   @  |   #  |   $  |   %  |
    * |------+------+------+------+------+------|
    * | Ctrl |      |      |      |      |      |
    * |------+------+------+------+------+------|
    * | Shift|      |      |      |      |      |
    * |------+------+------+------+------+------+------.
    * |      |      |      |      | Alt  | Gui  | Spc  |
    * `-----------------------------------------+------'
    */
    uint32_t layer2[MATRIX_ROWS][MATRIX_COLS] = KEYMAP( \
        KC_TILD , KC_EXLM , KC_AT   , KC_HASH , KC_DLR  , KC_PERC , _______ , \
        CTRLTAB , _______ , _______ , _______ , _______ , _______ , _______ , \
        KC_LSFT , _______ , _______ , _______ , _______ , _______ , _______ , \
        _______ , _______ , _______ , _______ , KC_LALT , KC_LGUI , KC_SPC \
    );

    /*
     * add the other layers on the regular presses.
     */
    for (int row = 0; row < MATRIX_ROWS; ++row)
    {
        for (int col = 0; col < MATRIX_COLS; ++col)
        {
            matrix[row][col].addActivation(_L1, Method::PRESS, layer1[row][col]);
            matrix[row][col].addActivation(_L2, Method::PRESS, layer2[row][col]);
            matrix[row][col].addActivation(_QWERTY, Method::MT_HOLD, qwerty_hold[row][col]);
            matrix[row][col].addActivation(_QWERTY, Method::DT_TAP,  qwerty_tap[row][col]);
        }
    }
}
#endif  // left

#if KEYBOARD_SIDE == RIGHT

/* Qwerty
 *        ,-----------------------------------------.
 *        | Y    | U    | I    | O    | P    | Bksp |
 *        |------+------+------+------+-------------|
 *        | H    | J    | K    | L    | ;    | "    |
 *        |------+------+------+------+------+------|
 *        | N    | M    | ,    | .    | /    | Entr |
 * .------+------+------+------+------+------+------|
 * | Spc  | L(1) | L(2) |      |      |      |      |
 * '------+-----------------------------------------'
 */
std::array<std::array<Key, MATRIX_COLS>, MATRIX_ROWS> matrix = {KEYMAP(
    _______ , KC_Y    , KC_U    , KC_I    , KC_O    , KC_P    , _______ , \
    _______ , KC_H    , KC_J    , KC_K    , KC_L    , KC_SCLN , KC_QUOT , \
    _______ , KC_N    , KC_M    , KC_COMMA, KC_DOT  , KC_SLSH , KC_ENT  , \
    KC_BSPC , LAYER_1 , LAYER_2 , _______ , _______ , _______ , _______ \
)};

void setupKeymap() {

    uint32_t qwerty_hold[MATRIX_ROWS][MATRIX_COLS] = KEYMAP( \
        _______ , _______ , _______ , _______ , _______ , _______ , _______ , \
        _______ , _______ , _______ , _______ , _______ , _______ , _______ , \
        _______ , _______ , _______ , _______ , _______ , _______ , _______ , \
        _______ , _______ , _______ , _______ , _______ , _______ , _______ \
    );

    uint32_t qwerty_tap[MATRIX_ROWS][MATRIX_COLS] = KEYMAP( \
        _______ , _______ , _______ , _______ , _______ , _______ , _______ , \
        _______ , _______ , _______ , _______ , _______ , _______ , _______ , \
        _______ , _______ , _______ , _______ , _______ , _______ , _______ , \
        _______ , _______ , _______ , _______ , _______ , _______ , _______ \
    );

    /* Layer 1 (Raise)
    *        ,-----------------------------------------.
    *        | 6    | 7    | 8    | 9    | 0    | Del  |
    *        +------+------+------+------+-------------|
    *        | Left | Down | Up   | Rght |      |      |
    *        +------+------+------+------+------+------|
    *        |      |      |      |      |      |      |
    * .------+------+------+------+------+------+------|
    * | Spc  | L(1) | L(2) |      |      |      |      |
    * '------+-----------------------------------------'
    */
    uint32_t layer1[MATRIX_ROWS][MATRIX_COLS] = KEYMAP( \
        _______ , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , _______ , \
        _______ , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT , _______ , _______ , \
        _______ , _______ , _______ , _______ , _______ , _______ , _______ , \
        KC_BSPC , LAYER_1 , LAYER_2 , _______ , _______ , _______ , _______ \
    );

    /* Layer 2 (lower)
    *        ,-----------------------------------------.
    *        | ^    | &    | *    | (    | )    | Del  |
    *        |------+------+------+------+-------------|
    *        | -    | =    | [    | ]    | \    |      |  
    *        |------+------+------+------+------+------|
    *        | _    | +    | {    | }    | |    |      |
    * .------+------+------+------+------+------+------|
    * | Spc  | L(1) | L(2) |      |      |      |      |
    * '------+-----------------------------------------'
    */
    uint32_t layer2[MATRIX_ROWS][MATRIX_COLS] = KEYMAP( \
        _______ , KC_CIRC , KC_AMPR , KC_ASTR , KC_LPRN , KC_RPRN , _______ ,  \
        _______ , KC_MINS , KC_EQL  , KC_LBRC , KC_RBRC , KC_BSLS , _______ , \
        _______ , KC_UNDS , KC_PLUS , KC_LCBR , KC_RCBR , KC_PIPE , _______ , \
        KC_BSPC , LAYER_1 , LAYER_2 , _______ , _______ , _______ , _______ \
    );

    /*
     * add the other layers
     */
    for (int row = 0; row < MATRIX_ROWS; ++row)
    {
        for (int col = 0; col < MATRIX_COLS; ++col)
        {
            matrix[row][col].addActivation(_L1, Method::PRESS, layer1[row][col]);
            matrix[row][col].addActivation(_L2, Method::PRESS, layer2[row][col]);
            matrix[row][col].addActivation(_QWERTY, Method::MT_HOLD, qwerty_hold[row][col]);
            matrix[row][col].addActivation(_QWERTY, Method::DT_TAP,  qwerty_tap[row][col]);
        }
    }

}
#endif
