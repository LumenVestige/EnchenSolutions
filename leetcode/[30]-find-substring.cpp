//
// Created by sanenchen on 25-7-5.
//
#include "LeetCodes.h"

vector<int> LeetCodes::findSubstring(string s, vector<string>& words) {
    // // 遍历 s 将 s 塞进 vector
    // vector<char> s_vector;
    // for (auto it : s) {
    //     s_vector.push_back(it);
    // }
    // 找到目标数
    int words_size = words.size();
    int target_length = words[0].length() * words_size;
    // cout << target_length << endl;

    //将 words 内所有可能的拼接方式搞出来，写进哈希表中
    unordered_map<string, int> m;
    // 0,1,2 三种数全排列？
    ranges::sort(words);
    do {
        stringstream temp;
        for (auto &it : words) {
            temp << it;
        }
        m[temp.str()] = 1;
        // cout << temp.str() << endl;
    } while (ranges::next_permutation(words).found);

    // 两个指针
    int a = 0, b = 0;
    vector<int> ans;
    // b 指针先游走
    while (b < s.length()) {
        // 如果目标数不满足8个，那就继续往前走
        // 如果到达了8个，那就要比较咯
        if (b - a + 1 == target_length) {
            string temp_str = s.substr(a, b - a + 1);
            if (m[temp_str] == 1) {
                ans.push_back(a);
            }
            a++;
        } else b++;
    }

    return ans;
}