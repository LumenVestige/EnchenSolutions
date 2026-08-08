#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve() {
    int n; cin >> n;
    unordered_map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
        int t; cin >> t;
        cnt[t]++;
    }
    int ans = INT_MAX;
    for (auto& [k, v] : cnt) {
        ans = min(ans, n - v);
    }
    cout << ans;
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