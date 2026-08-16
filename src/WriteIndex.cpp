#include <Wire.h>
#include "../include/Indexes.h"
#include <Arduino.h>
#include "../include/WriteIndex.h"

#define EEPROM_ADDRR 0x50

void writeEEPROM(byte device, unsigned int address, byte data) {
    Wire.beginTransmission(device);

    Wire.write(address >> 8);
    Wire.write(address & 0xFF);
    Wire.write(data);

    Wire.endTransmission();

    delay(5);
}

void WriteOnAddr(
    uint16_t Addresses[],
    const char Values[]
) {
    Wire.begin();
    // Mark EEPROM as Taken
    writeEEPROM(EEPROM_ADDRR, Addresses[0], 1);

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

