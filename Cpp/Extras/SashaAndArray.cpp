#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int tamanho;
        cin >> tamanho;

        vector<int> array(tamanho);
        // Preenchimento do vetor

        for (int i = 0; i < tamanho; i++)
        {
            cin >> array[i];
        }

        sort(array.begin(), array.end());

        // Cálculo do custo máximo
        int custo_maximo = 0;

        for (int i = 0; i < tamanho / 2; i++)
        {
            custo_maximo += array[tamanho - 1 - i] - array[i];
        }

        cout << custo_maximo << endl;
    }

    return 0;
}
