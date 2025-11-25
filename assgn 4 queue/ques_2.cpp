#include <iostream>
using namespace std;

#define SIZE 5   // Change size if needed

class CircularQueue {
private:
    int arr[SIZE];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1);
    }

    bool isFull() {
        return ((rear + 1) % SIZE == front);
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is FULL! Cannot enqueue.\n";
            return;
        }
        if (isEmpty()) { 
            front = rear = 0;
        } else {
            rear = (rear + 1) % SIZE;
        }
        arr[rear] = value;
        cout << value << " inserted.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is EMPTY! Cannot dequeue.\n";
            return;
        }
        cout << "Deleted: " << arr[front] << endl;

        if (front == rear) {
            // Queue became empty
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is EMPTY!\n";
            return -1;
        }
        return arr[front];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is EMPTY!\n";
            return;
        }

        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q;
    int choice, value;

    while (true) {
        cout << "\n--- Circular Queue Menu ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Check Empty\n";
        cout << "6. Check Full\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                q.enqueue(value);
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                value = q.peek();
                if (value != -1)
                    cout << "Front element: " << value << endl;
                break;

            case 4:
                q.display();
                break;

            case 5:
                cout << (q.isEmpty() ? "Queue is EMPTY\n" : "Queue is NOT empty\n");
                break;

            case 6:
                cout << (q.isFull() ? "Queue is FULL\n" : "Queue is NOT full\n");
                break;

            case 7:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice!\n";
        }
    }
}
