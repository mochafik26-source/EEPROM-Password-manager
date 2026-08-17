#include "../include/Indexes.h"
#include <ostream>
#include <stdint.h>
#include <string.h>
#include <iostream>
// Static buffer returned to callers. This avoids returning pointers to
// stack-allocated arrays.
static uint16_t AddressesStatic[100];
static uint16_t LoginAddresses[100];
static uint16_t PassAddresses[100];
uint8_t AddressCount = 0;
uint8_t LoginCount = 0;
uint8_t PassCount = 0;

IndexResult GetIndexAddresses(const char* Name, int Pos,const char* Login, const char* Password)
{
    AddressCount = 0;
    LoginCount = 0;
    PassCount = 0;
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
        RecordPosition += 1;
        if (LoginCount >= (sizeof(LoginAddresses)/sizeof(LoginAddresses[0]))) break;
        LoginAddresses[LoginCount++] = (uint16_t)RecordPosition;
    }


    size_t Passlen = strlen(Password);
    for (size_t i = 0; i < Passlen; i++) {
        PassIndex += 1;
        if (PassCount >= (sizeof(AddressesStatic)/sizeof(AddressesStatic[0]))) break;
        PassAddresses[PassCount++] = (uint16_t)PassIndex;
    }

return {PassAddresses,LoginAddresses,AddressesStatic,LoginCount, PassCount};
}

int main(){
  auto Logins = GetIndexAddresses("Github", 0, "Mohamed", "1234d");
  std::cout << "Passwords";
  for (int i = 0; i < Logins.Passcount; i++) {
        std::cout << Logins.PassAddresses[i] << std::endl;
    }

  std::cout << "Logins";
  for (int i = 0; i < Logins.Logincount; i++) {
        std::cout << Logins.LoginAddresses[i] << std::endl;
    }

  return 0;
}
