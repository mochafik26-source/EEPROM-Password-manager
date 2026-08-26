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
 
    for(int i = starting; i < 32000; i+= Recordsize){
      login = "";
      byte loginlen = readEEPROM(i);
      // byte passlen = readEEPROM(i +64);
      for(int s = i + 1; s < i + loginlen + 1; s++){
        byte letter = readEEPROM((uint16_t)s);
        if(letter > 32){
        login += (char)letter; 
        }
        
      }
      // for(int f = i + 1 + 64; f < i + passlen + 64; f++){
      //   byte letter = readEEPROM((uint16_t)f);
      //   if(letter >= 32){
      //     password = password + (char)letter;
      //   }
      //   else{
      //     break;
      //   }
      // }
      

    }

    return login;
  }