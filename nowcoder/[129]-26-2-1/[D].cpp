#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string str; cin >> str;
    int n = str.size();
    int ans = 0;
    int add = 0, del = 0;
    for (int i = 1; i < n - 1; ++i) {
        if (str[i] == str[i - 1]) {
            add++;
        } else {
            del++;
        }
        if (str[i] == str[i + 1]) {
            ans += del;
        } else {
            ans += add;
        }
    }
    cout << ans + 1;
    return 0;
}