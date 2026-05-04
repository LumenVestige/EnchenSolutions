#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int toInt(string str) {
    int ans = 0;
    for (auto& i : str) {
        ans = (ans << 1) | (i - '0');
    }
    // cout << ans;
    return ans;
}
void solve() {
    string a, b;
    cin >> a >> b;
    int iA = toInt(a), iB = toInt(b);
    if (iA == 0 && iB != 0) {
        cout << -1;
        return;
    }
    cout << abs(iA - iB);
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