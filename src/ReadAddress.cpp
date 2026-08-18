#include <Arduino.h>
#include <Wire.h>

byte readEEPROM(unsigned int address){

  Wire.beginTransmission(0x50);

  Wire.write(address >> 8);
  Wire.write(address & 0xFF);

  Wire.endTransmission();

  Wire.requestFrom(0x50, 1);

  if (Wire.available()) {
    return Wire.read();
  }

  return 0;
}
