#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

vector<bool> visitados;

vector<vector<int>> matrizGrafoArestas;

// Função para realizar a busca em profundidade
void dfs(int vertice)
{
    visitados[vertice] = true; // Marcar o vértice como visitado
    cout << "Visitando vértice " << vertice << endl;

    // Iterar sobre todos os vértices adjacentes ao vértice atual
    for (int i = 0; i < matrizGrafoArestas.size(); ++i)
    {
        if (matrizGrafoArestas[vertice][i] && !visitados[i])
        {
            // Se existe uma aresta entre os vértices e o vértice adjacente não foi visitado
            dfs(i); // Visitar o vértice adjacente recursivamente
        }
    }
}

int main()
{
    int x; // x = teste
    cout << "quantidade de arestas -> ";
    cin >> x;

    visitados.reserve(x);          // Reserva espaço para visitados
    matrizGrafoArestas.reserve(x); // Reserva espaço para matrizGrafoArestas

    cin.ignore(); // Ignora o caractere de nova linha deixado pelo cin

    visitados.assign(x, false);

    for (int i = 0; i < x; i++)
    {
        cout << "digite as ligações da vertice " << i << " ";
        vector<int> arestas; // arestas;
        string input;

        int a;
        getline(cin, input); // Recebe a linha inteira

        // Cria um stringstream com a linha de entrada
        stringstream ss(input);

        while (ss >> a)
        { // Extrai inteiros da stringstream
            arestas.push_back(a);
        }
        matrizGrafoArestas.push_back(move(arestas)); // Usa move para evitar cópias desnecessárias
    }

    // Mostra a matriz
    int cont = 0;
    for (vector<int> row : matrizGrafoArestas)
    {
        cout << cont++ << " | ";
        for (int col : row)
        {
            cout << col << " ";
        }
        cout << endl;
    }

    // Iniciar a busca em profundidade a partir de todos os vértices não visitados
    int i;
    cout << "Digite o vertice que deseja iniciar a busca profunda ->";
    cin >> i;
    dfs(i);

    return 0;
}