#include <bits/stdc++.h>
using namespace std;
// 关键词：仅仅向右，向下
// Leetcode 3742
int maxPathScore(vector<vector<int>>& grid, int k) {
    vector<vector<vector<int>>> memo (grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(k + 1, -1)));
    function<int(int, int, int)> dfs = [&](int x, int y, int k) {
        if (x < 0 || y < 0 || k < 0) {
            return INT_MIN;
        }
        if (x == 0 && y == 0) {
            return 0;
        }
        auto& res = memo[x][y][k];
        if (res != -1) {
            return res;
        }
        int m = grid[x][y];
        if (m != 0) {
            k--;
        }
        res = max(dfs(x - 1, y, k), dfs(x, y - 1, k)) + m;
        return res;
    };
    int ans = dfs(grid.size() - 1, grid[0].size() - 1, k);
    return ans < 0 ? -1 : ans;
}

int main() {
    vector<vector<int>> nums = {{0, 1}, {2, 0}};
    cout << maxPathScore(nums, 1);
    return 0;
}