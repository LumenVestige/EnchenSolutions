#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

struct UnionFind {
    vector<int> par;
    int size;
    UnionFind(int n) : size(n) {
        par.resize(n+1);
        for (int i = 1; i <= n; ++i) {
            par[i] = i;
        }
    }
    int find(int x) {
        while (par[x] != x) {
            par[x] = par[par[x]];
            x = par[x];
        }
        return par[x];
    }
    bool connect(int x, int y) {
        int rootX = find(x), rootY = find(y);
        if (rootX == rootY) {
            return false;
        }
        par[rootX] = rootY;
        size--;
        return true;
    }
};
int MOD = 998244353;
int qpow(int a, int n) {
    int res = 1;
    while (n > 0) {
        if (n & 1) {
            res = res * a % MOD;
        }
        a = a * a % MOD;
        n >>= 1;
    }
    return res;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, z;
    cin >> n >> z;
    UnionFind uf(n);
    while (z--) {
        int x, y;
        cin >> x >> y;
        uf.connect(x, y);
    }
    int size = uf.size;
    cout << qpow(26, size);
    return 0;
}