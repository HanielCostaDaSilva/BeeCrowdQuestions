#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxHappiness(int N, vector<int>& a, vector<int>& b, vector<int>& c) {
    // Iniciamos a matriz de DP para armazenar a máxima felicidade em cada dia
    vector<vector<int>> dp(N, vector<int>(3, 0));

    // Define os valores iniciais para o primeiro dia
    dp[0][0] = a[0]; // Natação
    dp[0][1] = b[0]; // Capturar insetos
    dp[0][2] = c[0]; // Dever de casa

    // Percorremos sobre o array de dias restantes
    for (int i = 1; i < N; i++) {
        // Atividade A: Natação
        dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + a[i];
        // Atividade B: Capturar insetos
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + b[i];
        // Atividade C: Dever de casa
        dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + c[i];
    }

    // Retorna a máxima felicidade no último dia
    return max({dp[N - 1][0], dp[N - 1][1], dp[N - 1][2]});
}

int main() {
    int N;
    cin >> N;

    vector<int> a(N), b(N), c(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }

    int result = maxHappiness(N, a, b, c);
    cout << result << endl;

    return 0;
}
