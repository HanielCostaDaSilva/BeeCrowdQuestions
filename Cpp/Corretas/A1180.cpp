#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main()
{
    int flag;
    cin >> flag;

    vector<int> valores;

    string entrada;
    cin.ignore();
    getline(cin, entrada);

    istringstream tokenizer(entrada);

    int valor;

    while (tokenizer >> valor)
    {
        valores.push_back(valor);
    }

    int menorvalor = valores[0];
    int posicaoMenor = 0;

    for (int i = 1; i < flag; i++)
    {
        if (valores[i] < menorvalor)
        {
            menorvalor = valores[i];
            posicaoMenor = i;
        }
    }

    cout << "Menor valor: " << menorvalor << endl;
    cout << "Posicao: " << posicaoMenor << endl;

    return 0;
}
