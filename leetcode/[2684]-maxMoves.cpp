#include <bits/stdc++.h>
using namespace std;
int maxMoves(vector<vector<int>>& grid) {
    int DIRS[3][2] = {{-1, 1}, {0, 1}, {1, 1}};
    unordered_map<string, int> cnt;
    function<int(int, int)> dfs = [&](int x, int y)-> int {
        // 转换
        string p = to_string(x) + "-" + to_string(y);
        if (cnt.count(p)) return cnt[p];
        int area = 0;
        bool flag = false;
        int tmp = 0;
        for (auto& [mx, my] : DIRS) {
            int i = mx + x, j = my + y;
            if (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] > grid[x][y]) {
                tmp = max(tmp, dfs(i, j));
                flag = true;
            }
        }
        if (flag) {
            area += tmp;
            area++;
        }
        cnt[p] = area;
        return area;
    };
    int ans = 0;
    for (int j = 0; j < grid.size(); ++j) {
        ans = max(ans, dfs(j, 0));
    }
    return ans;
}
int main() {
    vector<vector<int>> grid = {{3,2,4},{2,1,9},{1,1,7}};
    cout << maxMoves(grid);
    return 0;
}