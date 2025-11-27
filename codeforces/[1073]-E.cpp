#include <bits/stdc++.h>
using namespace std;
using ll = __int128;
using lli = long long;
#define endl "\n"

ll solve(lli n, lli k) {
    string strNum = to_string(n);
    ll ans = 0;
    auto check = [&](int mask, int i) { // 检测第i个数字是否在集合中
        return (mask >> i & 1);
    };
    unordered_map<string, ll[20][2][1 << 10][11]> cnt;
    auto dfs = [&](auto&& dfs, int pos, bool isLimit, int mask, string current, int left)-> ll {
        if (pos == strNum.size()) {
            // cout << current << " " << mask << endl;
            return stoi(current);
        }
        // 记忆化搜索
        if (cnt.count(current)) {
            if (cnt[current][pos][isLimit][mask][left] != -1) {
                return cnt[current][pos][isLimit][mask][left];
            }
        } else {
            memset(cnt[current], -1, sizeof(cnt[current]));
        }
        int up = isLimit ? strNum[pos] - '0' : 9;
        ll res = 0;
        // 检查是否允许新数字
        // 允许就一整个for
        // 否则就是只能是原来的数字
        for (int i = 0; i <= up; ++i) {
            if (left > 0) {
                if (check(mask, i)) { // 存在
                    res += dfs(dfs, pos + 1, isLimit && up == i, mask, current + to_string(i), left);
                } else {
                    res += dfs(dfs, pos + 1, isLimit && up == i, mask | (1 << i), current + to_string(i), left - 1);
                }
            } else {
                if (check(mask, i)) { // 存在
                    res += dfs(dfs, pos + 1, isLimit && up == i, mask, current + to_string(i), left);
                }
            }
        }
        cnt[current][pos][isLimit][mask][left] = res;
        return res;
    };
    return dfs(dfs, 0, true, 0, "", k);
}
void print(__int128 x){
    if(x<0)putchar('-'),x=-x;
    if(x>9)print(x/10);
    putchar(x%10+'0');
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    lli l, r, k;
    cin >> l >> r >> k;
    ll L = solve(l - 1, k), R = solve(r, k);
    ll res = (R - L) % 998244353;
    print(res);
    return 0;
}