#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    long double pos = 0.5;
    int ans = 0;
    while (n--) {
        int t;
        cin >> t;
        // 左还是右 优先穿过(变号)
        // left
        double left = pos - t;
        double right = pos + t;
        if (left * pos <= 0) {
            ans++;
            pos = left;
            continue;
        } else if (right * pos <= 0) {
            ans++;
            pos = right;
            continue;
        }
        if (abs(right) < abs(left)) {
            pos = right;
        } else {
            pos = left;
        }
    }
    cout << ans;
    return 0;
}