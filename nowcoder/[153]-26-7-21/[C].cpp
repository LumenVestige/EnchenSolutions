#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int n;
    string s, t;
    cin >> n >> s >> t;
    vector<int> diff0t1, diff1t0;
    for (int i = 0; i < n; ++i) {
        if (s[i] != t[i]) {
            if (s[i] == '0') {
                diff0t1.push_back(i+1);
            } else {
                diff1t0.push_back(i+1);
            }
        }
    }
    int times;
    vector<int> ans;
    int n1 = diff0t1.size();
    if (n1 == 0) {
        cout << 0;
        return;
    }
    int first = diff0t1[0]; 
    for (int i = 0; i < n1; ++i) {
        times += 2;
        ans.push_back(diff0t1[i]);
        ans.push_back(diff1t0[i]);
    }
    times++;
    ans.push_back(first);
    cout << times << endl;
    for (auto& i : ans) {
        cout << i << endl;
    }
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