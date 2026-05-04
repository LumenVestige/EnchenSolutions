#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int n; cin >> n;
    vector<int> nums(n);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    for (auto& i : nums) {
        if (i % (ans+1) == 0) {
            ans++;
        }
    }
    cout << ans << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}