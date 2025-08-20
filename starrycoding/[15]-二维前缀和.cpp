//
// Created by sanenchen on 25-8-18.
//

// 二维前缀和模版
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m ,q;
    cin >> n >> m >> q;
    vector<vector<int>> nums(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; j++)
            cin >> nums[i][j];

    vector<vector<int> > prefix = nums;
    // 构建前缀和数组
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; j++)
            prefix[i][j] = nums[i][j] + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
    while (q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        // 查询结果 22 12 21 11
        cout << prefix[x2][y2] - prefix[x1 - 1][y2] - prefix[x2][y1 - 1] + prefix[x1 - 1][y1 - 1] << '\n';
    }
    return 0;
}