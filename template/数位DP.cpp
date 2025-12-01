#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ll = long long;
// [LC]-3747
long long countDistinct(long long n) {
    string s = to_string(n);
    // 记忆化搜索
    ll memo[18][2][2]; // 记录状态用的 pos isLimit isLead
    memset(memo, -1, sizeof(memo));
    auto dfs = [&](auto&& self, int pos, bool isLimit, bool isLead) -> ll {
        // 终止条件：如果pos == s.size 
        if (pos == s.size()) {
            return isLead ? 0 : 1;
        }
        // 记忆化搜索 查表
        if (memo[pos][isLimit][isLead] != -1) {
            return memo[pos][isLimit][isLead];
        }

        // 标记 up 标签, 需要检查当前是否是在限制模式下
        int up = isLimit ? s[pos] - '0' : 9;
        ll res = 0;
        for (int i = 0; i <= up; ++i) {
            // 前导0判断
            if (isLead) {
                // 延续前导0状态
                res += self(self, pos + 1, isLimit && (i == up), i == 0); // 只有当当前的数字为0才会允许延续前导0状态
            } else {
                if (i != 0) {
                    res += self(self, pos + 1, isLimit && (i == up), false);
                }
            }
        }
        memo[pos][isLimit][isLead] = res; // 记忆化表设置
        return res;
    };
    return dfs(dfs, 0, true, true);
}

int main() {
    cout << countDistinct(10000);
    return 0;
}