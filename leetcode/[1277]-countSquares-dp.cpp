//
// Created by sanenchen on 25-8-20.
//
#include <bits/stdc++.h>
using namespace std;

int countSquares(vector<vector<int> > &matrix) {
    vector<vector<int> > dp = matrix;
    // 状态转移
    int ans = 0;
    for (int i = 1; i < matrix.size(); ++i) {
        for (int j = 1; j < matrix[0].size(); ++j) {
            if (matrix[i][j] == 0) dp[i][j] = 0;
            else {
                dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
            }
        }
    }
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[0].size(); ++j) {
            ans += dp[i][j];
        }
    }

    return ans;
}

int main() {
    vector<vector<int> > nums = {
        {0, 1, 1, 1},
        {1, 1, 1, 1},
        {0, 1, 1, 1}
    };
    cout << countSquares(nums);
    return 0;
}
