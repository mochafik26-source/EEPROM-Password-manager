#include <Wire.h>
#include "../include/Write.h"
#include <Arduino.h>
#include "../include/WriteRecords.h"

#define EEPROM_ADDRR 0x50



void writeRecords(uint16_t LogAddresses[],uint16_t PassAddresses[], const char Values[], uint8_t LoginCount, uint8_t PassCount) {
    
    // Storing Login
    for (uint8_t i = 0; i < LoginCount; i++) {
        writeEEPROM(
            EEPROM_ADDRR,
            LogAddresses[i],
            Values[i]
        );
    }
    //Storing the password
    for (uint8_t i = 0; i < PassCount; i++) {
        writeEEPROM(
            EEPROM_ADDRR,
            PassAddresses[i],
            Values[i]
        );
    }
}
