#include <bits/stdc++.h>
using namespace std;

int main(){
    const int column=12;
    const int row=12;
    double matriz[column][row];
    
    string o;
    cin >> o;

    for(int i = 0; i <row; i++){

        for(int j = 0; j < column; j++){
            cin >> matriz[i][j]; //Preenchendo a matriz 
        }
    }
    //Realizando o calculo da soma
    double sum=0.0;
    int divisor=0;
    for (int r = 0; r < row; r++) {
        for (int c =  column - 1; c > r; c--) {
            sum += matriz[r][c];
            divisor++;
        }
    }
    //  Operação
    if (o == "S"){
    cout << fixed << setprecision(1) << sum <<endl;
    }
    
    if (o== "M"){
    const double media = sum /divisor;
    cout << fixed << setprecision(1) << media <<endl;
    }

    return 0;
}

/*  
    0 1 2 3 4 5 6 7 8 9 10 11 
   [0 X X X X X X X X X X X  ]
   [0 0 X X X X X X X X X X  ]
   [0 0 0 X X X X X X X X X  ]
   [0 0 0 0 X X X X X X X X  ]
   [0 0 0 0 0 X X X X X X X  ]
   [0 0 0 0 0 0 X X X X X X  ]
   [0 0 0 0 0 0 0 X X X X X  ]
   [0 0 0 0 0 0 0 0 X X X X  ]
   [0 0 0 0 0 0 0 0 0 X X X  ]
   [0 0 0 0 0 0 0 0 0 0 X X  ]
   [0 0 0 0 0 0 0 0 0 0 0 X  ] 
   [0 0 0 0 0 0 0 0 0 0 0 0  ]
 */