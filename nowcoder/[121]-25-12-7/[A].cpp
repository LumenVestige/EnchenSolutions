#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

signed main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int ans = 0;
    ans += d * a;
    if (d <= b) {
        ans -= c;
    }
    cout << ans;
    return 0;
}