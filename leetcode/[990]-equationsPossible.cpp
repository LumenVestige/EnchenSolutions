//
// Created by sanenchen on 25-10-16.
//
#include <bits/stdc++.h>
using namespace std;

class Dsu {
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

    void union_(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) {
            return;
        }
        parent[rootX] = rootY;
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }
};

bool equationsPossible(vector<string>& equations) {
    auto dsu = Dsu(26);
    // 首先要先找到连等关系
    vector<string> equal, notEqual;
    for (auto& s : equations) {
        if (s[1] == '=') {
            equal.push_back(s);
        } else {
            notEqual.push_back(s);
        }
    }
    // 首先先把等于关系确定好
    for (auto& eq : equal) {
        dsu.union_(eq[0] - 'a', eq[3] - 'a');
    }
    // 之后判断不应该相等的是否相等了
    for (auto& eq : notEqual) {
        if (dsu.same(eq[0] - 'a', eq[3] - 'a')) {
            return false;
        }
    }
    return true;
}

int main() {
    vector<string> equations = {"a==b", "b!=c", "c==a"};
    cout << equationsPossible(equations);
    return 0;
}