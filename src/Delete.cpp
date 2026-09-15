#include <Wire.h>
#include <Arduino.h>
#include "../include/Write.h"
#include "../include/Delete.h"
#include "../include/ReadAddress.h"
#define EEPROM_ADDRR 0x50
void Deleting(const int Index){
  const int recordsize = 128;
  const int starting = 5105;
  uint8_t recordnum = 0;
  Wire.begin();
      recordnum = readEEPROM(0x0001); // Read the current number of records from EEPROM
      writeEEPROM(EEPROM_ADDRR, 0x0001, recordnum-1); // Mark the record as deleted in the index
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
