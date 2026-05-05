#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long

void solve(int a, int b) {
    for (int i = 0; i < 1e6; ++i) {
        if (gcd(a, i) == 1 && gcd(b, i) > 1) {
            cout << i << endl;
            return;
        }
    }
    cout << -1 << endl;
}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            cout << i << " " << j << " ";
            solve(i, j);
        }
    }
    return 0;
}