#include <Arduino.h>
#include "../include/Indexes.h"
#include "../include/WriteIndex.h"
#include "../include/WriteRecords.h"
#include "../include/Searching.h"
#include "../include/ReadingRecord.h"
void setup() {
    Serial.begin(9600);
     //auto addresses = GetIndexAddresses("Mohamed", "Mohamed", "Evo");
     // WriteOnAddr(addresses.IndexAddresses, "chatgpt", addresses.Pos);
    //delay(500);
   // writeRecords(addresses.LoginAddresses, addresses.PassAddresses, "MohamedEvo", addresses.Logincount, addresses.Passcount);

    //Serial.println("Data written to EEPROM successfully.");
   //String RecordsPos = Searching("chatgpt");
   //Serial.println("Record Position: " + RecordsPos);
    auto results = ReadingRecord(0);
    Serial.println(results);
}
void loop() {
}
