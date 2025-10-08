//
// Created by sanenchen on 25-10-3.
//
#include <bits/stdc++.h>
using namespace std;
int shortestPathBinaryMatrix(vector<vector<int>> &grid) {
    int DIRS[8][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};
    queue<pair<int, int>> q;
    q.emplace(0, 0);
    if (grid[0][0] == 0)
        grid[0][0] = 1;
    else return -1;
    int steps = 1;
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            auto [x, y] = q.front();
            q.pop();
            if (x == grid.size() - 1 && y == grid[0].size() - 1)
                return steps;
            for (auto &[mx, my] : DIRS) {
                int i = mx + x, j = my + y;
                if (i >= 0 && i < grid.size() && i >= 0 && j < grid[0].size() && grid[i][j] == 0) {
                    q.emplace(i, j);
                    grid[i][j] = 1;
                }
            }
        }
        steps++;
    }
    return -1;
}
int main() {
    vector<vector<int>> grid = {{1, 0, 0}, {1, 1, 0}, {1, 1, 0}};
    cout << shortestPathBinaryMatrix(grid);
    return 0;
}