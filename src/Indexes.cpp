#include <iostream>
#include <string>
#include <iomanip>
#include "../include/Indexes.h"
#include <cstdint>
#include <sstream>

uint16_t GetIndexAddresses(std::string Name, int NextPos)
{
    uint16_t Addresses[100];
    Addresses[0] = 0x0035;

    int Position = NextPos * 24 + 64;

    for (int i = 0; i < Name.length() + 2; i++) {
        Position += 1;
        Addresses[i + 1] = static_cast<uint16_t>(Position);
    }

    return Addresses;
}
