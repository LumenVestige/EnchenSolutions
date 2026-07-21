#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int n;
    cin >> n;
    vector<int> nums(n);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        ans += i*nums[i] - (n-1-i)*nums[i];
    }

    cout << ans;
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