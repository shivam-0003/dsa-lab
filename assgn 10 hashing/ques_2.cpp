#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
    vector<int> A = {1, 2, 3, 4};
    vector<int> B = {3, 4, 5, 6};

    unordered_set<int> setA;
    vector<int> common;

    for (int x : A) {
        setA.insert(x);
    }

    for (int y : B) {
        if (setA.find(y) != setA.end()) {
            common.push_back(y);
        }
    }

    for (int x : common) {
        cout << x << " ";
    }

    return 0;
}
