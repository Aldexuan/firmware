## MCKWorkshop：<br/>
### trackballseries firmware<br/>
* 本系列layout参考了:[keyball](https://github.com/Yowkees/keyball)<br/>
* firmware代码是基于[Charybdis](https://bastardkb.com)的源码进行二次开发，增加了一些实用性功能<br/>
* 后缀为ctc的就是双type c连接的版本，不带ctc的为trs音频线连接版本<br/>
* 如果你的键盘名称后缀大版本带V2/V3使用的传感器是PMW3389传感器<br/>
* 如果不带后缀，只有键盘名使用的是PMW3360传感器<br/>
* 如果想编译自己的固件，只需要根据键盘后缀判断自己的传感器，然后调整各配列下v2/splinky/rules.mk中的POINTING_DEVICE_DRIVER即可<br/>

## 编译基本信息：
```
Run echo "===== QMK CLI Version ====="
===== QMK CLI Version =====
1.2.0

===== Vial-QMK Source Version =====
00fc4627

===== Vial-QMK Commit =====
00fc4627cd038ac9b7e9b8bf2b40b50e9e88aecb

===== Python Version =====
Python 3.14.3

===== AVR GCC Version =====
avr-gcc (crosstool-NG 1.27.0.82_7f9d704 - qmk/qmk_toolchains @ a55a2b0) 15.2.0

===== ARM GCC Version =====
arm-none-eabi-gcc (crosstool-NG 1.27.0.82_7f9d704 - qmk/qmk_toolchains @ a55a2b0) 15.2.0

===== Build OS =====
PRETTY_NAME="Debian GNU/Linux 13 (trixie)"
```