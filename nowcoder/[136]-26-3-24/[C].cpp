#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int MOD = 998244353;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string str;
    cin >> n >> str;
    // 计算奇偶数
    int ou = n / 2;
    int ji = ou + (n % 2 != 0 ? 1 : 0);
    int ans = 1;
    for (auto& i : str) {
        if (i == 'j') {
            if (ji == 0) {
                cout << 0;
                return 0;
            }
            ans = ans * ji % MOD;
            ji--;
            n--;
        }
        if (i == 'o') {
            if (ou == 0) {
                cout << 0;
                return 0;
            }
            ans = ans * ou % MOD;
            ou--;
            n--;
        }
    }
    for (int i = 1; i <= n; ++i) {
        ans = ans * i % MOD;
    }
    cout << ans;
    return 0;
}