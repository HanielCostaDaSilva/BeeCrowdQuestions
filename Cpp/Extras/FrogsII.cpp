#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

int minCost(vector<int>& heights, int K) {
    int N = heights.size();
    vector<int> dp(N, 0);

    // Inicialização dos casos base
    dp[0] = 0;

    for (int i = 1; i < N; i++) {
        dp[i] = INT_MAX;
        for (int j = 1; j <= K && i - j >= 0; j++) {
            dp[i] = min(dp[i], dp[i - j] + abs(heights[i] - heights[i - j]));
        }
    }

    // Retorna o custo mínimo para alcançar a pedra N
    return dp[N - 1];
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> heights(N);
    for (int i = 0; i < N; i++) {
        cin >> heights[i];
    }

    cout << minCost(heights, K) << endl;

    return 0;
}
