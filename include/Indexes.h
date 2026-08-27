#ifndef INDEXES_H
#define INDEXES_H

#include <stdint.h>
#include <stddef.h>
#include "../include/ReadAddress.h"
struct IndexResult {
    uint16_t* PassAddresses;
    uint16_t* LoginAddresses;
    uint16_t* IndexAddresses;
    uint8_t Logincount;
    uint8_t Passcount;

    uint8_t Pos;
};
IndexResult GetIndexAddresses(const char* Name,const char* Login, const char* Password);
// Number of addresses currently populated in the returned array
extern uint8_t AddressCount;

#endif
