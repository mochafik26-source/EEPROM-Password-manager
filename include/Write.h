#ifndef WRITE_EEPROM_H
#define WRITE_EEPROM_H

#include <Arduino.h>
#include <Wire.h>

void writeEEPROM(byte device, unsigned int address, byte data);

#endif
