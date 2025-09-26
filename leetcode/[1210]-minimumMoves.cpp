//
// Created by sanenchen on 25-9-25.
//
#include <bits/stdc++.h>
using namespace std;
// 高端的bfs。。。能力不够 下一题
int minimumMoves(vector<vector<int>> &grid) {
    // 使用dfs操作
    bool alreadyFound = false;
    int times = INT_MAX;
    function<bool(pair<int, int>, int)> dfs = [&](pair<int, int> pos, int time) -> bool {
        // 判断结束标志
        if ((pos.first == grid.size() - 1 && pos.second == grid.size() - 1)) {
            // alreadyFound = true; = true;
            times = min(time, times);
            return true;
        }
        // 向右查询
        if (pos.second + 1 < grid.size() && grid[pos.first][pos.second + 1] != 1) {
            alreadyFound = dfs({pos.first, pos.second + 1}, time + 1);
        }
        // 向下查询
        if (pos.first + 1 < grid.size() && grid[pos.first + 1][pos.second] != 1) {
            alreadyFound = dfs({pos.first + 1, pos.second}, time + 1);
        }
        return alreadyFound;
    };
    auto ans = dfs({0, 0}, 0);
    if (ans) {
        return times + 1;
    } else
        return -1;
}
int main() {
    vector<vector<int>> grid = {{0, 0, 0, 0, 0, 1}, {1, 1, 0, 0, 1, 0}, {0, 0, 0, 0, 1, 1},
                                {0, 0, 1, 0, 1, 0}, {0, 1, 1, 0, 0, 0}, {0, 1, 1, 0, 0, 0}};
    cout << minimumMoves(grid);
    return 0;
}