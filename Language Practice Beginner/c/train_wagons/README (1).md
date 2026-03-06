# 🚂 Train Wagon Manager

A C program for managing a train's wagons and locomotives using a **singly linked list**, with file persistence support.

## About

This program simulates a train management system where you can add locomotives and wagons, search for a specific wagon, remove failed wagons, insert wagons at a specific position, and display the full train composition. The train state is loaded from and saved to a `.txt` file between sessions.

It was built as a hands-on exercise to practice the **singly linked list** data structure in C.

## Concept: Singly Linked List

A **singly linked list** is a linear data structure where each element (called a **node**) holds some data and a pointer to the next node in the sequence. The last node points to `NULL`, marking the end of the list.

```
[Locomotive] --> [Wagon 1] --> [Wagon 2] --> [Wagon 3] --> NULL
```

This project practices a range of core linked list operations:

| Operation | Pattern |
|-----------|---------|
| Add locomotive | **Head insertion** — O(1) |
| Add wagon | **Tail insertion** — traverse to last node, O(n) |
| Search | **Linear traversal** — O(n) |
| Delete failed wagons | **Node deletion with predecessor tracking** — O(n) |
| Insert after a node | **Mid-list insertion** — traverse to target, rewire pointers |
| Free list | **Full traversal with deallocation** |

## Features

| Option | Description |
|--------|-------------|
| 1. Add a locomotive | Inserts a locomotive at the **head** of the list; rejects duplicate numbers |
| 2. Add a wagon | Appends a wagon at the **tail** of the list; rejects duplicate numbers |
| 3. Search for a wagon | Traverses the list to find a wagon by its number |
| 4. Display the train | Prints all nodes in order from head to tail |
| 5. Delete failed wagons | Removes all wagons/locomotives with status `0` |
| 6. Insert wagon after a given number | Inserts a new wagon directly after a specified wagon |
| 7. Quit | Saves the current train to `train.txt`, frees memory, and exits |

## File Persistence

On **startup**, the train is automatically loaded from `train.txt`. On **exit**, the current state is saved back to `train.txt`. If the file does not exist, it is created automatically.

The file format is one wagon per line:
```
<number> <type> <status>
```
Example (`train.txt`):
```
11 wagon 0
8 wagon 1
5 locomotive 1
51 locomotive 0
3 wagon 1
```

## Project Structure

```
├── main.c      # Entry point, menu loop, and file load/save on start/exit
├── train.h     # Struct definitions and function declarations
├── train.c     # Linked list function implementations
└── train.txt   # Persistent train data (auto-created if missing)
```

### Key Data Structures (defined in `train.h`)

```c
typedef struct {
    int number, status;   // status: 0 = out of order, 1 = good working order
    char type[11];        // "locomotive" or "wagon"
} wagon;

typedef struct Node {
    wagon wag;
    struct Node *next;    // pointer to the next node
} Node;

typedef struct Node *List;
```

## How to Compile and Run

```bash
gcc main.c train.c -o train
./train
```

## Notes

- A wagon number must be **unique** — duplicates are rejected on insertion.
- Inserting a wagon after a node that is directly followed by a **locomotive** is not allowed, to preserve train structure integrity.
- Choosing **Quit** is required to properly save and free the train — closing the program abruptly will not save changes.
