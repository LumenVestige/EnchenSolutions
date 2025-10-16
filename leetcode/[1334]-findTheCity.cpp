#include <bits/stdc++.h>
using namespace std;

int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
    for (auto& it : edges) {
        dp[it[0]][it[1]] = it[2];
        dp[it[1]][it[0]] = it[2]; // 反向边
        dp[it[0]][it[0]] = 0;
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dp[i][k] != INT_MAX && dp[k][j] != INT_MAX) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }
    }
    int result = 0;
    int minCount = INT_MAX;
    for (int i = 0; i < n; ++i) {
        int count = 0;
        for (int j = 0; j < n; ++j) {
            if (i != j && dp[i][j] <= distanceThreshold) {
                count++;
            }
        }
        if (count <= minCount) {
            minCount = count;
            result = max(result, i);
        }
    }
    return result;
}

int main() {
    vector<vector<int>> edges = {{0,1,3},{1,2,1},{1,3,4},{2,3,1}};
    cout << findTheCity(4, edges, 4);
    return 0;
}