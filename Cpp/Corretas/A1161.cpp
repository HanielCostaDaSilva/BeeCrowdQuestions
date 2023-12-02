#include <iostream>
#include <cmath>

using namespace std;
int main() {
    int M, N;

    while (cin >> M >> N) {
        long long int factorialM = 1;
        long long int factorialN = 1;

        for (int i = 1; i <= M; ++i) {
            factorialM *= i;
        }

        for (int i = 1; i <= N; ++i) {
            factorialN *= i;
        }

        cout << factorialM + factorialN << endl;
    }

    return 0;
}