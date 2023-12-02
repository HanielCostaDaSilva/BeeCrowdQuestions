#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
    int alturaSalto, quantCanos;
    cin >> alturaSalto >> quantCanos;

    vector<int> alturaCanos;

    string entrada;
    cin.ignore();
    getline(cin, entrada);

    istringstream tokenizer(entrada);

    int canoAltura;

    while (tokenizer >> canoAltura)
    {
        alturaCanos.push_back(canoAltura);
    }

    bool vencedor = true;

    for (int canoPosicao = 1; canoPosicao < alturaCanos.size(); canoPosicao++)
    {
        if (abs(alturaCanos[canoPosicao] - alturaCanos[canoPosicao - 1]) > alturaSalto)
        {
            vencedor = !vencedor;
            break;
        }
    }

    if (vencedor)
    {
        cout << "YOU WIN" << endl;
    }
    else
    {
        cout << "GAME OVER" << endl;
    }

    return 0;
}
