#ifndef INDEXES_H
#define INDEXES_H

#include <stdint.h>
#include <stddef.h>

struct IndexResult {
    uint16_t* PassAddresses;
    uint16_t* LoginAddresses;
    uint16_t* IndexAddresses;
    uint8_t Logincount;
    uint8_t Passcount;
};
IndexResult GetIndexAddresses(const char* Name, int Pos,const char* Login, const char* Password);
// Number of addresses currently populated in the returned array
extern uint8_t AddressCount;

#endif
