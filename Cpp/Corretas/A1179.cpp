#include <vector>
#include <iostream>
using namespace std;

void mostrarValores(vector<int> lista, string tipo)
{
    int posicaoInicial= 0;
    const int posicaoFinal= lista.size();

    while (posicaoInicial < posicaoFinal)
    {
        cout << tipo << "[" << posicaoInicial << "]"
             << " = " << lista[posicaoInicial] << endl;
        posicaoInicial++;
    }
}

int main()
{
    vector<int> pares, impares;
    const int flag = 15;

    const int tamanhoVector=5;

    // incersão de valores
    for (int i = 0; i < flag; i++)
    {
        int valor;

        cin >> valor;

        if (valor % 2 == 0)
        {
            pares.push_back(valor);

            if (pares.size() == tamanhoVector)
            {
                mostrarValores(pares, "par");
                pares.clear();
            }
        }
        else
        {
            impares.push_back(valor);
              if (impares.size() == tamanhoVector)
            {
                mostrarValores(impares, "impar");
                impares.clear();
            }
        }
    }

    if (!impares.empty())
    {
        mostrarValores(impares, "impar");
    }
    if (!pares.empty())
    {
        mostrarValores(pares, "par");
    }

    return 0;
}