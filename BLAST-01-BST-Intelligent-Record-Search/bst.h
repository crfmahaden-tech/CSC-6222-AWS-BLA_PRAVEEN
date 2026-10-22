
#ifndef BST_H
#define BST_H

#include <string>

// Stores information about one record
struct Record {
    int id;
    std::string description;
};

// One node in the Binary Search Tree
struct Node {
    Record data;
    Node* left;
    Node* right;

    Node(int recordId, const std::string& recordDescription);
};

// Binary Search Tree class
class BinarySearchTree {
private:
    Node* root;
    int totalRecords;

    Node* insertNode(Node* node, int id,
                     const std::string& description, bool& inserted);

    Node* findNode(Node* node, int id) const;
    Node* minimumNode(Node* node) const;
    Node* maximumNode(Node* node) const;

    Node* deleteNode(Node* node, int id, bool& deleted);

    void displayInOrder(Node* node) const;
    void clearTree(Node* node);

public:
    BinarySearchTree();
    ~BinarySearchTree();

    BinarySearchTree(const BinarySearchTree&) = delete;
    BinarySearchTree& operator=(const BinarySearchTree&) = delete;

    bool insert(int id, const std::string& description);
    const Record* search(int id) const;
    bool remove(int id);

    void displayAll() const;
    void displayMinimumMaximum() const;

    int count() const;
    bool isEmpty() const;
};

#endif
