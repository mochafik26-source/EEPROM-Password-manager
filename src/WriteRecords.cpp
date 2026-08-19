#include <Wire.h>
#include "../include/Write.h"
#include <Arduino.h>
#include "../include/WriteRecords.h"

#define EEPROM_ADDRR 0x50



void writeRecords(uint16_t LogAddresses[],uint16_t PassAddresses[], const char Values[], uint8_t LoginCount, uint8_t PassCount) {
    
    // Storing Login
    // length of the Login
    writeEEPROM(EEPROM_ADDRR, LogAddresses[0], LoginCount-1);
  for (int i = 1; i < LoginCount; i++) {
      
        writeEEPROM(
            EEPROM_ADDRR,
            LogAddresses[i],
            Values[i-1]
        );
    }
    //Storing the password
    //length of the password
    writeEEPROM(EEPROM_ADDRR, PassAddresses[0], PassCount-1);
    for (uint8_t i = 1; i < PassCount; i++) {
        writeEEPROM(
            EEPROM_ADDRR,
            PassAddresses[i],
            Values[i-1]
        );
    }
}
