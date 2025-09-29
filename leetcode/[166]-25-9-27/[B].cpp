//
// Created by sanenchen on 25-9-27.
//
#include <bits/stdc++.h>
using namespace std;
int climbStairs(int n, vector<int>& costs) {
    vector<long long> dp(n + 1, LONG_LONG_MAX);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i && j <= 3; ++j) {
            // 本个循环是往前推3个楼梯，之后再爬上来。
            dp[i] = min(dp[i], dp[i - j] + costs[i - j] + j * j);
            // 这里比较一下，哪个方案 从哪个楼梯爬上来最佳
            // ｊ * ｊ 意味爬了ｊ层　就要+ｊ^2 
        }
    }
    return dp[n];
}
int main() {
    vector<int> costs = {1,2,3,4};
    cout << climbStairs(4, costs);
    return 0;
}