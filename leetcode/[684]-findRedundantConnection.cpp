#include <bits/stdc++.h>
using namespace std;

class Dsu{
private:
    vector<int> parent;
    int find(int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
public:
    Dsu(int n) {
        parent = vector<int>(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }
    void connect(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) {
            return;
        }
        parent[rootX] = rootY;
    }
    bool isConnected(int x, int y) {
        return find(x) == find(y);
    }
};

vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n = edges.size();
    for (int i = n - 1; i >= 0; --i) {
        // 删掉第n个是否可行
        // 是否可行的判断标准：构建的过程中，必须两个不是同属关系
        bool hasBreak = false;
        auto dsu = Dsu(n + 1);
        for (int j = 0; j < n; ++j) {
            if (j != i) {
                auto current = edges[j];
                if (dsu.isConnected(current[0], current[1])) {
                    hasBreak = true;
                    break;
                }
                dsu.connect(current[0], current[1]);
            }
        }
        if (!hasBreak) {
            return edges[i];
        }
    }
    return {};
}

int main() {
    vector<vector<int>> edges = {{1,2}, {2, 3}, {3, 4}, {1, 4}, {1,5}};
    for (auto& i : findRedundantConnection(edges)) {
        cout << i << " ";
    }
    return 0;
}