#include <bits/stdc++.h>
using namespace std;

class UnionFind {
private:
    int _count = 0;
    vector<int> parent;

int find(int x) {
    // 路径压缩
    // 沿途公用一个总头头
    while (parent[x] != x) {
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
    return x;
}

public:
    UnionFind(int n) {
        this->_count = n;
        parent = vector<int>(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    void union_(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) { // 已经是一个头头了
            return;
        }
        // 挂上去
        parent[rootX] = rootY;
        _count--;
    }

    int count() {
        return _count;
    }

};

int countComponents(int n, vector<vector<int>>& edges) {
    auto uf = UnionFind(5);
    for (auto& it : edges) {
        uf.union_(it[0], it[1]);
    }
    return uf.count();
}

int main() {
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {3,4 }};
    cout << countComponents(5, edges);
}