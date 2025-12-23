#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
#define int long long
void solve() {
    int n;
    cin >> n;
    vector<int> nums(n);
    int tmp = 0;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    cout << max(nums[0], nums[1] - nums[0]) << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}