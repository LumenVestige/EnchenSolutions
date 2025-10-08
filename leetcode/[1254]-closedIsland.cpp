#include <bits/stdc++.h>
using namespace std;

int closedIsland(vector<vector<int>>& grid) {
    int DIRS[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    vector<vector<int>> cnt(grid.size(), vector<int>(grid[0].size(), 0));
    function<bool(int ,int)> dfs = [&](int x, int y)-> bool {
        // 标记当前为已经查找
        cnt[x][y] = 1;
        bool isOut = false;
        if (x == 0 || y == 0 || x == grid.size() - 1 || y == grid[0].size() - 1) isOut = true;
        for (auto& [mx, my] : DIRS) {
            int i = mx + x, j = my + y;
            if (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && cnt[i][j] == 0 && grid[i][j] == 0) {
                bool tmp = dfs(i, j);
                if (tmp) isOut = true;
            }
        }
        return isOut;
    };
    int ans = 0;
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
            if (grid[i][j] == 0 && cnt[i][j] == 0) 
                if (!dfs(i, j)) ans++;
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> grid = {{1,1,1,1,1,1,1,0},{1,0,0,0,0,1,1,0},{1,0,1,0,1,1,1,0},{1,0,0,0,0,1,0,1},{1,1,1,1,1,1,1,0}};
    cout << closedIsland(grid);
    return 0;
}