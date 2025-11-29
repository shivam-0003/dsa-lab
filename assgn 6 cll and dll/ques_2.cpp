#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to display values including repeating head at end
void displayCircular(Node* head) {
    if (head == NULL) {
        cout << "List is empty";
        return;
    }

    Node* temp = head;

    // Traverse until just before head reappears
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    // Print the head again
    cout << head->data;
}

int main() {
    // Creating circular linked list: 20 → 100 → 40 → 80 → 60 → back to 20
    Node* head = new Node{20, NULL};
    Node* second = new Node{100, NULL};
    Node* third = new Node{40, NULL};
    Node* fourth = new Node{80, NULL};
    Node* fifth = new Node{60, NULL};

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = head; // circular link

    cout << "Output: ";
    displayCircular(head);

    return 0;
}
