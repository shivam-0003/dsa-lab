#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function prototypes
void insertAtBeginning(Node* &head, int value);
void insertAtEnd(Node* &head, int value);
void insertBefore(Node* &head, int key, int value);
void insertAfter(Node* &head, int key, int value);
void deleteFromBeginning(Node* &head);
void deleteFromEnd(Node* &head);
void deleteValue(Node* &head, int key);
int  search(Node* head, int key);
void display(Node* head);

int main() {
    Node* head = nullptr;
    int choice, value, key, posChoice;

    do {
        cout << "\n----- Singly Linked List Menu -----\n";
        cout << "1. Insertion at the beginning\n";
        cout << "2. Insertion at the end\n";
        cout << "3. Insertion before/after a specific node\n";
        cout << "4. Deletion from the beginning\n";
        cout << "5. Deletion from the end\n";
        cout << "6. Deletion of a specific node (by value)\n";
        cout << "7. Search for a node and display its position\n";
        cout << "8. Display all node values\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert at beginning: ";
            cin >> value;
            insertAtBeginning(head, value);
            break;

        case 2:
            cout << "Enter value to insert at end: ";
            cin >> value;
            insertAtEnd(head, value);
            break;

        case 3:
            cout << "Enter value of existing node (key): ";
            cin >> key;
            cout << "Enter new value to insert: ";
            cin >> value;
            cout << "1. Insert BEFORE " << key << endl;
            cout << "2. Insert AFTER " << key << endl;
            cout << "Enter your choice: ";
            cin >> posChoice;
            if (posChoice == 1)
                insertBefore(head, key, value);
            else if (posChoice == 2)
                insertAfter(head, key, value);
            else
                cout << "Invalid choice for before/after.\n";
            break;

        case 4:
            deleteFromBeginning(head);
            break;

        case 5:
            deleteFromEnd(head);
            break;

        case 6:
            cout << "Enter value of node to delete: ";
            cin >> key;
            deleteValue(head, key);
            break;

        case 7:
            cout << "Enter value to search: ";
            cin >> key;
            {
                int pos = search(head, key);
                if (pos == -1)
                    cout << "Node with value " << key << " not found.\n";
                else
                    cout << "Node with value " << key 
                         << " is at position " << pos << " from head.\n";
            }
            break;

        case 8:
            display(head);
            break;

        case 0:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 0);

    return 0;
}

// (a) Insertion at the beginning
void insertAtBeginning(Node* &head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    cout << "Inserted " << value << " at the beginning.\n";
}

// (b) Insertion at the end
void insertAtEnd(Node* &head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }
    cout << "Inserted " << value << " at the end.\n";
}

// (c) Insertion BEFORE a specific node (by value)
void insertBefore(Node* &head, int key, int value) {
    if (head == nullptr) {
        cout << "List is empty. Cannot insert before " << key << ".\n";
        return;
    }

    // If the key is at head
    if (head->data == key) {
        insertAtBeginning(head, value);
        return;
    }

    Node* prev = nullptr;
    Node* curr = head;

    while (curr != nullptr && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == nullptr) {
        cout << "Key " << key << " not found. Insertion failed.\n";
        return;
    }

    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = curr;
    prev->next = newNode;

    cout << "Inserted " << value << " before " << key << ".\n";
}

// (c) Insertion AFTER a specific node (by value)
void insertAfter(Node* &head, int key, int value) {
    Node* curr = head;

    while (curr != nullptr && curr->data != key)
        curr = curr->next;

    if (curr == nullptr) {
        cout << "Key " << key << " not found. Insertion failed.\n";
        return;
    }

    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = curr->next;
    curr->next = newNode;

    cout << "Inserted " << value << " after " << key << ".\n";
}

// (d) Deletion from the beginning
void deleteFromBeginning(Node* &head) {
    if (head == nullptr) {
        cout << "List is empty. Deletion not possible.\n";
        return;
    }

    Node* temp = head;
    head = head->next;
    cout << "Deleted node with value " << temp->data << " from beginning.\n";
    delete temp;
}

// (e) Deletion from the end
void deleteFromEnd(Node* &head) {
    if (head == nullptr) {
        cout << "List is empty. Deletion not possible.\n";
        return;
    }

    if (head->next == nullptr) {
        cout << "Deleted node with value " << head->data << " from end.\n";
        delete head;
        head = nullptr;
        return;
    }

    Node* prev = nullptr;
    Node* curr = head;

    while (curr->next != nullptr) {
        prev = curr;
        curr = curr->next;
    }

    cout << "Deleted node with value " << curr->data << " from end.\n";
    prev->next = nullptr;
    delete curr;
}

// (f) Deletion of a specific node (by value)
void deleteValue(Node* &head, int key) {
    if (head == nullptr) {
        cout << "List is empty. Deletion not possible.\n";
        return;
    }

    // If head is to be deleted
    if (head->data == key) {
        Node* temp = head;
        head = head->next;
        cout << "Deleted node with value " << key << ".\n";
        delete temp;
        return;
    }

    Node* prev = nullptr;
    Node* curr = head;

    while (curr != nullptr && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == nullptr) {
        cout << "Node with value " << key << " not found.\n";
        return;
    }

    prev->next = curr->next;
    cout << "Deleted node with value " << key << ".\n";
    delete curr;
}

// (g) Search for a node and return position (1-based)
int search(Node* head, int key) {
    int position = 1;
    Node* temp = head;

    while (temp != nullptr) {
        if (temp->data == key)
            return position;
        temp = temp->next;
        position++;
    }
    return -1; // Not found
}

// (h) Display all node values
void display(Node* head) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    cout << "Linked List: ";
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}
