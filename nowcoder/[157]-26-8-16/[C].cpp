#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve() {
    int n;
    cin >> n;
    map<int, pair<int, int>> mp;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (!mp.count(x)) {
            mp[x] = {i, i};
        } else {
            mp[x].second = i;
        }
    }
    int ans = 0;
    for (auto& [val, pos] : mp) {
        int l = pos.first;
        int r = pos.second;
        if (l < r && (r - l) % 2 == 0) {
            ans++;
        }
    }
    cout << ans << endl;
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