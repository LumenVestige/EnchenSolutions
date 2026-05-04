#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int n; cin >> n;
    vector<int> nums(n+2, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> nums[i];
    }
    for (int i = 1; i <= n; ++i) {
        if (nums[i] > nums[i-1] && nums[i] > nums[i+1]) {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}