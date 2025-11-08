#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    string s;
    cin >> s;
    string ans = s;
    for (int i = 0; i < s.length(); ++i) {
        ans[i] = '9' - s[i] + '0';
    }
    cout << ans;
    return 0;
}