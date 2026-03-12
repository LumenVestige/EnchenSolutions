#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int MOD = 2000120420010122;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string str;
    while (cin >> str) {
        int ans = 0;
        int dp0 = 0, dp1 = 0, dp2 = 0;
        for (auto& c : str) {

            if (c == 'c' || c == 'C') {
                dp0++;
                ans += dp2 % MOD;
            } else if (c == 'W' || c == 'w') {
                dp1 += dp0;
            } else if (c == 'b' || c == 'B') {
                dp2 += dp1;
            }
        }
        cout << ans % MOD << endl;
    }
    return 0;
}