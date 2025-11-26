#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int numDupDigitsAtMostN(int n) {
    string strNum = to_string(n);
    int memo[20][2][1 << 10];
    memset(memo, -1, sizeof(memo));
    auto dfs = [&](auto&& dfs, int pos, bool isLimit, int mask)->ll {
        if (pos == strNum.size()) {
            return mask != 0;
        }
        if (memo[pos][isLimit][mask] != -1) {
            return memo[pos][isLimit][mask];
        }
        int up = (isLimit) ? strNum[pos] - '0': 9;
        ll res = 0;
        // mask == 0 意味着当前是空的 还没有数字
        if (mask == 0) {
            res += dfs(dfs, pos + 1, false, mask); // 既然最高位是空的，自然也就不需要这个isLimit限制了
        }
        for (int i = 1 - (mask != 0); i <= up; ++i) {
            if (((mask >> i) & 1) == 0) { // 验证是否出现过了
                res += dfs(dfs, pos + 1, isLimit && (up == i), mask | (1 << i));
            }
        }
        memo[pos][isLimit][mask] = res;
        return res;
    };
    return n - dfs(dfs, 0, true, 0);
}

int main() {
    cout << numDupDigitsAtMostN(20);
    double c[10];
    double* x = c;
    return 0;
}