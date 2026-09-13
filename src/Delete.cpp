#include <Wire.h>
#include <Arduino.h>
#include "../include/Write.h"
#include "../include/WriteRecords.h"
#define EEPROM_ADDRR 0x50
void Deleting(const int Index){
  const int recordsize = 128;
  const int starting = 5105;

  Wire.begin();

  for(int i = starting + recordsize * Index; i < starting +recordsize * Index +128; i++){
    
    writeEEPROM(
              EEPROM_ADDRR,
              i,
              0
        ); 
  }
  writeEEPROM(
              EEPROM_ADDRR,
              64 + 24 * Index,
              255
        ); 
  for(int s = 65 + 24 * Index; s < 65 + 24 * Index + 24; s++){
     
    writeEEPROM(
              EEPROM_ADDRR,
              s,
              0
        ); 
  }
}
