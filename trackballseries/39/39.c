/*
 * Copyright 2020 Christopher Courtney <drashna@live.com> (@drashna)
 * Copyright 2021 Quentin LEBASTARD <qlebastard@gmail.com>
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Publicw License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "39.h"

// clang-format off
#ifdef RGB_MATRIX_ENABLE
/**
 * \brief LEDs index.
     0     1   2   3   4  5                6      7    8   9   10  11
 *   0   17  34  51  68  85              102    119  136 153  170 187
 * ╭────────────────────────╮                 ╭────────────────────────╮
 *    0   7   8  15  16                         34    33  28  27  21       0   0
 * ├────────────────────────┤                 ├─────  ───────────────────┤
 *    1   6   9  14  17                         35    32  29  26  22       13   1
 * ├────────────────────────┤                 ├─────  ───────────────────┤
 *    2   5   10  13  18                        36    31  30  25  23       26   2
 * ├────────────────────────┤                 ├────────────────────────┤
 *    3   4   11  12  19                        37                24       39  3
 * ╰─────────────────────20╯              38╰────────────────────────╯      52
*
 *
 * Note: the LED config simulates 58 LEDs instead of the actual 56 to prevent
 * confusion when testing LEDs during assembly when handedness is not set
 * correctly.  Those fake LEDs are bound to the physical bottom-left corner.
 */
led_config_t g_led_config = { {
    /* Key Matrix to LED index. */
    // Left split.
    {      0,      7,     8,     15,     16,      NO_LED}, // Num row
    {      1,      6,     9,     14,     17,     NO_LED }, // Top row
    {      2,      5,     10,     13,     18,     NO_LED }, // Middle row
    {      3,      4,     11,     12,     19,     20}, // Bottom row
    // Right split.
    {     21,     27,       28,         32,         34,    NO_LED }, // Num row
    {     22,     26,       29,         32,         35,    NO_LED }, // Top row
    {     23,     25,       30,         31,         36,    NO_LED }, // Middle row
    {     24,     NO_LED,   NO_LED,     NO_LED,     37,    38  }, // Bottom row
}, {
    /* LED index to physical position. */
    // Left split.
    /* index=0  */ {   0,   0 },   {   0,  13 },   {   0,  26 },   {   0,  39 },  // col 1 (left most)
    /* index=4  */ {  17,  39 },   {  17,  26 },   {  17,   13 },  {   17,  0 }, // col 2
    /* index=8  */ {  34,   0 },   {  34,  13 },   {  34,  26 },   {  34,  39 },
    /* index=12 */ {  51,  39 },   {  51,  26 },   {  51,   13 },  {   51,  0 },
    /* index=16 */ {  68,   0 },   {  68,  13 },   {  68,  26 },   {  68,  39 },
    /* index=20 */ {  85,   52 },
    // Right split.
    /* index=37 */ { 187,   0 },   { 187,  13 },    { 187,  26 },   { 187,  39 },
    /* index=41 */ { 170,  26 },    { 170,  13 },   { 170,   0 },
    /* index=45 */ { 153,   0 },   { 153,  13 },    { 153,  26 },
    /* index=49 */ { 136,  26 },   {   136,  13 },{ 136,   0 },
                   { 119,   0 },  { 119,   13 }, { 119,   26 },{ 119,   39 },
                   { 102,   52 }

}, {
    /* LED index to flag. */
    // Left split.
    /* index=0  */ LED_FLAG_MODIFIER, LED_FLAG_MODIFIER, LED_FLAG_MODIFIER, LED_FLAG_MODIFIER, // col 1
    /* index=4  */ LED_FLAG_MODIFIER, LED_FLAG_MODIFIER, LED_FLAG_MODIFIER, LED_FLAG_MODIFIER, // col 2
    /* index=8  */ LED_FLAG_MODIFIER, LED_FLAG_MODIFIER, LED_FLAG_MODIFIER, LED_FLAG_MODIFIER,
    /* index=16 */ LED_FLAG_MODIFIER, LED_FLAG_MODIFIER, LED_FLAG_MODIFIER, LED_FLAG_MODIFIER,
    /* index=20 */ LED_FLAG_MODIFIER, LED_FLAG_MODIFIER, LED_FLAG_MODIFIER, LED_FLAG_MODIFIER,
    /* index=24 */ LED_FLAG_MODIFIER,
    // Right split.
    /* index=29 */ LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, // col 12
    /* index=33 */ LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,  // col 11
    /* index=37 */ LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    /* index=41 */ LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    /* index=45 */ LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,
    /* index=49 */ LED_FLAG_KEYLIGHT
} };
#endif
// clang-format on


