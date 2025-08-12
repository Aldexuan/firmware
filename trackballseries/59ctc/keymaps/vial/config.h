/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
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
#pragma once

#ifdef VIA_ENABLE
/* VIA configuration. */
#define DYNAMIC_KEYMAP_LAYER_COUNT 10
#define DYNAMIC_KEYMAP_MACRO_COUNT 32
#ifdef VIAL_ENABLE
/** Vial-specific configuration. */

#define VIAL_KEYBOARD_UID { 0x6D, 0xA5, 0xCD, 0x8D, 0xC7, 0x3D, 0x7B, 0xA8 }
#endif // VIAL_ENABLE
#endif     // VIA_ENABLE

/* Charybdis-specific features. */

#ifdef POINTING_DEVICE_ENABLE
// Automatically enable the pointer layer when moving the trackball.  See also:
// - `CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS`
// - `CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD`
 #define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
#undef ROTATIONAL_TRANSFORM_ANGLE
#define ROTATIONAL_TRANSFORM_ANGLE 90
//交换x,y数据
//#define POINTING_DEVICE_ROTATION_90
//#define POINTING_DEVICE_ROTATION_90_RIGHT

// Double trackball build.
//#undef POINTING_DEVICE_RIGHT
//#define POINTING_DEVICE_LEFT
//反转Y轴数据
#define POINTING_DEVICE_INVERT_Y
#undef POINTING_DEVICE_INVERT_X
//#endif // POINTING_DEVICE_ENABLE

//#define CHARYBDIS_DRAGSCROLL_REVERSE_X
//要反转垂直滚动方向（即模仿 macOS“自然”滚动方向），请定义CHARYBDIS_DRAGSCROLL_REVERSE_Y
#define CHARYBDIS_DRAGSCROLL_REVERSE_Y

//#ifdef POINTING_DEVICE_ENABLE
// Enable pointer acceleration, which increases the speed by ~2x for large
// displacement, while maintaining 1x speed for slow movements.
// - `CHARYBDIS_POINTER_ACCELERATION_FACTOR`
//启用指针加速，这将使速度增加~2x
//位移，同时保持1倍的速度缓慢移动。
//#   define CHARYBDIS_POINTER_ACCELERATION_ENABLE

// Automatically enable the pointer layer when moving the trackball.  See also:
// - `CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS`
// - `CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD`
// #define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
#endif  // POINTING_DEVICE_ENABLE

