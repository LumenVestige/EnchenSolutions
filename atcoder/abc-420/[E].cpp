#include <bits/stdc++.h>
using namespace std;

class Dsu {
private:
    int size;
    vector<int> parent;

public:
    Dsu(int n) {
        this->size = n;
        parent = vector<int>(n);
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
    bool merge(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);
        if (rootA == rootB) {
            return false;
        }
        // B 挂在 A 上
        parent[rootA] = rootB;
        size--;
        return true;
    }
    bool same(int a, int b) {
        return find(a) == find(b);
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    Dsu dsu(n + 1);
    // 构建两个数组 一个是记录黑白 一个记录当前路径上黑色个数
    vector<int> cnt(n + 1, 0), path(n + 1, 0);
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int a, b;
            cin >> a >> b;
            int rootA = dsu.find(a);
            int rootB = dsu.find(b);
            // 连接
            if(!dsu.merge(a, b))
                continue;
            // 所以a上的数据要转移到b上面
            path[rootB] = path[rootA] + path[rootB];
            path[rootA] = 0;
        } else if (type == 2) {
            // 黑白转化
            int v;
            cin >> v;
            // 找到v的头子
            int head = dsu.find(v);
            if (cnt[v] == 0) {
                path[head]++;
                cnt[v] = 1;
            } else {
                path[head]--;
                cnt[v] = 0;
            }
        } else if (type == 3) {
            int v;
            cin >> v;
            // 查找head
            int head = dsu.find(v);
            if (path[head] > 0) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}