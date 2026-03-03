#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    string str;
    cin >> str;
    for (auto& i : str) {
        if (i == '0' || i == '5') {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    while (n--) {
        solve();
    }
    return 0;
}