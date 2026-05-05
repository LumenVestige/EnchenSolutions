#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int n; cin >> n;
    vector<int> nums(n+1);
    int mmax = -0x3f3f3f3f;
    for (int i = 1; i <= n; ++i) {
        cin >> nums[i];
    }
    vector<int> dp(n+1, 0);
    for (int i = 1; i <= n; ++i) {
        dp[i] = max(nums[i], nums[i]+dp[i-1]);
        mmax = max(mmax, dp[i]);
    }
    cout << mmax;
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