
#include "bst.h"

#include <iostream>
#include <limits>
#include <sstream>
#include <string>

using namespace std;

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
                    cout << "Description: "
                         << record->description << '\n';
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
