#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    string str;
    int n;
    cin >> n;
    cin >> str;
    int left = 0, right = 0;
    for (auto& i : str) {
        if (i == '(') {
            left++;
        } else if (left != 0) {
            left--;
        } else {
            right++;
        }
    }
    if (right == left) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
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