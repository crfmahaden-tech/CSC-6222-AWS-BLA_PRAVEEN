# BLAST 01 — Intelligent Record-Search System Using a Binary Search Tree

## 1. Project Information

- **Assignment:** BLAST 01
- **Course:** Data Structures and Algorithms
- **Project Title:** Intelligent Record-Search System
- **Assigned Data Structure:** Binary Search Tree (BST)
- **Emerging Technology Area:** Artificial Intelligence (AI)
- **Programming Language:** C++17
- **Development Environment:** Ubuntu Linux
- **Compiler:** GNU C++ Compiler (g++)
- **Student:** Nagajayamadhup raveen Mahadeva

## 2. Project Overview

The Intelligent Record-Search System is a menu-based C++ application that demonstrates how a Binary Search Tree can organize, search, and manage records using unique integer IDs.

The application allows users to add records, search for records, delete records, display records in ascending order, find the minimum and maximum record IDs, and view the total number of records.

The main purpose of this project is to demonstrate the implementation and practical use of the assigned data structure in a realistic scenario. It is an educational prototype, not a complete commercial record-management or Artificial Intelligence system.

## 3. Problem Statement

Searching for a record in an unsorted collection may require checking records one by one. A Binary Search Tree organizes records according to their keys, allowing the search process to follow a path based on comparisons.

In this application, each record has a unique integer ID and a description. The record ID is used as the BST key.

The system demonstrates how a BST can support record retrieval and management while maintaining records in an ordered structure.

## 4. Objectives

- Understand the structure and operation of a Binary Search Tree.
- Implement a BST in C++ using nodes and pointers.
- Perform insertion, searching, and deletion operations.
- Display records in ascending order using in-order traversal.
- Find the minimum and maximum record IDs.
- Count the records stored in the tree.
- Validate user input and handle meaningful edge cases.
- Demonstrate a possible connection between data structures and AI-assisted applications.
- Document the application and its design professionally.

## 5. Data Structure Explanation: Binary Search Tree

A Binary Search Tree is a hierarchical, node-based data structure. Each node stores a key and references to its left and right child nodes.

The BST ordering property is:

- Values smaller than a node's key are placed in its left subtree.
- Values larger than a node's key are placed in its right subtree.
- Each record ID must be unique in this application.

### Example BST

Inserting record IDs in this order — 50, 30, 70, 20, 40, 60, 80 — produces the following tree:

```text
             50
           /    \
         30      70
        /  \    /  \
       20  40  60  80
```

An in-order traversal visits the left subtree, the current node, and then the right subtree. Therefore, the record IDs are displayed in ascending order:

```text
20, 30, 40, 50, 60, 70, 80
```

## 6. Application Features

The application provides the following menu options:

1. Add a record.
2. Search for a record by ID.
3. Delete a record by ID.
4. Display all records in ascending ID order.
5. Display the minimum and maximum record IDs.
6. Display the total number of records.
0. Exit the application.

### Input Validation

The application includes validation for:

- Invalid menu choices.
- Non-numeric input when an integer is required.
- Non-positive record IDs.
- Duplicate record IDs.
- Empty record descriptions.
- Searches for missing records.
- Attempts to delete records that do not exist.
- Operations on an empty tree.

The program displays readable messages to help users understand the results of each operation.

## 7. Time and Space Complexity

Let `n` represent the number of records and `h` represent the height of the BST.

| Operation | Average case for a reasonably balanced BST | Worst case |
|---|---|---|
| Search | O(log n) | O(n) |
| Insertion | O(log n) | O(n) |
| Deletion | O(log n) | O(n) |
| In-order traversal | O(n) | O(n) |
| Find minimum or maximum | O(log n) | O(n) |
| Storage for all nodes | O(n) | O(n) |

The implementation uses an ordinary BST rather than a self-balancing tree. Consequently, inserting records in an unfavorable order can produce a skewed tree and reduce performance.

The recursive traversal and update operations also use stack space proportional to the tree height.

## 8. Advantages and Limitations

### Advantages

- Maintains records in an ordered structure.
- Supports insertion, searching, and deletion.
- In-order traversal displays records in ascending order.
- Provides a clear demonstration of pointers, nodes, classes, and recursion.
- Can perform efficiently when the tree height is small.

### Limitations

- An ordinary BST can become skewed.
- Worst-case search, insertion, and deletion can take O(n) time.
- Records are stored in memory and are not preserved after the application exits.
- The application searches by record ID rather than understanding natural-language queries.
- The program does not implement a machine-learning model or AI inference.

## 9. Connection to Artificial Intelligence

The assigned emerging technology area for this project is Artificial Intelligence.

A BST can be used as a supporting data structure in a larger AI-assisted workflow. For example, a system could retrieve a record using its ID and then pass the retrieved information to a separate AI component for summarization, categorization, or other analysis.

Possible applications include:

- **AI-assisted support systems:** Retrieve a support ticket by ID before a separate AI component summarizes the ticket.
- **Intelligent information-management systems:** Retrieve a stored record before an AI component classifies or analyzes its contents.

