#include <iostream>
using namespace std;

void improvedSelectionSort(int arr[], int n) {
    int left = 0;
    int right = n - 1;

    while (left < right) {

        int minIndex = left;
        int maxIndex = left;

        // Find both min and max in current range
        for (int i = left; i <= right; i++) {
            if (arr[i] < arr[minIndex])
                minIndex = i;
            if (arr[i] > arr[maxIndex])
                maxIndex = i;
        }

        // Swap minimum with left position
        swap(arr[left], arr[minIndex]);

        // If max element was at left index,
        // after swapping it moves to minIndex
        if (maxIndex == left)
            maxIndex = minIndex;

        // Swap maximum with right position
        swap(arr[right], arr[maxIndex]);

        left++;
        right--;
    }
}

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    improvedSelectionSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
