#include <bits/stdc++.h>
using namespace std;
#define ll long long
long long countCommas(int n) {
    string sN = to_string(n);
    int ans = 0;
    int memo[17][2][10];
    memset(memo, -1, sizeof(memo));
    // n 第n个数 isLimit 限制状态 
    auto nDP = [&](auto&& nDP, int pos, bool isLimit, int nCount)->ll {
        if (pos == sN.size()) {
            return (nCount-1)/3;
        }
        int up = 9;
        if (isLimit) {
            up = sN[pos] - '0';
        }
        auto& m = memo[pos][isLimit][nCount];
        if (m != -1) {
            return m;
        }
        ll res = 0;
        for (int i = 0; i <= up; ++i) {
            int c = nCount + 1;
            if (nCount == 0 && i == 0) {
                c = 0;
            }
            res += nDP(nDP, pos+1, isLimit && (i == up), c);
        }
        m = res;
        return res;
    };
    return nDP(nDP, 0, true, 0);
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << countCommas(2263071997);
    return 0;
}