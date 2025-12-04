#include <bits/stdc++.h>
using namespace std;

// 来上一个并查集
class UnionFind {
public:
    vector<int> parent;
    UnionFind(int x): parent(vector<int>(x)) {
        for (int i = 0; i < x; ++i) {
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
        int rootX = find(x), rootY = find(y);
        parent[rootY] = rootX;
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
};

vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    unordered_map<string, int> um;
    int n = accounts.size();
    UnionFind uf(n);
    // 遍历每一个账户，绑定邮箱与用户、合并同一个用户
    for (int i = 0 ; i < n; ++i) { // 用户ID
        for (int j = 1; j < accounts[i].size(); ++j) {
            string email = accounts[i][j];
            // 往um中查询是否存在对应的用户名、邮箱绑定
            if (um.count(email)) {
                // 存在，合并
                uf.merge(i, um[email]);
            } else {
                // 不存在
                um[email] = i;
            }
        }
    }
    unordered_map<int, vector<string>> cnt; // 每个用户对应的邮箱
    for (auto& [k, v] : um) {
        // key email v id
        cnt[uf.find(v)].emplace_back(k);
    }
    vector<vector<string>> ans;
    for (auto& [k, v] : cnt) {
        // k 是用户id
        // v 是邮箱列表
        sort(v.begin(), v.end());
        vector<string> tmp(1, accounts[k][0]);
        tmp.insert(tmp.end(), v.begin(), v.end());
        ans.emplace_back(tmp);
    }
    return ans;
}

int main() {
    vector<vector<string>> accounts = {{"John","johnsmith@mail.com","john_newyork@mail.com"},{"John","johnsmith@mail.com","john00@mail.com"},{"Mary","mary@mail.com"},{"John","johnnybravo@mail.com"}};
    for (auto& it : accountsMerge(accounts)) {
        for (auto& i : it) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}