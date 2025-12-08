#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    if (nums[0] >= x) {
        nums[0] -= x;
    } else {
        cout << "No" << endl;
        return;
    }
    for (int i = 1; i < n; ++i) {
        int tmp = 0;
        tmp = nums[i - 1] >= x ? x : nums[i - 1];
        if (nums[i] - (x - tmp) >= 0) {
            nums[i] -= x - tmp;
        } else {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}
signed main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}