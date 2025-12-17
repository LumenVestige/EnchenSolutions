#include <bits/stdc++.h>
using namespace std;

int maxProfit(int k, vector<int>& prices) {
    int memo[prices.size()][k + 1][2];
    memset(memo, -1, sizeof(memo));
    auto dfs = [&](auto&& dfs, int i, int j, bool hold) -> long long {
        if (i < 0) {
            return hold ? INT_MIN / 2 : 0;
        }
        if (j < 0) {
            return INT_MIN / 2;
        }
        int& res = memo[i][j][hold];
        if (res != -1) {
            return res;
        }
        if (!hold) {
            return res = max(dfs(dfs, i - 1, j, false), dfs(dfs, i - 1, j - 1, true) + prices[i]); // 买入
        }
        return res = max(dfs(dfs, i - 1, j, true), dfs(dfs, i - 1, j, false) - prices[i]); // 卖出
    };
    return dfs(dfs, prices.size() - 1, k, false);
}

int main() {
    vector<int> prices = {2, 4, 1};
    cout << maxProfit(2, prices);
}