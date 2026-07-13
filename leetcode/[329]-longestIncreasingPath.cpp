#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int longestIncreasingPath(vector<vector<int>>& matrix) {
    // 优先队列
    priority_queue<pair<int, array<int, 2>>,vector<pair<int, array<int, 2>>>,greater<pair<int, array<int, 2>>>> pq;
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(n, 1));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            pq.push({matrix[i][j], {i, j}});
        }
    }
    // 上下左右
    int DIRS[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    while (!pq.empty()) {
        pair<int, array<int, 2>> t = pq.top();
        pq.pop();
        int num = t.first;
        // cout << num << endl;
        auto [x, y] = t.second;
        int mmax = 0;
        for (auto& [mx, my] : DIRS) {
            int i = mx + x, j = my + y;
            if (i >= 0 && j >= 0 && i < m && j < n && matrix[i][j] < num) {
                mmax = max(mmax, dp[i][j]);
            }
        }
        dp[x][y] += mmax;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ans = max(ans, dp[i][j]);
        }
    }
    return ans;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<vector<int>> g = {
        {1, 2}
    };
    cout << longestIncreasingPath(g);
    return 0;
}