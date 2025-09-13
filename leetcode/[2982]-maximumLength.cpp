#include <bits/stdc++.h>
using namespace std;

// int maximumLength(string s) {
//     // 首先预处理字符串，记录连续相同字符的长度
//     vector<pair<char, int>> groups;
//     if (s.empty()) return -1;
    
//     char current = s[0];
//     int count = 1;
//     for (int i = 1; i < s.size(); ++i) {
//         if (s[i] == current) {
//             count++;
//         } else {
//             groups.emplace_back(current, count);
//             current = s[i];
//             count = 1;
//         }
//     }
//     groups.emplace_back(current, count);
    
//     // 检查是否存在长度为k的特殊子字符串至少出现3次
//     auto check = [&](int k) -> bool {
//         if (k == 0) return false;
        
//         unordered_map<char, int> freq;
//         for (auto& [c, len] : groups) {
//             if (len >= k) {
//                 freq[c] += len - k + 1;  // 长度为len的连续字符可产生len-k+1个长度为k的子串
//                 if (freq[c] >= 3) {
//                     return true;
//                 }
//             }
//         }
//         return false;
//     };
//     int left = 0, right = s.size();
//     while (left + 1 < right) {
//         int mid = left + (right - left) / 2;
//         if (check(mid)) left = mid;
//         else right = mid;
//     }
//     // 等于一的特判
//     unordered_map<char, int> cnt_special;
//     int m = 0;
//     if (left == 1 || left == 0)
//         for (auto& i : s) {
//             cnt_special[i]++;
//             m = max(m, cnt_special[i]);
//             return (m >= 3) ? -1 : left;
//         }
//     return left;
// }

int maximumLength(string s) {
    auto check = [&](int mid)-> bool {
        unordered_map<char, int> cnt;

        for (int i = 0; i < s.size();) {
            int l = i;
            while (s[i] == s[l]) i++;
            if (i - l >= mid) cnt[s[l]] += i - l - mid + 1;
            if (cnt[s[l]] >= 3) return true;
        }
        return false;
    };
    int left = 0, right = s.size() + 1;
    while (left + 1 < right) {
        int mid = left + (right - left) / 2;
        if (check(mid)) left = mid;
        else right = mid;
    }  
    return left ? -1 : left;
}

int main() {
    cout << maximumLength("aaaa");
    return 0;
}