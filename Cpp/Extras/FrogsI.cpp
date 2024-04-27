#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int minCost(vector<int>& heights) {
    int n = heights.size();
    vector<int> dp(n, 0);

    // Inicialização dos casos base
    dp[0] = 0;
    dp[1] = abs(heights[1] - heights[0]);

    // Iteração para calcular o custo mínimo até cada pedra
    for (int i = 2; i < n; i++) {
        dp[i] = min(dp[i - 1] + abs(heights[i] - heights[i - 1]),
                    dp[i - 2] + abs(heights[i] - heights[i - 2]));
    }

    return dp[n - 1];
}

int main() {
    int N;
    cin >> N;

    vector<int> heights(N);
    for (int i = 0; i < N; i++) {
        cin >> heights[i];
    }
    cout << minCost(heights) << endl;

    return 0;
}
