#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int n, x; cin >> n >> x;
    unordered_map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
        int t;cin >> t;
        cnt[t]++;
    }
    int ans = 0;
    for (auto& [k ,v] : cnt) {
        if (v <= x) {
            ans += v;
        }
    }
    cout << ans << endl;

}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}