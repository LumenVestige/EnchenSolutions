//
// Created by sanenchen on 25-7-5.
//
#include "LeetCodes.h"

int LeetCodes::lengthOfLongestSubstring(string s) {
    // 滑动窗口的基本操作
    /**
     * 有两个指针，b指针先动。如果满足条件：加入答案，b指针继续前进。直到不满足条件。
     * 如果不满足条件了，则b指针停止移动，a指针移动，直到符合条件为止。
     */
    int a = 0, b = 0;
    unordered_map<char, int> hash_map;
    string temp;
    int temp_ans = 0;
    while (b < s.length()) {
        temp = s.substr(a, b - a + 1);
        cout << temp << " ";
        // 记录当前指针
        hash_map[s[b]]++;
        // 滑动 b 指针
        b++;
        if (hash_map[s[b]] == 0) {
            // 没出现过
            // 符合条件
            temp = s.substr(a, b - a + 1);
            temp_ans = (temp.length() > temp_ans) ? temp.length() : temp_ans;
        } else {
            // 排除 s[b] 从左往右移动
            // 不符合条件了，说明有重复值，左端开始滑动
            temp = s.substr(a, b - a + 1);
            while (a < b) {
                // 滑动 a 指针
                hash_map[s[a++]]--;
                if (hash_map[s[b]] == 0) {
                    // 没出现过
                    // 符合条件
                    temp = s.substr(a, b - a + 1);
                    temp_ans = (temp.length() > temp_ans) ? temp.length() : temp_ans;
                    break;
                }
            }
        }
    }
    return temp_ans;
}
