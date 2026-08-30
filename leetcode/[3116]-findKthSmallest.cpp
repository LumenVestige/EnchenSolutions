//
// Created by sanenchen on 2026/08/21.
//
// 3116. 单面值组合的第 K 小金额
// https://leetcode.cn/problems/kth-smallest-amount-with-single-denomination-combination/

#include <bits/stdc++.h>
using namespace std;

long long findKthSmallest(vector<int>& coins, int k) {
    // TODO
    auto check = [&](long long m) -> int {
        long long cnt = 0;
        for (int i = 1; i < (1 << coins.size()); i++) { // 枚举所有非空子集 i
            long long lcm_res = 1; // 计算子集 lcm
            for (int j = 0; j < coins.size(); j++) {
                if (i >> j & 1) { // j 在集合 i 中
                    lcm_res = lcm(lcm_res, coins[j]);
                    if (lcm_res > m) { // 太大了
                        break;
                    }
                }
            }
            cnt += __builtin_popcount(1u * i) % 2 ? m / lcm_res : -m / lcm_res;
        }
        return cnt; 
    };
    long long l = k-1, r = 4305196548;
    while (l+1 < r) {
        long long mid = l + (r-l)/2;
        if (check(mid) >= k) {
            r = mid;
        } else {
            l = mid;
        }
    }
    return r;
}

int main() {
    // 改这个数字切换官方样例：1 .. 2
    const int CASE = 2;

    vector<int> coins;
    int k;
    if (CASE == 1) {
        coins = {3, 6, 9};
        k = 3;
    } else {
        coins = {5, 2};
        k = 7;
    }

    cout << findKthSmallest(coins, k) << endl;
    return 0;
}
