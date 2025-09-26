#include <bits/stdc++.h>
using namespace std;
int islandPerimeter(vector<vector<int>>& grid) {
    int DIRS[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int needDelete = 0;
    function<int(int, int)> dfs = [&](int x, int y)->int {
        int round = 4;
        grid[x][y] = 0;
        for (auto& [mx, my] : DIRS) {
            int i = mx + x, j = my + y;
            if (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j]) {
                needDelete++;
            }
        }
        for (auto& [mx, my] : DIRS) {
            int i = mx + x, j = my + y;
            if (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j]) {
                round += dfs(i, j);
            }
        }
        return round;
    };
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
            if (grid[i][j]) {
                return dfs(i, j) - 2 * needDelete;
            }
        }
    }
    return 0;
}
int main() {
    vector<vector<int>> grid = {{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}};
    cout << islandPerimeter(grid);
    return 0;
}