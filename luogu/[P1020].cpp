#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    vector<int> nums;
    int t;
    while (cin >> t) {
        nums.push_back(t);
    }
    int n = nums.size();
    // vector<int> dp(n, 1);
    // int maxLen = 0;
    // for (int i = 1; i < n; ++i) {
    //     for (int j = 0; j <= i; ++j) {
    //         if (nums[i] < nums[j])
    //             dp[i] = max(dp[i], dp[j] + 1);
    //     }
    //     maxLen = max(maxLen, dp[i]);
    // }
    // cout << maxLen;
    vector<int> n1, n2;
    for (int i = 0; i < n; ++i) {
        auto z = upper_bound(n1.begin(), n1.end(), nums[i], greater<int>());
        if (z == n1.end()) {
            n1.push_back(nums[i]);
        } else {
            *z = nums[i];
        }
    }
    for (int i = 0; i < n; ++i) {
        auto z = lower_bound(n2.begin(), n2.end(), nums[i]);
        if (z == n2.end()) {
            n2.push_back(nums[i]);
        } else {
            *z = nums[i];
        }
    }
    cout << n1.size() << endl << n2.size();
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