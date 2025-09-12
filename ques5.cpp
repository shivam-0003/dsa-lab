#include<iostream>
using namespace std;

int main() {
    int arr1[3][2] = {
        {1, 2},
        {3, 4},
        {5, 6}
    };

    int rows = 3;
    int cols = 2;

  
    for(int i = 0; i < rows; i++) {
        int rowSum = 0;
        for(int j = 0; j < cols; j++) {
            rowSum += arr1[i][j];
        }
        cout << "Sum of row " << i << ": " << rowSum << endl;
    }

   
    for(int j = 0; j < cols; j++) {
        int colSum = 0;
        for(int i = 0; i < rows; i++) {
            colSum += arr1[i][j];
        }
        cout << "Sum of column " << j << ": " << colSum << endl;
    }

    return 0;
}
