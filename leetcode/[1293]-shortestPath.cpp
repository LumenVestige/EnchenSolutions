//
// Created by sanenchen on 25-10-7.
//
#include <bits/stdc++.h>
using namespace std;

int shortestPath(vector<vector<int>> &grid, int k) {
    int DIRS[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    queue<vector<int>> q;
    vector<vector<int>> cnt(grid.size(), vector<int>(grid[0].size(), -1));
    if (grid[0][0] == 1) {
        q.push({0, 0, 1});
        cnt[0][0] = 1;
    } else {
        q.push({0, 0, 0});
        cnt[0][0] = 0;
    }

    int steps = 0;
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            int x = q.front()[0], y = q.front()[1], z = q.front()[2];
            q.pop();
            if (x == grid.size() - 1 && y == grid[0].size() - 1) {
                return steps;
            }
            for (auto &[mx, my] : DIRS) {
                int i = mx + x, j = my + y;
                if (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size()) {
                    int newZ = z + grid[i][j];
                    if (newZ <= k && (cnt[i][j] == -1 || newZ < cnt[i][j])) {
                        q.push({i, j, newZ});
                        cnt[i][j] = newZ;
                    }
                }
            }
        }
        steps++;
    }
    return -1;
}

int main() {
    vector<vector<int>> grid = {{0, 0, 0}, {1, 1, 0}, {0, 0, 0}, {0, 1, 1}, {0, 0, 0}};
    cout << shortestPath(grid, 1);
    return 0;
}