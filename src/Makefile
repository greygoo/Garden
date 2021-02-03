#BOARD_TAG   = nano
#BOARD_SUB   = atmega328
BOARD_TAG   = pro
BOARD_SUB   = 16MHzatmega328

ARDUINO_LIBS = DHT-sensor-library Arduino-Temperature-Control-Library Adafruit_Sensor OneWire rc-switch TimerOne SPI Wire EEPROM GravityTDS ShiftRegister74HC595 FlowMeter
ARDUINO_PORT = /dev/serial0

PWD = $(shell pwd)
USER_LIB_PATH = $(PWD)/lib


include ./Arduino-Makefile/Arduino.mk

