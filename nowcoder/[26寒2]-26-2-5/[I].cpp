#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int m, n;
    cin >> n >> m;
    vector<vector<int> > g(n, vector<int>(m));
    unordered_map<char, int> cnt;
    for (int i = 0; i < n; ++i) {
        string str;
        cin >> str;
        for (int j = 0; j < m; ++j) {
            g[i][j] = str[j];
            cnt[str[j]]++;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (cnt[g[i][j]] >= 2) {
                cout << "Y";
            } else {
                cout << "N";
            }
        }
        cout << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    while (n--) {
        solve();
    }
    return 0;
}