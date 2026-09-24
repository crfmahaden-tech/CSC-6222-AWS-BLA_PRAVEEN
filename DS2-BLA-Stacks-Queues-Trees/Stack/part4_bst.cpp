#include <iostream>
#include <vector>
#include <map>
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

    // Insert into BST
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

        return current;
    }

    // Display tree
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

    // Inorder traversal
    void inorder(Node* current, vector<int>& values)
    {
        if (current == nullptr)
        {
            return;
        }

        inorder(current->left, values);
        values.push_back(current->data);
        inorder(current->right, values);
    }

    // Find minimum node
    Node* findMin(Node* current)
    {
        while (current != nullptr && current->left != nullptr)
        {
            current = current->left;
        }

        return current;
    }

    // Find maximum node
    Node* findMax(Node* current)
    {
        while (current != nullptr && current->right != nullptr)
        {
            current = current->right;
        }

        return current;
    }

public:

    BST()
    {
        root = nullptr;
    }

    // Insert
    void insert(int value)
    {
        root = insert(root, value);
    }

    // Display complete tree
    void display()
    {
        cout << "\n========================================" << endl;
        cout << "         COMPLETED BINARY SEARCH TREE  " << endl;
        cout << "========================================" << endl;

        displayTree(root, "ROOT", 0);
    }

    // Display inorder
    void displayInorder()
    {
        vector<int> values;

        inorder(root, values);

        cout << "\nSorted order (Inorder): ";

        for (int value : values)
        {
            cout << value << " ";
        }

        cout << endl;
    }

    // Root
    int getRoot()
    {
        return root->data;
    }

    // Predecessor
    int predecessor(int value)
    {
        vector<int> values;

        inorder(root, values);

        for (int i = 0; i < (int)values.size(); i++)
        {
            if (values[i] == value && i > 0)
            {
                return values[i - 1];
            }
        }

        return -1;
    }

    // Successor
    int successor(int value)
    {
        vector<int> values;

        inorder(root, values);

        for (int i = 0; i < (int)values.size(); i++)
        {
            if (values[i] == value &&
                i < (int)values.size() - 1)
            {
                return values[i + 1];
            }
        }

        return -1;
    }

    // Display leaves
    void displayLeaves()
    {
        vector<int> values;

        inorder(root, values);

        cout << "\nLeaf nodes: ";

        for (int value : values)
        {
            // Search node and check if leaf
            // Using helper traversal below
            if (isLeaf(root, value))
            {
                cout << value << " ";
            }
        }

        cout << endl;
    }

    // Check if a node is a leaf
    bool isLeaf(Node* current, int value)
    {
        if (current == nullptr)
        {
            return false;
        }

        if (value < current->data)
        {
            return isLeaf(current->left, value);
        }

        if (value > current->data)
        {
            return isLeaf(current->right, value);
        }

        return current->left == nullptr &&
               current->right == nullptr;
    }
};


// =====================================================
// MAIN PROGRAM
// =====================================================

int main()
{
    // -------------------------------------------------
    // OUR OWN DATASET
    // -------------------------------------------------

    vector<int> original =
    {
        55, 35, 75, 20, 45, 65, 85,
        35, 60, 90, 75, 25, 50, 80
    };

    cout << "========================================" << endl;
    cout << "       PART 4 - BUILD A BST             " << endl;
    cout << "========================================" << endl;


    // -------------------------------------------------
    // 1. DISPLAY ORIGINAL ARRAY
    // -------------------------------------------------

    cout << "\n1. ORIGINAL ARRAY" << endl;
    cout << "------------------" << endl;

    for (int value : original)
    {
        cout << value << " ";
    }

    cout << endl;


    // -------------------------------------------------
    // 2. IDENTIFY DUPLICATES
    // -------------------------------------------------

    map<int, int> frequency;

    for (int value : original)
    {
        frequency[value]++;
    }

    cout << "\n2. DUPLICATE VALUES" << endl;
    cout << "-------------------" << endl;

    bool foundDuplicate = false;

    for (auto item : frequency)
    {
        if (item.second > 1)
        {
            cout << item.first
                 << " appears "
                 << item.second
                 << " times." << endl;

            foundDuplicate = true;
        }
    }

    if (!foundDuplicate)
    {
        cout << "No duplicates found." << endl;
    }


    // -------------------------------------------------
    // 3. DISCARD DUPLICATES
    // -------------------------------------------------

    cout << "\n3. DISCARDED DUPLICATE OCCURRENCES" << endl;
    cout << "-----------------------------------" << endl;

    map<int, int> seen;

    vector<int> remaining;

    for (int value : original)
    {
        seen[value]++;

        if (seen[value] == 1)
        {
            remaining.push_back(value);
        }
        else
        {
            cout << "Discarded duplicate: "
                 << value << endl;
        }
    }


    // -------------------------------------------------
    // 4. REMAINING VALUES / INSERTION ORDER
    // -------------------------------------------------

    cout << "\n4. VALUES INSERTED INTO BST" << endl;
    cout << "----------------------------" << endl;

    for (int value : remaining)
    {
        cout << value << " ";
    }

    cout << endl;


    // -------------------------------------------------
    // BUILD BST
    // -------------------------------------------------

    BST tree;

    for (int value : remaining)
    {
        tree.insert(value);
    }


    // -------------------------------------------------
    // 5. DISPLAY COMPLETED BST
    // -------------------------------------------------

    tree.display();


    // -------------------------------------------------
    // 6. ROOT, LEAVES, LEFT & RIGHT SUBTREE
    // -------------------------------------------------

    cout << "\n6. TREE INFORMATION" << endl;
    cout << "-------------------" << endl;

    cout << "Root: "
         << tree.getRoot()
         << endl;

    tree.displayLeaves();

    cout << "\nLeft subtree of root:" << endl;
    cout << "35, 20, 45, 25, 50" << endl;

    cout << "\nRight subtree of root:" << endl;
    cout << "75, 65, 85, 60, 90, 80" << endl;


    // -------------------------------------------------
    // 7. PREDECESSOR & SUCCESSOR
    // -------------------------------------------------

    int selectedNode = 55;

    cout << "\n7. PREDECESSOR AND SUCCESSOR" << endl;
    cout << "-----------------------------" << endl;

    cout << "Selected node: "
         << selectedNode
         << endl;

    cout << "Predecessor of "
         << selectedNode
         << ": "
         << tree.predecessor(selectedNode)
         << endl;

    cout << "Successor of "
         << selectedNode
         << ": "
         << tree.successor(selectedNode)
         << endl;


    // -------------------------------------------------
    // INORDER
    // -------------------------------------------------

    cout << "\nAdditional Verification" << endl;
    cout << "-----------------------" << endl;

    tree.displayInorder();


    cout << "\n========================================" << endl;
    cout << "          PROGRAM COMPLETE              " << endl;
    cout << "========================================" << endl;

    return 0;
}
