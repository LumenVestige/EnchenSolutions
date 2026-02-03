#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int n;
    cin >> n;
    vector<int> nums(n);
    int MAX = INT_MIN;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        MAX = max(MAX, nums[i]);
    }
    if (n <= 2) {
        int t = 0;
        for (auto& i : nums) {
            t += i;
        }
        cout << t << endl;
        return;
    }
    cout << (n-2)*MAX + nums[0] + nums[n-1] << endl;
    
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}