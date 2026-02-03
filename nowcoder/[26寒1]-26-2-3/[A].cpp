#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
#define endl "\n"
const int MOD = 998244353;
const int mod = 998244353;
int qpow(int x, int n) {
    int res = 1;
    while (n > 0) {
        if (n & 1) {
            res = res * x % MOD;
        }
        x = x * x % MOD;
        n >>= 1;
    }
    return res;
}

int inv(int i) {
    return qpow(i, MOD-2);
}

void solve() {
    int c;
    cin >> c;
    vector<int> p(8);
    vector<int> fp(8);
    for (int i = 1; i <= 7; ++i) {
        cin >> p[i];
        fp[i] = (100-p[i])*inv(100) % MOD;
        p[i] = p[i]*qpow(100,mod-2)%mod;

    }
    // 计算每个数字的概率
    vector<int> pp(10);
    pp[0] = p[1]*p[2]%mod*p[3]%mod*fp[4]%mod*p[5]%mod*p[6]%mod*p[7]%mod;
    pp[1] = fp[1]*fp[2]%mod*p[3]%mod*fp[4]%mod*fp[5]%mod*p[6]%mod*fp[7]%mod;
    pp[2] = p[1]*fp[2]%mod*p[3]%mod*p[4]%mod*p[5]%mod*fp[6]%mod*p[7]%mod;
    pp[3] = p[1]*fp[2]%mod*p[3]%mod*p[4]%mod*fp[5]%mod*p[6]%mod*p[7]%mod;
    pp[4] = fp[1]*p[2]%mod*p[3]%mod*p[4]%mod*fp[5]%mod*p[6]%mod*fp[7]%mod;
    pp[5] = p[1]*p[2]%mod*fp[3]%mod*p[4]%mod*fp[5]%mod*p[6]%mod*p[7]%mod;
    pp[6] = p[1]*p[2]%mod*fp[3]%mod*p[4]%mod*p[5]%mod*p[6]%mod*p[7]%mod;
    pp[7] = p[1]*fp[2]%mod*p[3]%mod*fp[4]%mod*fp[5]%mod*p[6]%mod*fp[7]%mod;
    pp[8] = p[1]*p[2]%mod*p[3]%mod*p[4]%mod*p[5]%mod*p[6]%mod*p[7]%mod;
    pp[9] = p[1]*p[2]%mod*p[3]%mod*p[4]%mod*fp[5]%mod*p[6]%mod*p[7]%mod;

    int ans = 0;
    auto cal = [&](int n) {
        string str = "0000" + to_string(n);
        // 截取后四位
        str = str.substr(str.size()-4);
        int res = 1;
        for (auto& i : str) {
            res = res * pp[i-'0'] % MOD;
        }
        return res % MOD;
    };
    for (int i = 0; i <= c; ++i) {
        int j = c - i;
        ans = (ans + cal(i)*cal(j)%MOD)%MOD;
    }
    cout << ans%MOD << endl;
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