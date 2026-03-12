#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve() {
    int n, m, h;
    cin >> n >> m >> h;

    vector<int> orig(n);
    for (int i = 0; i < n; ++i) {
        cin >> orig[i];
    }

    vector<pair<int, int>> ops(m);
    for (int i = 0; i < m; ++i) {
        cin >> ops[i].first >> ops[i].second;
        ops[i].first--;
    }

    vector<int> cur = orig;
    int lastCrash = -1;
    for (int i = 0; i < m; ++i) {
        int b = ops[i].first;
        int c = ops[i].second;
        cur[b] += c;
        if (cur[b] > h) {
            lastCrash = i;
            cur[b] = orig[b];
        }
    }

    vector<int> ans = orig;
    for (int i = lastCrash + 1; i < m; ++i) {
        int b = ops[i].first;
        int c = ops[i].second;
        ans[b] += c;
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
