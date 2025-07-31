//
// Created by sanenchen on 25-7-31.
//
#include <bits/stdc++.h>

using namespace std;

int longestCommonSubsequence(string text1, string text2) {
    auto dp = vector<vector<int> >(text2.length() + 1, vector<int>(text1.length() + 1, 0));
    for (int i = 1; i <= text2.length(); ++i) {
        for (int j = 1; j <= text1.length(); ++j) {
            // 如果 最后一位相同了
            if (text1[j - 1] == text2[i - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    return dp[text2.length()][text1.length()];
}


int main() {
    cout << longestCommonSubsequence("abcde", "ace");
    return 0;
}
