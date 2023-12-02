#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
        int N;
    while (true)
    {
            cin >> N;
        if (N == 0)
        {
                break;
     }
        vector<vector<int>> matriz(N, vector<int>(N, 1));
        for (int i = 1; i < N - 1; i++)
        {
                for (int j = 1; j < N - 1; j++)
            {
                    matriz[i][j] = min({i, j, N - 1 - i, N - 1 - j}) + 1;
         }
     }
        for (int i = 0; i < N; i++)
        {
                for (int j = 0; j < N; j++)
            {
                    cout << right << setw(3) << matriz[i][j];
                if (j < N - 1)
                {
                        cout << " ";
             }
         }
            cout << endl;
     }
        cout << endl;
 }
    return 0;
}
