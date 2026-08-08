#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
vector<int> mer(const vector<int>& a, const vector<int>& b) {
    vector<int> res;
    int i = 0, j = 0;
    while (i < a.size() && j < b.size() && res.size() < 10) {
        if (a[i] < b[j]) 
            res.push_back(a[i++]);
        else 
            res.push_back(b[j++]);
    }
    while (i < a.size() && res.size() < 10) 
        res.push_back(a[i++]);
    while (j < b.size() && res.size() < 10) 
        res.push_back(b[j++]);
    return res;
}
void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> g(n+1);
    vector<vector<int>> ids(n + 1);
    for (int i = 0; i < n-1; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 1; i <= m; ++i) {
        int t; cin >> t;
        if (ids[t].size() < 10) {
            ids[t].push_back(i);
        }
    }
    vector<int> depth(n+1);
    int k = log2(n+1);
    vector<vector<int>> up(n+1, vector<int>(k+1, 0));
    vector<vector<vector<int>>> info(n+1, vector<vector<int>>(k+1));
    auto dfs = [&](auto&& dfs, int u, int p) -> void {
        depth[u] = depth[p]+1;
        // 写一下 up
        up[u][0] = p;
        info[u][0] = ids[u];
        for (int i = 1; i <= k; ++i) {
            // 从i向上跳2^i是谁？
            up[u][i] = up[up[u][i-1]][i-1];
            info[u][i] = mer(info[u][i-1], info[up[u][i-1]][i-1]);
        }
        for (auto& i : g[u]) {
            if (i != p) dfs(dfs, i, u);
        }
    };
    dfs(dfs, 1, 0);
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
    auto qu = [&](int curr, int target) {
        vector<int> res;
        for (int i = k; i >= 0; --i) {
            if (depth[up[curr][i]] >= depth[target] && up[curr][i] != 0) {
                res = mer(res, info[curr][i]);
                curr = up[curr][i];
            }
        }
        return res;
    };
    while (q--) {
        int a, b, c;
        cin >> a >> b >> c;
        int r = lca(a, b);
        vector<int> cad;
        vector<int> cad_a = qu(a, r);
        vector<int> cad_b = qu(b, r);
        cad = mer(cad_a, cad_b);
        cad = mer(cad, ids[r]);
        int ansK = min((int)cad.size(), c);
        cout << ansK;
        for (int i = 0; i < ansK; ++i) {
            cout << " " << cad[i];
        }
        cout << endl;
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