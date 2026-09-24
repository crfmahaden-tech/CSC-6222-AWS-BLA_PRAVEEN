#include <iostream>
using namespace std;

class Stack {
private:
    static const int MAX_SIZE = 5;
    int arr[MAX_SIZE];
    int top;

public:
    // Constructor
    Stack() {
        top = -1;
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Check if stack is full
    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    // Push an element
    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << value << "." << endl;
            return;
        }

        top++;
        arr[top] = value;

        cout << value << " pushed into the stack." << endl;
    }

    // Pop an element
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Stack is empty." << endl;
            return;
        }

        cout << arr[top] << " popped from the stack." << endl;
        top--;
    }

    // View the top element
    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty. Nothing to peek." << endl;
            return;
        }

        cout << "Top element is: " << arr[top] << endl;
    }

    // Display all elements
    void displayAll() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }

        cout << "\nStack elements:" << endl;

        for (int i = top; i >= 0; i--) {
            cout << "|  " << arr[i] << "  |";

            if (i == top) {
                cout << " <- TOP";
            }

            cout << endl;
        }

        cout << "-------" << endl;
    }
};

int main() {

    Stack stack;
    int choice;
    int value;

    cout << "==================================" << endl;
    cout << "       STATIC ARRAY STACK         " << endl;
    cout << "==================================" << endl;

    do {
        cout << "\n----------- MENU -----------" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek / Top" << endl;
        cout << "4. Is Empty" << endl;
        cout << "5. Is Full" << endl;
        cout << "6. Display All" << endl;
        cout << "7. Exit" << endl;
        cout << "----------------------------" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                stack.push(value);
                break;

            case 2:
                stack.pop();
                break;

            case 3:
                stack.peek();
                break;

            case 4:
                if (stack.isEmpty()) {
                    cout << "Stack is EMPTY." << endl;
                } else {
                    cout << "Stack is NOT empty." << endl;
                }
                break;

            case 5:
                if (stack.isFull()) {
                    cout << "Stack is FULL." << endl;
                } else {
                    cout << "Stack is NOT full." << endl;
                }
                break;

            case 6:
                stack.displayAll();
                break;

            case 7:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 7);

    return 0;
}
