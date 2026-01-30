#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

signed main() {
    int n, m, s;
    cin >> n >> m >> s;
    vector<vector<pair<int, int>>> grids(n+1);
    vector<int> dis(n+1, LONG_MAX), vis(n+1, 0);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        grids[a].push_back({b, c});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dis[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        auto [w, v] = pq.top();
        pq.pop();
        if (vis[v]) continue;
        for (auto& [tV, tW] : grids[v]) {
            if (tW + dis[v] < dis[tV]) {
                dis[tV] = tW + dis[v];
                pq.push({dis[tV], tV});
            }
        }
        vis[v] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        if (dis[i] == LONG_MAX) cout << 2147483647 << " ";
        else cout << dis[i] << " ";
    }
    return 0;
}