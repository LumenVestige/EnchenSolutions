#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int a[500005], s[500005];
int n;
int lowBit(int x) {
    return x & -x;
}
void change(int x, int k) {
    while (x <= n) {
        s[x] += k;
        x += lowBit(x);
    }
}
int query(int x) {
    int t = 0;
    while (x) {
        t += s[x];
        x -= lowBit(x);
    }
    return t;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        change(i, a[i]);
    }
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            change(b, c);
        } else {
            cout << query(c) - query(b - 1) << endl;
        }
    }
    return 0;
}