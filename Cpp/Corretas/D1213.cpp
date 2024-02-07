#include <iostream>
#include <unordered_set>

using namespace std;

int findMinimumMultiple(int n) {
    unordered_set<int> memory;
    int multiple = 1;
    int digits = 1;

    while (true) {
        if (memory.find(multiple % n) != memory.end()) {
            break;
        }

        memory.insert(multiple % n);

        if (multiple % n == 0) {
            break;
        }

        digits++;
        multiple = (multiple * 10 + 1) % n;
    }

    return digits;
}

int main() {
    int n;

    while (cin >> n) {
        int result = findMinimumMultiple(n);
        cout << result << endl;
    }

    return 0;
}
