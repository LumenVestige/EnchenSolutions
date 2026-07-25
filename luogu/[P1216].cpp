#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int n;
    cin >> n;
    vector<vector<int>> nums(n, vector<int>(n)), dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i+1; ++j) {
            cin >> nums[i][j];
        }
    }
    dp[0][0] = nums[0][0];
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            int a = (j-1 >= 0 ? dp[i-1][j-1] : 0);
            int b = (j <= i-1 ? dp[i-1][j] : 0);
            dp[i][j] = max(a, b) + nums[i][j];
            // cout << dp[i][j] << " ";
        }
        // cout << endl;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(dp[n-1][i], ans);
    }
    cout << ans;

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