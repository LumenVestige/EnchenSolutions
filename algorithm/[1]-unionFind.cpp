//
// Created by sanenchen on 25-8-14.
//
// 并查集的实现
#include <bits/stdc++.h>

using namespace std;

class UnionFind {
    unordered_map<int, int> parent, rank;

public:
    // 初始化
    explicit UnionFind(vector<int> p) {
        for (int i = 0; i < p.size(); ++i) {
            parent[p[i]] = i;
        }
    }

    // 查找
    int find(int x) {
        // 路径压缩
        if (parent[x] != x) // 自己不是根节点
            parent[x] = find(parent[x]);
        return parent[x];
    }

    // 合并
    void union_n(int x, int y) {
        int root_x = find(x);
        int root_y = find(y);

        // 按秩合并
        // 矮的树挂在高的树上
        if (rank[root_x] > rank[root_y])
            parent[root_y] = root_x;
        else if (rank[root_x] < rank[root_y])
            parent[root_x] = root_y;
        else {
            parent[root_y] = root_x;
            rank[root_x] += 1;
        }
    }
};

int main() {
    vector<int> p = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    UnionFind union_find(p);
    union_find.union_n(1, 2);
    cout << union_find.find(2);

    return 0;
}
