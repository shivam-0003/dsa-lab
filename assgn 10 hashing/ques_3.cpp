#include <iostream>
using namespace std;

int main() {
    int nums[] = {2, 3, 2, 4, 3, 2};
    int n = 6;
    bool counted[6] = {false};

    for (int i = 0; i < n; i++) {
        if (counted[i])
            continue;

        int count = 1;

        for (int j = i + 1; j < n; j++) {
            if (nums[i] == nums[j]) {
                count++;
                counted[j] = true;
            }
        }

        cout << nums[i] << " → " << count << " times" << endl;
    }

    return 0;
}
