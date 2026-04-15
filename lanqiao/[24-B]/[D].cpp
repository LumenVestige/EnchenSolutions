#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int a, b, c, k;
    cin >> a >> b >> c >> k;
    while (k--) {
        // cout << "第" << k << "调整" << endl;
        int aa = (b+c)/2;
        int bb = (a+c)/2;
        int cc = (a+b)/2;
        a = aa, b = bb, c = cc;
        if (a == b && b == c && a == c) {
            // cout << "提前退出" << endl;
            break;
        }
        // cout << a << " "<< b << " "<< c << " " << endl;
    }
    cout << a << " "<< b << " "<< c << " " << endl;
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