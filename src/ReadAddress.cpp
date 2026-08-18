#include <Wire.h>
#include "../include/ReadAddress.h"
#include <Arduino.h>
byte readEEPROM(uint16_t address) {
    Wire.beginTransmission(0x50);
    Wire.write(address >> 8);
    Wire.write(address & 0xFF);
    Wire.endTransmission();

    Wire.requestFrom(0x50, 1);

    return Wire.read();
}