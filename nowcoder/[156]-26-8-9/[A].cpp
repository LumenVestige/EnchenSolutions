#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve() {
    string str; cin >> str;
    for (auto& i : str) {
        if (i >= '0' && i <= '9') {
            cout << i << endl;
            return;
        }
    }
    cout << -1;
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