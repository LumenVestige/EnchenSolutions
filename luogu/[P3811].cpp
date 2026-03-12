#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int q;
int qpow(int x, int n) {
    int res = 1;
    while (n > 0) {
        if (n & 1) {
            res = res * x % q;
        }
        x = x * x % q;
        n >>= 1;
    }
    return res;
}

int inv(int n) {
    return qpow(n, q-2);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cout << inv(i) << endl;
    }
    return 0;
}