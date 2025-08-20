//
// Created by sanenchen on 25-8-19.
//
#include <bits/stdc++.h>

using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int> > nums(n + 1, vector<int>(m + 1, 0)), diff(n + 2, vector<int>(m + 2, 0));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> nums[i][j];
    // 构建差分数组
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            diff[i][j] += nums[i][j];
            diff[i + 1][j] -= nums[i][j];
            diff[i][j + 1] -= nums[i][j];
            diff[i + 1][j + 1] += nums[i][j];
        }
    // 操作
    while (q--) {
        int x1, y1, x2, y2, c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        diff[x1][y1] += c;
        diff[x1][y2 + 1] -= c;
        diff[x2 + 1][y1] -= c;
        diff[x2 + 1][y2 + 1] += c;
    }
    // 数组还原 也就是求出前缀和
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            nums[i][j] = diff[i][j] + nums[i - 1][j] + nums[i][j - 1] - nums[i - 1][j - 1];
            cout << nums[i][j] << " ";
        }
        cout << "\n";
    }


    return 0;
}
