#include <iostream>
using namespace std;

/* ------------ DOUBLY LINKED LIST ------------ */

struct DNode {
    int data;
    DNode *prev;
    DNode *next;
};

DNode* createDNode(int val) {
    DNode *newNode = new DNode;
    if (!newNode) {
        cout << "Memory allocation failed!" << endl;
        exit(1);
    }
    newNode->data = val;
    newNode->prev = newNode->next = nullptr;
    return newNode;
}

void insertDAtBeginning(DNode* &head, int val) {
    DNode *newNode = createDNode(val);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void insertDAtEnd(DNode* &head, int val) {
    DNode *newNode = createDNode(val);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    DNode *temp = head;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

void insertDAfter(DNode *head, int key, int val) {
    DNode *temp = head;
    while (temp && temp->data != key)
        temp = temp->next;
    if (!temp) {
        cout << "Key " << key << " not found." << endl;
        return;
    }
    DNode *newNode = createDNode(val);
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next)
        temp->next->prev = newNode;
    temp->next = newNode;
}

void insertDBefore(DNode* &head, int key, int val) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    if (head->data == key) {
        insertDAtBeginning(head, val);
        return;
    }
    DNode *temp = head;
    while (temp && temp->data != key)
        temp = temp->next;
    if (!temp) {
        cout << "Key " << key << " not found." << endl;
        return;
    }
    DNode *newNode = createDNode(val);
    DNode *prevNode = temp->prev;
    newNode->next = temp;
    newNode->prev = prevNode;
    prevNode->next = newNode;
    temp->prev = newNode;
}

void deleteDNode(DNode* &head, int key) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    DNode *temp = head;
    while (temp && temp->data != key)
        temp = temp->next;
    if (!temp) {
        cout << "Node with value " << key << " not found." << endl;
        return;
    }
    if (temp == head) { 
        head = temp->next;
        if (head)
            head->prev = nullptr;
    } else {
        temp->prev->next = temp->next;
        if (temp->next)
            temp->next->prev = temp->prev;
    }
    cout << "Deleted node with value " << key << endl;
    delete temp;
}

void searchDNode(DNode *head, int key) {
    int pos = 1;
    while (head) {
        if (head->data == key) {
            cout << "Node " << key << " found at position " << pos << "." << endl;
            return;
        }
        head = head->next;
        pos++;
    }
    cout << "Node " << key << " not found in the list." << endl;
}

void displayDList(DNode *head) {
    if (!head) {
        cout << "List is empty." << endl;
        return;
    }
    cout << "Doubly Linked List: ";
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

/* ------------ CIRCULAR LINKED LIST ------------ */

struct CNode {
    int data;
    CNode *next;
};

CNode* createCNode(int val) {
    CNode *newNode = new CNode;
    newNode->data = val;
    newNode->next = nullptr;
    return newNode;
}

void insertCAtBeginning(CNode* &head, int val) {
    CNode *newNode = createCNode(val);
    if (head == nullptr) {
        newNode->next = newNode;
        head = newNode;
        return;
    }
    CNode *temp = head;
    while (temp->next != head)
        temp = temp->next;
    temp->next = newNode;
    newNode->next = head;
    head = newNode;
}

void insertCAtEnd(CNode* &head, int val) {
    CNode *newNode = createCNode(val);
    if (head == nullptr) {
        newNode->next = newNode;
        head = newNode;
        return;
    }
    CNode *temp = head;
    while (temp->next != head)
        temp = temp->next;
    temp->next = newNode;
    newNode->next = head;
}

void insertCAfter(CNode *head, int key, int val) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    CNode *temp = head;
    do {
        if (temp->data == key) {
            CNode *newNode = createCNode(val);
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    } while (temp != head);
    cout << "Key " << key << " not found." << endl;
}

void insertCBefore(CNode* &head, int key, int val) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    if (head->data == key) {
        insertCAtBeginning(head, val);
        return;
    }
    CNode *temp = head, *prev = nullptr;
    do {
        prev = temp;
        temp = temp->next;
        if (temp->data == key) {
            CNode *newNode = createCNode(val);
            newNode->next = temp;
            prev->next = newNode;
            return;
        }
    } while (temp != head);
    cout << "Key " << key << " not found." << endl;
}

