#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define endl "\n"
void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> g(n+1, vector<int>(m+1, 0));
    vector<pair<int, array<int, 2>>> bug;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> g[i][j];
            bug.push_back({g[i][j], {i, j}});
        }
    }
    sort(bug.begin(), bug.end(), [&](pair<int, array<int, 2>>&a , pair<int, array<int, 2>>& b) {
        return a.first > b.first;
    });
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    int DIRS[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    for (auto& z : bug) {
        auto [x, y] = z.second;
        bool flag = false;
        for (auto [mx, my] : DIRS) {
            int i = mx + x, j = my + y;
            if (i >= 0 && j >= 0 && i < n && j < m) {
                if (dp[i][j] == 0 && g[i][j] > g[x][y]) {
                    flag = true;
                }
            }
        }
        dp[x][y] = flag; 
    }
    while (q--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        if (dp[a][b]) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}