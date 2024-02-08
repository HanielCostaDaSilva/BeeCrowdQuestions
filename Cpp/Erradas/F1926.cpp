#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Gerar números primos usando a peneira de Eratóstenes
vector<int> generatePrimes(int n) {
    vector<bool> isPrime(n + 1, true);
    vector<int> primes;

    for (int p = 2; p * p <= n; p++) {
        if (isPrime[p]) {
            for (int i = p * p; i <= n; i += p) {
                isPrime[i] = false;
            }
        }
    }

    for (int p = 2; p <= n; p++) {
        if (isPrime[p]) {
            primes.push_back(p);
        }
    }

    return primes;
}

// Função para contar os primos gêmeos no intervalo [X, Y]
int countTwinPrimes(int X, int Y) {
    vector<int> primes = generatePrimes(max(X, Y));

    int count = 0;
    for (size_t i = 0; i < primes.size() - 1; i++) {
        if (primes[i] >= min(X, Y) && primes[i + 1] <= max(X, Y) && primes[i + 1] - primes[i] == 2) {
            count++;
        }
    }

    return count;
}

int main() {
    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++) {
        int X, Y;
        cin >> X >> Y;

        int counterTwinPrimes = countTwinPrimes(X, Y);
        cout << counterTwinPrimes << endl;
    }

    return 0;
}
