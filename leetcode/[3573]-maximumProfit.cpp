#include <bits/stdc++.h>
using namespace std;
using ll = long long;
long long maximumProfit(vector<int>& prices, int k) {
    vector memo(prices.size(), vector<array<long long, 3>>(k + 1, {LLONG_MIN, LLONG_MIN, LLONG_MIN})); // LLONG_MIN 表示还没有计算过
    // 状态定义：0 未持有 1 做空中 2 持有中
    auto dfs = [&](auto&& dfs, int i, int j, int k)->ll {
        if (i < 0) {
            if (k == 0) {
                return 0;
            }
            return LLONG_MIN / 2;
        }
        if (j < 0) {
            return INT_MIN / 2;
        }
        ll& res = memo[i][j][k];
        if (res != LLONG_MIN) {
            return res;
        }
        int p = prices[i];
        if (k == 0) {
            return res = max({dfs(dfs, i - 1, j, 0), dfs(dfs, i - 1, j, 1) - p, dfs(dfs, i - 1, j, 2) - p});
        }
        if (k == 1) {
            return res = max({dfs(dfs, i - 1, j, 1), dfs(dfs, i - 1, j - 1, 0) - p});
        }
        return res = max({dfs(dfs, i - 1, j, 2), dfs(dfs, i - 1, j - 1, 0) + p});
    };
    return dfs(dfs, prices.size() - 1, k, 0);
}
int main() {
    vector<int> prices = {1,7,9,8,2};
    cout << maximumProfit(prices, 2);
    return 0;
}