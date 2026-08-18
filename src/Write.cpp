#include <Wire.h>
#include <Arduino.h>
#include "../include/Write.h"
void writeEEPROM(byte device, unsigned int address, byte data) {
    Wire.beginTransmission(device);

    Wire.write(address >> 8);
    Wire.write(address & 0xFF);
    Wire.write(data);

    Wire.endTransmission();

    delay(5);
}