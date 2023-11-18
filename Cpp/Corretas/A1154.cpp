#include <bits/stdc++.h>
#include <vector>
using namespace std;
 
int main() {
    vector<int> idades;
    int idade=0;
    double soma=0;
        cin >> idade;

    while (idade >=0){
        idades.push_back(idade);
        cin >> idade;
    }
    
    for (int valor : idades) {
    soma += valor;
    };
    if (size(idades)==0){
    idades.push_back(1);

    }
    cout << fixed << setprecision(2) << soma/ size(idades) << endl;
 
    return 0;
}