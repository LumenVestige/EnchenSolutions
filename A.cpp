//
// Created by sanenchen on 2026/07/13.
//
// 2328. Number of Increasing Paths in a Grid
// https://leetcode.cn/problems/number-of-increasing-paths-in-a-grid/

#include <bits/stdc++.h>
using namespace std;

int countPaths(vector<vector<int>>& grid) {
    // TODO
}

int main() {
    // 改这个数字切换官方样例：1 .. 2
    const int CASE = 1;

    vector<vector<int>> grid;
    if (CASE == 1) {
        grid = {{1, 1}, {3, 4}};
    }
    else {
        grid = {{1}, {2}};
    }

    cout << countPaths(grid) << endl;
    return 0;
}
