//
// Created by sanenchen on 25-7-31.
//
#include <bits/stdc++.h>
using namespace std;
bool wordBreak(string s, vector<string>& wordDict) {
    unordered_map<string, bool> g_map;
    for (auto &it : wordDict) {
        g_map[it] = true;
    }

    auto dp = vector<bool>(s.length() + 1, false);
    dp[0] = true;
    for (int i = 1; i <= s.length(); ++i) {
        string tmp = s.substr(0, i);
        for (int j = i - 1; j >= 0; --j) {
            string tmp2 = tmp.substr(j);
            if (dp[i - tmp2.length()] && g_map[tmp2]) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[s.length()];
}

int main() {
    vector<string> wordDict = {"apple", "pen"};
    cout << wordBreak("applepenapple", wordDict) << endl;
    return 0;
}
