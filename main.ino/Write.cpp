#include <Wire.h>
#include <vector>
#include <cstdint>
#include "./Indexes.cpp"
#define EEPROM_ADDRR 0x50

void writeEEPROM(byte device, unsigned int address, byte data) {
    Wire.beginTransmission(device);

    Wire.write(address >> 8);
    Wire.write(address & 0xFF);
    Wire.write(data);

    Wire.endTransmission();

    delay(5);  // EEPROM write cycle
}

void WriteOnAddr(
    const std::vector<unsigned int>& Addresses,
    const std::vector<uint8_t>& Values
) {
    // Make sure there is at least the configuration address
    if (Addresses.empty()) {
        return;
    }

    // Mark EEPROM as configured
    writeEEPROM(EEPROM_ADDRR, Addresses[0], 1);

    // Write values starting at Addresses[1]
    for (size_t i = 0; i < Values.size(); i++) {
        if (i + 1 >= Addresses.size()) {
            break;
        }

        writeEEPROM(
            EEPROM_ADDRR,
            Addresses[i + 1],
            Values[i]
        );
    }
}
void setup() {
    Wire.begin();

    GetIndexAddresses("Github", 0);

    WriteOnAddr(Addresses, 'Github');
}
