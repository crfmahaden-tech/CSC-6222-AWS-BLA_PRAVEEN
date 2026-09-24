#include <iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;


// =====================================================
// SIMPLE TREE NODE FOR FILE SYSTEM
// =====================================================

class FileNode
{
public:
    string name;
    FileNode* child1;
    FileNode* child2;

    FileNode(string fileName)
    {
        name = fileName;
        child1 = nullptr;
        child2 = nullptr;
    }
};


// =====================================================
// BST NODE
// =====================================================

class BSTNode
{
public:
    int data;
    BSTNode* left;
    BSTNode* right;

    BSTNode(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};


// =====================================================
// BST CLASS
// =====================================================

class BST
{
private:
    BSTNode* root;

    BSTNode* insert(BSTNode* current, int value)
    {
        if (current == nullptr)
        {
            return new BSTNode(value);
        }

        if (value < current->data)
        {
            current->left = insert(current->left, value);
        }
        else if (value > current->data)
        {
            current->right = insert(current->right, value);
        }

        return current;
    }

    bool search(BSTNode* current, int value)
    {
        if (current == nullptr)
        {
            return false;
        }

        if (value == current->data)
        {
            return true;
        }

        if (value < current->data)
        {
            return search(current->left, value);
        }

        return search(current->right, value);
    }

    void inorder(BSTNode* current)
    {
        if (current == nullptr)
        {
            return;
        }

        inorder(current->left);
        cout << current->data << " ";
        inorder(current->right);
    }

public:

    BST()
    {
        root = nullptr;
    }

    void insert(int value)
    {
        root = insert(root, value);
    }

    bool searchValue(int value)
    {
        return search(root, value);
    }

    void displaySorted()
    {
        inorder(root);
        cout << endl;
    }
};


// =====================================================
// STACK APPLICATION - UNDO
// =====================================================

void demonstrateStack()
{
    cout << "\n========================================" << endl;
    cout << "     APPLICATION 1: STACK - UNDO" << endl;
    cout << "========================================" << endl;

    stack<string> actions;

    cout << "\nPerforming actions:" << endl;

    actions.push("Type Hello");
    cout << "Action: Type Hello" << endl;

    actions.push("Add Name");
    cout << "Action: Add Name" << endl;

    actions.push("Change Font");
    cout << "Action: Change Font" << endl;

    cout << "\nUndo operation:" << endl;

    cout << "Undo: " << actions.top() << endl;
    actions.pop();

    cout << "Undo: " << actions.top() << endl;
    actions.pop();

    cout << "\nWhy Stack?" << endl;
    cout << "The most recent action is undone first." << endl;
    cout << "This follows LIFO: Last In, First Out." << endl;
}


// =====================================================
// QUEUE APPLICATION - PRINT QUEUE
// =====================================================

void demonstrateQueue()
{
    cout << "\n========================================" << endl;
    cout << "     APPLICATION 2: QUEUE - PRINTING" << endl;
    cout << "========================================" << endl;

    queue<string> printQueue;

    cout << "\nDocuments added to print queue:" << endl;

    printQueue.push("Report.pdf");
    cout << "Added: Report.pdf" << endl;

    printQueue.push("Resume.docx");
    cout << "Added: Resume.docx" << endl;

    printQueue.push("Assignment.pdf");
    cout << "Added: Assignment.pdf" << endl;

    cout << "\nPrinting documents:" << endl;

    while (!printQueue.empty())
    {
        cout << "Printing: "
             << printQueue.front()
             << endl;

        printQueue.pop();
    }

    cout << "\nWhy Queue?" << endl;
    cout << "The first document added is printed first." << endl;
    cout << "This follows FIFO: First In, First Out." << endl;
}


// =====================================================
// TREE APPLICATION - FILE SYSTEM
// =====================================================

void demonstrateFileSystem()
{
    cout << "\n========================================" << endl;
    cout << "     APPLICATION 3: TREE - FILE SYSTEM" << endl;
    cout << "========================================" << endl;

    FileNode root("Documents");

    root.child1 = new FileNode("Reports");
    root.child2 = new FileNode("Pictures");

    root.child1->child1 = new FileNode("Report.docx");
    root.child1->child2 = new FileNode("Notes.txt");

    root.child2->child1 = new FileNode("Photo1.jpg");
    root.child2->child2 = new FileNode("Photo2.jpg");

    cout << "\nFile System Hierarchy:" << endl;

    cout << "Documents" << endl;
    cout << "|-- Reports" << endl;
    cout << "|   |-- Report.docx" << endl;
    cout << "|   |-- Notes.txt" << endl;
    cout << "|" << endl;
    cout << "|-- Pictures" << endl;
    cout << "    |-- Photo1.jpg" << endl;
    cout << "    |-- Photo2.jpg" << endl;

    cout << "\nWhy Tree?" << endl;
    cout << "A file system has a parent-child hierarchy." << endl;
    cout << "Folders can contain subfolders and files." << endl;
}


// =====================================================
// BST APPLICATION - ORDERED SEARCHING
// =====================================================

void demonstrateBST()
{
    cout << "\n========================================" << endl;
    cout << "     APPLICATION 4: BST - SEARCHING" << endl;
    cout << "========================================" << endl;

    BST tree;

    int values[] =
    {
        50, 30, 70, 20, 40, 60, 80
    };

    cout << "\nAdding ordered data:" << endl;

    for (int value : values)
    {
        tree.insert(value);
        cout << value << " ";
    }

    cout << endl;

    cout << "\nSorted data using inorder traversal:" << endl;

    tree.displaySorted();

    int searchValue;

    cout << "\nEnter a number to search: ";
    cin >> searchValue;

    if (tree.searchValue(searchValue))
    {
        cout << searchValue
             << " was found in the BST." << endl;
    }
    else
    {
        cout << searchValue
             << " was not found in the BST." << endl;
    }

    cout << "\nWhy BST?" << endl;
    cout << "A BST organizes values using comparisons." << endl;
    cout << "Smaller values go LEFT." << endl;
    cout << "Larger values go RIGHT." << endl;
    cout << "This makes it useful for ordered searching." << endl;
}


// =====================================================
// MAIN
// =====================================================

int main()
{
    int choice;

    do
    {
        cout << "\n\n========================================" << endl;
        cout << "      DATA STRUCTURE APPLICATIONS" << endl;
        cout << "========================================" << endl;

        cout << "1. Stack - Undo/Redo" << endl;
        cout << "2. Queue - Print Queue" << endl;
        cout << "3. Tree - File System" << endl;
        cout << "4. BST - Ordered Searching" << endl;
        cout << "5. Run All Applications" << endl;
        cout << "6. Exit" << endl;

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                demonstrateStack();
                break;

            case 2:
                demonstrateQueue();
                break;

            case 3:
                demonstrateFileSystem();
                break;

            case 4:
                demonstrateBST();
                break;

            case 5:
                demonstrateStack();
                demonstrateQueue();
                demonstrateFileSystem();
                demonstrateBST();
                break;

            case 6:
                cout << "\nProgram completed." << endl;
                break;

            default:
                cout << "\nInvalid choice." << endl;
        }

    } while (choice != 6);

    return 0;
}
