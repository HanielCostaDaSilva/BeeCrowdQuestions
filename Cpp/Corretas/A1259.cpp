#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void mostrarValores(vector<int> lista)
{
    int posicaoInicial= 0;
    const int posicaoFinal= lista.size();

    while (posicaoInicial < posicaoFinal)
    {
        cout << lista[posicaoInicial] << endl;
        posicaoInicial++;
    }
}

int main(){
    vector<int> pares, impares;
    
    int valor, flag;
    cin >>flag;

    for(int i=0; i<flag; i++){
        cin >>valor;

        valor % 2 ==0 ? pares.push_back(valor) : impares.push_back(valor);
    }

    //Ordem crescente
    sort(pares.begin(), pares.end() );
    sort(impares.begin(), impares.end(),greater<int>());   
    
    // Mostrando
    mostrarValores(pares);
    mostrarValores(impares);
    
    return 0;
}