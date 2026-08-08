# ESP32 EEPROM Password Manager

A password manager project built around an **ESP32** and an external **I²C EEPROM**.

The ESP32 handles communication and control, while the EEPROM is used for persistent storage.

## Hardware

* ESP32
* AT24C256 / 24LC512 I²C EEPROM
* I²C communication

EEPROM I²C address:

```text
0x50
```

## EEPROM Data Structure

The EEPROM is being organized into a custom data structure.

The first byte is used to determine whether the device has already been configured.

```text
EEPROM
│
├── Byte 0
│   └── Configuration status
│
├── Header
│
├── Index
│
└── Records
```

### Configuration Byte

The first byte of the EEPROM indicates whether the device has been configured.

```text
0 = Not configured
1 = Configured
```

For example:

```text
EEPROM[0] = 0
```

means the device has not been configured yet.

```text
EEPROM[0] = 1
```

means the device has already been configured.

This allows the ESP32 to check the device state when it starts.

Conceptually:

```cpp
uint8_t configured = readEEPROM(0);

if (configured == 0) {
    // Device is not configured
}

if (configured == 1) {
    // Device is configured
}
```

## Header

After the configuration byte, the EEPROM contains the database header.

The current header structure is:

```cpp
struct Header {
    char magic[4];      // "PASS"
    uint8_t version;    // Database version
};
```

The header is used to identify the database and its format version.

Example:

```text
PASS
01
```

The first byte of the EEPROM remains separate from this structure because it is specifically used for the device configuration state.

## Index

The EEPROM will contain an index for locating stored records.

The index is based on the name of the service or website.

Example:

```text
GitHub
Google
Discord
```

The index allows the ESP32 to determine where a corresponding record is located in EEPROM.

The exact index entry structure is still being developed.

## Records

Records will be stored after the index.

The record structure is still being developed, so the final fields and sizes are not fixed yet.

The password field is currently **not part of the implemented structure**.

## Memory Layout

The current concept is:

```text
Address
   │
   ▼
┌─────────────────────────┐
│ 0                       │
│ Configuration Byte      │
│ 0 = not configured     │
│ 1 = configured         │
├─────────────────────────┤
│ Header                  │
│                         │
│ Magic: "PASS"           │
│ Version                 │
├─────────────────────────┤
│ Index                   │
│                         │
│ Website/service names   │
│ Record locations        │
├─────────────────────────┤
│ Records                 │
│                         │
│ Stored data             │
└─────────────────────────┘
```

## Current Development

The project is currently focused on building the EEPROM storage system.

Current work includes:

* ESP32 ↔ EEPROM communication
* Reading EEPROM
* Writing EEPROM
* EEPROM memory addressing
* Configuration status byte
* Database header
* Index design
* Record storage design

The data structures are still being developed, so the final EEPROM layout may change.

## Technologies

* ESP32
* C++
* Arduino
* I²C
* AT24C256 / 24LC512 EEPROM
