#include <iostream>
using namespace std;

// -------------------------
// Doubly Linked List Node
// -------------------------
struct DNode {
    int data;
    DNode* prev;
    DNode* next;
};

// Function to get size of Doubly Linked List
int getSizeDoubly(DNode* head) {
    int count = 0;
    DNode* temp = head;

    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

// -------------------------
// Circular Linked List Node
// -------------------------
struct CNode {
    int data;
    CNode* next;
};

// Function to get size of Circular Linked List
int getSizeCircular(CNode* head) {
    if (head == nullptr)
        return 0;

    int count = 1;
    CNode* temp = head->next;

    while (temp != head) {
        count++;
        temp = temp->next;
    }
    return count;
}

// -------------------------
// Main Function
// -------------------------
int main() {

    // ----- Doubly Linked List Example -----
    DNode* d1 = new DNode{10, nullptr, nullptr};
    DNode* d2 = new DNode{20, d1, nullptr};
    DNode* d3 = new DNode{30, d2, nullptr};
    d1->next = d2;
    d2->next = d3;

    cout << "Size of Doubly Linked List = " << getSizeDoubly(d1) << endl;


    // ----- Circular Linked List Example -----
    CNode* c1 = new CNode{5, nullptr};
    CNode* c2 = new CNode{15, nullptr};
    CNode* c3 = new CNode{25, nullptr};

    c1->next = c2;
    c2->next = c3;
    c3->next = c1;   // make it circular

    cout << "Size of Circular Linked List = " << getSizeCircular(c1) << endl;

    return 0;
}
