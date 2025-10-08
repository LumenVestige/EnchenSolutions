//
// Created by sanenchen on 25-10-3.
//
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    vector<vector<int>> cnt(mat.size(), vector<int>(mat[0].size(), -1));
    int DIRS[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    queue<pair<int, int>> q;
    for (int i = 0; i < mat.size(); ++i) {
        for (int j = 0; j < mat[0].size(); ++j) {
            if (mat[i][j] == 0) {
                cnt[i][j] = 0;
                q.emplace(i, j);
            }
        }
    }
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (auto& [mx, my] : DIRS) {
            int i = mx + x, j = my + y;
            if (i >= 0 && i < mat.size() && j >= 0 && j < mat[0].size() && cnt[i][j] == -1) {
                cnt[i][j] = cnt[x][y] + 1;
                q.emplace(i, j);
            }
        }
    }
    return cnt;
}
int main() {
    vector<vector<int>> mat = {{0,0,0},{0,1,0},{1,1,1}};
    for (auto& i : updateMatrix(mat)) {
        for (auto& j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}