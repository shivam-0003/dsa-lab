#include <iostream>
#include <unordered_set>
using namespace std;

// Structure of a tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Function to check duplicates using DFS
bool containsDuplicate(Node* root, unordered_set<int>& seen) {
    if (root == nullptr)
        return false;

    // If value already exists → duplicate found
    if (seen.count(root->data))
        return true;

    // Insert value into the hash set
    seen.insert(root->data);

    // Check left and right subtrees
    return containsDuplicate(root->left, seen) ||
           containsDuplicate(root->right, seen);
}

int main() {
    // Example tree
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(20); // Duplicate value

    unordered_set<int> seen;

    if (containsDuplicate(root, seen))
        cout << "Duplicates Found\n";
    else
        cout << "No Duplicates\n";

    return 0;
}
