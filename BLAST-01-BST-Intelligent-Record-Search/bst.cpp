
#include "bst.h"

#include <iostream>
#include <utility>

using namespace std;

Node::Node(int recordId, const string& recordDescription)
    : data{recordId, recordDescription},
      left(nullptr), right(nullptr) {}

BinarySearchTree::BinarySearchTree()
    : root(nullptr), totalRecords(0) {}

BinarySearchTree::~BinarySearchTree() {
    clearTree(root);
}

Node* BinarySearchTree::insertNode(
    Node* node, int id, const string& description, bool& inserted) {

    if (node == nullptr) {
        inserted = true;
        return new Node(id, description);
    }

    if (id < node->data.id) {
        node->left = insertNode(node->left, id, description, inserted);
    } else if (id > node->data.id) {
        node->right = insertNode(node->right, id, description, inserted);
    }

    return node;
}

Node* BinarySearchTree::findNode(Node* node, int id) const {
    if (node == nullptr || node->data.id == id) {
        return node;
    }

    if (id < node->data.id) {
        return findNode(node->left, id);
    }

    return findNode(node->right, id);
}

Node* BinarySearchTree::minimumNode(Node* node) const {
    while (node != nullptr && node->left != nullptr) {
        node = node->left;
    }
    return node;
}

Node* BinarySearchTree::maximumNode(Node* node) const {
    while (node != nullptr && node->right != nullptr) {
        node = node->right;
    }
    return node;
}

Node* BinarySearchTree::deleteNode(
    Node* node, int id, bool& deleted) {

    if (node == nullptr) {
        return nullptr;
    }

    if (id < node->data.id) {
        node->left = deleteNode(node->left, id, deleted);
    } else if (id > node->data.id) {
        node->right = deleteNode(node->right, id, deleted);
    } else {
        deleted = true;

        // Case 1: No left child
        if (node->left == nullptr) {
            Node* replacement = node->right;
            delete node;
            return replacement;
        }

        // Case 2: No right child
        if (node->right == nullptr) {
            Node* replacement = node->left;
            delete node;
            return replacement;
        }

        // Case 3: Two children
        Node* successor = minimumNode(node->right);
        node->data = successor->data;

        bool successorDeleted = false;
        node->right = deleteNode(
            node->right, successor->data.id, successorDeleted);
    }

    return node;
}

bool BinarySearchTree::insert(
    int id, const string& description) {

    bool inserted = false;
    root = insertNode(root, id, description, inserted);

    if (inserted) {
        ++totalRecords;
    }

    return inserted;
}

const Record* BinarySearchTree::search(int id) const {
    Node* result = findNode(root, id);

    if (result == nullptr) {
        return nullptr;
    }

    return &result->data;
}

bool BinarySearchTree::remove(int id) {
    bool deleted = false;
    root = deleteNode(root, id, deleted);

    if (deleted) {
        --totalRecords;
    }

    return deleted;
}

void BinarySearchTree::displayInOrder(Node* node) const {
    if (node == nullptr) {
        return;
    }

    displayInOrder(node->left);

    cout << "ID: " << node->data.id
         << " | Description: " << node->data.description << '\n';

    displayInOrder(node->right);
}

void BinarySearchTree::displayAll() const {
    if (root == nullptr) {
        cout << "The tree is empty. Add a record first.\n";
        return;
    }

    cout << "\n--- Records in Ascending ID Order ---\n";
    displayInOrder(root);
}

void BinarySearchTree::displayMinimumMaximum() const {
    if (root == nullptr) {
        cout << "The tree is empty. No minimum or maximum ID.\n";
        return;
    }

    Node* smallest = minimumNode(root);
    Node* largest = maximumNode(root);

    cout << "Minimum ID: " << smallest->data.id
         << " (" << smallest->data.description << ")\n";

    cout << "Maximum ID: " << largest->data.id
         << " (" << largest->data.description << ")\n";
}

void BinarySearchTree::clearTree(Node* node) {
    if (node == nullptr) {
        return;
    }

    clearTree(node->left);
    clearTree(node->right);
    delete node;
}

int BinarySearchTree::count() const {
    return totalRecords;
}

bool BinarySearchTree::isEmpty() const {
    return root == nullptr;
}
