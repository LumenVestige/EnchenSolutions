#include <bits/stdc++.h>
using namespace std;

int maximumAmount(vector<vector<int>>& coins) {
    int m = coins.size(), n = coins[0].size();
    vector<vector<vector<int>>> memo(m, vector<vector<int>>(n, vector<int>(3, -1)));
    function<int(int, int, int)> dfs = [&](int x, int y, int k) {
        if (x < 0 || y < 0) {
            return INT_MIN;
        }
        auto& res = memo[x][y][k];
        if (res != -1) {
            return res;
        }
        if (x == 0 && y == 0) {
            return coins[0][0];;
        }
        int coin = coins[x][y];
        if (coins[x][y] < 0 && k > 0) {
            k--;
            coin = 0;
        }
        res = max(dfs(x - 1, y, k), dfs(x, y - 1, k)) + coin;
        return res;
    };
    return dfs(m - 1, n - 1, 2);
}

int main() {

    return 0;
}