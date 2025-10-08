//
// Created by sanenchen on 25-10-7.
//
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> highestRankedKItems(vector<vector<int>> &grid, vector<int> &pricing, vector<int> &start, int k) {
    vector<vector<int>> cnt(grid.size(), vector<int>(grid[0].size(), 0));
    int DIRS[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    queue<pair<int, int>> q;
    q.emplace(start[0], start[1]);
    cnt[start[0]][start[1]] = 1;
    int steps = 0;
    vector<vector<int>> ans;
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            auto [x, y] = q.front();
            q.pop();
            // 针对每个压入ans中 筛选
            if (grid[x][y] >= pricing[0] && grid[x][y] <= pricing[1]) {
                ans.push_back({steps, grid[x][y], x, y});
            }
            for (auto &[mx, my] : DIRS) {
                int i = mx + x, j = my + y;
                if (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && !cnt[i][j] && grid[i][j] != 0) {
                    q.emplace(i, j);
                    cnt[i][j] = 1;
                }
            }
        }
        steps++;
    }
    // 筛选 ans
    sort(ans.begin(), ans.end(), [](vector<int> &a, vector<int> &b) {
        if (a[0] < b[0])
            return a < b;
        if (a[1] < b[1])
            return a < b;
        if (a[2] < b[2])
            return a < b;
        if (a[3] < b[3])
            return a < b;
        return a < b;
    });
    vector<vector<int>> retAns;
    int t = k;
    if (ans.size() < k) {
        t = ans.size();
    }
    for (int i = 0; i < t; ++i) {
        retAns.push_back({ans[i][2], ans[i][3]});
    }
    return retAns;
}
int main() {
    vector<vector<int>> grid = {{1, 2, 0, 1}, {1, 3, 0, 1}, {0, 2, 5, 1}};
    vector<int> pricing = {2, 5};
    vector<int> start = {0, 0};
    for (auto &i : highestRankedKItems(grid, pricing, start, 3)) {
        for (auto &j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}