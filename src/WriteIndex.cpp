#include <Wire.h>
#include "../include/Write.h"
#include "../include/Indexes.h"
#include <Arduino.h>
#include "../include/WriteIndex.h"

#define EEPROM_ADDRR 0x50



void WriteOnAddr(
    uint16_t Addresses[],
    const char Values[],
    uint8_t Position
) {
    Wire.begin();
    // set the position of the record.
    writeEEPROM(EEPROM_ADDRR, Addresses[0], Position);

    // Write values starting at Addresses[1]
    for (uint8_t i = 0; Values[i] != '\0'; i++) {
        if (i + 1 >= AddressCount) {
            break;
        }

        writeEEPROM(
            EEPROM_ADDRR,
            Addresses[i + 1],
            Values[i]
        );
    }
}

