//
// Created by sanenchen on 25-10-1.
//
#include <bits/stdc++.h>
using namespace std;
bool hasValidPath(vector<vector<int>> &grid) {
    // 构建规则表
    unordered_map<int, vector<pair<vector<int>, vector<int>>>> DIRS;
    DIRS[1] = {{{0, 1}, {1, 3, 5}}, {{0, -1}, {1, 4, 6}}};
    DIRS[2] = {{{{1, 0}}, {2, 5, 6}}, {{{-1, 0}}, {2, 3, 4}}};
    DIRS[3] = {{{{1, 0}}, {2, 5, 6}}, {{{0, -1}}, {1, 4, 6}}};
    DIRS[4] = {{{{0, 1}}, {1, 3, 5}}, {{{1, 0}}, {2, 5, 6}}};
    DIRS[5] = {{{{-1, 0}}, {2, 3, 4}}, {{{0, -1}}, {1, 4, 6}}};
    DIRS[6] = {{{{0, 1}}, {1, 3, 5}},{{{-1, 0}}, {2, 3, 4}}};
    vector<vector<int>> cnt(grid.size(), vector<int>(grid[0].size(), 0));
    function<bool(int, int)> dfs = [&](int x, int y) -> bool {
        cnt[x][y] = 1;
        bool canGo = false;
        auto targets = DIRS[grid[x][y]];
        for (auto& target : targets) {
            int i = x + target.first[0], j = y + target.first[1];
            if (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && cnt[i][j] == 0) {
                int theNext = grid[i][j];
                if (find(target.second.begin(), target.second.end(), theNext) != target.second.end()) {
                    if (dfs(i, j))
                        canGo = true;
                }
            }
        }
        if (x == grid.size() - 1 && y == grid[0].size() - 1)
            canGo = true;
        return canGo;
    };
    return dfs(0, 0);
}
int main() {
    vector<vector<int>> grid = {{1,1,1,1,1,3}};
    cout << hasValidPath(grid);
    return 0;
}