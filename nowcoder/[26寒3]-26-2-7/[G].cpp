#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int n, m;
    cin >> n >> m;
    priority_queue<int> left, right;
    int totLeft = 0, totRight = 0;
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        left.push(t);
        totLeft += t;
    }
    for (int i = 0; i < m; ++i) {
        int t;
        cin >> t;
        right.push(t);
        totRight += t;
    }
    // 二者相等
    if (totLeft == totRight) {
        cout << 1 << endl;
        return;
    }
    // 左大于→
    n = 0;
    if (totLeft > totRight) {
        while (!left.empty() && totLeft > totRight) {
            totLeft -= left.top();
            left.pop();
            n++;
        }
        cout << n << endl;
    } else if (totLeft < totRight) {
        while (!right.empty() && totLeft < totRight) {
            totRight -= right.top();
            right.pop();
            n++;
        }
        cout << n << endl;
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}