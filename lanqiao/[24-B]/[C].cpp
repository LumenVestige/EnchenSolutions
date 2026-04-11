#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int ans = 0;
    while (n--) {
        int i;
        cin >> i;
        if ((i-3)%3 == 0) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}