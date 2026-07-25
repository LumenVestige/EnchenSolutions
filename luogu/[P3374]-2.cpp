#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

struct Binary {
    vector<int> mx;
    int n;
    int lowbit(int x) {
        return x & -x;
    }
    Binary(int x) : mx(x+1), n(x) {}
    void add(int x, int val) {
        for (int i = x; i <= n; i += lowbit(i)) {
            mx[i] += val;
        }
    }
    // 1..x
    int query(int x) {
        int res = 0;
        for (int i = x; i >= 1; i -= lowbit(i)) {
            res += mx[i];
        }
        return res;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    Binary bin(n);
    for (int i = 1; i <= n; ++i) {
        int t;
        cin >> t;
        bin.add(i, t);
    }
    while (m--) {
        int op, a, b;
        cin >> op >> a >> b;
        if (op == 1) {
            bin.add(a, b);
        } else {
            cout << bin.query(b) - bin.query(a-1) << endl;
        }
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