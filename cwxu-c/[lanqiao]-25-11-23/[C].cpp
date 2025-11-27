#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    string str;
    cin >> str;
    int ans = 0;
    for (int i = 1; i < n; ++i) {
        if (str[i] == '1' && str[i - 1] == '1') {
            ans ++;
            str[i] = '0';
        }
    }
    cout << ans;
    return 0;
}