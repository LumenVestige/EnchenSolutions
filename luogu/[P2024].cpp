#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

struct UnionFind {
    vector<int> par;
    UnionFind(int x) : par(x+1) {
        for (int i = 1; i <= x; ++i) {
            par[i] = i;
        }
    }
    int find(int x) {
        while (x != par[x]) {
            par[x] = par[par[x]];
            x = par[x];
        }
        return x;
    }
    bool merge(int x, int y) {
        int rootX = find(x), rootY = find(y);
        if (rootX != rootY) {
            par[rootX] = par[rootY];
            return true;
        }
        return false;
    }
    bool isMerged(int x, int y) {
        return find(x) == find(y);
    }
};

void solve() {
    int n, k;
    cin >> n >> k;
    int ans = 0;
    UnionFind uf(3*n);
    // [1, n] 为同类域
    // [n + 1, 2n] 为捕食域（i 吃的物种）
    // [2n + 1, 3n] 为天敌域（吃 i 的物种）
    while (k--) {
        int op, x, y;
        cin >> op >> x >> y;
        if (x > n || y > n) {
            ans++;
            continue;
        }
        if (op == 1) {
            // x和y是同类
            if (uf.isMerged(x, y+n) || uf.isMerged(x, y+2*n) ) {
                ans++;
            } else {
                uf.merge(x, y);
                uf.merge(x+n, y+n);
                uf.merge(x+2*n, y+2*n);
            }
        } else {
            // x吃y
            if (uf.isMerged(x, y) || uf.isMerged(x, y+n)) {
                ans++;
            } else {
                uf.merge(x+n, y);
                uf.merge(x, y+2*n);
                uf.merge(x+2*n, y+n);
            }
        }
    }
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