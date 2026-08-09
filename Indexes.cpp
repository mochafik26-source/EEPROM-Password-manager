#include <iostream>
#include <string>
#include <iomanip>
#include "Indexes.h"
#include <cstdint>
#include <vector>
std::vector<uint16_t> GetIndexAdresses(std::string Name, int NextPos) {
    int Position = NextPos * 24 + 64;
    std::vector<uint16_t> Addresses;
    // std::string StartIndex = std::to_string(Position);
    //StartIndex.insert(0, 4 - StartIndex.length(), '0');
    // int Index = std::stoi(StartIndex);
    for(int i = 0; i < Name.length() + 2; i++){
        Position += 1;
        std::string StartIndex =  std::to_string(Position);
        StartIndex.insert(0,4 - StartIndex.length(), '0');
    	Addresses.push_back(std::stoul(StartIndex, nullptr, 16));
	std::cout << StartIndex;
    }
    return Addresses;
}
int main(){
	GetIndexAdresses("git", 0);
}
