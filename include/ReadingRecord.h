#ifndef READADD_EEPROM_H
#define READADD_EEPROM_H


#include <Arduino.h>
#include <Wire.h>
#include "../include/ReadAddress.h"
struct Record {
    std::string login;
    std::string password;
};

std::list<Record> ReadingRecord(int startAddress);
#endif
