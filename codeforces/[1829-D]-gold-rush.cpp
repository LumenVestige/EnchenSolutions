//
// Created by sanenchen on 25-7-28.
//
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    cin >> t;
    // 加入记忆化搜索
    set<char> dict = {};
    while (t--) {
        int n, m;
        cin >> n >> m;
        unordered_map<int, bool> g_map;
        function<bool(int)> dfs = [&](int x) -> bool {
            if (x == m)
                return true;
            // 查表
            if (g_map.find(x) != g_map.end())
                return g_map[x];
            if (x % 3 == 0) {
                int tmp = x / 3;
                if (dfs(tmp)) {
                    g_map[x] = true;
                    return true;
                }
                if (dfs(2 * tmp)) {
                    g_map[x] = true;
                    return true;
                }
            }
            g_map[x] = false;
            return false;
        };
        if (m > n) {
            cout << "NO" << endl;
            continue;
        }
        if (dfs(n)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
