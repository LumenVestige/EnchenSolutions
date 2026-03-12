#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    n++;
    nums.insert(nums.begin(), k);
    int m = nums[0] + nums[n-1];
    for (int i = 1; i < n; ++i) {
        m = max(m, nums[i] + nums[i-1]);
    }
    cout << m << endl;
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