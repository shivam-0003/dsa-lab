#include <iostream>
using namespace std;

class Stack {
public:
    int top;
    char arr[100];

    Stack() { top = -1; }

    void push(char c) {
        arr[++top] = c;
    }

    char pop() {
        return arr[top--];
    }

    bool isEmpty() {
        return top == -1;
    }
};

int main() {
    string s = "DataStructure";
    Stack st;

    // Push characters
    for (char c : s) {
        st.push(c);
    }

    // Pop characters
    string reversed = "";
    while (!st.isEmpty()) {
        reversed += st.pop();
    }

    cout << "Reversed string: " << reversed << endl;

    return 0;
}
