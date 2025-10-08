//
// Created by sanenchen on 25-10-1.
//
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    vector<vector<int>> cnt(heights.size(), vector<int>(heights[0].size(), 0));
    int DIRS[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    function<pair<bool,bool>(int, int)> dfs = [&](int x, int y) -> pair<int, int> {
        cnt[x][y] = 1;
        bool toPac = false, toAtl = false;
        // 判断当前是否处于Pac边界
        if (y == 0 || x == 0) toPac = true;
        if (x == heights.size() - 1 || y == heights[0].size() - 1) toAtl = true;
        for (auto& [mx, my] : DIRS) {
            int i = mx + x, j = my + y;
            if (i >= 0 && i < heights.size() && j >= 0 && j < heights[0].size() && !cnt[i][j] && heights[i][j] <= heights[x][y]) {
                auto res = dfs(i, j);
                if (res.first) toPac = true;
                if (res.second) toAtl = true;
            }
        }
        return {toPac, toAtl};
    };
    vector<vector<int>> ans;
    for (int i = 0; i < heights.size(); ++i) {
        for (int j = 0; j < heights[0].size(); ++j) {
            auto tmp = dfs(i, j);
            if (tmp.first && tmp.second) {
                ans.push_back({i, j});
            }
            cnt.assign(cnt.size(), vector<int>(cnt[0].size(), 0));
        }
    }
    return ans;
}
int main() {
    vector<vector<int>> heights = {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
    for (auto& i : pacificAtlantic(heights)) {
        for (auto& j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}