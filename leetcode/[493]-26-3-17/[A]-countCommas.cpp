#include <bits/stdc++.h>
using namespace std;

int countCommas(int n) {
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        string s = to_string(i);
        ans += s.size() / 3;
        ans -= (s.size() % 3 == 0);
    }
    return ans;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << countCommas(1002);
    return 0;
}