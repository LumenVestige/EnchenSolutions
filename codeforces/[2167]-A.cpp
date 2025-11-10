#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve() {
    unordered_set<int> se;
    for (int i = 0; i < 4; ++i) {
        int t;
        cin >> t;
        se.insert(t);
    }
    if (se.size() == 1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    while (n--) {
        solve();
    }
    return 0;
}