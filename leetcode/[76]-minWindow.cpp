//
// Created by sanenchen on 25-10-10.
//
#include <bits/stdc++.h>
using namespace std;
string minWindow(string s, string t) {
    // 拉进hashmap
    unordered_map<char, int> cnt_t;
    for (auto& i : t)
        cnt_t[i]++;
    int target = cnt_t.size(), tmp = 0, ans = INT_MAX;
    int ans_left = 0;
    int left = 0;
    for (int right = 0; right < s.size(); ++right) {
        if (cnt_t.count(s[right])) {
            cnt_t[s[right]]--;
            if (cnt_t[s[right]] == 0) {
                tmp++;
            }
        }
        // 在符合条件情况下缩小
        while (tmp == target) {
            if (ans > right - left + 1) {
                ans = right - left + 1;
                ans_left = left;
            }
            if (cnt_t.count(s[left])) {
                cnt_t[s[left]]++;
                if (cnt_t[s[left]] > 0) tmp--;
            }
            left++;
        }
    }
    if (ans == INT_MAX) return "";
    return s.substr(ans_left, ans);
}
int main() {
    cout << minWindow("aaaaaaaaaaaabbbbbcdd", "abcdd");
    return 0;
}