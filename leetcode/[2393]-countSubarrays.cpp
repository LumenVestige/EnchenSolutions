#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
long long countSubarrays(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 0);
    dp[0] = 1;
    for (int i = 1; i < n; ++i) {
        if (nums[i] > nums[i-1]) {
            dp[i] = dp[i-1]+1;
        } else dp[i] = 1;
    }
    int tot = 0;
    for (int i = 0; i < n; ++i) {
        tot += dp[i];
    }
    return tot;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {

    }
    return 0;
}