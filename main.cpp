#include <Wire.h>

#define EEPROM_ADDR 0x50
int memory;
void setup() {
  Serial.begin(9600);
  Wire.begin();



}




void loop() {
  Serial.println("Task");
  while (Serial.available() == 0) {}

  String line = Serial.readStringUntil('\n');
  int task = line.toInt();

  // Clear leftover characters
  while (Serial.available()) {
    Serial.read();
  }

  if (task == 1) {
    Serial.println("Address:");

    while (Serial.available() == 0) {}
    String add = Serial.readStringUntil('\n');
    int address = add.toInt();

    while (Serial.available()) {
      Serial.read();
    }

    Serial.println("Value:");

    while (Serial.available() == 0) {}
    String val = Serial.readStringUntil('\n');
    int value = val.toInt();
    while (Serial.available()) {
      Serial.read();
    }

    writeEEPROM(EEPROM_ADDR, address, value);

    Serial.println("Done writing!");
  }

  else if(task == 2){
      Serial.println("address");
      while(Serial.available() == 0){}
      String addr = Serial.readStringUntil('\n');
      int addres = addr.toInt();
      while (Serial.available()) {
      Serial.read();
    }
    int readval = readEEPROM(EEPROM_ADDR, addres);
    Serial.println(readval);

  }
}

void writeEEPROM(byte device, unsigned int address, byte data) {
  Wire.beginTransmission(device);

  Wire.write(address >> 8);
  Wire.write(address & 0xFF);

  Wire.write(data);

  Wire.endTransmission();
}

byte readEEPROM(byte device, unsigned int address) {

  Wire.beginTransmission(device);

  Wire.write(address >> 8);
  Wire.write(address & 0xFF);

  Wire.endTransmission();

  Wire.requestFrom(device, 1);

  if (Wire.available()) {
    return Wire.read();
  }

  return 0;
}
