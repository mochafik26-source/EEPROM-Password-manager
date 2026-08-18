#ifndef WRITE_EEPROM_H
#define WRITE_EEPROM_H

#include <Arduino.h>
#include <stdint.h>


void WriteOnAddr(
    uint16_t Addresses[],
    const char Values[],
    uint8_t Position
);

#endif