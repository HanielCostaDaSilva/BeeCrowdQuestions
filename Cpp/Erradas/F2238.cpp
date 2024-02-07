#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    // Verificar se C é um múltiplo de A e se não é divisível por B ou D
    if (C % A == 0 && C % B != 0 && D % C != 0) {
        cout << C << endl;
        return 0;
    }

    long long n = C;
    int step = A / gcd(A, C);

    while (n <= A * C) {
        if (n % B != 0 && D % n != 0 && C % n == 0) {
            cout << n << endl;
            return 0;
        }
        n += step;
    }

    cout << -1 << endl;

    return 0;
}
