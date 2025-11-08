#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() {
    int n;
    cin >> n;
    int t = 0;
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        t += tmp;
    }
    if (t % n == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}