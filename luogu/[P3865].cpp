#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    int k = log2(n);
    vector<vector<int>> stMax(n, vector<int>(k+1, 0));
    // 初始化 ST 表
    for (int i = 0; i < n; ++i) {
        stMax[i][0] = nums[i];
    }
    for (int j = 1; j <= k; ++j) {
        for (int i = 0; i + (1 << j) - 1 < n; ++i) {
            stMax[i][j] = max(stMax[i][j-1], stMax[i+(1<<(j-1))][j-1]);
        }
    }
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        a--, b--;
        int m = log2(b-a+1);
        cout << max(stMax[a][m], stMax[b-(1<<m)+1][m]) << endl;
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