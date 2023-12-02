#include <bits/stdc++.h>
using namespace std;

int main()
{
    int limitesInt[2],soma;
    
    while(true){
    cin >> limitesInt[1] >> limitesInt[0];
    sort(limitesInt, limitesInt + 2);

    if(limitesInt[0] <=0)
        break;
    
    soma=0;
    
    for (int somando = limitesInt[0]; somando < limitesInt[1] + 1; somando++){
        cout << somando <<" ";
        soma+=somando;
    }
    cout << "Sum="<<soma<<endl;
    }
    return 0;
}