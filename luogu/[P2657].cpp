#include <bits/stdc++.h>
using namespace std;
using ll = __int128;
#define endl "\n"

ll solve(long long n) {
    string strNum = to_string(n);
    ll memo[24][2][10][2];
    memset(memo, -1, sizeof(memo));
    auto dfs = [&](auto&& dfs, int pos, bool isLimit, bool started, int lastNum)->ll {
        if (pos == strNum.size()) {
            return started ? 1 : 0; // ✅ 仅当已开始有效数字时计数
        }
        if (memo[pos][isLimit][lastNum][started] != -1) {
            return memo[pos][isLimit][lastNum][started];
        }
        int up = isLimit ? strNum[pos] - '0' : 9;
        ll res = 0;
        for (int i = 0; i <= up; ++i) {
            if (!started) {
                // 未开始：选0保持未开始，选非零开始有效数字
                bool newStarted = (i != 0);
                res += dfs(dfs, pos + 1, isLimit && (i == strNum[pos]-'0'), newStarted, i);
            } else if (abs(i - lastNum) >= 2) {
                // 已开始：必须满足差值条件
                res += dfs(dfs, pos + 1, isLimit && (i == strNum[pos]-'0'), true, i);
            }
        }
        return res;
    };
    return dfs(dfs, 0, true, 0, 0);
}
void print(__int128 x) {
    if (!x) return;
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    print(x / 10);
    putchar(x % 10 + '0');
}
signed main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    long long l, r;
    cin >> l >> r;
    l--;
    print(solve(r) - solve(l));
    return 0;
}