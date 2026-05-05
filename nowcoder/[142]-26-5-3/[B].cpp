#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int n; cin >> n;
    vector<int> nums(n+1);
    for (int i = 1; i <= n; ++i) {
        nums[i] = i;
    }
    int left = 1, right = n;
    int f = 0;
    for (int i = 0; i < n; ++i) {
        int t; cin >> t;
        if (left <= n && nums[left] == t) {
            left++;
        } else if (right >= 1 && nums[right] == t) {
            right--;
        } else {
            f++;
        }
    }
    cout << (f == 0 ? "YES" : "NO") << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}