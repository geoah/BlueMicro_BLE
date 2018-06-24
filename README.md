# BlueMicro Firmware

A Keyboard Firmware for nRF52832 Boards with a pinout compatible with the Arduino Pro Micro

![BlueMicro](https://i.imgur.com/0SJpnoA.jpg)

**Compabible Hardware**  

* BlueMicro V1.0  (Serial TX/RX routed through D2 and D3; Designed for the ErgoTravel only)
* BlueMicro V1.1  (Compatible with more Keyboards - Serial TX/RX are routed separately) 
* BLE Phage       (Compatible with even more Keyboards due to its small size - Serial USB and PoLi Charger on board)
* BLE Phage Basic (Compatible with even more Keyboards due to its small size - Serial TX/RX are routed separately)
* Adafruit nRF52 Feather (Software compatible - not Pinout compabible)

Maintainer: [/u/jpconstantineau](https://github.com/jpconstantineau)  

# Preparing your build and flashing environment

Follow the instructions on the Arduino BSP Setup page for the [Adafruit nRF52 Feather](https://learn.adafruit.com/bluefruit-nrf52-feather-learning-guide/arduino-bsp-setup).  The BlueMicro_BLE firmware uses the same libraries and bootloader.

Depending on whether your hardware has on-board serial or not, you will need a serial USB adapter.  Note that the hardware is +3.3V.  As such, a standard +5V serial adapter may damage the nRF52 processor.

# Building the Firmware for your Keyboard

- Clone the Repository
- If the keyboard already exists in the Keyboards folder, copy the keyboard_config.h and keymap.h files to the "firmware" folder
- If example files are not available, take the keyboard config files that are the closest to yours.
- Make necessary adjustments to the two files.  keyboard_config.h contains the configuration that should be relevant to the keyboard, regardless of the keymap.   keymap.h is "your personal" keymap file.
- Compile the firmware
- Flash the firmware by serial.  Depending if the hardware uses the DTR line to automatically  reset the chip, you may have to manually press reset just before the flashing command gets called.  If it doesn't work, make sure that the the lines are crossed (TX -> RX and RX <- TX).

# Need to flash the bootloader?

Follow the instructions on the Flashing the Bootloader page for the [Adafruit nRF52 Feather](https://learn.adafruit.com/bluefruit-nrf52-feather-learning-guide/flashing-the-bootloader).  You will need a j-link and connect it to the SWD lines of the hardware.

# Want to help?
Contact /u/jpconstantineau on reddit.

https://github.com/adafruit/Adafruit_nRF52_Arduino

# Credits
====

The firmware uses the same Arduino Core as the [Adafruit nRF52 Feather Boards](https://github.com/adafruit/Adafruit_nRF52_Arduino)

The Adafruit NRF52 Arduino Core is based on [Arduino-nRF5](https://github.com/sandeepmistry/arduino-nRF5) by Sandeep Mistry, which in turn is based on the [Arduino SAMD Core](https://github.com/arduino/ArduinoCore-samd).

The following tools are used:

- Arduino IDE as the Editing Environment
- GCC ARM Embedded as the compiler
- Nordic's nrfutil 0.5.2 for flashing the firmware by serial interface
- J-Link for flashing the bootloader by SWD interface