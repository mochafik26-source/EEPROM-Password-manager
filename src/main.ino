#include <Arduino.h>
#include "../include/Indexes.h"
#include "../include/WriteIndex.h"
#include "../include/WriteRecords.h"
#include "../include/Searching.h"
#include "../include/ReadingRecord.h"
#include "../include/Delete.h"
#include "../include/Reset.h"
void setup() {

    Serial.begin(9600);
}
void loop() {
    if (Serial.available() > 0) {
    String data = Serial.readStringUntil('\n');
    data.trim();
    String commands[4];
    Serial.println(data);
    String command = "";
    int f = 0;
    for(int i = 0; i < data.length(); i++){
      if(data[i] == '|'){
        commands[f] = command;
        command = "";
        f++;
      }
      else{
        command = command + data[i];
      }
    }
        if(commands[0] == "add"){
          auto addresses = GetIndexAddresses(commands[1].c_str(), commands[2].c_str(), commands[3].c_str());
          WriteOnAddr(addresses.IndexAddresses, commands[1].c_str(), addresses.Pos);
          delay(500);
          String namepass = commands[2] + commands[3];
          writeRecords(addresses.LoginAddresses, addresses.PassAddresses,namepass.c_str() , addresses.Logincount, addresses.Passcount);

          Serial.println("Data written to EEPROM successfully.");
          Serial.println("done");

          
        }
        else if(commands[0] == "read"){
            int RecordsPos = Searching(commands[1]);
            if (RecordsPos == -1) {
                Serial.println("Record not found");
                Serial.println("done");

            } else {
                auto results = ReadingRecord(RecordsPos);
                Serial.println(results);
                Serial.println("done");
            }
            
        }
        else if(commands[0] == "delete"){
          int RecordsPos = Searching(commands[1]);
          Deleting(RecordsPos);
          Serial.println("deleted");
          Serial.println("done");
          }
          else if(commands[0] == "reset"){
            Reset();
            Serial.println("EEPROM reset successfully.");
            Serial.println("done");
          
          }

        
}
}
