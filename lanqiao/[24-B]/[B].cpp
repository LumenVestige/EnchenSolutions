#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int MOD = 1e9+7;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int ans = 1;
    for (int i = 1; i <= 2025; ++i) {
        ans *= i;
        ans %= MOD;
    }
    cout << ans;
    return 0;
}