#include <Wire.h>
#include <Arduino.h>
#include "../include/WriteRecords.h"
#include "../include/Write.h"
#include "../include/Delete.h"
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
}
