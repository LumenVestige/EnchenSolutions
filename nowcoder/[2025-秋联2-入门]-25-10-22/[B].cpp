#include <bits/stdc++.h>
using namespace std;
signed main() {
    int n;
    string str;
    cin >> n >> str;
    int c6 = 0, c1 = 0;
    for (auto& i : str) {
        if (i == '6')
            c6++;
        if (i == '1')
            c1++;
    }
    int ans = min(c1, max(c6 - 1, 0));
    cout << ans;
    return 0;
}