#include <bits/stdc++.h>
using namespace std;

class Dsu{
private:
    int size;
    vector<int> parent;
    int find(int x) {
        while (x != parent[x]) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
public:
    Dsu(int n) : size(n), parent(n) {
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
        parent[rootY] = rootX;
        size--;
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }

    int count() {
        return size;
    }
};

int encode(vector<int>& point) {
    return point[0] * 10000 + point[1];
}

int removeStones(vector<vector<int>>& stones) {
    int n = stones.size();
    // 二维转一维 绑定 一维引索和stones id
    unordered_map<int, int> codeToId;
    for (int i = 0; i < n; ++i) {
        codeToId[encode(stones[i])] = i;
    }
    // 记录每一行 每一列有那些石头
    unordered_map<int, vector<int>> colIndex, rowIndex;
    for (auto& i : stones) {
        colIndex[i[0]].push_back(encode(i));
        rowIndex[i[1]].push_back(encode(i));
    }
    Dsu dsu(n);
    // 处理行
    for (auto& i : colIndex) {
        int firstId = codeToId[i.second[0]];
        for (auto& j : i.second) {
            dsu.connect(firstId, codeToId[j]);
        }
    }
    // 处理列
    for (auto& i : rowIndex) {
        int firstId = codeToId[i.second[0]];
        for (auto& j : i.second) {
            dsu.connect(firstId, codeToId[j]);
        }
    }
    return n - dsu.count();
}

int main() {
    vector<vector<int>> stones = {{0, 0}, {0, 1}, {1, 0}, {1, 2}, {2, 1}, {2, 2}};
    cout << removeStones(stones);
    return 0;
}