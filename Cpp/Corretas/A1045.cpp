#include <bits/stdc++.h>
using namespace std;

int main()
{
    float lados[3]; // lado[0]=a lado[1]=b lado[2]=c;

    cin >> lados[0] >> lados[1] >> lados[2];

    int tamanhoArrLados = sizeof(lados) / sizeof(lados[0]);

    sort(lados, lados + tamanhoArrLados, greater<float>());

    if (lados[0] >= lados[1] + lados[2])
    {
        cout << "NAO FORMA TRIANGULO" << endl;
    }
    else
    {
        if (pow(lados[0], 2) == pow(lados[1], 2) + pow(lados[2], 2))
        {
            cout << "TRIANGULO RETANGULO" << endl;
        }
        else if (pow(lados[0], 2) > pow(lados[1], 2) + pow(lados[2], 2))
        {
            cout << "TRIANGULO OBTUSANGULO" << endl;
        }
        else
        {
            cout << "TRIANGULO ACUTANGULO" << endl;
        }
        if (lados[0] == lados[1] && lados[1] == lados[2])
        {
            cout << "TRIANGULO EQUILATERO" << endl;
        }
        else if ((lados[0] == lados[1] || lados[1] == lados[2] || lados[2] == lados[0]))
        {
            cout << "TRIANGULO ISOSCELES" << endl;
        }
    }

    return 0;
}
