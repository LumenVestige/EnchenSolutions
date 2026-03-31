#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
// 最小生成树 Prim 算法
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> grids(n+1);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        grids[u].push_back({v, w});
        grids[v].push_back({u, w});
    }
    int ans = 0;
    int t = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> vis(n+1, 0);
    pq.push({0, 1});
    while (!pq.empty()) {
        auto [w, v] = pq.top();
        pq.pop();
        if (vis[v]) continue;
        for (auto [tV, tW] : grids[v]) {
            if (!vis[tV]) {
                pq.push({tW, tV});
            }
        }
        ans += w;
        t++;
        vis[v] = 1;
    }
    if (t != n) {
        cout << "NO";
        return 0;
    }
    cout << ans;
    return 0;
}