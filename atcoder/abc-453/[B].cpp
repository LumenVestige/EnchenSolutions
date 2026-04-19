#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, X;
    cin >> T >> X;
    vector<pair<int, int>> ts;
    for (int i = 0; i <= T; ++i) {
        int t;
        cin >> t;
        if (i == 0) {
            ts.push_back({0, t});
            continue;
        }
        if (abs(t-ts.back().second) >= X) {
            ts.push_back({i, t});
        }
    }
    for (auto& [k,v] : ts) {
        cout << k << " " << v << endl;
    }
    return 0;
}