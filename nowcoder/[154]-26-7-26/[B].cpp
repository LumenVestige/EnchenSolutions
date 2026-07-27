#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cout << i << " ";
    }
    cout << endl;
    for (int i = n; i >= 1; --i) {
        cout << i << " ";
    }
    cout << endl;
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