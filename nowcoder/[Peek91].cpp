#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

signed main() {
    int n, m, s;
    cin >> n >> m >> s;
    vector<vector<int>> grids(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        grids[a].push_back(b);
    }
    vector<int> dis(n+1, -1), vis(n+1, 0);
    queue<int> q;
    dis[s] = 0;
    q.push(s);
    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        if (vis[t]) continue;
        for (auto j : grids[t]) {
            if (dis[j] == -1) {
                dis[j] = dis[t] + 1;
                q.push(j);
            }
        }
        vis[t] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        cout << dis[i] << " ";
    }
    return 0;
}