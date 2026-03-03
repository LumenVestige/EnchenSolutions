#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int n;
    cin >> n;
    vector<int> nums(n);
    int ans = 0;
    int tmp = 0;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        if (nums[i] == 1) {
            cnt++;
        }
    }
    if (cnt == n) {
        cout << n << endl;
        return;
    }
    vector<int> gc(n-1);
    for (int i = 1; i < n; ++i) {
        gc[i-1] = gcd(nums[i], nums[i-1]);
    }
    for (int i = 0; i < n-1; ++i) {
        if (gc[i] == 1) {
            tmp++;
        } else {
            ans += (tmp + 1) / 2;
            tmp = 0;
        }
    }
    ans += (tmp + 1) / 2;
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