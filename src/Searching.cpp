#include <Wire.h>
#include "../include/ReadAddress.h"
#include "../include/Searching.h"
#include <Arduino.h>

String Searching(const char* Name){
  Wire.begin();
  const int max = 5040;
  const int min = 64;
  String word = "";
  for(int i = min; i < max; i++){
  byte letter = readEEPROM((uint16_t)i);
  word = word + letter;
  }
return word;
}
