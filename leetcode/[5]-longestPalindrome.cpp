//
// Created by sanenchen on 25-8-10.
//
#include <bits/stdc++.h>

using namespace std;


string longestPalindrome(string s) {
    string ans = "";
    vector<vector<bool> > dp = vector<vector<bool> >(s.size(), vector<bool>(s.size(), false));
    for (int i = s.size() - 1; i >= 0; --i) {
        for (int j = s.size() - 1; j >= i; --j) {
            if (s[i] == s[j]) {
                if (i == j) dp[i][j] = true;
                else if (i + 1 == j) dp[i][j] = true;
                else {
                    dp[i][j] = dp[i + 1][j - 1];
                }
            } else {
                dp[i][j] = false;
            }
            if (dp[i][j]) {
                string tmp = s.substr(i, j - i + 1);
                if (tmp.size() > ans.size())
                    ans = tmp;
            }
        }
    }
    return ans;
}

int main() {
    cout << longestPalindrome("babad");
    return 0;
}
