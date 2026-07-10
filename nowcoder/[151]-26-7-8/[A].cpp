#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int n; string str;
    cin >> n >> str;
    int cnt = 0;
    for (auto& i : str) {
        if (i == '|') cnt++;
    }
    cout << cnt / 2;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}