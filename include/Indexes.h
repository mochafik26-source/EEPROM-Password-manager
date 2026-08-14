#ifndef INDEXES_H
#define INDEXES_H

#include <stdint.h>
#include <stddef.h>

// Returns a pointer to an internal static array of addresses.
// The number of valid entries is available in `AddressCount`.
uint16_t* GetIndexAddresses(const char* Name, int NextPos);

// Number of addresses currently populated in the returned array
extern uint8_t AddressCount;

#endif
