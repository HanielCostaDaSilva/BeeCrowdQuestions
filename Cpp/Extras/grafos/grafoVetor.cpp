#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

// Estrutura para representar um vértice e sua lista de adjacência
struct Vertice
{
    int valor;
    vector<int> adjacencias; // Lista de vértices adjacentes
};

class Grafo
{
private:
    vector<Vertice> vertices;

public:
    // Adicionar um novo vértice ao grafo
    void adicionarVertice(int valor)
    {
        Vertice novoVertice;
        novoVertice.valor = valor;
        vertices.push_back(novoVertice);
    }

    // Adicionar uma aresta direcionada do vértice 'de' para o vértice 'para'
    void adicionarAresta(int de, int para)
    {
        vertices[de].adjacencias.push_back(para);
    }

    // Imprimir o grafo
    void imprimirGrafo()
    {
        for (int i = 0; i < vertices.size(); ++i)
        {
            cout << "Vértice " << vertices[i].valor << " --> ";
            for (int j = 0; j < vertices[i].adjacencias.size(); ++j)
            {
                cout << vertices[i].adjacencias[j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Grafo grafo;

    int quantVert;
    cin >> quantVert;
    cin.ignore(); // Descartar o caractere de nova linha

    // Adicionando vértices
    for (int i = 0; i < quantVert; ++i)
    {
        grafo.adicionarVertice(i);
    }

    // Adicionando arestas
    for (int i = 0; i < quantVert; ++i)
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
            grafo.adicionarAresta(i, a);
        }
    }

    // Imprimir o grafo
    cout << "Lista de Adjacência do Grafo:" << endl;
    grafo.imprimirGrafo();

    return 0;
}
