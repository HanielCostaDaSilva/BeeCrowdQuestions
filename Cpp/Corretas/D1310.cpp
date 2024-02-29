#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;

    while (cin >> N) {


        int custoPorDia;
        cin >> custoPorDia;

        vector<int> receita(N);
        for (int i = 0; i < N; ++i) {
            cin >> receita[i];
        }

        int maxLucro = 0;

        for (int inicio = 0; inicio < N; ++inicio) {
            for (int fim = inicio; fim < N; ++fim) {
                int lucroAtual = 0;

                // Calcular o lucro para a série de dias atual
                for (int i = inicio; i <= fim; ++i) {
                    lucroAtual += receita[i];
                }

                lucroAtual -= custoPorDia * (fim - inicio + 1);

                maxLucro = max(maxLucro, lucroAtual);
            }
        }

        cout << maxLucro << endl;
    }

    return 0;
}
