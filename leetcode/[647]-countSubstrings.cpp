//
// Created by sanenchen on 25-8-10.
//
#include <bits/stdc++.h>
using namespace std;

// 暴力解法
// int countSubstrings(string s) {
//     int ans = 0;
//     for (int i = 0; i < s.size(); ++i) {
//         for (int j = i; j < s.size(); ++j) {
//             string tmp = s.substr(i, j - i + 1);
//             // 判断tmp是不是回文
//             // if (tmp.size() % 2 != 0) continue;
//             bool isYes = true;
//             for (int k = 0; k < tmp.size() / 2; k++) {
//                 if (tmp[k] != tmp[tmp.size() - k - 1]) {
//                     isYes = false;
//                 }
//             }
//             if (isYes) ans ++;
//         }
//     }
//     return ans;
// }

// 动态规划
int countSubstrings(string s) {
    // 一个二维dp数组
    vector<vector<bool>> dp = vector<vector<bool>>(s.size(), vector<bool>(s.size(), false));
    // dp 数组的定义：dp[i][j]表示 [i, j] 是回文子串
    int ans = 0;
    for (int i = s.size() - 1; i >= 0; --i) {
        for (int j = s.size() - 1; j >= i; --j) {
            if (s[i] == s[j]) {
                if (i == j) {dp[i][j] = true; ans++;}
                else if (i + 1 == j) {dp[i][j] = true; ans++;}
                else {
                    dp[i][j] = dp[i + 1][j - 1];
                    if (dp[i][j])
                        ans++;
                }
            } else dp[i][j] = false;
        }
    }
    return ans;
}

int main() {
    cout << countSubstrings("aaa");
    return 0;
}