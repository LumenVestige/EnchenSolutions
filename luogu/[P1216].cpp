//
// Created by sanenchen on 25-8-2.
//
// P1216 [IOI 1994] 数字三角形 Number Triangles
// 线性dp
/**
*5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5
**/
#include <bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin >> n;
    vector<vector<int>> dp;
    for (int i = 1; i <= n; ++i) {
        vector<int> tmp(i);
        for (int j = 0; j < i; j++) {
            cin >> tmp[j];
        }
        dp.push_back(tmp);
    }
    // 自底向上
    for (int i = dp.size() - 1; i >= 1; --i) {
        for (int j = 0; j < i; ++j) {
            dp[i - 1][j] = max(dp[i][j], dp[i][j + 1]) + dp[i - 1][j];
        }
    }
    cout << dp[0][0] << endl;
    return 0;
}