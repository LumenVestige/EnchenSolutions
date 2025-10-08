//
// Created by sanenchen on 25-9-30.
//
#include <bits/stdc++.h>
using namespace std;
int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
    // 也就是说 第二个每一个区块，都要在第一块上有所对应
    int DIRS[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    vector<vector<int>> cnt(grid2.size(), vector<int>(grid2[0].size(), 0));
    function<bool(int, int)> dfs = [&](int x, int y)-> bool {
        cnt[x][y] = 1;
        bool bothHad = false;
        if (grid1[x][y]) bothHad = true;
        for (auto& [mx, my] : DIRS) {
            int i = mx + x, j = my + y;
            if (i >= 0 && i < grid2.size() && j >= 0 && j < grid2[0].size() && cnt[i][j] == 0 && grid2[i][j]) {
                if (!dfs(i, j)) {
                    bothHad = false;
                }
            }
        }
        return bothHad;
    };
    int ans = 0;
    for (int i = 0; i < grid2.size(); ++i) {
        for (int j = 0; j < grid2[0].size(); ++j) {
            if (cnt[i][j] == 0 && grid2[i][j]) {
                if (dfs(i, j))
                    ans++;
            }
        }
    }
    return ans;
}
int main() {
    vector<vector<int>> grid1 = {{1,1,1,0,0},{0,1,1,1,1},{0,0,0,0,0},{1,0,0,0,0},{1,1,0,1,1}};
    vector<vector<int>> grid2 = {{1,1,1,0,0},{0,0,1,1,1},{0,1,0,0,0},{1,0,1,1,0},{0,1,0,1,0}};
    cout << countSubIslands(grid1, grid2);
    return 0;
}