#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int s, l, r;
        cin >> s >> l >> r;
        if (l > r) {
            cout << 0 << endl;
        } else {
            cout << r - l + 1 << endl;
        }
    }
    return 0;
}