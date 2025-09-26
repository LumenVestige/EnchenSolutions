//
// Created by sanenchen on 25-9-25.
//
#include <bits/stdc++.h>
using namespace std;

int maxAreaOfIsland(vector<vector<int>>& grid) {
    // dfs 思想
    int DIRS[4][2] = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};
    function<int(int, int)> dfs = [&](int x, int y) -> int {
        int area = 1; // 当前这个格子记录
        grid[x][y] = 0; // 标记为空
        for (auto& [xm, ym] : DIRS) {
            int i = xm + x, j = ym + y;
            if (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j]) {
                area += dfs(i, j);
            }
        }
        return area;
    };
    int ans = 0;
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
            if (grid[i][j]) ans = max(ans, dfs(i, j));
        }
    }
    return ans;
}
int main() {
    vector<vector<int>> grid = {{0,0,1,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,1,1,0,1,0,0,0,0,0,0,0,0},{0,1,0,0,1,1,0,0,1,0,1,0,0},{0,1,0,0,1,1,0,0,1,1,1,0,0},{0,0,0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,0,0,0,0,0,0,1,1,0,0,0,0}};
    cout << maxAreaOfIsland(grid);
    return 0;
}