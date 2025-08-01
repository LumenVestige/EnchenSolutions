//
// Created by sanenchen on 25-8-1.
//
#include<bits/stdc++.h>
using namespace std;

int maxRepeating(string sequence, string word) {
    auto dp = vector<int>(sequence.size() + 1, 0);
    for (int i = word.size(); i <= sequence.size(); ++i) {
        string tmp = sequence.substr(i - word.size(), word.size());
        if (tmp == word) {
            dp[i] = dp[i - word.size()] + 1;
        } else
            dp[i] = 0;
    }
    int ans = 0;
    for (auto& it : dp) {
        ans = max(ans, it);
    }
    return ans;
}

int main() {
    cout << maxRepeating("aaabaaaabaaabaaaabaaaabaaaabaaaaba", "aaaba");

    return 0;
}