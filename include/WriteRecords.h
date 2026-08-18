#ifndef RECORDS_EEPROM_H
#define RECORDS_EEPROM_H

#include <Arduino.h>
#include <stdint.h>

void writeEEPROM(byte device, unsigned int address, byte data);

void writeRecords(
   uint16_t LogAddresses[],uint16_t PassAddresses[], const char Values[], uint8_t LoginCount, uint8_t PassCount
);

#endif