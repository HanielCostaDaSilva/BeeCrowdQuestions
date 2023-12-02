#include <bits/stdc++.h>
using namespace std;

int main() {
    int quantidadeElemento;
    cin >>  quantidadeElemento;
    int sequenciaFirb[quantidadeElemento];
    
    sequenciaFirb[0]=0;
    sequenciaFirb[1]=1;

    for (int i=2; i<quantidadeElemento; i++) {
        sequenciaFirb[i]=  sequenciaFirb[i-1] + sequenciaFirb[i-2];
    }

    for (int j=0; j<quantidadeElemento; j++) {
        cout << sequenciaFirb[j];
        if (j+1 == quantidadeElemento)
        continue;
        cout <<" ";
    }
    cout << endl;
    return 0;
}