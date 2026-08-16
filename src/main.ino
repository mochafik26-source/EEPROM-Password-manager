#include <Arduino.h>
#include "../include/Indexes.h"
#include "../include/WriteIndex.h"

void setup() {
    Serial.begin(9600);
    auto addresses = GetIndexAddresses("youtube", 0);

    WriteOnAddr(addresses, "youtube");
    delay(1000);
    Serial.println("Data written to EEPROM successfully.");
    
}
void loop() {
}