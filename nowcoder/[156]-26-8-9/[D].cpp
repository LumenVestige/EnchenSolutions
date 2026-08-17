#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve() {
    int n; cin >> n;
    vector<vector<char>> g(3, vector<char>(n));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> g[i][j];
        }
    }
    if (n > 8) {
        cout << 0 << endl;
        return;
    }
    unordered_map<string, int> mem;
    auto dd = [&](auto&& dd, int j, int i, string tmp, vector<string>& an)->void {
        if (i == 3) {
            an.push_back(tmp);
            return ;
        }
        if (g[i][j] != '?') {
            tmp += g[i][j] + '0';
            dd(dd, j, i+1, tmp, an);
        } else {
            dd(dd, j, i+1, tmp+'0', an);
            dd(dd, j, i+1, tmp+'1', an);
        }
    };
    auto dfs = [&](auto&& dfs, int index)->int {
        if (index == n) {
            return 1;
        }
        vector<string> st;
        dd(dd, index, 0, "", st);
        int res = 0;
        for (auto& i : st) {
            if (mem[i] == 0) {
                mem[i]++;
                res += dfs(dfs, index+1);
                mem[i]--;
            }
        }
        return res;
    };
    cout << dfs(dfs, 0);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}