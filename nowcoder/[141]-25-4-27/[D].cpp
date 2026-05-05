#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int n;
    cin >> n;
    unordered_map<int, int> mp;
    vector<int> nums;
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        mp[t]++;
        if (t <= 31622 && t != 1) nums.push_back(t);
    }
    if (mp[1] >= 2) {
        cout << "YES" << endl;
        return;
    }
    if (mp[1] == 1) {
        for (auto& [k, v] : mp) {
            if (v >= 2) {
                cout << "YES" << endl;
                return;
            }
        }
    }
    for (auto v : nums) {
        int x = v*v;
        for (int i = 2; x <= 1e9; i++, x*=v) {
            if (mp[i] && mp[x]) {
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
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