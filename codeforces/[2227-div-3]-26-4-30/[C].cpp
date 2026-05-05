#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int n;
    cin >> n;
    vector<int> y, no;
    vector<int> six, two, one, three;
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        if (tmp % 6 == 0) {
            six.push_back(tmp);
        } else if (tmp % 2 == 0) {
            two.push_back(tmp);
        } else if (tmp % 3 == 0) {
            three.push_back(tmp);
        } else {
            one.push_back(tmp);
        }
    }
    for (int x : six) cout << x << " ";
    for (int x : two) cout << x << " ";
    for (int x : one) cout << x << " ";
    for (int x : three) cout << x << " ";
    cout << endl;
    return;
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