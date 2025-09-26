#include <bits/stdc++.h>
using namespace std;
int findMaxFish(vector<vector<int>>& grid) {
    int DIRS[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    function<int (int, int)> dfs = [&](int x, int y)->int {
        int tmp = grid[x][y];
        grid[x][y] = 0;
        for (auto& [mx, my] : DIRS) {
            int i = mx + x, j = my + y;
            if (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] != 0) {
                tmp += dfs(i, j);
            }
        }
        return tmp;
    };
    int ans = 0;
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
            if (grid[i][j]) {
                ans = max(ans, dfs(i, j));
            }
        }
    }
    return ans;
}
int main() {
    vector<vector<int>> grid = {{0,2,1,0},{4,0,0,3},{1,0,0,4},{0,3,2,0}};
    cout << findMaxFish(grid);
    return 0;
}