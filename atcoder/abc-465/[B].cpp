#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int x, y, l, r, a, b;
    cin>>x>>y>>l>>r>>a>>b;
    int lF = 0, rF = 0, normal = 0;
    int tot = b-a;
    int sp = max(0LL, min(b, r) - max(a, l));
    int nor = tot-sp;
    // cout << rF << lF << normal << endl;
    cout << sp*x + nor*y;
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