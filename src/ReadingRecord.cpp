#include "../include/ReadingRecord.h"
#include <Arduino.h>
#include <Wire.h>
#include "../include/ReadAddress.h"
#include <stdint.h>
#include <stddef.h>
Record ReadingRecord(int startAddress) {
  Wire.begin();
    const int Recordsize = 128;
    const int starting = 5105;
    String login = "";
    String pass = "";
    byte loginlen = readEEPROM(starting + Recordsize * startAddress);

    for(int i = starting + Recordsize * startAddress + 1; i < starting + Recordsize * startAddress + 1 + loginlen; i++){
      
        
        byte letter = readEEPROM((uint16_t)i);
        if(letter > 32){
        login += (char)letter;  
      }
    }
    byte passlen = readEEPROM(64 + starting + Recordsize * startAddress);
 for(int i = starting + Recordsize * startAddress + 65; i < starting + Recordsize * startAddress + passlen + 65; i++){
      
        
        byte letter = readEEPROM((uint16_t)i);
        if(letter > 32){
        pass += (char)letter;  
      }
    }
    return {login, pass};
  }