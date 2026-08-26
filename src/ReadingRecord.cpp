#include <iostream>
#include <list>
#include <Arduino.h>
#include <Wire.h>
#include "../include/ReadAddress.h"
#include "../include/ReadingRecords.h"
std::list<std::string> ReadingRecord(int startAddress) {
    std::list<std::string> records;
    const int Recordsize = 128;
    const int starting = 6104;

    for(int i = starting; i < 32000; i+= Recordsize){
      records.clear();
      String login = "";
      String pass = "";
      byte loginlen = readEEPROM(i);
      byte passlen = readEEPROM(i +64);
      for(int s = i + 1; s < i + loginlen; s++){
        byte letter = readEEPROM((uin16_t)s);
        if(letter >= 32){
        login = login + (char)letter;  
        }
        else{
          break;
        }
      }
      for(int f = i + 1 + 64; f < i + passlen + 64; f++){
        byte letter = readEEPROM((uint16_t)f);
        if(letter >= 32){
          pass = pass + (char)letter;
        }
        else{
          break;
        }
      }
      records[0] = login;
      records[1] = pass;

    }

    return records;
}
