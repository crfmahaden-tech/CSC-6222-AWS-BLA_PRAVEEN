#include <iostream>
#include <string>
using namespace std;

// ======================================================
// NODE CLASS
// ======================================================

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};


// ======================================================
// BINARY SEARCH TREE CLASS
// ======================================================

class BinarySearchTree
{
private:
    Node* root;

    // --------------------------------------------------
    // Insert a value into the BST
    // --------------------------------------------------
    Node* insert(Node* current, int value)
    {
        // Empty position found
        if (current == nullptr)
        {
            return new Node(value);
        }

        // Smaller value -> LEFT
        if (value < current->data)
        {
            current->left = insert(current->left, value);
        }

        // Larger value -> RIGHT
        else if (value > current->data)
        {
            current->right = insert(current->right, value);
        }

        // Equal value -> Duplicate
        else
        {
            cout << "Duplicate value " << value
                 << " ignored. Duplicates are not allowed."
                 << endl;
        }

        return current;
    }


    // --------------------------------------------------
    // Search for a value
    // --------------------------------------------------
    bool search(Node* current, int value)
    {
        if (current == nullptr)
        {
            return false;
        }

        // Value found
        if (value == current->data)
        {
            return true;
        }

        // Search left
        if (value < current->data)
        {
            return search(current->left, value);
        }

        // Search right
        return search(current->right, value);
    }


    // --------------------------------------------------
    // Inorder Traversal
    // Left -> Root -> Right
    // --------------------------------------------------
    void inorder(Node* current)
    {
        if (current == nullptr)
        {
            return;
        }

        inorder(current->left);

        cout << current->data << " ";

        inorder(current->right);
    }


    // --------------------------------------------------
    // Preorder Traversal
    // Root -> Left -> Right
    // --------------------------------------------------
    void preorder(Node* current)
    {
        if (current == nullptr)
        {
            return;
        }

        cout << current->data << " ";

        preorder(current->left);

        preorder(current->right);
    }


    // --------------------------------------------------
    // Postorder Traversal
    // Left -> Right -> Root
    // --------------------------------------------------
    void postorder(Node* current)
    {
        if (current == nullptr)
        {
            return;
        }

        postorder(current->left);

        postorder(current->right);

        cout << current->data << " ";
    }


    // --------------------------------------------------
    // Display the tree clearly
    // --------------------------------------------------
    void displayTree(Node* current, string position, int level)
    {
        if (current == nullptr)
        {
            return;
        }

        // Indentation
        for (int i = 0; i < level; i++)
        {
            cout << "    ";
        }

        // Print node
        cout << position << ": " << current->data << endl;

        // Display left subtree
        displayTree(current->left, "L", level + 1);

        // Display right subtree
        displayTree(current->right, "R", level + 1);
    }


    // --------------------------------------------------
    // Delete all nodes from memory
    // --------------------------------------------------
    void deleteTree(Node* current)
    {
        if (current == nullptr)
        {
            return;
        }

        deleteTree(current->left);
        deleteTree(current->right);

        delete current;
    }


public:

    // --------------------------------------------------
    // Constructor
    // --------------------------------------------------
    BinarySearchTree()
    {
        root = nullptr;
    }


    // --------------------------------------------------
    // Destructor
    // --------------------------------------------------
    ~BinarySearchTree()
    {
        deleteTree(root);
    }


    // --------------------------------------------------
    // Public Insert
    // --------------------------------------------------
    void insert(int value)
    {
        root = insert(root, value);
    }


    // --------------------------------------------------
    // Public Search
    // --------------------------------------------------
    void searchValue(int value)
    {
        if (search(root, value))
        {
            cout << value
                 << " was found in the BST."
                 << endl;
        }
        else
        {
            cout << value
                 << " was NOT found in the BST."
                 << endl;
        }
    }


    // --------------------------------------------------
    // Display Tree
    // --------------------------------------------------
    void showTree()
    {
        cout << endl;
        cout << "=========================================" << endl;
        cout << "          BINARY SEARCH TREE             " << endl;
        cout << "=========================================" << endl;

        if (root == nullptr)
        {
            cout << "Tree is empty." << endl;
        }
        else
        {
            displayTree(root, "ROOT", 0);
        }

        cout << "=========================================" << endl;
    }


    // --------------------------------------------------
    // Display Inorder
    // --------------------------------------------------
    void showInorder()
    {
        cout << "Inorder Traversal: ";

        if (root == nullptr)
        {
            cout << "Tree is empty.";
        }
        else
        {
            inorder(root);
        }

        cout << endl;
    }


    // --------------------------------------------------
    // Display Preorder
    // --------------------------------------------------
    void showPreorder()
    {
        cout << "Preorder Traversal: ";

        if (root == nullptr)
        {
            cout << "Tree is empty.";
        }
        else
        {
            preorder(root);
        }

        cout << endl;
    }


    // --------------------------------------------------
    // Display Postorder
    // --------------------------------------------------
    void showPostorder()
    {
        cout << "Postorder Traversal: ";

        if (root == nullptr)
        {
            cout << "Tree is empty.";
        }
        else
        {
            postorder(root);
        }

        cout << endl;
    }
};


// ======================================================
// MAIN PROGRAM
// ======================================================

int main()
{
    BinarySearchTree bst;

    int choice;
    int value;

    cout << "=========================================" << endl;
    cout << "     BINARY SEARCH TREE PROGRAM          " << endl;
    cout << "=========================================" << endl;

    do
    {
        cout << endl;
        cout << "--------------- MENU ----------------" << endl;
        cout << "1. Insert a value" << endl;
        cout << "2. Search for a value" << endl;
        cout << "3. Display tree" << endl;
        cout << "4. Inorder traversal" << endl;
        cout << "5. Preorder traversal" << endl;
        cout << "6. Postorder traversal" << endl;
        cout << "7. Exit" << endl;
        cout << "--------------------------------------" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            // ------------------------------------------
            // INSERT
            // ------------------------------------------
            case 1:

                cout << "Enter value to insert: ";
                cin >> value;

                bst.insert(value);

                break;


            // ------------------------------------------
            // SEARCH
            // ------------------------------------------
            case 2:

                cout << "Enter value to search: ";
                cin >> value;

                bst.searchValue(value);

                break;


            // ------------------------------------------
            // DISPLAY TREE
            // ------------------------------------------
            case 3:

                bst.showTree();

                break;


            // ------------------------------------------
            // INORDER
            // ------------------------------------------
            case 4:

                bst.showInorder();

                break;


            // ------------------------------------------
            // PREORDER
            // ------------------------------------------
            case 5:

                bst.showPreorder();

                break;


            // ------------------------------------------
            // POSTORDER
            // ------------------------------------------
            case 6:

                bst.showPostorder();

                break;


            // ------------------------------------------
            // EXIT
            // ------------------------------------------
            case 7:

                cout << "Exiting program..." << endl;

                break;


            // ------------------------------------------
            // INVALID CHOICE
            // ------------------------------------------
            default:

                cout << "Invalid choice. Please try again."
                     << endl;
        }

    } while (choice != 7);


    return 0;
}
