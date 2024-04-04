#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> planes(n + 1);

    for (int i = 1; i <= n; ++i) {
        cin >> planes[i];
    }

    for (int i = 1; i <= n; ++i) {
        int A = i;
        int B = planes[A];
        int C = planes[B];

        if (planes[C] == A) {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;

    return 0;
}
