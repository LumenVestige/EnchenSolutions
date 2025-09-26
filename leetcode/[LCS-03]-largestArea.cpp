#include <bits/stdc++.h>
using namespace std;
int largestArea(vector<string>& grid) {
    int DIRS[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    // 遍历过的就标记为6
    char tmp = '6';
    function<pair<bool, int>(int, int)> dfs = [&](int x, int y) -> pair<bool, int> {
        // 0是不进入的
        tmp = grid[x][y];
        grid[x][y] = '6';
        bool isNearOutside = false; // 标记是否是与走廊相邻
        int area = 1;
        if (x == 0 || x == grid.size() - 1 || y == 0 || y == grid[0].size())
            isNearOutside = true;
        for (auto [mx, my] : DIRS) {
            int i = mx + x, j = my + y;
            // 判断是否是与走廊相邻
            if (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] == '0')
                isNearOutside = true;
            if (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] == tmp) {
                auto [check, areaNum] = dfs(i, j);
                if (check) isNearOutside = true;
                area += areaNum;
            }
        }
        return {isNearOutside, area};
    };
    int ans = 0;
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
            if (grid[i][j] != '0' && grid[i][j] != '6') {
                auto [check, area] = dfs(i, j);
                if (!check) ans = max(ans, area);
            }
        }
    }
    return ans;
}
int main() {
    vector<string> grid = {"110","231","221"};
    cout << largestArea(grid);
    return 0;
}