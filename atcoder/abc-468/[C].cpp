#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int n;
    cin >> n;
    vector<int> n1(n), n2(n);
    for (int i = 0; i < n; ++i) {
        cin >> n1[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> n2[i];
    }
    vector<bool> mem(n+1, false);
    int ans = 0;

    auto dfs = [&](auto&& dfs, int z, vector<int> str)->void {
        if (z == n) {
            if (str > n1 && str < n2) ans++;
            return;
        }
        int res = 0;
        // 提取范围
        int a = n1[z], b = n2[z];
        for (int i = 1; i <= n; ++i) {
            if (!mem[i]) {
                mem[i] = true;
                vector<int> tmp = str;
                tmp.push_back(i);
                dfs(dfs, z+1, tmp);
                mem[i] = false;
            }
        }
    };
    vector<int> r;
    dfs(dfs, 0, r);
    cout << ans;
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