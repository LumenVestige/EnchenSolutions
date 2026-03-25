#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve(int x, int y, int n) {
    // // int x, y, n;
    // // cin >> x >> y >> n;
    // int ans = 0;
    // for (int i = 1; i <= n; ++i) {    
    //     if (i / x == i / y) ans ++;
    //     if (i / x - i / y >= 2) {
    //         cout << ans << endl;
    //         return;
    //     }
    //     //cout << i / x << " " << i / y << " 当前ans" << ans << endl;
    // }
    // cout << ans << endl;
    // // cout << "cph:";
    // // if (x >= n and y >= n || (x == y)) {
    // //     cout << n;
    // // }
    // // cout << endl;
    int m1 = min(n, x - 1);
    cout << max((long long)0, m1) << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // for (int i = 10; i < 20; ++i) {
    //     for (int j = 2 * 10; j < 40; ++j) {
            
    //         cout << i << " " << j << " " << 60 << endl;
    //         cout << 60 / i << " " << 60 / j << endl;
    //         solve(i, j, 60);
    //         // for (int n = 50; n < 100; ++n) {
    //         //     cout << i << " " << j << " " << n << endl;
    //         //     solve(i, j, n);
    //         // }
    //     }
    // }
    //solve(2, 3, 1e9);
    int t;
    cin >> t;
    while(t--) {
        int x, y, n;
        cin >> x >> y >> n;
        solve(x, y, n);
    }
    //cout << endl;
    return 0;
}