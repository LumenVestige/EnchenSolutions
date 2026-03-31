#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int n, k;
    cin >> n >> k;
    for (int a = 2; a <= 1e8; ++a) {
        if ((k + n - 2 + a)% (a - 1) == 0) {
            int b = (k + n - 2 + a) / (a - 1);
            for (int i = 1; i <= n-2; ++i) {
                cout << "1 ";
            }
            cout << a << " " << b << endl;
            return;
        }
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