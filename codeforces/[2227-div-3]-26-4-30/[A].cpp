#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int a, b;
    cin >> a >> b;
    if ((a&1 && b&1)) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}