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

#include "61trs.h"

// clang-format off
#ifdef RGB_MATRIX_ENABLE
/**
 * \brief LEDs index.
     0     1   2   3   4  5   6             7    8   9   10  11  12  13
 *   0   17  34  51  68  85 102           119  136 153  170 187 204 221
 0 ╭────────────────────────╮                 ╭────────────────────────╮
      0   9   10  19  20  29                     60  50  49  42  41  32    0   0
13 ├────────────────────────┤                 ├────────────────────────┤
      1   8   11  18  21  28                     59  51  48  43  40  33   13   1
26 ├────────────────────────┤                 ├────────────────────────┤
      2   7   12  17  22  27                     58  52  47  44  39  34   26   2
 39├────────────────────────┤                 ├────────────────────────┤
      3   6   13  16  23  26   30          56    57  53  46  45  38   35   39  3
 52╰────────────────────────╯                 ╰────────────────────────╯
 *   4    5   14  15                                             37   36   52  4
 *                    24  25   31       55    54                            65  5

 */
led_config_t g_led_config = {
{
    /* Key Matrix to LED index. */
    // Left split.
    {      0,      9,     10,     19,     20,     29,     NO_LED }, // Num row
    {      1,      8,     11,     18,     21,     28,     NO_LED }, // Top row
    {      2,      7,     12,     17,     22,     27,     NO_LED }, // Middle row
    {      3,      6,     13,     16,     23,     26,     30 }, // Bottom row
    {      4,      5,     14,     15,     24,     25,     31 }, // Thumb cluster


    {     32,     41,     42,     49,         50,     60,     NO_LED }, // Num row
    {     33,     40,     43,     48,         51,     59,     NO_LED }, // Top row
    {     34,     39,     44,     47,         52,     58,     NO_LED }, // Middle row
    {     35,     38,     45,     46,         53,     57,     56  }, // Bottom row
    {     36,     37,     NO_LED, NO_LED,     54,     55,     NO_LED  } // Thumb cluster
},
{
    // Left split.
    /* index=0  */ {   0,   0 },   {   0,  13 },   {   0,  26 },   {   0,  39 },   {   0,  52 }, // col 1 (left most)
    /* index=4  */ {  17,  52 },   {  17,  39 },   {  17,  26 },   {  17,   13 },  {   17,  0 }, // col 2
    /* index=8  */ {  34,   0 },   {  34,  13 },   {  34,  26 },   {  34,  39 },   {   34,  52 },
    /* index=12 */ {  51,  52 },   {  51,  39 },   {  51,  26 },   {  51,   13 },  {   51,  0 },
    /* index=16 */ {  68,   0 },   {  68,  13 },   {  68,  26 },   {  68,  39 },   {  68,  65 },
    /* index=20 */ {  85,   65 },  {  85,  39 },   {  85,  26 },   {  85,  13 },   {  85,  0 },
    /* index=24 */ { 102,  39 },   { 102,  65 },

     // 左边旋钮，右边灯矩阵
    /* index=29 */ { 221,   0 },   { 221,  13 },    { 221,  26 },   { 221,  39 },  {   221,  52 }, // col 12 (right most)
    /* index=33 */ { 204,  52 },   { 204,  39 },    { 204,  26 },   { 204,   13 }, {   204,  0 },// col 11
    /* index=37 */ { 187,   0 },   { 187,  13 },    { 187,  26 },   { 187,  39 },
    /* index=41 */ {   170,  39 }, { 170,  26 },    { 170,  13 },   { 170,   0 },
    /* index=45 */ { 153,   0 },   { 153,  13 },    { 153,  26 },   { 153,  39 },  { 125,  52 },
    /* index=49 */ { 115,  65 },   { 119,  39 },    { 136,  39 },   {   136,  26 },{ 136,   13 },
                   { 136,   0 }

},
{
    /* LED index to flag. */
    // Left split.
    /* index=0  */ LED_FLAG_MODIFIER, LED_FLAG_MODIFIER, LED_FLAG_MODIFIER, LED_FLAG_MODIFIER,LED_FLAG_MODIFIER, // col 1
    /* index=4  */ LED_FLAG_MODIFIER, LED_FLAG_MODIFIER, LED_FLAG_MODIFIER, LED_FLAG_MODIFIER,LED_FLAG_MODIFIER, // col 2
    /* index=8  */ LED_FLAG_MODIFIER, LED_FLAG_MODIFIER, LED_FLAG_MODIFIER, LED_FLAG_MODIFIER,LED_FLAG_MODIFIER,
    /* index=12 */ LED_FLAG_MODIFIER, LED_FLAG_MODIFIER, LED_FLAG_MODIFIER, LED_FLAG_MODIFIER,LED_FLAG_MODIFIER,
    /* index=16 */ LED_FLAG_MODIFIER, LED_FLAG_MODIFIER, LED_FLAG_MODIFIER, LED_FLAG_MODIFIER,LED_FLAG_MODIFIER,
    /* index=20 */ LED_FLAG_MODIFIER, LED_FLAG_MODIFIER, LED_FLAG_MODIFIER, LED_FLAG_MODIFIER,LED_FLAG_MODIFIER,
    /* index=24 */ LED_FLAG_MODIFIER, LED_FLAG_MODIFIER,
    // Right split.
    /* index=29 */ LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, // col 12
    /* index=33 */ LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,// col 11
    /* index=37 */ LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    /* index=41 */ LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT ,LED_FLAG_KEYLIGHT,
    /* index=45 */ LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,LED_FLAG_KEYLIGHT,
    /* index=49 */ LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,LED_FLAG_KEYLIGHT
} };
#endif
// clang-format on


