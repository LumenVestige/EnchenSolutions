//
// Created by sanenchen on 25-10-24.
//
#include <bits/stdc++.h>
using namespace std;
int coinChange(vector<int>& coins, int amount) {
    int M = amount + 1;
    vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, 0));
    for (int i = 1; i <= amount; ++i) {
        dp[0][i] = M;
    }
    // 进行状态转移
    for (int i = 1; i <= coins.size(); ++i) {
        for (int j = 1; j <= amount; ++j) {
            if (coins[i - 1] > j) {
                // 转移到上一个上去
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - coins[i - 1]] + 1);
            }
        }
    }
    return dp[coins.size()][amount] == M ? -1 : dp[coins.size()][amount];
}
int main() {
    vector<int> coins = {1, 2, 5};
    cout << coinChange(coins, 11);
    return 0;
}