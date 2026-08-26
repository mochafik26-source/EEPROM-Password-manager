#include "../include/ReadingRecord.h"
#include <Arduino.h>
#include <Wire.h>
#include "../include/ReadAddress.h"
#include <stdint.h>
#include <stddef.h>
String ReadingRecord(int startAddress) {
  Wire.begin();
    const int Recordsize = 128;
    const int starting = 5105;
    String login = "";
       byte loginlen = readEEPROM(starting + Recordsize * startAddress);

    for(int i = starting + Recordsize * startAddress + 1; i < starting + Recordsize * startAddress + 1 + loginlen; i++){
      
      // byte passlen = readEEPROM(i +64);
        byte letter = readEEPROM((uint16_t)i);
        if(letter > 32){
        login += (char)letter; 
       
        
      }
      
      

    }

    return login;
  }