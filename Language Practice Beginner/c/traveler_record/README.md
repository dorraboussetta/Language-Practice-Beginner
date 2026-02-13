# Traveler Management Program (Binary File + Dynamic Memory)

## Overview

This C program manages traveler records using a **binary file** and **dynamic memory allocation**.

Each traveler is defined by:

- `id` (string)
- `name` (string)
- `address` (string)
- `number of trips` (integer)

When the program starts, it loads all existing travelers from `Traveler.bin` into a dynamically allocated array.  
All operations (add, search, delete, display) are performed in memory.  
Before exiting, the updated data is saved back into the binary file.

---

## Concepts Practiced

This program is designed to practice:

- Binary file handling in C (`fopen`, `fread`, `fwrite`)
- Dynamic memory allocation (`malloc`, `realloc`, `free`)
- Loading structured data from a file into memory
- Saving structured data back to a file
- Searching within an array of structures
- Adding elements dynamically to an array
- Deleting elements from a dynamically allocated array
- Preventing duplicate records (ID-based search before insertion)
---

