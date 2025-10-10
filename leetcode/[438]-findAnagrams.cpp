#include <bits/stdc++.h>
using namespace std;
vector<int> findAnagrams(string s, string p) {
    unordered_map<char, int> window, need;
    for (auto& i : p) {
        need[i]++;
    }
    vector<int> ans;
    int left = 0, right = 0, vaild = 0;
    while (right < s.size()) {
        if (need.count(s[right])) {
            window[s[right]]++;
            if (window[s[right]] == need[s[right]]) {
                vaild++;
            }
        }
        right++;
        while (right - left > p.size() && right > left) {
            if (need.count(s[left])) {
                if (window[s[left]] == need[s[left]]) {
                    vaild--;
                }
                window[s[left]]--;
            }
            left++;
        }
        if (vaild == need.size()) {
            ans.push_back(left);
        }
    }
    return ans;
}
int main() {
    for (auto& i : findAnagrams("baa", "aa")) {
        cout << i << " ";
    }
    return 0;
}