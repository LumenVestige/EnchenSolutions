#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int minFallingPathSum(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        dp[0][i] = grid[0][i];
    }
    for (int i = 1; i < n; ++i) {
        int aMin = INT_MAX, aPos, bMin = INT_MAX, bPos;
        for (int j = 0; j < n; ++j) {
            if (dp[i-1][j] <= bMin) {
                if (dp[i-1][j] <= aMin) {
                    bMin = aMin;
                    aMin = dp[i-1][j];
                    aPos = j;
                } else {
                    bMin = dp[i-1][j];
                }
            } 
        }
        cout << aMin << " " << bMin << "---";
        for (int j = 0; j < n; ++j) {
            if (j == aPos) {
                dp[i][j] = grid[i][j] + bMin;
            } else {
                dp[i][j] = grid[i][j] + aMin;
            }
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    int ans = INT_MAX;
    for (int i = 0; i < n; ++i) {
        ans = min(ans, dp[n-1][i]);
    }
    return ans;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<vector<int>> g = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    cout << minFallingPathSum(g);
    return 0;
}