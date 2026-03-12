#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

class UnionFind {
 private:
    int size;
    unordered_map<int, int> parent;
    int find(int x) {
        while(x != parent[x]) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
 public:
    UnionFind(int n) : size(n) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    bool connect(int x, int y) {
        int rootX = find(x), rootY = find(y);
        if (rootX == rootY) {
            return false;
        }
        parent[rootX] = rootY;
        size--;
        return true;
    }
    int getSize() {
        return size;
    }
};

signed main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<array<int, 3>> cons(m);
    for (int i = 0; i < m; ++i) {
        cin >> cons[i][0] >> cons[i][1] >> cons[i][2];
    }
    // 构建UnionFInd
    UnionFind uf(n);
    sort(cons.begin(), cons.end(), [](const array<int, 3>& a, const array<int, 3>& b) {
        return a[2] < b[2];
    });
    if (uf.getSize() == k) {
        cout << 0;
        return 0;
    }
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        if (uf.connect(cons[i][0], cons[i][1])) {
            ans += cons[i][2];
        };
        if (uf.getSize() == k) {
            cout << ans;
            return 0;
        }
    }
    cout << "No Answer";
    return 0;
}