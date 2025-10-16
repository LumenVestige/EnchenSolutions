#include <bits/stdc++.h>
using namespace std;

class Dsu{
public:
    vector<int> parent;
    int size;
    int find(int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
    Dsu(int n) {
        this->size = n;
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
        size--;
    }
    bool isConnected(int x, int y) {
        return find(x) == find(y);
    }
    bool isSelf(int x) {
        return x == parent[x];
    }
};


bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
    auto dsu = Dsu(n);
    for (int i = 0; i < n; ++i) {
        // 共同接了一个
        if (leftChild[i] >= 0) {
            if (dsu.isSelf(leftChild[i])) {
                // 环检测
                if (dsu.isConnected(i, leftChild[i])) return false;
                dsu.connect(leftChild[i], i);
            } else {
                return false;
            }
        }
        if (rightChild[i] >= 0) {
            if (dsu.isSelf(rightChild[i])) {
                // 环检测
                if (dsu.isConnected(i, rightChild[i])) return false;
                dsu.connect(rightChild[i], i);
            } else {
                return false;
            }
        }
    }
    if (dsu.size != 1) 
        return false;
    return true;
}

int main() {
    vector<int> leftChild = {3, -1, 1, -1}, rightChild = {-1, -1, 0, -1};
    cout << validateBinaryTreeNodes(4, leftChild, rightChild);
    return 0;
}