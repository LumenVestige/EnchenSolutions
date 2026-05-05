#include <bits/stdc++.h>
using namespace std;
#define int long long
struct UnionFind {
    vector<int> par;
    UnionFind(int x) {
        par.resize(x+1);
        for (int i = 1; i <= x; ++ i) {
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
    bool connect(int x, int y) {
        int rootX = find(x), rootY = find(y);
        if (rootX == rootY) {
            return false;
        }
        par[rootX] = rootY;
        return true;
    }

};
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    string numFlag; cin >> numFlag;
    numFlag = " " + numFlag;
    UnionFind uf(n);
    vector<pair<int, int>> inner, cross, ans;
    while (m--) {
        int a, b;
        cin >> a >> b;
        bool uA = numFlag[a] == 'A' || numFlag[a] == 'B';
        bool uB = numFlag[b] == 'B' || numFlag[b] == 'A';
        if (uA == uB) {
            inner.push_back({a, b});
        } else {
            cross.push_back({a, b});
        }
    }
    // 优先去搞这个inner
    for (auto& [x, y]: inner) {
        if (uf.connect(x, y)) {
            ans.push_back({x, y});
        }
    }
    // 判断这个inner是否合法
    vector<bool> hasA(n+1), hasB(n+1), hasC(n+1), hasD(n+1);
    for (int i = 1; i <= n; ++i) {
        int root = uf.find(i);
        if (numFlag[root] == 'A' || numFlag[root] == 'B') {
            if (numFlag[i] == 'A') hasA[root] = true;
            if (numFlag[i] == 'B') hasB[root] = true;
        } else {
            if (numFlag[i] == 'C') hasC[root] = true;
            if (numFlag[i] == 'D') hasD[root] = true;
        }
    }
    // 校验
    for (int i = 1; i <= n; ++i) {
        int root = uf.find(i);
        if (numFlag[root] == 'A' || numFlag[root] == 'B') {
            if (!hasA[root] || !hasB[root]) {
                cout << "No";
                return 0;
            }
        } else {
            if (!hasC[root] || !hasD[root]) {
                cout << "No";
                return 0;
            }
        }
    }
    // cross 连接
    for (auto& [x, y] : cross) {
        if (uf.connect(x, y)) {
            ans.push_back({x,y});
        }
    }
    if (ans.size() < n-1) {
        cout << "No";
        return 0;
    }
    cout << "Yes" << endl;
    for (auto [x, y]:ans) {
        cout << x << " " << y << endl;
    }

    return 0;
}