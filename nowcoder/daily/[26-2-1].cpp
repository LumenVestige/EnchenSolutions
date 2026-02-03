#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod = 1e9+7;
int a(int n, int m) {
    int result = 1;
    for (int i = 0; i < m; ++i) {
        result *= (n - i);
        result %= mod;
    }
    return result;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    // 判断点位
    int pos = (n / 3);
    if (2 * pos < n / 2) {
        cout << 0;
        return 0;
    }
    int needCut = 2*pos - n/2;
    cout << (a(pos, needCut)%mod*a(pos, needCut)%mod * a(n-pos, pos-needCut)%mod * a(n-pos, n-pos)%mod)%mod;


    return 0;
}