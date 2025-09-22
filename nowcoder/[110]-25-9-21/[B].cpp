//
// Created by sanenchen on 25-9-21.
//
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
        cin >> nums[i];
    sort(nums.begin(), nums.end());
    int ans = nums[0] + nums[1];
    for (int i = 2; i < nums.size(); ++i) {
        ans += 2 * nums[i];
    }

    cout << ans << endl;
}

signed main() {
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}