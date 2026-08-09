#include "Indexes.h"
#include <string>
#include <vector>
int Current = 0;
void CreateIndex(int CurrentPos, std::string Website){
std::vector<uint16_t> Addresses = GetIndexAdresses(Website, CurrentPos);	
for (uint16_t Address : Addresses) {
    std::cout << Address;
}
}

int main(){
	CreateIndex(1,"github");
}
