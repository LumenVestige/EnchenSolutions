#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve() {
    int n;
    string s;
    cin >> n >> s;
    bool normal = 1; // 1:normal
    string ans;
    for (auto& i : s) {
        if (i == '!') {
            normal = !normal;
        } else if (i == '-') {
            if (ans.size() <= 0) {
                continue;
            }
            // 判断当前模式
            if (normal) {
                ans = ans.erase(ans.size()-1, 1);
            } else {
                ans = ans.erase(0, 1);
            }
        } else {
            if (normal) {
                ans += i;
            } else {
                ans.insert(ans.begin(), i);
            }
        }
    }
    cout << (ans != "" ? ans : "Empty") << endl;
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