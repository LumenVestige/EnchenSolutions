//
// Created by sanenchen on 25-10-5.
//
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
    int DIRS[4][2] = {{0,1}, {1, 0}, {-1, 0}, {0, -1}};
    queue<pair<int, int>> q;
    vector<vector<int>> cnt(isWater.size(), vector<int>(isWater[0].size(), -1));
    for (int i = 0; i < isWater.size(); ++i) {
        for (int j = 0; j < isWater[0].size(); ++j) {
            if (isWater[i][j]) {
                cnt[i][j] = 0;
                q.emplace(i, j);
            }
        }
    }
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            auto [x, y] = q.front();
            q.pop();
            for (auto& [mx, my] : DIRS) {
                int i = mx + x, j = my + y;
                if (i >= 0 && i < isWater.size() && j >= 0 && j < isWater[0].size() && cnt[i][j] == -1) {
                    q.emplace(i, j);
                    cnt[i][j] = cnt[x][y] + 1;
                }
            }
        }
    }
    return cnt;
}
int main() {
    vector<vector<int>> isWater = {{0,1},{0,0}};
    for (auto& i : highestPeak(isWater)) {
        for (auto& j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}