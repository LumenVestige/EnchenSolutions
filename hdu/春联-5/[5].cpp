#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int t;
    cin >> t;
    while (t--) {
        int c;
        cin >> c;
        int z = (1 ^ c);
        int ans = 0;
        while (z > 0) {
            if (z & 1) {
                ans ++;
            }
            z >>= 1;
        }
        cout << ans << endl;
    }

    return 0;
}