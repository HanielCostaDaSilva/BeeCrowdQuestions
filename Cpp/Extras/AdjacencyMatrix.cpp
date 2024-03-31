#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

//vector<bool> visitados;

vector<vector<int>> matrizGrafoArestas;


int main()
{
    int x; // x = teste
//    cout << "quantidade de arestas -> ";
    cin >> x;

    cin.ignore(); // Ignora o caractere de nova linha deixado pelo cin

//    visitados.assign(x, false);

    for (int i = 0; i < x; i++)
    {
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
        matrizGrafoArestas.push_back(arestas);
    }
   
   // Verifica as conexões da matriz

    for (vector<int> row : matrizGrafoArestas)
    {
        for (int i = 0; i < row.size(); i++)
        {
            if (row[i] == 1){
                cout << i+1<< " ";
            }
        }
        cout << endl;
    }

    return 0;
}