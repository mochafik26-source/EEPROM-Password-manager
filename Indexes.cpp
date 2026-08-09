#include <iostream>
#include <string>
#include <iomanip>
#include "Indexes.h"
#include <cstdint>
#include <vector>
#include <sstream>
std::vector<std::string> GetIndexAdresses(std::string Name, int NextPos)
{
    std::vector<std::string> Addresses;
    int Position = NextPos * 24 + 64;
    for(int i = 0; i < Name.length() + 2; i++){
        Position += 1;
        std::stringstream ss;
        ss << std::uppercase << std::hex 
        << std::setw(4) << std::setfill('0') << Position;
        std::string hexa = ss.str();
        Addresses.push_back(hexa);

    }
    
    return Addresses;
}

