#include <iostream>
#include <iomanip>
#include <map>
using namespace std;

int main() {
    int idasFeira, prodCadasQuant, quantProdCompra;
    map<string, float> dictPrecoProd;

    cin >> idasFeira;

    for (int i = 0; i < idasFeira; i++) {
        // Armazena no dicionário produto e seu preço
        cin >> prodCadasQuant;

        for (int j = 0; j < prodCadasQuant; j++) {
            string produto;
            float preco;

            cin >> produto >> preco;
            dictPrecoProd[produto] = preco;
        }

        // Conta o preço total dos produtos comprados
        cin >> quantProdCompra;

        float precoTotal = 0;

        for (int j = 0; j < quantProdCompra; j++) {  // Corrigido para quantProdCompra
            string produto;
            int quantidade;
            cin >> produto >> quantidade;
            precoTotal += quantidade * dictPrecoProd[produto];
        }

        cout << "R$ " << fixed << setprecision(2) << precoTotal << endl;

        dictPrecoProd.clear();
    }

    return 0;
}
