#include <iostream>
#include <vector>
using namespace std;

// =====================================================
// NODE CLASS
// =====================================================

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};


// =====================================================
// BINARY SEARCH TREE CLASS
// =====================================================

class BST
{
private:
    Node* root;

    // -------------------------------------------------
    // Insert into BST
    // -------------------------------------------------

    Node* insert(Node* current, int value)
    {
        if (current == nullptr)
        {
            return new Node(value);
        }

        if (value < current->data)
        {
            current->left = insert(current->left, value);
        }
        else if (value > current->data)
        {
            current->right = insert(current->right, value);
        }

        // Duplicate values are ignored

        return current;
    }


    // -------------------------------------------------
    // Inorder
    // LEFT -> ROOT -> RIGHT
    // -------------------------------------------------

    void inorder(Node* current, int& count)
    {
        if (current == nullptr)
        {
            return;
        }

        // Visit left subtree
        inorder(current->left, count);

        // Visit root/current node
        count++;
        cout << count << ". " << current->data << endl;

        // Visit right subtree
        inorder(current->right, count);
    }


    // -------------------------------------------------
    // Preorder
    // ROOT -> LEFT -> RIGHT
    // -------------------------------------------------

    void preorder(Node* current, int& count)
    {
        if (current == nullptr)
        {
            return;
        }

        // Visit root/current node
        count++;
        cout << count << ". " << current->data << endl;

        // Visit left subtree
        preorder(current->left, count);

        // Visit right subtree
        preorder(current->right, count);
    }


    // -------------------------------------------------
    // Postorder
    // LEFT -> RIGHT -> ROOT
    // -------------------------------------------------

    void postorder(Node* current, int& count)
    {
        if (current == nullptr)
        {
            return;
        }

        // Visit left subtree
        postorder(current->left, count);

        // Visit right subtree
        postorder(current->right, count);

        // Visit root/current node
        count++;
        cout << count << ". " << current->data << endl;
    }


    // -------------------------------------------------
    // Display Tree
    // -------------------------------------------------

    void displayTree(Node* current, string position, int level)
    {
        if (current == nullptr)
        {
            return;
        }

        for (int i = 0; i < level; i++)
        {
            cout << "    ";
        }

        cout << position << ": " << current->data << endl;

        displayTree(current->left, "L", level + 1);
        displayTree(current->right, "R", level + 1);
    }


public:

    // -------------------------------------------------
    // Constructor
    // -------------------------------------------------

    BST()
    {
        root = nullptr;
    }


    // -------------------------------------------------
    // Insert
    // -------------------------------------------------

    void insert(int value)
    {
        root = insert(root, value);
    }


    // -------------------------------------------------
    // Display Tree
    // -------------------------------------------------

    void displayTree()
    {
        cout << "\n========================================" << endl;
        cout << "        BINARY SEARCH TREE" << endl;
        cout << "========================================" << endl;

        displayTree(root, "ROOT", 0);
    }


    // -------------------------------------------------
    // Inorder Traversal
    // -------------------------------------------------

    void showInorder()
    {
        cout << "\n========================================" << endl;
        cout << "          INORDER TRAVERSAL" << endl;
        cout << "          LEFT -> ROOT -> RIGHT" << endl;
        cout << "========================================" << endl;

        int count = 0;

        inorder(root, count);
    }


    // -------------------------------------------------
    // Preorder Traversal
    // -------------------------------------------------

    void showPreorder()
    {
        cout << "\n========================================" << endl;
        cout << "         PREORDER TRAVERSAL" << endl;
        cout << "         ROOT -> LEFT -> RIGHT" << endl;
        cout << "========================================" << endl;

        int count = 0;

        preorder(root, count);
    }


    // -------------------------------------------------
    // Postorder Traversal
    // -------------------------------------------------

    void showPostorder()
    {
        cout << "\n========================================" << endl;
        cout << "         POSTORDER TRAVERSAL" << endl;
        cout << "         LEFT -> RIGHT -> ROOT" << endl;
        cout << "========================================" << endl;

        int count = 0;

        postorder(root, count);
    }
};


// =====================================================
// MAIN PROGRAM
// =====================================================

int main()
{
    // =================================================
    // SAME DATASET FROM PART 4
    // =================================================

    int values[] =
    {
        55, 35, 75, 20, 45, 65, 85,
        60, 90, 25, 50, 80
    };

    int size = sizeof(values) / sizeof(values[0]);


    cout << "========================================" << endl;
    cout << "       PART 5 - TREE TRAVERSALS" << endl;
    cout << "========================================" << endl;


    // =================================================
    // CREATE BST
    // =================================================

    BST tree;

    for (int i = 0; i < size; i++)
    {
        tree.insert(values[i]);
    }


    // =================================================
    // DISPLAY DATASET
    // =================================================

    cout << "\nBST values used from Part 4:" << endl;

    for (int i = 0; i < size; i++)
    {
        cout << values[i] << " ";
    }

    cout << endl;


    // =================================================
    // DISPLAY BST
    // =================================================

    tree.displayTree();


    // =================================================
    // DISPLAY ALL THREE TRAVERSALS
    // =================================================

    tree.showInorder();

    tree.showPreorder();

    tree.showPostorder();


    // =================================================
    // FINAL RESULTS
    // =================================================

    cout << "\n========================================" << endl;
    cout << "             FINAL RESULTS" << endl;
    cout << "========================================" << endl;

    cout << "\nInorder:" << endl;
    cout << "20 25 35 45 50 55 60 65 75 80 85 90" << endl;

    cout << "\nPreorder:" << endl;
    cout << "55 35 20 25 45 50 75 65 60 85 80 90" << endl;

    cout << "\nPostorder:" << endl;
    cout << "25 20 50 45 35 60 65 80 90 85 75 55" << endl;


    cout << "\n========================================" << endl;
    cout << "          PROGRAM COMPLETE" << endl;
    cout << "========================================" << endl;

    return 0;
}
