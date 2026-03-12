#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod = 1e9+7;
const int MAXN = 2e5 + 10;
int fact[MAXN];
int inv_fact[MAXN];

int qpow(int x, int y) {
    int res = 1;
    while (y > 0) {
        if (y & 1) res = res * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return res;
}

void init() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        fact[i] = fact[i-1] * i % mod;
    }
    inv_fact[MAXN-1] = qpow(fact[MAXN-1], mod-2);
    for (int i = MAXN-2; i >= 0; --i) {
        inv_fact[i] = inv_fact[i+1] * (i+1) % mod;
    }
}

int C(int n, int i) {
    if (i < 0 || i > n) return 0;
    return fact[n] * inv_fact[i] % mod * inv_fact[n - i] % mod;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    int n;
    cin >> n;
    int pow_2 = qpow(2, n-1);
    for (int i = 1; i <= n; ++i) {
        int ans = C(n, i) * pow_2 % mod;
        cout << ans << " ";
    }
    return 0;
}