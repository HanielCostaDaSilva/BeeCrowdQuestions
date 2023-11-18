#include <bits/stdc++.h>
using namespace std;

int main() {
    int cedulasConvertidasMoedas[] = {10000, 5000, 2000, 1000, 500, 200};
    int moedas[] = {100, 50, 25, 10, 5, 1};

    float valortrocar;
    cin >> valortrocar;
    int valortrocarConvertidoMoeda = valortrocar * 100;
    
    // Calcula cédulas
    cout << "NOTAS:" << endl;
    for (int c = 0; c < size(cedulasConvertidasMoedas); c++) {
        int quantidadeCedula = valortrocarConvertidoMoeda / (cedulasConvertidasMoedas[c]);
        cout << quantidadeCedula << " nota(s) de R$ " << fixed << setprecision(2) << cedulasConvertidasMoedas[c] / 100.0 << endl;
        valortrocarConvertidoMoeda -= quantidadeCedula * cedulasConvertidasMoedas[c] ;
    }
    
    // Calcula moedas
    cout << "MOEDAS:" << endl;
    for (int c = 0; c < size(moedas); c++) {
        int quantidademoedas = valortrocarConvertidoMoeda / moedas[c];
        cout << quantidademoedas << " moeda(s) de R$ " << fixed << setprecision(2) << static_cast<float>(moedas[c] / 100.0) << endl;
        valortrocarConvertidoMoeda -= quantidademoedas * moedas[c];
    }

    return 0;
}