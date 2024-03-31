#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> tree; // Estrutura da árvore (lista de adjacência)
vector<int> ans;          // Número de subordinados de cada funcionário

// Função recursiva para calcular o número de subordinados de cada funcionário
void countSubordinates(int src, int par)
{
    int subords = 0;
    for (int child : tree[src])
    {
        if (child != par)
        {                                  // Verifica se o filho não é o pai para evitar ciclos na árvore
            countSubordinates(child, src); // Chamada recursiva para calcular o número de subordinados do filho
            subords += (1 + ans[child]);   
        }
    }
    ans[src] = subords; // Atualiza o número de subordinados do funcionário 'src'
}

int main()
{
    int n;
    cin >> n; // Lê o número de funcionários

    // Redimensiona as estruturas para o tamanho adequado
    tree.resize(n + 1); 
    ans.resize(n + 1);  

    // Constrói a estrutura da árvore
    for (int i = 2; i <= n; ++i)
    { // Começa do segundo funcionário, já que o primeiro é o diretor geral
        int x;
        cin >> x;             // Lê o chefe do funcionário 'i'
        tree[x].push_back(i); // Adiciona 'i' como subordinado do funcionário 'x'
        tree[i].push_back(x); // Adiciona 'x' como chefe do funcionário 'i'
    }

    // Calcula o número de subordinados para cada funcionário, começando pelo diretor geral (funcionário 1)
    countSubordinates(1, 0);

    for (int i = 1; i <= n; ++i)
        cout << ans[i] << ' ';

    return 0;
}
