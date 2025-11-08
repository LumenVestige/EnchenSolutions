#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int n, m, s;
    cin >> n >> m >> s;
    unordered_set<int> fired;
    unordered_set<int> vis;
    queue<int> fireQue;
    while (m--) {
        int t;
        cin >> t;
        fired.insert(t);
        fireQue.emplace(t);
    }
    unordered_map<int, vector<int>> tree;
    n--;
    while (n--) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    queue<int> que;
    int ans = 0;
    que.emplace(s);
    vis.insert(s);
    while (!que.empty()) {
        // 着火平台蔓延
        int fireSize = fireQue.size();
        while (fireSize--) {
            int pos = fireQue.front();
            fireQue.pop();
            // 查询相连的 全部着火
            auto con = tree[pos];
            for (auto& i : con) {
                if (!fired.count(i)) {
                    fireQue.emplace(i);
                    fired.insert(i);
                }
            }
        }
        int size = que.size();
        while (size--) {
            int pos = que.front();
            que.pop();
            // if (fired.count(pos)) {
            //     break;
            // }
            if (tree[pos].size() == 1) {
                cout << ans;
                return 0;
            }
            // 跳到下一个没有着火的平台
            auto con = tree[pos];
            for (auto& i : con) {
                if (!fired.count(i) && !vis.count(i)) {
                    que.emplace(i);
                    vis.insert(i);
                } 
            }
        }
        ans++;
    }
    
    cout << -1;
    return 0;
}