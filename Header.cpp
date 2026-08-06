

#define EEPROM_ADDR 0x50


void Initializing(){
    // Initializing byte if = 1 so its initialized.
    writeEEPROM(EEPROM_ADDR, 0x0000, 0);
    // the version
    writeEEPROM(EEPROM_ADDR, 0x0001, 1);
    // records count
    writeEEPROM(EEPROM_ADDR, 0x0002, 0);
    // record size
    writeEEPROM(EEPROM_ADDR, 0x0003, 128);
    // index size
    writeEEPROM(EEPROM_ADDR, 0x0004, 0);


}
