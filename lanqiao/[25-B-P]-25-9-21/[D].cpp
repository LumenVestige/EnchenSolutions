#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() {
    int a, b, c, k;
    cin >> a >> b >> c >> k;
    while (k--) {
        int aT = a, bT = b, cT = c;
        a = (bT + cT) / 2;
        b = (aT + cT) / 2;
        c = (aT + bT) / 2; 
    }
    cout << a << " " << b << " " << c << endl;
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}