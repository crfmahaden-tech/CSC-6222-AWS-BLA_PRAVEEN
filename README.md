# Data Structures and Algorithms – Stack, Queue, and Binary Search Tree

## Student Information

**Name:** NagaJayaMadhuPraveen  
**Course:** Data Structures and Algorithms  
**Assignment Title:** Stack, Queue, and Binary Search Tree Implementation  
**University:** Concordia University Chicago  
**Programming Language:** C++  
**Development Environment:** Ubuntu / Linux Terminal  

---

# Project Overview

This project focuses on the implementation and understanding of important Data Structures using C++.

The assignment covers:

- Stack Data Structure
- Queue Data Structure
- Circular Queue
- Binary Tree
- Binary Search Tree (BST)
- Custom BST Dataset
- Duplicate Value Handling
- Tree Traversals
- Real-World Applications of Data Structures

The project includes C++ source code, presentations, diagrams, screenshots, and practical demonstrations performed using the Ubuntu/Linux terminal.

The main goal of this project is to understand how different data structures organize, store, access, and manage data and how these concepts are applied in real-world computing systems.

---

# 1. Stack Data Structure

## Introduction

A Stack is a linear data structure that follows the:

**LIFO – Last In, First Out**

This means that the element inserted last is the first element removed.

A simple real-world example is a stack of plates. The last plate placed on the top is the first plate that is removed.

## Stack Operations

The main operations implemented are:

- `push()` – Adds an element to the top of the stack
- `pop()` – Removes the top element from the stack
- `peek()` / `top()` – Views the top element without removing it
- `isEmpty()` – Checks whether the stack is empty
- `isFull()` – Checks whether the stack is full
- `displayAll()` – Displays all elements in the stack

## Stack Implementation

The Stack is implemented using a static array.

The `top` variable keeps track of the current top position of the stack.

Example:

```text
       +------+
       |  50  |  <- TOP
       +------+
       |  40  |
       +------+
       |  30  |
       +------+
       |  20  |
       +------+
       |  10  |
       +------+
