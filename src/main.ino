#include <Arduino.h>
#include "../include/Indexes.h"
#include "../include/WriteIndex.h"
#include "../include/WriteRecords.h"
#include "../include/Searching.h"
#include "../include/ReadingRecord.h"

void setup() {
    String  Name = "";
    String  Login = "";
    String  Password = "";
    Serial.begin(9600);
     //auto addresses = GetIndexAddresses("reddit", "Evolution", "Evo");
     //WriteOnAddr(addresses.IndexAddresses, "reddit", addresses.Pos);
    //delay(500);
   //writeRecords(addresses.LoginAddresses, addresses.PassAddresses, "EvolutionEvo", addresses.Logincount, addresses.Passcount);

    //Serial.println("Data written to EEPROM successfully.");
   //String RecordsPos = Searching("reddit");
   //Serial.println("Record Position: " + RecordsPos);
    auto results = ReadingRecord(2);
    Serial.println(results);
}
void loop() {
    if (Serial.available() > 0) {
        String data = Serial.readStringUntil('\n');
        data.trim();

        
    }
}
