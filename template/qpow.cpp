#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int MOD = 1e9+7;
int qpow(int x, int j) {
    int res = 1;
    while (j > 0) {
        if (j & 1) {
            res = res * x % MOD;
        }
        x = (x * x) % MOD;
        j >>= 1;
    }
    return res;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << qpow(2, 4654586756784563543);
    return 0;
}