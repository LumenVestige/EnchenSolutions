//
// Created by sanenchen on 25-7-5.
//
#include <bits/stdc++.h>
using namespace std;
// 超时做法
// vector<int> findSubstring(string s, vector<string>& words) {
//     // // 遍历 s 将 s 塞进 vector
//     // vector<char> s_vector;
//     // for (auto it : s) {
//     //     s_vector.push_back(it);
//     // }
//     // 找到目标数
//     int words_size = words.size();
//     int target_length = words[0].length() * words_size;
//     // cout << target_length << endl;

//     //将 words 内所有可能的拼接方式搞出来，写进哈希表中
//     unordered_map<string, int> m;
//     // 0,1,2 三种数全排列？
//     ranges::sort(words);
//     do {
//         stringstream temp;
//         for (auto &it : words) {
//             temp << it;
//         }
//         m[temp.str()] = 1;
//         // cout << temp.str() << endl;
//     } while (ranges::next_permutation(words).found);

//     // 两个指针
//     int a = 0, b = 0;
//     vector<int> ans;
//     // b 指针先游走
//     while (b < s.length()) {
//         // 如果目标数不满足8个，那就继续往前走
//         // 如果到达了8个，那就要比较咯
//         if (b - a + 1 == target_length) {
//             string temp_str = s.substr(a, b - a + 1);
//             if (m[temp_str] == 1) {
//                 ans.push_back(a);
//             }
//             a++;
//         } else b++;
//     }

//     return ans;
// }
vector<int> findSubstring(string s, vector<string>& words) {
    // 截取
    vector<string> strs;
    unordered_multiset<string> strsSet;
    int p = 0, token = words[0].size();
    while (p < s.size()) {
        string tmp;
        for (int i = 0; i < token; ++i) {
            tmp += s[p];
            p++;
        }
        strs.push_back(tmp);
    }
    for (int i = 0; i < words.size(); ++i) {
        strsSet.insert(words[i]);
    }
    int left = 0, right = 0;
    vector<int> ans;
    int n = words.size();
    unordered_map<string, int> cnt;
    int tmp = 0;
    while (right < strs.size()) {
        // 直接跳过的情况
        // 1. 出现不存在的 直接指针都调到下一位，清空当前缓存
        // 2. 出现之前重复的
        if (!strsSet.count(strs[right])) {
            right++;
            left = right;
            cnt.clear();
            tmp = 0;
            continue;
        }
        cnt[strs[right]]++;
        tmp++;
        while (cnt[strs[right]] > strsSet.count(strs[right]) && left <= right) {
            cnt[strs[left]]--;
            tmp--;
            left++;
        }
        if (tmp == n) {
            ans.push_back(left * token);
            right++;
            cnt[strs[left]]--;
            left++;
            tmp--;
            continue;
        }
        right++;
    }
    return ans;
}

int main() {
    vector<string> words = {"fooo","barr","wing","ding","wing"};
    for (auto& i : findSubstring("lingmindraboofooowingdingbarrwingmonkeypoundcake", words)) {
        cout << i << " ";
    }
    return 0;
}