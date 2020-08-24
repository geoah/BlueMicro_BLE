/*
Copyright 2018 <Pierre Constantineau>

3-Clause BSD License

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR 
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/
#ifndef KEYBOARD_CONFIG_H
#define KEYBOARD_CONFIG_H
#include "hardware_variants.h"
#define HARDWARE_MAPPING  BLUEMICROV2_0C
#include "breakout_mapping.h"

#define KEYBOARD_SIDE LEFT
// CHANGE THIS FOR THE KEYBOARD TO MATCH WHAT IS BEING FLASHED. OPTIONS: LEFT  RIGHT  MASTER

#define DEVICE_NAME_R "minisplit_R"
#define DEVICE_NAME_L "minisplit_L"
#define DEVICE_NAME_M "minisplit"
#define DEVICE_MODEL "minisplit_v1.0"
#define MANUFACTURER_NAME "github.com/kata0510/minisplit"

/* HARDWARE DEFINITION*/
/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 7

#define MATRIX_ROW_PINS { D7, E6, B4, B5 }
#define MATRIX_COL_PINS { F5, F6, F7, B1, B3, B2, B6 }
#define UNUSED_PINS {}

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW
// #define BACKLIGHT_LED_PIN B5
#define DEFAULT_PWM_VALUE 10000            // PWM intensity  max is 10000
#define BACKLIGHT_PWM_ON 0

#define DEBOUNCETIME 5

#if KEYBOARD_SIDE == RIGHT
#define KEYMAP( \
      k00, k01, k02, k03, k04, k05, k06, \
      k10, k11, k12, k13, k14, k15, k16, \
      k20, k21, k22, k23, k24, k25, k26, \
      k30, k31, k32, k33, k34, k35, k36 \
) \
{ \
    { k06, k05, k04, k03, k02, k01, k00 }, \
    { k16, k15, k14, k13, k12, k11, k10 }, \
    { k26, k25, k24, k23, k22, k21, k20 }, \
    { k36, k35, k34, k33, k32, k31, k30 } \
}
#else
#define KEYMAP( \
      k00, k01, k02, k03, k04, k05, k06, \
      k10, k11, k12, k13, k14, k15, k16, \
      k20, k21, k22, k23, k24, k25, k26, \
      k30, k31, k32, k33, k34, k35, k36 \
) \
{ \
    { k00, k01, k02, k03, k04, k05, k06 }, \
    { k10, k11, k12, k13, k14, k15, k16 }, \
    { k20, k21, k22, k23, k24, k25, k26 }, \
    { k30, k31, k32, k33, k34, k35, k36 } \
} 
#endif

#endif /* KEYBOARD_CONFIG_H */
