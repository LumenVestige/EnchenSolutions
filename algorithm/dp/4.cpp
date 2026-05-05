#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int n, m; cin >> n>>m;
    vector<vector<int> > grids(n+1, vector<int>(m+1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> grids[i][j];
        }
    }
    vector<vector<int> > dp(n+1, vector<int>(m+1, 0));
    for (int i = 1; i <= n; ++i) {
        dp[i][1] = dp[i-1][1] + grids[i][1];
    }
    for (int i = 1; i <= m; ++i) {
        dp[1][i] = dp[1][i-1] + grids[1][i];
    }
    for (int i = 2; i <= n; ++i) {
        for (int j = 2; j <= m; ++j) {
            dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grids[i][j];
        }
    }
    cout << dp[n][m];
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}