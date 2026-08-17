#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve() {
    int n;
    cin >> n;
    string cor; cin >> cor;
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
    auto getUp = [&](auto&& getUp, int u, int p)->void {
        depth[u] = depth[p]+1;
        up[u][0] = p; // 向上跳 2^0(1)次
        for (int i = 1; i <= k; ++i) {
            up[u][i] = up[up[u][i-1]][i-1];
        }
        for (auto& i : g[u]) {
            if (i != p) getUp(getUp, i, u);
        }
    };
    getUp(getUp, 1, 0);
    auto lca = [&](int a, int b)->int {
        // 保证 a 深度比 b 深
        if (depth[a] < depth[b]) swap(a, b);
        for (int i = k; i >= 0; --i) {
            if (depth[up[a][i]] >= depth[b]) {
                a = up[a][i];
            }
        }
        if (a == b) {
            return a;
        }
        for (int i = k; i >= 0; --i) {
            // 同时往上跳
            if (up[a][i] != up[b][i]) {
                a = up[a][i];
                b = up[b][i];
            }
        }
        return up[a][0];
    };
    auto dist = [&](int a, int b) {
        return depth[a] + depth[b] - 2*depth[lca(a, b)];
    };
    int r0 = 0;
    for (int i = 0; i < cor.size(); ++i) {
        if (cor[i] == '1') {
            r0 = i+1;
            break;
        }
    }
    int maxd = -1;
    int far = -1;
    auto findMax = [&](auto&& findMax, int u, int p, int d)->void {
        if (cor[u - 1] == '1' && d > maxd) {
            maxd = d;
            far = u;
        }
        for (int v : g[u]) {
            if (v != p) {
                findMax(findMax, v, u, d + 1);
            }
        }
    };
    findMax(findMax, r0, 0, 0);
    int A = far;
    maxd = -1;
    findMax(findMax, A, 0, 0);
    int B = far;
    int maxD = dist(A, B);
    for (int i = 0; i < n; ++i) {
        if (cor[i] == '1') {
            cout << maxD << endl;
        } else {
            cout << max({maxD, dist(A, i+1), dist(B, i+1)}) << endl;
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