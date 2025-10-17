//
// Created by sanenchen on 25-10-17.
//
#include <bits/stdc++.h>
using namespace std;
class Dsu {
public:
    int size;
    vector<int> parent;
    Dsu(int n) : size(n), parent(n) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }
    int find(int x) {
        while (x != parent[x]) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
    void merge(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) {
            return;
        }
        parent[rootY] = rootX;
        size--;
    }
};

int numberOfComponents(vector<vector<int>> &properties, int k) {
    Dsu dsu(properties.size());

    // 内部去重
    int n = properties.size();
    vector<unordered_set<int>> sets(n);
    for (int i = 0; i < n; i++) {
        sets[i] = unordered_set(properties[i].begin(), properties[i].end());
    }

    for (int i = 0; i < properties.size(); ++i) {
        for (int j = i; j < properties.size(); ++j) {
            if (i != j) {
                int cnt = 0;
                for (auto& x : sets[i]) {
                    if (sets[j].find(x) != sets[j].end()) {
                        cnt++;
                    }
                }
                if (cnt >= k) {
                    dsu.merge(i, j);
                }
            }
        }
    }
    return dsu.size;
}
int main() {
    vector<vector<int>> properties = {{1, 1}, {1, 1}};
    cout << numberOfComponents(properties, 2);
    return 0;
}