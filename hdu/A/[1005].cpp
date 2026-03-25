#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int n, k;
    cin >> n >> k;
    auto check = [&](int x) {
        if (x == 0) return false;
        int res = 1;
        int j = k;
        int tx = x;
        while (j) {
            if (j & 1) {
                if (res > n / tx) return false;
                res *= tx;
                if (res > n) return false;
            }
            if (j > 1 && tx > n / tx) return false;
            tx *= tx;
            j >>= 1;
        }
        return res <= n;
    };
    int left = 0, right = n + 1;
    int ans = 0;
    while (left + 1 != right) {
        int mid = left + (right - left) / 2;
        if (check(mid)) {
            ans = mid;
            left = mid;
        } else {
            right = mid;
        }
    }
    cout << ans << endl;
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