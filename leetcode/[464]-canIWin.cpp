//
// Created by sanenchen on 2026/07/27.
//
// 464. 我能赢吗
// https://leetcode.cn/problems/can-i-win/

#include <bits/stdc++.h>
using namespace std;

bool canIWin(int maxChoosableInteger, int desiredTotal) {
    map<array<int, 2>, int> mem;
    auto dfs = [&](auto&& dfs, int mask, int sum)->bool {
        if (mem.count({mask, sum})) {
            return mem[{mask, sum}];
        }
        int& res = mem[{mask, sum}];
        // 稳赢策略
        for (int i = 1; i <= maxChoosableInteger; ++i) {
            // 当前这个可否选择
            if (!(mask >> (i-1) & 1)) { // 可选择
                if (sum + i >= desiredTotal) {
                    return res = true;
                }
                if(!dfs(dfs, mask | (1 << (i-1)), sum + i)) return res=true;
            }
        }
        return res=false;
    };
    return dfs(dfs, 0, 0);
}
int main() {
    // 改这个数字切换官方样例：1 .. 3
    const int CASE = 3;

    int maxChoosableInteger;
    int desiredTotal;
    if (CASE == 1) {
        maxChoosableInteger = 10;
        desiredTotal = 11;
    } else if (CASE == 2) {
        maxChoosableInteger = 10;
        desiredTotal = 0;
    } else {
        maxChoosableInteger = 10;
        desiredTotal = 1;
    }

    cout << (canIWin(maxChoosableInteger, desiredTotal) ? "true" : "false") << endl;
    return 0;
}
