#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << "YES" << endl;
        cout << 1 << endl;
        return;
    } else if (n == 3) {
        cout << "YES" << endl;
        cout << "1 2 3" << endl;
        return;
    }
    cout << "NO" << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
    // int t1 = 0, t2 = 1;
    // for (int i = 1; i < 100; ++i) {
    //     t1 += i;
    //     t2 *= i;
    //     cout << t1 << " " << t2 << endl;;
    // }
    return 0;
}