#include <iostream>
using namespace std;

int main() {
    int arr[] = {4, 5, 1, 2, 0, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    bool isRepeating;

    for (int i = 0; i < n; i++) {
        isRepeating = false;

        // Check if arr[i] repeats
        for (int j = 0; j < n; j++) {
            if (i != j && arr[i] == arr[j]) {
                isRepeating = true;
                break;
            }
        }

        // If not repeating → first non-repeating element
        if (!isRepeating) {
            cout << arr[i];
            return 0;
        }
    }

    cout << "No non-repeating element";
    return 0;
}
