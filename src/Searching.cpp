#include <Wire.h>
#include "../include/ReadAddress.h"
#include "../include/Searching.h"
#include <Arduino.h>
String Searching(const String Name){
  Wire.begin();
  const int max = 5040;
  const int min = 64;
  const int recordSize = 24;
  String word = "";
  for (int i = min; i < max; i += recordSize) {

        word = "";

        for (int s = i + 1; s < i + recordSize; s++) {

            byte letter = readEEPROM((uint16_t)s);

            if (letter == 0 && !(letter > 32)) {
                continue;
            }
            if(isAlpha((char)letter)){
            word += (char)letter;
            }
        }
        return word;

        
    }

    return "not found";
}