#include <bits/stdc++.h>
using namespace std;

int main() {
    float soma=1.0;
    
    for(float i=2; i<101; i++){
    soma+= 1/i;
    }
    cout <<fixed << setprecision(2) << soma << endl;
    return 0;
}