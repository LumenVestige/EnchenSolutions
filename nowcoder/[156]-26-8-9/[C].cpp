#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve() {
    int n, q, x;
    cin >> n >> q >>x;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        nums[i] = abs(nums[i] - x);
    }
    sort(nums.begin(), nums.end());
    vector<int> prefix(n);
    prefix[0] = abs(nums[0]);
    for (int i = 1; i < n; ++i) {
        prefix[i] = prefix[i-1] + abs(nums[i]);
    }
    // for (auto& i : prefix) {
    //     cout << i << " ";
    // }
    cout << endl;
    while (q--) {
        int t; cin >> t;
        auto pos = upper_bound(prefix.begin(), prefix.end(), t);
        cout << n - (pos - prefix.begin()) << endl;
    }

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}