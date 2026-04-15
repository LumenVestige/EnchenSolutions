#include <bits/stdc++.h>
using namespace std;
#define pll pair<int, int>
int n;
vector<vector<char>> grids(2, vector<char>(1e6+1));
vector<vector<bool>> vis(2, vector<bool>(1e6+1, false));
pll checkEnd(int x, int y) {
    int DIRS[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    queue<pll> q;
    q.push({x, y});
    pll ans = {x, y};
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        vis[x][y] = true;
        for (auto [mx, my] : DIRS) {
            int i = mx + x, j = my + y;
            if (i >= 0 && j >= 0 && i < 2 && j < n && !vis[i][j] && grids[i][j] == '#') {
                q.push({i, j});
                if (j > ans.second) {
                    ans = {i, j};
                }
            }
        }
    }
    return ans;
}
int main() {
    string str1, str2;
    cin >> str1 >> str2;
    n = str1.size();
    int maxEnd = 0;
    for (int i = 0; i < n; ++i) {
        grids[0][i] = str1[i];
        grids[1][i] = str2[i];    
        if (grids[0][i] == '#' || grids[1][i] == '#') {
            maxEnd = max({i, maxEnd});
        }
    }
    int ans = 0;
    int i = 0;
    while (i <= maxEnd) {
        if (grids[0][i] == '#' || grids[1][i] == '#') {
            pll end = checkEnd(grids[1][i] == '#', i);
            if (end.second != maxEnd) {
                int x = end.first;
                int y = end.second;
                int cnt = 0;
                for (int j = y + 1; j <= maxEnd; ++j) {
                    grids[x][j] = '#';
                    cnt++;
                    // 如果下面或者右边是# 就停下来了
                    if (j + 1 < n && grids[x][j+1] == '#' || grids[x == 1][j] == '#') {
                        i = j;
                        ans += cnt;
                        break;
                    }
                }
            } else {
                break;
            }
        } else {
            i++;
        }
    }
    cout << ans;
    return 0;
}