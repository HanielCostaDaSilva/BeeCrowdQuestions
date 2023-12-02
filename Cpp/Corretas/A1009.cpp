#include <bits/stdc++.h>
using namespace std;

int main()
{
    string nome;
    double salarioFixo;
    double montanteVendas;

    const double porcentagemComissao = 15;

    cin >> nome;
    cin >> salarioFixo;
    cin >> montanteVendas;

    const double comissao = (porcentagemComissao / 100) * montanteVendas;
    const double salarioReal = salarioFixo + comissao;

    cout << "TOTAL = R$ " << fixed << setprecision(2) << salarioReal << endl;
    return 0;
}