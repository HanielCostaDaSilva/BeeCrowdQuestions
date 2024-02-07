#include <iostream>

using namespace std;

// Algoritmo de Euclides
int mdcEuclides(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int f1, f2;
        cin >> f1 >> f2;

        // Calcula o mdc para encontrar o tamanho máximo da pilha de figurinhas
        int tamanhoMaximoPilha = mdcEuclides(f1, f2);

        cout << tamanhoMaximoPilha << endl;
    }

    return 0;
}
