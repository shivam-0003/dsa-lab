#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

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

int findMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;         // move by 1
        fast = fast->next->next;   // move by 2
    }

    return slow->data; // slow is at the middle
}

int main() {
    Node* head = nullptr;

    // Input: 1->2->3->4->5
    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 3);
    head = insert(head, 4);
    head = insert(head, 5);

    cout << "Middle element: " << findMiddle(head) << endl;

    return 0;
}
