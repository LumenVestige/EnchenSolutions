#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    string str;
    cin >> str;
    int k, n = str.size();
    cin >>k;
    string target = "Rounddo";
    for (int i = 0; i < k; ++i) {
        target += 'g';
    }
    string s = str+str;
    int pos = 0;
    int ans = 0;
    vector<int> diff(2*n+1, 0);
    while ((pos = s.find(target, pos)) != string::npos && pos < n) {
        int l = (pos + target.size()) % n;
        int r = pos;
        if (l > r) {
            diff[l]++;
            diff[n-1] --;
            diff[0]++;
            diff[r] --;
        } else {
            diff[l]++;
            diff[r] --;
        }

        pos++;
        // cout << 1 << endl;
    }
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        cur += diff[i];
        if (cur > 0) ans++;
    }
    cout << ans << endl;
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