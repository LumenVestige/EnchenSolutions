#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve() {
    int n, d;
    cin >> n >> d;
    string str;
    cin >> str;
    int sum = d;
    int tot = 0;
    for (auto& i : str) {
        if (i == '+') {
            sum = (sum + 1) % 10;
        } else {
            sum = (sum - 1 + 10) % 10;
        }
        if (sum == d) {
            tot++;
        }
    }
    cout << sum << " " << tot;
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