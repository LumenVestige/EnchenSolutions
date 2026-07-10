#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    int x;
    cin >> x;
    int sum = 0;
    for (int j = 1; j <= m; j++) sum ^= a[1][j];
    for (int i = 2; i <= n; i++) sum ^= a[i][1];
    int v = sum ^ a[1][1] ^ x;
    cout << "YES" << endl;
    cout << 1 << " " << 1 << " " << v << endl;
    cout << 1 << " " << 1 << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}