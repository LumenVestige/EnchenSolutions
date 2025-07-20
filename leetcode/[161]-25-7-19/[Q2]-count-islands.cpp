//
// Created by sanenchen on 25-7-19.
//
#include "../LeetCodes.h"
int LeetCodes::countIslands(vector<vector<int>>& grid, int k) {
    // 思路 遍历每一个数，遇到非0的，就要看看他的上下左右怎么样，如果啥都没有，就新建一个
    int index = 0;
    vector grid_index(grid);
    unordered_map<int, int> map;
    // copy 一份 grid 都赋值为 0
    for (auto& i : grid_index) {
        for (auto& j : i) {
            j = -1;
        }
    }
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] != 0) {
                // 说明不是0，是有值了，那么就要看看他的上下左右怎么样了
                // 找到了就撤退
                int flag = 0;
                // 如果检测到多个flag 则意味着这里出现问题了，要撤销上一个index
                // 上面一个:
                if (i - 1 >= 0) {
                    if (grid_index[i - 1][j] != -1) {
                        map[grid_index[i - 1][j]] += grid[i][j];
                        grid_index[i][j] = grid_index[i - 1][j];
                        grid[i][j] = 0;
                        continue;
                    }
                }
                // 下面一个
                if (i + 1 < grid.size()) {
                    if (grid_index[i + 1][j] != -1) {
                        map[grid_index[i + 1][j]] += grid[i][j];
                        grid_index[i][j] = grid_index[i + 1][j];
                        grid[i][j] = 0;
                        continue;
                    }

                }
                // 左面一个
                if (j - 1 >= 0) {
                    if (grid_index[i][j - 1] != -1) {
                        map[grid_index[i][j - 1]] += grid[i][j];
                        grid_index[i][j] = grid_index[i][j - 1];
                        grid[i][j] = 0;
                        continue;
                    }
                }
                // 后面一个
                if (j + 1 < grid.size()) {
                    if (grid_index[i][j + 1] != -1) {
                        map[grid_index[i][j + 1]] += grid[i][j];
                        grid_index[i][j] = grid_index[i][j + 1];
                        grid[i][j] = 0;
                        continue;
                    }
                }
                // 到这里说明这是个孤独的岛屿。。。
                // 创建新的岛屿
                map[index] += grid[i][j];
                grid_index[i][j] = index;
                index++;
                // 搞完了，要主动联系相关岛屿，看看他们附近是否有没录上去的岛屿，有的话就带进去
                // 上面一个:
                if (i - 1 >= 0) {
                    if (grid[i - 1][j] != 0) {
                        map[grid_index[i - 1][j]] += grid[i][j];
                        grid_index[i][j] = grid_index[i - 1][j];
                        grid[i - 1][j] = 0;
                    }
                }
                // 下面一个
                if (i + 1 < grid.size()) {
                    if (grid[i + 1][j] != 0) {
                        map[grid_index[i + 1][j]] += grid[i][j];
                        grid_index[i][j] = grid_index[i + 1][j];
                        grid[i + 1][j] = 0;
                    }

                }
                // 左面一个
                if (j - 1 >= 0) {
                    if (grid[i][j - 1] != 0) {
                        map[grid_index[i][j - 1]] += grid[i][j];
                        grid_index[i][j] = grid_index[i][j - 1];
                        grid[i][j - 1] = 0;
                    }
                }
                // 后面一个
                if (j + 1 < grid.size()) {
                    if (grid[i][j + 1] != 0) {
                        map[grid_index[i][j + 1]] += grid[i][j];
                        grid_index[i][j] = grid_index[i][j + 1];
                        grid[i][j + 1] = 0;
                    }
                }
            }
        }
    }

    for (auto it : map) {
        cout << it.second << " ";
    }
    return 0;
}