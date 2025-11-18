#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    string s1, s2;
    cin >> s1 >> s2;
    int base = abs(m - n);
    int ans = 0;
    for (int i = 0; i < min(m, n); ++i) {
        if (s1[i] != s2[i]) ans++;
    }
    cout << ans + base;
    return 0;
}