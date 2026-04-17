#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int t;
    cin >> t;
    while (t--) {
        int a, b, c; cin >> a >> b >>c;
        if (a * (pow(2, b)-1) >= c) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}