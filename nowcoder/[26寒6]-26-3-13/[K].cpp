#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int m,n,z;
    cin >> m >> n >> z;
    bool player = 0;
    int x = 0;
    z = z % (m+n);
    while (x < z) {
        if (player == 0) {
            x += m;
            player = !player;
        } else {
            x += n;
            player = !player;
        }
    }
    cout << !player;
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