#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Insert at end (for building list)
Node* insert(Node* head, int data) {
    Node* newNode = new Node{data, nullptr};

    if (head == nullptr)
        return newNode;

    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Reverse Linked List
Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;

    while (curr != nullptr) {
        next = curr->next;   // store next node
        curr->next = prev;   // reverse the link
        prev = curr;         // move prev forward
        curr = next;         // move curr forward
    }

    return prev; 
}

void display(Node* head) {
    while (head != nullptr) {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = nullptr;

    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 3);
    head = insert(head, 4);

    cout << "Original List: ";
    display(head);

    head = reverseList(head);

    cout << "Reversed List: ";
    display(head);

    return 0;
}
