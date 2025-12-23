#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> nums(n);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        if (i > 0) {
            ans += abs(nums[i] -nums[i - 1]);
        }
    }
    
    int tmp = max(abs(nums[0] - nums[1]), abs(nums[n - 1] - nums[n - 2]));
    for (int i = 1; i < n - 1; i++) {
        int add = abs(nums[i] - nums[i - 1]) + abs(nums[i] - nums[i + 1]);
        int direct = abs(nums[i - 1] - nums[i + 1]);
        tmp = max(tmp, abs(add - direct));
    }
    ans -= tmp;
    cout << ans << endl;
}
signed main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}