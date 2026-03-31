#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve() {
    int n;
    cin >> n;
    vector<int> nums(n+1);
    // 前缀异或和
    vector<int> prefix(n+1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> nums[i];
        prefix[i] = prefix[i-1] ^ nums[i];
    }
    vector<int> dp(n+1, 1e18);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        int cM = 1e18;
        for (int j = 0; j < i; ++j) {
            // 从j位置开始分割 分为 [1, j], (j, i]
            cM = min(cM, prefix[i] ^ prefix[j]);
            dp[i] = min(dp[i], dp[j] + cM);
        }
    }
    cout << dp[n] << endl;

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}