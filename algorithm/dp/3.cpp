#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int n; cin >> n;
    vector<vector<int> > nums(n+1, vector<int>(n+1,0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            cin >> nums[i][j];
        }
    }
    vector<vector<int>> dp(n+1, vector<int>(n+1));
    for (int i = 1; i <= n; ++i) {
        dp[n][i] = nums[n][i];
    }
    for (int i = n-1; i >= 1; --i) {
        for (int j = 1; j <= i; ++j) {
            dp[i][j] = max(dp[i+1][j], dp[i+1][j+1])+nums[i][j];
        }
    }
    cout << dp[1][1] << endl;
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