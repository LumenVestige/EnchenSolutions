//
// Created by sanenchen on 25-10-6.
//
#include <bits/stdc++.h>
using namespace std;
int shortestBridge(vector<vector<int>>& grid) {
    int DIRS[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    vector<vector<int>> cnt(grid.size(), vector<int>(grid[0].size(), 0));
    queue<pair<int, int>> q;
    function<void(int, int)> dfs = [&](int x, int y) {
        q.emplace(x, y);
        cnt[x][y] = 1;
        grid[x][y] = -1;
        for (auto& [mx, my] : DIRS) {
            int i = mx + x, j = my + y;
            if (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && !cnt[i][j] && grid[i][j])
                dfs(i, j);
        }
    };
    bool found = false;
    for (int i = 0; i < grid.size() && !found; ++i) {
        for (int j = 0; j < grid[0].size() && !found; ++j) {
            if (grid[i][j] == 1) {
                dfs(i, j);
                found = true;
            }
        }
    }
    int ans = 0;
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            auto [x, y] = q.front();
            q.pop();
            if (grid[x][y] == 1) return ans - 1;
            for (auto& [mx, my] : DIRS) {
                int i = mx + x, j = my + y;
                if (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && !cnt[i][j]) {
                    q.emplace(i, j);
                    cnt[i][j] = 1;
                }
            }
        }
        ans++;
    }
    return -1;
}
int main() {
    vector<vector<int>> grid = {{0, 1}, {1, 0}};
    cout << shortestBridge(grid);
    __asm {
        mov eax, 1;
    }
    return 0;
}