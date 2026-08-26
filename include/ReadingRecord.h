#ifndef READADD_EEPROM_H
#define READADD_EEPROM_H

#include <stdint.h>
#include <stddef.h>
#include <Arduino.h>
#include <Wire.h>
#include "../include/ReadAddress.h"
struct Record {
    String log;
    String pass;
};

String ReadingRecord(int startAddress);
#endif
