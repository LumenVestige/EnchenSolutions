#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int countSpecialNumbers(int n) {
    string strNum = to_string(n);
    ll ans = 0;
    auto check = [&](int mask, int i) { // 检测第i个数字是否在集合中
        return (mask >> i & 1);
    };
    ll memo[20][2][1 << 10];
    memset(memo, -1, sizeof(memo));
    auto dfs = [&](auto&& dfs, int pos, bool isLimit, int mask)-> ll {
        if (pos == strNum.size()) {
            // cout << current << " " << mask << endl;
            return mask!=0;
        }
        // 记忆化搜索
        if (memo[pos][isLimit][mask] != -1) {
            return memo[pos][isLimit][mask];
        }
        int up = isLimit ? strNum[pos] - '0' : 9;
        ll res = 0;
        if (mask == 0) {
            res += dfs(dfs, pos + 1, false, mask); // 既然最高位是空的，自然也就不需要这个isLimit限制了
        }
        // 检查是否存在了，存在了不许进入了
        for (int i = 1 - (mask != 0); i <= up; ++i) {
            if (!check(mask, i)) {
                res += dfs(dfs, pos + 1, isLimit && up == i, mask | (1 << i));
            }
        }
        memo[pos][isLimit][mask] = res;
        return res;
    };
    return dfs(dfs, 0, true, 0);
}

int main() {
    cout << countSpecialNumbers(135);
    return 0;
}