#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int n;
    cin >> n;
    if (n <= 2) {
        cout << "No" << endl;
        return ;
    }
    if (n&1) {
        cout << n << " " << (n*n + 1) / 2 << " " << (n*n - 1) / 2 << endl;
    } else {
        cout << n << " " << (n*n/2+2)/2 << " " << (n*n/2-2)/2 << endl;
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >>t;
    while (t--) {
        solve();
    }
    return 0;
}