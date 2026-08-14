#include "../include/Indexes.h"
#include <stdint.h>
#include <string.h>

// Static buffer returned to callers. This avoids returning pointers to
// stack-allocated arrays.
static uint16_t AddressesStatic[100];
uint8_t AddressCount = 0;

uint16_t* GetIndexAddresses(const char* Name, int NextPos)
{
    AddressCount = 0;
    // First address: marker/config location
    AddressesStatic[AddressCount++] = {};

    int Position = NextPos * 24 + 64;

    size_t len = strlen(Name);
    for (size_t i = 0; i < len; i++) {
        Position += 1;
        if (AddressCount >= (sizeof(AddressesStatic)/sizeof(AddressesStatic[0]))) break;
        AddressesStatic[AddressCount++] = (uint16_t)Position;
    }

    return AddressesStatic;
}
