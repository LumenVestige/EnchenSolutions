#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n+1);
    vector<bool> star(n+1, false);
    for (int i = 2; i <= n; ++i) {
        int t; cin >> t;
        g[t].push_back(i);
    }
    int m; cin >> m;
    for (int i = 0; i < m; ++i) {
        int a; cin >> a;
        star[a] = true;
    }
    vector<int> ans;
    auto dfs = [&](auto&& dfs, int r)->bool {
        bool active = star[r];
        for (int v : g[r]) {
            if (!dfs(dfs, v)) {
                continue;
            }
            if (active) {
                ans.push_back(v);
            } else {
                active = true;
            }
        }
        return active;
    };
    dfs(dfs, 1);
    cout << ans.size() << " ";
    for (auto& i : ans) {
        cout << i << " ";
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}