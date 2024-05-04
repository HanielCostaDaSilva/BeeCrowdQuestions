#include <iostream>
#include <vector>

using namespace std;

int maxNumberOfPages(vector<int> &precoLivros, vector<int> &quantPaginas, int precoMaximo)
{
    int N = precoLivros.size();

    vector<int> dp(precoMaximo + 1, 0);

    // Percorremos o array de precoLivros e atualizamos o DP conforme possível

    for (int i = 0; i < N; i++)
    {
        for (int preco = precoMaximo; preco >= precoLivros[i]; preco--)
        {
            dp[preco] = max(dp[preco], dp[preco - precoLivros[i]] + quantPaginas[i]);
        }
    }

    // Retorna o máximo de páginas que conseguimos comprar com o preço máximo dado
    return dp[precoMaximo];
}

int main()
{
    int n, x; // Número de livros / o preço máximo total dos livros

    cin >> n >> x;

    vector<int> precoLivros(n), paginasTotalCadaLivro(n); // preço de cada livro / quantidade de páginas de cada livro

    // Preechendo o vetor com o preco de cada livro
    for (int i = 0; i < n; i++)
    {
        cin >> precoLivros[i];
    }

    // Preechendo o vetor com a quantidade de páginas de cada livro
    for (int i = 0; i < n; i++)
    {
        cin >> paginasTotalCadaLivro[i];
    }

    int result = maxNumberOfPages(precoLivros, paginasTotalCadaLivro, x);
    cout << result << endl;

    return 0;
}
