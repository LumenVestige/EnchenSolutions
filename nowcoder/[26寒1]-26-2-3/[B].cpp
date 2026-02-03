#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int MOD = 998244353;
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
const int MAX_N = 2e5+10;
int cal[MAX_N], inv_cal[MAX_N];
int inv(int n) {
    return qpow(n, MOD - 2);
}


void init() {
    cal[0] = 1;
    for (int i = 1; i < MAX_N; ++i) {
        cal[i] = cal[i - 1] * i % MOD;
    }
    // inv_cal[MAX_N - 1] = inv(cal[MAX_N-1]);
    // for (int i = MAX_N - 2; i >= 0; --i) {
    //     inv_cal[i] = inv_cal[i+1]*i;
    // }
}

void solve() {
    int n;
    cin >> n;
    vector<int> n1(n), n2(n);
    for (int i = 0; i < n; ++i) {
        cin >> n1[i]; // n1 小苯
    }
    for (int i = 0; i < n; ++i) {
        cin >> n2[i];
    }
    auto n1_sort = n1, n2_sort = n2;
    sort(n2_sort.begin(), n2_sort.end());
    int has = 0, no = 0;
    for (auto& i : n1) {
        int t = lower_bound(n2_sort.begin(), n2_sort.end(), i) - n2_sort.begin();
        if (t) {
            has++;
        } else {
            no++;
        }
    }
    cout << (cal[has]%MOD * cal[no]%MOD) % MOD << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}