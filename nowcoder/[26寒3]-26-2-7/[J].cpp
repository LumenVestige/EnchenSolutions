#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
#define endl "\n"

int qpow(int x, int n) {
    int res = 1;
    while (n > 0) {
        if (n & 1) {
            res *= x;
        }
        x *= x;
        n >>= 1;
    }
    return res;
}

int cnt(int n) {
    int res = -1;
    while (n > 0) {
        res++;
        n >>= 1;
    }
    return res;
}

void solve() {
    int n, q; cin >> n >> q;
    int endC = cnt(n);
    while (q--) {
        int t; cin >> t;
        int cur = cnt(t);
        if (cur != endC) {
            cout << qpow(2, cur) << endl;
        } else {
            cout << n - qpow(2, cur) + 1 << endl;
        }
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