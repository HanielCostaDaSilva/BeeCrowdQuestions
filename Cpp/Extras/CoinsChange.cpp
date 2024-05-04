#include <iostream>
#include <vector>

using namespace std;

vector<int> coins = {1, 5, 10, 25, 50};

int countWays(int amount) {
    vector<int> dp(amount + 1, 0);
    dp[0] = 1; // Existe a forma de realizar o troco com 0 moedas

    for (int coin : coins) {
        for (int i = coin; i <= amount; i++) {
            dp[i] += dp[i - coin];
        }
    }

    return dp[amount];
}

int main() {
    int amount;
    while (cin >> amount) {
        int ways = countWays(amount);
        cout << ways << endl;
    }
    return 0;
}
