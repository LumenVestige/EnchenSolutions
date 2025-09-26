//
// Created by sanenchen on 25-9-26.
//
#include <bits/stdc++.h>
using namespace std;
vector<int> pondSizes(vector<vector<int>>& land) {
    int DIRS[8][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {-1, 1}, {1, -1}, {1, 1}, {-1, -1}};
    function<int(int, int)> dfs = [&](int x, int y) -> int {
        // 标记当前这一个为非0
        land[x][y] = 1;
        int area = 1;
        for (auto& [mx, my] : DIRS) {
            int i = x + mx, j = y + my;
            if (i >= 0 && i < land.size() && j >= 0 && j < land[0].size() && land[i][j] == 0) {
                area += dfs(i, j);
            }
        }
        return area;
    };
    vector<int> ans;
    for (int i = 0; i < land.size(); ++i) {
        for (int j = 0; j < land[0].size(); ++j) {
            if (land[i][j] == 0)
                ans.push_back(dfs(i, j));
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}
int main() {
    vector<vector<int>> land = {{0,2,1,0},{0,1,0,1},{1,1,0,1},{0,1,0,1}};
    for (auto& i : pondSizes(land)) {
        cout << i << " ";
    }
    return 0;
}