#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int MOD = 998244353;
void solve() {
    string n;
    cin >> n;
    // vector<vector<vector<int>>> memo(n.size() + 1, vector<vector<int>>(3, vector<int>(1024, -1)));
    int memo[n.size()+1][3][1024];
    memset(memo, -1, sizeof(memo));
    // pos rem mask
    auto dfs = [&](auto&& dfs, int pos, int rem, int mask, bool isLimit, bool isHead)->int {
        int r = 0;
        if (pos == n.size()) {
            if (isHead) return 0;
            int a = rem == 0;
            int b = __builtin_popcount(mask) == 3;
            int c = (mask & (1 << 3)) != 0;
            if (a + b +c == 1) {
                // cout << rem << " " << __builtin_popcount(mask) << endl;
                return 1;
            }
            return 0;
        }
        if (!isLimit && !isHead && memo[pos][rem][mask] != -1) {
            return memo[pos][rem][mask];
        }
        int up = (isLimit) ? n[pos]-'0' : 9;
        for (int i = 0; i <= up; ++i) {
            // 选中i
            int maskNew = mask, remNew = rem;
            if (!(isHead && i==0)) {
                maskNew = mask | (1 << i);
                remNew = (rem + i) % 3;
            }
            r = r + dfs(dfs, pos+1, remNew, maskNew, isLimit & (i==up), isHead && (i == 0)) % MOD;
            r %= MOD;
        }
        memo[pos][rem][mask] = r;
        return r;
    };
    cout << dfs(dfs, 0, 0, 0, 1, 1);
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