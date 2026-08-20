#include <Arduino.h>
#include "../include/Indexes.h"
#include "../include/WriteIndex.h"
#include "../include/WriteRecords.h"
#include "../include/Searching.h"
void setup() {
    Serial.begin(9600);
    //auto addresses = GetIndexAddresses("Mohamed", "Mohamed", "Evo");
  // WriteOnAddr(addresses.IndexAddresses, "github", addresses.Pos);
    ///delay(500);
   // writeRecords(addresses.LoginAddresses, addresses.PassAddresses, "MohamedEvo", addresses.Logincount, addresses.Passcount);

    //Serial.println("Data written to EEPROM successfully.");
   Serial.println(Searching("git"));
}
void loop() {
}
