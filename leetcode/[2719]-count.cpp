#include <bits/stdc++.h>
using namespace std;
using ll = __int128;

// 处理借位问题
string deHelper(string str) {
    for (int i = str.size() - 1; i >= 0; --i) {
        if (str[i] != '0') {
            str[i]--;
            break;
        }
        str[i] = '9';
    }
    if (str[0] == '0' && str.size() > 1) 
        str = str.substr(1);
    return str;
}

ll countSolve(string num, int min_sum, int max_sum) {
    ll memo[24][2][500];
    memset(memo, -1, sizeof(memo));
    function<ll(int, int, int)> dfs = [&](int pos, bool isLimit, int able)->ll {
        if (pos == num.size()) {
            // 判断是否满足最低点
            // if (isLead) return 0;
            if (max_sum - able >= min_sum) return 1;
            return 0;
        }
        // 查询memo
        if (memo[pos][isLimit][able] != -1) {
            return memo[pos][isLimit][able];
        }
        // 计算当前up是多少
        int up = 9;
        if (isLimit) up = num[pos] - '0';
        if (able < up) up = able;
        ll res = 0;
        for (int i = 0; i <= up; ++i) {
            res += dfs(pos + 1, isLimit && (i == up), able - i);
        }
        memo[pos][isLimit][able] = res;
        return res;
    };
    return dfs(0, true, max_sum);
}

int count(string num1, string num2, int min_sum, int max_sum) {
    // [L, R] -> [0, R] - [0, L - 1]
    ll R = countSolve(num2, min_sum, max_sum);
    num1 = deHelper(num1);
    ll L = countSolve(num1, min_sum, max_sum);
    return (R - L) % (long long)(1e9 + 7);
}

int main() {
    cout << deHelper("4179205230");
    //cout << count("8990", "9927", 1, 3);
    return 0;
}