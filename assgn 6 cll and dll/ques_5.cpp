#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    
    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Function to check if linked list is circular
bool isCircular(Node* head) {
    if (head == NULL) 
        return true;  // Empty list is considered circular

    Node* temp = head->next;

    // Traverse until we either reach head again or reach NULL
    while (temp != NULL && temp != head) {
        temp = temp->next;
    }

    // If we reached back to head → circular
    return (temp == head);
}

// Driver Code
int main() {
    // Creating the linked list: 2 -> 4 -> 6 -> 7 -> 5
    Node* head = new Node(2);
    head->next = new Node(4);
    head->next->next = new Node(6);
    head->next->next->next = new Node(7);
    head->next->next->next->next = new Node(5);

    // Making it circular
    head->next->next->next->next->next = head;

    if (isCircular(head))
        cout << "True";
    else
        cout << "False";

    return 0;
}
