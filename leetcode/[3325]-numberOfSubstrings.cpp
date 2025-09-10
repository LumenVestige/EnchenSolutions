//
// Created by sanenchen on 25-9-9.
//
#include <bits/stdc++.h>
using namespace std;

int numberOfSubstrings(string s, int k) {
    unordered_map<char, int> all_cnt;
    vector<int> has_repeated;
    int left = 0, ans = 0;
    for (int right = 0; right < s.size(); ++right) {
        all_cnt[s[right]]++;
        if (all_cnt[s[right]] == k) has_repeated.push_back(s[right]);
        while (!has_repeated.empty()) {
            all_cnt[s[left]]--;
            if (all_cnt[s[left]] == k - 1) has_repeated.erase(find(has_repeated.begin(), has_repeated.end(), s[left]));
            left++;
        }
        ans += left;
    }
    return ans;
}

int main() {
    cout << numberOfSubstrings("abacb", 2);
    return 0;
}
