#include <bits/stdc++.h>
using namespace std;
int numEnclaves(vector<vector<int>>& grid) {
    int DIRS[4][2] = {{0,1}, {1, 0}, {-1, 0}, {0, -1}};
    int ans = 0;
    vector<vector<int>> cnt(grid.size(), vector<int>(grid[0].size(), 0)); // 没有被标记为0 标记过的为1
    function<pair<bool, int>(int, int)> dfs = [&](int x, int y)-> pair<bool, int> {
        // 标记当前
        cnt[x][y] = 1;
        bool canGo = false;
        // 判断当前这个是否是边界
        if (x == 0 || y == 0 || x == grid.size() - 1 || y == grid[0].size() - 1) 
            canGo = true;
        int area = 1;
        for (auto& [mx, my] : DIRS) {
            int i = mx + x, j = my + y;
            if (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && cnt[i][j] != 1 && grid[i][j] == 1) {
                auto res = dfs(i, j);
                area += res.second;
                if(res.first) canGo = true; 
            }
        }
        return {canGo, area};
    };
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
            if (grid[i][j] == 1 && cnt[i][j] != 1) {
                auto res = dfs(i, j);
                if (!res.first) 
                    ans += res.second;
            }
        }
    }
    return ans;
}
int main() {
    vector<vector<int>> grid = {{0,0,0,0},{1,0,1,0},{0,1,1,0},{0,0,0,0}};
    cout << numEnclaves(grid);
    return 0;
}