#include <Arduino.h>
#include "../include/Indexes.h"
#include "../include/WriteIndex.h"
#include "../include/WriteRecords.h"
void setup() {
    Serial.begin(9600);
    auto addresses = GetIndexAddresses("youtube", 0, "Mohamed", "Evo");

    WriteOnAddr(addresses.IndexAddresses, "youtube");
    delay(500);
    writeRecords(addresses.LoginAddresses, addresses.PassAddresses, "MohamedEvo", addresses.Logincount, addresses.Passcount);

    delay(1000);
    Serial.println("Data written to EEPROM successfully.");
    
}
void loop() {
}
