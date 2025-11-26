#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int countDigitOne(int n) {
    string numStr = to_string(n);
    // 记忆化搜索
    unordered_map<int, int[20][2]> memo;
    function<ll(int, int, int)> dfs = [&](int pos, bool isLimit, ll cnt) -> ll {
        if (pos == numStr.size()) {
            return cnt;
        }
        ll res = 0;
        if (!memo.count(cnt)) {
            memset(memo[cnt], -1, sizeof(memo[cnt]));
        }
        if (memo[cnt][pos][isLimit] != -1) {
            return memo[cnt][pos][isLimit];
        }
        int up = (isLimit) ? numStr[pos] - '0' : 9;
        for (int i = 0; i <= up; ++i) {
            res += dfs(pos + 1, isLimit && (up == i), (i == 1) ? cnt + 1 : cnt);
        }
        memo[cnt][pos][isLimit] = res;
        return res;
    };
    return dfs(0, true, 0);
}

int main() {
    cout << countDigitOne(13);
    return 0;
}