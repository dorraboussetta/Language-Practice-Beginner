# Student Binary File Management Program

## Overview

This C program manages student records using a **binary file**.  
Each student has:

- An ID (integer)
- A name (string)
- A specialty (string)
- An average grade (float)

The program allows the user to:

- Enter and store student records in a binary file
- Search for a student by ID
- Add a student only if the ID does not already exist
- Display students with an average ≥ 10, sorted in ascending order
- Modify the specialty of a specific student

All records are stored in a binary file.

---

## Concepts Practiced

This program is designed to practice:

- Binary file handling in C (`fopen` with `"rb"` and `"ab"`)
- Reading and writing structures using `fread` and `fwrite`
- Preventing duplicate records using search before insertion
- Updating records stored in files 

The program reinforces understanding of how structured data is stored and managed in binary files using dynamic and structured file operations in C.
