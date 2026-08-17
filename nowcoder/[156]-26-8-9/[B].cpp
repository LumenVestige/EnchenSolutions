#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve() {
    int n;
    cin >> n;
    string str; cin >> str;
    unordered_set<char> se(str.begin(), str.end());
    int ans = 0;
    for (auto& c : se) {
        // cout << c << endl;
        int l = 0, r = n-1;
        bool flag = true;
        while (l <= r && l < n && r >= 0) {
            if (str[l] == c) {
                l++;
                continue;
            }
            if (str[r] == c) {
                r--;
                continue;
            }
            if (str[l] != str[r]) {
                flag = false;
                break;
            }
            l++, r--;

        }
        if (flag) {
            ans++;
        }
    }
    cout << ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}