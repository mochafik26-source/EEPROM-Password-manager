#include "../include/Indexes.h"
#include <stdint.h>
#include <string.h>
#include <iostream>
// Static buffer returned to callers. This avoids returning pointers to
// stack-allocated arrays.
static uint16_t AddressesStatic[100];
static uint16_t LoginAddresses[100];
uint8_t AddressCount = 0;
uint8_t LoginCount = 0;
uint16_t* GetIndexAddresses(const char* Name, int Pos,const char* Login, const char* Password)
{
    AddressCount = 0;
    LoginCount = 0;
    // First address: marker/config location
    AddressesStatic[AddressCount++] = {};

    int IndexPosition = Pos * 24 + 64;
    int RecordPosition = Pos * 128 + 5040 + 64;
    int PassIndex = RecordPosition + 64;

    size_t len = strlen(Name);
    for (size_t i = 0; i < len; i++) {
        IndexPosition += 1;
        if (AddressCount >= (sizeof(AddressesStatic)/sizeof(AddressesStatic[0]))) break;
        AddressesStatic[AddressCount++] = (uint16_t)IndexPosition;
    }

    size_t Loginlen = strlen(Login);
    for (size_t i = 0; i < Loginlen; i++) {
        if (LoginCount >= (sizeof(AddressesStatic)/sizeof(AddressesStatic[0]))) break;
        LoginAddresses[LoginCount++] = (uint16_t)RecordPosition;
    }

return LoginAddresses;
}

int main(){
  auto Logins = GetIndexAddresses("Github", 0, "Mohamed", "1234d");

  for (int i = 0; i < AddressCount; i++) {
        std::cout << Logins[i] << std::endl;
    }
  return 0;
}
