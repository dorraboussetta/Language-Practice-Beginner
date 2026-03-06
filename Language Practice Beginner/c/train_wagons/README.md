# 🚂 Train Wagon Manager

A C program for managing a train's wagons and locomotives using a **singly linked list** and text files management.

## About

This program simulates a train management system where you can add locomotives and wagons, search for a specific wagon, remove failed wagons, insert wagons at a specific position, and display the full train composition. The train state is loaded from and saved to a `.txt` file between sessions.

## Purpose
Practicing the **singly linked list** data structure in C.

## Exercise Structure

```
├── main.c      # Entry point, menu loop, and file load/save on start/exit
├── train.h     # Struct definitions and function declarations
├── train.c     # Linked list function implementations
└── train.txt   # Persistent train data (auto-created if missing)
```

## How to Compile and Run

```bash
gcc main.c train.c -o train
./train
```

## Notes
- On **startup**, the train is automatically loaded from `train.txt`. On **exit**, the current state is saved back to `train.txt`. If the file does not exist, it is created automatically.
- A wagon number must be **unique** — duplicates are rejected on insertion.
- Inserting a wagon after a node that is directly followed by a **locomotive** is not allowed, to preserve train structure integrity.
- Choosing **Quit** is required to properly save and free the train — closing the program abruptly will not save changes.
