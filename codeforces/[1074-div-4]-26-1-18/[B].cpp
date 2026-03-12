#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int n;
    cin >> n;
    vector<int> nums(n);
    int theMax = INT_MIN;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        theMax = max(nums[i], theMax);
    }
    cout << theMax * n << endl;
}
signed main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}