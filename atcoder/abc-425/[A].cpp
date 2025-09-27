#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += pow(-1, i) * pow(i, 3);
    }
    cout << ans;
    return 0;
}