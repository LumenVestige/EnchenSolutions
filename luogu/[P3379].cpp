#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define endl "\n"
void solve() {
    int n, m, s;
    cin >> n >> m >> s;
    vector<vector<int>> g(n+1);
    for (int i = 0; i < n-1; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> depth(n+1);
    int k = log2(n+1);
    vector<vector<int>> up(n+1, vector<int>(k+1, 0));
    auto dfs = [&](auto&& dfs, int u, int p) -> void {
        depth[u] = depth[p]+1;
        // 写一下 up
        up[u][0] = p;
        for (int i = 1; i <= k; ++i) {
            // 从i向上跳2^i是谁？
            up[u][i] = up[up[u][i-1]][i-1];
        }
        for (auto& i : g[u]) {
            if (i != p) dfs(dfs, i, u);
        }
    };
    dfs(dfs, s, 0);
    auto lca = [&](int a, int b) {
        if (depth[a] < depth[b]) swap(a, b); // a 的深度要比 b 大
        // 将 a 深度 提高到 b深度
        for (int i = k; i >= 0; --i) {
            if (depth[up[a][i]] >= depth[b]) {
                a = up[a][i];
            }
        }
        if (a == b) return a;
        // 同时往上跳
        for (int i = k; i >= 0; --i) {
            if (up[a][i] != up[b][i]) {
                a = up[a][i];
                b = up[b][i];
            }
        }
        return up[a][0];
    };
    while (m--) {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << endl;
    }
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