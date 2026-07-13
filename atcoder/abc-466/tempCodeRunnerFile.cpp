#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int n;
    cin >> n;
    int num=0;
    for (int i = 0; i < n;++i) {
        int a;
        cin >> a;
        if (a < 0) num++;
    }
    if (num == n) {
        cout << "No";
    } else {
        cout << "Yes"
    }
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