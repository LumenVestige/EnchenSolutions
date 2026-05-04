#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int n, sum = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i], sum += a[i];
    if (sum % n) {
        cout << "NO" << endl;
        return;
    }
    int k = sum / n, s = 0, mx = 0, mn = 0x3f3f3f3f;
    for (auto v : a) s += v - k, mx = max(mx, s), mn = min(mn, s);
    cout << (mx - mn <= 1 ? "YES" : "NO") << endl;
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