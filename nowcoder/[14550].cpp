#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int dijkstra(int m, unordered_map<int, vector<array<int, 2>>>& grids, int n) {
    // m 其实是中间点，但是我们把它当做起点去单源扫
    vector<int> dis(n + 1, 0x3f3f3f3f);
    vector<bool> vis(n + 1, false);
    dis[m] = 0;
    auto cmp = [](const array<int, 2>& a, const array<int, 2>& b) {
        return a[1] > b[1];
    };
    priority_queue<array<int, 2>, vector<array<int, 2>>, decltype(cmp)> pq(cmp);
    pq.push({m, 0});
    int max1 = 0, max2 = 0; // 第一大 第二大
    while (!pq.empty()) {
        // 取出最上层
        auto [f, c] = pq.top();
        pq.pop();
        if (vis[f]) continue;
        for (auto& i : grids[f]) {
            if (c + i[1] < dis[i[0]]) {
                dis[i[0]] = c + i[1];
                pq.push({i[0], dis[i[0]]});
            }
        }
        vis[f] = 1;
        if (dis[f] > max1) {
            max2 = max1;
            max1 = dis[f];
        } else if (dis[f] > max2) {
            max2 = dis[f];
        }
    }
    if (max2 == 0) return -1;
    return max1 + max2;
}

void solve() {
    int n, m;
    cin >> n >> m;
    // 初始化邻接表
    unordered_map<int, vector<array<int, 2>>> grids;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        grids[a].push_back({b, c});
        grids[b].push_back({a, c});
    }
    int ma = -1;
    for (int i = 1; i <= n; ++i) {
        int t = dijkstra(i, grids, n);
        if (t > ma) {
            ma = t;
        }
    }
    cout << ma << endl;
}

signed main() {
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}