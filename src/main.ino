#include <Arduino.h>
#include "../include/Indexes.h"
#include "../include/WriteIndex.h"
#include "../include/WriteRecords.h"
void setup() {
    Serial.begin(9600);
    auto addresses = GetIndexAddresses("Mohamed", "Mohamed", "Evo");
    for(int i = 0; i < addresses.Logincount; i++) {
        Serial.print("Login Address ");
        Serial.print(i);
        Serial.print(": ");
        Serial.println(addresses.IndexAddresses[i], HEX);
    }
    WriteOnAddr(addresses.IndexAddresses, "github", addresses.Pos);
    delay(500);
    writeRecords(addresses.LoginAddresses, addresses.PassAddresses, "MohamedEvo", addresses.Logincount, addresses.Passcount);

    Serial.println("Data written to EEPROM successfully.");
    
}
void loop() {
}
