#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int MOD = 998244353;
void solve() {
    int n; cin >> n;
    vector<int> dp(n+1, 0);
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i-1] + dp[i-2];
        dp[i] %= MOD;
    }
    cout << dp[n] % MOD << endl;
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