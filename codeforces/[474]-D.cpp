#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod = 1e9+7;
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> dp(1e5+7, 0), prefix(1e5+7, 0);
    dp[0] = 1;
    for (int i = 1; i < 1e5+7; ++i) {
        // R end
        dp[i] += dp[i-1];
        // W end
        if (i-k >= 0) {
            dp[i] += dp[i-k];
        }
        dp[i] %= mod;
        prefix[i] = (prefix[i-1]+dp[i])%mod;
    }
    while (n--) {
        int a, b; cin >> a >> b;
        int ans = prefix[b]-prefix[a-1]+mod;
        ans %= mod;
        cout << ans << endl;
    }
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