void deleteCNode(CNode* &head, int key) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    CNode *curr = head, *prev = nullptr;

    if (curr->data == key && curr->next == head) {
        head = nullptr;
        delete curr;
        cout << "Deleted node with value " << key << endl;
        return;
    }

    if (curr->data == key) {
        CNode *last = head;
        while (last->next != head)
            last = last->next;
        last->next = curr->next;
        head = curr->next;
        delete curr;
        cout << "Deleted node with value " << key << endl;
        return;
    }

    do {
        prev = curr;
        curr = curr->next;
        if (curr->data == key) {
            prev->next = curr->next;
            delete curr;
            cout << "Deleted node with value " << key << endl;
            return;
        }
    } while (curr != head);

    cout << "Node with value " << key << " not found." << endl;
}

void searchCNode(CNode *head, int key) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    int pos = 1;
    CNode *temp = head;
    do {
        if (temp->data == key) {
            cout << "Node " << key << " found at position " << pos << "." << endl;
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);
    cout << "Node " << key << " not found in the list." << endl;
}

void displayCList(CNode *head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    cout << "Circular Linked List: ";
    CNode *temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

/* ------------ MENUS ------------ */

void doublyMenu() {
    DNode *head = nullptr;
    int choice, val, key;

    do {
        cout << "\n--- Doubly Linked List Menu ---\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert after a specific node\n";
        cout << "4. Insert before a specific node\n";
        cout << "5. Delete a node by value\n";
        cout << "6. Search for a node\n";
        cout << "7. Display list\n";
        cout << "0. Back to main menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: cout << "Enter value: "; cin >> val; insertDAtBeginning(head, val); break;
        case 2: cout << "Enter value: "; cin >> val; insertDAtEnd(head, val); break;
        case 3: cout << "Key: "; cin >> key; cout << "Value: "; cin >> val; insertDAfter(head, key, val); break;
        case 4: cout << "Key: "; cin >> key; cout << "Value: "; cin >> val; insertDBefore(head, key, val); break;
        case 5: cout << "Delete value: "; cin >> key; deleteDNode(head, key); break;
        case 6: cout << "Search value: "; cin >> key; searchDNode(head, key); break;
        case 7: displayDList(head); break;
        case 0: break;
        default: cout << "Invalid choice\n"; 
        }
    } while (choice != 0);
}

void circularMenu() {
    CNode *head = nullptr;
    int choice, val, key;

    do {
        cout << "\n--- Circular Linked List Menu ---\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert after a specific node\n";
        cout << "4. Insert before a specific node\n";
        cout << "5. Delete a node by value\n";
        cout << "6. Search for a node\n";
        cout << "7. Display list\n";
        cout << "0. Back to main menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: cout << "Enter value: "; cin >> val; insertCAtBeginning(head, val); break;
        case 2: cout << "Enter value: "; cin >> val; insertCAtEnd(head, val); break;
        case 3: cout << "Key: "; cin >> key; cout << "Value: "; cin >> val; insertCAfter(head, key, val); break;
        case 4: cout << "Key: "; cin >> key; cout << "Value: "; cin >> val; insertCBefore(head, key, val); break;
        case 5: cout << "Delete value: "; cin >> key; deleteCNode(head, key); break;
        case 6: cout << "Search value: "; cin >> key; searchCNode(head, key); break;
        case 7: displayCList(head); break;
        case 0: break;
        default: cout << "Invalid choice\n";
        }
    } while (choice != 0);
}

/* ------------ MAIN FUNCTION ------------ */

int main() {
    int choice;
    do {
        cout << "\n========== MAIN MENU ==========\n";
        cout << "1. Work with Doubly Linked List\n";
        cout << "2. Work with Circular Linked List\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: doublyMenu(); break;
        case 2: circularMenu(); break;
        case 0: cout << "Exiting...\n"; break;
        default: cout << "Invalid choice\n";
        }
    } while (choice != 0);

    return 0;
}
