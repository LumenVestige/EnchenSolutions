//
// Created by sanenchen on 25-10-5.
//
#include <bits/stdc++.h>
using namespace std;
int orangesRotting(vector<vector<int>> &grid) {
    int DIRS[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    vector<vector<int>> cnt(grid.size(), vector<int>(grid[0].size(), 0));
    queue<pair<int, int>> q;
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
            if (grid[i][j] == 2) {
                q.emplace(i, j);
                cnt[i][j] = 1;
            }

        }
    }
    int ans = 0;
    while (!q.empty()) {
        int size = q.size();
        int flag = false;
        while (size--) {
            auto [x, y] = q.front();
            q.pop();
            for (auto &[mx, my] : DIRS) {
                int i = mx + x, j = my + y;
                if (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && !cnt[i][j] && grid[i][j] == 1) {
                    flag = true;
                    q.emplace(i, j);
                    cnt[i][j] = 1;
                    grid[i][j] = 2;
                }
            }
        }
        if (flag)
            ans++;
    }
    // 扫描一遍
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
            if (grid[i][j] == 1) {
                return -1;
            }
        }
    }
    return ans;
}
int main() {
    vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    cout << orangesRotting(grid);
    return 0;
}