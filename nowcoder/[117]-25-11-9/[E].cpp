//
// Created by sanenchen on 25-11-9.
//
#include <bits/stdc++.h>
using namespace std;
#define int long long
struct Node {
    int x;
    int y;
    int px;
    int py;
};
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int DIRS[8][2] = {{1, 2}, {2, 1}, {-1, -2}, {-2, -1}, {-1, 2}, {2, -1}, {1, -2}, {-2, 1}};
    queue<Node> que;
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int,int>>> parent(n + 1, vector<pair<int,int>>(m + 1, {-1, -1}));
    vector<vector<int>> vis(n + 1, vector<int>(m + 1, 0));
    int tarX, tarY;
    cin >> tarX >> tarY;
    que.push({tarX, tarY, -1, -1});
    vis[tarX][tarY] = 1;
    cin >> tarX >> tarY;
    int times = 0;
    while (!que.empty()) {
        int size = que.size();
        while (size-- && times <= k) {
            auto v = que.front();
            que.pop();
            int x = v.x, y = v.y;
            if (x == tarX && y == tarY && times == k) {
                // 回溯路径
                vector<pair<int,int>> path;
                int cx = x, cy = y;
                while (cx != -1) {
                    path.emplace_back(cx, cy);
                    auto [px, py] = parent[cx][cy];
                    cx = px, cy = py;
                }
                reverse(path.begin(), path.end());

                cout << "Yes" << endl;
                for (int i = 1; i < path.size(); i++) {
                    cout << path[i].first << " " << path[i].second << endl;
                }
                return 0;
            }
            for (auto& [mx, my] : DIRS) {
                int i = mx + x, j = my + y;
                if (i >= 1 && j >= 1 && i <= n && j <= m && vis[i][j] == 0) {
                    vis[i][j] = 1;
                    parent[i][j] = {x, y};
                    que.push({i, j, x, y});
                }
            }
        }
        times++;
    }
    cout << "No";
    return 0;
}