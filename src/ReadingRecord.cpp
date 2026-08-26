#include <Arduino.h>
#include <Wire.h>
#include "../include/ReadAddress.h"
#include "../include/ReadingRecord.h"
std::list<Record> ReadingRecord(int startAddress) {
    std::list<Record> records;
    const int Recordsize = 128;
    const int starting = 6104;

    for(int i = starting; i < 32000; i+= Recordsize){
      records.clear();
      String login = "";
      String pass = "";
      byte loginlen = readEEPROM(i);
      byte passlen = readEEPROM(i +64);
      for(int s = i + 1; s < i + loginlen; s++){
        byte letter = readEEPROM((uint16_t)s);
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
      records.push_back(login.c_str());
      records.push_back(pass.c_str());

    }

    return records;
}
