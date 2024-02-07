#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int calcularMaiorValorRecursivo(vector<pair<int, int>> &canos, int tamanhoCano, unordered_map<int, int> &memo) {
    if (tamanhoCano == 0) {
        return 0;
    }

    // Verificar se o resultado para o tamanhoCano já foi calculado anteriormente
    if (memo.find(tamanhoCano) != memo.end()) {
        return memo[tamanhoCano];
    }

    int maximoValor = 0;
    
    for (auto cano : canos) {
        if (cano.first <= tamanhoCano) {
            int valorAtual = cano.second + calcularMaiorValorRecursivo(canos, tamanhoCano - cano.first, memo);
            maximoValor = max(maximoValor, valorAtual);
        }
    }

    memo[tamanhoCano] = maximoValor;

    return maximoValor;
}

int main() {
    int quantidadeCanos, tamanhoCano;

    while (cin >> quantidadeCanos >> tamanhoCano) {
        vector<pair<int, int>> canos(quantidadeCanos);

        for (int i = 0; i < quantidadeCanos; i++) {
            cin >> canos[i].first >> canos[i].second;
        }

        unordered_map<int, int> memo;  

        int resultado = calcularMaiorValorRecursivo(canos, tamanhoCano, memo);

        cout << resultado << endl;
    }

    return 0;
}
