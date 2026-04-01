#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int n;
    cin >> n;
    vector<int> nums(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> nums[i];
        if (nums[i] < i) {
            cout << -1 << endl;
            return;
        }
    }
    // the last
    int last = nums[n];
    int canModi = last - n;
    int needModi = 0;
    vector<int> afterMin(n+2, INT_MAX);
    for (int i = n; i >= 1; --i) {
        afterMin[i] = min(afterMin[i+1], nums[i]);
    }
    //cout << canModi << endl;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans++;
        if (nums[i] - ans > 0) {
            needModi += nums[i] - ans;
        }
        if (canModi > 0 && needModi > 0 && ans+1 < afterMin[i+1]) {
            ans++;
            needModi--;
            canModi--;
        }
    }
    cout << ans+needModi << endl;
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