#include <iostream>
#include <vector>

using namespace std;

void processInput() {
    int n;
    cin >> n;
    vector<int> array(n);
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    vector<int> uniqueArray;
    for (int x : array) {
        if (uniqueArray.empty() || uniqueArray.back() != x) {
            uniqueArray.push_back(x);
        }
    }
    int count = 0;
    for (int i = 0; i < uniqueArray.size(); i++) {
        if ((i == 0 || uniqueArray[i] < uniqueArray[i - 1]) && (i == uniqueArray.size() - 1 || uniqueArray[i] < uniqueArray[i + 1])) {
            count++;
        }
    }
    cout << (count == 1 ? "YES" : "NO") << endl;
}

int main() {
    int numberOfTestCases;
    cin >> numberOfTestCases;
    for (int i = 0; i < numberOfTestCases; i++) {
        processInput();
    }
    return 0;
}