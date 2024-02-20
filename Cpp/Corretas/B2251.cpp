#include <iostream>
#include <cmath>

using namespace std;

//forma mais simples de se calcular a quantidade de movimentos na torre de Honoi
long long calcularMovimentos(int N) {
    return pow(2, N) - 1;
}

int main() {
    int N, testeQuanty = 0;

    while (cin >> N) {
        if (N == 0) {
            break;
        }

        testeQuanty++;
        cout << "Teste " << testeQuanty << endl;

        long long movimentos = calcularMovimentos(N);

        cout << movimentos << endl <<endl;
    }

    return 0;
}
