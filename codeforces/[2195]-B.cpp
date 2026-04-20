#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
struct UnionFind {
    vector<int> par;
    int size;
    UnionFind(int n) : size(n) {
        par.resize(n+1);
        for (int i = 0; i <= n; ++i) {
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
    bool connected(int x, int y) {
        int rootX = find(x), rootY = find(y);
        return rootX == rootY;
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
void solve() {
    int n;
    cin >> n;
    vector<int> nums(n+1);
    UnionFind uf(n);
    
    for (int i = 1; i <= n; ++i) {
        cin >> nums[i];
        if (i>=1 && i <= n/2) {
            uf.connect(i, 2*i);
        }
        
    }
    // 把 块 拉出来
    // unordered_map<int, vector<int>> umap;
    // for (int i = 1; i <= n; ++i) {
    //     umap[uf.find(i)].push_back(nums[i]);
    // }
    for (int i = 1; i <= n; ++i) {
        if (!uf.connected(i, nums[i])) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES"<< endl;

}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}