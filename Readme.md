# Arduino EEPROM Password Manager

A password manager project built around an **Arduino** and an external **I²C EEPROM**.

The Arduino handles communication with the EEPROM and manages the stored data. During development, the Arduino is controlled through the **Arduino Serial Monitor**.

A separate **Go CLI application built with Cobra** is also being developed to provide a command-line interface for communicating with the Arduino.
<img width="813" height="429" alt="image" src="https://github.com/user-attachments/assets/29b175ed-2160-4061-9c3f-3ed3b3762917" />


## Architecture

```text
┌──────────────────────────┐
│     Arduino Serial       │
│        Monitor           │
└────────────┬─────────────┘
             │
          Serial
             │
             ▼
      ┌─────────────┐
      │   Arduino   │
      └──────┬──────┘
             │
            I²C
             │
             ▼
┌─────────────────────────┐
│   AT24C256 / 24LC512    │
│         EEPROM          │
└─────────────────────────┘
```

The planned Go CLI follows the same communication concept:

```text
┌──────────────────────────┐
│      Go + Cobra CLI      │
└────────────┬─────────────┘
             │
          Serial
             │
             ▼
      ┌─────────────┐
      │   Arduino   │
      └──────┬──────┘
             │
            I²C
             │
             ▼
          EEPROM
```

## Hardware

* Arduino
* AT24C256 / 24LC512 I²C EEPROM
* I²C connection
* USB connection for Serial communication

EEPROM I²C address:

```text
0x50
```

## Communication

The current development and testing interface is the **Arduino Serial Monitor**.

The computer sends commands to the Arduino through Serial. The Arduino processes the commands and performs the required EEPROM operations.

```text
Serial Monitor
      │
      │ Serial
      ▼
   Arduino
      │
      │ I²C
      ▼
   EEPROM
```

The Go Cobra CLI is being developed as a separate interface that will communicate with the Arduino through Serial.

## EEPROM Data Structure

The EEPROM uses a custom storage structure:

```text
EEPROM
│
├── Configuration Byte
├── Header
├── Index
└── Records
```

The layout is designed to allow the Arduino to identify the database, locate records, and store data persistently.

## Configuration Byte

The first byte of the EEPROM is used to determine whether the device has been configured.

```text
0 = Not configured
1 = Configured
```

For example:

```text
EEPROM[0] = 0
```

means the device has not been configured.

```text
EEPROM[0] = 1
```

means the device has been configured.

The Arduino checks this byte when starting or initializing the database.

Example:

```cpp
uint8_t configured = readEEPROM(0);

if (configured == 0) {
    // Device is not configured
}

if (configured == 1) {
    // Device is configured
}
```

The configuration byte is separate from the database header.

## Header

The header is stored after the configuration byte.

The current header structure is:

```cpp
struct Header {
    char magic[4];      // "PASS"
    uint8_t version;    // Database version
};
```

Example:

```text
PASS
01
```

The `magic` field identifies the EEPROM data as belonging to this password manager.

The `version` field identifies the database format version.

This allows the storage format to be changed in the future while keeping track of which format is currently stored.

## Index

An index is used to locate stored records.

The index is based on the service or website name.

Example:

```text
GitHub
Google
Discord
```

Conceptually, an index entry contains information such as:

```text
┌─────────────────────┐
│ Service name        │
│ Record address      │
└─────────────────────┘
```

The Arduino can use the index to find the location of a corresponding record in EEPROM.

The exact index structure is still being developed.

## Records

Records contain the data associated with a stored service.

The final record structure is still under development, so the fields and sizes are not yet fixed.

The password field is **not currently part of the finalized structure**.

The record format will be finalized as the storage system develops.

## Memory Layout

The current concept is:

```text
Address
   │
   ▼
┌─────────────────────────┐
│ 0                       │
│ Configuration Byte      │
│                         │
│ 0 = Not configured      │
│ 1 = Configured          │
├─────────────────────────┤
│ Header                  │
│                         │
│ Magic: "PASS"           │
│ Version                 │
├─────────────────────────┤
│ Index                   │
│                         │
│ Service names           │
│ Record locations        │
├─────────────────────────┤
│ Records                 │
│                         │
│ Stored data             │
└─────────────────────────┘
```

The EEPROM layout is still under development and may change as the project evolves.

## Go Cobra CLI

A separate command-line application is being developed in **Go** using **Cobra**.

The purpose of the CLI is to provide a more convenient interface for controlling the Arduino without relying on the Arduino Serial Monitor.

Conceptually:

```text
Go CLI
  │
  │ Serial
  ▼
Arduino
  │
  │ I²C
  ▼
EEPROM
```

Planned commands include operations such as:

```bash
password-manager add <service> <login> <password>
password-manager read <service>
password-manager delete <service>
```

The command set and communication protocol are still under development.

## Current Development

The project is currently focused on building the EEPROM storage system.

Current work includes:

* Arduino ↔ EEPROM communication
* Serial communication with the Arduino
* EEPROM reading
* EEPROM writing
* EEPROM memory addressing
* Configuration status byte
* Database header
* Database versioning
* Index design
* Record storage design
* Serial command handling
* Go Cobra CLI

## Technologies

### Hardware

* Arduino
* AT24C256 / 24LC512 EEPROM

### Embedded

* C++
* I²C
* Serial communication

### CLI

* Go
* Cobra
* Serial communication

## Project Status

**Status: In development**

The current focus is designing and implementing a reliable EEPROM storage system and testing it through the Arduino Serial Monitor.

The Go + Cobra CLI is being developed as a dedicated interface for controlling the Arduino.

The EEPROM layout, index structure, record format, and communication protocol are still being developed and may change.
