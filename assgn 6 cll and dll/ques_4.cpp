#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* prev;
    Node* next;

    Node(char ch) {
        data = ch;
        prev = nullptr;
        next = nullptr;
    }
};

// Insert node at end of DLL
void insertEnd(Node* &head, Node* &tail, char ch) {
    Node* newNode = new Node(ch);
    if (head == nullptr) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

// Check palindrome
bool isPalindrome(Node* head, Node* tail) {
    while (head != nullptr && tail != nullptr && head != tail && head->prev != tail) {
        if (head->data != tail->data)
            return false;

        head = head->next;
        tail = tail->prev;
    }
    return true;
}

int main() {
    char s[100];
    cout << "Enter a string (no spaces): ";
    cin >> s;

    Node* head = nullptr;
    Node* tail = nullptr;

    // Build DLL
    for (int i = 0; s[i] != '\0'; i++) {
        insertEnd(head, tail, s[i]);
    }

    if (isPalindrome(head, tail))
        cout << "The doubly linked list is a palindrome.\n";
    else
        cout << "The doubly linked list is NOT a palindrome.\n";

    return 0;
}
