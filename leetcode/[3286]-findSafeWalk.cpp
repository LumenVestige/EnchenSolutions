#include <bits/stdc++.h>
using namespace std;

bool findSafeWalk(vector<vector<int>>& grid, int health) {
    int DIRS[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    vector<vector<int>> cnt = {grid.size(), vector<int>(grid[0].size(), -1)};
    queue<vector<int>> q;
    int firstHealth = grid[0][0];
    q.push({0, 0, firstHealth});
    cnt[0][0] = firstHealth;
    while (!q.empty()) {
        int x = q.front()[0], y = q.front()[1], z = q.front()[2];
        q.pop();
        for (auto& [mx, my] : DIRS) {
            int i = mx + x, j = my + y;
            if (x == grid.size() - 1 && y == grid[0].size() - 1)
                return true;
            if (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size()) {
                int mz = z + grid[i][j];
                if ((cnt[i][j] == -1 || mz < cnt[i][j]) && mz < health) {
                    q.push({i, j, mz});
                    cnt[i][j] = mz;
                }
            }
        }
    }
    return false;
}

int main() {
    vector<vector<int>> grid = {{0, 1, 1, 0, 0, 0}, {1,0,1,0,0,0}, {0,1,1,1,0,1}, {0,0,1,0,1,0}};
    cout << findSafeWalk(grid, 3);
    return 0;
}