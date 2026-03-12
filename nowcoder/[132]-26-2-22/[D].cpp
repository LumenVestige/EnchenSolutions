#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve2() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; j++) {
            ans += (nums[i] + nums[j]) / 2;
        }
    }
    cout << ans << endl;
}
void solve() {
    int n;
    cin >> n;
    int sum_a = 0;
    int cnt_odd = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        sum_a += x;
        if (x % 2 != 0) {
            cnt_odd++;
        }
    }
    int cnt_even = n - cnt_odd;
    int ans = ((n - 1) * sum_a - cnt_odd * cnt_even) / 2;
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    while (n--) {
        solve();
        //solve2();
    }
    return 0;
}