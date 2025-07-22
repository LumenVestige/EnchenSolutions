//
// Created by sanenchen on 25-7-19.
//
#include "../LeetCodes.h"

int g_index;
unordered_map<int, int> g_map;
vector<vector<int>> grid_index, g_grid;
void pin(int i, int j) {
    // 将当前加进去
    grid_index[i][j] = g_index;
    g_map[g_index] += g_grid[i][j];
    // // 以当前为中心，判断上下左右是否是陆地，并且grid_index=-1
    // 上面一个
    if (i - 1 >= 0) {
        if (g_grid[i - 1][j] != 0 && grid_index[i - 1][j] == -1) {
            pin(i - 1, j);
        }
    }
    // 下面一个
    if (i + 1 < g_grid.size()) {
        if (g_grid[i + 1][j] != 0 && grid_index[i + 1][j] == -1) {
            pin(i + 1, j);
        }
    }
    // 左面一个
    if (j - 1 >= 0) {
        if (g_grid[i][j - 1] != 0 && grid_index[i][j - 1] == -1) {
            pin(i, j - 1);
        }
    }
    // 后面一个
    if (j + 1 < grid_index[i].size()) {
        if (g_grid[i][j + 1] != 0 && grid_index[i][j + 1] == -1) {
            pin(i, j + 1);
        }
    }
}

int LeetCodes::countIslands(vector<vector<int>>& grid, int k) {
    grid_index = grid;
    g_grid = grid;
    // copy 一份 grid 都赋值为 -1
    for (auto& i : grid_index) {
        for (auto& j : i) {
            j = -1;
        }
    }

    // 遍历原始的grid
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            // pin(grid_index, grid, i, j);
            // 判断当前grid是否是陆地 grid_index是否是 -1
            // 跳过已经判断过，就是grid_index不是 -1 的，那些已经在递归中绑定好了
            if (grid[i][j] != 0 && grid_index[i][j] == -1) {
                // 进入递归
                pin(i, j);
                // 结束
                g_index++;
            }
        }
    }
    int ans = 0;
    for (auto it : g_map) {
        if (it.second % k == 0)
            ans++;
    }
    return ans;
}