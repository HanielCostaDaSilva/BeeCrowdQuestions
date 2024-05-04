#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007; 

int distinctWays(int n, int x, vector<int>& coins) {
    vector<int> dp(x + 1, 0);
    dp[0] = 1; 

    for (int i = 0; i < n; i++) { // Itera sobre cada moeda
        for (int j = coins[i]; j <= x; j++) { // Itera sobre cada valor possível da soma
            dp[j] = (dp[j] + dp[j - coins[i]]) % MOD; 
        }
    }

    return dp[x]; 
}

int main() {
    int quantyCoins, total;
    cin >> quantyCoins >> total; 

    vector<int> coins(quantyCoins);
    for (int i = 0; i < quantyCoins; i++) {
        cin >> coins[i];
    }

    cout << distinctWays(quantyCoins, total, coins) << endl;

    return 0;
}
