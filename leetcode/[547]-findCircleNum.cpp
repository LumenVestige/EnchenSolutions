//
// Created by sanenchen on 25-10-16.
//
#include <bits/stdc++.h>
using namespace std;

class Dsu {
private:
    vector<int> parent;
    int size = 0;
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
        this->size = n;
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    void union_(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) {
            return;
        }
        size--;
        parent[rootX] = rootY;
    }

    int count() {
        return size;
    }
};

int findCircleNum(vector<vector<int>>& isConnected) {
    auto dsu = Dsu(isConnected.size());
    for (int i = 0; i < isConnected.size(); ++i) {
        for (int j = 0; j < isConnected.size(); ++j) {
            if (isConnected[i][j]) {
                dsu.union_(i, j);
            }
        }
    }
    return dsu.count();
}
int main() {
    vector<vector<int>> isConnected = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    cout << findCircleNum(isConnected);
    return 0;
}