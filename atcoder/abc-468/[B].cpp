#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int n, d;
    cin >> n >> d;
    string str;
    cin >> str;
    str = str;
    // diff
    vector<int> diff(n+1, 0);
    for (int i = 0; i < n; ++i) {
        if (str[i] == 'G') {
            if (i-d < 0) {
                diff[0]++;
            } else {
                diff[i-d]++;
            }
            if (i+d+1 > n) {
                diff[n]--;
            } else {
                diff[i+d+1]--;
            }
        }
    }
    vector<int> ori(n+1, 0);
    ori[0] = diff[0];
    int ans = (ori[0] == 0 ? 1 : 0);
    for (int i = 1; i < n; ++i) {
        ori[i] = ori[i-1]+diff[i];
        if (ori[i] == 0) ans++;
        // cout << ori[i] << " ";
    }
    // cout << endl;
    cout << ans;

}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}