These examples illustrate possible system designs. The current C++ application demonstrates key-based record retrieval only; it does not integrate an AI model.

## 10. Technologies Used

- C++17
- GNU C++ Compiler (g++)
- Ubuntu Linux
- Standard C++ Library
- Binary Search Tree data structure
- GitHub for source-code hosting and project documentation

## 11. Project File Structure

```text
BLAST-01-BST-Intelligent-Record-Search/
├── main.cpp
├── bst.h
├── bst.cpp
├── README.md
├── docs/
│   └── BST_Part3_UML_Design.pptx
└── screenshots/
    └── [actual execution screenshots]
```

### File Descriptions

- `main.cpp`: Contains the application menu, input validation, and user interaction.
- `bst.h`: Declares the `Record` structure, `Node` structure, and `BinarySearchTree` class.
- `bst.cpp`: Implements BST insertion, searching, deletion, traversal, minimum/maximum lookup, record counting, and memory cleanup.
- `README.md`: Describes the project, data structure, features, build instructions, and testing.
- `docs/`: Contains UML and design documentation.
- `screenshots/`: Contains genuine screenshots captured during program execution.

## 12. Installation, Compilation, and Execution

### Step 1: Install the compiler

On Ubuntu, install the build tools if they are not already available:

```bash
sudo apt update
sudo apt install build-essential
```

Verify the compiler:

```bash
g++ --version
```

### Step 2: Open the project directory

Navigate to the directory containing the C++ source files:

```bash
cd ~/BST_Intelligent_Record_Search
```

### Step 3: Compile the program

Compile the source files together:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp bst.cpp -o bst_app
```

If compilation succeeds, the compiler generates the `bst_app` executable.

### Step 4: Run the application

```bash
./bst_app
```

The menu will appear in the terminal, allowing the user to perform the available operations.

## 13. Sample Execution

The following is an illustrative example of the expected interaction. Actual output should be verified against the compiled program.

### Adding a Record

```text
Enter your choice: 1
Enter record ID: 50
Enter record description: Network support ticket
Record added successfully.
```

### Searching for an Existing Record

```text
Enter your choice: 2
Enter ID to search: 50

Record found!
ID: 50
Description: Network support ticket
```

### Displaying Records in Sorted Order

After adding records with IDs 50, 30, and 70:

```text
Enter your choice: 4

--- Records in Ascending ID Order ---
ID: 30 | Description: Server connection issue
ID: 50 | Description: Network support ticket
ID: 70 | Description: System access request
```

### Handling a Missing Record

```text
Enter your choice: 2
Enter ID to search: 999
Record not found.
```

## 14. Testing and Edge Cases

The application should be tested using normal operations and meaningful edge cases.

- [ ] Compile the application successfully.
- [ ] Add multiple records.
- [ ] Search for an existing record.
- [ ] Search for a missing record.
- [ ] Display records in ascending order.
- [ ] Delete an existing record.
- [ ] Attempt to delete a missing record.
- [ ] Attempt to insert a duplicate ID.
- [ ] Enter invalid menu input.
- [ ] Enter non-numeric ID input.
- [ ] Attempt to use a non-positive ID.
- [ ] Display an empty tree.
- [ ] Verify the minimum and maximum IDs.
- [ ] Verify the record count after insertion and deletion.
- [ ] Test deletion of a node with no children, one child, and two children.

Only mark a test as completed after observing the actual result in Ubuntu.

## 15. UML and Design Documentation

The UML/design documentation describes the program's structure and behavior.

The class diagram covers:

- `Record`: stores the record ID and description.
- `Node`: stores a record and links to the left and right children.
- `BinarySearchTree`: manages the root node and implements the BST operations.

The activity diagrams illustrate the menu workflow and the BST search process.

The diagrams should match the final C++ implementation.

## 16. Execution Evidence

Add genuine screenshots of the application running in Ubuntu.

Recommended screenshots:

1. Successful compilation.
2. Application menu.
3. Successful record insertion.
4. Successful search.
5. Sorted record display.
6. Invalid input or duplicate-ID handling.
7. Missing-record handling.
8. Successful deletion and updated tree contents.

Screenshots should show the actual program output, not recreated or simulated results.

## 17. YouTube Presentation and LinkedIn Post

**YouTube presentation:** Add the published presentation URL here.

**LinkedIn post:** Add the published LinkedIn post URL here.

Replace these placeholders with the actual public links before submitting the repository.

## 18. References

1. cppreference.com — C++ language and standard library reference: https://en.cppreference.com/
2. Open Data Structures — Data structures and Binary Search Trees: https://opendatastructures.org/
3. GNU Compiler Collection — GCC documentation: https://gcc.gnu.org/onlinedocs/

## 19. Conclusion

This project demonstrates how a Binary Search Tree can be implemented in C++ to manage and retrieve records using unique integer IDs.

The application combines data-structure implementation, object-oriented programming, input validation, record management, and testing. It also explains how key-based retrieval could support a larger AI-assisted system while keeping the scope focused on the assigned data structure.

The project provides a practical demonstration of the Binary Search Tree and its relevance to data organization and emerging technology applications.

