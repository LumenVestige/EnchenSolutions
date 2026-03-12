#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int MOD = 1e9+7;
int qpow(int x, int n) {
    int res = 1;
    while (n > 0) {
        if (n & 1) {
            res = res * x % MOD;
        }
        x = x * x % MOD;
        n >>= 1;
    }
    return res;
}

int inv(int i) {
    return qpow(i, MOD-2);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    vector<vector<int>> conn(n+1);
    for (int i = 0; i < n-1; ++i) {
        int x, y;
        cin >> x >> y;
        conn[x].push_back(y);
        conn[y].push_back(x);
    }
    queue<int> q;
    auto dfs = [&](auto&& dfs, int fa, int cur, int p)->void {
        int d = conn[cur].size();
        q.push(p%MOD);
        for (auto c : conn[cur]) {
            if (c == fa) {
                continue;
            }
            dfs(dfs, cur, c, p*inv(d)%MOD);
        }
    };
    dfs(dfs, 0, 1, 1);
    int ans = 0;
    while (!q.empty()) {
        ans = (ans + q.front()) % MOD;
        q.pop();
    }
    cout << ans % MOD;
    return 0;
}