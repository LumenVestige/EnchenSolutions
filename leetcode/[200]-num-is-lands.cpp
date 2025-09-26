//
// Created by sanenchen on 25-7-22.
//
#include "LeetCodes.h"

void bfs(vector<vector<char> > &grid, int i, int j) {
    queue<pair<int ,int>> queue;
    queue.emplace(i, j);
    while (!queue.empty()) {
        int n_i = queue.front().first;
        int n_j = queue.front().second;
        queue.pop();
        // 避免越界
        if (n_i < 0 || n_j < 0 || n_i >= grid.size() || n_j >= grid[0].size() || grid[n_i][n_j] == '0')
            continue;
        // 标记当前已经遍历过了
        grid[n_i][n_j] = '0';
        // 压入上下左右的陆地
        queue.emplace(n_i + 1, n_j);
        queue.emplace(n_i, n_j + 1);
        queue.emplace(n_i - 1, n_j);
        queue.emplace(n_i, n_j - 1);
    }
}
// bfs 解法
int LeetCodes::numIslands(vector<vector<char> > &grid) {
    int res = 0;
    // 遍历 grid
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] == '1') {
                bfs(grid, i, j);
                res++;
            }
        }
    }
    return res;
}

// dfs 解法
int numIslands(vector<vector<char>>& grid) {
    int DIRS[4][2] = {{0,1}, {1, 0}, {0, -1}, {-1, 0}};
    function<void(int, int)> dfs = [&](int i, int j) {
        // 标记当前为空
        grid[i][j] = '0';
        // 递归标记为空
        for (auto& [mx, my] : DIRS) {
            int x = mx + i, y = my + j;
            if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == '1') {
                // grid[x][y] = '0';
                dfs(x, y);
            }
        }
    };
    int ans = 0;
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
            if (grid[i][j] == '1') {
                dfs(i, j);
                ans++;
            }
        }
    }
    return ans;
}