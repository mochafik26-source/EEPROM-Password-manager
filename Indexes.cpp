#include <iostream>
#include <string>
#include <iomanip>
void makeIndex(int Status, std::string Name, int NextPos) {
    int Position = NextPos * 128 + 64;

    // std::string StartIndex = std::to_string(Position);
    //StartIndex.insert(0, 4 - StartIndex.length(), '0');
    // int Index = std::stoi(StartIndex);
    for(int i = 0; i < Name.length() + 2; i++){
        Position += 1;
        std::string StartIndex =  std::to_string(Position);
        StartIndex.insert(0,4 - StartIndex.length(), '0');
        std::cout << "0x" << StartIndex << std::endl;

    }
}

int main() {
    makeIndex(1, "Mohamed", 0);
}
