#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    dp[0][0] = 0, dp[0][1] = -1e9;
    for (int i = 0; i < n; ++i) {
        dp[i + 1][0] = max(dp[i][0], dp[i][1] + prices[i]);
        dp[i + 1][1] = max(dp[i][1], dp[i][0] - prices[i]);
    }
    return dp[n][0];
}
int main() {
    vector<int> prices = {7,1,5,3,6,4};
    cout << maxProfit(prices);
    return 0;
}