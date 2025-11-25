#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertAtEnd(Node* &head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
}

int deleteAllOccurrences(Node* &head, int key) {
    int count = 0;

    while (head != nullptr && head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        count++;
    }

    if (head == nullptr)
        return count;

    Node* curr = head;
    Node* prev = nullptr;

    while (curr != nullptr) {
        if (curr->data == key) {
            Node* temp = curr;
            prev->next = curr->next;
            curr = curr->next;
            delete temp;
            count++;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }

    return count;
}

void display(Node* head) {
    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = nullptr;

    int arr[] = {1, 2, 1, 2, 1, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++)
        insertAtEnd(head, arr[i]);

    int key = 1;

    cout << "Original List: ";
    display(head);

    int count = deleteAllOccurrences(head, key);

    cout << "Count: " << count << endl;
    cout << "Updated List: ";
    display(head);

    return 0;
}
