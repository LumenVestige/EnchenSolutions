#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

signed main() {
    int n, m ,s;
    cin >> n >> m >> s;
    vector<vector<pair<int, int>>> grids(n+1);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        grids[u].push_back({v, w});
    }
    vector<int> dis(n+1, LLONG_MAX), vis(n+1, 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dis[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        auto [w, v] = pq.top();
        pq.pop();
        if (vis[v]) continue;
        for (auto [tv, tw] : grids[v]) {
            if (dis[v] + tw < dis[tv]) {
                dis[tv] = dis[v] + tw;
                pq.push({dis[tv], tv});
            }
        }
        vis[v] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        cout << (dis[i] == LLONG_MAX ? -1 : dis[i]) << " ";
    }
    return 0;
}