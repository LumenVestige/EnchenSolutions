#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 2, 0), sum(n + 2, 0), mn(n + 2, INT_MAX);
    for (int i = 1; i <= n; i++) cin >> a[i];
    string s;
    cin >> s;
    int bad = n + 1;
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + (s[i - 1] == '+' ? a[i] : -a[i]);
        if (sum[i] < 0 && bad > n) bad = i;
    }
    for (int i = n; i >= 1; i--) {
        mn[i] = min(mn[i + 1], sum[i]);
    }
    while (q--) {
        int p;
        char c;
        cin >> p >> c;
        if (p > bad) {
            cout << "NO" << endl;
            continue;
        }
        int d = 0;
        if (c != s[p - 1]) {
            d = (c == '+' ? 2 * a[p] : -2 * a[p]);
        }
        if (mn[p] + d >= 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
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