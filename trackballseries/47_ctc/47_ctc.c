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

#include "47_ctc.h"

// clang-format off
#ifdef RGB_MATRIX_ENABLE
/**
     0     1   2   3   4  5   6             7    8   9   10  11  12  13
 *   0   17  34  51  68  85 102           119  136 153  170 187 204 221
 *
 * ╭────────────────────────╮                 ╭────────────────────────╮
 *    3   4   11  12  19  20                     42  41  36  35  29  28       0
 * ├────────────────────────┤                 ├────────────────────────┤
 *    2   5   10  13  18  21                     43  40  37  34  30  27       13
 * ├────────────────────────┤                 ├────────────────────────┤
 *    1   6    9  14  17  22                     44  39  38  33  31  26       26
 * ├────────────────────────┤                 ├────────────────────────┤
 *    0   7    8  15                        46  45               32  25       39
 * ╰────────────────────────╯                 ╰────────────────────────╯
                       16  23 24                                              52

 *                     ╰────────────╯ ╰────────────╯
*
 *
 * Note: the LED config simulates 58 LEDs instead of the actual 56 to prevent
 * confusion when testing LEDs during assembly when handedness is not set
 * correctly.  Those fake LEDs are bound to the physical bottom-left corner.
 */
led_config_t g_led_config = { {
    /* Key Matrix to LED index. */
    // Left split.
    {      3,      4,     11,     12,     19,      20,  NO_LED}, // Num row
    {      2,      5,     10,     13,     18,      21 , NO_LED}, // Top row
    {      1,      6,     9,      14,     17,      22 , NO_LED}, // Middle row
    {      0,      7,     8,      15,     16,      23,  24}, // Bottom row
    // Right split.
    {     28,     29,       35,         36,         41,      42, NO_LED}, // Num row
    {     27,     30,       34,         37,         40,      43, NO_LED}, // Top row
    {     26,     31,       33,         38,         39,      44, NO_LED}, // Middle row
    {     25,     32,       NO_LED,     NO_LED,     NO_LED,  45, 46 }, // Bottom row
}, {
    /* LED index to physical position. */
    // Left split.
    /* index=0  */ {   0,   39 },   {   0,  26 },   {   0,  13 },   {   0,  0 },  // col 1 (left most)
    /* index=4  */ {  17,  0 },   {  17,  13 },   {  17,   26 },  {   17,  39 }, // col 2
    /* index=8  */ {  34,   39 },   {  34,  26 },   {  34,  13 },   {  34,  0 },
    /* index=12 */ {  51,  0 },   {  51,  13 },   {  51,   26 },  {   51,  39 },
    /* index=16 */ {  68,   52 },   {  68,  30 },   {  68,  15 },   {  68,  5 },
    /* index=16 */ {  85,   5 },   {  85,  15 },   {  85,  30 },   {  85,  55 },
    /* index=20 */ {  102,   58 },
    // Right split.
    /* index=37 */ { 221,   39 },   { 221,  26 },    { 221,  13 },   { 221,  0 },
    /* index=41 */ { 204,  0 },    { 204,  13 },   { 204,   26 }, { 204,   39 },
    /* index=45 */ { 187,   26 },   { 187,  13 },    { 187,  0 },
    /* index=49 */ { 170,  0 },   {   170,  13 },{ 170,   26 },
                   { 153,   26 },  { 153,   13 }, { 153,   0 },
                   { 136,   0 },{ 136,   13 },{ 136,   26 },
                   { 130,   39 },{ 119,   40 }

}, {
    /* LED index to flag. */
    // Left split.
    /* index=0  */ LED_FLAG_MODIFIER, LED_FLAG_MODIFIER, LED_FLAG_MODIFIER, LED_FLAG_MODIFIER, // col 1
    /* index=4  */ LED_FLAG_MODIFIER, LED_FLAG_MODIFIER, LED_FLAG_MODIFIER, LED_FLAG_MODIFIER, // col 2
    /* index=8  */ LED_FLAG_MODIFIER, LED_FLAG_MODIFIER, LED_FLAG_MODIFIER, LED_FLAG_MODIFIER,
    /* index=16 */ LED_FLAG_MODIFIER, LED_FLAG_MODIFIER, LED_FLAG_MODIFIER, LED_FLAG_MODIFIER,
    /* index=20 */ LED_FLAG_MODIFIER, LED_FLAG_MODIFIER, LED_FLAG_MODIFIER, LED_FLAG_MODIFIER,
    /* index=20 */ LED_FLAG_MODIFIER, LED_FLAG_MODIFIER, LED_FLAG_MODIFIER, LED_FLAG_MODIFIER,
    /* index=24 */ LED_FLAG_MODIFIER,
    // Right split.
    /* index=29 */ LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, // col 12
    /* index=29 */ LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, // col 12
    /* index=33 */ LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,  // col 11
    /* index=37 */ LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    /* index=41 */ LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    /* index=45 */ LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,
    /* index=49 */ LED_FLAG_KEYLIGHT
} };
#endif
// clang-format on


