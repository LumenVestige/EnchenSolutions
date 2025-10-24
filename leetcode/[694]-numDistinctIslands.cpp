#include <bits/stdc++.h>
using namespace std;

int numDistinctIslands(vector<vector<int>>& grid) {
    const int DIRS[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    unordered_set<string> visPath;
    function<string(int, int)> dfs = [&](int x, int y) -> string {
        string tmp = "";
        grid[x][y] = 0;
        for (int k = 0; k < 4; ++k) {
            int i = DIRS[k][0] + x, j = DIRS[k][1] + y;
            char b = '0';
            if (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] != 0) {
                b++;
            }
            tmp += b;
        }
        for (int k = 0; k < 4; ++k) {
            int i = DIRS[k][0] + x, j = DIRS[k][1] + y;
            char b = '0';
            if (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] != 0) {
                tmp += b++;
                tmp += k + '0';
                tmp += dfs(i, j);
            }
        }
        return tmp;
    };
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
            if (grid[i][j]) {
                visPath.insert(dfs(i, j));
            }
        }
    }
    return visPath.size();
}

int main() {
    vector<vector<int>> grid = {
    {1, 1, 0},
    {0, 1, 1},
    {0, 0, 0},
    {1, 1, 1},
    {0, 1, 0}
    };
    cout << numDistinctIslands(grid);
    return 0;
}