#include <Arduino.h>
#include "../include/Indexes.h"
#include "../include/WriteIndex.h"
#include "../include/WriteRecords.h"
void setup() {
    Serial.begin(9600);
    auto addresses = GetIndexAddresses("github", "Mohamed", "Evo");
    Serial.println("got the addresses");
    WriteOnAddr(addresses.IndexAddresses, "github", addresses.Pos);
    delay(500);
    writeRecords(addresses.LoginAddresses, addresses.PassAddresses, "MohamedEvo", addresses.Logincount, addresses.Passcount);

    Serial.println("Data written to EEPROM successfully.");
    
}
void loop() {
}
