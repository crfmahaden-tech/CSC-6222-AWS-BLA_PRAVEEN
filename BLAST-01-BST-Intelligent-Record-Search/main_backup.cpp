
#include <iostream>
#include <string>
#include <limits>
#include <sstream>
#include <utility>

using namespace std;

// Stores information about one record
struct Record {
    int id;
    string description;
};

// One node in the Binary Search Tree
struct Node {
    Record data;
    Node* left;
    Node* right;

    Node(int recordId, const string& recordDescription)
        : data{recordId, recordDescription},
          left(nullptr), right(nullptr) {}
};

// Binary Search Tree class
class BinarySearchTree {
private:
    Node* root;
    int totalRecords;

    Node* insertNode(Node* node, int id,
                     const string& description, bool& inserted) {
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

    Node* findNode(Node* node, int id) const {
        if (node == nullptr || node->data.id == id) {
            return node;
        }

        if (id < node->data.id) {
            return findNode(node->left, id);
        }

        return findNode(node->right, id);
    }

    Node* minimumNode(Node* node) const {
        while (node != nullptr && node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    Node* maximumNode(Node* node) const {
        while (node != nullptr && node->right != nullptr) {
            node = node->right;
        }
        return node;
    }

    Node* deleteNode(Node* node, int id, bool& deleted) {
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
                node->right, successor->data.id, successorDeleted
            );
        }

        return node;
    }

    void displayInOrder(Node* node) const {
        if (node == nullptr) {
            return;
        }

        displayInOrder(node->left);

        cout << "ID: " << node->data.id
             << " | Description: " << node->data.description << '\n';

        displayInOrder(node->right);
    }

    void clearTree(Node* node) {
        if (node == nullptr) {
            return;
        }

        clearTree(node->left);
        clearTree(node->right);
        delete node;
    }

public:
    BinarySearchTree() : root(nullptr), totalRecords(0) {}

    ~BinarySearchTree() {
        clearTree(root);
    }

    // Prevent accidental copying of raw node pointers
    BinarySearchTree(const BinarySearchTree&) = delete;
    BinarySearchTree& operator=(const BinarySearchTree&) = delete;

    bool insert(int id, const string& description) {
        bool inserted = false;
        root = insertNode(root, id, description, inserted);

        if (inserted) {
            totalRecords++;
        }

        return inserted;
    }

    const Record* search(int id) const {
        Node* result = findNode(root, id);

        if (result == nullptr) {
            return nullptr;
        }

        return &result->data;
    }

    bool remove(int id) {
        bool deleted = false;
        root = deleteNode(root, id, deleted);

        if (deleted) {
            totalRecords--;
        }

        return deleted;
    }

    void displayAll() const {
        if (root == nullptr) {
            cout << "The tree is empty. Add a record first.\n";
            return;
        }

        cout << "\n--- Records in Ascending ID Order ---\n";
        displayInOrder(root);
    }

    void displayMinimumMaximum() const {
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

    int count() const {
        return totalRecords;
    }

    bool isEmpty() const {
        return root == nullptr;
    }
};

// Reads a valid integer without accepting extra characters
bool readInteger(const string& prompt, int& value) {
    cout << prompt;

    string line;
    if (!getline(cin, line)) {
        return false;
    }

    stringstream input(line);
    char extra;

    if (!(input >> value) || (input >> extra)) {
        cout << "Invalid input. Please enter a whole number.\n";
        return false;
    }

    return true;
}

int main() {
    BinarySearchTree bst;
    bool running = true;

    while (running) {
        cout << "\n====================================\n";
        cout << " INTELLIGENT RECORD-SEARCH SYSTEM\n";
        cout << "====================================\n";
        cout << "1. Add a record\n";
        cout << "2. Search by record ID\n";
        cout << "3. Delete a record\n";
        cout << "4. Display all records (sorted)\n";
        cout << "5. Display minimum and maximum IDs\n";
        cout << "6. Show total number of records\n";
        cout << "0. Exit\n";

        int choice;
        if (!readInteger("Enter your choice: ", choice)) {
            if (!cin) {
                break;
            }
            continue;
        }

        switch (choice) {
            case 1: {
                int id;

                if (!readInteger("Enter record ID: ", id)) {
                    if (!cin) running = false;
                    break;
                }

                if (id <= 0) {
                    cout << "Record ID must be a positive integer.\n";
                    break;
                }

                if (bst.search(id) != nullptr) {
                    cout << "This ID already exists. Duplicate rejected.\n";
                    break;
                }

                cout << "Enter record description: ";
                string description;

                if (!getline(cin, description)) {
                    running = false;
                    break;
                }

                if (description.find_first_not_of(" \t\r\n") ==
                    string::npos) {
                    cout << "Description cannot be empty.\n";
                    break;
                }

                if (bst.insert(id, description)) {
                    cout << "Record added successfully.\n";
                }
                break;
            }

            case 2: {
                int id;

                if (!readInteger("Enter ID to search: ", id)) {
                    if (!cin) running = false;
                    break;
                }

                const Record* record = bst.search(id);

                if (record != nullptr) {
                    cout << "\nRecord found!\n";
                    cout << "ID: " << record->id << '\n';
                    cout << "Description: " << record->description << '\n';
                } else {
                    cout << "Record not found.\n";
                }
                break;
            }

            case 3: {
                int id;

                if (!readInteger("Enter ID to delete: ", id)) {
                    if (!cin) running = false;
                    break;
                }

                if (bst.remove(id)) {
                    cout << "Record deleted successfully.\n";
                } else {
                    cout << "Record not found. Nothing was deleted.\n";
                }
                break;
            }

            case 4:
                bst.displayAll();
                break;

            case 5:
                bst.displayMinimumMaximum();
                break;

            case 6:
                cout << "Total records: " << bst.count() << '\n';
                break;

            case 0:
                running = false;
                cout << "Thank you for using the system. Goodbye!\n";
                break;

            default:
                cout << "Invalid menu choice. Select an option from 0 to 6.\n";
        }
    }

    return 0;
}
