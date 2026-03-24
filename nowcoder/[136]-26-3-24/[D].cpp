#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    // 摸清这个mid的上下限
    int pos_mid = (n+1)/2;
    int pos_lower = lower_bound(nums.begin(), nums.end(), nums[(n+1)/2-1]) - nums.begin() + 1;
    int pos_upper = upper_bound(nums.begin(), nums.end(), nums[(n+1)/2-1]) - nums.begin();
    int ans = INT_MAX;
    if (pos_lower != 1) {
        ans = min(ans, n + 2 - 2 * pos_lower);
    }
    if (pos_upper != n) {
        ans = min(ans, 2 * pos_upper - n + 1);
    }
    cout << (ans == INT_MAX ? -1 : ans);
    return 0;
}