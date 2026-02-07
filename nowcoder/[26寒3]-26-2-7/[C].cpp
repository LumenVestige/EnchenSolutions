#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int n;
    cin >> n;
    string nums;
    cin >> nums;
    int ans = LLONG_MAX;
    if (n == 1) {
        cout << 0 << endl;
        return;
    }
    // 101
    for (int last = 0; last < 2; ++last) {
        char target = last + '0', l = '2';
        int cur = 0, m = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != target) {
                if (nums[i] == l) {
                    ++cur;
                } else {
                    cur = 1;
                    l = nums[i];
                }
                m = max(m, cur);
            }
            target = (target == '0') ? '1' : '0';
        }
        ans = min(ans, m);
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