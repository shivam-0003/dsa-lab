#include<iostream>
using namespace std;

void reverse(int arr[], int size);
void display(int arr[], int size);
void displayMatrix(int matrix[3][3]);

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(int);

    cout << "Original 1D array: ";
    display(arr, size);
    reverse(arr, size);
    cout << "Reversed 1D array: ";
    display(arr, size);


    int arr1[3][3] = {
        {1, 2, 9},
        {3, 4, 11},
        {5, 6, 12}
    };

    int arr2[3][3] = {
        {0, 2, 8},
        {3, 4, 7},
        {5, 6, 9}
    };

    int arr3[3][3] = {0};

   
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            arr3[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                arr3[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }

    cout << "\nMatrix after multiplication:\n";
    displayMatrix(arr3);

   
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            swap(arr3[i][j], arr3[j][i]);
        }
    }

    cout << "\nMatrix after transposing:\n";
    displayMatrix(arr3);

    return 0;
}

void reverse(int arr[], int size) {
    int start = 0, end = size - 1;
    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void display(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void displayMatrix(int matrix[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}