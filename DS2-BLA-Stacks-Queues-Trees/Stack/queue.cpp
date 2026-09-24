#include <iostream>
using namespace std;

// ======================================================
// LINEAR QUEUE
// ======================================================

class LinearQueue {
private:
    static const int MAX_SIZE = 5;
    int arr[MAX_SIZE];
    int front;
    int rear;

public:
    LinearQueue() {
        front = 0;
        rear = -1;
    }

    bool isEmpty() {
        return rear < front;
    }

    bool isFull() {
        return rear == MAX_SIZE - 1;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot enqueue "
                 << value << "." << endl;
            return;
        }

        rear++;
        arr[rear] = value;

        cout << value << " enqueued into the linear queue." << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Queue is empty." << endl;
            return;
        }

        cout << arr[front] << " dequeued from the linear queue."
             << endl;

        front++;
    }

    void displayAll() {
        if (isEmpty()) {
            cout << "Linear queue is empty." << endl;
            return;
        }

        cout << "\nLinear Queue:" << endl;

        for (int i = front; i <= rear; i++) {
            cout << "| " << arr[i] << " |";

            if (i == front)
                cout << " <- FRONT";

            if (i == rear)
                cout << " <- REAR";

            cout << endl;
        }
    }
};


// ======================================================
// CIRCULAR QUEUE
// ======================================================

class CircularQueue {
private:
    static const int MAX_SIZE = 5;
    int arr[MAX_SIZE];
    int front;
    int rear;
    int count;

public:
    CircularQueue() {
        front = 0;
        rear = -1;
        count = 0;
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == MAX_SIZE;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Circular Queue Overflow! Cannot enqueue "
                 << value << "." << endl;
            return;
        }

        rear = (rear + 1) % MAX_SIZE;
        arr[rear] = value;
        count++;

        cout << value << " enqueued into the circular queue." << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Circular Queue Underflow! Queue is empty."
                 << endl;
            return;
        }

        cout << arr[front]
             << " dequeued from the circular queue." << endl;

        front = (front + 1) % MAX_SIZE;
        count--;
    }

    void displayAll() {
        if (isEmpty()) {
            cout << "Circular queue is empty." << endl;
            return;
        }

        cout << "\nCircular Queue:" << endl;

        int index = front;

        for (int i = 0; i < count; i++) {

            cout << "| " << arr[index] << " |";

            if (index == front)
                cout << " <- FRONT";

            if (index == rear)
                cout << " <- REAR";

            cout << endl;

            index = (index + 1) % MAX_SIZE;
        }
    }

    void showPositions() {
        cout << "\nArray Positions:" << endl;

        for (int i = 0; i < MAX_SIZE; i++) {
            cout << "Index " << i << ": ";

            if (count == 0) {
                cout << "EMPTY";
            } else {
                bool occupied = false;
                int index = front;

                for (int j = 0; j < count; j++) {
                    if (index == i) {
                        occupied = true;
                        cout << arr[i];
                        break;
                    }

                    index = (index + 1) % MAX_SIZE;
                }

                if (!occupied)
                    cout << "EMPTY";
            }

            cout << endl;
        }

        cout << "Front index: " << front << endl;
        cout << "Rear index: " << rear << endl;
    }
};


// ======================================================
// MAIN PROGRAM
// ======================================================

int main() {

    LinearQueue linearQueue;
    CircularQueue circularQueue;

    int mainChoice;
    int choice;
    int value;

    do {

        cout << "\n========================================" << endl;
        cout << "       QUEUE DEMONSTRATION PROGRAM      " << endl;
        cout << "========================================" << endl;

        cout << "1. Linear Queue" << endl;
        cout << "2. Circular Queue" << endl;
        cout << "3. Exit" << endl;

        cout << "\nEnter your choice: ";
        cin >> mainChoice;

        // ==========================================
        // LINEAR QUEUE MENU
        // ==========================================

        if (mainChoice == 1) {

            do {

                cout << "\n----------------------------------------" << endl;
                cout << "             LINEAR QUEUE               " << endl;
                cout << "----------------------------------------" << endl;

                cout << "1. Enqueue" << endl;
                cout << "2. Dequeue" << endl;
                cout << "3. Is Empty" << endl;
                cout << "4. Is Full" << endl;
                cout << "5. Display All" << endl;
                cout << "6. Back to Main Menu" << endl;

                cout << "\nEnter your choice: ";
                cin >> choice;

                switch (choice) {

                    case 1:
                        cout << "Enter value: ";
                        cin >> value;
                        linearQueue.enqueue(value);
                        break;

                    case 2:
                        linearQueue.dequeue();
                        break;

                    case 3:
                        if (linearQueue.isEmpty())
                            cout << "Linear queue is EMPTY." << endl;
                        else
                            cout << "Linear queue is NOT empty." << endl;
                        break;

                    case 4:
                        if (linearQueue.isFull())
                            cout << "Linear queue is FULL." << endl;
                        else
                            cout << "Linear queue is NOT full." << endl;
                        break;

                    case 5:
                        linearQueue.displayAll();
                        break;

                    case 6:
                        cout << "Returning to main menu..." << endl;
                        break;

                    default:
                        cout << "Invalid choice." << endl;
                }

            } while (choice != 6);
        }

        // ==========================================
        // CIRCULAR QUEUE MENU
        // ==========================================

        else if (mainChoice == 2) {

            do {

                cout << "\n----------------------------------------" << endl;
                cout << "            CIRCULAR QUEUE              " << endl;
                cout << "----------------------------------------" << endl;

                cout << "1. Enqueue" << endl;
                cout << "2. Dequeue" << endl;
                cout << "3. Is Empty" << endl;
                cout << "4. Is Full" << endl;
                cout << "5. Display All" << endl;
                cout << "6. Show Array Positions" << endl;
                cout << "7. Back to Main Menu" << endl;

                cout << "\nEnter your choice: ";
                cin >> choice;

                switch (choice) {

                    case 1:
                        cout << "Enter value: ";
                        cin >> value;
                        circularQueue.enqueue(value);
                        break;

                    case 2:
                        circularQueue.dequeue();
                        break;

                    case 3:
                        if (circularQueue.isEmpty())
                            cout << "Circular queue is EMPTY." << endl;
                        else
                            cout << "Circular queue is NOT empty." << endl;
                        break;

                    case 4:
                        if (circularQueue.isFull())
                            cout << "Circular queue is FULL." << endl;
                        else
                            cout << "Circular queue is NOT full." << endl;
                        break;

                    case 5:
                        circularQueue.displayAll();
                        break;

                    case 6:
                        circularQueue.showPositions();
                        break;

                    case 7:
                        cout << "Returning to main menu..." << endl;
                        break;

                    default:
                        cout << "Invalid choice." << endl;
                }

            } while (choice != 7);
        }

        else if (mainChoice == 3) {
            cout << "\nProgram ended." << endl;
        }

        else {
            cout << "Invalid choice." << endl;
        }

    } while (mainChoice != 3);

    return 0;
}
