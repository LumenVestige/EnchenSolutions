//
// Created by sanenchen on 25-9-9.
//
#include <bits/stdc++.h>
using namespace std;

int numberOfSubstrings(string s) {
    unordered_map<char, int> cnt;
    int left = 0, ans = 0;
    for (int right = 0; right < s.size(); ++right) {
        cnt[s[right]]++;
        while (cnt['a'] >= 1 && cnt['b'] >= 1 && cnt['c'] >= 1) {
            cnt[s[left]]--;
            left++;
        }
        ans += left;
    }
    return ans;
}

int main() {
    cout << numberOfSubstrings("abcabc");
    return 0;
}