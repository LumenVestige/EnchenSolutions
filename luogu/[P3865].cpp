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
    vector<vector<int>> stMax(n+1, vector<int>(k+1, 0));
    for (int i = 0; i < n; ++i) {
        stMax[i][0] = nums[i];
    }
    for (int j = 1; j <= k; ++j) {
        for (int i = 0; i + (1 << j) - 1 < n; ++i) {
            stMax[i][j] = max(stMax[i][j-1], stMax[i+(1<<(j-1))][j-1]);
        }
    }
    auto getMax = [&](int l, int r) {
        int s = log2(r - l + 1);
        return max(stMax[l][s], stMax[r-(1<<s)+1][s]);
    };
    while (m--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        cout << getMax(l, r) << endl;
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