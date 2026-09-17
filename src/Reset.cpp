#include <Wire.h>
#include <Arduino.h>
#include "../include/Write.h"
#include "../include/Reset.h"
#define EEPROM_ADDRR 0x50
void Reset(){
    const int MemorySize = 31999;
    Wire.begin();
    for(int i = 0; i < MemorySize; i++){
        writeEEPROM(
              EEPROM_ADDRR,
              i,
              0
        );
    }
}