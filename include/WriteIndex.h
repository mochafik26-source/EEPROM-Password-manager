#ifndef WRITE_EEPROM_H
#define WRITE_EEPROM_H

#include <Arduino.h>
#include <stdint.h>

void writeEEPROM(byte device, unsigned int address, byte data);

void WriteOnAddr(
    uint16_t Addresses[],
    const char Values[]
);

#endif