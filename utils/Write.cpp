#include <iostream>
#include <string>
#include <vector>
#include <Wire.h>

#define EEPROM_ADDRR 0x50

void WriteOnAddr(std::vector<std::string> Addresses, std::vector<std::int> Values){
	Wire.begin();
	writeEEPROM(EEPROM_ADDRR, Addresses[0], 1);
	for(int i = 0; i < Addresses.size(); i++){
		if(i < Value.size()){
		writeEEPROM(EEPROM_ADDRR, Addresses[i+1], Values[i]);
		}
		else{

		writeEEPROM(EEPROM_ADDRR, Addresses[i+1], 0);
		}
	}
}


void writeEEPROM(byte device, unsigned int address, byte data) {
  Wire.beginTransmission(device);

  Wire.write(address >> 8);
  Wire.write(address & 0xFF);

  Wire.write(data);

  Wire.endTransmission();
}
