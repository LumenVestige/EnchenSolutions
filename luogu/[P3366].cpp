#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve() {
    // Prim 算法
    int point = 0;
    int n, m;
    cin >> n >> m;
    vector<vector<array<int, 2>>> edges(n+1);
    int t;
    for (int i = 0; i < m; ++i) {
        int a, b, v;
        cin >> a >> b >> v;
        edges[a].push_back({v, b});
        edges[b].push_back({v, a});
        t = a;
    }
    vector<int> dis(n+1,INT_MAX), vis(n+1, false);
    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;
    dis[1] = 0;
    pq.push({0, 1});
    int res = 0;
    while (!pq.empty()) {
        auto [v, a] = pq.top();
        pq.pop();
        if (vis[a]) continue;
        vis[a] = 1;
        res += v;
        point++;
        for (auto& [vv, aa] : edges[a]) {
            if (vv < dis[aa]) {
                dis[aa] = vv;
                pq.push({vv, aa});
            }
        }
    }
    if (point!=n) {
        cout << "orz";
    } else {
        cout << res;
    }
}

struct DSU {
    vector<int> par;
    int n;
    DSU(int n) : par(n+1), n(n) {
        for (int i = 0 ; i <= n; ++i) {
            par[i] = i;
        }
    }
    int find(int x) {
        while (x != par[x]) {
            par[x] = par[par[x]];
            x = par[x];
        }
        return x;
    }
    bool merge(int x, int y) {
        int rootX = find(x), rootY = find(y);
        if (rootX != rootY) {
            n--;
            par[rootX] = rootY;
            return true;
        }
        return false;
    }
};

void solve2() {
    // Kruskal 算法
    int point = 0;
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> edges(n+1);
    for (int i = 0; i < m; ++i) {
        int a, b, v;
        cin >> a >> b >> v;
        edges.push_back({v, a, b});
    }
    // 根据边权排序，加边
    DSU dsu(n);
    int res = 0;
    sort(edges.begin(), edges.end());
    for (auto& i : edges) {
        auto [v, a, b] = i;
        if (dsu.merge(a, b)) {
            res += v;
        }
    }
    if (dsu.n != 1) {
        cout << "orz";
    } else {
        cout << res;
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve2();
    }
    return 0;
}