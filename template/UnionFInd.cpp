#include <bits/stdc++.h>
using namespace std;

class UnionFind {
private:
    vector<int> parent;
public:
    int cnt;
    UnionFind(int x) : cnt(x) {
        parent = vector<int>(x);
        for (int i = 0; i < x; ++i) {
            parent[i] = i;
        }
    }
    int find(int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
    bool connect(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) {
            return false;
        }
        // y 挂在 x 上
        parent[rootX] = parent[rootY];
        cnt--;
        return true;
    }
    bool connected(int x, int y) {
        return parent[x] == parent[y];
    }
};
// 并查集模板，LC.261 以图判树
bool validTree(int n, vector<vector<int>>& edges) {
    UnionFind unionFind(n);
    for (auto& i : edges) {
        int lL = unionFind.find(i[0]);
        int lR = unionFind.find(i[1]);
        if (lR == i[0] && lL == i[1]) {
            return false;
        }
        if (!unionFind.connect(i[0], i[1])) {
            return false;
        }
    }
    if (unionFind.cnt != 1) return false;
    return true;
}

int main() {
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {1, 3}, {1, 4}};
    cout << validTree(5, edges);
    return 0;
}