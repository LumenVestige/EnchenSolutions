#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
    vector<vector<int>> cnt(grid.size(), vector<int>(grid[0].size(), 0));
    int DIRS[4][2] = {{0,1}, {1, 0}, {-1, 0}, {0,-1}};
    int origin = grid[row][col];
    function<void(int, int)> dfs = [&](int x, int y) {
        // 染色判断
        cnt[x][y] = 1;
        int flag = false;
        for (auto& [mx, my] : DIRS) {
            int i = mx + x, j = my + y;
            if (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] != origin && cnt[i][j] == 0) 
                flag = true;
        }
        if (x == 0 || y == 0 || x == grid.size() - 1 || y == grid[0].size() - 1) flag = true;
        if (flag == true) {
            grid[x][y] = color;
        }
        for (auto& [mx, my] : DIRS) {
            int i = mx + x, j = my + y;
            if (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] == origin && cnt[i][j] == 0) {
                dfs(i, j);
            }
        }
    };
    dfs(row, col);
    return grid;
}
int main() {
    vector<vector<int>> grid = {{1,1,1}, {1,1,1}, {1,1,1}};
    for (auto& i : colorBorder(grid, 0, 0, 3)) {
        for (auto& j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}