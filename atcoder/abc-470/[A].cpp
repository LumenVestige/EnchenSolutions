#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve() {
    int i; cin >> i;
    for (int j = 1; j <= i; ++j) {
        if (j % 3 == 0) {
            cout << "Fizz" << endl;
        } else {
            cout << j << endl;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}