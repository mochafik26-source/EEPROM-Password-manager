#include "../include/Indexes.h"
#include <stdint.h>
#include <string.h>
#include "../include/ReadAddress.h"
#include "../include/Write.h"
// Static buffer returned to callers. This avoids returning pointers to
// stack-allocated arrays.
static uint16_t AddressesStatic[100];
static uint16_t LoginAddresses[100];
static uint16_t PassAddresses[100];
uint8_t AddressCount = 0;
uint8_t LoginCount = 0;
uint8_t PassCount = 0;
uint8_t Pos = 0;
IndexResult GetIndexAddresses(const char* Name,const char* Login, const char* Password)
{
    Wire.begin();
    writeEEPROM(0x50, 0x0001, 0); // Initialize position if not already set
    Pos = readEEPROM(0x0001);

    AddressCount = 0;
    LoginCount = 0;
    PassCount = 0;
    // First address: marker/config location

    int IndexPosition = Pos * 24 + 64;
    int RecordPosition = Pos * 128 + 5040 + 64;
    int PassIndex = RecordPosition + 64;

    size_t len = strlen(Name);
    for (size_t i = 0; i < len+1; i++) {
        IndexPosition += 1;
        if (AddressCount >= (sizeof(AddressesStatic)/sizeof(AddressesStatic[0]))) break;
        AddressesStatic[AddressCount++] = (uint16_t)IndexPosition;
    }

    size_t Loginlen = strlen(Login);
    for (size_t i = 0; i < Loginlen + 1; i++) {
        RecordPosition += 1;
        if (LoginCount >= (sizeof(LoginAddresses)/sizeof(LoginAddresses[0]))) break;
        LoginAddresses[LoginCount++] = (uint16_t)RecordPosition;
    }


    size_t Passlen = strlen(Password);
    for (size_t i = 0; i < Passlen + 1; i++) {
        PassIndex += 1;
        if (PassCount >= (sizeof(AddressesStatic)/sizeof(AddressesStatic[0]))) break;
        PassAddresses[PassCount++] = (uint16_t)PassIndex;
    }
    writeEEPROM(0x50, 0x0001, Pos + 1); // Increment position for next write
    return {PassAddresses,LoginAddresses,AddressesStatic,LoginCount, PassCount, Pos};
}


