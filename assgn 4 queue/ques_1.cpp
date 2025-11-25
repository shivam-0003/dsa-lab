#include <iostream>
using namespace std;

#define MAX 5   // Size of Queue

class Queue {
private:
    int arr[MAX];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    bool isFull() {
        return (rear == MAX - 1);
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is FULL! Cannot enqueue.\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear++;
        }
        arr[rear] = value;
        cout << value << " enqueued.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is EMPTY! Cannot dequeue.\n";
            return;
        }
        cout << arr[front] << " dequeued.\n";

        if (front == rear) { 
            front = rear = -1;      // Queue becomes empty
        } else {
            front++;
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is EMPTY! No front element.\n";
        } else {
            cout << "Front element: " << arr[front] << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is EMPTY!\n";
            return;
        }

        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    int choice, value;

    while (true) {
        cout << "\n--- Queue Menu ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Is Empty?\n";
        cout << "6. Is Full?\n";
        cout << "7. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> value;
            q.enqueue(value);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.peek();
            break;

        case 4:
            q.display();
            break;

        case 5:
            if (q.isEmpty()) cout << "Queue is EMPTY.\n";
            else cout << "Queue is NOT empty.\n";
            break;

        case 6:
            if (q.isFull()) cout << "Queue is FULL.\n";
            else cout << "Queue is NOT full.\n";
            break;

        case 7:
            cout << "Exiting...\n";
            return 0;

        default:
            cout << "Invalid choice! Try again.\n";
        }
    }
}
