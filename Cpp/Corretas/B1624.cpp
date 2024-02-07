#include <iostream>
#include <vector>

using namespace std;

int calcularTotalRecursivo(vector<pair<int, int>> &produtos, int indice, int pesoPossivel)
{
    // Caso base: índice fora dos limites ou peso máximo atingido
    if (        indice == produtos.size() || pesoPossivel == 0)
        return 0;

    // Se o peso do produto for maior que o peso possível, não pode ser escolhido
    if (produtos[indice].second > pesoPossivel)
        return calcularTotalRecursivo(produtos, indice + 1, pesoPossivel);

    // Escolher o produto atual ou não escolher e comparar os resultados
    int escolherProduto = produtos[indice].first + calcularTotalRecursivo(produtos, indice + 1, pesoPossivel - produtos[indice].second);
    int naoEscolherProduto = calcularTotalRecursivo(produtos, indice + 1, pesoPossivel);

    // Retornar o máximo entre escolher e não escolher o produto atual
    return max(escolherProduto, naoEscolherProduto);
}

int calcularTotal(vector<pair<int, int>> &produtos, int pesoMaximo)
{
    return calcularTotalRecursivo(produtos, 0, pesoMaximo);
}

int main()
{
    int n;
    vector<pair<int, int>> l_preco_peso;

    while (cin >> n)
    {
        if (n == 0)
            break;
        // Recebe os valores da lista de preço e peso
        for (int j = 0; j < n; j++)
        {
            int p, P;
            cin >> p >> P;
            l_preco_peso.push_back(pair<int, int>(p, P));
        }

        // Calcular a quantidade que o Dr pode levar
        int m; // Peso total
        cin >> m;

        cout << calcularTotal(l_preco_peso, m) << endl;
        l_preco_peso.clear(); // Limpar o vetor a cada iteração
    }

    return 0;
}
