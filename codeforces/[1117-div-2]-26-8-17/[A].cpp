#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve() {
    int n, m;
    cin >> n >> m;
    unordered_map<char, int> cnt;
    for (int i = 0; i < n; ++i) {
        string tmp;
        cin >> tmp;
        cnt[tmp[0]-32]++;
    }
    bool f = true;
    for (int i = 0; i < m; ++i) {
        string tmp; cin >> tmp;
        bool flag = true;
        for (auto& i : tmp) {
            if (cnt[i] == 0) {
                flag = false;
                break;
            }
        }
        if (!flag) {
            f = false;
        }
    }
    if (!f) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
}

signed main() {
    // cout << char('a'-32);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}