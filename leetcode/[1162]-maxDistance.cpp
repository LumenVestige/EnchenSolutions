//
// Created by sanenchen on 25-10-3.
//
#include <bits/stdc++.h>
using namespace std;

int maxDistance(vector<vector<int>> &grid) {
    int DIRS[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    vector<vector<int>> cnt(grid.size(), vector<int>(grid[0].size(), -1));
    queue<pair<int, int>> q;
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
            if (grid[i][j] == 1) {
                q.emplace(i, j);
                cnt[i][j] = 0;
            }
        }
    }
    int ans = -1;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (auto& [mx, my] : DIRS) {
            int i = mx + x, j = my + y;
            if (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && cnt[i][j] == -1) {
                cnt[i][j] = cnt[x][y] + 1;
                ans = max(ans, cnt[i][j]);
                q.emplace(i, j);
            }
        }
    }
    return ans;
}
int main() {
    vector<vector<int>> grid = {{1, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    cout << maxDistance(grid);
    return 0;
}