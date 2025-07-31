//
// Created by sanenchen on 25-7-31.
//
#include <bits/stdc++.h>

using namespace std;

int climbStairs(int n) {
    auto dp = vector<int>(46, 0);
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main() {
    cout << climbStairs(3);
    return 0;
}