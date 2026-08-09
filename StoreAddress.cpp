#include "Indexes.h"
#include <string>
#include <vector>
#include <iostream>
void CreateIndex(int CurrentPos, std::string Website){
std::vector<std::string> Addresses = GetIndexAdresses(Website, CurrentPos);	
for (std::string Address : Addresses) {
    std::cout << Address << std::endl;
}
}

int main(){
	CreateIndex(1,"github");
}
