
# Intelligent Record-Search System Using a Binary Search Tree

## Project Overview

This project implements a menu-based C++ application using a
Binary Search Tree (BST). It demonstrates how records can be
organized and retrieved by unique record IDs.

## Data Structure

Each BST node stores a record ID, a description, and pointers
to its left and right children.

- Smaller IDs are stored in the left subtree.
- Larger IDs are stored in the right subtree.
- In-order traversal displays records in ascending ID order.

## Features

1. Add a record
2. Search by record ID
3. Delete a record
4. Display records in sorted order
5. Display minimum and maximum IDs
6. Display total record count
7. Validate input and reject duplicate IDs

## Technologies

- C++
- C++17
- Ubuntu Linux
- GNU g++ compiler

## Project Files

- `main.cpp`: Menu and user interaction
- `bst.h`: Record, node, and BST declarations
- `bst.cpp`: BST implementation
- `README.md`: Project documentation

## Compilation

```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp bst.cpp -o bst_app
```

## Run

```bash
./bst_app
```

## Testing

Test the program with:
- Valid record insertion and search
- Displaying records in ascending order
- Deleting an existing record
- Searching for a missing record
- Rejecting duplicate IDs
- Handling an empty tree
- Invalid menu and ID input

Record actual results after executing each test.

## Artificial Intelligence Connection

The BST demonstrates key-based record retrieval that could
support an AI-assisted workflow. The BST itself does not
perform machine learning or semantic understanding.
